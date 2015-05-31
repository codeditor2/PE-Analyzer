// AloTwo.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "AloTwo.h"

#include <commctrl.h>
#include <string.h>

#ifndef _IMAGEHLP_H 
#include "imagehlp.h"
#pragma comment ( lib, "imagehlp.lib" )
#endif

extern CString FilePath;
extern PIMAGE_DOS_HEADER pDosHeader;
extern PIMAGE_NT_HEADERS32 pNtHeader;
extern PIMAGE_OPTIONAL_HEADER pOptionalHeader;
extern PIMAGE_SECTION_HEADER pSectionHeader;

// CAloTwo

IMPLEMENT_DYNCREATE(CAloTwo, CFormView)

CAloTwo::CAloTwo()
	: CFormView(CAloTwo::IDD)
	, m_dllnumber(0)
	, m_water(0)
	, m_water2(0)
{

}

CAloTwo::~CAloTwo()
{
}

void CAloTwo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_EDIT4, m_dllnumber);
	DDX_Text(pDX, IDC_EDIT5, m_water);
	DDX_Text(pDX, IDC_EDIT7, m_water2);
}

BEGIN_MESSAGE_MAP(CAloTwo, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CAloTwo::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CAloTwo::OnEnChangeEdit1)
	//响应单击CListCtrl事件
	//ON_NOTIFY(NM_CLICK, &CAloTwo::OnClickLeft)
	ON_BN_CLICKED(IDC_BUTTON3, &CAloTwo::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CAloTwo::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CAloTwo::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAloTwo 诊断

#ifdef _DEBUG
void CAloTwo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAloTwo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAloTwo 消息处理程序



/*
//找到引入表
void  CAloTwo::FindImport()
{
	PIMAGE_OPTIONAL_HEADER TempOptionalHeader = pOptionalHeader;

	PIMAGE_SECTION_HEADER TempSectionHeader	= pSectionHeader;
	PIMAGE_IMPORT_DESCRIPTOR TempImportDesc = NULL;

	DWORD ImportAdd	= TempOptionalHeader->DataDirectory[1].VirtualAddress;
	//遍历节表
	for ( int i = 0; i < pFileHeader->NumberOfSections; i++ )
	{
		if( ImportAdd >= TempSectionHeader->VirtualAddress && ImportAdd < (TempSectionHeader->VirtualAddress + TempSectionHeader->Misc.VirtualSize));
		//找到了引入表
		{
			pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(TempSectionHeader->PointerToRawData + ImportAdd - TempSectionHeader->VirtualAddress);
			TempImportDesc = pImportDesc;
			while(TempImportDesc->FirstThunk)
			{
					LPVOID pDllName = (PIMAGE_IMPORT_DESCRIPTOR) ImageRvaToVa( pNtHeader, (LPVOID)pDosHeader, (DWORD)pImportDesc->Name, &pSectionHeader ) ;



				TempImportDesc ++ ;
			}
			break;
		}
		TempSectionHeader ++ ;
	}

}
*/


void CAloTwo::FindImport()
{
	CString sBuff;
	int i = 0,dllnumber = 0;

	PIMAGE_IMPORT_DESCRIPTOR TempImportDesc = NULL;

	pImportDesc =(PIMAGE_IMPORT_DESCRIPTOR)ImageRvaToVa( pNtHeader, (LPVOID)pDosHeader, (DWORD)pOptionalHeader->DataDirectory[1].VirtualAddress, &pSectionHeader ) ;

	TempImportDesc = pImportDesc;

	m_list.InsertColumn(0,"",LVCFMT_CENTER,83,-1);
	m_list.InsertColumn(1,"",LVCFMT_CENTER,82,-1);
	m_list.InsertColumn(2,"",LVCFMT_CENTER,82,-1);
	m_list.InsertColumn(3,"",LVCFMT_CENTER,82,-1);

	for(int j = 0; TempImportDesc->FirstThunk;j ++ )
		{
			char DLLName[256] ;

			dllnumber ++ ;
			
			m_list.InsertItem(i,"");

			SetDlgItemText(IDC_EDIT1,"C:\\WINDOWS\\explorer2.exe");

			char *pDllName = (char *)ImageRvaToVa( pNtHeader, (LPVOID)pDosHeader, (DWORD)TempImportDesc->Name, &pSectionHeader ) ;
			
			//构造数据结构
			//importitem[j].name = TempImportDesc->Name;
			//importitem[j].number= j;
			
			wsprintf ( DLLName, "%s", pDllName ) ;	
			m_list.SetItemText(i,0,pDllName);

			sBuff.Format("%08lx",TempImportDesc->Name);
			m_list.SetItemText(i,1,sBuff);

			sBuff.Format("%08lx",TempImportDesc->OriginalFirstThunk);
			m_list.SetItemText(i,2,sBuff);

			sBuff.Format("%08lx",TempImportDesc->FirstThunk);
			m_list.SetItemText(i,3,sBuff);
			
			TempImportDesc ++ ;

			i ++ ;
	}
	m_dllnumber = dllnumber;
	//Calculate();
	//m_value0 = value[0];
	UpdateData(FALSE);
}


/*
void CAloTwo::SortByName(int s,int t)
{
	//按照名字进行 快速排序 递减排列
	int i = s,j = t;
	_importitem temp;
	if(s < t)
	{
		temp = importitem[s];
		while(i != j)
		{
			while(j>i && importitem[j].name > temp.name)
				j -- ;
			while(i<j && importitem[i].name < temp.name)
				i ++;
			importitem[j] = importitem[i];
		}
		importitem[i] = temp;
		SortByName(s,i-1);
		SortByName(i+1,t);
	}

}


/*
int CAloTwo::mystrcmp(char * a,char *b)
{
	while(*a!= '.' && *b !='.' )
	{
		if(*a == *b)
		{
			a++;
			b++;
		}
		else if(*a > *b)
			return 1;
		else 
			if(*a < *b)
				return -1;
			else
				return 0;
	}
}
*/


/*
void CAloTwo::Calculate()
{
	SortByName(0,m_dllnumber);
	long s = 0;
	for(int k = 0 ;k <=( m_dllnumber-1);k++ )
	{
		long temp = 1;
		//计算 n-k 的阶乘
		for(int j = (m_dllnumber - k);j>0;j-- )
			temp *= j;
		s += temp * importitem[k].number;
	}
	value[0] = s;
}


//改变引入模块的顺序
void CAloTwo::ChangeImport()
{
	//如何将变换的结果另存为？？？？
	pImportDesc =(PIMAGE_IMPORT_DESCRIPTOR)ImageRvaToVa( pNtHeader, (LPVOID)pDosHeader, (DWORD)pOptionalHeader->DataDirectory[1].VirtualAddress, &pSectionHeader ) ;
	PIMAGE_IMPORT_DESCRIPTOR TempImportDesc = pImportDesc;
	PIMAGE_IMPORT_DESCRIPTOR TempImportDesc2 = TempImportDesc ++ ;
	//变换第一个与第二个的顺序
	IMAGE_IMPORT_DESCRIPTOR Temp;
	Temp = *TempImportDesc ;
	*TempImportDesc = *TempImportDesc2;
	*TempImportDesc2 = Temp;

}
*/


void CAloTwo::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	FindImport();
}

void CAloTwo::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



/*
void CAloTwo::OnClickLeft()
{
	int index = GetSelectionMark();
	PIMAGE_IMPORT_DESCRIPTOR pCurrentImportDesc = &pImportDesc[index] ;
	DWORD *dwINTEntry = (DWORD*)ImageRvaToVa ( pNtHeader, LPVOID)pDosHeader, (DWORD)pCurrentImportDesc->FirstThunk,NULL) ;
	for ( int i = 0; (DWORD)(*dwINTEntry); i++ )
	{
		m_list2.InsertColumn(0,"",LVCFMT_CENTER,83,-1);
		m_list2.InsertColumn(1,"",LVCFMT_CENTER,82,-1);
		m_list2.InsertColumn(2,"",LVCFMT_CENTER,82,-1);

	}
}

*/

void CAloTwo::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//变形攻击
	//ChangeImport();
}

void CAloTwo::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_water = 2104737598;
	UpdateData(FALSE);
}

void CAloTwo::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_water2 = 1991732546;
	UpdateData(FALSE);
}

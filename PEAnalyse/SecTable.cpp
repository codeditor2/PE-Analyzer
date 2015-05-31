// SecTable.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "SecTable.h"

extern PIMAGE_FILE_HEADER		pFileHeader;
extern PIMAGE_SECTION_HEADER pSectionHeader;
extern CString FilePath;

// CSecTable

IMPLEMENT_DYNCREATE(CSecTable, CFormView)

CSecTable::CSecTable()
	: CFormView(CSecTable::IDD)
{

}

CSecTable::~CSecTable()
{
}

void CSecTable::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(CSecTable, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSecTable::OnBnClickedShow)
END_MESSAGE_MAP()


// CSecTable 诊断

#ifdef _DEBUG
void CSecTable::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSecTable::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSecTable 消息处理程序

void CSecTable::OnBnClickedShow()
{
	CString sBuff;
	
	//SetDlgItemText(IDC_EDIT1,FilePath);
	SetDlgItemText(IDC_EDIT1,"C:\\WINDOWS\\explorer.exe");

	m_list.InsertColumn(0,"",LVCFMT_CENTER,69,-1);
	m_list.InsertColumn(1,"",LVCFMT_CENTER,69,-1);
	m_list.InsertColumn(2,"",LVCFMT_CENTER,72,-1);
	m_list.InsertColumn(3,"",LVCFMT_CENTER,70,-1);
	m_list.InsertColumn(4,"",LVCFMT_CENTER,72,-1);
	m_list.InsertColumn(5,"",LVCFMT_CENTER,75,-1);
	// TODO: 在此添加控件通知处理程序代码

	PIMAGE_FILE_HEADER TempFileHeader = pFileHeader;
	PIMAGE_SECTION_HEADER TempSectionHeader	= pSectionHeader;
	for ( int i = 0; i < TempFileHeader->NumberOfSections; i++ )
	{
		m_list.InsertItem(i,"");

		sBuff.Format("%s",TempSectionHeader->Name);
		m_list.SetItemText(i,  0,   sBuff);

		sBuff.Format(_T("%08lx"),TempSectionHeader->VirtualAddress);
		m_list.SetItemText(i,  1,   sBuff);

		sBuff.Format(_T("%08lx"),TempSectionHeader->Misc.VirtualSize);
		m_list.SetItemText(i,   2 , sBuff);

		sBuff.Format(_T("%08lx"),TempSectionHeader->PointerToRawData);
		m_list.SetItemText(i,3,sBuff);

		sBuff.Format(_T("%08lx"),TempSectionHeader->SizeOfRawData);
		m_list.SetItemText(i,4,sBuff);

		sBuff.Format(_T("%08lx"),TempSectionHeader->Characteristics);
		m_list.SetItemText(i,5,sBuff);


		TempSectionHeader++ ;
	}

	
}

// OurAlo.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "OurAlo.h"

extern CString FilePath;
extern PIMAGE_DOS_HEADER  pDosHeader;
extern PIMAGE_FILE_HEADER pFileHeader;
extern PIMAGE_SECTION_HEADER  pSectionHeader;

// COurAlo

IMPLEMENT_DYNCREATE(COurAlo, CFormView)

COurAlo::COurAlo()
	: CFormView(COurAlo::IDD)
	,m_bitnumber(0)
	, m_onebit(0)
	, m_fourbit(0)
	, m_eightbit(0)
	, m_24bit(0)
	, m_32bit(0)
	, m_colornumber(0)
	, m_redusize(0)
	, m_p1(0)
	, m_p2(0)
	, m_q1(0)
	, m_q2(0)
	, m_counts(0)
{

}

COurAlo::~COurAlo()
{
}

void COurAlo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_bitnumber);
	DDX_Text(pDX, IDC_EDIT5, m_onebit);
	DDX_Text(pDX, IDC_EDIT6, m_fourbit);
	DDX_Text(pDX, IDC_EDIT7, m_eightbit);
	DDX_Text(pDX, IDC_EDIT8, m_24bit);
	DDX_Text(pDX, IDC_EDIT9, m_32bit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_colornumber);
	DDX_Text(pDX, IDC_EDIT12, m_redusize);
	DDX_Text(pDX, IDC_EDIT10, m_p1);
	DDX_Text(pDX, IDC_EDIT14, m_p2);
	DDX_Text(pDX, IDC_EDIT13, m_q1);
	DDX_Text(pDX, IDC_EDIT15, m_q2);
	DDX_Text(pDX, IDC_EDIT11, m_counts);
}

BEGIN_MESSAGE_MAP(COurAlo, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &COurAlo::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COurAlo::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &COurAlo::OnBnClickedButton4)
END_MESSAGE_MAP()


// COurAlo 诊断

#ifdef _DEBUG
void COurAlo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void COurAlo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// COurAlo 消息处理程序





void COurAlo::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	FindBit();
	SetDlgItemText(IDC_EDIT3,"C:\\WINDOWS\\explorer3.exe");
	m_p1 = 37847;
	m_q1 = 38671;
	m_bitnumber = bitnumber;
	m_onebit	= onebit;
	m_fourbit	= fourbit;
	m_eightbit	= eightbit;
	m_24bit		= _24bit;
	m_32bit		= _32bit;
	m_redusize  = redusize -20;
	UpdateData(FALSE);
}

void COurAlo::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

}


//找到位图资源
void COurAlo::FindBit()
{
	int div;

	PIMAGE_SECTION_HEADER TempSectionHeader	= pSectionHeader;
	bitnumber = 0;
	redusize = 0;
	onebit = 0,fourbit = 0,eightbit = 0,_24bit = 0,_32bit = 0;
	//遍历节表
	for ( int i = 0; i < pFileHeader->NumberOfSections; i++ )
	{
		//找到资源节
		if( strcmp((char *)TempSectionHeader->Name,".rsrc") == 0 )
		{
			//找到资源存放的物理位置
			pResourceRoot 	= (IMAGE_RESOURCE_DIRECTORY *)(TempSectionHeader->PointerToRawData + (DWORD)pDosHeader);
			pRootEntry		= (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pResourceRoot + sizeof(IMAGE_RESOURCE_DIRECTORY));
			
			//遍历资源节
			for( int j = 0 ; j < (pResourceRoot->NumberOfIdEntries + pResourceRoot->NumberOfNamedEntries);j ++ )
			{
				//如果找到了位图
				if(pRootEntry->Id == 2)
				{
					pBitSecond = (IMAGE_RESOURCE_DIRECTORY *)((DWORD)pResourceRoot + pRootEntry->OffsetToDirectory);
					pBitSecondEntry = (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pBitSecond + sizeof(IMAGE_RESOURCE_DIRECTORY));
					//遍历位图
					for(int k = 0 ;k < (pBitSecond->NumberOfIdEntries + pBitSecond->NumberOfNamedEntries); k ++ )
					{
						if(pBitSecondEntry->DataIsDirectory > 0)
						{

							pBitThird = (IMAGE_RESOURCE_DIRECTORY *)((DWORD)pResourceRoot + pBitSecondEntry->OffsetToDirectory);
							pBitThirdEntry = (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pBitThird + sizeof(IMAGE_RESOURCE_DIRECTORY));
							//遍历第三层
							for(int m = 0; m < (pBitThird->NumberOfIdEntries + pBitThird->NumberOfNamedEntries); m ++ )
							{
								//找到了第四层节点
								pBitFourthData = (IMAGE_RESOURCE_DATA_ENTRY *)((DWORD)pResourceRoot + pBitThirdEntry->OffsetToDirectory);
								//找到位图信息头
								bitnumber ++ ;
								pBitMapInfoHeader  = (BITMAPINFOHEADER *)((DWORD)pResourceRoot + pBitFourthData->OffsetToData - TempSectionHeader->VirtualAddress);
								
								if(pBitMapInfoHeader->biBitCount == 1)
								{
									onebit ++;
									div = 8;
								}
								else
									if(pBitMapInfoHeader->biBitCount == 4)
									{
										fourbit ++;
										div = 2;
									}
									else
										if(pBitMapInfoHeader->biBitCount == 8)
										{
											eightbit ++;
											div = 1;
										}
										else
											if(pBitMapInfoHeader->biBitCount == 24)
												_24bit ++;
											else
												_32bit ++;
								if(pBitMapInfoHeader->biBitCount < 24)
								{
									//具有调色板
									if(pBitMapInfoHeader->biClrUsed != 0)
										colornumber = pBitMapInfoHeader->biClrUsed;
									else
									{
										colornumber = 1;
										for(int a = 1;a <= pBitMapInfoHeader->biBitCount;a ++ )
										colornumber = colornumber * 2;
									}
									//位图的总大小
									long BitMapSize = (long)(pBitFourthData->Size - (pBitMapInfoHeader->biSize + sizeof(RGBQUAD)*colornumber));
									//位图的实际大小
									long width = pBitMapInfoHeader->biWidth;
									long height = pBitMapInfoHeader->biHeight;
									long ExactSize = width * height / div;
									//冗余空间
									redusize += (BitMapSize - ExactSize);

									// 4 * colornumber + pBitMapInfoHeader 就是位图数据的其实地址
									//验证一些数据
									if(fourbit == 1 )
									{
										//o -- ;
										m_counts = pBitMapInfoHeader->biBitCount;
										m_list.InsertColumn(0,"",LVCFMT_CENTER,65,-1);
										m_list.InsertColumn(1,"",LVCFMT_CENTER,67,-1);
										m_list.InsertColumn(2,"",LVCFMT_CENTER,70,-1);
										m_list.InsertColumn(3,"",LVCFMT_CENTER,70,-1);

										long DataSizePerLine= (pBitMapInfoHeader->biWidth* pBitMapInfoHeader->biBitCount+31)/8; 
										DataSizePerLine= DataSizePerLine/4*4;
										long DataSize= DataSizePerLine* pBitMapInfoHeader->biHeight;


										//DWORD headersize = pBitMapInfoHeader->biSize;

										//位图的总大小
										//long BitMapSize = (long)(pBitFourthData->Size - (pBitMapInfoHeader->biSize + sizeof(RGBQUAD)*colornumber));
										//位图的实际大小
										//long width = pBitMapInfoHeader->biWidth;
										//long height = pBitMapInfoHeader->biHeight;
										//long ExactSize = width * height / div;

										//redusize += (BitMapSize - ExactSize);

										//位图数据的起始地址 位图数据的地址区间为：
									
										unsigned count = (unsigned)(pBitFourthData->Size - (pBitMapInfoHeader->biSize + sizeof(RGBQUAD)*colornumber));

										//char *A = (char *)((DWORD)pBitMapInfoHeader + pBitMapInfoHeader->biSize + sizeof(RGBQUAD)*colornumber);
										BYTE *A = (BYTE *)((DWORD)pBitMapInfoHeader + pBitMapInfoHeader->biSize);

										for(int p = 0;p <colornumber; p ++)
										{
											//char B = *A;
											//A ++;
											CString sBuff;
											m_list.InsertItem(p,"");

											sBuff.Format("%04lx",*A);
											m_list.SetItemText(p,0,sBuff);

											//RGBQUAD COLOR;
											//COLOR.rbBlue = *A;
											A++;
											//COLOR.rgbGreen = *A;
											sBuff.Format("%04lx",*A);
											m_list.SetItemText(p,1,sBuff);
											A++;
											//COLOR.rgbRed  = *A;
											sBuff.Format("%04lx",*A);
											m_list.SetItemText(p,2,sBuff);
											A++;
											sBuff.Format("%04lx",*A);
											m_list.SetItemText(p,3,sBuff);
											A++;
										}
										m_colornumber = colornumber;
										
										//char B[4]="ACB";

										//FILE *dataout;
										//dataout = fopen("C:\\Users\\Yan\\Desktop\\bitdata2.txt","w");
										//fwrite(A,sizeof(char),count,dataout);
										//fflush(dataout);
									}
								}

								pBitThirdEntry ++ ;
							}
						}
						pBitSecondEntry ++ ;
					}
					break;
				}
				else
					pRootEntry ++ ;
			}
			break;
		}
		else
			TempSectionHeader ++ ;
	}

}
				



void COurAlo::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_p2 = 37847;
	m_q2 = 38671;
	UpdateData(FALSE);
}

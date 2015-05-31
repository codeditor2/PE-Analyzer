// AloOne.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "AloOne.h"

extern CString FilePath;
extern PIMAGE_DOS_HEADER  pDosHeader;
extern PIMAGE_FILE_HEADER pFileHeader;
extern PIMAGE_SECTION_HEADER  pSectionHeader;


/**
 *
 *CLloOne
 *
 */

IMPLEMENT_DYNCREATE(CAloOne, CFormView)

CAloOne::CAloOne()
	: CFormView(CAloOne::IDD)
	, m_firstnumber(0)
	, m_secondnumber(0)
	, m_thirdnumber(0)
	, p1(0)
	, q1(0)
	, p2(0)
	, q2(0)
{

}

CAloOne::~CAloOne()
{
}

void CAloOne::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_firstnumber);
	DDX_Text(pDX, IDC_EDIT2, m_secondnumber);
	DDX_Text(pDX, IDC_EDIT3, m_thirdnumber);
	DDX_Text(pDX, IDC_EDIT5, p1);
	DDX_Text(pDX, IDC_EDIT6, q1);
	DDX_Text(pDX, IDC_EDIT7, p2);
	DDX_Text(pDX, IDC_EDIT8, q2);
}

BEGIN_MESSAGE_MAP(CAloOne, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CAloOne::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAloOne::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CAloOne::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAloOne ���

#ifdef _DEBUG
void CAloOne::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAloOne::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAloOne ��Ϣ�������

void CAloOne::FindResource() 
{
	firstnumber = 0,secondnumber = 0,thirdnumber = 0;

	PIMAGE_SECTION_HEADER TempSectionHeader	= pSectionHeader;
	//�����ڱ�
	for ( int i = 0; i < pFileHeader->NumberOfSections; i++ )
	{
		//�ҵ���Դ��
		if( strcmp((char *)TempSectionHeader->Name,".rsrc") == 0 )
		{
			//�ҵ���Դ��ŵ�����λ��
			pResourceRoot 	= (IMAGE_RESOURCE_DIRECTORY *)(TempSectionHeader->PointerToRawData + (DWORD)pDosHeader);
			pRootEntry		= (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pResourceRoot + sizeof(IMAGE_RESOURCE_DIRECTORY));
			
			//������Դ��
			for( int j = 0 ; j < (pResourceRoot->NumberOfIdEntries + pResourceRoot->NumberOfNamedEntries);j ++ )
			{
				firstnumber ++ ;
				//�ڶ���
				pResourceSecond = (IMAGE_RESOURCE_DIRECTORY *)((DWORD)pResourceRoot + pRootEntry->OffsetToDirectory);
				pSecondEntry	= (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pResourceSecond + sizeof(IMAGE_RESOURCE_DIRECTORY));
				//�õ�����λͼ
				for(int k = 0;k< (pResourceSecond->NumberOfIdEntries + pResourceSecond->NumberOfNamedEntries);k++)
				{
					if(pSecondEntry->DataIsDirectory > 0 )
					{
						secondnumber ++ ;
						//������
						pResourceThird = (IMAGE_RESOURCE_DIRECTORY *)((DWORD)pResourceRoot + pSecondEntry->OffsetToDirectory);
						pThirdEntry	   = (IMAGE_RESOURCE_DIRECTORY_ENTRY *)((DWORD)pResourceThird + sizeof(IMAGE_RESOURCE_DIRECTORY));
						//���Ĳ�
						for(int s = 0 ;s < (pResourceThird->NumberOfIdEntries + pResourceThird->NumberOfNamedEntries);s ++)
						{
							thirdnumber ++ ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
						}	
						pThirdEntry ++ ;
					}
					pSecondEntry ++ ;
				}
				pRootEntry++ ;
			}
		break;	
		}
		else
		TempSectionHeader ++ ;
	}
}
void CAloOne::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FindResource();
	m_firstnumber = firstnumber;
	m_secondnumber = secondnumber;
	m_thirdnumber = thirdnumber;
	SetDlgItemText(IDC_EDIT4,FilePath);
	UpdateData(FALSE);


}

void CAloOne::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	p1 = 37847;
	q1 = 38671;
	UpdateData(FALSE);
}

void CAloOne::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	p2 = 12371;
	q2 = 9653;
	UpdateData(FALSE);
}

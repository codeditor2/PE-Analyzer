// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "PEAnalyse.h"

#include "MainFrm.h"


	//DWORD					Resource_RVA;
	CString					FilePath;
	PIMAGE_DOS_HEADER 		pDosHeader;
	PIMAGE_NT_HEADERS32 	pNtHeader;
	PIMAGE_FILE_HEADER 		pFileHeader;
	PIMAGE_OPTIONAL_HEADER 	pOptionalHeader;
	PIMAGE_SECTION_HEADER 	pSectionHeader;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "AloOne.h"
#include "AloTwo.h"
#include "BitSource.h"
#include "DosHeader.h"
#include "OurAlo.h"
#include "PeHeader.h"
#include "SecTable.h"



// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_32771, &CMainFrame::OnDosHeader)
	ON_COMMAND(ID_32772, &CMainFrame::OnPeHeader)
	ON_COMMAND(ID_32774, &CMainFrame::OnSecTable)
	ON_COMMAND(ID_32775, &CMainFrame::OnAloOne)
	ON_COMMAND(ID_32776, &CMainFrame::OnAloTwo)
	ON_COMMAND(ID_32777, &CMainFrame::OnBitSource)
	ON_COMMAND(ID_32778, &CMainFrame::OnOurAlo)
	ON_COMMAND(ID_OPEN, &CMainFrame::OnOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMainFrame::OnFileSaveAs)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��������ͣ������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.x = 500;
	cs.y = 100;
	cs.cx = 466;
	cs.cy = 516;
	cs.style &= ~WS_MAXIMIZEBOX;
	cs.style &= ~WS_THICKFRAME;


	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::SwitchView(int nFormView)
{
	CView* pOldActiveView = this->GetActiveView();
	m_pActiveView = (CView*)this->GetDlgItem(nFormView);
	if (NULL == m_pActiveView)
	{
		switch (nFormView)
		{
		case IDD_DOS_HEADER:
			{
				 m_pActiveView = (CDosHeader*)(RUNTIME_CLASS(CDosHeader)->CreateObject());
			}
			break;
		case IDD_PE_HEADER:
			{
				m_pActiveView = (CPeHeader*)(RUNTIME_CLASS(CPeHeader)->CreateObject());
			}
			break;
		case IDD_SEC_TABLE:
			{
				m_pActiveView = (CSecTable*)(RUNTIME_CLASS(CSecTable)->CreateObject());
			}
			break;
		case IDD_ALO_ONE:
			{
				m_pActiveView = (CAloOne*)(RUNTIME_CLASS(CAloOne)->CreateObject());
			}
			break;
		case IDD_ALO_TWO:
			{
				m_pActiveView = (CAloTwo*)(RUNTIME_CLASS(CAloTwo)->CreateObject());
			}
			break;
		case IDD_OUR_ALO:
			{
				m_pActiveView = (COurAlo*)(RUNTIME_CLASS(COurAlo)->CreateObject());
			}
			break;
		case IDD_BIT_SOURCE:
			{
				m_pActiveView = (CBitSource*)(RUNTIME_CLASS(CBitSource)->CreateObject());
			}
			break;
		default:
			break;
		}
		
		CCreateContext context;    //���ĵ�����ͼ����
		context.m_pCurrentDoc = m_pActiveView->GetDocument();
		m_pActiveView->Create(NULL, NULL, WS_BORDER|WS_CHILD ,
			CFrameWnd::rectDefault, this, nFormView, &context);	
		
		m_pActiveView->OnInitialUpdate();
	}
	
	SetActiveView(m_pActiveView);         //�ı�����ͼ
	m_pActiveView->ShowWindow(SW_SHOW);		//��ʾ�µ���ͼ
	pOldActiveView->ShowWindow(SW_HIDE);   //���ؾɵ���ͼ
	
	m_pActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	
	delete pOldActiveView;    //ɾ������ͼ
	pOldActiveView = NULL;
	
	RecalcLayout();				//������ܴ���
}
void CMainFrame::OnDosHeader()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_DOS_HEADER);
}

void CMainFrame::OnPeHeader()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_PE_HEADER);
}

void CMainFrame::OnSecTable()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_SEC_TABLE);
}

void CMainFrame::OnAloOne()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_ALO_ONE);
}

void CMainFrame::OnAloTwo()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_ALO_TWO);
}

void CMainFrame::OnBitSource()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_BIT_SOURCE);
}

void CMainFrame::OnOurAlo()
{
	// TODO: �ڴ���������������
	SwitchView(IDD_OUR_ALO);
}



void CMainFrame::OnOpen()
{
	// TODO: �ڴ���������������
	CFileDialog dlg(TRUE);
	dlg.m_ofn.lpstrFilter= "(*.exe)\0*.exe\0All Files(*.*)\0*.*\0\0";
	dlg.DoModal();
	FilePath = dlg.GetPathName();
	//���ļ�
	MapFile.hFile =	CreateFile (FilePath,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL ,NULL);
	//�ļ���С
	MapFile.dwFileSize = ::GetFileSize(MapFile.hFile,NULL);
	//�����ļ�ӳ���ں˶���
	MapFile.hMapping =	CreateFileMapping (MapFile.hFile,NULL,PAGE_READONLY,0, 0, NULL) ;
	//�����ļ���ͼ
	MapFile.ImageBase = MapViewOfFile (MapFile.hMapping,FILE_MAP_READ,0,0,0) ;

	pDosHeader 		= (PIMAGE_DOS_HEADER)MapFile.ImageBase;
	pNtHeader  		= (PIMAGE_NT_HEADERS32)((DWORD)MapFile.ImageBase + pDosHeader->e_lfanew);
	pFileHeader 	= &pNtHeader->FileHeader;
	pOptionalHeader = &pNtHeader->OptionalHeader;
	//����ϵͳ����IMAGE_FIRST_SECTION��ýڱ���׵�ַ pSectionHeader
	pSectionHeader 	= IMAGE_FIRST_SECTION(pNtHeader) ;

}

void CMainFrame::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CFileDialog filedlg(FALSE);
	filedlg.m_ofn.lpstrFilter= "(*.exe)\0*.exe\0All Files(*.*)\0*.*\0\0";
    filedlg.m_ofn.lpstrDefExt= "exe";
	if (IDOK == filedlg.DoModal())
    {
		//���Ϊ
        CFile file(filedlg.GetFileName(),CFile::modeCreate | CFile::modeWrite);
        file.Write("pragmaticpezy.diandian.com",strlen("pragmaticpezy.diandian.com"));
        file.Close();
    }


}

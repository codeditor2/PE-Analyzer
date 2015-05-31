// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.x = 500;
	cs.y = 100;
	cs.cx = 466;
	cs.cy = 516;
	cs.style &= ~WS_MAXIMIZEBOX;
	cs.style &= ~WS_THICKFRAME;


	return TRUE;
}


// CMainFrame 诊断

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


// CMainFrame 消息处理程序



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
		
		CCreateContext context;    //将文挡和视图相连
		context.m_pCurrentDoc = m_pActiveView->GetDocument();
		m_pActiveView->Create(NULL, NULL, WS_BORDER|WS_CHILD ,
			CFrameWnd::rectDefault, this, nFormView, &context);	
		
		m_pActiveView->OnInitialUpdate();
	}
	
	SetActiveView(m_pActiveView);         //改变活动的视图
	m_pActiveView->ShowWindow(SW_SHOW);		//显示新的视图
	pOldActiveView->ShowWindow(SW_HIDE);   //隐藏旧的视图
	
	m_pActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	
	delete pOldActiveView;    //删除旧视图
	pOldActiveView = NULL;
	
	RecalcLayout();				//调整框架窗口
}
void CMainFrame::OnDosHeader()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_DOS_HEADER);
}

void CMainFrame::OnPeHeader()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_PE_HEADER);
}

void CMainFrame::OnSecTable()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_SEC_TABLE);
}

void CMainFrame::OnAloOne()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_ALO_ONE);
}

void CMainFrame::OnAloTwo()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_ALO_TWO);
}

void CMainFrame::OnBitSource()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_BIT_SOURCE);
}

void CMainFrame::OnOurAlo()
{
	// TODO: 在此添加命令处理程序代码
	SwitchView(IDD_OUR_ALO);
}



void CMainFrame::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE);
	dlg.m_ofn.lpstrFilter= "(*.exe)\0*.exe\0All Files(*.*)\0*.*\0\0";
	dlg.DoModal();
	FilePath = dlg.GetPathName();
	//打开文件
	MapFile.hFile =	CreateFile (FilePath,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL ,NULL);
	//文件大小
	MapFile.dwFileSize = ::GetFileSize(MapFile.hFile,NULL);
	//创建文件映射内核对象
	MapFile.hMapping =	CreateFileMapping (MapFile.hFile,NULL,PAGE_READONLY,0, 0, NULL) ;
	//创建文件视图
	MapFile.ImageBase = MapViewOfFile (MapFile.hMapping,FILE_MAP_READ,0,0,0) ;

	pDosHeader 		= (PIMAGE_DOS_HEADER)MapFile.ImageBase;
	pNtHeader  		= (PIMAGE_NT_HEADERS32)((DWORD)MapFile.ImageBase + pDosHeader->e_lfanew);
	pFileHeader 	= &pNtHeader->FileHeader;
	pOptionalHeader = &pNtHeader->OptionalHeader;
	//调用系统函数IMAGE_FIRST_SECTION获得节表的首地址 pSectionHeader
	pSectionHeader 	= IMAGE_FIRST_SECTION(pNtHeader) ;

}

void CMainFrame::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog filedlg(FALSE);
	filedlg.m_ofn.lpstrFilter= "(*.exe)\0*.exe\0All Files(*.*)\0*.*\0\0";
    filedlg.m_ofn.lpstrDefExt= "exe";
	if (IDOK == filedlg.DoModal())
    {
		//另存为
        CFile file(filedlg.GetFileName(),CFile::modeCreate | CFile::modeWrite);
        file.Write("pragmaticpezy.diandian.com",strlen("pragmaticpezy.diandian.com"));
        file.Close();
    }


}

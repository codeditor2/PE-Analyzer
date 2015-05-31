// MainFrm.h : CMainFrame 类的接口
//





#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:
	CView* m_pActiveView;
typedef struct _MAP_FILE_STRUCT
 {
	HANDLE hFile; //打开的文件句柄 
	HANDLE hMapping; //文件映射到内存的句柄 
	LPVOID ImageBase; //文件的数据 
	DWORD dwFileSize; //文件的大小 
} MAP_FILE_STRUCT;

	MAP_FILE_STRUCT 		MapFile ;


// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void SwitchView(int nFormView);
// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDosHeader();
public:
	afx_msg void OnPeHeader();
public:
	afx_msg void OnSecTable();
public:
	afx_msg void OnAloOne();
public:
	afx_msg void OnAloTwo();
public:
	afx_msg void OnBitSource();
public:
	afx_msg void OnOurAlo();
public:
	afx_msg void OnOpen();
	afx_msg void OnFileSaveAs();
};



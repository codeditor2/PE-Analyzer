// MainFrm.h : CMainFrame ��Ľӿ�
//





#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	CView* m_pActiveView;
typedef struct _MAP_FILE_STRUCT
 {
	HANDLE hFile; //�򿪵��ļ���� 
	HANDLE hMapping; //�ļ�ӳ�䵽�ڴ�ľ�� 
	LPVOID ImageBase; //�ļ������� 
	DWORD dwFileSize; //�ļ��Ĵ�С 
} MAP_FILE_STRUCT;

	MAP_FILE_STRUCT 		MapFile ;


// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void SwitchView(int nFormView);
// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
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



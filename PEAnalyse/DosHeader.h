#pragma once



// CDosHeader 窗体视图

class CDosHeader : public CFormView
{
	DECLARE_DYNCREATE(CDosHeader)

public:
	CDosHeader();           // 动态创建所使用的受保护的构造函数
	virtual ~CDosHeader();

public:
	enum { IDD = IDD_DOS_HEADER };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


	DECLARE_MESSAGE_MAP()
public:
	
public:




	//void MyUpdateData();
public:
	afx_msg void OnBnClickedA();
};



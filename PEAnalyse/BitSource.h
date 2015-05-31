#pragma once



// CBitSource 窗体视图

class CBitSource : public CFormView
{
	DECLARE_DYNCREATE(CBitSource)

protected:
	CBitSource();           // 动态创建所使用的受保护的构造函数
	virtual ~CBitSource();

public:
	enum { IDD = IDD_BIT_SOURCE };
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
	afx_msg void OnBnClickedButton1();
};



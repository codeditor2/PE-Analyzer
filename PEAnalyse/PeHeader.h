#pragma once



// CPeHeader 窗体视图

class CPeHeader : public CFormView
{
	DECLARE_DYNCREATE(CPeHeader)

protected:
	CPeHeader();           // 动态创建所使用的受保护的构造函数
	virtual ~CPeHeader();

public:
	enum { IDD = IDD_PE_HEADER };
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



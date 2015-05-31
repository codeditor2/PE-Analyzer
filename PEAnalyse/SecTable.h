#pragma once
#include "afxcmn.h"



// CSecTable 窗体视图

class CSecTable : public CFormView
{
	DECLARE_DYNCREATE(CSecTable)

protected:
	CSecTable();           // 动态创建所使用的受保护的构造函数
	virtual ~CSecTable();

public:
	enum { IDD = IDD_SEC_TABLE };
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
	CListCtrl m_list;
public:
	afx_msg void OnBnClickedShow();
};



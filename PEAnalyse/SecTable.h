#pragma once
#include "afxcmn.h"



// CSecTable ������ͼ

class CSecTable : public CFormView
{
	DECLARE_DYNCREATE(CSecTable)

protected:
	CSecTable();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
public:
	afx_msg void OnBnClickedShow();
};



#pragma once
#include "afxcmn.h"



// CAloTwo 窗体视图

class CAloTwo : public CFormView
{
	DECLARE_DYNCREATE(CAloTwo)

protected:
	CAloTwo();           // 动态创建所使用的受保护的构造函数
	virtual ~CAloTwo();

public:
	enum { IDD = IDD_ALO_TWO };


	PIMAGE_IMPORT_DESCRIPTOR pImportDesc;

	int dllnumber;
	//DWORD value[30];

	void FindImport();
	//void SortByName(int s,int t);
	//void Calculate();
	//void ChangeImport();


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
	afx_msg void OnEnChangeEdit1();
	//相应鼠标单击事件
	//afx_msg void OnClickLeft();

	int m_dllnumber;
	CListCtrl m_list;

	struct _importitem
	{
		DWORD name;
		int	  number;
	};

	//引入模块数组
	_importitem importitem[30];

	//指针数组
	//char *name[30];


	DWORD m_value0;
	afx_msg void OnBnClickedButton3();
	long m_water;
	long m_water2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};



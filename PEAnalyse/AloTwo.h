#pragma once
#include "afxcmn.h"



// CAloTwo ������ͼ

class CAloTwo : public CFormView
{
	DECLARE_DYNCREATE(CAloTwo)

protected:
	CAloTwo();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	//��Ӧ��굥���¼�
	//afx_msg void OnClickLeft();

	int m_dllnumber;
	CListCtrl m_list;

	struct _importitem
	{
		DWORD name;
		int	  number;
	};

	//����ģ������
	_importitem importitem[30];

	//ָ������
	//char *name[30];


	DWORD m_value0;
	afx_msg void OnBnClickedButton3();
	long m_water;
	long m_water2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};



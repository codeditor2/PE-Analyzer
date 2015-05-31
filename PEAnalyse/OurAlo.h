#pragma once
#include "afxcmn.h"



// COurAlo ������ͼ

class COurAlo : public CFormView
{
	DECLARE_DYNCREATE(COurAlo)

protected:
	COurAlo();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~COurAlo();

public:
	enum { IDD = IDD_OUR_ALO };

	int firstnumber,secondnumber,thirdnumber,bitnumber;

	int onebit,fourbit,eightbit,_24bit,_32bit;

	int colornumber;

	long redusize;

	IMAGE_RESOURCE_DIRECTORY* pResourceRoot;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pRootEntry;

	//�ڶ���
	IMAGE_RESOURCE_DIRECTORY* pResourceSecond;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pSecondEntry;
	//������
	IMAGE_RESOURCE_DIRECTORY* pResourceThird;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pThirdEntry;
	//���Ĳ�
	IMAGE_RESOURCE_DATA_ENTRY* FourthData;

	//λͼ����
	IMAGE_RESOURCE_DIRECTORY* pBitSecond;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pBitSecondEntry;

	//������λͼ
	IMAGE_RESOURCE_DIRECTORY* pBitThird;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pBitThirdEntry;

	//���Ĳ�λͼ
	IMAGE_RESOURCE_DATA_ENTRY* pBitFourthData;

	//λͼ
	BITMAPINFOHEADER* pBitMapInfoHeader;
	
void FindResource() ;

void FindBit();

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
	afx_msg void OnBnClickedButton2();
	int m_bitnumber;
	int m_onebit;
	int m_fourbit;
	int m_eightbit;
	int m_24bit;
	int m_32bit;
	CListCtrl m_list;
	int m_colornumber;
	long m_redusize;
	long m_p1;
	long m_p2;
	long m_q1;
	long m_q2;
	afx_msg void OnBnClickedButton4();
	int m_counts;
};



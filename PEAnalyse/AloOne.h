#pragma once



// CAloOne ������ͼ

class CAloOne : public CFormView
{
	DECLARE_DYNCREATE(CAloOne)

protected:
	CAloOne();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAloOne();

public:
	enum { IDD = IDD_ALO_ONE };
	void FindResource();
	int firstnumber,secondnumber,thirdnumber;
	
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
	int m_firstnumber;
	int m_secondnumber;
	int m_thirdnumber;
	long p1;
	long q1;
	long p2;
	long q2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};



#pragma once



// CDosHeader ������ͼ

class CDosHeader : public CFormView
{
	DECLARE_DYNCREATE(CDosHeader)

public:
	CDosHeader();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��


	DECLARE_MESSAGE_MAP()
public:
	
public:




	//void MyUpdateData();
public:
	afx_msg void OnBnClickedA();
};



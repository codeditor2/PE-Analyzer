#pragma once



// CBitSource ������ͼ

class CBitSource : public CFormView
{
	DECLARE_DYNCREATE(CBitSource)

protected:
	CBitSource();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};



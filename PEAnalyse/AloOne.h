#pragma once



// CAloOne 窗体视图

class CAloOne : public CFormView
{
	DECLARE_DYNCREATE(CAloOne)

protected:
	CAloOne();           // 动态创建所使用的受保护的构造函数
	virtual ~CAloOne();

public:
	enum { IDD = IDD_ALO_ONE };
	void FindResource();
	int firstnumber,secondnumber,thirdnumber;
	
	IMAGE_RESOURCE_DIRECTORY* pResourceRoot;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pRootEntry;

	//第二层
	IMAGE_RESOURCE_DIRECTORY* pResourceSecond;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pSecondEntry;
	//第三层
	IMAGE_RESOURCE_DIRECTORY* pResourceThird;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pThirdEntry;
	//第四层
	IMAGE_RESOURCE_DATA_ENTRY* FourthData;

	//位图数据
	IMAGE_RESOURCE_DIRECTORY* pBitSecond;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pBitSecondEntry;

	//第三层位图
	IMAGE_RESOURCE_DIRECTORY* pBitThird;
	IMAGE_RESOURCE_DIRECTORY_ENTRY* pBitThirdEntry;

	//第四层位图
	IMAGE_RESOURCE_DATA_ENTRY* pBitFourthData;

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



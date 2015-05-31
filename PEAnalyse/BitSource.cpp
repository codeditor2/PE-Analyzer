// BitSource.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "BitSource.h"


// CBitSource

IMPLEMENT_DYNCREATE(CBitSource, CFormView)

CBitSource::CBitSource()
	: CFormView(CBitSource::IDD)
{

}

CBitSource::~CBitSource()
{
}

void CBitSource::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBitSource, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CBitSource::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBitSource 诊断

#ifdef _DEBUG
void CBitSource::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBitSource::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBitSource 消息处理程序

void CBitSource::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


}

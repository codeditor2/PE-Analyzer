// DosHeader.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "DosHeader.h"


extern PIMAGE_DOS_HEADER pDosHeader;
extern CString FilePath;

//extern PIMAGE_OPTIONAL_HEADER pOptionalHeader;


// CDosHeader

IMPLEMENT_DYNCREATE(CDosHeader, CFormView)

CDosHeader::CDosHeader()
	: CFormView(CDosHeader::IDD)
{

}

CDosHeader::~CDosHeader()
{
}

void CDosHeader::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDosHeader, CFormView)
	ON_BN_CLICKED(IDC_A, &CDosHeader::OnBnClickedA)
END_MESSAGE_MAP()


// CDosHeader 诊断

#ifdef _DEBUG
void CDosHeader::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDosHeader::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDosHeader 消息处理程序
/*
void CDosHeader::MyUpdateData()
{	
	CString cBuff;
	PIMAGE_DOS_HEADER TempDosHeader = pDosHeader;

	cBuff.Format(_T("%04lX"), TempDosHeader->e_magic);
	SetDlgItemText(IDC_MAGIC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_cblp);
	SetDlgItemText(IDC_CBLP, cBuff);
}*/

void CDosHeader::OnBnClickedA()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cBuff;
	PIMAGE_DOS_HEADER TempDosHeader = pDosHeader;

	//SetDlgItemText(IDC_FILEPATH,FilePath);
	SetDlgItemText(IDC_FILEPATH,"C:\\WINDOWS\\explorer.exe");

	cBuff.Format(_T("%04lX"), TempDosHeader->e_magic);
	SetDlgItemText(IDC_MAGIC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_cblp);
	SetDlgItemText(IDC_CBLP, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_cblp);
	SetDlgItemText(IDC_CBLP, cBuff);

	
	cBuff.Format(_T("%04lX"), TempDosHeader->e_cp);
	SetDlgItemText(IDC_CP, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_crlc);
	SetDlgItemText(IDC_CRLC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_cparhdr);
	SetDlgItemText(IDC_CPARHBR, cBuff);

	
	cBuff.Format(_T("%04lX"), TempDosHeader->e_minalloc);
	SetDlgItemText(IDC_MINALLOC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_maxalloc);
	SetDlgItemText(IDC_MAXALLOC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_ss);
	SetDlgItemText(IDC_SS, cBuff);

	
	cBuff.Format(_T("%04lX"), TempDosHeader->e_sp);
	SetDlgItemText(IDC_SP, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_csum);
	SetDlgItemText(IDC_CSUM, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_ip);
	SetDlgItemText(IDC_IP, cBuff);

	
	cBuff.Format(_T("%04lX"), TempDosHeader->e_cs);
	SetDlgItemText(IDC_CS,cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_lfarlc);
	SetDlgItemText(IDC_LFARLC, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_ovno);
	SetDlgItemText(IDC_OVNO, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_res[0]);
	SetDlgItemText(IDC_RES4, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_oemid);
	SetDlgItemText(IDC_OEMID, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_oeminfo);
	SetDlgItemText(IDC_OEMINFO, cBuff);

	cBuff.Format(_T("%04lX"), TempDosHeader->e_res2[0]);
	SetDlgItemText(IDC_RES2, cBuff);

	cBuff.Format(_T("%08lX"), TempDosHeader->e_lfanew);
	SetDlgItemText(IDC_LFANEW, cBuff);
}

// PeHeader.cpp : 实现文件
//

#include "stdafx.h"
#include "PEAnalyse.h"
#include "PeHeader.h"

extern PIMAGE_NT_HEADERS32 pNtHeader;
extern PIMAGE_FILE_HEADER	pFileHeader;
extern PIMAGE_OPTIONAL_HEADER		pOptionalHeader;
extern CString FilePath;

// CPeHeader

IMPLEMENT_DYNCREATE(CPeHeader, CFormView)

CPeHeader::CPeHeader()
	: CFormView(CPeHeader::IDD)
{

}

CPeHeader::~CPeHeader()
{
}

void CPeHeader::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPeHeader, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CPeHeader::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPeHeader 诊断

#ifdef _DEBUG
void CPeHeader::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPeHeader::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPeHeader 消息处理程序

void CPeHeader::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cBuff;
	PIMAGE_NT_HEADERS32 TempNtHeader = pNtHeader;

	//SetDlgItemText(IDC_EDIT19,FilePath);
	SetDlgItemText(IDC_EDIT19,"C:\\WINDOWS\\explorer.exe");

	cBuff.Format(_T("%08lX"), TempNtHeader->Signature);
	SetDlgItemText(IDC_EDIT2, cBuff);

	PIMAGE_FILE_HEADER TempFileHeader = pFileHeader;

	cBuff.Format(_T("%08lX"), TempFileHeader->Machine);
	SetDlgItemText(IDC_EDIT1, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->NumberOfSections);
	SetDlgItemText(IDC_EDIT3, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->TimeDateStamp);
	SetDlgItemText(IDC_EDIT4, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->PointerToSymbolTable);
	SetDlgItemText(IDC_EDIT5, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->NumberOfSymbols);
	SetDlgItemText(IDC_EDIT6, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->SizeOfOptionalHeader);
	SetDlgItemText(IDC_EDIT7, cBuff);

	cBuff.Format(_T("%08lX"), TempFileHeader->Characteristics);
	SetDlgItemText(IDC_EDIT8, cBuff);

	PIMAGE_OPTIONAL_HEADER TempOptionalHeader = pOptionalHeader;

	cBuff.Format(_T("%08lX"), TempOptionalHeader->AddressOfEntryPoint);
	SetDlgItemText(IDC_EDIT9, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->BaseOfCode);
	SetDlgItemText(IDC_EDIT10, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->BaseOfData);
	SetDlgItemText(IDC_EDIT11, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->FileAlignment);
	SetDlgItemText(IDC_EDIT12, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->ImageBase);
	SetDlgItemText(IDC_EDIT13, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->DllCharacteristics);
	SetDlgItemText(IDC_EDIT14, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->SizeOfImage);
	SetDlgItemText(IDC_EDIT16, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->SizeOfHeaders);
	SetDlgItemText(IDC_EDIT15, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->Subsystem);
	SetDlgItemText(IDC_EDIT17, cBuff);

	cBuff.Format(_T("%08lX"), TempOptionalHeader->SectionAlignment);
	SetDlgItemText(IDC_EDIT18, cBuff);
}



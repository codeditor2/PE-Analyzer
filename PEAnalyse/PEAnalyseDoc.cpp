// PEAnalyseDoc.cpp : CPEAnalyseDoc ���ʵ��
//

#include "stdafx.h"
#include "PEAnalyse.h"

#include "PEAnalyseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPEAnalyseDoc

IMPLEMENT_DYNCREATE(CPEAnalyseDoc, CDocument)

BEGIN_MESSAGE_MAP(CPEAnalyseDoc, CDocument)
END_MESSAGE_MAP()


// CPEAnalyseDoc ����/����

CPEAnalyseDoc::CPEAnalyseDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CPEAnalyseDoc::~CPEAnalyseDoc()
{
}

BOOL CPEAnalyseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CPEAnalyseDoc ���л�

void CPEAnalyseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CPEAnalyseDoc ���

#ifdef _DEBUG
void CPEAnalyseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPEAnalyseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPEAnalyseDoc ����

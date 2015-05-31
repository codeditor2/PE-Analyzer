// PEAnalyseView.cpp : CPEAnalyseView ���ʵ��
//

#include "stdafx.h"
#include "PEAnalyse.h"

#include "PEAnalyseDoc.h"
#include "PEAnalyseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPEAnalyseView

IMPLEMENT_DYNCREATE(CPEAnalyseView, CView)

BEGIN_MESSAGE_MAP(CPEAnalyseView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPEAnalyseView ����/����

CPEAnalyseView::CPEAnalyseView()
{
	// TODO: �ڴ˴���ӹ������

}

CPEAnalyseView::~CPEAnalyseView()
{
}

BOOL CPEAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPEAnalyseView ����

void CPEAnalyseView::OnDraw(CDC* /*pDC*/)
{
	CPEAnalyseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPEAnalyseView ��ӡ

BOOL CPEAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPEAnalyseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPEAnalyseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CPEAnalyseView ���

#ifdef _DEBUG
void CPEAnalyseView::AssertValid() const
{
	CView::AssertValid();
}

void CPEAnalyseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPEAnalyseDoc* CPEAnalyseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPEAnalyseDoc)));
	return (CPEAnalyseDoc*)m_pDocument;
}
#endif //_DEBUG


// CPEAnalyseView ��Ϣ�������

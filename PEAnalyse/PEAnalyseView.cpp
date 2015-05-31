// PEAnalyseView.cpp : CPEAnalyseView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPEAnalyseView 构造/析构

CPEAnalyseView::CPEAnalyseView()
{
	// TODO: 在此处添加构造代码

}

CPEAnalyseView::~CPEAnalyseView()
{
}

BOOL CPEAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPEAnalyseView 绘制

void CPEAnalyseView::OnDraw(CDC* /*pDC*/)
{
	CPEAnalyseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPEAnalyseView 打印

BOOL CPEAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPEAnalyseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPEAnalyseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CPEAnalyseView 诊断

#ifdef _DEBUG
void CPEAnalyseView::AssertValid() const
{
	CView::AssertValid();
}

void CPEAnalyseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPEAnalyseDoc* CPEAnalyseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPEAnalyseDoc)));
	return (CPEAnalyseDoc*)m_pDocument;
}
#endif //_DEBUG


// CPEAnalyseView 消息处理程序

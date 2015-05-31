// PEAnalyseDoc.cpp : CPEAnalyseDoc 类的实现
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


// CPEAnalyseDoc 构造/析构

CPEAnalyseDoc::CPEAnalyseDoc()
{
	// TODO: 在此添加一次性构造代码

}

CPEAnalyseDoc::~CPEAnalyseDoc()
{
}

BOOL CPEAnalyseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CPEAnalyseDoc 序列化

void CPEAnalyseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CPEAnalyseDoc 诊断

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


// CPEAnalyseDoc 命令

// PEAnalyseDoc.h : CPEAnalyseDoc ��Ľӿ�
//


#pragma once


class CPEAnalyseDoc : public CDocument
{
protected: // �������л�����
	CPEAnalyseDoc();
	DECLARE_DYNCREATE(CPEAnalyseDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CPEAnalyseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};



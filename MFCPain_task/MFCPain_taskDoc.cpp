
// MFCPain_taskDoc.cpp : implementation of the CMFCPain_taskDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCPain_task.h"
#endif

#include "MFCPain_taskDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCPain_taskDoc

IMPLEMENT_DYNCREATE(CMFCPain_taskDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCPain_taskDoc, CDocument)
END_MESSAGE_MAP()


// CMFCPain_taskDoc construction/destruction

CMFCPain_taskDoc::CMFCPain_taskDoc()
{
	// TODO: add one-time construction code here

}

CMFCPain_taskDoc::~CMFCPain_taskDoc()
{
}

BOOL CMFCPain_taskDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_linePoints.clear();				//

	return TRUE;
}




// CMFCPain_taskDoc serialization

void CMFCPain_taskDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		int size = m_linePoints.size();	//
		ar << size;						//
		for (auto point : m_linePoints)	//
			ar << point.x << point.y;	//
	}
	else
	{
		// TODO: add loading code here
		int size;							//
		ar >> size;							//
		CPoint point;						//
		for (int i = 0; i < size; ++i)		//
		{									//
			ar >> point.x >> point.y;		//
			m_linePoints.push_back(point);	//
		}									//
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCPain_taskDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCPain_taskDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCPain_taskDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCPain_taskDoc diagnostics

#ifdef _DEBUG
void CMFCPain_taskDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCPain_taskDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCPain_taskDoc commands


BOOL CMFCPain_taskDoc::OnOpenDocument(LPCTSTR lpszPathName)
{

	m_linePoints.clear();

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Add your specialized creation code here

	return TRUE;
}


// MFCPain_taskView.cpp : implementation of the CMFCPain_taskView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCPain_task.h"
#endif

#include "MFCPain_taskDoc.h"
#include "MFCPain_taskView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPain_taskView

IMPLEMENT_DYNCREATE(CMFCPain_taskView, CView)

BEGIN_MESSAGE_MAP(CMFCPain_taskView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCPain_taskView construction/destruction

CMFCPain_taskView::CMFCPain_taskView()
{
	// TODO: add construction code here

}

CMFCPain_taskView::~CMFCPain_taskView()
{
}

BOOL CMFCPain_taskView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCPain_taskView drawing

void CMFCPain_taskView::OnDraw(CDC* pDC)	//uncommentpDC
{
	CMFCPain_taskDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	const std::vector<CPoint>& linePoints = pDoc->GetLinePoints();	//

	int sizeLinePoints = linePoints.size();							//
	if (sizeLinePoints > 0)											//
	{
		CPen pen(PS_SOLID, 4, RGB(0, 0, 200));	//
		CPen *oldPen = pDC->SelectObject(&pen);	//
		pDC->MoveTo(linePoints[0]);				//
		for (int i = 1; i < sizeLinePoints; ++i)		//
		{												//
			pDC->LineTo(linePoints[i]);						//
		}												//
		pDC->SelectObject(oldPen);						//
	}
}

void CMFCPain_taskView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCPain_taskView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCPain_taskView diagnostics

#ifdef _DEBUG
void CMFCPain_taskView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPain_taskView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPain_taskDoc* CMFCPain_taskView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPain_taskDoc)));
	return (CMFCPain_taskDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPain_taskView message handlers


void CMFCPain_taskView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMFCPain_taskDoc* pDoc = GetDocument();	//
	ASSERT_VALID(pDoc);						//
	if (pDoc)								//
	{							//
	//start mouse drag
		m_mouseDragging = true;				//
		//add a new line point
		pDoc->AddLinePoint(point);				//

		//draw a new data
		Invalidate();							//
		UpdateWindow();							//
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFCPain_taskView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//end mouse drag
	m_mouseDragging = false;				//

	CView::OnLButtonUp(nFlags, point);
}


void CMFCPain_taskView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_mouseDragging)						//
	{											//
		CMFCPain_taskDoc* pDoc = GetDocument();	//
		ASSERT_VALID(pDoc);						//
		if (pDoc)								//
		{										
			//add a new line point
			pDoc->AddLinePoint(point);				//

			//draw a new data
			Invalidate();							//
			UpdateWindow();							//
		}										//
	}											//

	CView::OnMouseMove(nFlags, point);
}

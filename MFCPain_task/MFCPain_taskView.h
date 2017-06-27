
// MFCPain_taskView.h : interface of the CMFCPain_taskView class
//

#pragma once


class CMFCPain_taskView : public CView
{
protected: // create from serialization only
	CMFCPain_taskView();
	DECLARE_DYNCREATE(CMFCPain_taskView)

// Attributes
public:
	CMFCPain_taskDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCPain_taskView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	bool m_mouseDragging{ false };

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCPain_taskView.cpp
inline CMFCPain_taskDoc* CMFCPain_taskView::GetDocument() const
   { return reinterpret_cast<CMFCPain_taskDoc*>(m_pDocument); }
#endif


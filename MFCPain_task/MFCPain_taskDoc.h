
// MFCPain_taskDoc.h : interface of the CMFCPain_taskDoc class
//


#pragma once
#include <vector>	//


class CMFCPain_taskDoc : public CDocument
{
protected: // create from serialization only
	CMFCPain_taskDoc();
	DECLARE_DYNCREATE(CMFCPain_taskDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCPain_taskDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	const std::vector<CPoint>& GetLinePoints() { return m_linePoints; }			//
	void AddLinePoint(const CPoint& point) { m_linePoints.push_back(point); }	//

protected:
	std::vector<CPoint> m_linePoints;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};

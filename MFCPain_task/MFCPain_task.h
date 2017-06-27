
// MFCPain_task.h : main header file for the MFCPain_task application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCPain_taskApp:
// See MFCPain_task.cpp for the implementation of this class
//

class CMFCPain_taskApp : public CWinAppEx
{
public:
	CMFCPain_taskApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCPain_taskApp theApp;

// FF7Extractor.h : main header file for the FF7EXTRACTOR application
//

#if !defined(AFX_FF7EXTRACTOR_H__A3C19B75_5B4C_4FA8_82E8_2165BAD15E55__INCLUDED_)
#define AFX_FF7EXTRACTOR_H__A3C19B75_5B4C_4FA8_82E8_2165BAD15E55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


struct Header
{
	_int16 nReserved;
	char chTitle[10];
	_int32 nFiles;
};

struct FileInfo
{
	char chFileName[20];
	_int32 nHeaderOffset;
//	_int16 nReserved1;
//	char nReserved2;
};

struct FileHeader
{
	char chFileName[20];
	_int32 nFileSize;
};

struct FileStatus
{
	char chFileName[20];
	_int32 nHeaderOffset;
	_int32 nFileOffset;
	_int32 nFileSize;
};


#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFF7ExtractorApp:
// See FF7Extractor.cpp for the implementation of this class
//

class CFF7ExtractorApp : public CWinApp
{
public:
	CFF7ExtractorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFF7ExtractorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFF7ExtractorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FF7EXTRACTOR_H__A3C19B75_5B4C_4FA8_82E8_2165BAD15E55__INCLUDED_)

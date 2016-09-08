#if !defined(AFX_FILELISTDIALOG_H__F47B4BC2_3C38_43E8_B353_F873B827FAFB__INCLUDED_)
#define AFX_FILELISTDIALOG_H__F47B4BC2_3C38_43E8_B353_F873B827FAFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileListDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileListDialog dialog

class CFileListDialog : public CDialog
{
// Construction
public:
	CFileListDialog(CWnd* pParent = NULL);   // standard constructor
	CArray <FileStatus,FileStatus> *m_pFileStatusList;
	LONG m_nFile;

// Dialog Data
	//{{AFX_DATA(CFileListDialog)
	enum { IDD = IDD_DIALOG_FILELIST };
	CListCtrl	m_lstFiles;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileListDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileListDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILELISTDIALOG_H__F47B4BC2_3C38_43E8_B353_F873B827FAFB__INCLUDED_)

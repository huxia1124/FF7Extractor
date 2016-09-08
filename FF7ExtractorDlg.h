// FF7ExtractorDlg.h : header file
//

#if !defined(AFX_FF7EXTRACTORDLG_H__3CB9EEBF_05FC_44D8_961E_B591FFC357B5__INCLUDED_)
#define AFX_FF7EXTRACTORDLG_H__3CB9EEBF_05FC_44D8_961E_B591FFC357B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFF7ExtractorDlg dialog

class CFF7ExtractorDlg : public CDialog
{
// Construction
public:
	LONG BytesCopy(CFile *pTgFile,CFile *pScFile,LONG nBeginOffset,LONG nByte);
	int Extract();
	int EvaluationFile();
	CFF7ExtractorDlg(CWnd* pParent = NULL);	// standard constructor
	CArray <FileStatus,FileStatus> FileStatusList;
	LONG m_nFile;

// Dialog Data
	//{{AFX_DATA(CFF7ExtractorDlg)
	enum { IDD = IDD_FF7EXTRACTOR_DIALOG };
	CButton	m_btnExtract;
	CStatic	m_stCurExtFile;
	CButton	m_btnListFile;
	CProgressCtrl	m_pbExt;
	CString	m_strScFile;
	CString	m_strTgFolder;
	CString	m_strCurExtFile;
	CString	m_strFileCount;
	CString	m_strFileSize;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFF7ExtractorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFF7ExtractorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBrowseSourcefile();
	afx_msg void OnChangeEditSourcefile();
	afx_msg void OnButtonExtract();
	afx_msg void OnButtonClose();
	afx_msg void OnButtonListfiles();
	afx_msg void OnButtonStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int bStop;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FF7EXTRACTORDLG_H__3CB9EEBF_05FC_44D8_961E_B591FFC357B5__INCLUDED_)

// FileListDialog.cpp : implementation file
//

#include "stdafx.h"
#include "FF7Extractor.h"
#include "FileListDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileListDialog dialog


CFileListDialog::CFileListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFileListDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileListDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFileListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileListDialog)
	DDX_Control(pDX, IDC_LIST_FILES, m_lstFiles);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileListDialog, CDialog)
	//{{AFX_MSG_MAP(CFileListDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileListDialog message handlers

BOOL CFileListDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	BeginWaitCursor();
	m_lstFiles.InsertColumn(0,_T("文件名"),LVCFMT_LEFT,100);
	m_lstFiles.InsertColumn(1,_T("大小"),LVCFMT_LEFT,100);
	m_lstFiles.InsertColumn(2,_T("位置[OFFSET]"),LVCFMT_LEFT,140);

	int ifact=-1;
	CString strTemp;
	m_lstFiles.SetItemCount(m_nFile);
	for(LONG i=1;i<=m_nFile;i++)
	{
		ifact=m_lstFiles.InsertItem(i-1,m_pFileStatusList->GetAt(i-1).chFileName);
		strTemp.Format("%10.2lfK",m_pFileStatusList->GetAt(i-1).nFileSize/1024.00);
		m_lstFiles.SetItemText(ifact,1,strTemp);
		strTemp.Format("%ld",m_pFileStatusList->GetAt(i-1).nFileOffset);
		m_lstFiles.SetItemText(ifact,2,strTemp);
	}
	EndWaitCursor();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFileListDialog::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

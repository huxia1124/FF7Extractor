// FF7ExtractorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FF7Extractor.h"
#include "FF7ExtractorDlg.h"
#include "FileListDialog.h"
#include "ExtraUse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFF7ExtractorDlg dialog

CFF7ExtractorDlg::CFF7ExtractorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFF7ExtractorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFF7ExtractorDlg)
	m_strScFile = _T("");
	m_strTgFolder = _T("");
	m_strCurExtFile = _T("");
	m_strFileCount = _T("");
	m_strFileSize = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFF7ExtractorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFF7ExtractorDlg)
	DDX_Control(pDX, IDC_BUTTON_EXTRACT, m_btnExtract);
	DDX_Control(pDX, IDC_STATIC_CURRENTFILE, m_stCurExtFile);
	DDX_Control(pDX, IDC_BUTTON_LISTFILES, m_btnListFile);
	DDX_Control(pDX, IDC_PROGRESS_EXTRACT, m_pbExt);
	DDX_Text(pDX, IDC_EDIT_SOURCEFILE, m_strScFile);
	DDX_Text(pDX, IDC_EDIT_TARGEFOLDER, m_strTgFolder);
	DDX_Text(pDX, IDC_STATIC_CURRENTFILE, m_strCurExtFile);
	DDX_Text(pDX, IDC_STATIC_FILECOUNT, m_strFileCount);
	DDX_Text(pDX, IDC_STATIC_FILESIZE, m_strFileSize);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFF7ExtractorDlg, CDialog)
	//{{AFX_MSG_MAP(CFF7ExtractorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_SOURCEFILE, OnButtonBrowseSourcefile)
	ON_EN_CHANGE(IDC_EDIT_SOURCEFILE, OnChangeEditSourcefile)
	ON_BN_CLICKED(IDC_BUTTON_EXTRACT, OnButtonExtract)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_LISTFILES, OnButtonListfiles)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFF7ExtractorDlg message handlers

BOOL CFF7ExtractorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_strTgFolder=_T("H:\\F\\");
	UpdateData(FALSE);
	m_nFile=-1;
	bStop=0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFF7ExtractorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFF7ExtractorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFF7ExtractorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFF7ExtractorDlg::OnButtonBrowseSourcefile() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFileDialog fd(TRUE,_T("*.LGP"),m_strScFile,OFN_HIDEREADONLY,_T("FF7 Data(*.LGP)|*.LGP||"));

	if(fd.DoModal()==IDOK)
	{
		m_strScFile=fd.GetPathName();
	}
	UpdateData(FALSE);

	EvaluationFile();
}

int CFF7ExtractorDlg::EvaluationFile()
{
	m_nFile=-1;
	UpdateData(TRUE);

	CFile file;
	if(!file.Open(m_strScFile,CFile::modeRead))
	{
		m_strFileSize=_T("?");
		m_strFileCount=_T("?");
		UpdateData(FALSE);
		m_btnListFile.EnableWindow(FALSE);
		m_btnExtract.EnableWindow(FALSE);
		m_nFile=0;
		return -1;
	}

	CFileStatus fs;
	file.GetStatus(fs);

	m_strFileSize.Format("%ld",fs.m_size);
	Header fheader;
	file.Read(&fheader,sizeof(Header));

	m_strFileCount.Format("%ld",fheader.nFiles);
	m_nFile=fheader.nFiles;

	UpdateData(FALSE);

	file.Close();
	m_btnListFile.EnableWindow(TRUE);
	m_btnExtract.EnableWindow(TRUE);
	return 0;
}

void CFF7ExtractorDlg::OnChangeEditSourcefile() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	EvaluationFile();	
}

void CFF7ExtractorDlg::OnButtonExtract() 
{
	// TODO: Add your control notification handler code here
	Extract();
}

int CFF7ExtractorDlg::Extract()
{
	m_btnExtract.EnableWindow(FALSE);
	BeginWaitCursor();
	UpdateData(TRUE);
	CFile scFile;
	if(!scFile.Open(m_strScFile,CFile::modeRead))
	{
		m_btnExtract.EnableWindow(TRUE);
		EndWaitCursor();
		return -1;
	}
	Header header;
	scFile.Read(&header,sizeof(Header));

	FileStatusList.SetSize(header.nFiles);
	FileInfo finfo;
	for(LONG i=1;i<=header.nFiles;i++)
	{
		scFile.Read(&finfo,sizeof(FileInfo));
		scFile.Seek(3,CFile::current);
		strcpy(FileStatusList[i-1].chFileName,finfo.chFileName);
		FileStatusList[i-1].nHeaderOffset=finfo.nHeaderOffset;
		FileStatusList[i-1].nFileOffset=finfo.nHeaderOffset+sizeof(FileHeader);
	}
	FileHeader fheader;
	for(i=1;i<=header.nFiles;i++)
	{
		scFile.Seek(FileStatusList[i-1].nHeaderOffset,CFile::begin);
		scFile.Read(&fheader,sizeof(FileHeader));
		FileStatusList[i-1].nFileSize=fheader.nFileSize;
	}

	if(m_strTgFolder.Right(1)!=_T('\\'))
		m_strTgFolder+=_T("\\");

	XMkDir(m_strTgFolder);

	CString strTgFile;
	CFile tgFile;

	m_pbExt.SetRange(0,header.nFiles);
	MSG msg;
	for(i=1;i<=header.nFiles;i++)
	{
		strTgFile=m_strTgFolder+FileStatusList[i-1].chFileName;
		m_stCurExtFile.SetWindowText(strTgFile);
		tgFile.Open(strTgFile,CFile::modeCreate|CFile::modeWrite);
		BytesCopy(&tgFile,&scFile,FileStatusList[i-1].nFileOffset,FileStatusList[i-1].nFileSize);
		tgFile.Close();
		m_pbExt.SetPos(i);

		while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			AfxGetApp()->PumpMessage();
		}
		if(bStop)
		{
			bStop=0;
			scFile.Close();
			m_btnExtract.EnableWindow(TRUE);
			EndWaitCursor();

			MessageBox("被用户中止!","STOP",48);
			return 1;
		}
	}

	scFile.Close();
	m_btnExtract.EnableWindow(TRUE);
	EndWaitCursor();

	m_pbExt.SetPos(0);
	MessageBox("文件已经被成功解开!");
	return 0;
}

LONG CFF7ExtractorDlg::BytesCopy(CFile *pTgFile, CFile *pScFile, LONG nBeginOffset, LONG nByte)
{
	pTgFile->SeekToBegin();
	pScFile->Seek(nBeginOffset,CFile::begin);

#define BUFLEN 100000
	char buf[BUFLEN];
	LONG nBlock;
	LONG nLeft;

	nBlock=nByte/BUFLEN;
	nLeft=nByte%BUFLEN;

	for(LONG i=1;i<=nBlock;i++)
	{
		pScFile->Read(buf,BUFLEN);
		pTgFile->Write(buf,BUFLEN);
	}
	pScFile->Read(buf,nLeft);
	pTgFile->Write(buf,nLeft);

	return 0;
#undef BUFLEN
}

void CFF7ExtractorDlg::OnButtonClose() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CFF7ExtractorDlg::OnButtonListfiles() 
{
	// TODO: Add your control notification handler code here
	BeginWaitCursor();
		UpdateData(TRUE);
		CFile scFile;
		if(!scFile.Open(m_strScFile,CFile::modeRead))
			return ;
		Header header;
		scFile.Read(&header,sizeof(Header));

		FileStatusList.SetSize(header.nFiles);
		FileInfo finfo;
		for(LONG i=1;i<=header.nFiles;i++)
		{
			scFile.Read(&finfo,sizeof(FileInfo));
			scFile.Seek(3,CFile::current);
			strcpy(FileStatusList[i-1].chFileName,finfo.chFileName);
			FileStatusList[i-1].nHeaderOffset=finfo.nHeaderOffset;
			FileStatusList[i-1].nFileOffset=finfo.nHeaderOffset+sizeof(FileHeader);
		}
		FileHeader fheader;
		for(i=1;i<=header.nFiles;i++)
		{
			scFile.Seek(FileStatusList[i-1].nHeaderOffset,CFile::begin);
			scFile.Read(&fheader,sizeof(FileHeader));
			FileStatusList[i-1].nFileSize=fheader.nFileSize;
		}
		scFile.Close();
	EndWaitCursor();

	CFileListDialog fld;
	fld.m_nFile=m_nFile;
	fld.m_pFileStatusList=&FileStatusList;

	m_btnListFile.EnableWindow(FALSE);
	fld.DoModal();
	m_btnListFile.EnableWindow(TRUE);
}

void CFF7ExtractorDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here

	bStop=1;
	
}

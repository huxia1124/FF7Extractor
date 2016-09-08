; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFF7ExtractorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FF7Extractor.h"

ClassCount=4
Class1=CFF7ExtractorApp
Class2=CFF7ExtractorDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_FF7EXTRACTOR_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CFileListDialog
Resource4=IDD_DIALOG_FILELIST

[CLS:CFF7ExtractorApp]
Type=0
HeaderFile=FF7Extractor.h
ImplementationFile=FF7Extractor.cpp
Filter=N

[CLS:CFF7ExtractorDlg]
Type=0
HeaderFile=FF7ExtractorDlg.h
ImplementationFile=FF7ExtractorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFF7ExtractorDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FF7ExtractorDlg.h
ImplementationFile=FF7ExtractorDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FF7EXTRACTOR_DIALOG]
Type=1
Class=CFF7ExtractorDlg
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_SOURCEFILE,edit,1350631552
Control3=IDC_BUTTON_BROWSE_TARGEFOLDER,button,1342242816
Control4=IDC_STATIC,static,1342308354
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT_TARGEFOLDER,edit,1350631552
Control7=IDC_BUTTON_BROWSE_SOURCEFILE,button,1342242816
Control8=IDC_STATIC,static,1342308354
Control9=IDC_BUTTON_EXTRACT,button,1476460544
Control10=IDC_BUTTON_CLOSE,button,1342242816
Control11=IDC_BUTTON_STOP,button,1342242816
Control12=IDC_PROGRESS_EXTRACT,msctls_progress32,1342177280
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_BUTTON_LISTFILES,button,1476460544
Control17=IDC_STATIC_FILECOUNT,static,1342308352
Control18=IDC_STATIC_FILESIZE,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC_CURRENTFILE,static,1342308352

[DLG:IDD_DIALOG_FILELIST]
Type=1
Class=CFileListDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_LIST_FILES,SysListView32,1350631425

[CLS:CFileListDialog]
Type=0
HeaderFile=FileListDialog.h
ImplementationFile=FileListDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_FILES
VirtualFilter=dWC


; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMemDC
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mymemory.h"
LastPage=0

ClassCount=11
Class1=CMymemoryApp
Class2=CMymemoryDoc
Class3=CMymemoryView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class10=CPicButton
Class11=CMemDC
Resource2=IDD_ABOUTBOX

[CLS:CMymemoryApp]
Type=0
HeaderFile=mymemory.h
ImplementationFile=mymemory.cpp
Filter=N

[CLS:CMymemoryDoc]
Type=0
HeaderFile=mymemoryDoc.h
ImplementationFile=mymemoryDoc.cpp
Filter=N

[CLS:CMymemoryView]
Type=0
HeaderFile=mymemoryView.h
ImplementationFile=mymemoryView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=mymemory.cpp
ImplementationFile=mymemory.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:CPicButton]
Type=0
HeaderFile=PicButton.h
ImplementationFile=PicButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[CLS:CMemDC]
Type=0
HeaderFile=MemDC.h
ImplementationFile=MemDC.cpp
BaseClass=CButton
Filter=W


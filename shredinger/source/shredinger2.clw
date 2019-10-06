; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAutoPage
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "shredinger2.h"

ClassCount=5
Class1=CShredinger2App
Class2=CShredinger2Dlg

ResourceCount=4
Resource2=IDD_SHREDINGER2_DIALOG (English (U.S.))
Resource1=IDR_MAINFRAME
Class3=CManPage
Class4=CSheet
Resource3=IDD_MAN_PAGE
Class5=CAutoPage
Resource4=IDD_AUTO_PAGE

[CLS:CShredinger2App]
Type=0
HeaderFile=shredinger2.h
ImplementationFile=shredinger2.cpp
Filter=N

[CLS:CShredinger2Dlg]
Type=0
HeaderFile=shredinger2Dlg.h
ImplementationFile=shredinger2Dlg.cpp
Filter=D
LastObject=CShredinger2Dlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_SHREDINGER2_DIALOG (English (U.S.))]
Type=1
Class=CManPage
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_MAN_PAGE]
Type=1
Class=CShredinger2Dlg
ControlCount=12
Control1=IDC_CHENGE,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_U,edit,1350631552
Control6=IDC_EDIT_A,edit,1350631552
Control7=IDC_EDIT_L,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_Z,edit,1350631552
Control12=IDC_EDIT_Energy,edit,1350631552

[CLS:CManPage]
Type=0
HeaderFile=ManPage.h
ImplementationFile=ManPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CManPage
VirtualFilter=idWC

[CLS:CSheet]
Type=0
HeaderFile=Sheet.h
ImplementationFile=Sheet.cpp
BaseClass=CPropertySheet
Filter=W

[CLS:CAutoPage]
Type=0
HeaderFile=AutoPage.h
ImplementationFile=AutoPage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CAutoPage

[DLG:IDD_AUTO_PAGE]
Type=1
Class=CAutoPage
ControlCount=16
Control1=IDC_CHENGE,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_N,edit,1350631552
Control7=IDC_EDIT_U,edit,1350631552
Control8=IDC_EDIT_A,edit,1350631552
Control9=IDC_EDIT_L,edit,1350631552
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_Z,edit,1350631552
Control14=IDC_EDIT_Energy,edit,1350631552
Control15=IDC_BUTTONshowE,button,1342242816
Control16=IDC_STATIC,static,1342308352


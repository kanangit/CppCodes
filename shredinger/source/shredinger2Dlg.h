// shredinger2Dlg.h : header file
//

#if !defined(AFX_SHREDINGER2DLG_H__1AE6B750_EC56_11D8_811C_EF62D7D2861F__INCLUDED_)
#define AFX_SHREDINGER2DLG_H__1AE6B750_EC56_11D8_811C_EF62D7D2861F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShredinger2Dlg dialog

class CShredinger2Dlg : public CDialog
{
// Construction
public:
	CShredinger2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShredinger2Dlg)
	enum { IDD = IDD_MAN_PAGE };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShredinger2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShredinger2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHREDINGER2DLG_H__1AE6B750_EC56_11D8_811C_EF62D7D2861F__INCLUDED_)

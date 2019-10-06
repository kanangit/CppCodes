#if !defined(AFX_SHEET_H__90171121_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_)
#define AFX_SHEET_H__90171121_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sheet.h : header file
//

#include "ManPage.h"
#include "AutoPage.h"
/////////////////////////////////////////////////////////////////////////////
// CSheet

class CSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheet)

// Construction
public:
	CSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

	CManPage m_ManPage;
	CAutoPage m_AutoPage;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEET_H__90171121_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_)

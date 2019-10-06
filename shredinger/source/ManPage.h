#if !defined(AFX_MANPAGE_H__7B5EC1C1_ED4A_11D8_811C_CACAD3740D3E__INCLUDED_)
#define AFX_MANPAGE_H__7B5EC1C1_ED4A_11D8_811C_CACAD3740D3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManPage dialog

class CManPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CManPage)

// Construction
public:
	void evenness1UP();
	void evenness1();
	void evenness2UP();
	void evenness2();
	float i_Width_a;
	float i_Width_l;
	CString String;
	float i_PotentialEnergy;
	
   
	float i_ColStep;
	double Y[3];
	bool fa;
	double A,H, x ,beta;	
	float E, Control,ScaleX,ScaleY;

	CManPage();
	~CManPage();

// Dialog Data
	//{{AFX_DATA(CManPage)
	enum { IDD = IDD_MAN_PAGE };
	double	m_a;
	double	m_l;
	double	m_U;
	int		m_z;
	int     m_H;
	double	m_Energy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CManPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HCURSOR OnQueryDragIcon();

	// Generated message map functions
	//{{AFX_MSG(CManPage)
	afx_msg void OnChenge();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANPAGE_H__7B5EC1C1_ED4A_11D8_811C_CACAD3740D3E__INCLUDED_)

#if !defined(AFX_AUTOPAGE_H__90171122_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_)
#define AFX_AUTOPAGE_H__90171122_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AutoPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutoPage dialog

class CAutoPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CAutoPage)

// Construction
public:
	float i_Width_a;
	float i_Width_l;
	CString String;
	float i_PotentialEnergy;
	double EState[20];
    float i_NumCondition;
	float i_ColStep;
	double Y[3];
	double calc2(double E2);
	double calc2UP(double E2 );
	double calc1(double E1);
	double calc1UP( double E1 );
	bool fa;
	double A,H, x ,beta;	
	float E, Control,ScaleX,ScaleY;


	void evenness2();
	void evenness1();
	void evenness1UP();
	void evenness2UP();

	CAutoPage();
	~CAutoPage();

// Dialog Data
	//{{AFX_DATA(CAutoPage)
	enum { IDD = IDD_AUTO_PAGE };
	double	m_a;
	double	m_l;
	int		m_n;
	double	m_U;
	int		m_z;
	CString	m_Energy;
	int     m_H;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAutoPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	HICON m_hIcon;
	HCURSOR OnQueryDragIcon();
	void OnPaint();
	//BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CAutoPage)
	afx_msg void OnChenge();
	afx_msg void OnBUTTONshowE();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOPAGE_H__90171122_ED5A_11D8_811C_A4E1DBE19377__INCLUDED_)

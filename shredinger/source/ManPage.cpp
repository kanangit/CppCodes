// ManPage.cpp : implementation file
//

#include "stdafx.h"
#include "shredinger2.h"
#include "ManPage.h"
#include  <Math.h>

#define X_                20
#define Y_				  20

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManPage property page

IMPLEMENT_DYNCREATE(CManPage, CPropertyPage)

CManPage::CManPage() : CPropertyPage(CManPage::IDD)
{
	//{{AFX_DATA_INIT(CManPage)
	m_a = 6.0;
	m_l = 1.0;
	m_U = 3.0;
	m_z = 2;
	m_H = 10000;
	m_Energy = 2.07;
	//}}AFX_DATA_INIT
}

CManPage::~CManPage()
{
}

void CManPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManPage)
	DDX_Text(pDX, IDC_EDIT_A, m_a);
	DDX_Text(pDX, IDC_EDIT_L, m_l);
	DDX_Text(pDX, IDC_EDIT_U, m_U);
	DDX_Text(pDX, IDC_EDIT_Z, m_z);
	DDV_MinMaxInt(pDX, m_z, 0, 19);
	DDX_Text(pDX, IDC_EDIT_Energy, m_Energy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManPage, CPropertyPage)
	//{{AFX_MSG_MAP(CManPage)
	ON_BN_CLICKED(IDC_CHENGE, OnChenge)
	
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManPage message handlers

void CManPage::OnChenge() 
{
	UpdateData();					

	i_ColStep = m_H;					 	
	 
	i_PotentialEnergy = m_U;
	i_Width_a = m_a;			
	i_Width_l = m_l;
	
	Invalidate();	
}

void CManPage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect(10,10,11,11);
	GetClientRect(&rect);
	char ch[5];
	dc.Rectangle(X_, 110, rect.Width()-X_, rect.Height()-Y_);
	int rectHeight = rect.Height();
	
	double ScaleX1;
	double PaintHeight;
	PaintHeight = rect.Height() - 1.5 * Y_ - 120;
	
	int CenterY;
	ScaleX1 = (rect.Width()-X_-X_)/(i_Width_a);
	CenterY = (rect.Height()-Y_+110)/2;
	

	dc.MoveTo(X_, CenterY);
	dc.LineTo(rect.Width()-X_, CenterY);  // Координатная ось
	
	for (int i =0; i<=i_Width_a;  i++) {
		dc.MoveTo(X_+ScaleX1*i, CenterY -4);
		dc.LineTo(X_+ScaleX1*i ,CenterY + 4);
		dc.TextOut((X_+ScaleX1*i) ,(CenterY+8),itoa(i,ch,10)); //Координатная ось (буковки )
	}




	/////////////вычисляем кривую///////////////////////////////////////////
	//double spScale;
	E = m_Energy;
	div_t div_result;
	div_result = div( m_z, 2 );
	if(div_result.rem == 0)
	{
///////////////////////Четные уровни/////////////////////////////////////
	
	if(E < 1.9 * i_PotentialEnergy )
	{
	

	
		if( E <= i_PotentialEnergy )
		{
		evenness2();
		
		
	// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2(E) / calc2(E - 0.01);

		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2 ;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = PaintHeight *E/i_PotentialEnergy/Control/2;   // Вычисление масштаба по оси у



    if(spScale > rect.Height() / 1.662 )//Чтобы не рисовалась одна
	//лишняя красная линия	
	{
		while (x<i_Width_l/2 ) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = cosh(beta * x);
				
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2]) + spScale),RGB(222,0,0));
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;	
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}
	}
					
			CPen MyPen(PS_SOLID,1,RGB(222,0,0));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		

		}

			else
			{
				evenness2UP();
				
				double k = sqrt(2 * ( - i_PotentialEnergy + E));
				x = 0;
				double spScale;
				spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2;
		
				ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
				ScaleY = ((PaintHeight *(i_PotentialEnergy*2 - E))/i_PotentialEnergy/Control/2);
				//ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у

				while (x<i_Width_l/ 2) 
				{
					x = x + H;
					Y[1] = Y[2];
					Y[2] = cos(k * x);
					if( E < 2* i_PotentialEnergy )
					{
						dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
						dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
					}
				}
				while (x<i_Width_a/2) 
				{
					x = x+H;
					if(E < 2* i_PotentialEnergy )
					{
						dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) + spScale),RGB(222,0,0));
						dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(222,0,0));
					}
					Y[0] = Y[1];
					Y[1] = Y[2];
					Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
				}
			
				
				CPen MyPen(PS_SOLID,1,RGB(222,0,0));	// настраиваем перо	dc.SelectObject(MyPen);		
				dc.SelectObject(MyPen);     
				dc.MoveTo(X_, spScale  );
				dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
			

	}

	
	}
	
}
		if(div_result.rem != 0)
		{
///////////////////////Нечетные Уровни////////////////////////////////////
if(E < 1.9 * i_PotentialEnergy )
	{
	

	
		if( E <= i_PotentialEnergy )
		{
		evenness1();
		
		
	// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2(E) / calc2(E - 0.01);

		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2 ;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = PaintHeight *E/i_PotentialEnergy/Control/2;   // Вычисление масштаба по оси у



    if(spScale > rect.Height() / 1.662 )//Чтобы не рисовалась одна
	//лишняя красная линия	
	{
		while (x<i_Width_l/2 ) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = sinh(beta * x);
				
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2]) + spScale),RGB(0,0,222));
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;	
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2])  + spScale),RGB(0,0,222));
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}
	}
					
			CPen MyPen(PS_SOLID,1,RGB(0,0,222));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		

		}

			else
			{
				evenness1UP();
				
				double k = sqrt(2 * ( - i_PotentialEnergy + E));
				x = 0;
				double spScale;
				spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2;
		
				ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
				ScaleY = ((PaintHeight *(i_PotentialEnergy*2 - E))/i_PotentialEnergy/Control/2);
				//ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у

				while (x<i_Width_l/ 2) 
				{
					x = x + H;
					Y[1] = Y[2];
					Y[2] = sin(k * x);
					if( E < 2* i_PotentialEnergy )
					{
						dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2])  + spScale),RGB(0,0,222));
						dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2])  + spScale),RGB(0,0,222));
					}
				}
				while (x<i_Width_a/2) 
				{
					x = x+H;
					if(E < 2* i_PotentialEnergy )
					{
						dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) + spScale),RGB(0,0,222));
						dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2])  + spScale),RGB(0,0,222));
					}
					Y[0] = Y[1];
					Y[1] = Y[2];
					Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
				}
			
				
				CPen MyPen(PS_SOLID,1,RGB(0,0,222));	// настраиваем перо	dc.SelectObject(MyPen);		
				dc.SelectObject(MyPen);     
				dc.MoveTo(X_, spScale  );
				dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
			

	}

	
	}
	
}
// строим потенциальную ступеньку///////////////////////////////
		//CPen pen(PS_SOLID, 20, RGB(255, 255, 255));
         //CPen *oldPen = pDC->SelectObject(&pen);
	CPen MyPen(PS_SOLID,4,RGB(0,0,0));	// настраиваем перо	dc.SelectObject(MyPen);		
     dc.SelectObject(MyPen);     
	float b;
	
	b = (i_Width_a - i_Width_l)/2;
	dc.MoveTo(X_, 110);
	dc.LineTo(X_, rect.Height()  - 1.5 * Y_);
	dc.LineTo(X_ + ScaleX1*b,rect.Height()  - 1.5 * Y_ );
	
	dc.LineTo(X_ + ScaleX1*b, (rect.Height() - 1.5 * Y_) / 2 +60);
	dc.LineTo(X_ + ScaleX1*(b + i_Width_l ),(rect.Height() - 1.5 * Y_) / 2 +60 );
	dc.LineTo(X_ + ScaleX1*(b + i_Width_l ),rect.Height() - 1.5*Y_);
	dc.LineTo(X_ + ScaleX1*i_Width_a,rect.Height() - 1.5*Y_ );
	dc.LineTo(rect.Width() - X_, 110);

	CDialog::OnPaint();
	
}

void CManPage::evenness2()
{
	
	double Y0, Y1, Y2;
	
	// Теперь можно найти максимальное значение волновой функции 
	// это значение заносится в переменную Control
	
	A = 2 * E;
    beta = sqrt(2 * ( i_PotentialEnergy - E));
	H = (i_Width_a/i_ColStep);
	  	
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	Control = 0;

	while (x< i_Width_l / 2) 
	{
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y1 = Y2;
		Y2 = cosh(beta*x);
		x= x+H;
	}

	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
}

void CManPage::evenness2UP()
{

	if( E < 2* i_PotentialEnergy )
	{
	double Y0, Y1, Y2, k;
	
	A = 2 * E;
    k = sqrt(2 * ( - i_PotentialEnergy + E));
	H = (i_Width_a/i_ColStep);
	  	
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	Control = 0;

	while (x< i_Width_l / 2) 
	{
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y1 = Y2;
		Y2 = cos(k*x);
		x= x+H;
	}

	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;	
	}
}


void CManPage::evenness1()
{
	
	if( E <= i_PotentialEnergy )
	{
	double Y0, Y1, Y2;
	
	// Теперь можно найти максимальное значение функции Шредингера
	// это значение заносится в переменную Control
	
	A = 2 * E;
    beta = sqrt(2 * ( i_PotentialEnergy - E));
	H = (i_Width_a/i_ColStep);
	  	
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	Control = 0;

	while (x< i_Width_l / 2) 
	{
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y1 = Y2;
		Y2 = sinh(beta*x);
		x= x+H;
	}

	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;

}
}

void CManPage::evenness1UP()
{
	
	if( E < 2 * i_PotentialEnergy )
	{
	double Y0, Y1, Y2,k;
	
	// Теперь можно найти максимальное значение волновой функции 
	// это значение заносится в переменную Control

	A = 2 * E;
    k = sqrt(2 * ( - i_PotentialEnergy + E));
	H = (i_Width_a/i_ColStep);
	  	
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	Control = 0;

	while (x< i_Width_l / 2) 
	{
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y1 = Y2;
		Y2 = sin(k*x);
		x= x+H;
	}

	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		if (Control < Y2) 
			Control = Y2;
		if (Control < -Y2)
			Control = -Y2;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;

}
}

BOOL CManPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();	
	char ch[5];	
	i_ColStep = m_H;
	i_PotentialEnergy = m_U;
	i_Width_a = m_a;			
	i_Width_l = m_l;	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

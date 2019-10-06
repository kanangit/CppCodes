// AutoPage.cpp : implementation file
//

#include "stdafx.h"
#include "shredinger2.h"
#include "AutoPage.h"
#include "Math.h"

#define X_                20
#define Y_				  20

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoPage property page

IMPLEMENT_DYNCREATE(CAutoPage, CPropertyPage)

CAutoPage::CAutoPage() : CPropertyPage(CAutoPage::IDD)
{
	//{{AFX_DATA_INIT(CAutoPage)
	m_a = 6.0;
	m_l = 1.0;
	m_n = 8;
	m_U = 3.0;
	m_z = 2;
	m_Energy = _T("");
	m_H = 1500;
	//}}AFX_DATA_INIT

	i_Width_l = 1;				// ширина потенциальной ямы
	i_Width_a = 6;				// ширина поленциальной ступеньки
				
					
	i_PotentialEnergy =	 3;		// потенциальная энергия U
	          
    			// номер состояния чистицы
	i_ColStep = 1500;			// число шагов
	
	
	Y[0] = 0;

							
			
    i_NumCondition = 8;			
	fa = 0;
}

double CAutoPage::calc1(double E1)
{	
	// Функция предназначена для того,	// чтобы найти значение ф-ции Шрединргера (Y[2])
	// на правом краю ямы. Для этого ей придется вычислить 	// значение этой функции во всех предыдущих точках.
	// Функция возвращает модуль ф-ции шредингера ,	// помноженный на достаточно болшое число
	// задаем необходимые параметры
	double Y0, Y1 , Y2;
	A = 2 * E1;
    beta = sqrt(2 * ( i_PotentialEnergy - E1));
	H = (i_Width_a/i_ColStep);
	// задаем началные значения( )
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	
// Вычисления начинаются с середины ямы. ( x = 0) 	// принято за координату начала ямы.
	// на этом этапе Y[0] пока не нужно
	while (x< i_Width_l / 2) 
	{
		Y1 = Y2;
		Y2 = sinh(beta*x);
		x= x+H;
	}
	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	return Y2;
}






double CAutoPage::calc1UP(double E1)
{	
	// Функция предназначена для того,	// чтобы найти значение ф-ции Шрединргера (Y[2])
	// на правом краю ямы. Для этого ей придется вычислить 	// значение этой функции во всех предыдущих точках.
	// Функция возвращает модуль ф-ции шредингера ,	// помноженный на достаточно болшое число
	// задаем необходимые параметры
	double Y0, Y1 , Y2 , k ;
	A = 2 * E1;
    k = sqrt(2 * ( - i_PotentialEnergy + E1));
	H = (i_Width_a/i_ColStep);
	// задаем началные значения( )
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	
// Вычисления начинаются с середины ямы. ( x = 0) 	// принято за координату начала ямы.
	// на этом этапе Y[0] пока не нужно
	while (x< i_Width_l / 2) 
	{
		Y1 = Y2;
		Y2 = sin(k*x);
		x= x+H;
	}
	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	return Y2;
}






double CAutoPage::calc2(double E2)
{	
	// Функция предназначена для того,	// чтобы найти значение ф-ции Шрединргера (Y[2])
	// на правом краю ямы. Для этого ей придется вычислить 	// значение этой функции во всех предыдущих точках.
	// Функция возвращает модуль ф-ции шредингера ,	// помноженный на достаточно болшое число
	// задаем необходимые параметры
	double Y0, Y1 , Y2;
	A = 2 * E2;
    beta = sqrt(2 * ( i_PotentialEnergy - E2));
	H = (i_Width_a/i_ColStep);
	// задаем началные значения( )
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	
// Вычисления начинаются с середины ямы. ( x = 0) 	// принято за координату начала ямы.
	// на этом этапе Y[0] пока не нужно
	while (x< i_Width_l / 2) 
	{
		Y1 = Y2;
		Y2 = cosh(beta*x);
		x= x+H;
	}
	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	return Y2;
}


double CAutoPage::calc2UP(double E2)
{	
	// Функция предназначена для того,	// чтобы найти значение ф-ции Шрединргера (Y[2])
	// на правом краю ямы. Для этого ей придется вычислить 	// значение этой функции во всех предыдущих точках.
	// Функция возвращает модуль ф-ции шредингера ,	// помноженный на достаточно болшое число
	// задаем необходимые параметры
	double Y0, Y1 , Y2, k ;
	A = 2 * E2;
    k = sqrt(2 * ( - i_PotentialEnergy + E2));
	H = (i_Width_a/i_ColStep);
	// задаем началные значения( )
	x = H;
	Y0 = 0;
	Y1 = 1;
	Y2 = 2;
	
// Вычисления начинаются с середины ямы. ( x = 0) 	// принято за координату начала ямы.
	// на этом этапе Y[0] пока не нужно
	while (x< i_Width_l / 2) 
	{
		Y1 = Y2;
		Y2 = cos(k*x);
		x= x+H;
	}
	while (x<i_Width_a /2 ) 
	{
		x= x+H;
		Y0 = Y1;
		Y1 = Y2;
		Y2 = Y1*(2 - H*H*A)-Y0; 
	}
	return Y2;
}






void CAutoPage::evenness1()
{
//	CPaintDC dc(this); // device context for painting
//	CRect rect;// это я пытался заставить эту функцию рисовать
//  GetClientRect(&rect);
	if( E <= i_PotentialEnergy )
	{
	double Y0, Y1, Y2, E3;
	while(calc1(E) /calc1(E - 0.01) > 0) // это критерий , по которому отбирается нужное Е
	{	
		E = E + 0.01;
	}
	// Е найдено. Теперь можно найти максимальное значение функции Шредингера
	// это значение заносится в переменную Control
	E3 =  calc1(E) /calc1(E - 0.01);
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


void CAutoPage::evenness1UP()
{
//	CPaintDC dc(this); // device context for painting
//	CRect rect;// это я пытался заставить эту функцию рисовать
//  GetClientRect(&rect);
	if( E < 2 * i_PotentialEnergy )
	{
	double Y0, Y1, Y2, E3 , k;
	while(calc1UP(E) /calc1UP(E - 0.01) > 0) // это критерий , по которому отбирается нужное Е
	{	
		E = E + 0.01;
	}
	// Е найдено. Теперь можно найти максимальное значение функции Шредингера
	// это значение заносится в переменную Control
	E3 =  calc1(E) /calc1(E - 0.01);
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




void CAutoPage::evenness2()
{
//	CPaintDC dc(this); // device context for painting
//	CRect rect;// это я пытался заставить эту функцию рисовать
//  GetClientRect(&rect);
	
	double Y0, Y1, Y2, E3;
	while(calc2(E) /calc2(E - 0.01) > 0) // это критерий , по которому отбирается нужное Е
	{	
		E = E + 0.01;
	}

	
	
	// Е найдено. Теперь можно найти максимальное значение волновой функции 
	// это значение заносится в переменную Control
	E3 =  calc2(E) /calc2(E - 0.01);
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



void CAutoPage::evenness2UP()
{
//	CPaintDC dc(this); // device context for painting
//	CRect rect;// это я пытался заставить эту функцию рисовать
//  GetClientRect(&rect);
	if( E < 2* i_PotentialEnergy )
	{
	double Y0, Y1, Y2, E3 , k;
	while(calc2UP(E) /calc2UP(E - 0.01) > 0) // это критерий , по которому отбирается нужное Е
	{	
		E = E + 0.01;
	}
	// Е найдено. Теперь можно найти максимальное значение функции Шредингера
	// это значение заносится в переменную Control
	E3 =  calc2(E) /calc2(E - 0.01);
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


CAutoPage::~CAutoPage()
{
}

void CAutoPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoPage)
	DDX_Text(pDX, IDC_EDIT_A, m_a);
	DDX_Text(pDX, IDC_EDIT_L, m_l);
	DDX_Text(pDX, IDC_EDIT_N, m_n);
	DDV_MinMaxInt(pDX, m_n, 1, 20);
	DDX_Text(pDX, IDC_EDIT_U, m_U);
	DDX_Text(pDX, IDC_EDIT_Z, m_z);
	DDV_MinMaxInt(pDX, m_z, 0, 19);
	DDX_Text(pDX, IDC_EDIT_Energy, m_Energy);
	//}}AFX_DATA_MAP

		if(m_z < m_n)
		{
			int z = m_z;
			sprintf(String.GetBuffer(60),"%f",EState[z]);
		}
		else
		{
			String = _T("Выходит за пределы отображения");
		}

		SetDlgItemText(IDC_EDIT_Energy,String);
}

	


BEGIN_MESSAGE_MAP(CAutoPage, CPropertyPage)
	//{{AFX_MSG_MAP(CAutoPage)
	ON_BN_CLICKED(IDC_CHENGE, OnChenge)
	ON_BN_CLICKED(IDC_BUTTONshowE, OnBUTTONshowE)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoPage message handlers


BOOL CAutoPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	//SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon

	// установка начальных параметров


	// установка этих значений в соответствующие  Edit (ячейчи) в диалоге
	char ch[5];
	
	m_a = i_Width_a;			
	m_H = i_ColStep;			m_l = i_Width_l;
	m_n = i_NumCondition;
	m_U = i_PotentialEnergy;  

	

return TRUE;  // return TRUE  unl
}

void CAutoPage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect(10,10,11,11);
	GetClientRect(&rect);
	char ch[5];
	dc.Rectangle(X_, 110, rect.Width()-X_, rect.Height()-Y_);
	int rectHeight = rect.Height();
	
	double ScaleX1;
	
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


///////////////////////Четные уровни/////////////////////////////////////
	
	E = 0.02;
	if(E < 2 * i_PotentialEnergy )
	{
	for ( i =0; i < i_NumCondition/2  ; i++)
	{

	
		if( E <= i_PotentialEnergy )
		{
		evenness2();
		EState[i*2] = E;
		
	// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2(E) / calc2(E - 0.01);

		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2 ;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у



    if(spScale > rect.Height() / 1.662 )//Чтобы не рисовалась одна
	//лишняя красная линия	
	{


		while (x<i_Width_l/2 ) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = cosh(beta * x);
				
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(222,0,0));
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;	
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) /i_NumCondition  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition + spScale),RGB(222,0,0));
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}




	}
		
		if(calc2(E) / calc2(E - 0.01) < 0 && spScale > (110 + rect.Height() - Y_) / 2 +1 )
		  
		{	
			CPen MyPen(PS_SOLID,1,RGB(222,0,0));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		}

		}

			else
			{
				evenness2UP();
				EState[i*2] = E;
				double k = sqrt(2 * ( - i_PotentialEnergy + E));
					// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2UP(E) / calc2UP(E - 0.01);


	
		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у

		while (x<i_Width_l/ 2) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = cos(k * x);
				if( E < 2* i_PotentialEnergy )
				{
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(222,0,0));
				}
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;
				if(E < 2* i_PotentialEnergy )
				{
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) /i_NumCondition  + spScale),RGB(222,0,0));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition + spScale),RGB(222,0,0));
				}
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}
		if(calc2UP(E) / calc2UP(E - 0.01) < 0 && E < 2* i_PotentialEnergy )
		{	
			CPen MyPen(PS_SOLID,1,RGB(222,0,0));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		}

	}

	E = E + 0.5;
	}
	}

///////////////////////Нечетные Уровни////////////////////////////////////



E = 0.02;
if( E < 2 * i_PotentialEnergy)
{

	for ( i =0; i < i_NumCondition/2 ; i++)
	{

	
		if( E <= i_PotentialEnergy )
		{
		evenness1();
		EState[i*2 + 1] = E;
		
	// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2(E) / calc2(E - 0.01);


	
		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2 ;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у
		

		while (x<i_Width_l/ 2) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = sinh(beta * x);
				if(E < i_PotentialEnergy )
				{
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(0,0,222));
				}
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;
				if( E < i_PotentialEnergy )
				{
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) /i_NumCondition  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2]) / i_NumCondition + spScale),RGB(0,0,222));
				}
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}
		if(calc1(E) / calc1(E - 0.01) < 0 && spScale > (110 + rect.Height() - Y_) / 2 +1)
		{
			CPen MyPen(PS_SOLID,1,RGB(0,0,222));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		}

		}

			else
			{
				evenness1UP();
				EState[i*2 + 1] = E;
				double k = sqrt(2 * ( - i_PotentialEnergy + E));
					// строим кривую
	// постороение нужно производить только в фукции OnPaint на основании значений 
	// вычисленных где угодно в программе
		//double E3 = calc2UP(E) / calc2UP(E - 0.01);


	
		x = 0;
		double spScale;
		spScale =rect.Height() - 1.5 * Y_ - (rect.Height() - 1.5 * Y_ - 120) * E / i_PotentialEnergy/2;
		
		ScaleX = (rect.Width()-X_-X_)/(i_Width_a);
		ScaleY = ((rect.Height()/2)/Control);   // Вычисление масштаба по оси у

		while (x<i_Width_l/ 2) 
			{
				x = x + H;
				Y[1] = Y[2];
				Y[2] = sin(k * x);
			if(E < 2* i_PotentialEnergy )	
			{
				dc.SetPixel(rect.Width()/2 + ScaleX*x, ((- ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2]) / i_NumCondition  + spScale),RGB(0,0,222));
			}
			}
		while (x<i_Width_a/2) 
			{
				x = x+H;	
				if(E < 2* i_PotentialEnergy )
				{
				dc.SetPixel(rect.Width() / 2 + ScaleX*x, ((- ScaleY*Y[2]) /i_NumCondition  + spScale),RGB(0,0,222));
				dc.SetPixel(rect.Width()/2 - ScaleX*x, (( ScaleY*Y[2]) / i_NumCondition + spScale),RGB(0,0,222));
				}
				Y[0] = Y[1];
				Y[1] = Y[2];
				Y[2] = Y[1]*(2 - H*H*A)-Y[0]; 
			}
		if(calc1UP(E) / calc1UP(E - 0.01 ) < 0  && E < i_PotentialEnergy * 2)
		{	
			CPen MyPen(PS_SOLID,1,RGB(0,0,222));	// настраиваем перо	dc.SelectObject(MyPen);		
			dc.SelectObject(MyPen);     
			dc.MoveTo(X_, spScale  );
			dc.LineTo(X_ + ScaleX*i_Width_a,spScale );
		}

		}

		E = E + 0.5;
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
	
	if(m_z < m_n)
	{
		int x = m_z;
		
		
		sprintf(String.GetBuffer(60),"%f",EState[x]);
	}
	else
	{
		String = _T("Выходит за пределы отображения");
	}
	SetDlgItemText(IDC_EDIT_Energy,String);
	
		
	CDialog::OnPaint();
	
	
	
	CDialog::OnPaint();
}

void CAutoPage::OnChenge() 
{
	UpdateData();					

	i_ColStep = m_H;					 	
	i_NumCondition = m_n;  
	i_PotentialEnergy = m_U;
	i_Width_a = m_a;			
	i_Width_l = m_l;
	
	Invalidate();	
}

HCURSOR CAutoPage::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAutoPage::OnBUTTONshowE() 
{
	
	UpdateData();
}



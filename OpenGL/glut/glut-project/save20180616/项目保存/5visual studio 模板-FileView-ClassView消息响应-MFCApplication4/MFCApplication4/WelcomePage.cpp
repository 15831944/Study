#include "stdafx.h"
#include "WelcomePage.h"


CWelcomePage::CWelcomePage()
{
	m_bmpWelcomePage.LoadBitmapW(IDB_BITMAP_WELCOMEPAGE);
}


CWelcomePage::~CWelcomePage()
{
}


void CWelcomePage::DrawWelcomePage(CDC* pDC,CRect rect)
{
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	CDC* pMDC;
	pMDC = &MemDC;




	DrawPicture(pMDC);

	DrawMyText(pMDC);



	// ��ɻ���
	//pDC->BitBlt(0 , 0 , 1024 , 628 , &MemDC , 0 , 0 , SRCCOPY);
	//BOOL StretchBlt(int x , int y , int nWidth , int nHeight , CDC* pSrcDC , int xSrc , int ySrc , int nSrcWidth , int nSrcHeight , DWORD dwRop);
	//��ȡ��ǰ�ͻ����ڵĴ�С����
	
	//pDC->StretchBlt(0 , 0 , 1024 , 700 , &MemDC , 0 , 0 , 1024 , 628 , SRCCOPY);
	pDC->StretchBlt(0 , 0 , rect.Width() , rect.Height() , &MemDC , 0 , 0 , 1024 , 628 , SRCCOPY);
}


void CWelcomePage::DrawPicture(CDC* pDC)
{
	pDC->SelectObject(m_bmpWelcomePage);
	
}



void CWelcomePage::DrawMyText(CDC* pDC)
{
	int nOldDC = pDC->SaveDC();
	//���廭��
	CPen PenBlue(PS_SOLID , 1 , RGB(255 , 0 , 0));
	CPen *poldpen;
	poldpen = pDC->SelectObject(&PenBlue);

	pDC->SetROP2(R2_NOTXORPEN);

	//���ĳһ�����ɫ��RGB
	COLORREF clr;
	int R , G , B;

	clr = ::GetPixel(pDC->m_hDC , 24 , 42);
	R = GetRValue(clr);
	G = GetGValue(clr);
	B = GetBValue(clr);
	//pDC->FillSolidRect(&crossrange0 , RGB(R , G , B));//������ɫ���

	//��������
	CFont font;
	CFont *poldfont;
	poldfont = pDC->SelectObject(&font);
	font.CreateFont(
		30 ,                                                  //   nHeight  
		25 ,                                                   //   nWidth  
		0 ,                                                   //   nEscapement
		0 ,                                                   //   nOrientation  
		20 ,                                   //   nWeight  
		TRUE ,                                           //   bItalic  
		FALSE ,                                           //   bUnderline  
		0 ,                                                   //   cStrikeOut  
		ANSI_CHARSET ,                             //   nCharSet  
		OUT_DEFAULT_PRECIS ,                 //   nOutPrecision  
		CLIP_DEFAULT_PRECIS ,               //   nClipPrecision  
		DEFAULT_QUALITY ,                       //   nQuality  
		DEFAULT_PITCH | FF_SWISS ,     //   nPitchAndFamily     
		_T("����"));

	pDC->SelectObject(&font);
	
	//����������ɫ�����ֱ���Ϊ͸�� 
	SetTextColor(*pDC , RGB(255 , 170 , 0));
	SetBkMode(*pDC , TRANSPARENT);

	pDC->TextOutW(300,100, _T("��ά���й���ϵͳ"));

	//�ͷ�����
	pDC->SelectObject(poldfont);


	
	CFont font1;
	CFont *poldfont1;
	poldfont1 = pDC->SelectObject(&font1);
	font1.CreateFont(
		16 ,                                                  //   nHeight  
		8 ,                                                   //   nWidth  
		0 ,                                                   //   nEscapement
		0 ,                                                   //   nOrientation  
		20 ,                                   //   nWeight  
		FALSE ,                                           //   bItalic  
		FALSE ,                                           //   bUnderline  
		0 ,                                                   //   cStrikeOut  
		ANSI_CHARSET ,                             //   nCharSet  
		OUT_DEFAULT_PRECIS ,                 //   nOutPrecision  
		CLIP_DEFAULT_PRECIS ,               //   nClipPrecision  
		DEFAULT_QUALITY ,                       //   nQuality  
		DEFAULT_PITCH | FF_SWISS ,     //   nPitchAndFamily     
		_T("����"));

	pDC->SelectObject(&font1);

	

	//�������
	
	pDC->TextOutW(750 , 480 , _T("�����ˣ�������"));
	
	pDC->TextOutW(750 , 500 , _T("ѧ�ţ�1403070217"));
	
	pDC->TextOutW(780 , 520 , _T("2017.5.4"));

	//�ͷ�����
	pDC->SelectObject(poldfont1);
}
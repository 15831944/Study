
// GODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GO.h"
#include "GODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGODlg �Ի���



CGODlg::CGODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()

	ON_BN_CLICKED(IDOK, &CGODlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CGODlg::OnBnClickedCancel)
	ON_BN_CLICKED(ID_BUTTON_GAMESTART, &CGODlg::OnBnClickedGamestart)
	ON_BN_CLICKED(ID_BUTTON_RESIGNS, &CGODlg::OnBnClickedButtonResigns)
	ON_BN_CLICKED(ID_BUTTON_PAUSE, &CGODlg::OnBnClickedButtonPause)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGODlg ��Ϣ�������

BOOL CGODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//���ô��ڳ�ʼ����С
	SetWindowPos(0, 0, 0, 880, 540, SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGODlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CGODlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
BOOL CGODlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CBitmap bmpBoard, bmpChessWhite, bmpChessBlack, bmpChessWhite1, bmpChessBlack1;
	CDC memdc;

	//����ľ��
	memdc.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmapBoard = memdc.SelectObject(&bmpBoard);
	bmpBoard.LoadBitmap(IDB_BITMAP_GOBOARD0);
	memdc.SelectObject(&bmpBoard);

	pDC->StretchBlt(0, 0, 500, 500, &memdc, 0, 0, 1000, 1000, SRCCOPY);

	//������
	DrawGOBoard(pDC);

	//���̱�ע
	DrawGOInformation(pDC);

	//����
	CBitmap* pOldBitmapChessBlack = memdc.SelectObject(&bmpChessBlack);
	bmpChessBlack.LoadBitmap(IDB_BITMAP_GOCHESSBLACK);
	memdc.SelectObject(&bmpChessBlack);

	for (int i = 0;i<19;i++)
		for (int j = 0;j < 19;j++)
		{
			if (m_gop.GOMap[i][j] == 1) pDC->StretchBlt(40 + i * 22, 40 + j * 22, 20, 20, &memdc, 0, 0, 150, 150, SRCCOPY);

		}

	//����
	CBitmap* pOldBitmapChessWhite = memdc.SelectObject(&bmpChessWhite);
	bmpChessWhite.LoadBitmap(IDB_BITMAP_GOCHESSWHITE);
	memdc.SelectObject(&bmpChessWhite);

	for (int i = 0;i<19;i++)
		for (int j = 0;j < 19;j++)
		{
			if (m_gop.GOMap[i][j] == 2) pDC->StretchBlt(40 + i * 22, 40 + j * 22, 20, 20, &memdc, 0, 0, 150, 150, SRCCOPY);

		}

	

	//��ǰ�ֺ����Ǳ�ע

	//У����ĵ�:Rectificatory ������
	CPoint RectificatoryPoint;

	RectificatoryPoint.x = 50 + m_gop.coordinateX2 * 22;
	RectificatoryPoint.y = 50 + m_gop.coordinateY2 * 22;

	//RectificatoryPoint.x = 100;
	//RectificatoryPoint.y = 100;


	//��ɫ��ˢ
	CBrush br(RGB(255, 0, 0));
	//�����
	CRgn rgn;
	CPoint arrpt[3];
	arrpt[0] = arrpt[1] = arrpt[2] = RectificatoryPoint;
	arrpt[1].y = arrpt[0].y + 10;
	arrpt[2].x = arrpt[0].x + 10;
	if (m_gop.step>0)
	{
		if (rgn.CreatePolygonRgn(arrpt, 3, ALTERNATE) && arrpt[0].x > 0 && arrpt[0].y > 0)
		{
			pDC->FillRgn(&rgn, &br);
			pDC->MoveTo(arrpt[0]);
			pDC->LineTo(arrpt[1]);
			pDC->LineTo(arrpt[2]);
			pDC->LineTo(arrpt[0]);
		}
	}
	br.DeleteObject();
	rgn.DeleteObject();





	//����Ϣ���ڷ�
	CBitmap* pOldBitmapChessBlack1 = memdc.SelectObject(&bmpChessBlack1);
	bmpChessBlack1.LoadBitmap(IDB_BITMAP_GOCHESSBLACK1);
	memdc.SelectObject(&bmpChessBlack1);

	pDC->StretchBlt(560, 20, 70, 70, &memdc, 0, 0, 150, 150, SRCCOPY);


	//����Ϣ���׷�
	CBitmap* pOldBitmapChessWhite1 = memdc.SelectObject(&bmpChessWhite1);
	bmpChessWhite1.LoadBitmap(IDB_BITMAP_GOCHESSWHITE1);
	memdc.SelectObject(&bmpChessWhite1);

	pDC->StretchBlt(750, 20, 70, 70, &memdc, 0, 0, 150, 150, SRCCOPY);


	memdc.SelectObject(pOldBitmapChessBlack);
	memdc.SelectObject(pOldBitmapChessWhite);
	memdc.SelectObject(pOldBitmapChessBlack1);
	memdc.SelectObject(pOldBitmapChessWhite1);
	bmpChessWhite.DeleteObject();
	bmpChessBlack.DeleteObject();
	bmpChessWhite1.DeleteObject();
	bmpChessBlack1.DeleteObject();

	memdc.SelectObject(pOldBitmapBoard);
	bmpBoard.DeleteObject();
	return true;

	//return CDialogEx::OnEraseBkgnd(pDC);
}

void CGODlg::DrawGOBoard(CDC* pDC)
{

	//������

	//���廭��
	CRect rect;
	GetClientRect(&rect);
	//���ɻ���
	CPen PenBlackLine1(PS_SOLID, 2, RGB(0, 0, 0));
	CPen *poldpenline1;
	poldpenline1 = pDC->SelectObject(&PenBlackLine1);

	pDC->MoveTo(50, 50);
	pDC->LineTo(446, 50);
	pDC->LineTo(446, 446);
	pDC->LineTo(50, 446);
	pDC->LineTo(50, 50);



	//�ͷŻ���
	pDC->SelectObject(poldpenline1);

	// ���ɻ���
	CPen PenBlackLine2(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *poldpenline2;
	poldpenline2 = pDC->SelectObject(&PenBlackLine2);

	for (int i = 0;i<17;i++)
	{
		pDC->MoveTo(50, i * 22 + 72);
		pDC->LineTo(50 + 18 * 22, i * 22 + 72);
		pDC->MoveTo(i * 22 + 72, 50);
		pDC->LineTo(i * 22 + 72, 50 + 18 * 22);

	}
	//�ͷŻ���
	pDC->SelectObject(poldpenline2);

	//������������Ϣ

	CBrush fillbrush;
	CBrush *oldbrush;
	fillbrush.CreateSolidBrush(RGB(0, 0, 0));
	oldbrush = pDC->SelectObject(&fillbrush);
	int r = 4;
	for (int i = 0;i <= 2;i++)
	{
		for (int j = 0;j <= 2;j++)
		{
			pDC->Ellipse(50 + 22 * 3 + i * 6 * 22 - r, 50 + 22 * 3 + j * 6 * 22 - r, 50 + 22 * 3 + i * 6 * 22 + r, 50 + 22 * 3 + j * 6 * 22 + r);
		}
	}

	//�ͷŻ�ˢ
	pDC->SelectObject(oldbrush);



	//��ע

	//���ĳһ�����ɫ��RGB
	COLORREF clr;
	int R, G, B;

	clr = ::GetPixel(pDC->m_hDC, 24, 42);
	R = GetRValue(clr);
	G = GetGValue(clr);
	B = GetBValue(clr);

	CFont font;
	CFont *poldfont;
	poldfont = pDC->SelectObject(&font);
	font.CreateFont(
		16,                                                  //   nHeight  
		8,                                                   //   nWidth  
		0,                                                   //   nEscapement
		0,                                                   //   nOrientation  
		20,                                   //   nWeight  
		FALSE,                                           //   bItalic  
		FALSE,                                           //   bUnderline  
		0,                                                   //   cStrikeOut  
		ANSI_CHARSET,                             //   nCharSet  
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision  
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision  
		DEFAULT_QUALITY,                       //   nQuality  
		DEFAULT_PITCH | FF_SWISS,     //   nPitchAndFamily     
		_T("����"));

	pDC->SelectObject(&font);
	//pDC->SetTextColor(RGB(0, 0, 0));


	//int originx = 46;
	//int originy = 32;

	int originx = 46;
	int originy = 24;

	//����
	int add = 0;

	CRect crossrange0(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange0, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("1"));

	add = 1;
	CRect crossrange1(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange1, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("2"));

	add = 2;
	CRect crossrange2(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange2, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("3"));

	add = 3;
	CRect crossrange3(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange3, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("4"));

	add = 4;
	CRect crossrange4(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange4, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("5"));

	add = 5;
	CRect crossrange5(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange5, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("6"));

	add = 6;
	CRect crossrange6(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange6, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("7"));

	add = 7;
	CRect crossrange7(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange7, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("8"));

	add = 8;
	CRect crossrange8(originx + 22 * add, originy, originx + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange8, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx + 22 * add, originy, _T("9"));


	//ԭ��2
	int origin1x = 42;

	add = 9;
	CRect crossrange9(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange9, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("10"));


	add = 10;
	CRect crossrange10(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange10, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("11"));


	add = 11;
	CRect crossrange11(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange11, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("12"));

	add = 12;
	CRect crossrange12(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange12, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("13"));

	add = 13;
	CRect crossrange13(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange13, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("14"));

	add = 14;
	CRect crossrange14(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange14, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("15"));

	add = 15;
	CRect crossrange15(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 58);
	pDC->FillSolidRect(&crossrange15, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("16"));

	add = 16;
	CRect crossrange16(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange16, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("17"));

	add = 17;
	CRect crossrange17(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange17, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("18"));

	add = 18;
	CRect crossrange18(origin1x + 22 * add, originy, origin1x + 22 * add, originy + 5);
	pDC->FillSolidRect(&crossrange18, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin1x + 22 * add, originy, _T("19"));

	//�ͷ�����
	pDC->SelectObject(poldfont);



	//����
	CFont font1;
	CFont *poldfont1;
	poldfont1 = pDC->SelectObject(&font1);
	font1.CreateFont(
		16,                                                  //   nHeight  
		8,                                                   //   nWidth  
		0,                                                   //   nEscapement
		0,                                                   //   nOrientation  
		20,                                   //   nWeight  
		FALSE,                                           //   bItalic  
		FALSE,                                           //   bUnderline  
		0,                                                   //   cStrikeOut  
		ANSI_CHARSET,                             //   nCharSet  
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision  
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision  
		DEFAULT_QUALITY,                       //   nQuality  
		DEFAULT_PITCH | FF_SWISS,     //   nPitchAndFamily     
		_T("����"));

	pDC->SelectObject(&font1);



	//originx = 24;
	originx = 16;
	originy = 42;
	add = 0;
	CRect lengthways0(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways0, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("һ"));

	add = 1;
	CRect lengthways1(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways1, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 2;
	CRect lengthways2(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways2, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 3;
	CRect lengthways3(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways3, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 4;
	CRect lengthways4(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways4, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 5;
	CRect lengthways5(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways5, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 6;
	CRect lengthways6(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways6, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 7;
	CRect lengthways7(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways7, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 8;
	CRect lengthways8(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways8, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("��"));

	add = 9;
	CRect lengthways9(originx, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways9, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(originx, originy + 22 * add, _T("ʮ"));


	//ԭ��2
	//int  origin2x = 15;
	int  origin2x = 7;

	add = 10;
	CRect lengthways10(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways10, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮһ"));


	add = 11;
	CRect lengthways11(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways11, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 12;
	CRect lengthways12(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways12, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 13;
	CRect lengthways13(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways13, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 14;
	CRect lengthways14(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways14, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 15;
	CRect lengthways15(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways15, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 16;
	CRect lengthways16(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways16, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 17;
	CRect lengthways17(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways17, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	add = 18;
	CRect lengthways18(origin2x, originy + 22 * add, 30, 58 + 22 * add);
	pDC->FillSolidRect(&lengthways18, RGB(R, G, B));//������ɫ���
	pDC->TextOutW(origin2x, originy + 22 * add, _T("ʮ��"));

	//�ͷŻ���
	//pDC->SelectObject(poldpentext);
	//�ͷ�����
	pDC->SelectObject(poldfont1);

}


void CGODlg::DrawGOInformation(CDC* pDC)
{
	

	//���ñ���
	CRect rect(500, 0, 880, 500);

	pDC->FillSolidRect(rect, RGB(128, 128, 128));//������ɫ���

												 //���廭��


												 //���ɻ���
	CPen PenBlackLine1(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *poldpenline1;
	poldpenline1 = pDC->SelectObject(&PenBlackLine1);

	pDC->MoveTo(500, 170);
	pDC->LineTo(880, 170);

	pDC->MoveTo(500, 210);
	pDC->LineTo(880, 210);

	pDC->MoveTo(500, 250);
	pDC->LineTo(880, 250);

	pDC->MoveTo(520, 290);
	pDC->LineTo(850, 290);

	pDC->MoveTo(520, 390);
	pDC->LineTo(850, 390);

	pDC->MoveTo(500, 400);
	pDC->LineTo(880, 400);
	//�ͷŻ���
	pDC->SelectObject(poldpenline1);


	CFont font;
	CFont *poldfont;
	poldfont = pDC->SelectObject(&font);
	font.CreateFont(
		16,                                                  //   nHeight  
		8,                                                   //   nWidth  
		0,                                                   //   nEscapement
		0,                                                   //   nOrientation  
		20,                                   //   nWeight  
		FALSE,                                           //   bItalic  
		FALSE,                                           //   bUnderline  
		0,                                                   //   cStrikeOut  
		ANSI_CHARSET,                             //   nCharSet  
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision  
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision  
		DEFAULT_QUALITY,                       //   nQuality  
		DEFAULT_PITCH | FF_SWISS,     //   nPitchAndFamily     
		_T("����"));

	//����ת��
	CString blacktaking,whitetaking,step,blacktime, whitetime, steptime,informationtemp,currentplayer;
	blacktaking.Format(_T("%d"), m_gop.BlackTaking);
	whitetaking.Format(_T("%d"), m_gop.WhiteTaking);
	step.Format(_T("%d"), m_gop.step);
	blacktime = m_gop.TimeConvert(m_gop.BlackTime);
	whitetime = m_gop.TimeConvert(m_gop.WhiteTime);
	steptime = m_gop.TimeConvert(m_gop.stepTime);

	informationtemp = "���ӣ�";
	blacktaking = informationtemp + blacktaking;
	whitetaking = informationtemp + whitetaking;

	informationtemp = "��ʱ��";
	blacktime = informationtemp + blacktime;
	whitetime = informationtemp + whitetime;

	informationtemp = "������ʱ��";
	steptime = informationtemp + steptime;

	informationtemp = "��ǰ������";
	step = informationtemp + step;


	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	informationtemp = "";
	//��Ϣ��ʾ
	pDC->SelectObject(&font);

	pDC->TextOutW(520, 100, _T("�ڷ������"));
	pDC->TextOutW(720, 100, _T("�׷�������"));
	pDC->TextOutW(520, 120, blacktaking);
	pDC->TextOutW(720, 120, whitetaking);
	pDC->TextOutW(520, 140, blacktime);
	pDC->TextOutW(720, 140, whitetime);

	pDC->TextOutW(520, 180, _T("��ǰ���ڷ���"));

	pDC->TextOutW(520, 220, steptime);
	pDC->TextOutW(720, 220, step);

	pDC->TextOutW(650, 260, _T("�Ծ���Ϣ"));

	pDC->TextOutW(520, 300, _T("����ʱ��:2018-1-1"));
	pDC->TextOutW(520, 320, _T("��Ҽ���1d"));
	pDC->TextOutW(520, 340, _T("���Լ���1d"));
	pDC->TextOutW(520, 360, _T("���̴�С��19x19"));

	pDC->TextOutW(720, 300, _T("��������0"));
	pDC->TextOutW(720, 320, _T("��Ŀ��7Ŀ��"));
	pDC->TextOutW(720, 340, _T("����״̬�����ڽ���"));

	//�ͷ�����
	pDC->SelectObject(poldfont);
}


void CGODlg::DropChessPieces(CPoint point)
{
	//����
	int coordinateX = -1;
	int coordinateY = -1;

	//����
	int distanceX, distanceY;

	//У����ĵ�:Rectificatory ������
	CPoint RectificatoryPoint;
	//������ľ���
	CRect RectificatoryRect;

	distanceX = (point.x - 50) % 22;
	if (distanceX <= 10)
		coordinateX = (point.x - 50) / 22;
	if (distanceX >= 12)
		coordinateX = (point.x - 50) / 22 + 1;

	distanceY = (point.y - 50) % 22;
	if (distanceY <= 10)
		coordinateY = (point.y - 50) / 22;
	if (distanceY >= 12)
		coordinateY = (point.y - 50) / 22 + 1;
	if (m_gop.flag == 1)
	{
		if (coordinateX >= 0 && coordinateX <19 && coordinateY >= 0 && coordinateY <19)
		{
			if (m_gop.GOMap[coordinateX][coordinateY] == 0)
			{
				m_gop.GOMap[coordinateX][coordinateY] = 1;
				m_gop.flag = 2;
				m_gop.stepTime = 0;
				m_gop.step++;

				//��һ������λ������
				m_gop.coordinateX1 = m_gop.coordinateX2;
				m_gop.coordinateY1 = m_gop.coordinateY2;

				//��ǰ�ֵ�λ��
				m_gop.coordinateX2 = coordinateX;
				m_gop.coordinateY2 = coordinateY;

				//ˢ����һ�������������ھ���
				RectificatoryPoint.x = 50 + m_gop.coordinateX1 * 22;
				RectificatoryPoint.y = 50 + m_gop.coordinateY1 * 22;

				RectificatoryRect.top = RectificatoryPoint.y - 10;
				RectificatoryRect.bottom = RectificatoryPoint.y + 10;
				RectificatoryRect.left = RectificatoryPoint.x - 10;
				RectificatoryRect.right = RectificatoryPoint.x + 10;

				InvalidateRect(RectificatoryRect);

				//ˢ�µ�ǰ�����������ھ���
				RectificatoryPoint.x = 50 + m_gop.coordinateX2 * 22;
				RectificatoryPoint.y = 50 + m_gop.coordinateY2 * 22;

				RectificatoryRect.top = RectificatoryPoint.y - 10;
				RectificatoryRect.bottom = RectificatoryPoint.y + 10;
				RectificatoryRect.left = RectificatoryPoint.x - 10;
				RectificatoryRect.right = RectificatoryPoint.x + 10;

				InvalidateRect(RectificatoryRect);

			}
		}

	}
	else
		if (m_gop.flag == 2)
		{
			if (coordinateX >= 0 && coordinateX < 19 && coordinateY >= 0 && coordinateY < 19)
			{
				if (m_gop.GOMap[coordinateX][coordinateY] == 0)
				{
					m_gop.GOMap[coordinateX][coordinateY] = 2;
					m_gop.flag = 1;
					m_gop.stepTime = 0;
					m_gop.step++;

					//��һ������λ������
					m_gop.coordinateX1 = m_gop.coordinateX2;
					m_gop.coordinateY1 = m_gop.coordinateY2;

					//��ǰ�ֵ�λ��
					m_gop.coordinateX2 = coordinateX;
					m_gop.coordinateY2 = coordinateY;

					//ˢ����һ�������������ھ���
					RectificatoryPoint.x = 50 + m_gop.coordinateX1 * 22;
					RectificatoryPoint.y = 50 + m_gop.coordinateY1 * 22;

					RectificatoryRect.top = RectificatoryPoint.y - 10;
					RectificatoryRect.bottom = RectificatoryPoint.y + 10;
					RectificatoryRect.left = RectificatoryPoint.x - 10;
					RectificatoryRect.right = RectificatoryPoint.x + 10;

					InvalidateRect(RectificatoryRect);

					//ˢ�µ�ǰ�����������ھ���
					RectificatoryPoint.x = 50 + m_gop.coordinateX2 * 22;
					RectificatoryPoint.y = 50 + m_gop.coordinateY2 * 22;

					RectificatoryRect.top = RectificatoryPoint.y - 10;
					RectificatoryRect.bottom = RectificatoryPoint.y + 10;
					RectificatoryRect.left = RectificatoryPoint.x - 10;
					RectificatoryRect.right = RectificatoryPoint.x + 10;

					InvalidateRect(RectificatoryRect);

				}
			}

		}

}

void CGODlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int flagchange = m_gop.flag;
	if (m_gop.flag == 1 | m_gop.flag == 2)
	{
		if (point.x >= 40 && point.x <= 478 && point.y >= 40 && point.y <= 478)
			DropChessPieces(point);

	}
	
	//ˢ�²�����ʱ�����Ϣ
	CRect rect(520, 120, 880, 260);
	InvalidateRect(rect);
	
	CDialogEx::OnLButtonDown(nFlags, point);
}



void CGODlg::OnBnClickedGamestart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_gop.GameStart();
	SetTimer(1, 1000, NULL);
	Invalidate();
}


void CGODlg::OnBnClickedButtonResigns()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_gop.flag = 3;
	KillTimer(1);
}

void CGODlg::OnBnClickedButtonPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}


void CGODlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent)
	{
		if (m_gop.flag == 1) m_gop.BlackTime++;
		if (m_gop.flag == 2) m_gop.WhiteTime++;
		m_gop.stepTime++;
	}
	
	//ˢ�²�����ʱ�����Ϣ
	CRect rect(520, 120, 880, 260);
	InvalidateRect(rect);
	//Invalidate();

	CDialogEx::OnTimer(nIDEvent);
}


// MFCApplication3View.cpp : CMFCApplication3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication3View ����/����

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: �ڴ˴���ӹ������

	m_bShowWelcomePage = 1;
	m_nTimeShowWelcomePage = 0;

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View ����

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	if (m_bShowWelcomePage)
	{
		m_wcp.DrawWelcomePage(pDC);
		
	}
	else
	{
		pDC->MoveTo(0 , 0);
		pDC->LineTo(1024 , 700);
	}
		
		
	

}


// CMFCApplication3View ��ӡ

BOOL CMFCApplication3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplication3View ���

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View ��Ϣ�������


int CMFCApplication3View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	/*   //����͸������//
	//����������ǵ��ĵ���������ͼ���OnCreate���������ӣ�
	//	SetClassLong(m_hWnd , GCL_HBRBACKGROUND , (LONG)GetStockObject(NULL_BRUSH));//�ı䱳��ˢ
	//NULL_BRUSHΪ͸��������BLACK_BRUSHΪ��ɫ�������ɽ�(LONG)GetStockObject(NULL_BRUSH����Ϊ��
	//(long)::CreateSolidBrush(RGB(255 , 255 , 0))���ı�RGB������������ּ��ɽ�������Ϊ��ͬ����ɫ��

	//����ͼ��OnDraw��������ӣ�SetTextColor(*pDC , RGB(255 , 0 , 0));//����������ɫ
	//pDC->TextOut(100 , 100 , "��ʾ����");//��ʾ����
	*/


	SetClassLong(m_hWnd , GCL_HBRBACKGROUND , (LONG)GetStockObject(NULL_BRUSH));//�ı䱳��ˢ
	

	SetTimer(1 , 50 , NULL);

	return 0;
}


void CMFCApplication3View::OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch (nChar)
	{
	//case VK_UP:m_bShowWelcomePage = 0;
	}



	Invalidate();

	CView::OnKeyDown(nChar , nRepCnt , nFlags);
}


void CMFCApplication3View::OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	

	CView::OnKeyUp(nChar , nRepCnt , nFlags);
}


void CMFCApplication3View::OnLButtonDown(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(m_bShowWelcomePage==1)
		m_bShowWelcomePage = 0;
	else
		if (m_bShowWelcomePage == 0)
			m_bShowWelcomePage = 1;
	
	Invalidate();

	CView::OnLButtonDown(nFlags , point);
}


void CMFCApplication3View::OnLButtonUp(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	

	CView::OnLButtonUp(nFlags , point);
}


void CMFCApplication3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//��ʱ����OnCreate()������SetTimer(0,50,NULL);
	switch (nIDEvent)
	{
	case 1 :
		if (m_bShowWelcomePage)
		{
			m_nTimeShowWelcomePage++;
			if (m_nTimeShowWelcomePage == 200)
			{
				m_bShowWelcomePage = 0;
				m_nTimeShowWelcomePage = 0;
				Invalidate();
			}
		}

	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}

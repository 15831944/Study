
// MFCApplication4View.cpp : CMFCApplication4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication4View::OnFilePrintPreview)

	/*�Զ���˵���Ϣ*/
	//ON_COMMAND(ID_APP_CONTROL , &COpenGL3DView::OnDrawControl)
	//ON_COMMAND(ID_APP_2D , &COpenGL3DView::OnViewSelect2D)
	//ON_COMMAND(ID_APP_3D , &COpenGL3DView::OnViewSelect3D)

	ON_WM_CONTEXTMENU()

	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_SIZE()
	ON_WM_TIMER()


	
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCApplication4View ����/����

CMFCApplication4View::CMFCApplication4View()
{
	// TODO: �ڴ˴���ӹ������
	m_pDC = NULL;
	m_nDrawSelect = 0;
	//m_DlgCtrlBoard = NULL;
	//CreateControlBoard();

	m_bWelcomePage = 1;
	timeTemp = 0;
}

CMFCApplication4View::~CMFCApplication4View()
{
	//if (m_DlgCtrlBoard != NULL)
	{
		//ɾ����ģ̬�Ի���
	//	delete m_DlgCtrlBoard;
	//	m_DlgCtrlBoard = NULL;
	}
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	//cs.cx = m_oglf.m_WindowWidth;
	//cs.cy = m_oglf.m_WindowHeight;
	//cs.x = 700;
	//cs.y = 700;

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View ����

void CMFCApplication4View::OnDraw(CDC* pDC)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���


	if (m_bWelcomePage)
	{
		//m_wcp.DrawWelcomePage(pDC);
	}
	else
	{
		//if (m_DlgCtrlBoard != NULL)m_nDrawSelect = m_DlgCtrlBoard->m_nNumber;
		m_oglf.GLDraw(m_nDrawSelect);
		//m_oglf.GLDrawTest();
		//ShowControlBoard();

	}

	/*
	CString ao,bo;
	int ud, lr;
	ud = m_oglf.a;
	lr = m_oglf.b;
	ao.Format(_T("%d"), ud);
	bo.Format(_T("%d"), lr);
	pDC->TextOutW(185, 205, ao);
	pDC->TextOutW(400, 205, bo);
	*/
}


// CMFCApplication4View ��ӡ


void CMFCApplication4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMFCApplication4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication4View ���

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View ��Ϣ�������


int CMFCApplication4View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	m_pDC = new CClientDC(this);

	GetClientRect(&m_oldRect);

	m_oglf.GLInit(m_pDC);

	SetTimer(1 , 50 , NULL);
	return 0;
}


BOOL CMFCApplication4View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}


void CMFCApplication4View::OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
		//case VK_DOWN: m_DlgCtrlBoard->OnBnClickedAdd();break;
		//case VK_UP:if (m_DlgCtrlBoard->m_nNumber > 0)m_DlgCtrlBoard->OnBnClickedMinus();;break;
	case 'A':m_oglf.PfmTranslate(0);break;
	case 'O':m_oglf.PfmTranslate(1);break;
	case 'E':m_oglf.PfmTranslate(2);break;
	case 'I':m_oglf.PfmTranslate(3);break;


	case 'J':m_oglf.PfmTranslate(4);break;

	case 'K':m_oglf.PfmTranslate(5);break;


	case 'R':m_oglf.PfmRotate(0);break;

	case 'T':m_oglf.PfmRotate(1);break;
	case 'N':m_oglf.PfmRotate(2);break;
	case 'S':m_oglf.PfmRotate(3);break;
	case 'M':m_oglf.PfmRotate(4);break;
	case 'W':m_oglf.PfmRotate(5);break;



		//case VK_UP: MessageBox(_T("keyup"));break;
		//case VK_DOWN: MessageBox(_T("keydown"));break;
		//case VK_LEFT: MessageBox(_T("keyleft"));break;
		//case VK_RIGHT: MessageBox(_T("keyright"));break;
	case VK_UP: m_oglf.m_keyup = 1;break;
	case VK_DOWN:m_oglf.m_keydown = 1;break;
	case VK_LEFT:m_oglf.m_keyleft = 1;break;
	case VK_RIGHT:m_oglf.m_keyright = 1;break;
	case VK_SHIFT:m_oglf.m_keyshift = 1;break;
	case 33:m_oglf.m_keypageup = 1;break;
	case 34:m_oglf.m_keypagedown = 1;break;

	}
	UpdateData();

	//Invalidate();
	CView::OnKeyDown(nChar , nRepCnt , nFlags);
}


void CMFCApplication4View::OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
	case VK_UP: m_oglf.m_keyup = 0;break;
	case VK_DOWN:m_oglf.m_keydown = 0;break;
	case VK_LEFT:m_oglf.m_keyleft = 0;break;
	case VK_RIGHT:m_oglf.m_keyright = 0;break;
	case VK_SHIFT:m_oglf.m_keyshift = 0;break;
	case 33:m_oglf.m_keypageup = 0;break;
	case 34:m_oglf.m_keypagedown = 0;break;

	}
	UpdateData();
	CView::OnKeyUp(nChar , nRepCnt , nFlags);
}


void CMFCApplication4View::OnLButtonDblClk(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDblClk(nFlags , point);
}


void CMFCApplication4View::OnLButtonDown(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_bWelcomePage = 0;
	m_oglf.LButtonDown(nFlags , point);

	CView::OnLButtonDown(nFlags , point);
}


void CMFCApplication4View::OnLButtonUp(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnLButtonUp(nFlags , point);
}


void CMFCApplication4View::OnMouseMove(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags , point);
}


BOOL CMFCApplication4View::OnMouseWheel(UINT nFlags , short zDelta , CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CView::OnMouseWheel(nFlags , zDelta , pt);
}


void CMFCApplication4View::OnSize(UINT nType , int cx , int cy)
{
	CView::OnSize(nType , cx , cy);

	m_oglf.GLSize(nType , cx , cy , m_oldRect);
	//m_oglf.GLSize(nType , 2000 , 2000 , m_oldRect);

	// TODO: �ڴ˴������Ϣ����������
}


void CMFCApplication4View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (nIDEvent == 1)
	{
		if (m_bWelcomePage == 1)
		{
			timeTemp++;
			//if (timeTemp == 50)m_bWelcomePage = 0;
		}
	}



	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFCApplication4View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//HGLRC hrc;
	//hrc = ::wglGetCurrentContext();
	//if (hrc)::wglDeleteContext(hrc);
	//if (m_pDC)delete m_pDC;
	m_oglf.GLDestroy(m_pDC);
}


/*
void COpenGL3DView::CreateControlBoard()
{
	if (m_DlgCtrlBoard == NULL)
	{
		m_DlgCtrlBoard = new CDialogControlBoard();
		m_DlgCtrlBoard->Create(IDD_DIALOG_CONTROL);
	}
}



void COpenGL3DView::OnViewSelect2D()
{
	m_oglf.m_nViewSelect = 2;

}


void COpenGL3DView::OnViewSelect3D()
{
	m_oglf.m_nViewSelect = 3;

}


void COpenGL3DView::OnDrawControl()
{
	//���ڱ���DoModel�Ի���ķ���ֵ
	//INT_PTR nRes;
	//����DoModel�Ի����ʵ��
	//CDialogControl m_DlgCtrl=new CDialogControl();
	/*��ʼ��*/
	//m_DlgCtrl.m_nNumber = m_nDrawSelect;

	//�����Ի���
	//nRes = m_DlgCtrl.DoModal();
	//m_DlgCtrl->Create(IDD_DIALOG_CONTROL);
	//nRes = m_DlgCtrl->ShowWindow(TRUE);
	//�ж϶Ի���ķ���ֵ�Ƿ�ΪCANCEL,������򷵻�return�������������ִ��
	//if (nRes == IDCANCEL)
	//return;

/*
	if (m_DlgCtrlBoard != NULL)m_DlgCtrlBoard->ShowWindow(SW_SHOW);
	m_DlgCtrlBoard->m_bShow = true;

	//���ؼ��еı���ֵ���浽��Ӧ�ı�����

	m_nDrawSelect = m_DlgCtrlBoard->m_nNumber;
	//UpdateData();
	//���¿ؼ��б�����ֵ
	//UpdateData(FALSE);
}
void COpenGL3DView::ShowControlBoard()
{
	if (m_DlgCtrlBoard != NULL)
	{
		m_bShowControlBoard = m_DlgCtrlBoard->m_bShow;
		if (m_bShowControlBoard == false)
		{
			m_DlgCtrlBoard->ShowWindow(SW_HIDE);
		}
	}

}
*/
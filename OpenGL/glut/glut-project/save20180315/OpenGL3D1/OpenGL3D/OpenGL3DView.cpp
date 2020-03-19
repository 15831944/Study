
// OpenGL3DView.cpp : COpenGL3DView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "OpenGL3D.h"
#endif

#include "OpenGL3DDoc.h"
#include "OpenGL3DView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGL3DView

IMPLEMENT_DYNCREATE(COpenGL3DView, CView)

BEGIN_MESSAGE_MAP(COpenGL3DView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)




	/*�Զ���˵���Ϣ*/
	ON_COMMAND(ID_APP_CONTROL, &COpenGL3DView::OnDrawControl)




	//ON_WM_CONTEXTMENU()

	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_TIMER()

	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_KEYUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// COpenGL3DView ����/����

COpenGL3DView::COpenGL3DView()
{
	// TODO: �ڴ˴���ӹ������
	m_pDC = NULL;
	m_nDrawSelect = 0;
	m_DlgCtrlBoard = NULL;
	CreateControlBoard();
}

COpenGL3DView::~COpenGL3DView()
{
	//�����ģ̬�Ի����Ѿ�������ɾ����
	if (m_DlgCtrlBoard != NULL)
	{
		//ɾ����ģ̬�Ի���
		delete m_DlgCtrlBoard;
		m_DlgCtrlBoard = NULL;
	}
}

BOOL COpenGL3DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	cs.cx = m_oglf.m_WindowWidth;
	cs.cy = m_oglf.m_WindowHeight;

	return CView::PreCreateWindow(cs);
}

// COpenGL3DView ����

void COpenGL3DView::OnDraw(CDC* pDC)
{
	COpenGL3DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (m_DlgCtrlBoard != NULL)m_nDrawSelect = m_DlgCtrlBoard->m_nNumber;
	m_oglf.GLDraw(m_nDrawSelect);
	//m_oglf.GLDrawTest();
	ShowControlBoard();
}


// COpenGL3DView ��ӡ

BOOL COpenGL3DView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void COpenGL3DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void COpenGL3DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}





// COpenGL3DView ���

#ifdef _DEBUG
void COpenGL3DView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGL3DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGL3DDoc* COpenGL3DView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGL3DDoc)));
	return (COpenGL3DDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGL3DView ��Ϣ�������


BOOL COpenGL3DView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}


int COpenGL3DView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDC = new CClientDC(this);

	GetClientRect(&m_oldRect);

	m_oglf.GLInit(m_pDC);

	SetTimer(1, 50, NULL);
	return 0;
}


void COpenGL3DView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������

	//HGLRC hrc;
	//hrc = ::wglGetCurrentContext();
	//if (hrc)::wglDeleteContext(hrc);
	//if (m_pDC)delete m_pDC;
	m_oglf.GLDestroy(m_pDC);
}



void COpenGL3DView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������

	m_oglf.GLSize(nType, cx, cy, m_oldRect);
	//m_oglf.GLSize(nType , 2000 , 2000 , m_oldRect);
}




void COpenGL3DView::CreateControlBoard()
{
	if (m_DlgCtrlBoard == NULL)
	{
		m_DlgCtrlBoard = new CDialogControlBoard();
		m_DlgCtrlBoard->Create(IDD_DIALOG_CONTROL);
	}
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









void COpenGL3DView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void COpenGL3DView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_oglf.LButtonDown(nFlags, point);
	CView::OnLButtonDown(nFlags, point);
}


void COpenGL3DView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnLButtonUp(nFlags, point);
}



void COpenGL3DView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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
	case VK_UP:AfxMessageBox(_T("����up"));break;
	case VK_LEFT:AfxMessageBox(_T("����left"));break;
	}
	UpdateData();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void COpenGL3DView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
void COpenGL3DView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDblClk(nFlags, point);
}

void COpenGL3DView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags, point);
}


BOOL COpenGL3DView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
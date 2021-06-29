
// OpenGLBaseView.cpp : COpenGLBaseView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "OpenGLBase.h"
#endif

#include "OpenGLBaseDoc.h"
#include "OpenGLBaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLBaseView

IMPLEMENT_DYNCREATE(COpenGLBaseView, CView)

BEGIN_MESSAGE_MAP(COpenGLBaseView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COpenGLBaseView::OnFilePrintPreview)



	/*�Զ���˵���Ϣ*/
	ON_COMMAND(ID_APP_CONTROL, &COpenGLBaseView::OnDrawControl)



	/*�Զ��幤������Ϣ*/
	ON_COMMAND(ID_DRAW_CLEAR, &COpenGLBaseView::OnDrawClear)
	ON_COMMAND(ID_DRAW_POINTS,&COpenGLBaseView::OnDrawPoints)
	ON_COMMAND(ID_DRAW_LINE, &COpenGLBaseView::OnDrawLine)
	ON_COMMAND(ID_DRAW_TRAINGLES, &COpenGLBaseView::OnDrawTraingles)
	





	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()

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
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// COpenGLBaseView ����/����

COpenGLBaseView::COpenGLBaseView()
{
	// TODO: �ڴ˴���ӹ������
	m_pDC = NULL;
	m_nDrawSelect = 0;
	m_DlgCtrlBoard = NULL;
	CreateControlBoard();
}

COpenGLBaseView::~COpenGLBaseView()
{
	
		//�����ģ̬�Ի����Ѿ�������ɾ����
	if (m_DlgCtrlBoard != NULL)
	{
			//ɾ����ģ̬�Ի���
			delete m_DlgCtrlBoard;
			m_DlgCtrlBoard = NULL;
	}
}

BOOL COpenGLBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	return CView::PreCreateWindow(cs);
}

// COpenGLBaseView ����

void COpenGLBaseView::OnDraw(CDC* pDC)
{
	COpenGLBaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (m_DlgCtrlBoard != NULL)m_nDrawSelect=m_DlgCtrlBoard->m_nNumber;
	m_oglo.GLDraw(m_nDrawSelect);
	//m_oglo.GLDrawTest();
	ShowControlBoard();
}


// COpenGLBaseView ��ӡ


void COpenGLBaseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COpenGLBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void COpenGLBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void COpenGLBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


void COpenGLBaseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpenGLBaseView ���

#ifdef _DEBUG
void COpenGLBaseView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLBaseDoc* COpenGLBaseView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLBaseDoc)));
	return (COpenGLBaseDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGLBaseView ��Ϣ�������


BOOL COpenGLBaseView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}

int COpenGLBaseView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	//m_oglo.GLInit();


	m_pDC=new CClientDC(this);

	GetClientRect(&m_oldRect);

	m_oglo.GLInit(m_pDC);
	
	SetTimer(1, 50, NULL);

	return 0;
}


void COpenGLBaseView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	HGLRC hrc;
	hrc = ::wglGetCurrentContext();
	if (hrc)::wglDeleteContext(hrc);
	if (m_pDC)delete m_pDC;
}


void COpenGLBaseView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	m_oglo.GLSize(nType, cx, cy, m_oldRect); 
	//m_oglo.GLSize(nType , 2000 , 2000 , m_oldRect);
}




void COpenGLBaseView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//if (nIDEvent == 1)
	{
		//m_oglo.m_fAngleY += 10.0f;
		//m_oglo.m_fAngleX += 1.0f;
		//m_oglo.m_fAngleZ += 5.0f;
	}
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}

void COpenGLBaseView::OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{
	//case VK_DOWN: m_DlgCtrlBoard->OnBnClickedAdd();break;
	//case VK_UP:if (m_DlgCtrlBoard->m_nNumber > 0)m_DlgCtrlBoard->OnBnClickedMinus();;break;
	case 'P':m_oglo.PfmTranslate(0);break;
	case 'Y':m_oglo.PfmTranslate(1);break;
	case 'F':m_oglo.PfmTranslate(2);break;
	case 'G':m_oglo.PfmTranslate(3);break;
	case 'C':m_oglo.PfmTranslate(4);break;
	case 'R':m_oglo.PfmTranslate(5);break;
		
	case 'A':m_oglo.PfmRotate(0);break;
	case 'O':m_oglo.PfmRotate(1);break;
	case 'E':m_oglo.PfmRotate(2);break;
	case 'U':m_oglo.PfmRotate(3);break;
	case 'I':m_oglo.PfmRotate(4);break;
	case 'D':m_oglo.PfmRotate(5);break;
	}
	UpdateData();

	CView::OnKeyDown(nChar , nRepCnt , nFlags);
}

void COpenGLBaseView::OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnKeyUp(nChar , nRepCnt , nFlags);
}

void COpenGLBaseView::OnLButtonDown(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_oglo.LButtonDown(nFlags , point);
	Invalidate();


	CView::OnLButtonDown(nFlags , point);
}

void COpenGLBaseView::OnLButtonUp(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags , point);
}


void COpenGLBaseView::OnLButtonDblClk(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDblClk(nFlags , point);
}

void COpenGLBaseView::OnMouseMove(UINT nFlags , CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags , point);
}


BOOL COpenGLBaseView::OnMouseWheel(UINT nFlags , short zDelta , CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CView::OnMouseWheel(nFlags , zDelta , pt);
}











void COpenGLBaseView::CreateControlBoard()
{
	if (m_DlgCtrlBoard == NULL)
	{
		m_DlgCtrlBoard = new CDialogControlBoard();
		m_DlgCtrlBoard->Create(IDD_DIALOG_CONTROL);
	}
}

void COpenGLBaseView::OnDrawControl()
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
	
	
	if(m_DlgCtrlBoard !=NULL)m_DlgCtrlBoard->ShowWindow(SW_SHOW);
	m_DlgCtrlBoard->m_bShow = true;
	
	//���ؼ��еı���ֵ���浽��Ӧ�ı�����

	m_nDrawSelect = m_DlgCtrlBoard->m_nNumber;
	//UpdateData();
	//���¿ؼ��б�����ֵ
	//UpdateData(FALSE);
}


void COpenGLBaseView::ShowControlBoard()
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


void COpenGLBaseView::OnDrawClear()
{
	m_DlgCtrlBoard->m_nNumber = 0;
	Invalidate();
}

void COpenGLBaseView::OnDrawPoints()
{
	m_DlgCtrlBoard->m_nNumber = 1;
	Invalidate();
}

void COpenGLBaseView::OnDrawLine()
{
	m_DlgCtrlBoard->m_nNumber = 2;
	Invalidate();
}

void COpenGLBaseView::OnDrawTraingles()
{
	m_DlgCtrlBoard->m_nNumber = 3;
	Invalidate();
}







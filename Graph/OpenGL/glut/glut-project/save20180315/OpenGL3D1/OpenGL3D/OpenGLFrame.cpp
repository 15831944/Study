#include "stdafx.h"
#include "OpenGLFrame.h"


COpenGLFrame::COpenGLFrame()
{
	a = b = 5;
	c = 1;

	m_WindowWidth = 500;
	m_WindowHeight = 500;

	m_fAngelX = 0.0f;
	m_fAngelY = 0.0f;
	m_fAngelZ = 0.0f;

	m_fPositionX = 0.0f;
	m_fPositionY = 0.0f;
	m_fPositionZ = 0.0f;



	m_nSelect = 0;



	


	

	

	m_iWindowWidth=m_WindowWidth;
	m_iWindowHeight=m_WindowHeight;


	m_fRevolveAngleStep=10.0f;
	m_fTranslationStep = 0.1f;

	
}


COpenGLFrame::~COpenGLFrame()
{
}



BEGIN_MESSAGE_MAP(COpenGLFrame, CWnd)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


BOOL COpenGLFrame::bSetupPixelFormat(CClientDC* m_pDC)
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER,/*˫����*/
		PFD_TYPE_RGBA,
		24,
		0,0,0,0,0,0,
		0,
		0,
		0,
		0,0,0,0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0,0,0,
	};
	int pixelformat;
	if ((pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0)
	{
		AfxMessageBox(_T("ChoosePixFormat failed!"));
		return FALSE;
	}
	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		AfxMessageBox(_T("SetPixelFormat failed!"));
		return FALSE;
	}
	return TRUE;
}


void COpenGLFrame::GLInit(CClientDC* m_pDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	int n;
	HGLRC hrc;

	ASSERT(m_pDC != NULL);
	if (!bSetupPixelFormat(m_pDC))return;

	n = ::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);
	hrc = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);

	//GetClientRect(&m_oldRect);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_gd.light0(0, 10, -20, 128);
}

void COpenGLFrame::GLSize(UINT nType, int cx, int cy, CRect m_oldRect)
{


	// TODO: �ڴ˴������Ϣ����������

	m_iWindowWidth = cx;
	m_iWindowHeight = cy;
	m_gd.m_iWindowWidth = m_iWindowWidth;
	m_gd.m_iWindowHeight = m_iWindowHeight;




	if (cy > 0)
	{
		if ((m_oldRect.right > cx) || (m_oldRect.bottom > cy))
			RedrawWindow();
		m_oldRect.right = cx;
		m_oldRect.bottom = cy;


		glViewport(0, 0, cx, cy);				// ����OpenGL�ӿڴ�С��	
		glMatrixMode(GL_PROJECTION);			// ���õ�ǰ����ΪͶӰ����
		glLoadIdentity();						// ���õ�ǰָ���ľ���Ϊ��λ����
		gluPerspective							// ����͸��ͼ
		(54.0f,									// ͸�ӽ�����Ϊ 45 ��
			(GLfloat)cx / (GLfloat)cy,			// ���ڵĿ���߱�
			0.1f,								// ��Ұ͸�����:����1.0f
			3000.0f								// ��Ұ͸�����:ʼ��0.1fԶ��1000.0f
		);
		// �������������ƣ���һ���������þ�ͷ��Ƕȣ��ڶ��������ǳ���ȣ�������Զ�����С�
		glMatrixMode(GL_MODELVIEW);				// ���õ�ǰ����Ϊģ����ͼ����
		glLoadIdentity();						// ���õ�ǰָ���ľ���Ϊ��λ����

		//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.0, 7.0);



		glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 7.0);

	}
}

void COpenGLFrame::GLDestroy(CClientDC* m_pDC)
{


	// TODO: �ڴ˴������Ϣ����������
	HGLRC hrc;
	hrc = ::wglGetCurrentContext();
	if (hrc)::wglDeleteContext(hrc);
	if (m_pDC)delete m_pDC;

}

void COpenGLFrame::GLDraw(int select)
{
	m_nSelect = select;
	DrawScene();
	glPushMatrix();

	/*����任*/
	glTranslatef(m_fPositionX , m_fPositionY , m_fPositionZ);

	glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);

	//����ͼ��
	m_gd.GLDraw(select);
	
	glPopMatrix();
	glDisable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
	glFinish();

	/*˫����*/
	SwapBuffers(wglGetCurrentDC());
}

void COpenGLFrame::DrawScene()
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -4.5f);


	glFlush();										 // ���´���
	SwapBuffers(hDC);								 // �л�������
   
	
}

void COpenGLFrame::PfmTranslate(int translation_direction)
{
	switch (translation_direction)
	{
	case 0:m_fPositionX += m_fTranslationStep;break;
	case 1:m_fPositionX -= m_fTranslationStep;break;
	case 2:m_fPositionY += m_fTranslationStep;break;
	case 3:m_fPositionY -= m_fTranslationStep;break;
	case 4:m_fPositionZ += m_fTranslationStep;break;
	case 5:m_fPositionZ -= m_fTranslationStep;break;
	default:break;
	}

	glTranslatef(m_fPositionX, m_fPositionY, m_fPositionZ);




}

void COpenGLFrame::PfmRotate(int revolve_direction)
{
	switch (revolve_direction)
	{
	case 0:m_fAngelX += m_fRevolveAngleStep;break;
	case 1:m_fAngelX -= m_fRevolveAngleStep;break;
	case 2:m_fAngelY += m_fRevolveAngleStep;break;
	case 3:m_fAngelY -= m_fRevolveAngleStep;break;
	case 4:m_fAngelZ += m_fRevolveAngleStep;break;
	case 5:m_fAngelZ -= m_fRevolveAngleStep;break;
	default:break;
	}

	glRotatef(m_fAngelX, 1.0f, 0.0f, 0.0f);
	glRotated(m_fAngelY, 0.0, 1.0, 0.0);
	glRotatef(m_fAngelZ, 0.0f, 0.0f, 1.0f);


}

void COpenGLFrame::GLDrawTest()
{
	/*��ʼ������*/
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -4.5f);


	glPushMatrix();

	/*����任*/
	//*

	//*/

	

	glPopMatrix();

	//glDisable(GL_LIGHTING);

	glFinish();

	/*˫����*/
	SwapBuffers(wglGetCurrentDC());
}


void COpenGLFrame::LButtonDown(UINT nFlags , CPoint point)
{
	if (m_nSelect != 34)return;

	
}


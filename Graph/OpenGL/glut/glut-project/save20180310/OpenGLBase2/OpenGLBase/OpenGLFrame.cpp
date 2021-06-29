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



	InitLightParameter();
	InitMatrialParameter();



	

	glReadPixels(0, 0, 64, 64, GL_RGB, GL_UNSIGNED_BYTE, image);

	m_iWindowWidth=m_WindowWidth;
	m_iWindowHeight=m_WindowHeight;


	m_fRevolveAngleStep=10.0f;
	m_fTranslationStep = 0.1f;



	hFont = CreateFont(-12, 0, 0, 0, 400, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, FF_MODERN, _T("Arial"));
	hFont0 = CreateFont(-48, 0, 0, 0, 800, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, FF_MODERN, _T("����"));
	m_Fram = 0;//
	m_Time = timeGetTime();				//
	tim = 0;                              //ˢ���ٶ�
	Font = new CGLFont();

	
}


COpenGLFrame::~COpenGLFrame()
{

}



BEGIN_MESSAGE_MAP(COpenGLFrame, CWnd)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


BOOL COpenGLFrame::bSetupPixelFormat(CClientDC* m_pDC)//��ⰲװOpenGL
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),// pfd�ṹ�Ĵ�С
		1,                                          // �汾�� 
		PFD_DRAW_TO_WINDOW |// ֧���ڴ����л�ͼ
		PFD_SUPPORT_OPENGL | // ֧�� OpenGL
		PFD_DOUBLEBUFFER,// ˫����ģʽ
		PFD_TYPE_RGBA,// RGBA ��ɫģʽ
		24, // 24 λ��ɫ���
		0,0,0,0,0,0,// ������ɫλ 
		0,// û�з�͸���Ȼ���
		0,                                // ������λλ 
		0,                                // ���ۼӻ��� 
		0, 0, 0, 0,                       // �����ۼ�λ 
		32,                               // 32 λ��Ȼ���     
		0,                                // ��ģ�建�� 
		0,                                // �޸������� 
		PFD_MAIN_PLANE,                   // ���� 
		0,                                // ���� 
		0, 0, 0                           // ���Բ�,�ɼ��Ժ������ģ 
	};

	int pixelformat;// ���ص��ʽ
	if ((pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0)
	{
		AfxMessageBox(_T("û�ҵ����ʵ���ʾģʽ!"));
		return FALSE;
	}
	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		AfxMessageBox(_T("�������ش����ʽʧ��!"));
		return FALSE;
	}//���õ�ǰ�豸�����ص��ʽ

	//m_baiscobj = new baiscobj();
	 //hRC = wglCreateContext(hDC);          //��ȡ��Ⱦ�������
	 //wglMakeCurrent(hDC, hRC);             //������Ⱦ�������
	return TRUE;
}

void COpenGLFrame::InitLightParameter()
{
	m_lightAmb[0] = 1.0f;m_lightAmb[1] = 0.2f;m_lightAmb[2] = 0.2f;m_lightAmb[3] = 1.0f;
	m_lightDif[0] = 1.0f;m_lightDif[1] = 1.0f;m_lightDif[2] = 0.3f;m_lightDif[3] = 1.0f;
	m_lightSpe[0] = 1.0f;m_lightSpe[1] = 1.0f;m_lightSpe[2] = 1.0f;m_lightSpe[3] = 1.0f;
	m_lightPos[0] = 1.0f;m_lightPos[1] = 1.0f;m_lightPos[2] = 1.0f;m_lightPos[3] = 0.0f;
}

void COpenGLFrame::InitMatrialParameter()
{
	m_materialAmb[0] = 1.0f;m_materialAmb[1] = 0.2f;m_materialAmb[2] = 0.2f;m_materialAmb[3] = 1.0f;
	m_materialDif[0] = 1.0f;m_materialDif[1] = 1.0f;m_materialDif[2] = 0.3f;m_materialDif[3] = 1.0f;
	m_materialSpe[0] = 1.0f;m_materialSpe[1] = 1.0f;m_materialSpe[2] = 1.0f;m_materialSpe[3] = 1.0f;
	m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
	m_materialShininess[0] = 10.0f;m_materialShininess[1] = 10.0f;m_materialShininess[2] = 0.0f;m_materialShininess[3] = 10.0f;
}

void COpenGLFrame::CreateLights()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT, m_lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, m_lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, m_lightSpe);
	glLightfv(GL_LIGHT0, GL_POSITION, m_lightPos);


	glEnable(GL_LIGHTING);
	/*���ɴ���8յ��*/
	glEnable(GL_LIGHT0);

}

void COpenGLFrame::CreateMaterial()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_materialAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_materialDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_materialSpe);
	glMaterialfv(GL_FRONT, GL_POSITION, m_materialPos);
	glMaterialfv(GL_FRONT, GL_SHININESS, m_materialShininess);

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

		glViewport(0, 0, cx, cy);			// ����OpenGL�ӿڴ�С��	
		glMatrixMode(GL_PROJECTION);			// ���õ�ǰ����ΪͶӰ����
		glLoadIdentity();						// ���õ�ǰָ���ľ���Ϊ��λ����
		gluPerspective							// ����͸��ͼ
		(54.0f,							// ͸�ӽ�����Ϊ 45 ��
			(GLfloat)cx / (GLfloat)cy,	// ���ڵĿ���߱�
			0.1f,								// ��Ұ͸�����:����1.0f
			3000.0f							// ��Ұ͸�����:ʼ��0.1fԶ��1000.0f
		);
		// �������������ƣ���һ���������þ�ͷ��Ƕȣ��ڶ��������ǳ���ȣ�������Զ�����С�
		glMatrixMode(GL_MODELVIEW);				// ���õ�ǰ����Ϊģ����ͼ����
		glLoadIdentity();						// ���õ�ǰָ���ľ���Ϊ��λ����




												//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.0, 7.0);

												//glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 7.0);

												//glViewport(0, 0, cx, cy);
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
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);			 // ����ˢ�±���ɫ
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// ˢ�±���
	glLoadIdentity();								 // ���õ�ǰ��ģ�͹۲����

													 //	glColor3f(1.0f, 0.0f, 0.0f);


													 //	glMatrixMode(GL_MODELVIEW);
													 //	glLoadIdentity();
													 //	glTranslatef(0.0f, 0.0f, -4.5f);


													 //	CreateLights();
													 //	CreateMaterial();


	m_baiscobj->DisplayScene();							//�����
	m_baiscobj->CreateSkyBox(3, 6, 3, 6);		//��ʾ��
	m_baiscobj->DrawSand();						//��ʾ���ɽ��
	srand(100);//�������Ĺ̶����������
	for (int i = 0;i<300;i++)						//��������			
	{
		float x = RAND_COORD((MAP_W - 1)*MAP_SCALE);	//λ��x
		float z = RAND_COORD((MAP_W - 1)*MAP_SCALE);	//λ��z
		float size = 4.0f + rand() % 4;					//��С2-4���
		float h = -size / 10;							//��ǳ
		int   cactus = rand() % 4 + 11;					//�������4��   
		m_baiscobj->ShowTree(x, z, size, h, cactus);	//��ʾ��
	}
	m_baiscobj->picter(MAP + 10, 0, -MAP);			//���ͼ��1
													//////////////////////////////////////////////////////////////////////////
	text();//��ʾ����
	SwapBuffers(hDC);								 // �л�������

	glFlush();										 // ���´���
	//SwapBuffers(hDC);								 // �л�������
   
	
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

	//m_gd.BitmapTexture();

	glPopMatrix();

	//glDisable(GL_LIGHTING);

	glFinish();

	/*˫����*/
	SwapBuffers(wglGetCurrentDC());
}

void COpenGLFrame::text()//��ʾ����
{
	DWORD Dura = (timeGetTime() - m_Time) / 1000;
	if (Dura>0) tim = m_Fram / Dura;
	m_Fram++;
	char ch[128];
	
	CString cstr = _T("ˢ��: %2d ֡/�� %s");
	int len = WideCharToMultiByte(CP_ACP, 0, cstr, -1, NULL, 0, NULL, NULL);
	char *ptxtTemp = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, cstr, -1, ptxtTemp, len, NULL, NULL);

	//delete[] ptxtTemp;
	sprintf(ch, ptxtTemp, tim, test);
	delete[] ptxtTemp;

	CString str(ch);
	//str.format("%s", ch);


	Font->settext(350, 550, str, hFont, 1, 1, 1.0f);
	Font->settext(419, 258, _T("+"), hFont, 1, 0, 0);
}


void COpenGLFrame::LButtonDown(UINT nFlags , CPoint point)
{
	if (m_nSelect != 34)return;

	
}


#include "stdafx.h"
#include "GraphDraw.h"





CGraphDraw::CGraphDraw()
{
	a = b = 5;
	c = 1;


	m_nSelect = 0;

	r = 0;

	g_text = gluNewQuadric();
	//LoadT8("aa.BMP", g_cactus[0]);//��ͼ
	//LoadT8("bb.BMP", g_cactus[1]);//��ͼ
	//LoadTGATexture()

	numtest = 0;

	m_tgawr.LoadTGA(&texture[0], _T("F:\\znpop\\xmbb.tga"));

	
		
}


CGraphDraw::~CGraphDraw()
{
}



BEGIN_MESSAGE_MAP(CGraphDraw, CWnd)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()




void CGraphDraw::GLDraw(int select)
{
	m_nSelect = select;

	switch (select)
	{
	case 0:;break;
	
	default:break;
	}
	

	
	//picter(4, -4, -10);					//��ʾ���ͼ��
	//if(numtest==1) airplane(0, 8, -50);					//��Ϸɻ�

	//TextureDraw();
	
	Textureaa();
}


void CGraphDraw::light0(float x, float y, float z, float a)//��
{
	GLfloat light_position[] = { x,y,z,a };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

void CGraphDraw::airplane(float x, float y, float z)//��Ϸɻ�
{
	r += 1;if (r>360) r = 0;
	glPushMatrix();//ѹ���ջ
	glTranslatef(x, y, z);//�ɻ��Ķ�λ
	glRotatef(-r, 0.0, 1.0, 0.0);//�ɻ�����ת
	glTranslatef(30, 0, 0);		 //�ɻ�����ת�뾶
	glRotatef(30, 0.0, 0.0, 1.0);//�ɻ�����б
								 //=============================================
	glPushMatrix();//
	glRotatef(-r * 30, 0.0, 0.0, 1.0);//�ɻ�����ת
	glColor3f(0.0, 0.0, 1.0);
	Box(1.0f, 0.1f, 0.02f);		//����������	
	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);		//��ɫ
	glEnable(GL_TEXTURE_2D);		//ʹ������
	glBindTexture(GL_TEXTURE_2D, g_cactus[1]);//
	glTranslatef(0.0f, 0.0f, -0.5f);	//����
	gluSphere(g_text, 0.4f, 8, 8);  //��ͷ԰(�뾶)
									//=============================================
	glTranslatef(0.0f, -0.0f, -2);	//λ�õ���,���ͷ�Խ�
	gluCylinder(g_text, 0.4, 0.4, 2.0, 8, 4);//����,԰��(�뾶����)
											 //=====================================================
	glRotatef(-180, 1.0, 0.0, 0.0); //�Ƕȵ���
	glTranslatef(0.0f, -0.0f, 0.0f);	//λ�õ���,����һ��		
	gluCylinder(g_text, 0.4, 0.1, 1.5, 8, 4);//��β,԰׶(�װ뾶����)
											 //======================================================
	glBindTexture(GL_TEXTURE_2D, g_cactus[0]);//
	glTranslatef(0.0f, -0.8f, 1.2f);	//λ�õ���
	Box(1.0, 0.05f, 0.3f);			//����
	glTranslatef(0.0f, 0.1f, 0.0f);	//λ�õ���
	Box(0.05f, 0.6f, 0.30f);			//����
										//======================================================
	glTranslatef(0.0f, 0.7f, -1.9f);	//λ�õ���
	Box(3, 0.05f, 0.5f);				//ǰ��
										//======================================================
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void CGraphDraw::Box(float x, float y, float z)
{
	glPushMatrix();//ѹ���ջ
	glScalef(x, y, z);
	glEnable(GL_TEXTURE_2D);		//ʹ������
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// ǰ
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// ��
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// ��
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);// ��
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// ��
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void CGraphDraw::picter(float x, float y, float z)//���ͼ��
{
	r += 1;if (r>360) r = 0;
	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��
	glPushMatrix();//ƽ̨==============================
	glTranslatef(x, y + 0.5f, z);		//ƽ̨�Ķ�λ
	glColor3f(0.0f, 1.0f, 0.2f);		//��ɫ
	//auxSolidCube(1);				//��̨(�߳�)
	glutSolidCube(1);
	glTranslatef(0.0f, 0.8f, 0.0f);	//�ܵ�λ�õ���,����0.8
	glColor3f(0.0f, 0.0f, 1.0f);		//��ɫ
	//auxSolidBox(.2f, 1.3f, .2f);		//������(���ߡ���)
	
	glPopMatrix();
	glPushMatrix();//�״�==============================
	glTranslatef(x, y + 2.5f, z);		//�״�Ķ�λ1
	glRotatef(-r, 0.0, 1.0, 0.0);	//�״���ת2
										//=======================================
	glColor3f(1.0f, 1.0f, 1.0f);		//��ɫ
	glRotatef(45, 1.0, 0.0, 0.0);	//�̵ĽǶȵ�������30��
	//auxWireCone(1.5, 0.6f);			//��԰׶��(�װ뾶����)
	glutSolidCone(1.5,0.6f,50,50);				

	//=======================================
	glRotatef(180, 1.0, 0.0, 0.0);	//�˵ĽǶȵ���,������ת
	glTranslatef(0.0f, 0.0f, -0.7f);  //�˵�λ�õ���,����һ��
	//auxWireCone(0.2f, 2.0f);			//԰׶��(�װ뾶����)
	glutSolidCone(0.2, 2.0f, 50, 50);

	glColor3f(FRAND, 0, 0);			//�����ɫ
	glTranslatef(0.0f, 0.0f, 2.0f);	//�˵�λ�õ���,����һ��
	//auxSolidSphere(0.1f);			//԰(�뾶)
	glutSolidSphere(0.1f,50,50);

	glPopMatrix();

	glPushMatrix();//���=============================
	glTranslatef(x, y+7.0f , z);		//����Ķ�λ
	glRotatef(-r, 0.0, 1.0, 0.0);	//�������ת
	glTranslatef(15, 0, 0);			//����Ķ�λ
									//=============================================
	glColor3f(1.0f, 0.0f, 0.0f);		//��ɫ
	//glRotatef(180, 0.0, 1.0, 0.0);	//�Ƕȵ���,���״�ƽ�У���ͷ��ǰ
	//auxSolidCone(.2, 0.6);			//԰׶(�װ뾶����)
	glutSolidCone(0.2, 0.6f, 50, 50);							
	//=============================================
	glColor3f(1.0f, 1.0f, 1.0f);		//��ɫ
	glRotatef(90, 1.0, 0.0, 0.0);	//�Ƕȵ���,����ͷ�Խ�
	glTranslatef(0.0f, -1.0f, 0);		//λ�õ���,����ͷ�Խ�
	//auxSolidCylinder(.2f, 1);		//԰��(�뾶����)
	//glScalef(6.0f, 6.0f, 6.0f);//x,y,z����Ŵ�6��  
	//glutWireDodecahedron();
	glutSolidCube(0.3);
	glRotatef(-270, 1.0, 0.0, 0.0);
	glColor3f(FRAND + .6f, 0.2f, 0.0f);	//���ɫ
	glTranslatef(0.0f, -0.0f, -0.2f); //λ�õ���,����һ��
	//auxSolidCone(.2, 1.5);			//԰׶(�װ뾶����)
	glutSolidCone(0.2, 1.5f, 50, 50);
	glPopMatrix();
	glPopAttrib();//�ָ�ǰһ����
	
}

bool CGraphDraw::LoadT8(char *filename, GLuint &texture)//��8λ��ͼ
{
	AUX_RGBImageRec *pImage = NULL;


	WCHAR wfilename[256];
	memset(wfilename, 0, sizeof(wfilename));
	MultiByteToWideChar(CP_ACP, 0, filename, strlen(filename) + 1, wfilename, sizeof(wfilename) / sizeof(wfilename[0]));

	pImage = auxDIBImageLoad(wfilename);			// װ��λͼ	



	if (pImage == NULL)		return false;		// ȷ��λͼ�����Ѿ�װ��
	glGenTextures(1, &texture);					// ��������
	glBindTexture(GL_TEXTURE_2D, texture);	// ��������
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, pImage->sizeX,
		pImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);
	free(pImage->data);	//�ͷ�λͼռ�ݵ��ڴ���Դ
	free(pImage);
	return true;// ����true
}

void CGraphDraw::TextureDraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);

	glBegin(GL_QUADS);
	// Front Face   
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);
	glBegin(GL_QUADS);
	// Back Face   
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);
	glBegin(GL_QUADS);
	// Top Face   
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);
	glBegin(GL_QUADS);
	// Bottom Face   
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);
	glBegin(GL_QUADS);
	// Right face   
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);
	glBegin(GL_QUADS);
	// Left Face   
	// Bottom Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	// Bottom Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Top Right Of The Texture and Quad   
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Top Left Of The Texture and Quad   
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
}

void CGraphDraw::Textureaa()
{
	m_tgawr.zTexture2D(texture, 0);

	glBegin(GL_QUADS);
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	
	glBegin(GL_QUADS);
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	
	glBegin(GL_QUADS);
	
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	 
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	
	glBegin(GL_QUADS);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	 
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	
	glBegin(GL_QUADS);
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();

	
	glBegin(GL_QUADS);
	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
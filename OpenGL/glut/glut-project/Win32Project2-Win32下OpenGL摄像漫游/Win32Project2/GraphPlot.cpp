#include"stdafx.h"
#include "GraphPlot.h"



CGraphPlot::CGraphPlot()
{
	g_eye[0] = MAP;//
	g_eye[2] = -MAP;//
	g_Angle = 0;//��λ��
	g_elev = 0;//������
	g_text = gluNewQuadric();
	LoadT8("aa.BMP", g_cactus[0]);//�ɻ���ͼ
	LoadT8("bb.BMP", g_cactus[1]);//�ɻ���ͼ
}


CGraphPlot::~CGraphPlot()
{
}

///////////////////////////////////////////////////////////////
//*
void CGraphPlot::light0()
{
	GLfloat light_position[] = { 1.0,10.0,-51.0,10.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}
BOOL CGraphPlot::DisplayScene()//�����
{
	float speed = 0.2f;							//����
	if (KEY_DOWN(VK_SHIFT))  speed = speed * 4;//��SHIFTʱ�ļ���
	if (KEY_DOWN(VK_LEFT))   g_Angle -= speed * 2;//��ת
	if (KEY_DOWN(VK_RIGHT))  g_Angle += speed * 2;//��ת
	rad_xz = float(3.13149* g_Angle / 180.0f);	//����������ת�Ƕ�
	if (KEY_DOWN(33)) g_elev += 0.2f;	//Page UP  ��
	if (KEY_DOWN(34)) g_elev -= 0.2f;	//Page Down��
	if (g_elev<-100)	g_elev = -100;	//������
	if (g_elev> 100)	g_elev = 100;	//������
	if (KEY_DOWN(VK_UP))				//ǰ��
	{
		g_eye[2] += sin(rad_xz)*speed;
		g_eye[0] += cos(rad_xz)*speed;
	}
	if (KEY_DOWN(VK_DOWN))			//����
	{
		g_eye[2] -= sin(rad_xz)*speed;
		g_eye[0] -= cos(rad_xz)*speed;
	}
	//���Ƶ���������뿪����
	/*  if(g_eye[0]<  MAP_SCALE*2)		 g_eye[0]=  MAP_SCALE*2;
	if(g_eye[0]> (MAP_W-3)*MAP_SCALE) g_eye[0]= (MAP_W-3)*MAP_SCALE;
	if(g_eye[2]<-(MAP_W-3)*MAP_SCALE) g_eye[2]=-(MAP_W-3)*MAP_SCALE;
	if(g_eye[2]> -MAP_SCALE*2)		 g_eye[2]= -MAP_SCALE*2;*/
	if (g_eye[0]<-(MAP * 2 - 20))	g_eye[0] = -(MAP * 2 - 20); //�ӵ��X��������
	if (g_eye[0]> (MAP * 2 - 20))	g_eye[0] = (MAP * 2 - 20);
	if (g_eye[2]<-(MAP * 2 - 20))	g_eye[2] = -(MAP * 2 - 20); //�ӵ��Z��������
	if (g_eye[2]> (MAP * 2 - 20))	g_eye[2] = (MAP * 2 - 20);
	g_eye[1] = 1.8;//����������Ե�λ�ø�
				   //������ķ���
	g_look[0] = float(g_eye[0] + 100 * cos(rad_xz));
	g_look[2] = float(g_eye[2] + 100 * sin(rad_xz));
	g_look[1] = g_eye[1];
	//����modelview������
	gluLookAt(g_eye[0], g_eye[1], g_eye[2], g_look[0], g_look[1] + g_elev, g_look[2], 0.0, 1.0, 0.0);
	return TRUE;
}
GLvoid CGraphPlot::DrawGround()//��ɫ���������
{
	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��
	glEnable(GL_BLEND);//ʹ������
	glPushMatrix();
	glColor3f(0.5f, 0.7f, 1.0f);//������ɫ
	glTranslatef(0, 0.0f, 0);		//ƽ̨�Ķ�λ
	int size0 = (int)(MAP * 2);
	glBegin(GL_LINES);//��һ����
	for (int x = -size0; x < size0;x += 4)
	{
		glVertex3i(x, 0, -size0); glVertex3i(x, 0, size0);
	}
	for (int z = -size0; z < size0;z += 4)
	{
		glVertex3i(-size0, 0, z); glVertex3i(size0, 0, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
	glPopAttrib();//�ָ�ǰһ����
}
//==========================================================================
void CGraphPlot::picter(float x, float y, float z)//���ͼ��
{
	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��
	glPushMatrix();//ƽ̨==============================
	glTranslatef(x, y + 0.5f, z);		//ƽ̨�Ķ�λ
	glColor3f(0.0f, 1.0f, 0.2f);		//��ɫ
	auxSolidCube(1);				//��̨(�߳�)
	glTranslatef(0.0f, 0.8f, 0.0f);	//�ܵ�λ�õ���,����0.8
	glColor3f(0.0f, 0.0f, 1.0f);		//��ɫ
	auxSolidBox(.2f, 1.3f, .2f);		//������(���ߡ���)
	glPopMatrix();
	glPushMatrix();//�״�==============================
	glTranslatef(x, y + 2.5f, z);		//�״�Ķ�λ1
	glRotatef(r - 90, 0.0, 1.0, 0.0);	//�״���ת2
										//=======================================
	glColor3f(1.0f, 1.0f, 1.0f);		//��ɫ
	glRotatef(45, 1.0, 0.0, 0.0);	//�̵ĽǶȵ�������30��
	auxWireCone(1.5, 0.6f);			//��԰׶��(�װ뾶����)
									//=======================================
	glRotatef(180, 1.0, 0.0, 0.0);	//�˵ĽǶȵ���,������ת
	glTranslatef(0.0f, 0.0f, -0.7f);  //�˵�λ�õ���,����һ��
	auxWireCone(0.2f, 2.0f);			//԰׶��(�װ뾶����)
	glColor3f(FRAND, 0, 0);			//�����ɫ
	glTranslatef(0.0f, 0.0f, 2.0f);	//�˵�λ�õ���,����һ��
	auxSolidSphere(0.1f);			//԰(�뾶)
	glPopMatrix();
	/* glPushMatrix();//���=============================
	glTranslatef(x,y+10.0f,z);//����Ķ�λ
	glRotatef(r, 0.0, 1.0, 0.0);	//�������ת
	glTranslatef(x/15,0,0);//����Ķ�λ
	//=============================================
	glColor3f(1.0f,0.0f,0.0f);		//��ɫ
	glRotatef(180, 0.0, 1.0, 0.0);	//�Ƕȵ���,���״�ƽ�У���ͷ��ǰ
	auxSolidCone(.2,0.6);			//԰׶(�װ뾶����)
	//=============================================
	glColor3f(1.0f,1.0f,1.0f);		//��ɫ
	glRotatef(90, 1.0, 0.0, 0.0);	//�Ƕȵ���,����ͷ�Խ�
	glTranslatef(0.0f,-1.0f,0);		//λ�õ���,����ͷ�Խ�
	auxSolidCylinder(.2f,1);		//԰��(�뾶����)
	glRotatef(-270, 1.0, 0.0, 0.0);
	glColor3f(FRAND+.6f,0.2f,0.0f);	//���ɫ
	glTranslatef(0.0f,-0.0f,-0.2f); //λ�õ���,����һ��
	auxSolidCone(.2,1.5);			//԰׶(�װ뾶����)
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);*/
	glPopAttrib();//�ָ�ǰһ����
	r += 0.1f;if (r>360) r = 0;

}
void CGraphPlot::airplane(float x, float y, float z)//��Ϸɻ�
{
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
	Box(1.0, 0.05f, 0.3f);				//����
	glTranslatef(0.0f, 0.1f, 0.0f);	//λ�õ���
	Box(0.05f, 0.6f, 0.30f);			//����
										//======================================================
	glTranslatef(0.0f, 0.7f, -1.9f);	//λ�õ���
	Box(3, 0.05f, 0.5f);				//ǰ��
										//======================================================
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void CGraphPlot::Box(float x, float y, float z)
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
bool CGraphPlot::LoadT8(char *filename, GLuint &texture)//��8λ��ͼ
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
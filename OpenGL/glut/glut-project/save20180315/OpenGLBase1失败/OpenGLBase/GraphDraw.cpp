#include "stdafx.h"
#include "GraphDraw.h"





CGraphDraw::CGraphDraw()
{
	a = b = 0;
	c = 0;


	m_nSelect = 0;

	r = 0;

	g_text = gluNewQuadric();
	
	//LoadTGATexture()




	//g_eye[0] = MAP;//
	//g_eye[2] = -MAP;//

	g_eye[0] = 0;//
	g_eye[2] =5;//
	g_Angle = 0;//
	g_elev = -0;//360;//


	m_keydown = m_keyup = m_keyshift = m_keypagedown = m_keypageup = 0;

	m_BoxSize = 100;
	m_BoxBottomHeightMax = 5;
	//m_BoxBottomHeight[10][10] = 10;
	//m_BoxBottomHeight[50][50] = 10;
	for(int i=0;i<m_BoxSize;i++)
		for (int j = 0;j < m_BoxSize;j++)
		{
			GLfloat temp,temprand;
			temp = temprand = 0;
			while (1)
			{
				temprand = GLfloat(rand() % m_BoxBottomHeightMax);
				temprand /= 10;
				temp = temprand - m_BoxBottomHeight[i][j];
				if (temp < 0)temp = -temp;
				if (temp < 0.2)
				{
					m_BoxBottomHeight[i][j] = temp;
					break;
				}
				
			}
			
		}
	
	m_tgawr.LoadTGA(&texture[0], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4front.tga"));
	/*
	m_tgawr.LoadTGA(&texture[1], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4back.tga"));
	m_tgawr.LoadTGA(&texture[2], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[3], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4right.tga"));
	m_tgawr.LoadTGA(&texture[4], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4top.tga"));
	m_tgawr.LoadTGA(&texture[5], _T("E:\\data\\data\\pictrues\\tga\\sands\\sand0.tga"));
	m_tgawr.LoadTGA(&texture[6], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[7], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[8], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[9], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[10], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[11], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[12], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[13], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[14], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[15], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[16], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	*/
		
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
	//airplane(0, 8, -50);					//��Ϸɻ�

	//TextureDraw();
	
	//Textureaa();

	//gluLookAt(0.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(b, a, 5.0f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt(0.0f, 0.0f, a, a, b, c, 0.0, 1.0, 0.0);
	//DisplayScene();						 // �����
	//DrawSand();							 // ��ʾ���ɽ��
	CreateSkyBox(3, 6, 3, 6);				 // ��ʾ��
	//picter(MAP + 10, 0, -MAP);				//��ʾ���ͼ��
	//gluLookAt(0.0f, 0.0f, 0.0f, a, b, c, 0.0, 1.0, 0.0);
	//DrawGround();
	//DrawBottom();

}


void CGraphDraw::light0()//��
{
	GLfloat light_position[] = { 1.0,5.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}
/*
BOOL CGraphDraw::DisplayScene()//��������
{
	float speed = 0.5f;						//����
	float x = g_eye[0], y = g_eye[2], z = g_eye[2];
	if (KEY_DOWN(VK_SHIFT))  speed = speed * 2;//��SHIFTʱ�ļ���true
	if (KEY_DOWN(VK_LEFT))   g_Angle -= speed * 2;//��ת,��λ��-
	if (KEY_DOWN(VK_RIGHT))  g_Angle += speed * 2;//��ת,��λ��+
	rad_xz = float(3.13149* g_Angle / 180.0f);	//����������ת�Ƕ�
	if (KEY_DOWN(33))		   g_elev += speed;	//Page UP  ��
	if (KEY_DOWN(34))		   g_elev -= speed;	//Page Down��
	if (g_elev<-360)		   g_elev = -360;	//������
	if (g_elev> 360)		   g_elev = 360;	//������
	if (KEY_DOWN(VK_UP))						//ǰ��
	{
		g_eye[2] += (float)sin(rad_xz)*speed;			//�ӵ��x����
		g_eye[0] += (float)cos(rad_xz)*speed;			//�ӵ��Z����
	}
	if (KEY_DOWN(VK_DOWN))					//����
	{
		g_eye[2] -= (float)sin(rad_xz)*speed;			//�ӵ��x����
		g_eye[0] -= (float)cos(rad_xz)*speed;			//�ӵ��Z����
	}
	//���Ƶ���������뿪����
	if (g_eye[0]<  MAP_SCALE)			g_eye[0] = MAP_SCALE;
	if (g_eye[0]> (MAP_W - 2)*MAP_SCALE)	g_eye[0] = (MAP_W - 2)*MAP_SCALE;
	if (g_eye[2]<-(MAP_W - 2)*MAP_SCALE)	g_eye[2] = -(MAP_W - 2)*MAP_SCALE;
	if (g_eye[2]> -MAP_SCALE)			g_eye[2] = -MAP_SCALE;
	g_eye[1] = GetHeight((float)g_eye[0], (float)g_eye[2]) + gao;//����������Ե�λ�ø�
																 //������ķ���
	g_look[0] = (float)(g_eye[0] + 100 * cos(rad_xz));	//Ŀ���X����
	g_look[2] = (float)(g_eye[2] + 100 * sin(rad_xz));	//Ŀ���Z����
	g_look[1] = g_eye[1] + g_elev;				//Ŀ���Y����
												//����modelview������
	//g_eye[0] = 0;g_eye[1] = 0;g_eye[2] = 5;g_look[0] = 0;g_look[1] = 0;g_look[2] = 0;
	gluLookAt(g_eye[0], g_eye[1], g_eye[2],		//�ӵ�
		g_look[0], g_look[1], g_look[2],	//Ŀ���
		0.0, 1.0, 0.0						//�ӵ㷽��
	);
	return TRUE;
}
*/
void CGraphDraw::InitTerrain(float h)//������������
{
	int index = 0;
	int Vertex;
	for (int z = 0; z < MAP_W; z++)
		for (int x = 0; x < MAP_W; x++)
		{
			Vertex = z * MAP_W + x;
			g_terrain[Vertex][0] = float(x)*MAP_SCALE;	//��������X����
			g_terrain[Vertex][1] = (float)(g_imageData[(z*MAP_W + x) * 3] / 3);//Y������ɽ�ĸ߶�
																			   //	  g_terrain [Vertex][1] = h + FRAND * h;		//Y�������������ɽ�ĸ߶�
			g_terrain[Vertex][2] = -float(z)*MAP_SCALE;	//��������Z����
			g_texcoord[Vertex][0] = (float)x;			//��������x
			g_texcoord[Vertex][1] = (float)z;				//��������z
			g_index[index++] = Vertex;					//��������1ά
			g_index[index++] = Vertex + MAP_W;
		}
	glEnableClientState(GL_VERTEX_ARRAY);				//����ʹ�õ�������
	glVertexPointer(3, GL_FLOAT, 0, g_terrain);		//װ���������
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);		//����ʹ����������
	glTexCoordPointer(2, GL_FLOAT, 0, g_texcoord);		//װ����������
}
void CGraphDraw::DrawSand()//��ʾ���ɽ��
{
	//glBindTexture(GL_TEXTURE_2D, g_cactus[0]);//����ͼ
	m_tgawr.zTexture2D(texture, 5);		// ����BACK��ͼ��
	glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//�Ŵ���������˲�
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	for (int z = 0; z < MAP_W - 1; z++)
		glDrawElements(GL_TRIANGLE_STRIP, MAP_W * 2, GL_UNSIGNED_INT, &g_index[z*MAP_W * 2]);
	glDisable(GL_TEXTURE_2D);
	//��ʾ�ɶ�������ָ�����档
}
float CGraphDraw::GetHeight(float x, float z)// ȡ����߶�
{
	float CameraX = x / MAP_SCALE;              //��������һ��
	float CameraZ = -z / MAP_SCALE;              //��������һ��
	int Col0 = int(CameraX);                  //����к�
	int Row0 = int(CameraZ);                  //����к�
	int Col1 = Col0 + 1;                      //������
	int Row1 = Row0 + 1;                      //������
	if (Col1 > MAP_W)	Col1 = 0;             //�����д��ڵؿ�����ȡ����
	if (Row1 > MAP_W)	Row1 = 0;             //�����д��ڵؿ�����ȡ����
	float h00 = g_terrain[Col0 + Row0*MAP_W][1];//��ȡ���Ľǵĸ߶�
	float h01 = g_terrain[Col1 + Row0*MAP_W][1];
	float h11 = g_terrain[Col1 + Row1*MAP_W][1];
	float h10 = g_terrain[Col0 + Row1*MAP_W][1];
	float tx = CameraX - int(CameraX);         //�����Xƫ��λ��
	float ty = CameraZ - int(CameraZ);         //�����Zƫ��λ��
	float txty = tx * ty;                     //����Ϊ˫���Բ�ֵ(�ڲ�)����
	return h00*(1.0f - ty - tx + txty)
		+ h01*(tx - txty)
		+ h11*txty
		+ h10*(ty - txty);                  //���ز�ֵ����ֵ��Ϊ�����ĸ߶ȡ�
}
void CGraphDraw::CreateSkyBox(int a, int wi, int he, int le)//��ʾ���
{
	float width = MAP*wi;		// ��պп�
	float height = MAP*he;		// ��պи�
	float length = MAP*le;		// ��պг�
	float x = MAP - width / 2;	// ��յ�λ��x
	float y = MAP / a - height / 2;	// ��յ�λ��y
	float z = -MAP - length / 2;	// ��յ�λ��z
									///////////////////////////////////////////////////////////////////////////////
	m_tgawr.zTexture2D(texture, 1);		// ����BACK��ͼ��
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 0);		// ����FRONT��ͼ��
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 4);		// ����TOP��ͼ��
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���		
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 2);		// ����LEFT��ͼǰ
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 3);		// ����RIGHT��ͼ��
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���		
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

GLvoid CGraphDraw::DrawGround()//��ɫ���������
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





void CGraphDraw::Textureaa()
{
	m_tgawr.zTexture2D(texture, 0);
	glEnable(GL_TEXTURE_2D);
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


void CGraphDraw::DrawBottom()
{
	m_tgawr.zTexture2D(texture, 0);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
	int length,width;
	length = width = m_BoxSize-1;
	GLfloat bottomheight = 0;
	GLfloat microSquare = 0.5;
	GLfloat posX, posY;

	//*
	for(int i=0;i<length;i++)
		for (int j = 0;j < width;j++)
		{
			bottomheight = m_BoxBottomHeight[i][j];

			posX = microSquare*(GLfloat)i;
			posY = microSquare*(GLfloat)j;

			if (i < 100 && j < 100)
			{
				//����
				glBegin(GL_QUADS);

				glTexCoord2f(0.0f, 0.0f); glVertex3f(posX, posY, m_BoxBottomHeight[i][j]);

				glTexCoord2f(0.0f, 1.0f); glVertex3f(posX, posY + microSquare, m_BoxBottomHeight[i][j + 1]);

				glTexCoord2f(1.0f, 1.0f); glVertex3f(posX + microSquare, posY + microSquare, m_BoxBottomHeight[i + 1][j + 1]);

				glTexCoord2f(1.0f, 0.0f); glVertex3f(posX + microSquare, posY, m_BoxBottomHeight[i + 1][j]);
				glEnd();
			}
			
		}
	//*/
	/*
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -1.0f);

	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, -1.0f);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();
	
	*/

	glDisable(GL_TEXTURE_2D);
}



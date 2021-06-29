#include "stdafx.h"
#include "GraphDraw.h"





CGraphDraw::CGraphDraw()
{
	a = b = 0;
	c = 0;


	m_nSelect = 0;

	m_nViewSelect = 2;

	r = 0;

	g_text = gluNewQuadric();
	
	//LoadTGATexture()




	g_eye[0] = MAP;//
	g_eye[2] = -MAP;//

	g_eye[0] = 0;//
	g_eye[2] =5;//
	g_Angle = 0;//
	g_elev = -0;//360;//
	
	gao = -50;


	g_eye[1] = gao;


	m_keyleft=m_keyright=m_keydown = m_keyup = m_keyshift = m_keypagedown = m_keypageup = m_lbuttondown = m_rbuttondown =m_mousemove = m_keyP =0;

	m_BoxSize = 100;
	m_BoxBottomHeightMax = 5;
	//m_BoxBottomHeight[10][10] = 10;
	//m_BoxBottomHeight[50][50] = 10;
	/*
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
	*/
	m_tgawr.LoadTGA(&texture[0], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4front.tga"));
	//*
	m_tgawr.LoadTGA(&texture[1], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4back.tga"));
	m_tgawr.LoadTGA(&texture[2], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4left.tga"));
	m_tgawr.LoadTGA(&texture[3], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4right.tga"));
	m_tgawr.LoadTGA(&texture[4], _T("E:\\data\\data\\pictrues\\tga\\airbox\\4top.tga"));
	m_tgawr.LoadTGA(&texture[5], _T("E:\\data\\data\\pictrues\\tga\\sands\\sand0.tga"));
	m_tgawr.LoadTGA(&texture[6], _T("E:\\data\\data\\pictrues\\tga\\map\\map1.tga"));
	m_tgawr.LoadTGA(&texture[7] , _T("E:\\data\\data\\pictrues\\tga\\map\\baidumap1_1.tga"));
	//m_tgawr.LoadTGA(&texture[6], _T("E:\\data\\data\\pictrues\\tga\\map\\sand1.tga"));
	
	/*
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
	//*/
	//InitTerrain(5);//��ʼ������


	x2D = 10.0f;
	y2D = 10.0f;
	z2D = -13.0f;


	m_fAngelX = m_fAngelY = m_fAngelZ = 0.0f;
	m_fPosX = 40;
	m_fPosY = -52;
	m_fPosZ = -70;
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


	if (m_nViewSelect == 2)
	{
		ViewSelect2D();
	}
	else
		if (m_nViewSelect == 3)
		{
			ViewSelect3D();
		}
			
	
	

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

void CGraphDraw::ViewSelect2D()
{
	DisplayScene2D();
	//Textureaa();
}


void CGraphDraw::ViewSelect3D()
{
	DisplayScene3D();						 // �����
											 //airplane(0, 8, -50);					//��Ϸɻ�
	airplane(MAP , 0 , -MAP);					//��Ϸɻ�
												//TextureDraw();

												//Textureaa();


														
												//DrawSand();							 // ��ʾ���ɽ��
	CreateSkyBox(3 , 6 , 3 , 6);				 // ��ʾ��

	picter(MAP + 10 , -52 , -MAP);				//��ʾ���ͼ��

												//DrawGround();

	DrawPipleNet();

	//DrawMap();
	DrawBottom();
}


BOOL CGraphDraw::DisplayScene2D()
{
	m_tgawr.zTexture2D(texture , 7);
	glEnable(GL_TEXTURE_2D);

	
	

	if (m_keyleft&&x2D>5)x2D--;
    if (m_keyright&&x2D<15)x2D++;
	if (m_keydown&&y2D>5)y2D--;
	if (m_keyup&&y2D<15)y2D++;
	
	if (m_keypageup&&z2D<-5)z2D++;
	if (m_keypagedown&&z2D>-13.0)z2D--;


	GLfloat x , y , z;
	x = x2D;
	y = y2D;
	z = z2D;


	glBegin(GL_QUADS);

	glTexCoord2f(0.0f , 0.0f); glVertex3f(x-20.0 , y - 20.0 , z);

	glTexCoord2f(1.0f , 0.0f); glVertex3f(x , y-20.0 , z);

	glTexCoord2f(1.0f , 1.0f); glVertex3f(x , y , z);

	glTexCoord2f(0.0f , 1.0f); glVertex3f(x-20.0 , y , z);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	return TRUE;
}


BOOL CGraphDraw::DisplayScene3D()//��������
{
	float speed = 5.0f;						//����
	float x = g_eye[0], y = g_eye[2], z = g_eye[2];
	if (m_keyshift)  speed = speed * 2;//��SHIFTʱ�ļ���true
	if (m_keyleft)   g_Angle -= speed * 2;//��ת,��λ��-
	if (m_keyright)  g_Angle += speed * 2;//��ת,��λ��+
	rad_xz = float(3.141592653589793* g_Angle / 180.0f);	//����������ת�Ƕ�
	if (m_keypageup)	   g_elev += speed;	//Page UP  ��
	if (m_keypagedown)		   g_elev -= speed;	//Page Down��
	if (g_elev<-360)		   g_elev = -360;	//������
	if (g_elev> 360)		   g_elev = 360;	//������
	if (m_keyup)						//ǰ��
	{
		g_eye[2] += (float)sin(rad_xz)*speed;			//�ӵ��x����
		g_eye[0] += (float)cos(rad_xz)*speed;			//�ӵ��Z����
	}
	if (m_keydown)					//����
	{
		g_eye[2] -= (float)sin(rad_xz)*speed;			//�ӵ��x����
		g_eye[0] -= (float)cos(rad_xz)*speed;			//�ӵ��Z����
	}
	//���Ƶ���������뿪����
	if (g_eye[0]<  MAP_SCALE)			g_eye[0] = MAP_SCALE;
	if (g_eye[0]> (MAP_W - 2)*MAP_SCALE)	g_eye[0] = (MAP_W - 2)*MAP_SCALE;
	if (g_eye[2]<-(MAP_W - 2)*MAP_SCALE)	g_eye[2] = -(MAP_W - 2)*MAP_SCALE;
	if (g_eye[2]> -MAP_SCALE)			g_eye[2] = -MAP_SCALE;
	//g_eye[1] = GetHeight((float)g_eye[0], (float)g_eye[2]) + gao;//����������Ե�λ�ø�
	g_eye[1] = gao;//����������Ե�λ�ø�
	
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

void CGraphDraw::InitTerrain(float h)//������������
{
	int index = 0;
	int Vertex;
	for (int z = 0; z < MAP_W; z++)
		for (int x = 0; x < MAP_W; x++)
		{
			Vertex = z * MAP_W + x;
			//g_terrain[Vertex][0] = float(x)*MAP_SCALE;	//��������X����
			//g_terrain[Vertex][1] = (float)(g_imageData[(z*MAP_W + x) * 3] / 3);//Y������ɽ�ĸ߶�
																			   //	  g_terrain [Vertex][1] = h + FRAND * h;		//Y�������������ɽ�ĸ߶�
			//g_terrain[Vertex][2] = -float(z)*MAP_SCALE;	//��������Z����
			//g_texcoord[Vertex][0] = (float)x;			//��������x
			//g_texcoord[Vertex][1] = (float)z;				//��������z
			//g_index[index++] = Vertex;					//��������1ά
			//g_index[index++] = Vertex + MAP_W;

			g_terrain[Vertex][0] = x*MAP_SCALE;	//��������X����
			//g_terrain[Vertex][1] = (float)(g_imageData[(z*MAP_W + x) * 3] / 3);//Y������ɽ�ĸ߶�
			g_terrain [Vertex][1] = h + FRAND * h;		//Y�������������ɽ�ĸ߶�
			g_terrain[Vertex][2] = -z*MAP_SCALE;	//��������Z����
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
	//glGenTextures(1, &texture[0]);
	//glBindTexture(GL_TEXTURE_2D, g_cactus[5]);//����ͼ
	//glBindTexture(GL_TEXTURE_2D, texture[5]);//����ͼ
	m_tgawr.zTexture2D(texture, 5);		
	//glEnable(GL_TEXTURE_2D);
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
	m_tgawr.zTexture2D(texture, 2);		// ����BACK��ͼ��
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 3);		// ����FRONT��ͼ��
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
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 0);		// ����LEFT��ͼǰ
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	m_tgawr.zTexture2D(texture, 1);		// ����RIGHT��ͼ��
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
	int bottom;
	bottom = 0;
	for (int x = -size0; x < size0;x += 4)
	{
		glVertex3i(x, bottom, -size0); glVertex3i(x, bottom, size0);
	}
	for (int z = -size0; z < size0;z += 4)
	{
		glVertex3i(-size0, bottom, z); glVertex3i(size0, bottom, z);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
	glPopAttrib();//�ָ�ǰһ����
}


void CGraphDraw::DrawMap()
{
	float size = (float)(MAP * 2);
	size = 10.0f;
	float bottom;
	bottom = 20.0f;

	glTranslatef(0, 0.0f, 0);		//ƽ̨�Ķ�λ

	glDisable(GL_TEXTURE_2D);
	m_tgawr.zTexture2D(texture,6);
	/*
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -bottom, -size);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -bottom, size);

	glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, bottom, size);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, bottom, -size);
	glEnd();
	*/
	/*
	float a;
	a = 10;
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, -a, -a);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-a, -a, a);

	glTexCoord2f(1.0f, 1.0f); glVertex3f(-a, a, a);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(-a, a, -a);
	glEnd();
	*/
	//MAP=384,width=2304,height=1152,length=2304,x=-768,y=-384,z=-1536
	//float wi, he, le, a;
	//he = a = 3;wi = le = 6;
	//glDisable(GL_TEXTURE_2D);float width = MAP*wi;		// ��պп�
	//float height = MAP*he;		// ��պи�
	//float length = MAP*le;		// ��պг�
	//float x = MAP - width / 2;	// ��յ�λ��x
	//float y = MAP / a - height / 2;	// ��յ�λ��y
	//float z = -MAP - length / 2;	// ��յ�λ��z

	
	float width , height , length , x , y , z ;
	width = 2304; height = 1152; length = 2304; x = -768; y = -384; z = -1536;
	y = -80;


	//glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);			// �����������ı���		
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y , z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y , z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y , z);
	glEnd();

	glDisable(GL_TEXTURE_2D);
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
	m_tgawr.zTexture2D(texture, 5);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
	int length,width;
	length = width = m_BoxSize-1;
	GLfloat bottomheight = 0;
	GLfloat microSquare = 0.5;
	GLfloat posX, posY,posZ;

	/*
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
	//bottomheight = -1536;
	microSquare = 50;
	length = 2304;
	width = 2304;
	posY = -60;
	//posY = -70;


	for (int i = 0;i<50;i++)
		for (int j = 0;j <50 ;j++)
		{
			//bottomheight = m_BoxBottomHeight[i][j];

			posX = microSquare*(GLfloat)i-1000;
			posZ = microSquare*(GLfloat)j-1536;
			//posX = microSquare;
			//posZ = microSquare-1536;
			//if (i != 25 && j != 25)
			{
				//����
				glBegin(GL_QUADS);

				glTexCoord2f(1.0f , 1.0f); glVertex3f(posX + microSquare , posY , posZ);

				glTexCoord2f(0.0f , 1.0f); glVertex3f(posX + microSquare , posY , posZ + microSquare);

				glTexCoord2f(0.0f , 0.0f); glVertex3f(posX  , posY  , posZ + microSquare);

				glTexCoord2f(1.0f , 0.0f); glVertex3f(posX  , posY , posZ);
				glEnd();
			}


		}

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

















void CGraphDraw::InitLightParameter()
{
	m_lightAmb[0] = 1.0f;m_lightAmb[1] = 0.2f;m_lightAmb[2] = 0.2f;m_lightAmb[3] = 1.0f;
	m_lightDif[0] = 1.0f;m_lightDif[1] = 1.0f;m_lightDif[2] = 0.3f;m_lightDif[3] = 1.0f;
	m_lightSpe[0] = 1.0f;m_lightSpe[1] = 1.0f;m_lightSpe[2] = 1.0f;m_lightSpe[3] = 1.0f;
	m_lightPos[0] = 1.0f;m_lightPos[1] = 1.0f;m_lightPos[2] = 1.0f;m_lightPos[3] = 0.0f;
}

void CGraphDraw::InitMatrialParameter(int s)
{
	/*
	m_materialAmb[0] = 1.0f;m_materialAmb[1] = 0.2f;m_materialAmb[2] = 0.2f;m_materialAmb[3] = 1.0f;
	m_materialDif[0] = 1.0f;m_materialDif[1] = 1.0f;m_materialDif[2] = 0.3f;m_materialDif[3] = 1.0f;
	m_materialSpe[0] = 1.0f;m_materialSpe[1] = 1.0f;m_materialSpe[2] = 1.0f;m_materialSpe[3] = 1.0f;
	m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
	m_materialShininess[0] = 10.0f;m_materialShininess[1] = 10.0f;m_materialShininess[2] = 0.0f;m_materialShininess[3] = 10.0f;
	*/
	switch (s)
	{
	case 0:
	{
		//��//��
		m_materialAmb[0] = 0.25f;m_materialAmb[1] = 0.25f;m_materialAmb[2] = 0.25f;m_materialAmb[3] = 1.0f;
		m_materialDif[0] = 0.4f;m_materialDif[1] = 0.4f;m_materialDif[2] = 0.4f;m_materialDif[3] = 1.0f;
		m_materialSpe[0] = 0.774597f;m_materialSpe[1] = 0.774597f;m_materialSpe[2] = 0.774597f;m_materialSpe[3] = 0.774597f;
		m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
		m_materialShininess[0] = m_materialShininess[1] = m_materialShininess[2] = m_materialShininess[3] = 76.800003;

	}break;
	case 1:
	{
		//��//��
		m_materialAmb[0] = 0.24725f;m_materialAmb[1] = 0.199500f;m_materialAmb[2] = 0.074500f;m_materialAmb[3] = 1.0f;
		m_materialDif[0] = 0.751640f;m_materialDif[1] = 0.606480f;m_materialDif[2] = 0.226480f;m_materialDif[3] = 1.0f;
		m_materialSpe[0] = 0.628281f;m_materialSpe[1] = 0.555802f;m_materialSpe[2] = 0.366065f;m_materialSpe[3] = 0.774597f;
		m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
		m_materialShininess[0] = m_materialShininess[1] = m_materialShininess[2] = m_materialShininess[3] = 51.200001f;
	}break;
	case 2:
	{
		//��//��
		m_materialAmb[0] = 0.192250f;m_materialAmb[1] = 0.192250f;m_materialAmb[2] = 0.192250f;m_materialAmb[3] = 1.0f;
		m_materialDif[0] = 0.507540f;m_materialDif[1] = 0.507540f;m_materialDif[2] = 0.507540f;m_materialDif[3] = 1.0f;
		m_materialSpe[0] = 0.508273f;m_materialSpe[1] = 0.508273f;m_materialSpe[2] = 0.508273f;m_materialSpe[3] = 0.774597f;
		m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
		m_materialShininess[0] = m_materialShininess[1] = m_materialShininess[2] = m_materialShininess[3] = 51.200001f;
	}break;
	default:
	{
		//��//��
		m_materialAmb[0] = 0.25f;m_materialAmb[1] = 0.25f;m_materialAmb[2] = 0.25f;m_materialAmb[3] = 1.0f;
		m_materialDif[0] = 0.4f;m_materialDif[1] = 0.4f;m_materialDif[2] = 0.4f;m_materialDif[3] = 1.0f;
		m_materialSpe[0] = 0.774597f;m_materialSpe[1] = 0.774597f;m_materialSpe[2] = 0.774597f;m_materialSpe[3] = 0.774597f;
		m_materialPos[0] = 1.0f;m_materialPos[1] = 1.0f;m_materialPos[2] = 1.0f;m_materialPos[3] = 0.0f;
		m_materialShininess[0] = m_materialShininess[1] = m_materialShininess[2] = m_materialShininess[3] = 76.800003;
	}
	}



}

void CGraphDraw::CreateLights()
{
	glLightfv(GL_LIGHT0 , GL_AMBIENT , m_lightAmb);
	glLightfv(GL_LIGHT0 , GL_DIFFUSE , m_lightDif);
	glLightfv(GL_LIGHT0 , GL_SPECULAR , m_lightSpe);
	glLightfv(GL_LIGHT0 , GL_POSITION , m_lightPos);


	glEnable(GL_LIGHTING);
	/*���ɴ���8յ��*/
	glEnable(GL_LIGHT0);

}

void CGraphDraw::CreateMaterial()
{
	glMaterialfv(GL_FRONT , GL_AMBIENT , m_materialAmb);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , m_materialDif);
	glMaterialfv(GL_FRONT , GL_SPECULAR , m_materialSpe);
	glMaterialfv(GL_FRONT , GL_POSITION , m_materialPos);
	glMaterialfv(GL_FRONT , GL_SHININESS , m_materialShininess);
	glEnable(GL_COLOR_MATERIAL);

}






void CGraphDraw::DrawCylinder(GLfloat x , GLfloat y , GLfloat z)
{
	if (m_keydown)m_fAngelX -= 3;
	if (m_keyup)m_fAngelX += 3;
	if (m_keyleft)m_fAngelY -= 3;
	if (m_keyright)m_fAngelY += 3;


	InitLightParameter();
	InitMatrialParameter(2);

	CreateLights();
	CreateMaterial();


	GLUquadricObj* quadObj;
	/*Բ��*/
	glNewList(1 , GL_COMPILE);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj , GLU_FILL);
	gluQuadricNormals(quadObj , GLU_SMOOTH);
	gluCylinder(quadObj , 0.3 , 0.3 , 0.8 , 16 , 16);
	glEndList();




	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��

	glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
	glLineWidth(1.5f);
	glColor3f(0.5f , 1.0f , 1.0f);




	glPushMatrix();//ƽ̨==============================
	glTranslatef(x , y + 0.5f , z);		//ƽ̨�Ķ�λ


	glRotatef(-90.0f , 0.0f , 1.0f , 0.0f);
	glTranslatef(0.0f , 0.0f , 1.0f);
	glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);

	//glRotatef(r , 1 , 1 , 1);
	glScalef(0.3 , 0.3 , 3.0);
	glCallList(1);
	glPopMatrix();



	//�ӿ�
	glLoadIdentity();
	glPushMatrix();

	glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);

	glPushMatrix();
	glColor3f(0.5f , 0.0f , 1.0f);
	glTranslatef(0.0f , 0.0f , 0.0f);
	//glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	//glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	//glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);
	glScalef(0.1f , 0.1f , 1.0f);
	glCallList(1);
	glPopMatrix();

	//�ӿ��м�
	glPushMatrix();
	glColor3f(0.0f , 0.0f , 0.0f);
	//glTranslatef(0.0f , 0.0f , 0.0f);
	//glRotatef(0, 0.0f , 1.0f , 0.0f);
	//glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	//glRotated(m_fAngelY-90 , 0.0 , 1.0 , 0.0);
	//glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);
	glScalef(0.1f , 0.1f , 0.1f);
	glCallList(1);
	glPopMatrix();
	glPopMatrix();
	glPopAttrib();

	/*
	glPushMatrix();
	glColor3f(0 , 1 , 0);
	glTranslatef(-2 , 2.0 , -12);
	glRotatef(r , 1 , 1 , 1);
	glScalef(0.3 , 0.3 , 10.0);
	Cylinder();
	glPopMatrix();

	glColor3f(0.0f , 0.0f , 1.0f);
	glRotatef(15 / 360.0*360.0 , 0.0f , 0.0f , -1.0f);
	glTranslatef(150 , 0.0f , 0.0f);
	glutSolidSphere(15.945 , 100 , 100);
	*/

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_COLOR_MATERIAL);
}


void CGraphDraw::DrawPiple(GLfloat x , GLfloat y , GLfloat z , int color)
{

	//InitLightParameter();
	//InitMatrialParameter(1);

	//CreateLights();
	//CreateMaterial();

	//glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
	//glLineWidth(1.5f);
	//glColor3f(0.5f , 1.0f , 1.0f);




	GLUquadricObj* quadObj;
	/*Բ��*/
	glNewList(1 , GL_COMPILE);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj , GLU_FILL);
	gluQuadricNormals(quadObj , GLU_SMOOTH);
	gluCylinder(quadObj , 0.3 , 0.3 , 0.8 , 16 , 16);
	glEndList();



	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��

	glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
	glLineWidth(1.5f);

	if (color == 1)glColor3f(0.5f , 1.0f , 1.0f);
	if (color == 2)glColor3f(0.5f , 0.0f , 1.0f);
	if (color == 3)glColor3f(0.5f , 1.0f , 0.0f);

	glPushMatrix();//ƽ̨==============================

	glTranslatef(x , y , z);		//ƽ̨�Ķ�λ

									//glColor3f(0.0f , 1.0f , 0.2f);		//��ɫ

	glRotatef(90 , 0.0 , 1.0 , 0.0);
	glScalef(1 , 1 , 80.0);
	glCallList(1);
	glPopMatrix();

	glPopAttrib();//�ָ�ǰһ����



}


void CGraphDraw::drawaaa()
{
	InitLightParameter();
	//InitMatrialParameter(1);

	CreateLights();

	glColor3f(0 , 1 , 1);

	///�����������ֵ
	float no_mat[] = { 0.0f , 0.0f , 0.0f , 1.0f };        // �޲�����ɫ
	float mat_ambient[] = { 0.7f , 0.7f , 0.7f , 1.0f };   // ������ɫ
	float mat_ambient_color[] = { 0.8f , 0.6f , 0.2f , 1.0f };
	float mat_diffuse[] = { 0.2f , 0.5f , 0.8f , 1.0f };   // ɢ����ɫ
	float mat_specular[] = { 1.0f , 1.0f , 1.0f , 1.0f };  // ���淴����ɫ
	float no_shininess[] = { 0.0f };                    // ���淴��ָ��Ϊ0
	float low_shininess[] = { 5.0f };                   // ���淴��ָ��Ϊ5.0
	float high_shininess[] = { 100.0f };                // ���淴��ָ��Ϊ100.0
	float mat_emission[] = { 0.3f , 0.2f , 0.3f , 0.0f };  // �������ɫ

														   //������沢���õ�λ����


														   // ��һ�е�һ�л��Ƶ���������������޻�����;���⡣
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-2.0f , 1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , no_mat);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// ��һ�еڶ��л��Ƶ������������;���⣬���е͸߹⣬���޻�����
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-0.5f , 1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , no_mat);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , low_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// ��һ�е����л��Ƶ������������;���⣬���к����ĸ߹⣬���޻����� ��*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(1.0f , 1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , no_mat);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , high_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// ��һ�е����л��Ƶ������������ͷ���⣬���޻����;��淴��⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(2.5f , 1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , no_mat);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , mat_emission);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();




	// �ڶ��е�һ�л��Ƶ������������ͻ����⣬�����淴��⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-2.0f , 0.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �ڶ��еڶ��л��Ƶ�����������⡢������;���⣬���е͸߹⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-0.5f , 0.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , low_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �ڶ��е����л��Ƶ�����������⡢������;���⣬���к����ĸ߹⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(1.0f , 0.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , high_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �ڶ��е����л��Ƶ�����������⡢������ͷ���⣬���޾���⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(2.5f , 0.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , mat_emission);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �����е�һ�л��Ƶ�����������������ɫ�Ļ����⣬���޾���⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-2.0f , -1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient_color);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();
	// �����еڶ��л��Ƶ�����������������ɫ�Ļ������Լ�����⣬���е͸߹⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(-0.5f , -1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient_color);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , low_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �����е����л��Ƶ�����������������ɫ�Ļ������Լ�����⣬���к����ĸ߹⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(1.0f , -1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient_color);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , mat_specular);
	glMaterialfv(GL_FRONT , GL_SHININESS , high_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , no_mat);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

	// �����е����л��Ƶ�����������������ɫ�Ļ������Լ�����⣬���޾���⡣*/
	glPushMatrix();
	glScalef(1 , 1 , 1);
	glTranslatef(2.5f , -1.5f , -7.0f);
	glMaterialfv(GL_FRONT , GL_AMBIENT , mat_ambient_color);
	glMaterialfv(GL_FRONT , GL_DIFFUSE , mat_diffuse);
	glMaterialfv(GL_FRONT , GL_SPECULAR , no_mat);
	glMaterialfv(GL_FRONT , GL_SHININESS , no_shininess);
	glMaterialfv(GL_FRONT , GL_EMISSION , mat_emission);
	glutSolidSphere(0.5f , 30 , 30); //(0.3f);
	glPopMatrix();

}


void CGraphDraw::picter1(float x , float y , float z)//���ͼ��
{
	r += 1;if (r>360) r = 0;

	if (m_keydown)m_fAngelX -= 3;
	if (m_keyup)m_fAngelX += 3;
	if (m_keyleft)m_fAngelY -= 3;
	if (m_keyright)m_fAngelY += 3;
	if (m_keypagedown)m_fAngelZ -= 3;
	if (m_keypageup)m_fAngelZ += 3;

	InitLightParameter();
	InitMatrialParameter(2);

	CreateLights();
	CreateMaterial();


	GLUquadricObj* quadObj;
	/*Բ��*/
	glNewList(1 , GL_COMPILE);
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj , GLU_FILL);
	gluQuadricNormals(quadObj , GLU_SMOOTH);
	gluCylinder(quadObj , 0.3 , 0.3 , 0.8 , 16 , 16);
	glEndList();



	glPushAttrib(GL_CURRENT_BIT);//����������ɫ��ʵ��

	glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
	glLineWidth(1.5f);
	glColor3f(0.5f , 1.0f , 1.0f);

	glPushMatrix();//ƽ̨==============================
	glTranslatef(x , y + 0.5f , z);		//ƽ̨�Ķ�λ
	glColor3f(0.0f , 1.0f , 0.2f);		//��ɫ
										//auxSolidCube(1);				//��̨(�߳�)
	glutSolidCube(1);

	//

	//glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	//glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	//glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);
	//glTranslatef(x+m_fAngelX , y + 0.5f+m_fAngelY , z+m_fAngelZ);
	glRotatef(90 , 0.0 , 1.0 , 0.0);
	glScalef(3 , 3 , 30.0);
	glCallList(1);


	//
	//glRotatef(90 , 1.0 , 0.0 , 0.0);
	//glTranslatef(x , y + 0.5f , z);		//ƽ̨�Ķ�λ												//glTranslatef(-2.0 , 0.1, m_fAngelY);
	//glScalef(3 , 3 , 5);
	//glCallList(1);
	//


	glTranslatef(0.0f , 0.8f , 0.0f);	//�ܵ�λ�õ���,����0.8
	glColor3f(0.0f , 0.0f , 1.0f);		//��ɫ
										//auxSolidBox(.2f, 1.3f, .2f);		//������(���ߡ���)
	glPopMatrix();

	glPushMatrix();
	//glLoadIdentity();
	glRotatef(90 , 1.0 , 0.0 , 1.0);
	glRotatef(m_fAngelX , 1.0f , 0.0f , 0.0f);
	glRotated(m_fAngelY , 0.0 , 1.0 , 0.0);
	glRotatef(m_fAngelZ , 0.0f , 0.0f , 1.0f);
	//glRotatef(90 , 0.0 , 0.0 , -1.0);
	glTranslatef(x , y + 0.5f , z);		//ƽ̨�Ķ�λ												//glTranslatef(-2.0 , 0.1, m_fAngelY);
	glScalef(4 , 4 , 40);
	glCallList(1);
	glPopMatrix();


	glPushMatrix();
	//glLoadIdentity();
	//glRotatef(90 , 1.0 , 0.0 , 1.0);
	glTranslatef(x + 5 , y + 0.5f , z);		//ƽ̨�Ķ�λ												//glTranslatef(-2.0 , 0.1, m_fAngelY);
	glScalef(4 , 4 , 40);
	glCallList(1);
	glPopMatrix();



	glPushMatrix();//�״�==============================
	glTranslatef(x , y + 2.5f , z);		//�״�Ķ�λ1
	glRotatef(-r , 0.0 , 1.0 , 0.0);	//�״���ת2
										//=======================================
	glColor3f(1.0f , 1.0f , 1.0f);		//��ɫ
	glRotatef(45 , 1.0 , 0.0 , 0.0);	//�̵ĽǶȵ�������30��
										//auxWireCone(1.5, 0.6f);			//��԰׶��(�װ뾶����)
	glutSolidCone(1.5 , 0.6f , 50 , 50);

	//=======================================
	glRotatef(180 , 1.0 , 0.0 , 0.0);	//�˵ĽǶȵ���,������ת
	glTranslatef(0.0f , 0.0f , -0.7f);  //�˵�λ�õ���,����һ��
										//auxWireCone(0.2f, 2.0f);			//԰׶��(�װ뾶����)
	glutSolidCone(0.2 , 2.0f , 50 , 50);

	glColor3f(FRAND , 0 , 0);			//�����ɫ
	glTranslatef(0.0f , 0.0f , 2.0f);	//�˵�λ�õ���,����һ��
										//auxSolidSphere(0.1f);			//԰(�뾶)
	glutSolidSphere(0.1f , 50 , 50);

	glPopMatrix();

	glPushMatrix();//���=============================
	glTranslatef(x , y + 7.0f , z);		//����Ķ�λ
	glRotatef(-r , 0.0 , 1.0 , 0.0);	//�������ת
	glTranslatef(15 , 0 , 0);			//����Ķ�λ
										//=============================================
	glColor3f(1.0f , 0.0f , 0.0f);		//��ɫ
										//glRotatef(180, 0.0, 1.0, 0.0);	//�Ƕȵ���,���״�ƽ�У���ͷ��ǰ
										//auxSolidCone(.2, 0.6);			//԰׶(�װ뾶����)
	glutSolidCone(0.2 , 0.6f , 50 , 50);
	//=============================================
	glColor3f(1.0f , 1.0f , 1.0f);		//��ɫ
	glRotatef(90 , 1.0 , 0.0 , 0.0);	//�Ƕȵ���,����ͷ�Խ�
	glTranslatef(0.0f , -1.0f , 0);		//λ�õ���,����ͷ�Խ�
										//auxSolidCylinder(.2f, 1);		//԰��(�뾶����)
										//glScalef(6.0f, 6.0f, 6.0f);//x,y,z����Ŵ�6��  
										//glutWireDodecahedron();
	glutSolidCube(0.3);
	glRotatef(-270 , 1.0 , 0.0 , 0.0);
	glColor3f(FRAND + .6f , 0.2f , 0.0f);	//���ɫ
	glTranslatef(0.0f , -0.0f , -0.2f); //λ�õ���,����һ��
										//auxSolidCone(.2, 1.5);			//԰׶(�װ뾶����)
	glutSolidCone(0.2 , 1.5f , 50 , 50);
	glPopMatrix();
	glPopAttrib();//�ָ�ǰһ����

}



void CGraphDraw::DrawPipleNet()
{
	GLfloat x , y , z;
	x = y = z = 0.0f;
	///*
	//int i = 0;
	for (int i = 0;i < 3;i++)
	{
		if (i == 0) y = m_fPosY;
		if (i == 1)y = m_fPosY + 3;
		if (i == 2)y = m_fPosY + 6;
		x = m_fPosX;
		z = m_fPosZ;

		//DrawPiple(x , y , z , 3);
		//DrawPiple(x , y , z+2 , 3);
		for (int j = 0;j < 10;j++)
		{
			//if (pipledraw[i][j])
			{

				DrawPiple(x , y , z , piplecolor[i][j]);
				z += 2;
			}
		}
	}




}

#pragma once
#include "stdafx.h"
#include"TGAWR.h"






//enum { Cube };

/************************************************************************************************/
/*                                                                                              */
/*���ڴ�С��CMainFrame����#��ʼ����cs.cx,cs.cy***************************************************/
/*                                                                                              */
/***************************************OpenGL��ʼ��*********************************************/
/*                                                                                              */
/*GLInit()��ʼ����view��Init()��ʼ�������б����ã����ڳ�ʼ����ͼ����*****************************/
/*GLSize()��ʼ����view��Size()��ʼ�������б����ã����ڳ�ʼ��GL��ͼ�����ӵ��С*******************/
/*GLDraw()��ʼ����view��OnDraw()�����б����ã�GLDraw()����DrawScene()��ʼ����ͼ����**************/
/*GLDestroy()��ʼ����view��OnDestroy()�����б����ã��������ٻ�ͼ����*****************************/
/*                                                                                              */
/************************************************************************************************/




class CGraphDraw :
	public CWnd
{
public:
	CGraphDraw();
	~CGraphDraw();







	/*����*/
protected:

	


	/*����*/
public:


	float a, b, c;

	bool m_keyleft,m_keyright,m_keydown, m_keyup, m_keyshift, m_keypageup, m_keypagedown , m_lbuttondown , m_rbuttondown , m_mousemove,  m_keyP;

	int m_nViewSelect;

	int m_nSelect;
	double r;

	/*��ǰ���ڴ�С*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;

	

	/*����*//*2D��ͼ*/
public:
	GLfloat x2D , y2D , z2D;
	
	/*����*//*2D��ͼ*/
public:
	void ViewSelect2D();
	BOOL		DisplayScene2D();



	/*����*//*3D��ͼ*/
public:

	/*����*//*3D��ͼ*/
public:
	void ViewSelect3D();

public:

	UINT g_cactus[16];	//��ͼ
	GLUquadricObj *g_text;

	CTGAWR m_tgawr;
	float  gao ;

	TextureImage texture[16];
	BITMAPINFOHEADER  g_bit;                        //
	unsigned char    *g_imageData;                  //

	int m_BoxSize,m_BoxBottomHeightMax;
	GLfloat m_BoxBottomHeight[100][100] = { 0 };

public:
	//A����
	float		g_terrain[MAP_W*MAP_W][3];	    //��������
	GLuint		g_index[MAP_W*MAP_W * 2];	    //��������
	float		g_texcoord[MAP_W*MAP_W][2];	    //��������
	void		InitTerrain(float h);	            //�����������
	void		DrawSand();					        //��ʾ���ɽ��
	float		GetHeight(float x, float z);        //ȡ��ǰλ�ø߶�
	//B������
	float	    g_eye[3]; 	                        //�ӵ�
	float	    g_look[3];	                        //Ŀ���
	float	    rad_xz;		                        //�Ƕ�
	float	    g_Angle;	                        //��λ��
	float	    g_elev;		                        //������
	BOOL		DisplayScene3D();	                    //��������
	//C���졢����
	//UINT		g_cactus[16];	                    //��ͼ
	
	void		CreateSkyBox(int a, int wi, int he, int le);//��ʾ��
	
	void		light0();                           // ������

	GLvoid DrawGround();

	void Box(float x, float y, float z);
	void picter(float x, float y, float z);//���ͼ��
	void airplane(float x, float y, float z);//��Ϸɻ�
	//void light0(float x, float y, float z, float a);//��
	
	void DrawBottom();
	void DrawMap();



	



	/*��������ʼ��*/
protected:
	
	/*����*/
public:
	

	
	GLfloat xRot, yRot, zRot;

	

	/*����*/
public:
	//����TGA�ļ�texture��ͼ����
	void Textureaa();

	
													
	
	

public:
	/*�滭ѡ��*/
	void GLDraw(int select);

	

	
	/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()


	public:

		/*��Դ*/
		/*���û����⣬������⣬�۹�ָ������Դλ��*/
		GLfloat m_lightAmb[4] , m_lightDif[4] , m_lightSpe[4] , m_lightPos[4];

		/*����*/
		GLfloat m_materialAmb[4] , m_materialDif[4] , m_materialSpe[4] , m_materialPos[4] , m_materialShininess[4];
		BOOL m_bMatrial;


		/*��������ʼ��*/
protected:
	/*��ʼ����Դ����*/
	void InitLightParameter();

	/*��ʼ�����ʲ���*/
	void InitMatrialParameter(int s);

	/*������Դ*/
	void CreateLights();

	/*��������*/
	void CreateMaterial();




public:
	/*��ʼ�Ƕ�*/
	GLfloat m_fAngelX , m_fAngelY , m_fAngelZ;

	/*��ʼλ��*/
	GLfloat m_fPosX , m_fPosY , m_fPosZ;
	int pipleposX[3][10] = { 0 };
	int pipleposZ[3][10] = { 0 };

	int piplenum[3][10] = { { 1,2,3,4,5,6,7,8,9,10 },{ 1,2,3,4,5,6,7,8,9,10 },{ 1,2,3,4,5,6,7,8,9,10 } };
	float piplelength[3][10] = { 10 };
	int piplecolor[3][10] = { { 1,2,3,1,2,3,1,2,3,1 },{ 1,2,3,1,2,3,1,2,3,1 },{ 1,2,3,1,2,3,1,2,3,1 } };
	bool pipledraw[3][10] = { 1 };
	//int piplelayer[3][10] = { 0 };


public:
	//int story , int num , int color;
	void DrawCylinder(GLfloat x , GLfloat y , GLfloat z);
	void DrawPiple(GLfloat x , GLfloat y , GLfloat z , int color);
	void drawaaa();
	void picter1(float x , float y , float z);
	void DrawPipleNet();

};


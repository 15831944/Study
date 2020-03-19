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

	bool m_keydown, m_keyup, m_keyshift, m_keypageup, m_keypagedown;

	int m_nSelect;
	double r;

	/*��ǰ���ڴ�С*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;

	

	


	/*����*/
public:

	UINT g_cactus[16];	//��ͼ
	GLUquadricObj *g_text;

	CTGAWR m_tgawr;
	float  gao = 1.8f;

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
	BOOL		DisplayScene();	                    //��������
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



};


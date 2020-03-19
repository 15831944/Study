#pragma once
//#include "afxwin.h"
#include"stdafx.h"




/**/





#define ABS(x) ((x)<0?-(x):(x)>0?(x):0)





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
public:





	int m_nSelect;


	/*����*/
protected:

	int a, b, c;



	GLubyte image[64][64][3];




	/*����*/
public:

	/*Mip��ͼ*//*Mip�Զ���ͼ*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;


	/*��������ʼ��*/
protected:



	/*����*/
public:

	GLfloat	r;       //�ɻ������Ƕ�
	float  gao = 1.8f;
	CString	test;    //������Ϣ



	/*����*/
public:

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
	UINT		g_cactus[16];	                    //��ͼ
	BITMAPINFOHEADER  g_bit;                        //
	unsigned char    *g_imageData;                  //
	void		CreateSkyBox(int a, int wi, int he, int le);//��ʾ��
	void		texture(UINT textur);				//������ͼ�˲�
	void		light0();                           // ������
													//D��
	void		picter(float x, float y, float z);    //���ͼ��
	bool		LoadT8(char *filename, GLuint &texture); //��8λ��ͼ
	void		LoadT16(char *filename, GLuint &texture);//��16λ��ͼ
	unsigned char* LoadBit(char *filename, BITMAPINFOHEADER *bitmap);
	//E����
	void		ShowTree(float x, float z, float h, float s, int cactus);//��
	void		ShowTree0(float x, float z, float h, float s, int cactus);//��ͨƽ����













public:


public:
	/*�滭ѡ��*/
	void GLDraw(int select);




	/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()



};


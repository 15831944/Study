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

	int a, b, c;


	/*����*/
public:
	int m_nSelect;
	double r;

	/*��ǰ���ڴ�С*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;

	

	


	/*����*/
public:

	UINT g_cactus[16];	//��ͼ
	GLUquadricObj *g_text;
	void Box(float x, float y, float z);
	void picter(float x, float y, float z);//���ͼ��
	void airplane(float x, float y, float z);//��Ϸɻ�
	void light0(float x, float y, float z, float a);//��
	bool LoadT8(char *filename, GLuint &texture);//��8λ��ͼ

	/*��������ʼ��*/
protected:
	
	/*����*/
public:
	

	CTGAWR m_tgawr;

	TextureImage texture[1];
	GLfloat xRot, yRot, zRot;

	int numtest;

	/*����*/
public:

	


	void TextureDraw();
	void Textureaa();








	






public:


public:
	/*�滭ѡ��*/
	void GLDraw(int select);

	

	
	/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()



};


#pragma once
//#include "afxwin.h"
#include"stdafx.h"

/*OpenGLͷ�ļ�*/
#include <GL\gl.h>  
#include <GL\glu.h>
#include <GL\glut.h>
#include <GL\glaux.h>



/**/


#include "Dib.h"


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

	CDib* m_pDib;


	/*����*/
public:

	/*Mip��ͼ*//*Mip�Զ���ͼ*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;


	/*��������ʼ��*/
protected:
	


	/*����*/
public:
	




	/*����*/
public:











	void DrawPoints();

	void DrawLines();

	void DrawTraingles();

	void DrawTraingleStrip();

	void DrawTraingleFun();

	/*�ı���*/
	void DrawQuadrilateral();

	/*�ı���Ƭ*/
	void DrawQuadrilateralStrip();

	/*������Σ��ߵĿɼ���*/
	/*glEdgeFlag()��������˵���ߵĿɼ��ԣ�TRUE �ɼ���FALSE ���ɼ�*/
	void DrawNonConvex();

	/*���洴����άͼ��*/
	/*������*/
	void DrawCube();

	void DrawCube(GLdouble GLdLength);


	/*���ű任*/
	void PfmScale();

	/*���б任*/
	void PfmClip();

	/*����*/
	void PfmAssemble();

	/*���ƿ���ƽ��ģ��*/
	/*����*/
	void Quadrangle(GLdouble dQuadWidth, GLdouble dQuadHeight);
	/*����*/
	void Wheel(GLdouble dWheelRadius);
	/*����*/
	void PfmMatrixStack();

	/*��ʾ�б�*/
	/*������ʾ�б�*/
	/*Բ��*/
	void Trous();

	/*��һ����*/
	void DrawSphere();

	/*ƽ������*/
	void DrawSmoothCube();


	/*��ȡͼ��*/
	void mImage();

	/*������ͼ*/
	void TexturePlane();

	/*λͼ��ͼ*/
	void BitmapTexture();

	/*���������Զ�����*/
	void TexGenerate();

	/*Mip��ͼ*/
	void Mipmapping();

	/*Mip�Զ���ͼ*/
	void AutoMipmapping();

	/*�ں��ı���*/
	void BlendQuads();



	/*��һ����*/
	GLint Sphere(GLdouble radius);
	/*͸������*/
	void BlendObjects();

	/*���ƶ�������*/
	void DrawQuadrics();

	/*Berzier����*/
	/*����һ������������*/
	void DrawBezierCurve();
	void EvenBezierCurve();
	void DrawBezier();


	/*�޷���ʾ*/
	/*NURBS����*/
	/*����һ��NURBS����*/
	void DrawNurbsCurve();

	/*Bezier����*/
	/*������������*/
	void BzrSufacMesh();

	/*Bezier����*/
	/*���������������*/
	void BzrSufacMeshFill();

	/*�޷���ʾ*/
	/*Bezier����*/
	/*��λͼ����������*/
	void BzrSufacTex();

	/*Nurbs����*/
	/*������������*/
	void NurbsSurface();

	/*�����ж�*/
	/*Nurbs�������*/
	void NurbsSurfaceTrim();

	/*�߼���������*/
	/*��Ĥ*/
	void StencilMask();
	/*�߼�����*/
	void StencilClip();







public:


public:
	/*�滭ѡ��*/
	void GLDraw(int select);

	

	
	/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()



};


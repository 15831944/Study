#pragma once
#include "afxwin.h"

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




class COpenGLBaseOperation :
	public CWnd
{
public:
	COpenGLBaseOperation();
	~COpenGLBaseOperation();


	

	/*����*/
public:
	/*���ô��ڳ�ʼ��С*/
	int m_WindowWidth , m_WindowHeight;

	/*��ʼλ��*/
	GLfloat m_fAngelX, m_fAngelY , m_fAngelZ;
	/*��ʼ�Ƕ�*/
	GLfloat m_fPositionX, m_fPositionY , m_fPositionZ;

	/*��ת����*/
	GLfloat m_fRevolveAngleStep;
	/*ƽ�Ʋ���*/
	GLfloat m_fTranslationStep;




	int m_nSelect;


  /*����*/
protected:

	int a, b, c;

	/*��Դ*/
	/*���û����⣬������⣬�۹�ָ������Դλ��*/
	GLfloat m_lightAmb[4],m_lightDif[4], m_lightSpe[4], m_lightPos[4];

	/*����*/
	GLfloat m_materialAmb[4], m_materialDif[4], m_materialSpe[4], m_materialPos[4], m_materialShininess[4];
	BOOL m_bMatrial;

	GLubyte image[64][64][3];

	CDib* m_pDib;
	
	/*Mip��ͼ*//*Mip�Զ���ͼ*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;


	

/*��������ʼ��*/
protected:
	/*��ʼ����Դ����*/
	void InitLightParameter();

	/*��ʼ�����ʲ���*/
	void InitMatrialParameter();

	/*������Դ*/
	void CreateLights();

	/*��������*/
	void CreateMaterial();

	/*��ʼ������*/
	void DrawScene();


	/*����*/
public:
	BOOL bSetupPixelFormat(CClientDC* m_pDC);

	/*��ʼ����view���ʼ�������б�����*/
	void GLInit(CClientDC* m_pDC);

	void GLDestroy(CClientDC* m_pDC);

	/*�ӿڱ任*/
	void GLSize(UINT nType , int cx , int cy , CRect m_oldRect);



	
/*����*/
protected:

	


	






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

	/*�滭����*/
	void GLDrawTest();

	void LButtonDown(UINT nFlags , CPoint point);


	/*ƽ�Ʊ任*/
	/*ǰ��front ,��back , ��left , �ң�right*/
	/*����direction��ǰ��0 , ��1 ,��2 ,�ң�3*/
	void PfmTranslate(int translation_direction);


	/*��ת�任*/
	/*γ�ȣ�latitude,���ȣ�longitude,˳ʱ�룺clockwise,��ʱ�룺anticlockwise*/
	/*�Ƕȷ���angel_direction��ˮƽ˳ʱ�룺0��ˮƽ��ʱ�룺1����ֱ˳ʱ�룺2����ֱ��ʱ�룺3*/
	void PfmRotate(int revolve_direction);

/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()


	
};


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





	/*����*/
public:















public:


public:
	/*�滭ѡ��*/
	void GLDraw(int select);




	/*���ɵ���Ϣӳ�亯��*/
public:
	DECLARE_MESSAGE_MAP()



};


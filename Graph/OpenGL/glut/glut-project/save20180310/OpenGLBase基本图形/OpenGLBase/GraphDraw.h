#pragma once
//#include "stdafx.h"







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
	int r;

	/*��ǰ���ڴ�С*/
	GLint m_iWindowWidth;
	GLint m_iWindowHeight;

	

	


	/*����*/
public:

	void	Point();	//����
	void	Line();		//����
	void	Triangle();	//����
	void	Square();	//��������
	void	Esquare();	//��������
	void	Park();		//��԰
	void	Pillar();	//԰��

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


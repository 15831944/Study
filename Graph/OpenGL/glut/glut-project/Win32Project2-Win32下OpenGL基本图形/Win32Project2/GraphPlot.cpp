#include"stdafx.h"
#include "GraphPlot.h"



CGraphPlot::CGraphPlot()
{
	r = 3;
}


CGraphPlot::~CGraphPlot()
{
}

///////////////////////////////////////////////////////////////
void CGraphPlot::Point()//����
{
	glBegin(GL_POINTS);// ��������
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphPlot::Line()//����
{
	glBegin(GL_LINE_LOOP); //�պ�����
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphPlot::Triangle()//����
{
	glBegin(GL_POLYGON);//���͹�����
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphPlot::Square()//��������
{
	glBegin(GL_POLYGON);//���͹�����
	glVertex3f(0.0f, 0.0f, 0.0f);//a��
	glVertex3f(1.0f, 0.0f, 0.0f);//b��
	glVertex3f(1.0f, 0.0f, -1.0f);//c��
	glVertex3f(0.0f, 0.0f, -1.0f);//d��
	glEnd();
}
void CGraphPlot::Esquare()//��������
{
	glBegin(GL_QUAD_STRIP);//���͹�����
	glVertex3f(0.0f, 0.0f, 0.0f);//a0��
	glVertex3f(0.0f, 1.0f, 0.0f);//a1��
	glVertex3f(1.0f, 0.0f, 0.0f);//b0��
	glVertex3f(1.0f, 1.0f, 0.0f);//b1��
	glVertex3f(1.0f, 0.0f, -1.0f);//c0��
	glVertex3f(1.0f, 1.0f, -1.0f);//c1��
	glVertex3f(0.0f, 0.0f, -1.0f);//d0��
	glVertex3f(0.0f, 1.0f, -1.0f);//d1��
	glVertex3f(0.0f, 0.0f, 0.0f);//a0��
	glVertex3f(0.0f, 1.0f, 0.0f);//a1��
	glEnd();
	//������������廹ȱ���������档Ӧ�ò��ϡ�
	glBegin(GL_POLYGON);//���͹�����
	glVertex3f(0.0f, 0.0f, 0.0f);//a0��
	glVertex3f(1.0f, 0.0f, 0.0f);//b0��
	glVertex3f(1.0f, 0.0f, -1.0f);//c0��
	glVertex3f(0.0f, 0.0f, -1.0f);//d0��
	glVertex3f(0.0f, 1.0f, 0.0f);//a1��
	glVertex3f(1.0f, 1.0f, 0.0f);//b1��
	glVertex3f(1.0f, 1.0f, -1.0f);//c1��
	glVertex3f(0.0f, 1.0f, -1.0f);//d1��
	glEnd();
}
void CGraphPlot::Park()//��԰
{
	glBegin(GL_TRIANGLE_FAN);//����������������δ�
	glVertex3f(0, 0, 0.0f);
	for (int i = 0;i <= 390;i += 30)
	{
		float p = (float)(i*3.14 / 180);
		glVertex3f((float)sin(p), (float)cos(p), 0.0f);// ԰�켣
	}
	glEnd();
}
void CGraphPlot::Pillar() //԰��
{
	glBegin(GL_QUAD_STRIP);// ��������ı��δ�
	for (int i = 0;i <= 390;i += 30)
	{
		float p = (float)(i*3.14 / 180);
		glVertex3f((float)sin(p) / 2, (float)cos(p) / 2, 1.0f);// ǰ԰ 
		glVertex3f((float)sin(p) / 2, (float)cos(p) / 2, 0.0f);// ��԰ 
	}
	glEnd();
}
void CGraphPlot::Draw()
{
	
}
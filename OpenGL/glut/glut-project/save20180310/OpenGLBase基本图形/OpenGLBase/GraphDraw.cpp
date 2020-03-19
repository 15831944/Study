#include "stdafx.h"
#include "GraphDraw.h"





CGraphDraw::CGraphDraw()
{
	a = b = 5;
	c = 1;


	m_nSelect = 0;

	r = 0;

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
	

	r += 10;if (r>360) r = 0;

	glPushMatrix();
	glPointSize(4);										//��Ĵ�С
	glTranslatef(-5, 4, -13);glRotatef(r, 1.0, 1.0, 1.0);	//������ת
	glColor3f(1.0f, 0.0f, 0.0f);Point();		//����
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 4, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(0.0f, 1.0f, 0.0f);Line();		//����
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5, 4, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(0.0f, 0.0f, 1.0f);Triangle();	//����
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5, 0, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(1.0f, 1.0f, 0.0f);Square();		//��������
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(0.0f, 1.0f, 1.0f);Esquare();		//��������
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5, 0, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(1.0f, 0.0f, 1.0f);Park();		//��԰
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5, -4, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(1.0f, 1.0f, 1.0f);Pillar();		//԰��
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -4, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(0.7f, 0.7f, 0.7f);glutSolidCone(1.0f, 2.0f, 10, 10);  	//����������ʵ��԰׶
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5, -4, -13);glRotatef(r, 1.0, 1.0, 1.0); //������ת
	glColor3f(0.4f, 0.4f, 0.4f);auxWireTeapot(1);	//�����������߲��
	glPopMatrix();



}






void CGraphDraw::Point()//����
{
	glBegin(GL_POINTS);// ��������
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphDraw::Line()//����
{
	glBegin(GL_LINE_LOOP); //�պ�����
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphDraw::Triangle()//����
{
	glBegin(GL_POLYGON);//���͹�����
	glVertex3f(0.0f, 1.0f, -1.0f);//a��
	glVertex3f(-1.0f, -1.0f, 0.0f);//b��
	glVertex3f(1.0f, -1.0f, 0.0f);//c��
	glEnd();
}
void CGraphDraw::Square()//��������
{
	glBegin(GL_POLYGON);//���͹�����
	glVertex3f(0.0f, 0.0f, 0.0f);//a��
	glVertex3f(1.0f, 0.0f, 0.0f);//b��
	glVertex3f(1.0f, 0.0f, -1.0f);//c��
	glVertex3f(0.0f, 0.0f, -1.0f);//d��
	glEnd();
}
void CGraphDraw::Esquare()//��������
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
void CGraphDraw::Park()//��԰
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
void CGraphDraw::Pillar() //԰��
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
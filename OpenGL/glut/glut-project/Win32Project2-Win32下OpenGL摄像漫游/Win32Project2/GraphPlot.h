#pragma once


/*ͼ�λ�����*/
class CGraphPlot
{
public:
	CGraphPlot();
	virtual~CGraphPlot();


public:
	double r;

public:
	//*
public:
	int			m_Time, m_Fram;
	////�����////////////////////////////////////////////////////////////////////
private:GLdouble	g_eye[3];		//
		GLdouble	g_look[3];		//
		float		rad_xz;			//�Ƕ�
		float		g_Angle;		//����ת
		float		g_elev;			//������
		UINT g_cactus[16];	//��ͼ
		GLUquadricObj *g_text;
public:
	GLvoid		DrawGround();	//��ɫ���������
	BOOL		DisplayScene();	//�����
	void		light0();
	void		picter(float x, float y, float z);//���ͼ��
	void		Box(float x, float y, float z);
	void		airplane(float x, float y, float z);//��Ϸɻ�
	bool LoadT8(char *filename, GLuint &texture);//��8λ��ͼ
	//*/

public:
public:
public:
public:
public:


};


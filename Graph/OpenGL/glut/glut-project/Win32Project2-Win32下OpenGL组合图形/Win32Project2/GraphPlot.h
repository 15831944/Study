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
	UINT g_cactus[16];	//��ͼ
	GLUquadricObj *g_text;
	void Box(float x, float y, float z);
	void picter(float x, float y, float z);//���ͼ��
	void airplane(float x, float y, float z);//��Ϸɻ�
	void light0(float x, float y, float z, float a);//��
	bool LoadT8(char *filename, GLuint &texture);//��8λ��ͼ
	//*/

public:
public:
public:
public:
public:


};


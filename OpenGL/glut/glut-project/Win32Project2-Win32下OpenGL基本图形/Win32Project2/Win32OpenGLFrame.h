#pragma once
#include"stdafx.h"

#include"GraphPlot.h"






HGLRC   hRC = NULL;       // ������ɫ��������  
HDC hDC = NULL;           // OpenGL��Ⱦ��������  
HWND    hWnd = NULL;  // �������ǵĴ��ھ��  
HINSTANCE   hInstance;  // ��������ʵ��  
bool    keys[256];          // ������̰���������  
bool    active = TRUE;        // ���ڵĻ��־��ȱʡΪTRUE  
bool    fullscreen = TRUE;        // ȫ����־ȱʡ��ȱʡ�趨��ȫ��ģʽ 

								  


				 //����ȫ�ֺ���  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   // WndProc��Ϣѭ�������Ķ���  
BOOL CreateGLWindow(int width, int height, int bits, bool fullscreenflag);  //�������ں�������  
GLvoid ReSizeGLScene(GLsizei width, GLsizei height);    // ����OpenGL���ڴ�С��������  
int InitGL(GLvoid);     // ��OpenGL���г�ʼ������  
int DrawGLScene(GLvoid);    //��ͼ����  
							/**********************************************************
							*GLvoid KillGLWindow(GLvoid)
							*���ܣ����ٴ���
							*��������
							*����ֵ����
							************************************************************/
GLvoid KillGLWindow(GLvoid);        // �������ٴ��ں���  



////////////////////////////////////////////////////////////////////////////////////////
				
float	r;       //�����Ƕ�

CGraphPlot m_gp;//��ͼ������
void play();
				





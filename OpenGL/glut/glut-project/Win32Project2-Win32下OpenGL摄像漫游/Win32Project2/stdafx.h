// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once


//#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 

//#include <afxwin.h>

#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include <mmsystem.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//OpenGLͷ�ļ�


#include <gl/glew.h>      // �������µ�gl.h,glu.h��  
#include <gl/glut.h>      // ����OpenGLʵ�ÿ�


#include <gl\gl.h>		// OpenGL32���ͷ�ļ�
#include <gl\glu.h>		// GLu32���ͷ�ļ�
#include <gl\glaux.h>	// GLaux���ͷ�ļ�

  

//OpenGL���ӿ�

#pragma comment( lib, "winmm.lib")
#pragma comment( lib, "opengl32.lib")	// OpenGL32���ӿ�
#pragma comment( lib, "glu32.lib")		// GLu32���ӿ�
#pragma comment( lib, "glaux.lib")		// GLaux���ӿ�

#define FRAND   (((float)rand()-(float)rand())/RAND_MAX)
//#define MAP_W       16.0f       // size of map along x-axis 32 
//#define MAP_SCALE   16.0f     // the scale of the terrain map24
#define MAP		40//	MAP_W*MAP_SCALE/2
#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

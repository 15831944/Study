
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif






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





#define ABS(x) ((x)<0?-(x):(x)>0?(x):0)
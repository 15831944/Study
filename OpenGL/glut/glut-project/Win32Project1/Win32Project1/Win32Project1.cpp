// Win32Project1.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Project1.h"
#include<time.h>

/*����װ���ַ�������󳤶�*/
#define MAX_LOADSTRING 100
#define WM_TIMER_CLOCK WM_USER+20
/*����ʱ��ˢ��ʱ����*/
#define WM_CLOCK_INTERVAL 1000

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��/*����ʵ�����*/
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

/*��ǰʱ��*/
struct tm* newdate;
/*ʱ������*/
time_t  long_date;
/*��ʱ���ı�*/
//TCHAR szTimerTitle[MAX_LOADSTRING];
char szTimerTitle[MAX_LOADSTRING];


// �˴���ģ���а����ĺ�����ǰ������: 
/*ע�ᴰ����*/
ATOM                MyRegisterClass(HINSTANCE hInstance);
/*��ʼ��ʵ��*/
BOOL                InitInstance(HINSTANCE, int);
/*���ڴ�����*/
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
/*���ں���*/
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

/*������*/
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �ڴ˷��ô��롣


    // ��ʼ��ȫ���ַ���
	/*װ��Ӧ�ó������*/
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	/*ע��Ӧ�ó�����*/
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��:
	/*���Ӧ�ó����ʼ��*/
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

	/*������ټ�����*//*װ�ؼ��ټ�*/
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	/*������Ϣ*/
    MSG msg;

    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
		/*ת����ݼ���Ϣ*/
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
			/*ת����Ϣ*/
            TranslateMessage(&msg);
			/*������Ϣ*/
            DispatchMessage(&msg);
        }
    }

	/*������Ϣ�Ĳ���*/
    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	/*����ע�ᴰ����Ľṹ����*/
    WNDCLASSEXW wcex;

	/*Ϊ�ṹ��С��Ա��ֵ*/
    wcex.cbSize = sizeof(WNDCLASSEX);

	/*��ֵ���ڵ���ʽ��Ա*/
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
	/*��ֵ���ڵĴ�����*/
    wcex.lpfnWndProc    = WndProc;
	/*��ֵ����������ݳ���*/
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
	/*��ֵ�������ʵ�����*/
    wcex.hInstance      = hInstance;
	/*ͼ��*/
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	/*���*/
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	/*������ɫ*/
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	/*�˵�*/
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT1);
	/*��������*/
    wcex.lpszClassName  = szWindowClass;
	/*Сͼ��*/
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	/*ע�ᴰ����*/
    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   /*����ʧ�ܣ��򷵻�*/
   if (!hWnd)
   {
      return FALSE;
   }

   /*��ʾ����*/
   ShowWindow(hWnd, nCmdShow);
   /*���´���*/
   UpdateWindow(hWnd);

   /*������ʱ��*/
   SetTimer(hWnd, WM_TIMER_CLOCK, WM_CLOCK_INTERVAL, NULL);
   /*����*/

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	/*������Ϣ����ִ����Ӧ�Ĳ���*/
    switch (message)
    {

	/*�����WM_COMMAND���͵�*/
    case WM_COMMAND:
        {
			/*��ȡ������Ϣ���������ID*/
            int wmId = LOWORD(wParam);
			/*��ȡ�����¼�*/
			int wmEvent = HIWORD(wParam);
            // �����˵�ѡ��: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
			/*��ʼ�ػ�*/
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...

			
			/*�����������*/
			RECT rt;
			/*��ȡ�ͻ�����Χ*/
			GetClientRect(hWnd, &rt);
			/*���ƻ�ӭ�ı�*/
			//DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			
			/*�����ػ�*/
            EndPaint(hWnd, &ps);
        }
        break;
	/*���ٴ���*/
    case WM_DESTROY:
		/*�����˳���Ϣ*/
        PostQuitMessage(0);
        break;
	/*���붨ʱ��������*/
	case WM_TIMER:
		/*���붨ʱ������Ϊ��ʾʱ�䶨ʱ��*/
		if (wParam == WM_TIMER_CLOCK)
		{
			//����tm�ṹ��ʱ�����
			struct tm newdate;

			//����time_t�ṹ��ʱ�����
			time_t long_date;
			//��ȡʱ��
			time(&long_date);

			//��ʱ��ת��Ϊ����ʱ��
			localtime_s(&newdate, &long_date);

			memset(szTimerTitle, 0, sizeof(szTimerTitle));

			//strcpy_s(szTimerTitle, asctime(newdate));

			//char stTmp[100];
			asctime_s(szTimerTitle, &newdate);

			/*��ӡ��ǰʱ��*/
			UpdateWindow(hWnd);
			/*��ʾ��ǰ����*/
		}
		break;
		/*Ĭ���������������Ϣ*/
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

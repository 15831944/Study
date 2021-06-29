
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*���Ա༭���������*/
	//DDX_Control(pDX, IDC_EDIT_TEST_SCROLL, m_editTestScroll);
	//DDX_Control(pDX, IDC_STATIC_LOG, m_staticLog);
	/*��־��̬���������*/

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEST, m_EditTest);
	DDX_Control(pDX, IDC_STATIC_LOG, m_staticLog);
}

/*ӳ���ʼ*/
BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	/*�༭�����ݸı���Ϣ*/
	ON_EN_CHANGE(IDC_EDIT_TEST, OnChangeEditText)
	/*�༭�����ݲ�����Ϣ*/
	ON_EN_ERRSPACE(IDC_EDIT_TEST,OnErrspaceEditText)
	/*�༭��ʧȥ������Ϣ*/
	ON_EN_KILLFOCUS(IDC_EDIT_TEST,OnKillfocusEditText)
	/*�༭�����ݴﵽ���ֵ��Ϣ*/
	ON_EN_MAXTEXT(IDC_EDIT_TEST,OnMaxtextEditText)
	/*�༭�����ý�����Ϣ*/
	ON_EN_SETFOCUS(IDC_EDIT_TEST,OnSetfocusEditText)
	/*�༭�����ݸ�����Ϣ*/
	ON_EN_UPDATE(IDC_EDIT_TEST,OnUpdateEditText)
	/*ˮƽ������Ϣ*/
	ON_EN_HSCROLL(IDC_SCROLLBAR_V,OnHscrollEditTestScroll)
	/*��ֱ������Ϣ*/
	ON_EN_VSCROLL(IDC_SCROLLBAR_H,OnVscrollEditTestScroll)
	/*��ȡ�ı���Ϣ*/
	ON_BN_CLICKED(IDC_BUTTON_GETTEXT,OnButtonGetEditText)
	/*�����ı���Ϣ*/
	ON_BN_CLICKED(IDC_BUTTON_SETTEXT,OnButtonSetEditText)
	/*��ȡ��*/
	ON_BN_CLICKED(IDC_BUTTON_GETLINE, OnButtonGetLine)
	/*����ѡ�������*/
	ON_BN_CLICKED(IDC_BUTTON_GETSEL, OnButtonGetSel)
	/*��ȡѡ��Ե�����*/
	ON_BN_CLICKED(IDC_BUTTON_SETSEL, OnButtonSetSel)
	/*�ı��滻*/
	ON_BN_CLICKED(IDC_BUTTON_REPLACESEL, OnButtonReplaceSel)
	/*��Ϣ��ʾ*/
	ON_BN_CLICKED(IDC_STATIC_TEXT,OnStaticText)
	/*��Ϣӳ������*/

END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//���öԻ����ʼ��С
	//����ԭ�ͣ�
		//BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags);
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 200, 200,600, 430, SWP_NOZORDER);


	//���öԻ���̶���С�����ܸı䡣
	DWORD dwStyle;
	dwStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);
	dwStyle &= ~ WS_THICKFRAME;
	dwStyle &= ~ WS_MAXIMIZEBOX;
	::SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		//CDialogEx::OnPaint();

		//���Ի�����ӱ���ͼƬ
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);
		//˫������ͼ
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP_DLGBACKGROUND);
		//IDB_BITMAP1�����Լ���ͼ��Ӧ��ID   
		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		//ǿ�Ƹı�ͼƬ��Сʹ֮��Ӧ�Ի����С
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
			bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::WriteLog(CString message, CString title)
{
	m_staticLog.SetWindowTextW(title + _T("--") + message);
}



/*�ı����ݸı���Ϣ������*/
void CMFCApplication1Dlg::OnChangeEditText()
{
	WriteLog(_T("���յ�ON_EN_CHANGE��Ϣ"), _T("��ߵı༭�ؼ�"));
	
}
/*�ı����ݲ�����Ϣ������*/
void CMFCApplication1Dlg::OnErrspaceEditText()
{
	WriteLog(_T("���յ�ON_EN_ERRSPACE��Ϣ"), _T("��ߵı༭�ؼ�"));

}
/*ʧȥ���㴦����*/
void CMFCApplication1Dlg::OnKillfocusEditText()
{
	WriteLog(_T("���յ�ON_EN_KILLFOCUS��Ϣ"), _T("��ߵı༭�ؼ�"));

}
/*�ﵽ����ı�����Ϣ������*/
void CMFCApplication1Dlg::OnMaxtextEditText()
{
	WriteLog(_T("���յ�ON_EN_MAXTEXT��Ϣ"), _T("��ߵı༭�ؼ�"));

}
/*�༭�����ý�����Ϣ*/
void CMFCApplication1Dlg::OnSetfocusEditText()
{
	WriteLog(_T("���յ�ON_EN_SETFOCUS��Ϣ"), _T("��ߵı༭�ؼ�"));

}
/*�༭�����ݸ�����Ϣ*/
void CMFCApplication1Dlg::OnUpdateEditText()
{
	WriteLog(_T("���յ�ON_EN_UPDATE��Ϣ"), _T("��ߵı༭�ؼ�"));

}
/*ˮƽ������Ϣ*/
void CMFCApplication1Dlg::OnHscrollEditTestScroll()
{
	WriteLog(_T("���յ�ON_EN_HSCROLL��Ϣ"), _T("�ұߵı༭�ؼ�"));

}
/*��ֱ������Ϣ*/
void CMFCApplication1Dlg::OnVscrollEditTestScroll()
{
	WriteLog(_T("���յ�ON_EN_VSCROLL��Ϣ"), _T("�ұߵı༭�ؼ�"));

}
/*��ȡ�ı���Ϣ*/
void CMFCApplication1Dlg::OnButtonGetEditText()
{
	CString content;
	m_EditTest.GetWindowTextW(content);
	MessageBox(content, _T("��ȡ��߱༭�������"));
}

/*�����ı���Ϣ*/
void CMFCApplication1Dlg::OnButtonSetEditText()
{
	m_EditTest.SetWindowTextW(_T("���ã����ǲ���"));
}
/*��ȡ��*/
void CMFCApplication1Dlg::OnButtonGetLine()
{
	TCHAR content[256];
	memset(content, 0X00, sizeof(content));
	int iCount = m_EditTest.GetLine(1, content, sizeof(content));
	if (iCount > 0)MessageBox(content, _T("GETLINE��ȡ�ڶ��е�����"));
	else MessageBox(_T("ʧ��"), _T("GETLINE��ȡ�ڶ��е�����"));
}

/*��ȡѡ��Ե�����*/
void CMFCApplication1Dlg::OnButtonGetSel()
{
	int iStart = 0, iEnd = 0;
	m_EditTest.GetSel(iStart, iEnd);
	CString log;
	log.Format(_T("ѡ������ݴӵ�%d���ַ�����%d���ַ�"), iStart, iEnd);
	MessageBox(log, _T("GetSel"));
}
//*����ѡ�������*/
void CMFCApplication1Dlg::OnButtonSetSel()
{
	m_EditTest.SetSel(5, 10, TRUE);
	MessageBox(_T("ѡ������ݴӵ�6���ַ�����11���ַ�"), _T("SetSel"));
}
/*�ı��滻*/
void CMFCApplication1Dlg::OnButtonReplaceSel()
{
	m_EditTest.ReplaceSel(_T("�˴������µ�����"));
}

void CMFCApplication1Dlg::OnStaticText()
{
	MessageBox(_T("���ʹ��SS_NOTIFY������̬�ؼ���\n����Խ��յ����¼���\n�˴��������ӡ�"), _T("��̬�ؼ�"));
}

/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/




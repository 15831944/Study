
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

	DDX_Control(pDX, IDC_EDIT1, m_TextShow);
	DDX_Control(pDX, IDC_EDIT_PATH, m_EditPath);
	DDX_Control(pDX, IDC_EDIT_JUMP, m_EditJump);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(ID_AO, &CMFCApplication1Dlg::OnBnClickedAo)
	ON_WM_KEYDOWN()
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
	a = 0;
	i_pos = flength = 0;

	
	

	
	
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCApplication1Dlg::OnBnClickedAo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString path;
	CString a, b;
	a = b = "";
	path = "E:\\GOChessBlack.tga";
	if (m_tgawr.LoadTGA(&texture[0], path))
	{
		//a.Format(_T("%d"), m_tgawr.tgaheader.Header[2]);
		//a = "��ȡ�ɹ���";
		//MessageBox(a);
	}
	//else
	{
		//a = "��ȡʧ�ܣ�";
		//MessageBox(a);
	}

	for (int i = 0;i < 6;i++)
	{
		//b.Format(_T("%d"), m_tgawr.tga.header[i]);
		b.Format(_T("%d"), m_tgawr.tga.Bpp);
		//b.Format(_T("%d"), m_tgawr.tgaheader.Header[i]);
		a += b;
		a += " ";
	}
	//a.Format(_T("%d"), m_tgawr.tga.header[3]);
	//GLubyte rt[7] = { 1,2,3,4,5,6,7 };
	//int ei = *rt;
	//a.Format(_T("%d"), *(rt+2));
	MessageBox(a);

	//Readbinary();
	
}


void CMFCApplication1Dlg::Readbinary()
{
	CString tex, temp, path, str_jumppos;
	int max;
	unsigned long uli_jmp;
	tex = " ";
	temp = " ";

	uli_jmp = 0;


	CFile cfile;
	m_EditPath.GetWindowTextW(path);
	m_EditJump.GetWindowTextW(str_jumppos);

	path.Replace(_T("\\"), _T("\\\\"));
	//m_EditPath.SetWindowTextW(path);

	cfile.Open(path, CFile::modeRead | CFile::typeBinary, NULL);

	

	max = 1000;
	short Buf[1000] = { 0 };

	uli_jmp = _ttoi(str_jumppos);

	uli_jmp = (unsigned long)uli_jmp;
	//temp.Format(_T("%uld"), uli_jmp);
	//MessageBox(temp);
	///*
	flength = cfile.GetLength();
	//����
	int remainder = 0;
	if (uli_jmp <= flength)
	{
		i_pos = uli_jmp;
	}
	else
	{
		i_pos = flength - 1000;
		str_jumppos.Format(_T("%uld"), flength);
		m_EditJump.SetWindowTextW(str_jumppos);
	}
	if (i_pos < flength)
	{
		//����
		remainder = flength - i_pos;
		if (remainder >= max)
			for (int j = 0; j < max;j++)
			{
				cfile.Seek(i_pos, CFile::begin);
				cfile.Read((Buf + j), 1);
				i_pos++;

			}
		else

		{
			for (int j = 0; j < remainder;j++)
			{
				cfile.Seek(i_pos, CFile::begin);
				cfile.Read((Buf + j), 1);
				i_pos++;
			}
		}


		for (int j = 0;j < max;j++)
		{
			temp.Format(_T("%d"), (int)Buf[j]);
			if (j == 0) tex = temp;
			else tex += temp;
			tex += " ";

			if (j > 0 && (j % 30) == 0)
			{
				tex += _T("\r\n");
			}
			Buf[j] = 0;
		}

		cfile.Close();
		m_TextShow.SetWindowTextW(tex);
		//EditAddtoText(tex);
		Invalidate();
		//cfile.Seek((flength - 2), CFile::begin);
		//cfile.SeekToEnd();
		//cfile.Read((Buf), 1);
		//temp.Format(_T("%d"), Buf[0]);
		//MessageBox(temp);
		//temp.Format(_T("%uld"), flength);


	}
}

void CMFCApplication1Dlg::EditAddtoText(CString add)
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	int nLength = pEdit->GetWindowTextLength();

	//ѡ����ǰ�ı���ĩ��  
	pEdit->SetSel(nLength, nLength);
	//l׷���ı�  
	pEdit->ReplaceSel(add);
}

void CMFCApplication1Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nChar==VK_UP) MessageBox(_T("keyup"));
	if (nChar == VK_LEFT) MessageBox(_T("keyuleft"));
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

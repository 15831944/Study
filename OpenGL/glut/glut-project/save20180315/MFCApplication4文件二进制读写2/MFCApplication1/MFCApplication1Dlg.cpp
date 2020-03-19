
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

	DDX_Control(pDX, IDC_EDIT1, m_EditShow);
	DDX_Control(pDX, IDC_EDIT_PATH, m_EditPath);
	DDX_Control(pDX, IDC_EDIT_JUMP, m_EditJump);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(ID_BUTTON_READJUMP, &CMFCApplication1Dlg::OnBnClickedReadJump)
	ON_BN_CLICKED(ID_BUTTON_WRITE, &CMFCApplication1Dlg::OnBnClickedWrite)
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





void CMFCApplication1Dlg::OnBnClickedReadJump()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tex, temp,path,str_jumppos;
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

	uli_jmp=_ttoi(str_jumppos);

	uli_jmp = (unsigned long)uli_jmp ;
	//temp.Format(_T("%uld"), uli_jmp);
	//MessageBox(temp);
	///*
	flength = cfile.GetLength();
	//����
	int remainder=0;
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


		m_EditShow.SetWindowTextW(tex);
		//EditAddtoText(tex);
		Invalidate();
		//cfile.Seek((flength - 2), CFile::begin);
		//cfile.SeekToEnd();
		//cfile.Read((Buf), 1);
		//temp.Format(_T("%d"), Buf[0]);
		//MessageBox(temp);
		//temp.Format(_T("%uld"), flength);


	}
	cfile.Close();
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

void CMFCApplication1Dlg::OnBnClickedWrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString textwrite, temp, path;
	
	int max;
	
	//textwrite = " ";
	//temp = " ";

	CFile cfile;
	m_EditPath.GetWindowTextW(path);
	m_EditShow.GetWindowTextW(textwrite);

	path.Replace(_T("\\"), _T("\\\\"));
	//m_EditPath.SetWindowTextW(path);



	/*
	CString strData = _T("123456ab?!@c");
	char cData[1024];
	char *pBuff = (char*)strData.GetBuffer(strData.GetLength());
	char one = pBuff[0];
	char two = pBuff[1];
	int i = 0;
	for (; i < strData.GetLength(); i++)
	{
		cData[i] = pBuff[i * 2];
	}
	cData[i] = '\0';
	*/


	short WriteBuf[1000] = { 0 };
	TransformStringToInt(WriteBuf, textwrite);

	cfile.Open(path, CFile::modeWrite | CFile::typeBinary, NULL);
	max = 1000;
	
	
	
	//cfile.SeekToEnd();
	for (int j = 0; j < 2;j++)
	{
		//cfile.Seek(i_pos, CFile::begin);
		cfile.SeekToEnd();
		cfile.Write((WriteBuf + j), 1);
		//cfile.Write((Buf + j), 1);

	}
	
	cfile.Close();
}


void CMFCApplication1Dlg::TransformStringToInt(short* buf, CString strData)
{
	//CString strData = _T("123456ab?!@c");



	char cData[1000];
	char *pBuff = (char*)strData.GetBuffer(strData.GetLength());
	char one = pBuff[0];
	char two = pBuff[1];
	int i = 0;
	for (; i < strData.GetLength(); i++)
	{
		cData[i] = pBuff[i * 2];
	}
	cData[i] = '\0';


	int l, r;
	l = r = 0;
	int j = 0;
	//if(i>0)j=i-1;
	while(j<i)
	{
		*buf = 0;
		
		//��λ
		int numbit = 0;
		int db = 0;
		
		while (j <i && cData[j] != ' ')
		{
			j++;
		}
		r = j;
		numbit = r - l-1;
		for(;l<r;l++)
		{
			switch (cData[l])
			{
			case'0':db = 0;break;
			case'1':db = 1;break;
			case'2':db = 2;break;
			case'3':db = 3;break;
			case'4':db = 4;break;
			case'5':db = 5;break;
			case'6':db = 6;break;
			case'7':db = 7;break;
			case'8':db = 8;break;
			case'9':db = 9;break;
			default:break;
			}
			int a = 1;
			for (int i = 0;i < numbit;i++)a *= 10;
			*buf += a*db;
			numbit--;
		}
		l = r + 1;
		j++;
		buf++;
	}
}
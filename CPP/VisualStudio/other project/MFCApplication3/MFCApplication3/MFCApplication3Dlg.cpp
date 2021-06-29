
// MFCApplication3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"




//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE
//#pragma warning(disable:4996)

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
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg �Ի���



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditOutPut);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	DDX_Control(pDX, IDC_EDIT2, m_EditLableName);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCApplication3Dlg ��Ϣ�������

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	bool pass=CMFCApplication3Dlg::login();
	if (pass == false)
	{
		this->OnCancel();
		return false;
	}
	

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
	



	/*ListCtrl�ؼ���ʹ��*/

	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_listCtrl2.SetBkColor(RGB(0, 0, 0))
	m_ListCtrl.SetTextBkColor(RGB(255, 255, 255)); //�����ı�������ɫ
	m_ListCtrl.SetTextColor(RGB(255, 0, 0)); //�����ı���ɫ
	m_ListCtrl.DeleteAllItems();//���





	sprintf_s(sql.querry, "SELECT user_id,user_name,user_second_sum FROM user_infoo");
	//��ʾ�ղŲ��������  

	m_EditLableName.SetWindowTextW(_T("                                         user_infoo"));

	MYSQL_RES *result = NULL;
	if (0 == mysql_query(&sql.mydata, sql.querry))
	{
		sql.c += "mysql_query() select data succeed";
		sql.c += "\r\n";
		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&sql.mydata);
		//ȡ�ò���ӡ����  
		int rowcount = (int)mysql_num_rows(result);

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;

		sql.c += "row count:";
		CString a;
		a.Format(_T("%d"), rowcount);
		sql.c += a;
		sql.c += "\r\n";


		/*�ֶε���������*/
		for (unsigned int i = 0; i < fieldcount; i++)
		{
			field = mysql_fetch_field_direct(result, i);
			sql.c += field->name;
			sql.c += "\r\t";

			CString n;
			n = field->name;
			m_ListCtrl.InsertColumn(i, n, LVCFMT_CENTER, 100);



			//cout << field->name << "\t\t";
		}
		//cout << endl;



		/*������*/
		for (int i = 0;i < rowcount;i++)
		{
			CString item;
			item.Format(_T("%d"), i + 1);
			m_ListBox.AddString(item);
			m_ListCtrl.InsertItem(i, item);
		}




		//��ӡ����  
		/*��ȡ��ʾ����*/
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		sql.c += "\r\n";
		int i = 0;
		while (NULL != row)
		{
			sql.c += "\r\n";
			for (int j = 0; j < fieldcount; j++)
			{
				//cout << row[i] << "\t\t";
				sql.c += row[j];
				sql.c += "            ";
				CString r;
				r = row[j];
				m_ListCtrl.SetItemText(i, j, r);

			}
			i++;
			row = mysql_fetch_row(result);
		}
		
	}
	else
	{
		sql.c += "mysql_query() select data failed";
		sql.c += "\r\n";
		

		mysql_close(&sql.mydata);
		return -1;
	}



	//ɾ���ղŽ��ı�  
	sprintf_s(sql.querry, "DROP TABLE user_info");
	/*
	if (0 == mysql_query(&mydata, querry))
	{
	//cout << "mysql_query() drop table succeed" << endl;
	m_EditOutPut.SetWindowTextW(_T("mysql_query() drop table succeed"));
	}
	else
	{
	//cout << "mysql_query() drop table failed" << endl;
	m_EditOutPut.SetWindowTextW(_T("mysql_query() drop table failed"));
	mysql_close(&mydata);
	return -1;
	}
	*/
	mysql_free_result(result);
	mysql_close(&sql.mydata);
	mysql_server_end();


	/*�����Ϣ*/
	m_EditOutPut.SetWindowTextW(sql.c);





	/*ListBox�ؼ���ʹ��*/
	
	



	


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication3Dlg::OnPaint()
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
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



bool CMFCApplication3Dlg::login()
{
LG0:
	lg.m_EditUser = "";
	lg.m_EditPassWord = "";


LG1:
	lg.m_EditPassWord = "";


    UpdateData(FALSE);



	INT_PTR nResponse = lg.DoModal();

	

	if (nResponse == IDOK)
	{
		

		CString user,password;
		
		password =sql.login(lg.m_EditUser);
		if(lg.m_EditUser == "" )
		{
			AfxMessageBox(_T("�˺Ų���Ϊ��!"),MB_ICONEXCLAMATION);
			 goto LG0;
		}
		else if (lg.m_EditPassWord == "")
		{
			AfxMessageBox(_T("���벻��Ϊ��!"), MB_ICONEXCLAMATION);
			goto LG1;
		}
		else if (password == "$")
		{
			AfxMessageBox(_T("��������˺���������������!"));
			goto LG0;
		}
		else if(lg.m_EditPassWord==password)
		{
			
			return true;
		}
		else
		{
			AfxMessageBox(_T("�������������������������!"));
			
			goto LG1;
		}
		

	}
    else if (nResponse == IDCANCEL)
	{
		int nFlag = MessageBox( _T("��ȷ��Ҫ�˳���"), _T("��ܰ��ʾ"), MB_YESNO | MB_ICONQUESTION);
		if (nFlag == 7)
		{
			goto LG0;
		}
		else return false;
		
	}
}
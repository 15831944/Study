
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
	DDX_Control(pDX , IDC_TREE1 , m_tcTestTree);
	DDX_Control(pDX , IDC_LIST1 , m_lcTestList);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_NOTIFY(TVN_SELCHANGED , IDC_TREE1 , &CMFCApplication1Dlg::OnTvnSelchangedTree1)

	ON_NOTIFY(TVN_GETINFOTIP , IDC_TREE1 , &CMFCApplication1Dlg::OnTvnGetInfoTipTree1)
	ON_NOTIFY(NM_CLICK , IDC_LIST1 , &CMFCApplication1Dlg::OnNMClickList1)
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


	InitTreeCtrl();
	InitListCtrl();


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




void CMFCApplication1Dlg::InitTreeCtrl()
{
	HICON hIcon[3];      // ͼ��������   
	HTREEITEM hRoot;     // ���ĸ��ڵ�ľ��   
	HTREEITEM hCataItem; // �ɱ�ʾ��һ����ڵ�ľ��   
	HTREEITEM hArtItem;  // �ɱ�ʾ��һ���½ڵ�ľ��   

						 // ��������ͼ�꣬�������ǵľ�����浽����   
	hIcon[0] = theApp.LoadIcon(IDI_ICON1);
	hIcon[1] = theApp.LoadIcon(IDI_ICON2);
	hIcon[2] = theApp.LoadIcon(IDI_ICON3);

	// ����ͼ������CImageList����   
	m_imageList.Create(32 , 32 , ILC_COLOR32 , 3 , 3);
	// ������ͼ����ӵ�ͼ������   
	for (int i = 0; i<3; i++)
	{
		m_imageList.Add(hIcon[i]);
	}

	// Ϊ���οؼ�����ͼ������   
	m_tcTestTree.SetImageList(&m_imageList , TVSIL_NORMAL);

	// ������ڵ�   
	hRoot = m_tcTestTree.InsertItem(_T("������") , 0 , 0);
	// �ڸ��ڵ��²����ӽڵ�   
	hCataItem = m_tcTestTree.InsertItem(_T("IT������") , 1 , 1 , hRoot , TVI_LAST);
	// Ϊ��IT���������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hCataItem , 1);
	// �ڡ�IT���������ڵ��²����ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("�ٶ�����1") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ���ٶ�����1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 2);
	// �ڡ�IT���������ڵ��²�����һ�ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("�ȸ�����2") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ���ȸ�����2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 3);
	// �ڸ��ڵ��²���ڶ����ӽڵ�   
	hCataItem = m_tcTestTree.InsertItem(_T("��������") , 1 , 1 , hRoot , TVI_LAST);
	// Ϊ����������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hCataItem , 4);
	// �ڡ���������ڵ��²����ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("�����ֻ�����1") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ�������ֻ�����1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 5);
	// �ڡ���������ڵ��²�����һ�ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("ƽ���������2") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ��ƽ���������2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 6);
	// �ڸ��ڵ��²���������ӽڵ�   
	hCataItem = m_tcTestTree.InsertItem(_T("�������") , 1 , 1 , hRoot , TVI_LAST);
	// Ϊ������������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hCataItem , 7);
	// �ڡ�����������ڵ��²����ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("C++�������ϵ��1") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ��C++�������ϵ��1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 8);
	// �ڡ�����������ڵ��²�����һ�ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("VS2010/MFC�������2") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ��VS2010/MFC�������2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 9);
	// �ڸ��ڵ��²�����ĸ��ӽڵ�   
	hCataItem = m_tcTestTree.InsertItem(_T("��������") , 1 , 1 , hRoot , TVI_LAST);
	// Ϊ���������С��ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hCataItem , 10);
	// �ڡ��������С��ڵ��²����ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("������������1") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ��������������1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 11);
	// �ڡ��������С��ڵ��²�����һ�ӽڵ�   
	hArtItem = m_tcTestTree.InsertItem(_T("ITЦ��2") , 2 , 2 , hCataItem , TVI_LAST);
	// Ϊ��ITЦ��2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
	m_tcTestTree.SetItemData(hArtItem , 12);
}



void CMFCApplication1Dlg::OnTvnSelchangedTree1(NMHDR *pNMHDR , LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strText; // ���ڵ�ı�ǩ�ı��ַ���   

					 // ��ȡ��ǰѡ�нڵ�ľ��   
	HTREEITEM hItem = m_tcTestTree.GetSelectedItem();
	// ��ȡѡ�нڵ�ı�ǩ�ı��ַ���   
	strText = m_tcTestTree.GetItemText(hItem);
	// ���ַ�����ʾ���༭����   
	SetDlgItemText(IDC_EDIT1 , strText);
}


void CMFCApplication1Dlg::OnTvnGetInfoTipTree1(NMHDR *pNMHDR , LRESULT *pResult)
{
	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	NMTVGETINFOTIP* pTVTipInfo = (NMTVGETINFOTIP*)pNMHDR;   // �������pNMHDRת��ΪNMTVGETINFOTIPָ������   
	HTREEITEM hRoot = m_tcTestTree.GetRootItem();      // ��ȡ���ĸ��ڵ�   
	CString strText;     // ÿ�����ڵ����ʾ��Ϣ   

	if (pTVTipInfo->hItem == hRoot)
	{
		// �����껮���Ľڵ��Ǹ��ڵ㣬����ʾ��ϢΪ��   
		strText = _T("");
	}
	else
	{
		// �����껮���Ľڵ㲻�Ǹ��ڵ㣬�򽫸ýڵ�ĸ���32λ���ݸ�ʽ��Ϊ�ַ���   
		strText.Format(_T("%d") , pTVTipInfo->lParam);
	}

	// ��strText�ַ���������pTVTipInfo�ṹ�������pszText��Ա�У�����������ʾ����ΪstrText����ʾ��Ϣ   
	wcscpy(pTVTipInfo->pszText , strText);
}


void CMFCApplication1Dlg::InitListCtrl()
{
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_lcTestList.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_lcTestList.SetExtendedStyle(m_lcTestList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������   
	m_lcTestList.InsertColumn(0 , _T("����") , LVCFMT_CENTER , rect.Width() / 3 , 0);
	m_lcTestList.InsertColumn(1 , _T("2012.02����") , LVCFMT_CENTER , rect.Width() / 3 , 1);
	m_lcTestList.InsertColumn(2 , _T("2011.02����") , LVCFMT_CENTER , rect.Width() / 3 , 2);

	// ���б���ͼ�ؼ��в����б���������б������ı�   
	m_lcTestList.InsertItem(0 , _T("Java"));
	m_lcTestList.SetItemText(0 , 1 , _T("1"));
	m_lcTestList.SetItemText(0 , 2 , _T("1"));
	m_lcTestList.InsertItem(1 , _T("C"));
	m_lcTestList.SetItemText(1 , 1 , _T("2"));
	m_lcTestList.SetItemText(1 , 2 , _T("2"));
	m_lcTestList.InsertItem(2 , _T("C#"));
	m_lcTestList.SetItemText(2 , 1 , _T("3"));
	m_lcTestList.SetItemText(2 , 2 , _T("6"));
	m_lcTestList.InsertItem(3 , _T("C++"));
	m_lcTestList.SetItemText(3 , 1 , _T("4"));
	m_lcTestList.SetItemText(3 , 2 , _T("3"));
}

void CMFCApplication1Dlg::OnNMClickList1(NMHDR *pNMHDR , LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strLangName;    // ѡ�����Ե������ַ���   
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
	{
		// ��ȡ��ѡ���б����һ��������ı�   
		strLangName = m_lcTestList.GetItemText(pNMListView->iItem , 0);
		// ��ѡ���������ʾ��༭����   
		SetDlgItemText(IDC_EDIT2 , strLangName);
	}
}

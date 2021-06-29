// DialogControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DialogControlBoard.h"
#include "afxdialogex.h"


// CDialogControl �Ի���

IMPLEMENT_DYNAMIC(CDialogControlBoard, CDialogEx)

CDialogControlBoard::CDialogControlBoard(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CONTROL, pParent)
{
	m_nNumber = 0;
	m_sNubmer = "";
	m_bShow = false;
}

CDialogControlBoard::~CDialogControlBoard()
{

}

void CDialogControlBoard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditNumber);
	DDX_Control(pDX, IDC_STATIC1, m_StaticDrawMessage);
}


BEGIN_MESSAGE_MAP(CDialogControlBoard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDialogControlBoard::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CDialogControlBoard::OnBnClickedMinus)
	ON_BN_CLICKED(IDOK, &CDialogControlBoard::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogControlBoard::OnBnClickedCancel)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CDialogControl ��Ϣ�������


void CDialogControlBoard::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nNumber++;
	m_sNubmer.Format(_T("%d"), m_nNumber);
	m_EditNumber.SetWindowTextW(m_sNubmer);

	ShowDrawMessage();
	//UpdateData(FALSE);
	
}


void CDialogControlBoard::OnBnClickedMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_nNumber > 0)
	{
		m_nNumber--;
		m_sNubmer.Format(_T("%d"), m_nNumber);
		m_EditNumber.SetWindowTextW(m_sNubmer);

		ShowDrawMessage();
		
	}
	
}


void CDialogControlBoard::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_EditNumber.GetWindowTextW(m_sNubmer);
	int NumberTemp;
	NumberTemp =_ttoi(m_sNubmer);

	if (NumberTemp <=0)
	{
		m_nNumber=0;
		m_sNubmer.Format(_T("%d"), m_nNumber);
		m_EditNumber.SetWindowTextW(m_sNubmer);

		ShowDrawMessage();
		
	}
	else
	{
		m_nNumber = NumberTemp;
		m_sNubmer.Format(_T("%d"), m_nNumber);
		m_EditNumber.SetWindowTextW(m_sNubmer);

		ShowDrawMessage();
	}
	
	//CDialogEx::OnOK();
}


void CDialogControlBoard::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bShow = false;
	//CDialogEx::OnCancel();
}


void CDialogControlBoard::ShowDrawMessage()
{
	CString SDrawMessage;
	switch (m_nNumber)
	{
	case 0:SDrawMessage = "��ս���";break;
	case 1:SDrawMessage = "��";break;
	case 2:SDrawMessage = "��";break;
	case 3:SDrawMessage = "������";break;
	case 4:SDrawMessage = "������Ƭ";break;
	case 5:SDrawMessage = "��������";break;
	case 6:SDrawMessage = "�ı���";break;
	case 7:SDrawMessage = "�ı���Ƭ";break;
	case 8:SDrawMessage = "������Σ��ߵĿɼ���";break;
	case 9:SDrawMessage = "������";break;
	case 10:SDrawMessage = "������(������)";break;
	case 11:SDrawMessage = "ƽ�Ʊ任";break;
	case 12:SDrawMessage = "��ת�任";break;
	case 13:SDrawMessage = "���ű任";break;
	case 14:SDrawMessage = "���б任";break;
	case 15:SDrawMessage = "����";break;
	case 16:SDrawMessage = "���ƿ���ƽ��ģ��";break;
	case 17:SDrawMessage = "��ʾ�б�������ʾ�б�Բ��";break;
	case 18:SDrawMessage = "��һ����";break;
	case 19:SDrawMessage = "ƽ������";break;
	case 20:SDrawMessage = "��ȡͼ��";break;
	case 21:SDrawMessage = "������ͼ";break;
	case 22:SDrawMessage = "Mip��ͼ";break;
	case 23:SDrawMessage = "�ں��ı���";break;
	case 24:SDrawMessage = "͸������";break;
	case 25:SDrawMessage = "���ƶ�������";break;
	case 26:SDrawMessage = "Mip�Զ���ͼ";break;
	case 27:SDrawMessage = "Berzier����,����һ������������";break;
	case 28:SDrawMessage = "NURBS����,����һ��NURBS����";break;
	case 29:SDrawMessage = "Bezier����,������������";break;
	case 30:SDrawMessage = "Bezier����,���������������";break;
	case 31:SDrawMessage = "Nurbs����,������������";break;
	case 32:SDrawMessage = "�߼�������������Ĥ";break;
	case 33:SDrawMessage = "�߼������������߼�����";break;
	case 34:SDrawMessage = "��������,ʰȡ����";break;
	case 35:SDrawMessage = "";break;
	case 36:SDrawMessage = "";break;
	case 37:SDrawMessage = "";break;
	case 38:SDrawMessage = "";break;
	case 39:SDrawMessage = "";break;
	case 40:SDrawMessage = "";break;
	case 41:SDrawMessage = "";break;
	case 42:SDrawMessage = "";break;
	case 43:SDrawMessage = "";break;
	default:break;
	}

	//m_StaticDrawMessage.SetWindowTextW(SDrawMessage);
	m_StaticDrawMessage.SetWindowTextW(SDrawMessage);
	
}

void CDialogControlBoard::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch (nChar)
	{
	case VK_DOWN: OnBnClickedAdd();break;
	case VK_UP:if (m_nNumber > 0)OnBnClickedMinus();;break;
	}
	UpdateData();


	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

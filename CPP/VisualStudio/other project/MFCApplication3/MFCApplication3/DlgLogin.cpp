// DlgLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "DlgLogin.h"
#include "afxdialogex.h"


// CDlgLogin �Ի���

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_EditPassWord(_T(""))
	, m_EditUser(_T(""))
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_EditPassWord);
	DDX_Text(pDX, IDC_EDIT1, m_EditUser);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
END_MESSAGE_MAP()


// CDlgLogin ��Ϣ�������


// MFCApplication3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "MySQLOperate.h"
#include "DlgLogin.h"



// CMFCApplication3Dlg �Ի���
class CMFCApplication3Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;




public:
	CMySQLOperate sql;
	CDlgLogin lg;
	


public:
	CEdit m_EditOutPut;
	CListBox m_ListBox;
	CListCtrl m_ListCtrl;
	CEdit m_EditLableName;





	/*�Զ���ĺ���*/
public:
	bool login();

	
	
	
	// ���ɵ���Ϣӳ�亯��
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()






};

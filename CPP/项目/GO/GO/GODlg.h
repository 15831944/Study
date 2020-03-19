
// GODlg.h : ͷ�ļ�
//

#pragma once
#include"Resource.h"

#include"GOProcess.h"


// CGODlg �Ի���
class CGODlg : public CDialogEx
{
// ����
public:
	CGODlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//��ʼ��Ϸ
	afx_msg void OnBnClickedGamestart();
	afx_msg void OnBnClickedButtonResigns();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonPause();
public:
	CGOProcess m_gop;
	CPoint m_mlcp;

public:
	//������
	void DrawGOBoard(CDC* pDC);

	//����Ϣ
	void DrawGOInformation(CDC* pDC);

	//����
	void DropChessPieces(CPoint p);


	
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

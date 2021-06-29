#pragma once
#include "afxwin.h"
#include"resource.h"

// CDialogControl �Ի���

class CDialogControlBoard : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogControlBoard)

public:
	CDialogControlBoard(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogControlBoard();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CONTROL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()




protected:
	CStatic m_StaticDrawMessage;

protected:
	void ShowDrawMessage();



public:
	int m_nNumber;
	CString m_sNubmer;
	CEdit m_EditNumber;
	bool m_bShow;



public:



public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedCancel();
	
	
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
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

	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR , LRESULT *pResult);
	afx_msg void OnTvnGetInfoTipTree1(NMHDR *pNMHDR , LRESULT *pResult);

	DECLARE_MESSAGE_MAP()

public:
	CTreeCtrl m_tcTestTree;
	CImageList m_imageList;
	CListCtrl m_lcTestList;

public:
	void InitTreeCtrl();
	void InitListCtrl();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR , LRESULT *pResult);
};

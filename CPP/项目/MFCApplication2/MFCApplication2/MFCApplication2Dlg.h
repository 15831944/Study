
// MFCApplication2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCApplication2Dlg �Ի���
class CMFCApplication2Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
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
	
	afx_msg void OnNMCustomdrawSliderH(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderV(NMHDR *pNMHDR, LRESULT *pResult);
	// ˮƽ����λ��
	CEdit m_EditSliderH;
	// ��ֱ����λ��
	CEdit m_EditSliderV;
	CSliderCtrl m_SliderV;
	CSliderCtrl m_SliderH;
	afx_msg void OnBnClickedOk();
};

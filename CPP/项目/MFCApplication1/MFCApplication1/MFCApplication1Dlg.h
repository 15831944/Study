
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once

#include"resource.h"
#include "afxwin.h"


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
	// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	/*��¼��־��������*/
	void WriteLog(CString message, CString title);

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

	/*�ı�༭�����ݺ�������*/
	afx_msg void OnChangeEditText();
	/*�����༭�����ݺ�������*/
	afx_msg void OnErrspaceEditText();
	/*�༭��ʧȥ���㺯������*/
	afx_msg void OnKillfocusEditText();
	/*�༭�������ݴﵽ���ֵ��������*/
	afx_msg void OnMaxtextEditText();
	/*���ñ༭�򽹵㺯������*/
	afx_msg void OnSetfocusEditText();
	/*���±༭��������*/
	afx_msg void OnUpdateEditText();
	/*ˮƽ�����¼���������*/
	afx_msg void OnHscrollEditTestScroll();
	/*��ֱ�����¼���������*/
	afx_msg void OnVscrollEditTestScroll();
	/*��ȡ�ı������¼���������*/
	afx_msg void OnButtonGetEditText();
	/*�����ı������¼���������*/
	afx_msg void OnButtonSetEditText();
	/*��ȡѡ���ı��¼���������*/
	afx_msg void OnButtonGetLine();
	/*��ȡѡ����ı������¼���������*/
	afx_msg void OnButtonGetSel();
	/*����ѡ����ı������¼���������*/
	afx_msg void OnButtonSetSel();
	/*�滻ѡ����ı������¼���������*/
	afx_msg void OnButtonReplaceSel();
	/*��̬�ؼ������¼���������*/
	afx_msg void OnStaticText();



	DECLARE_MESSAGE_MAP()
public:


	CEdit m_EditTest;
	CStatic m_staticLog;
	CEdit m_EditTestScroll;
};

/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
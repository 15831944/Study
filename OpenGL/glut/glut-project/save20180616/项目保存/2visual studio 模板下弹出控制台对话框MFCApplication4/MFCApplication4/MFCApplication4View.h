
// MFCApplication4View.h : CMFCApplication4View ��Ľӿ�
//

#pragma once
#include "DialogControlBoard.h"
#include"OpenGLFrame.h"
//#include "WelcomePage.h"



class CMFCApplication4View : public CView
{
protected: // �������л�����
	CMFCApplication4View();
	DECLARE_DYNCREATE(CMFCApplication4View)

// ����
public:
	CMFCApplication4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags , CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags , CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags , CPoint point);
	afx_msg void OnMouseMove(UINT nFlags , CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags , short zDelta , CPoint pt);
	afx_msg void OnSize(UINT nType , int cx , int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnDrawControl();
	afx_msg void OnViewSelect2D();
	afx_msg void OnViewSelect3D();

	// ����
protected:
	bool m_bWelcomePage;
	int timeTemp;
	// ����
public:
	CClientDC* m_pDC;
	CRect m_oldRect;
	/*��ʾ����̨*/
	int m_nDrawSelect;
	bool m_bShowControlBoard;



	//CWelcomePage m_wcp;
public:

	/*OpenGL��������*/
	COpenGLFrame m_oglf;
	CDialogControlBoard* m_DlgCtrlBoard;


	// ����
protected:
	/*��������̨*/
	void CreateControlBoard();
	/*��ʾ����̨*/
	void ShowControlBoard();
public:
	
};

#ifndef _DEBUG  // MFCApplication4View.cpp �еĵ��԰汾
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif


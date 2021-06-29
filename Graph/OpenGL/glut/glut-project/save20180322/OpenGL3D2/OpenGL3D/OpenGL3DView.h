
// OpenGL3DView.h : COpenGL3DView ��Ľӿ�
//

#pragma once
#include "DialogControlBoard.h"
#include"OpenGLFrame.h"





class COpenGL3DView : public CView
{
protected: // �������л�����
	COpenGL3DView();
	DECLARE_DYNCREATE(COpenGL3DView)

// ����
public:
	COpenGL3DDoc* GetDocument() const;

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
	virtual ~COpenGL3DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:


	//afx_msg void OnFilePrintPreview();
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


	afx_msg void OnDrawControl();

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	DECLARE_MESSAGE_MAP()
public:
	



	// ����
public:
	CClientDC* m_pDC;
	CRect m_oldRect;
	/*��ʾ����̨*/
	int m_nDrawSelect;
	bool m_bShowControlBoard;
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

};

#ifndef _DEBUG  // OpenGL3DView.cpp �еĵ��԰汾
inline COpenGL3DDoc* COpenGL3DView::GetDocument() const
   { return reinterpret_cast<COpenGL3DDoc*>(m_pDocument); }
#endif


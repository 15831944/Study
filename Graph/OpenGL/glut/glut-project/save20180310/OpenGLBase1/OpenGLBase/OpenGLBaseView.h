
// OpenGLBaseView.h : COpenGLBaseView ��Ľӿ�
//

#pragma once
#include"OpenGLFrame.h"
#include"DialogControlBoard.h"


class COpenGLBaseView : public CView
{
protected: // �������л�����
	COpenGLBaseView();
	DECLARE_DYNCREATE(COpenGLBaseView)

// ����
public:
	COpenGLBaseDoc* GetDocument() const;


// ����
public:
	CClientDC* m_pDC;
	CRect m_oldRect;
	/*��ʾ����̨*/
	int m_nDrawSelect;
	bool m_bShowControlBoard;
public:
	
	/*OpenGL��������*/
	COpenGLFrame m_oglo;
	CDialogControlBoard* m_DlgCtrlBoard;
	

// ����
protected:
	/*��������̨*/
	void CreateControlBoard();
	/*��ʾ����̨*/
	void ShowControlBoard();

	
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
	virtual ~COpenGLBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()


	/*���ɵ���Ϣӳ�亯��*/
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType , int cx , int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags , CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags , CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags , CPoint point);
	afx_msg void OnMouseMove(UINT nFlags , CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags , short zDelta , CPoint pt);
	
	
	


	/*�Զ���˵���Ϣ*/
public:
	afx_msg void OnDrawControl();


	/*�Զ��幤������Ϣ*/
public:
	afx_msg void OnDrawClear();
	afx_msg void OnDrawPoints();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawTraingles();
	

	
};

#ifndef _DEBUG  // OpenGLBaseView.cpp �еĵ��԰汾
inline COpenGLBaseDoc* COpenGLBaseView::GetDocument() const
   { return reinterpret_cast<COpenGLBaseDoc*>(m_pDocument); }
#endif


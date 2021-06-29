
// MFCApplication3View.h : CMFCApplication3View ��Ľӿ�
//

#pragma once

#include "WelcomePage.h"




class CMFCApplication3View : public CView
{
protected: // �������л�����
	CMFCApplication3View();
	DECLARE_DYNCREATE(CMFCApplication3View)

// ����
public:
	CMFCApplication3Doc* GetDocument() const;

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
	virtual ~CMFCApplication3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

	//����
protected:

	//����
public:
	bool m_bShowWelcomePage;
	int m_nTimeShowWelcomePage;

	//����
protected:
	CWelcomePage m_wcp;

	//����
protected:

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar , UINT nRepCnt , UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags , CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags , CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication3View.cpp �еĵ��԰汾
inline CMFCApplication3Doc* CMFCApplication3View::GetDocument() const
   { return reinterpret_cast<CMFCApplication3Doc*>(m_pDocument); }
#endif


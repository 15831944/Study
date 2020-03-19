// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ������� 
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// CntrItem.cpp : CMFCApplication1CntrItem ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication1.h"

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1CntrItem ��ʵ��

IMPLEMENT_SERIAL(CMFCApplication1CntrItem, COleDocObjectItem, 0)

CMFCApplication1CntrItem::CMFCApplication1CntrItem(CMFCApplication1Doc* pContainer)
	: COleDocObjectItem(pContainer)
{
	// TODO: �ڴ����һ���Թ������
}

CMFCApplication1CntrItem::~CMFCApplication1CntrItem()
{
	// TODO: �ڴ˴�����������
}

void CMFCApplication1CntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);

	// �ڱ༭ĳ��ʱ(�͵ر༭����ȫ�򿪽��б༭)��
	//  �����������״̬�ĸ���
	//  �������ݵĿ������״̬�ĸ��ķ��� OnChange ֪ͨ��

	// TODO: ͨ������ UpdateAllViews ʹ������Ч
	//  (�����ʺ�����Ӧ�ó������ʾ)

	GetDocument()->UpdateAllViews(NULL);
		// ����ֻ����������ͼ/����ʾ
}

BOOL CMFCApplication1CntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// �͵ؼ����ڼ䣬���������� CMFCApplication1CntrItem::OnChangeItemPosition
	//  �Ը��ľ͵ش��ڵ�λ�á�
	//  ��ͨ�������ڷ�����
	//  �ĵ��е����ݸ��Ķ����·�Χ�ı����
	//  �͵ص�����С������ġ�
	//
	// �˴���Ĭ�����õ��û��࣬�û��ཫ����
	//  COleDocObjectItem::SetItemRects �Խ�����
	//  �ƶ����µ�λ�á�

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: ���¸���ľ���/��Χ���ܴ��ڵ��κλ���

	return TRUE;
}

BOOL CMFCApplication1CntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}


void CMFCApplication1CntrItem::OnActivate()
{
}

void CMFCApplication1CntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleDocObjectItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CMFCApplication1CntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// ���ȵ��û����Զ�ȡ COleDocObjectItem ���ݡ�
	// ��Ϊ���������ô� CMFCApplication1CntrItem::GetDocument ���ص� m_pDocument ָ�룬
	//  ��������ȵ���
	//  ���� Serialize��
	COleDocObjectItem::Serialize(ar);

	// ���ڴ洢/�����ض��� CMFCApplication1CntrItem ������
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

BOOL CMFCApplication1CntrItem::CanActivate()
{
	// �������������ھ͵ر༭ģʽʱ���͵ر༭��Ч�Ҳ���֧�֡�
	//  ��ˣ�����������½��þ͵�
	//  ���
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;
	ASSERT_KINDOF(COleServerDoc, pDoc);
	if (!pDoc->IsKindOf(RUNTIME_CLASS(COleServerDoc)))
	{
		return FALSE;
	}
	if (pDoc->IsInPlaceActive())
		return FALSE;

	// ��������Ĭ����Ϊ
	return COleClientItem::CanActivate();
}


// CMFCApplication1CntrItem ���

#ifdef _DEBUG
void CMFCApplication1CntrItem::AssertValid() const
{
	COleDocObjectItem::AssertValid();
}

void CMFCApplication1CntrItem::Dump(CDumpContext& dc) const
{
	COleDocObjectItem::Dump(dc);
}
#endif


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

// CntrItem.h : CMFCApplication1CntrItem ��Ľӿ�
//

#pragma once

class CMFCApplication1Doc;
class CMFCApplication1View;

class CMFCApplication1CntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CMFCApplication1CntrItem)

// ���캯��
public:
	CMFCApplication1CntrItem(CMFCApplication1Doc* pContainer = NULL);
		// ע��: ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����  OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	CMFCApplication1Doc* GetDocument()
		{ return reinterpret_cast<CMFCApplication1Doc*>(COleDocObjectItem::GetDocument()); }
	CMFCApplication1View* GetActiveView()
		{ return reinterpret_cast<CMFCApplication1View*>(COleDocObjectItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);
	virtual BOOL CanActivate();

// ʵ��
public:
	~CMFCApplication1CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};


#pragma once

#include"resource.h"


class CWelcomePage
{
public:
	CWelcomePage();
	~CWelcomePage();


public:
	CBitmap m_bmpWelcomePage;

	/*���ƻ�ӭҳ��*/
public:
	void DrawWelcomePage(CDC* pDC);
	void DrawPicture(CDC* pDC);
	void DrawMyText(CDC* pDC);
};


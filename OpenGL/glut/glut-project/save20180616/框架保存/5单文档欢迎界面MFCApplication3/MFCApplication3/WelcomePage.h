#pragma once

#include"resource.h"


class CWelcomePage
{
public:
	CWelcomePage();
	~CWelcomePage();

protected:
	CBitmap m_bmpWelcomePage;


public:
	

	

protected:
	void DrawPicture(CDC* pDC);
	void DrawMyText(CDC* pDC);



	/*���ƻ�ӭҳ��*/
public:
	void DrawWelcomePage(CDC* pDC);

};


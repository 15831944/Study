#pragma once
#include<afxsock.h>

class CClientSocket:public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

public:
	CString OnRecevie(int nErrorCode);
	//���ش������
	int SendMSG(LPSTR lpBuffer, int nLen);
};


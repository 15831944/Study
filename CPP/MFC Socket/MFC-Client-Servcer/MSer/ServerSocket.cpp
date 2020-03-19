#pragma once
#include "pch.h"
#include "ServerSocket.h"
CServerSocket::CServerSocket()
{

}
CServerSocket::~CServerSocket()
{

}

void CServerSocket::OnReceive(int nErrorCode)

{

    m_pMSDlg->RecvData(this);                           // ��������

    CSocket::OnReceive(nErrorCode);

}

void CServerSocket::OnClose(int nErrorCode)

{

    m_pMSDlg->RemoveClient(this);                   // ɾ�������û�

    CSocket::OnClose(nErrorCode);

}

void CServerSocket::OnAccept(int nErrorCode)

{

    m_pMSDlg->AddClient();                                  //��������û�

    CSocket::OnAccept(nErrorCode);

}

#pragma once
//#include "ServerSocket.h"

class CDataProcess
{
public:
	CDataProcess();
	virtual ~CDataProcess();

public:
	// �˿ں�
	UINT m_uiPort;
	// �û�����
	UINT m_uiUserCount;
	
	//CServerSocket* listenSocket;     // ���ڴ򿪷�����

	CPtrList m_clientList;                 // �������ڴ洢�û�

	//bool m_connect;                       // ���ڱ�Ƿ�����״̬
	// �㲥
	//CString m_edit_csSend;

public:

    void AddClient();                       // �����û�����Ӧ�û�����

	//void RemoveClient(CServerSocket* pSocket);          // �Ƴ����ߵ��û�

//	void RecvData(CServerSocket* pSocket);                 // ��ȡ����

	void UpdateEvent(CString str);  // �����¼���־
	void Broadcast();		//�㲥

	//�ַ�ת��
	BOOL WChar2MByte(LPCWSTR srcBuff, LPSTR destBuff, int nlen);        

	void SendMSG(CString str);       // ������Ϣ�������ͻ���
	void ControlPC(CString AndroidControl);  // �ֻ�����PC����Ӧ����
	BOOL PreTranslateMessage(MSG* pMsg);

};


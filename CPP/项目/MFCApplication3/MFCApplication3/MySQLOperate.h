#pragma once

#include <mysql.h> 

#pragma comment(lib, "ws2_32.lib")  
#pragma comment(lib, "libmysql.lib") 





class CMySQLOperate
{
public:
	CMySQLOperate();
	~CMySQLOperate();


public:
	//�ر���һ�����ݽṹ  
	MYSQL mydata;

	CString c;

	//sql�ַ���  
	char querry[500];

public:
	bool ConnectMySQL();
	bool Querry();
	CString login(CString user);
};


#include "stdafx.h"
#include "MySQLOperate.h"


CMySQLOperate::CMySQLOperate()
{

	
}


CMySQLOperate::~CMySQLOperate()
{
}


bool CMySQLOperate::ConnectMySQL()
{
	bool sqlSucceed = true;




	//��ʼ�����ݿ�  
	if (0 == mysql_library_init(0, NULL, NULL))
	{
		c += "mysql_library_init() succeed";
		//c.Replace("\n", "\r\n");
		c += "\r\n";

	}
	else
	{
		c += "mysql_library_init() failed";
		c += "\r\n";
		return -1;
	}

	//UpdateData��FALSE��;

	//��ʼ�����ݽṹ  
	if (NULL != mysql_init(&mydata))
	{
		c += "mysql_init() succeed";
		c += "\r\n";

	}
	else
	{
		c += "mysql_init() failed";
		c += "\r\n";
		return -1;
	}



	//���������ݿ�֮ǰ�����ö��������ѡ��  
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������  
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gb2312"))
	{
		c += "mysql_options() succeed";
		c += "\r\n";
	}
	else
	{
		c += "mysql_options() failed";
		c += "\r\n";
		return -1;
	}



	//�������ݿ�  
	if (NULL != mysql_real_connect(&mydata, "", "zn", "123456", "test", 3306, NULL, 0))
		//����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������  
	{
		c += "mysql_real_connect() succeed";
		c += "\r\n";
	}
	else
	{
		c += "mysql_real_connect() failed";
		c += "\r\n";
		return -1;
	}
	return false;
}


bool CMySQLOperate::Querry()
{
	
	sprintf_s(querry, "CREATE TABLE IF NOT EXISTS user_infoo(user_id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY COMMENT 'Unique User ID',user_name VARCHAR(100) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL COMMENT 'Name Of User',user_second_sum INT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'The Summation Of Using Time');");
	if (0 == mysql_query(&mydata, querry))
	{
		c += "mysql_query() create table succeed";
		c += "\r\n";
	}
	else
	{
		c += "mysql_query() create table failed";
		c += "\r\n";
		mysql_close(&mydata);
		return -1;
	}



	//����в�������  
	sprintf_s(querry, "INSERT INTO user_infoo(user_name) VALUES('��˾����'),('һ������'),('��������'),('����С��'),('����');");

	if (0 == mysql_query(&mydata, querry))
	{
		c += "mysql_query() insert data succeed";
		c += "\r\n";
	}
	else
	{
		c += "mysql_query() insert data failed";
		c += "\r\n";
		mysql_close(&mydata);
		return -1;
	}

	




	
	return false;
}



CString CMySQLOperate::login(CString user)
{
	CString pw;
	bool be = false;




	CMySQLOperate::ConnectMySQL();
	CMySQLOperate::Querry();
	

	sprintf_s(querry, "SELECT Administrator,PassWord FROM administrator");
	MYSQL_RES *result = NULL;
	if (0 == mysql_query(&mydata, querry))
	{
		
		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = (int)mysql_num_rows(result);

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;

		//��ӡ����  
		/*��ȡ��ʾ����*/
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		
		
		while (NULL != row)
		{
			for (int j = 0; j < fieldcount; j++)
			{  
				CString r;
				r = row[j];
				if(r==user)
				{
					if ((j + 1)<fieldcount)
					{
						be = true;
						pw = row[j+1];
					}
				}
			}
			row = mysql_fetch_row(result);
		}
	}
	else
	{
		mysql_close(&mydata);
		//return -1;
	}

	if(!be)pw = "$";
	return pw;
}
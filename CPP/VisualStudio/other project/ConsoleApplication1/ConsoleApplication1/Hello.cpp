#include"stdafx.h"
#include"Hello.h"
#include<time.h>
const int TIME_MAX = 32;

void pruintDate()
{
	//����tm�ṹ��ʱ�����
	struct tm newdate;
	
	//����time_t�ṹ��ʱ�����
	time_t long_date;
	//��ȡʱ��
	time(&long_date);

	//��ʱ��ת��Ϊ����ʱ��
	 localtime_s(&newdate, &long_date);

	 char stTmp[TIME_MAX];

	 asctime_s(stTmp, &newdate);
	//��ӡ��ǰʱ��
	 printf("��ǰʱ���ǣ�%s\n", stTmp);

}
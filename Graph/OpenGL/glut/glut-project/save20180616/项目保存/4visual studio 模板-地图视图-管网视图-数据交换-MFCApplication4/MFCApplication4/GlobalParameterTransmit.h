#pragma once
#include"stdafx.h"

class CGlobalParameterTransmit
{
public:
	CGlobalParameterTransmit();
	~CGlobalParameterTransmit();

public:
	//ȫ���ļ���ͼ���������
	typedef struct GlobalFileviewParameter
	{
		// �ֲ㣬���
		int iStorey;
		//����(�ж��ǹ���(Pipe)���ǹܽ�ͷ(Pipe joints)��)
		bool bPiple;
		//���
		int iNum;
		//ͷ
		int iHead;
		//β
		int iTail;
		//�м�
		int iMiddle;

		
	}GFP;

	//ȫ���ļ���ͼ���������
	GFP gfp;

	int a;

public:
	void FileViewParameterVoluation(int iStorey , bool bPiple , int iNum , int iHead , int iTail , int iMiddle);
	void FileViewParameterVoluation(int iStorey , bool bPiple , int iNum , int iHead , int iTail );

};


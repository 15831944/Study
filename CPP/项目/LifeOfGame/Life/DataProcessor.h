#pragma once

class CDataProcessor
{
public:
	CDataProcessor();
	~CDataProcessor();

public:
	int LifeArray[40][40] = { 0 };

public:
	// Initaliza Setting�����������ʼ������
	void InitSetting(int x,int y, bool put);
	//������������
	void Reset();
	//�ݻ���ʼ
	void Evolution();
};


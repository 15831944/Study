#pragma once
class CGOProcess
{
public:
	CGOProcess();
	virtual ~CGOProcess();

public:
	int GOMap[19][19] = { 0 };
	//0:�Ծ�δ��ʼ��1���ڷ���2���׷���3���Ծֽ���
	int flag;
	//����
	int step;
	//�������
	int BlackTaking;
	//�������
	int WhiteTaking;
	//������ʱ
	int BlackTime;
	//������ʱ
	int WhiteTime;
	//������ʱ
	int stepTime;
	//��Ŀ
	float komi;

	//��һ������λ������
	int coordinateX1;
	int coordinateY1;

	//��ǰ����λ������
	int coordinateX2 ;
	int coordinateY2 ;

	
public:
	void GameStart();
	//ת��ʱ��
	CString TimeConvert(int seconds);

};


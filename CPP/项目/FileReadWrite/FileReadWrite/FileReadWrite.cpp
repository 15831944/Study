#include<iostream>
#include<fstream>
using namespace std;

//˳���ļ���д
void WriteOrderFile()
{
	ofstream myFile;
	myFile.open("dataOrder.txt", ios::out);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}
	myFile << "����" << endl << "����" << endl;


	myFile.close();

	cout << endl << "дdataOrder.txt�ļ�";

}


void ReadOrderFile()
{
	ifstream myFile;
	myFile.open("dataOrder.txt", ios::in);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}
	cout << endl << "��ȡdataOrder.txt�ļ�����������ʾ��" << endl;
	int value;
	while ((value = myFile.get()) != EOF)
	{
		cout << (char)value;
	}
	myFile.close();
}


//����ļ���д
struct Record
{
	char value[10];
};

void WriteRandomFile()
{
	Record record[3] = { "01-����","02-����","03-����" };


	ofstream myFile;
	myFile.open("dataRandom.txt",ios::out|ios::binary);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}
	for (int i = 0;i < 3;i++)
	{
		myFile.write((const char*)&record[i], sizeof(Record));

	}
	


	myFile.close();

	cout << endl << "дdataRandom.txt�ļ�";

}

void ReadRandomFile()
{

	ifstream myFile;
	myFile.open("dataRandom.txt", ios::in|ios::binary);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}

	cout << endl << "��dataRandom.txt�ļ�" << endl;
	//�����Ż�ȡ��¼�ı���
	Record record;
	//���ļ���дָ����ļ��Ŀ�ͷ�����һ����¼
	myFile.seekg(sizeof(Record), ios::beg);
	//��ȡ�ļ��ڶ�����¼
	myFile.read((char*)&record, sizeof(record));
	cout << (char*)&record;

	myFile.close();

	

}





void main()
{
	int a;
	a = 7753;
	cout << a;

	//WriteOrderFile();

	ReadOrderFile();


	WriteRandomFile();

	ReadRandomFile();

	system("pause");
}

#include<iostream>
#include<fstream>
using namespace std;


void WriteOrderFile()
{
	ofstream myFile;
	myFile.open("data.txt", ios::out);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}
	myFile << "����" << endl << "����" << endl;


	myFile.close();

	cout << endl << "дdata.txt�ļ�" ;

}


void ReadOrderFile()
{
	ifstream myFile;
	myFile.open("data.txt", ios::in);
	if (!myFile)
	{
		cout << "���ļ�����" << endl;
		return;
	}
	cout << endl<<"��ȡdata.txt�ļ�����������ʾ��" << endl;
	int value;
	while ((value = myFile.get() )!= EOF)
	{
		cout << (char)value;
	}
	myFile.close();
}

void main()
{
	int a;
	a = 7753;
	cout << a;
	
	WriteOrderFile();

	ReadOrderFile();

	system("pause");
}

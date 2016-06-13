#include <iostream>
#include <string>
#include <fstream>	//���������
#include <functional>	//greater
#include <iterator>
#include <vector>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define YELGREEN	SetConsoleTextAttribute(col, 0x00a);
#define WHITE 	SetConsoleTextAttribute(col, 0x000f);
#define YELLOW 	SetConsoleTextAttribute(col, 0x000e);
using namespace std;
using namespace chrono;
typedef pair<char, double> data;

void Menu()
{
	YELGREEN;
	cout << " �޸����� �Է��ϱ⸦ ������ �������� ��ȭ�� ���۵˴ϴ�. " << endl;
	cout << " �ܰ躰�� ����ϽǶ��� �渦 �����ø� �˴ϴ�. " << endl;
	cout << " ������ �����ϽǶ����� �����̸��� ���ø� �˴ϴ�. " << endl;
	cout << " ������ �ҷ��ö��� �����̸��� ���ø� �˴ϴ�. " << endl << endl;
	WHITE;
	cout << " 1. �Է��ϱ�" << endl;
	cout << " 2. ����ϱ� (�ð�) " << endl;
	cout << " 3. ����ϱ� (�ܰ�) " << endl << endl;
	cout << " ��ȣ �Է� : ";

}
int main()
{
	char num;
	const char space = 0;
	const char enter = 1;

	while (1)
	{
		Menu();
		cin >> num;

		switch (num)
		{
		case '1':
		{
					system("cls");
					char chr;
					vector<data> input;

					system_clock::time_point start_time = system_clock::now();	//�Է� ���� �ð� ����
					system_clock::time_point end_time;
					duration<double, micro> d;
					YELGREEN;
					cout << "[ ������ �Է����ּ���. �������� ESC�� �������� ] " << endl;
					WHITE;
					while ((chr = _getch()) != 27)					//esc�� ������ ������
					{
						end_time = chrono::system_clock::now();
						d = end_time - start_time;
						if (chr == 8)	{ cout << "\b" << " "; }		//�齺���̽�
						if (chr == 13)	{ cout << endl; }			//����
						if (chr == 32)	{ cout << " "; }			// �����̽�
						input.push_back(make_pair(chr, d.count()));
						cout << chr;
					}
					end_time = chrono::system_clock::now();
					d = end_time - start_time;
					input.push_back(make_pair(chr, d.count()));
					ofstream write_txt;
					string filename;
					cout << endl << endl;
					YELLOW;
					cout << "���� �̸��� �Է��� �ּ��� : ";
					WHITE;
					cin >> filename;
					write_txt.open(filename + ".txt", ios::out, ios::trunc); // ��� & ������������ �����ϰ� ���� ����

					for (auto i = input.begin(); i != input.end(); ++i)
					{
						if (i < input.end() - 1){
							if (i->first == 32){	// �����̽�
								write_txt << space << "\t" << i->second - input.begin()->second << endl;
							}
							else if (i->first == 13){	//����
								write_txt << enter << "\t" << i->second - input.begin()->second << endl;
							}
							else
								write_txt << i->first << "\t" << i->second - input.begin()->second << endl;
						}
						else if (i == input.end() - 1)
						{
							if (i->first == 32)	// �����̽�
							{
								write_txt << space << "\t" << i->second - input.begin()->second;
							}
							else if (i->first == 13)	//����
							{
								write_txt << enter << "\t" << i->second - input.begin()->second;
							}
							else
								write_txt << i->first << "\t" << i->second - input.begin()->second;
						}
					}
					write_txt.close();
					YELLOW;
					cout << "���� �Ϸ�" << endl << endl;
					break;
		}
		case '2':
		{
					system("cls");
					system_clock::time_point end_time;
					duration<double, micro> d;

					vector<data> output;
					char data;
					double time;
					ifstream read_txt;
					string filename;
					YELLOW;
					cout << "�ҷ��� ���� �̸��� �Է����ּ��� : ";
					WHITE;
					cin >> filename;
					read_txt.open(filename + ".txt", ios::in);

					if (read_txt.is_open()){
						while (read_txt >> data >> time){
							output.push_back(make_pair(data, time));
						}
						read_txt.close();
					}
					else{
						cout << "������ �����" << endl;
						break;
					}

					cout << endl;
					YELGREEN;
					cout << "-------------- < ���÷��� ����(�ð���) > -------------" << endl;
					WHITE;
					system_clock::time_point start_time = system_clock::now();

					for (auto i = output.begin(); i != output.end();)
					{
						end_time = chrono::system_clock::now();
						d = end_time - start_time;
						if (d.count() >= i->second)
						{
							if (i->first == 8){ cout << "\b"<<" "; }
							if (i->first == 27)	{ break; }
							if (i->first == enter)	{ cout << endl; }
							else if (i->first == space){ cout << " "; }
							else { cout << i->first; }
							++i;
						}
					}
					cout << endl << endl;
					cout << "���÷��� ��" << endl << endl;
					break;
		}
		case '3':
		{
					system("cls");

					vector<data> step;
					char in;			// ����ڰ� �Է��� ��
					char data;		// �ҷ��� ���� �����Ұ�1 (�Է°�)
					double time;	// �ҷ��� ���� �����Ұ�2 (�ð�)
					ifstream read_txt;
					string filename;
					YELLOW;
					cout << "�ҷ��� ���� �̸��� �Է����ּ��� : ";
					WHITE;
					cin >> filename;
					read_txt.open(filename + ".txt", ios::in);

					if (read_txt.is_open()){
						while (read_txt >> data >> time){
							step.push_back(make_pair(data, time));
						}
						read_txt.close();
					}
					else{
						cout << "������ �����" << endl;
						break;
					}

					cout << endl;
					YELGREEN;
					cout << "----------- < ���÷��� ����(�ܰ躰)  �渦 ��������> -----------" << endl;
					WHITE;
					for (auto i = step.begin(); i != step.end();)
					{
						in = _getch();		//�Է� �޾ƿ���
						if (in == 77)		// ������Ű �Է¹޾�����
						{
							if (i->first == 8){ cout << "\b" << " "; }
							if (i->first == 27)	{ break; }
							if (i->first == enter)	{ cout << endl; }
							else if (i->first == space){ cout << " "; }
							else { cout << i->first; }
							++i;
						}
					}
					cout << endl<<endl;
					cout << "���÷��� ��" << endl;
					break;
		}
		}
	}
}
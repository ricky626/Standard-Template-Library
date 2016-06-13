#include <iostream>
#include <string>
#include <fstream>	//파일입출력
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
	cout << " 메모장은 입력하기를 누르는 순간부터 녹화가 시작됩니다. " << endl;
	cout << " 단계별로 출력하실때는 →를 누르시면 됩니다. " << endl;
	cout << " 파일을 저장하실때에는 파일이름만 쓰시면 됩니다. " << endl;
	cout << " 파일을 불러올때도 파일이름만 쓰시면 됩니다. " << endl << endl;
	WHITE;
	cout << " 1. 입력하기" << endl;
	cout << " 2. 출력하기 (시간) " << endl;
	cout << " 3. 출력하기 (단계) " << endl << endl;
	cout << " 번호 입력 : ";

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

					system_clock::time_point start_time = system_clock::now();	//입력 시작 시간 저장
					system_clock::time_point end_time;
					duration<double, micro> d;
					YELGREEN;
					cout << "[ 내용을 입력해주세요. 끝내려면 ESC를 누르세요 ] " << endl;
					WHITE;
					while ((chr = _getch()) != 27)					//esc를 누르기 전까지
					{
						end_time = chrono::system_clock::now();
						d = end_time - start_time;
						if (chr == 8)	{ cout << "\b" << " "; }		//백스페이스
						if (chr == 13)	{ cout << endl; }			//엔터
						if (chr == 32)	{ cout << " "; }			// 스페이스
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
					cout << "파일 이름을 입력해 주세요 : ";
					WHITE;
					cin >> filename;
					write_txt.open(filename + ".txt", ios::out, ios::trunc); // 출력 & 파일이있으면 삭제하고 새로 생성

					for (auto i = input.begin(); i != input.end(); ++i)
					{
						if (i < input.end() - 1){
							if (i->first == 32){	// 스페이스
								write_txt << space << "\t" << i->second - input.begin()->second << endl;
							}
							else if (i->first == 13){	//엔터
								write_txt << enter << "\t" << i->second - input.begin()->second << endl;
							}
							else
								write_txt << i->first << "\t" << i->second - input.begin()->second << endl;
						}
						else if (i == input.end() - 1)
						{
							if (i->first == 32)	// 스페이스
							{
								write_txt << space << "\t" << i->second - input.begin()->second;
							}
							else if (i->first == 13)	//엔터
							{
								write_txt << enter << "\t" << i->second - input.begin()->second;
							}
							else
								write_txt << i->first << "\t" << i->second - input.begin()->second;
						}
					}
					write_txt.close();
					YELLOW;
					cout << "저장 완료" << endl << endl;
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
					cout << "불러올 파일 이름을 입력해주세요 : ";
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
						cout << "파일이 없어요" << endl;
						break;
					}

					cout << endl;
					YELGREEN;
					cout << "-------------- < 리플레이 시작(시간별) > -------------" << endl;
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
					cout << "리플레이 끝" << endl << endl;
					break;
		}
		case '3':
		{
					system("cls");

					vector<data> step;
					char in;			// 사용자가 입력한 값
					char data;		// 불러온 값을 저장할것1 (입력값)
					double time;	// 불러온 값을 저장할것2 (시간)
					ifstream read_txt;
					string filename;
					YELLOW;
					cout << "불러올 파일 이름을 입력해주세요 : ";
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
						cout << "파일이 없어요" << endl;
						break;
					}

					cout << endl;
					YELGREEN;
					cout << "----------- < 리플레이 시작(단계별)  →를 누르세요> -----------" << endl;
					WHITE;
					for (auto i = step.begin(); i != step.end();)
					{
						in = _getch();		//입력 받아오기
						if (in == 77)		// 오른쪽키 입력받았을때
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
					cout << "리플레이 끝" << endl;
					break;
		}
		}
	}
}
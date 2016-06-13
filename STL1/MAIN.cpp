#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

#define MAX 10000

void PrintAll(vector<pair <string, int>> v)
{
	for (auto d : v)
		cout << d.first << ends << d.second << endl;
	cout << endl;
}

int main()
{
	using Data = pair<string, int>;

	vector<Data> v; // 실제 데이터가 들어갈 vector

	
	time_t system_time = time(0);
	default_random_engine dre(system_time); // 기본 엔진 사용
	uniform_int_distribution<> ui(0, 1000); // 점수 범위
	uniform_int_distribution<> nui(5, 10); // 아이디의 길이
	uniform_int_distribution<> stui(65, 90); // 알파벳 범위 설정
	
	string str = ""; // ID가 될 문자열을 담는 변수
	int max = 0; // 아이디의 길이에 대한 정보를 담는 변수
	double mynumber = -1; // 나의 순위를 나타낼 변수

	ofstream ofs("파일저장.txt");

	
	for (int i = 0; i < MAX; ++i)
	{
		//문자열 초기화
		str = "";
		// ID의 길이를 랜덤하게 설정
		max = nui(dre);

		for (int j = 0; j < max; ++j)
		{
			// 문자열을 랜덤한 길이로 생성
			str += stui(dre);
		}

		// vector에 대입
		v.push_back({ str, ui(dre) });

		// 저장할 파일에 저장
		ofs << v[i].first << endl << v[i].second << endl;
	}

	//저장한 파일을 닫는다.
	ofs.close();

	ifstream ifs("파일저장.txt");
	vector<Data> readv; // 파일에 저장된 것을 읽어와서 저장할 vector


	cout << "**파일 읽기**" << endl;

	string s = "";
	int n = 0;

	for (int i = 0; i < MAX; ++i)
	{
		ifs >> s;
		ifs >> n;
		readv.push_back({ s, n });
		cout << readv[i].first << ends << readv[i].second << endl;
	}
	
	cout << "**파일 읽기**" << endl << endl;
	ifs.close();


	//나의 대한 정보를 넣어줌
	vector<Data> my; // 나의 점수가 들어갈 vector
	my.push_back({ v[0].first, v[0].second });


	// ID를 기준으로 오름차순 정렬
	sort(v.begin(), v.end());

	cout << "**ID를 기준으로 오름차순 정렬**" << endl;
	PrintAll(v); // 출력

	// 점수를 기준으로 내림차순 정렬
	sort(v.begin(), v.end(), [](const Data& a, const Data& b) {
		return a.second > b.second;
	});

	cout << endl << "**점수를 기준으로 내림차순 정렬**" << endl;
	PrintAll(v); // 출력

	
	// 나의 현재 순위는 몇번째인지 검사
	for (int i = 0; i < MAX; ++i)
	{
		if (my[0].first == v[i].first)
		{
			mynumber = i + 1;
			break;
		}
	}

	// 내 점수를 기준으로 위로 10개 아래로 10개를 판별
	int nummin = (mynumber <= 10) ? 0 : (mynumber - 1) - 10; 
	int nummax = (mynumber >= MAX - 10) ? MAX : mynumber + 10;

	cout << "**내 점수를 기준으로 위로 10개 데이터 표시**" << endl;
	for (int i = nummin; i < mynumber-1; ++i)
		cout << v[i].first << ends << v[i].second << "  " << i+1 << "위" << endl;
	cout << endl;

	cout << "**내 점수를 기준으로 아래로 10개 데이터 표시**" << endl;
	for (int i = mynumber; i < nummax; ++i)
		cout << v[i].first << ends << v[i].second << "  " << i+1 << "위" << endl;
	cout << endl;

	cout << endl << "나의 ID : " << my[0].first << ends << my[0].second << endl;
	cout << "나의 순위 : " << mynumber << "위" << endl;

	// 상위 몇 %인지 계산
	double d = mynumber / MAX * 100;

	cout << "상위 : " << d << "% 입니다." << endl << endl;

	
}
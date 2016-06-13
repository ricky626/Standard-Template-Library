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

	vector<Data> v; // ���� �����Ͱ� �� vector

	
	time_t system_time = time(0);
	default_random_engine dre(system_time); // �⺻ ���� ���
	uniform_int_distribution<> ui(0, 1000); // ���� ����
	uniform_int_distribution<> nui(5, 10); // ���̵��� ����
	uniform_int_distribution<> stui(65, 90); // ���ĺ� ���� ����
	
	string str = ""; // ID�� �� ���ڿ��� ��� ����
	int max = 0; // ���̵��� ���̿� ���� ������ ��� ����
	double mynumber = -1; // ���� ������ ��Ÿ�� ����

	ofstream ofs("��������.txt");

	
	for (int i = 0; i < MAX; ++i)
	{
		//���ڿ� �ʱ�ȭ
		str = "";
		// ID�� ���̸� �����ϰ� ����
		max = nui(dre);

		for (int j = 0; j < max; ++j)
		{
			// ���ڿ��� ������ ���̷� ����
			str += stui(dre);
		}

		// vector�� ����
		v.push_back({ str, ui(dre) });

		// ������ ���Ͽ� ����
		ofs << v[i].first << endl << v[i].second << endl;
	}

	//������ ������ �ݴ´�.
	ofs.close();

	ifstream ifs("��������.txt");
	vector<Data> readv; // ���Ͽ� ����� ���� �о�ͼ� ������ vector


	cout << "**���� �б�**" << endl;

	string s = "";
	int n = 0;

	for (int i = 0; i < MAX; ++i)
	{
		ifs >> s;
		ifs >> n;
		readv.push_back({ s, n });
		cout << readv[i].first << ends << readv[i].second << endl;
	}
	
	cout << "**���� �б�**" << endl << endl;
	ifs.close();


	//���� ���� ������ �־���
	vector<Data> my; // ���� ������ �� vector
	my.push_back({ v[0].first, v[0].second });


	// ID�� �������� �������� ����
	sort(v.begin(), v.end());

	cout << "**ID�� �������� �������� ����**" << endl;
	PrintAll(v); // ���

	// ������ �������� �������� ����
	sort(v.begin(), v.end(), [](const Data& a, const Data& b) {
		return a.second > b.second;
	});

	cout << endl << "**������ �������� �������� ����**" << endl;
	PrintAll(v); // ���

	
	// ���� ���� ������ ���°���� �˻�
	for (int i = 0; i < MAX; ++i)
	{
		if (my[0].first == v[i].first)
		{
			mynumber = i + 1;
			break;
		}
	}

	// �� ������ �������� ���� 10�� �Ʒ��� 10���� �Ǻ�
	int nummin = (mynumber <= 10) ? 0 : (mynumber - 1) - 10; 
	int nummax = (mynumber >= MAX - 10) ? MAX : mynumber + 10;

	cout << "**�� ������ �������� ���� 10�� ������ ǥ��**" << endl;
	for (int i = nummin; i < mynumber-1; ++i)
		cout << v[i].first << ends << v[i].second << "  " << i+1 << "��" << endl;
	cout << endl;

	cout << "**�� ������ �������� �Ʒ��� 10�� ������ ǥ��**" << endl;
	for (int i = mynumber; i < nummax; ++i)
		cout << v[i].first << ends << v[i].second << "  " << i+1 << "��" << endl;
	cout << endl;

	cout << endl << "���� ID : " << my[0].first << ends << my[0].second << endl;
	cout << "���� ���� : " << mynumber << "��" << endl;

	// ���� �� %���� ���
	double d = mynumber / MAX * 100;

	cout << "���� : " << d << "% �Դϴ�." << endl << endl;

	
}
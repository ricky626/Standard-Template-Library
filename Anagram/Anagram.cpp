#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
//include�� ����ϴ� �͸� ����(������ Ÿ�ӿ� ����, ������)

using namespace std;

struct PS : pair<string, string>    //Pair of String
{
	PS() : pair<string, string>(string(), string()) {}
	PS(const string& s) : pair<string, string>(s, s) {
		sort(first.begin(), first.end());
	}

	operator string() const { return second; }
};

int main()
{
	cout << "Anagram�� ã�� ���α׷�" << endl;

	ifstream ifs("diction");
	if (!ifs.is_open()) {    //�� ���ȳ� �˻�
		cout << "���� diction�� ���� �� �����ϴ�." << endl;
		exit(0);
	}

	vector<PS> v;
	v.reserve(20159);
	//string s;
	//while (ifs >> s)
	//    v.push_back(s);
	//STL������ �ݺ����� �Ⱦ��� ������ ���� �ʴ� ���� ����

	copy(istream_iterator<string>(ifs),
		istream_iterator<string>(), back_inserter(v));
	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�. " << endl;

	//���̵��
	//���� �ܾ�� �� �ܾ ������ �ܾ �ϳ��� ������ �����.
	//v�� first �������� �����Ѵ�.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
	});

	// ó������ ������ ������ ���� �ܾ ��������
	// ���� ��ġ�� ���� ��ġ�� �ܾ ���� ���� ã�´�.
	// if( �߰��ߴ� )
	//        �߰��� ��ġ���� ���� �ʴ� �ܾ ������ ��ġ�� ã�´�.

	int i = 1;
	vector<PS>::const_iterator j = v.begin(),
		end = v.end(), k;

	while (true) {
		j = adjacent_find(j, end, [](const PS& a, const PS& b) {
			return a.first == b.first;
		});

		if (j == end)
			break;
		k = find_if_not(j + 1, end, [j](const PS& a) {
			return a.first == j->first;
		});


		// ���� [j, k)�� anagram�̴�.
		cout << "[" << i++ << "] ";
		copy(j, k, ostream_iterator<string>(cout, " "));
		cout << endl;

		j = k;
	}

}


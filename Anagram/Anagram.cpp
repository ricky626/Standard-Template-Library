#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
//include는 사용하는 것만 넣자(컴파일 타임에 영향, 가독성)

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
	cout << "Anagram을 찾는 프로그램" << endl;

	ifstream ifs("diction");
	if (!ifs.is_open()) {    //잘 열렸나 검사
		cout << "파일 diction을 읽을 수 없습니다." << endl;
		exit(0);
	}

	vector<PS> v;
	v.reserve(20159);
	//string s;
	//while (ifs >> s)
	//    v.push_back(s);
	//STL에서는 반복문은 안쓸수 있으면 쓰지 않는 것을 권장

	copy(istream_iterator<string>(ifs),
		istream_iterator<string>(), back_inserter(v));
	cout << "모두 " << v.size() << "개의 단어를 읽었습니다. " << endl;

	//아이디어
	//읽은 단어와 그 단어를 정렬한 단어를 하나의 쌍으로 만든다.
	//v의 first 기준으로 정렬한다.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
	});

	// 처음부터 끝까지 정렬해 놓은 단어를 기준으로
	// 현재 위치와 다음 위치의 단어가 같은 것을 찾는다.
	// if( 발견했다 )
	//        발견한 위치부터 같지 않는 단어가 나오는 위치를 찾는다.

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


		// 구간 [j, k)는 anagram이다.
		cout << "[" << i++ << "] ";
		copy(j, k, ostream_iterator<string>(cout, " "));
		cout << endl;

		j = k;
	}

}


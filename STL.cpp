#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
using namespace std;

int compare(const void *a, const void *b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}


int main()
{
	int* a = new int[1000000];

	 난수생성 엔진과 난수확률 분포를 사용하여 생성한다.

	default_random_engine dre; // 기본 엔진 사용

							   normal_distribution<> nd(0, 1.0); //확률 분포
	uniform_int_distribution<> ui; // 모든 랜덤 수가 고르게 분포하도록 

	for (int i = 0; i < 1000000; i++)
	{
		a[i] = ui(dre);
	}

	auto test = compare;

	qsort(a, 1000000, sizeof(a[0]), test);


	ofstream out("백만개저장.txt");

	out.write((const char*)(a), sizeof(int) * 1000000);



	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
using namespace std;


int main()
{
	ifstream in("백만개저장.txt", ios::binary);

	int* a = new int[1000000];

	in.read((char*)a, 1000000);

	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}
	save();
}

#include <iostream>
#include <string>
#include "save.h"

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "save.h"
 새언어 특성 
 auto, 일관된 초기화, 범위 기반의 for loop
 이동문맥과 r-vaule 참조( 클래스 전체 복습 실습 )
 람다

using namespace std;

int main()
{
	vector : 동적 배열
	vector<string> v{ "오늘은", "3월", "14일", "화이트", "데이" };

	vector<string>::const_iterator it = v.begin();

	for (auto it = v.begin(); it < v.end(); ++it)
		cout << *it << endl;

	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int a[]{ 2, 4, 6, 1, 3, 5 };

	sort(&a[0], &a[6]);
	sort(begin(a), end(a), [](int a, int b) -> bool {

		return a > b;
	});


	for (auto d : a)
		cout << d << endl;

	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

class wizard
{
	string month;
	int number;

public:
	wizard(const string _month, const int _number) : month(_month), number(_number) {}

	string getmonth() const { return month; }
	int getnumber() const { return number; }

	void show()
	{
		cout << month << " - " << number << endl;
	}

};

int compare(const void *a, const void *b)
{
	string x = *(string*)a;
	string y = *(string*)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}

int reverse(const void* a, const void* b)
{
	string x = *(string*)a;
	string y = *(string*)b;

	if (x > y)
		return -1;
	else if (x < y)
		return 1;

	return 0;
}

ostream& operator<< (ostream& os, const wizard& w)
{
	os << w.getmonth() << " - " << w.getnumber() << endl;
	return os;
}

int main()
{
	마법사는 이름과 나이를 갖는다.

	wizard a[] = { wizard("2월", 20), wizard("1월", 10), wizard("7월", 3), wizard("3월", 5) };
	wizard a[] = { { "2월", 20 },{ "1월", 10 },{ "7월", 3 },{ "3월", 5 } };

	sort(begin(a), end(a), [](const wizard& a, const wizard& b) {
		return a.getmonth() < b.getmonth();

	});

	for (auto d : a)
		cout << d << endl;

	save();

}

class monster
{
private:
	string name;
	int num;

public:

	monster(string _name, int _num) : name(_name), num(_num) {}

	string getname() const { return name; }
	int getnum() const { return num; }
};

template <class t>


void change(t& a, t& b)
{
	t temp = a;
	a = b;
	b = temp;
}

ostream& operator<< (ostream& os, const monster& m)
{
	os << m.getname() << " - " << m.getnum() << endl;
	return os;
}

int main()
{
	monster x("빅뱅", 333), y("ogre", 777);

	change(x, y);

	cout << x << ends << y << endl;

	save();
}

#include <iostream>
#include <string>
#include "save.h"

using namespace std;

int compare(const void *a, const void *b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}

int main()
{
	int a[] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };

	 c함수 qsort를 이용하여 a를 정렬하시오

	qsort(a, 10, sizeof(a[0]), compare);

	for (auto d : a)
		cout << d << " "; //오름차순 정렬
	cout << endl;

	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
using namespace std;

int compare(const void *a, const void *b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}


int main()
{
	int* a = new int[1000000];

	 난수생성 엔진과 난수확률 분포를 사용하여 생성한다.

	default_random_engine dre; // 기본 엔진 사용

							   normal_distribution<> nd(0, 1.0); //확률 분포
	uniform_int_distribution<> ui; // 모든 랜덤 수가 고르게 분포하도록 

	for (int i = 0; i < 1000000; i++)
	{
		a[i] = ui(dre);
	}

	auto test = compare;

	qsort(a, 1000000, sizeof(a[0]), test);


	ofstream out("백만개저장.txt");

	out.write((const char*)(a), sizeof(int) * 1000000);



	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
using namespace std;


int main()
{
	ifstream in("백만개저장.txt", ios::binary);

	int* a = new int[1000000];

	in.read((char*)a, 1000000);

	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}
	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>
using namespace std;

 내림차순 정렬
int f(int a, int b)
{
	return a > b;
}


int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	c++에서는 a를 다음과 같이 정렬한다.

	sort(a, a + 10, f);

	for (auto d : a)
		cout << d << " ";
	cout << endl;
	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

 내림차순 람다 사용
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	c++에서는 a를 다음과 같이 정렬한다.

	sort(a, a + 10, [](int a, int b) //람다
	{
		return a > b;
	});

	for (auto d : a)
		cout << d << " ";
	cout << endl;
	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int a[]{ 2, 4, 6, 1, 3, 5 };

	sort(&a[0], &a[6]);
	sort(begin(a), end(a), [](int a, int b) -> bool {

		return a > b;
	});


	for (auto d : a)
		cout << d << endl;

	save();
}

#include <iostream>
#include <string>
#include "save.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

class wizard
{
	string month;
	int number;

public:
	wizard(const string _month, const int _number) : month(_month), number(_number) {}

	string getmonth() const { return month; }
	int getnumber() const { return number; }

	void show()
	{
		cout << month << " - " << number << endl;
	}

};

int compare(const void *a, const void *b)
{
	string x = *(string*)a;
	string y = *(string*)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;

	return 0;
}

int reverse(const void* a, const void* b)
{
	string x = *(string*)a;
	string y = *(string*)b;

	if (x > y)
		return -1;
	else if (x < y)
		return 1;

	return 0;
}

ostream& operator<< (ostream& os, const wizard& w)
{
	os << w.getmonth() << " - " << w.getnumber() << endl;
	return os;
}

int main()
{
	마법사는 이름과 나이를 갖는다.

	wizard a[] = { wizard("2월", 20), wizard("1월", 10), wizard("7월", 3), wizard("3월", 5) };
	wizard a[] = { { "2월", 20 },{ "1월", 10 },{ "7월", 3 },{ "3월", 5 } };

	sort(begin(a), end(a), [](const wizard& a, const wizard& b) {
		return a.getmonth() < b.getmonth();

	});

	for (auto d : a)
		cout << d << endl;

	save();

}

#include <iostream>
#include <string>
#include <vector>
#include "save.h"
 새언어 특성 
 auto, 일관된 초기화, 범위 기반의 for loop
 이동문맥과 r-vaule 참조( 클래스 전체 복습 실습 )
 람다

using namespace std;

int main()
{
	vector : 동적 배열
	vector<string> v{ "오늘은", "3월", "14일", "화이트", "데이" };

	vector<string>::const_iterator it = v.begin();

	for (auto it = v.begin(); it < v.end(); ++it)
		cout << *it << endl;

	save();


#include <iostream>
#include <string>
#include <vector>
	using namespace std;

	 통합된 초기화 (uniform initialization c++)
	
	 raii resource allocation 
	 more effective modern c++
	int gid{ 0 };
	class model
	{
		char* data{ nullptr };
		size_t size{ 0 };
		int id{ 0 };
	public:
		model()
		{
			id = gid++;
			cout << id << " 기본 생성자" << endl;
		};
		model(int _size) : size(_size)
		{
			data = new char[size];
			id = gid++;
			cout << id << " 크기를 갖는 생성자 " << size << endl;
		};
		model(const model& other) : size(other.size)
		{
			data = new char[size];
			데이터를 복사해온다.
			memcpy(data, other.data, size);
			대입 연산자를 만들었다면 복사생성을 간단하게 다음과 같이 쓸 수 있다.
			-this = other;
			id = gid++;
			cout << id << " 복사 생성자 " << size << endl;
		};
		model(model&& other) : data(nullptr), size(other.size), id(gid++)
		{ // && : r-value reference
			data = other.data;
			other.data = nullptr;
			other.size = 0;
			cout << id << " 이동생성자(기존 객체) " << size << " id " << other.id << endl;
		}
		 move assignment operator
		model& operator = (model&& other)
		{
			 자기 자신을 대입한다면 아무것도 안해도 된다.
			if (this == &other)
				return *this;
			 나는 원래 할당한 메모리가 있다면 지우자
			if (data != nullptr)
			{
				delete[] data;
			}
			 대입할 메모리와 같은 내용을 만든다.
			size = other.size;
			data = other.data;
			other.data = nullptr;
			other.size = 0;
			return *this;
		}
		~model()
		{
			if (data != nullptr)
				delete[] data;
			cout << id << " 소멸자 " << size << endl;
		}
		 assignment operator 대입 연산자
		model& operator = (const model& other)
		{
			 자기 자신을 대입한다면 아무것도 안해도 된다.
			if (this == &other)
				return *this;
			 내가 만든 메모리를 먼저 지워야 한다.
			if (data != nullptr)
				delete[] data;
			 대입할 메모리와 같은 내용을 만든다.
			size = other.size;
			data = new char[size];
			memcpy(data, other.data, size);
			cout << id << " 대입연산자 " << size << endl;
			return *this;
		}

	};
	int main()
	{
		model a;
		model b(1000);
		model c(b);
		a = c; // a.operator = (c); // 대입 연산자
		model a(1000);
		model b(move(a));
		model a(1000);
		model b(1234);
		a = move(b);
		vector<model> v;
		v.push_back(model(100));
		v.push_back(model(200));


	}

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
	using namespace std;
	 람다 이름없는 함수
	 함수를 프로그래머가 호출할 일이 없지만
	 함수의 기능(body)을 필요로 하는 곳에 사용함
	 [=]()
	
	 stl은 속도의 최적화된 라이브러리입니다.
	 이 말은 예외처리 따위는 하지 않는다는 이야기 입니다.
	 예외처리가 필요하다면 그렇게 해주는 특별버전의 라이브러리나 함수를 사용해야 합니다.
	 교재 81쪽 dynamic_cast
	class animal
	{
	public:
		virtual void move() = 0;
	};
	class dog : public animal
	{
	public:
		virtual void move() override final { cout << "개 뛴다." << endl; }
	};
	class bird : public animal
	{
	public:
		virtual void move() override final { cout << "새 난다." << endl; }
	};
	int main()
	{
		animal* a[3]{ new dog, new bird, new dog };
		for (animal* d : a)
		{
			if (dynamic_cast<dog*>(d) != nullptr) //개 일때만 for loop 돌도록
				d->move();
		}
	}

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <random>
#include <functional>
	using namespace std;
	 람다 이름없는 함수
	 함수를 프로그래머가 호출할 일이 없지만
	 함수의 기능(body)을 필요로 하는 곳에 사용함
	 [=]()
	
	 stl은 속도의 최적화된 라이브러리입니다.
	 이 말은 예외처리 따위는 하지 않는다는 이야기 입니다.
	 예외처리가 필요하다면 그렇게 해주는 특별버전의 라이브러리나 함수를 사용해야 합니다.
	 교재 81쪽 dynamic_cast
	  if (dynamic_cast<bird*>(d) != nullptr) //개 일때만 for loop 돌도록
	   d->move();
	class animal
	{
	public:
		virtual void move() = 0;
	};
	class dog : public animal
	{
	public:
		virtual void move() override final { cout << "개 뛴다." << endl; }
	};
	class bird : public animal
	{
	public:
		virtual void move() override final { cout << "새 난다." << endl; }
	};
	void f(animal& a)
	{
		 만일 a가 원래 개였다면 move()를 호출하라

		if (dynamic_cast<dog*>(&a) != nullptr)
		{
		 a.move();
		}
		dog d;
		try
		{
			d = dynamic_cast<dog&>(a);
			d.move();
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
	int main()
	{
		animal* a[3]{ new dog, new bird, new dog };
		for (animal* d : a)
		{
			f(*d);
		}
	}
	 호출 가능 타입(callable type)
	 1. 함수
	 2. 멤버 함수
	 3. 함수 객체 : 함수 호출연산자를 오버로딩한 클래스
	 4. 람다
	 5. function class
	 6. bind
	class march
	{
	public:
		bool operator()(const int a, const int b) { return a > b; };
	};
	int main()
	{
		int a[]{ 2, 4, 6, 1, 3, 5 };
		sort(begin(a), end(a), march());
		for (int d : a)
			cout << d << ends;
		cout << endl;
	}
	 6. bind : 원래 함수의 인자 갯수를 바꾼 새 함수를 만들어 준다.#include <functional>
	int add(int a, int b)
	{
		return a + b;
	}
	int main()
	{
		auto f = bind(add, 5, 10);
		cout << f() << endl;
	}
	 pair<>, 스마트 포인터, tyep traits 5장
	 pair : 이종(heterogeneous)의 자료형을 하나로 묶어 사용할 수 있도록 한다.
	int main()
	{
		 이름과 현상금
		pair<string, int> onepiece[]{ { "루피", 400 },{ "조로", 300 },{ "상디", 100 } };

		sort(begin(onepiece), end(onepiece), [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.first < b.first;
		});
		for (pair<string, int> d : onepiece)
		{
			cout << "이름 순 : " << d.first << ends << d.second << endl;
		}
		sort(begin(onepiece), end(onepiece), [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.second < b.second;
		});
		for (pair<string, int> d : onepiece)
		{
			cout << "현상금 순 : " << d.first << ends << d.second << endl;
		}
	}
	 pair<>, 스마트 포인터, tyep traits 5장
	 pair : 이종(heterogeneous)의 자료형을 하나로 묶어 사용할 수 있도록 한다.

	int main()
	{
		 pair<double, double> point2d;
		 2차원 좌표 100개(-100 ~ 100 사이값)를 생성하자
		 원점에서 반경 10이내인 점들만 화면에 출력
		pair<double, double> point2d[100];
		default_random_engine dre;
		uniform_int_distribution<> ui(-100, 100);

		for (auto& d : point2d)
		{
			d.first = ui(dre);
			d.second = ui(dre);
		}
		double d;
		for (int i = 0; i < 100; ++i)
		{
			d = sqrt(point2d[i].first * point2d[i].first + point2d[i].second * point2d[i].second);
			if (d < 40.0)
			{
				cout << point2d[i].first << ends << point2d[i].second << endl;
			}
		}
	}

	 스마트 포인터 - 자신이 획득한 자원을 자신이 소멸될 때 해제해 주는 포인터
	 p = new int[100]; - 획득한 자원 -> 포인터가 사라질 때 헤제
	 c++11 에서는 unique_ptr - 자원을 독점하는 포인터 // shared_ptr - 자원을 공유하는 포인터
	
	 포인터 -
	 1. 자원을 획득한다.(heap)
	 2. 자원을 이용한다.
	 3. 반환한다.
	
	 5.3 numeric_limits
	 5.4 type traits
	 
	 템플릿 코드에서는 전달된 인자의 타입을 구분할 필요가 있다.
	 인자의 타입을 구분하기 위해 type traits을 이용한다. 교재 167쪽
	class mini
	{
	public:
		mini() { cout << "생성자 " << endl; }
		~mini()
		{
			cout << "소멸자" << endl;
		}
		void f() { cout << "멤버 함수" << endl; }
	};

	template <class t>
	void f(t t)
	{
		f(t, is_pointer<t>());
	}

	template<class t>
	void f(t t, true_type)
	{
		cout << *t << endl;
	}

	template<class t>
	void f(t t, false_type)
	{
		cout << t << endl;
	}

	int main()
	{
		 자원을 독점하는 포인터 unique_ptr
		 레퍼런스를 카운팅하는 포인터 shared_ptr
		unique_ptr<mini> p(new mini);
		unique_ptr<mini> q = move(p);
		shared_ptr<mini> p(new mini);
		shared_ptr<mini> q = p;
		shared_ptr<mini> a = q;
		shared_ptr<mini> b = a;
		shared_ptr<mini> c = b;
		shared_ptr<mini> d = c;
		cout << numeric_limits<int>::min() << endl;
		cout << numeric_limits<int>::max() << endl;

		 어떤 함수가 있는데 넘겨주는 값이 포인터이면 그것이 가리키는 값을
		 그냥 값이라면 그 값을 출력하는 함수를 작성하고 싶다.
		int n{ 100 };
		int* p{ &n };
		f(n); // 100
		f(p); // 100


	}

#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
	using namespace std;



	int main()
	{
		 정수 10개를 담는 array를 만들어 보자
		array<int, 10> a{};
		vector<int> a{};
		list<int> a{ 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
		set<int> a{ 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };

		sort(a.begin(), a.end(), [](const int a, const int b) {
			return a > b;
		});

		for (int i = 0; i < a.size(); ++i)
			cout << a[i] << endl;

		for (auto i = a.begin(); i != a.end(); ++i)
		{
			cout << *i << endl;
		}

	}

	int main()
	{
		set<string> v;

		copy(istream_iterator<string>(cin), istream_iterator<string>(), inserter(v, v.begin()));
		copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));

	}

	int main()
	{
		vector<pair<string, int>> v;

		using score = pair<string, int>;

		vector<score> v;

		v.push_back(make_pair<string, int>("asfd", 124));
		v.push_back({ "abc", 2121 });

		sort(v.begin(), v.end(), [](const score& a, const score& b) {
			return a.second < b.second;
		});

		 stl 반복자를 이용한 컨테이너 원소 접근
		vector<score>::iterator i = v.begin();

		for (; i < v.end(); ++i)
			cout << i->first << i->second << endl;
	}

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
#include <list>
#include <set>
	using namespace std;

	int main()
	{
		using score = pair<string, int>;
		vector<score> v;

		v.reserve(10000);

		time_t system_time = time(0);
		default_random_engine dre(system_time);
		uniform_int_distribution<> ui(0, 10000);
		char buf[10];
		for (int i = 0; i < 10000; ++i)
		{
			v.push_back({ string("이름") + itoa(i + 1, buf, 10), ui(dre) });
			cout << v[i].first << ends << v[i].second << endl;
		}
		auto p = find_if(v.begin(), v.end(), [](const score& a)
		{
			if (a.second == 5000)
			{
				return true;
			}
			return false;
		});

		if (p != v.end())
		{
			auto f = p - v.begin();
			cout << p->first << ends << p->second << "찾음" << endl;
			cout << v[f].first << ends << v[f].second << "찾음" << endl;
		}

		else
			cout << "없음" << endl;
	}
	class april
	{
	public:
		april() { cout << "생성자" << endl; }
		~april() { cout << "소멸자" << endl; }
		april(const april& other) { cout << "복사생성자" << endl; }

	};
	int main()
	{
		vector<april> v;
		v.push_back(april());
		cout << "메인함수 끝" << endl;
		vector<april> v;
		april a;
		v.push_back(a);

		cout << "메인함수 끝" << endl;

		vector<april> v;
		v.reserve(3);
		v.emplace_back();
		v.emplace_back();
		cout << endl << "메인 함수 " << endl << endl;

		리스트에 a ~ z를 넣어보자

		list<char> clist;
		for (char i = 'a'; i <= 'z'; ++i)
		{
			clist.push_back(i);
		}
		 'o'위치에 3번 'a', 'b', 'c'를 삽입해보자.
		auto p = find(clist.begin(), clist.end(), 'o');
		clist.insert(p, 'a');
		clist.insert(p, 'b');
		clist.insert(p, 'c');

		for (auto i = clist.begin(); i != clist.end(); ++i)
			cout << *i << endl;

		for (auto d : clist)
			cout << d << endl;


		 연관 컨테이너 set<int>에 랜덤 정수 100개 넣어보자.

		time_t system_time = time(0);
		default_random_engine dre(system_time);
		uniform_int_distribution<> ui(0, 10000);

		set<int> s;
		for (int i = 0; i < 100; ++i)
		{
			s.insert(ui(dre));
		}
		for (auto d : s)
			cout << d << endl;
	}

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <fstream>
#include <algorithm>
	using namespace std;
	 반복자(iterator)
	 컨테이너가 자신의 원소(private)를 순회할 수 있도록 제공하는 마치 포인터처럼 사용할 수 있는 인터페이스이다.
	
	 컨테이너의 멤버함수
	  begin() - 컨테이너의 처음 원소를 가리킨다.
	  end() - 컨테이너의 마지막 원소를 하나 지난 원소를 가리킨다.
	
	
	 반복자로 할 수 있는 연산
	  *  - 역참조(dereferancing operator)
	  ++ - 다음원소로 이동한다.
	  == - 반복자끼리 비교한다.
	
	 반복자의 종류(category)
	
	 stl 표준 컨테이너가 제공하는 반복자는 다음 카테고리 중 하나이다.
	 1. 순방향(forward) 반복자    forward_list
	 2. 양방향(bidirectional) 반복자  list
	 3. 랜덤 액세스(random access) 반복자 array, vector, deque
	 그 외에
	 4. 입력 반복자
	 5. 출력 반복자

	int main()
	{
		set<int> s;
		for (int i = 0; i < 100; ++i)
			s.insert(rand() % 100);
		for (auto d : s)
			cout << d << endl;

		auto p = s.find(94);
		if (p != s.end())
			cout << "찾음" << endl;
		set <int, greater<int>> s; // greater : 내림차순 // less : 오름차순
		for (int i = 0; i < 100; ++i)
			s.insert(rand() % 100);

		for (auto d : s)
			cout << d << ends;
		연관 컨테이너 map map<key, value>
		using data = pair<string, int>;
		multimap<string, int> m{ data("ttt", 111), {"fdadf", 70}, make_pair("dfdfdf", 23)};
		map<string, int> m{ data("ttt", 111),{ "fdadf", 70 }, make_pair("dfdfdf", 23) };
		m.insert({ "ttt", 99 });
		m.insert(make_pair("aaa", 24));
		m.insert(data("rda", 8));
		auto p = m.begin();
		++p;
		++p;
		++p;
		p->second = 77777;
		m["ttt"] = 77777;
		 map은 subscript operator를 overloading 한다.
		 사용자는 map을 연관 배열(associative array)처럼 사용할 수 있다.
		m["어머니"] = 1; // 새로운것을 insert할 수도 있다.
		m.operator[]("철수") = 333; // 새로운것을 insert하거나 key값의 value를 변경할 수도 있다.
								   map을 정수순으로 정렬할순 없다. 굳이 하자면 새로 맵을 만들어서 정수 순으로 정렬해야한다.
		map<int, string> mm;
		auto p = m.begin();
		for (int i = 0; i < m.size(); ++i, ++p)
		{
			mm.insert({ p->second, p->first });
		}

		for (auto d : mm)
			cout << d.first << ends << d.second << endl;
		현재 파일에 있는 문자의 빈도수를 출력하라.
		ifstream ifs("파일저장.txt");
		string str;
		map<char, int> m;

		string s("1234567890");

		for (auto p = s.rbegin(); p != s.rend(); ++p)
		{
			cout << *p << ends;
		}
		cout << endl;
	}

	 알고리즘 (250쪽)
	
	 알고리즘은 제네릭한 전역함수이다.
	 알고리즘의 인자는 반복자 구간이다.
	 함수의 이름은 동사(verb)이다.
	 모든 알고리즘이 항상 효율적일 수는 없다.
	
	
	
	
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
	using namespace std;

	int main()
	{
		vector<int> v(10, 1); // 1이 10개 들어간다.

		multiset<int> s;

		for (int i = 0; i < 10; ++i)
			s.insert(i);

		for (auto d : s)
			cout << d << ends;
		cout << endl;

		auto p = find(s.begin(), s.end(), 1);

		if (p == s.end())
			cout << "ok" << endl; *-

			auto p = s.find(3);

		if (p == s.end())
			cout << "back" << endl;
		else
			cout << *p << "find" << endl;

	}
	template<class iter, class val>

	iter myfind(iter begin, iter end, const val& val)
	{
		while (begin != end)
		{
			if (*begin == val)
				return begin;

			++begin;

		}
		return begin;
	}


	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		auto p = myfind(v.begin(), v.end(), 3);

		if (p != v.end())
			cout << "찾음" << ends << *p << endl;
		else
			cout << "못찾음" << endl;
	}

	template<class iter, class val>

	iter myfind(iter begin, iter end, const val& val)
	{

		for (iter temp = begin; temp < end; ++temp)
		{
			if (*temp == val)
				return temp;
		}

		return end;

		while (begin != end)
		{
			if (*begin == val)
				return begin;

			++begin;

		}
		return begin;
	}


	int main()
	{
		string s("abcdefghijklmnopqrstuvwxyz");

		 s에서 m을 찾아서 m으로 바꿔라 myfind를 써서
		auto p = myfind(s.begin(), s.end(), '0');

		if (p != s.end())
			*p = 'm';

		cout << s << endl;

	}

	template<class iter>
	iter mymin_element(iter begin, iter end) // 최소값 찾기
	{
		iter min = begin;

		while (begin != end)
		{
			if (*begin < *min)
				min = begin;

			++begin;
		}

		return min;
	}

	int main()
	{
		vector <int> v{ 1, 3, 5, 7, 9 };

		cout << *mymin_element(v.begin(), v.end());
	}
	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9 };
		vector<int> vcopy(v.size());


		copy 알고리즘 함수는 하나의 구간을 다른 구간으로 복사한다.

		copy(v.begin(), v.end(), vcopy.begin());


		for (auto d : vcopy)
			cout << d << ends;
		cout << endl;
	}
#include <iterator>
	template<class iter, class dest>
	void mycopy(iter begin, iter end, dest dest)
	{
		while (begin != end)
		{
			dest.operator*() = begin.operator*();
			dest.operator++();
			begin.operator++();

			-dest++ = *begin++; 연산자 오버로딩
		}
	}

	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9 };
		vector<int> vcopy;

		copy 알고리즘 함수는 하나의 구간을 다른 구간으로 복사한다.
		mycopy(v.begin(), v.end(), back_inserter(vcopy));
		for (auto d : vcopy)
			cout << d << ends;
		cout << endl;
	}

	숙제1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

	using namespace std;

#define max 10000

	void printall(vector<pair <string, int>> v)
	{
		for (auto d : v)
			cout << d.first << ends << d.second << endl;
		cout << endl;
	}

	int main()
	{
		using data = pair<string, int>;

		vector<data> v; // 실제 데이터가 들어갈 vector


		time_t system_time = time(0);
		default_random_engine dre(system_time); // 기본 엔진 사용
		uniform_int_distribution<> ui(0, 1000); // 점수 범위
		uniform_int_distribution<> nui(5, 10); // 아이디의 길이
		uniform_int_distribution<> stui(65, 90); // 알파벳 범위 설정

		string str = ""; // id가 될 문자열을 담는 변수
		int max = 0; // 아이디의 길이에 대한 정보를 담는 변수
		double mynumber = -1; // 나의 순위를 나타낼 변수

		ofstream ofs("파일저장.txt");


		for (int i = 0; i < max; ++i)
		{
			문자열 초기화
			str = "";
			 id의 길이를 랜덤하게 설정
			max = nui(dre);

			for (int j = 0; j < max; ++j)
			{
				 문자열을 랜덤한 길이로 생성
				str += stui(dre);
			}

			 vector에 대입
			v.push_back({ str, ui(dre) });

			 저장할 파일에 저장
			ofs << v[i].first << endl << v[i].second << endl;
		}

		저장한 파일을 닫는다.
		ofs.close();

		ifstream ifs("파일저장.txt");
		vector<data> readv; // 파일에 저장된 것을 읽어와서 저장할 vector


		cout << "**파일 읽기**" << endl;

		string s = "";
		int n = 0;

		for (int i = 0; i < max; ++i)
		{
			ifs >> s;
			ifs >> n;
			readv.push_back({ s, n });
			cout << readv[i].first << ends << readv[i].second << endl;
		}

		cout << "**파일 읽기**" << endl << endl;
		ifs.close();


		나의 대한 정보를 넣어줌
		vector<data> my; // 나의 점수가 들어갈 vector
		my.push_back({ v[0].first, v[0].second });


		 id를 기준으로 오름차순 정렬
		sort(v.begin(), v.end());

		cout << "**id를 기준으로 오름차순 정렬**" << endl;
		printall(v); // 출력

					  점수를 기준으로 내림차순 정렬
		sort(v.begin(), v.end(), [](const data& a, const data& b) {
			return a.second > b.second;
		});

		cout << endl << "**점수를 기준으로 내림차순 정렬**" << endl;
		printall(v); // 출력


					  나의 현재 순위는 몇번째인지 검사
		for (int i = 0; i < max; ++i)
		{
			if (my[0].first == v[i].first)
			{
				mynumber = i + 1;
				break;
			}
		}

		 내 점수를 기준으로 위로 10개 아래로 10개를 판별
		int nummin = (mynumber <= 10) ? 0 : (mynumber - 1) - 10;
		int nummax = (mynumber >= max - 10) ? max : mynumber + 10;

		cout << "**내 점수를 기준으로 위로 10개 데이터 표시**" << endl;
		for (int i = nummin; i < mynumber - 1; ++i)
			cout << v[i].first << ends << v[i].second << "  " << i + 1 << "위" << endl;
		cout << endl;

		cout << "**내 점수를 기준으로 아래로 10개 데이터 표시**" << endl;
		for (int i = mynumber; i < nummax; ++i)
			cout << v[i].first << ends << v[i].second << "  " << i + 1 << "위" << endl;
		cout << endl;

		cout << endl << "나의 id : " << my[0].first << ends << my[0].second << endl;
		cout << "나의 순위 : " << mynumber << "위" << endl;

		 상위 몇 %인지 계산
		double d = mynumber / max * 100;

		cout << "상위 : " << d << "% 입니다." << endl << endl;


	}

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>
#include <vector>

	using namespace std;

	class treasure
	{
		string name = "특급";
		int rank{ 0 };
		int mag{ 0 };
		int coin{ 0 };
	public:
		treasure() {}
		~treasure() {  }
		treasure(string name, int rank, int mag, int coin) : name(name), rank(rank), mag(mag), coin(coin) { }

		getter
		string getname() const { return name; }
		int getrank() const { return rank; }
		int getmag() const { return mag; }
		int getcoin() const { return coin; }
	};


	void print(list<treasure> box, int step, int count)
	{
		auto p = box.begin();
		for (int i = 0; i < step; ++i)
			++p;
		for (int i = 0; i < count; ++i, ++p)
			cout << p->getname() << ends << p->getrank() << ends << p->getmag() << ends << p->getcoin() << endl;
	}

	ostream &operator <<(ostream &out, const list<treasure> &box)
	{
		for (auto i = box.begin(); i != box.end(); ++i)
		{
			out << i->getname() << ends << i->getrank() << ends << i->getmag() << ends << i->getcoin() << endl;
		}
		return out;
	}

	istream &operator >> (istream& in, list<treasure> &box)
	{
		char buf[10];
		char rank[10];
		char mag[10];
		char coin[10];
		int max = 0;
		string line;
		int i = 0;

		in >> max;


		while (i < 500)
		{
			in.read(buf, 6);

			in.read(rank, 4);
			in.read(mag, 4);
			in.read(coin, 4);


			i++;
		}


		return in;
	}

	int main()
	{
		list<treasure> box;

		default_random_engine dre;
		uniform_int_distribution<> ui(0, 20);

		string name = "특급";
		char buf[10];

		다음과 같이 한 개의 보물을 생성할 수 있다.
		treasure(name, ui(dre), ui(dre), ui(dre));

		 보물함에 보물 500개를 넣어라

		for (int i = 0; i < 500; ++i)
		{
			box.push_back({ name, ui(dre), ui(dre), ui(dre) });
		}


		 보물함의 내용을 지정한 위치에서부터 지정한 갯수를 출력하는 함수 print()
		print(box, 20, 5);

		 능력의 합계순으로 정렬된 보물함


		box.sort([](const treasure& a, const treasure& b) {
			int aa = a.getrank() + a.getmag() + a.getcoin();
			int bb = b.getrank() + b.getmag() + b.getcoin();
			return aa > bb;
		});

		print(box, 0, 10);


		auto p = find_if(box.begin(), box.end(), [](treasure a) {
			return (a.getcoin() + a.getmag() + a.getrank() == 30);
		});

		size_t size = distance(box.begin(), p) / 2;

		if (p != box.end())
		{
			for (int i = 0; i < 5; ++i, ++p)
			{
				cout << p->getname() << ends << p->getrank() << ends << p->getmag() << ends << p->getcoin() << endl;
			}
			cout << "*****" << p->getname() << ends << p->getrank() << ends << p->getmag() << ends << p->getcoin() << endl;
			++p;
			for (int i = 0; i < 5; ++i, ++p)
			{
				cout << p->getname() << ends << p->getrank() << ends << p->getmag() << ends << p->getcoin() << endl;
			}
		}

		ofstream out("보물함.txt");
		out << box.size() << endl;
		out << box;
		out.close();

		box.clear();

		ifstream in("보물함.txt");

		in >> box;

		cout << "보물의 수 : " << box.size() << endl;


		print(box, 0, 10);
	}

#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <algorithm>
#include <fstream>

	using namespace std;

	class cherry
	{
		int x{ 0 }, y{ 768 };
		int speed{ 0 };
		bool alive{ true };

	public:
		cherry(int x, int y, int speed) : x(x), y(y), speed(speed) {}

		getter

		pair<int, int> getxy() const { return make_pair(x, y); }
		int getspeed() const { return speed; }
		bool isalive() const { return alive; }

		void render()
		{
			cout << "꽃잎" << "{" << x << ends << y << ")" << endl;
		}

		void update()
		{
			if (alive)
				y -= speed;
			if (y < 0)
				alive = false;
		}
	};

	void print(list<cherry> box, int step, int count)
	{
		auto p = box.begin();
		for (int i = 0; i < step; ++i)
			++p;

		for (int i = 0; i < count; ++i, ++p)
			p->render();//cout << p->getname() << ends << p->getrank() << ends << p->getmag() << ends << p->getcoin() << endl;
	}

	ostream &operator <<(ostream &out, const list<cherry> &box)
	{
		for (auto i = box.begin(); i != box.end(); ++i)
		{
			out << i->getxy().first << ends << i->getxy().second << ends << i->getspeed() << endl;//out << i->getname() << ends << i->getrank() << ends << i->getmag() << ends << i->getcoin() << endl;
		}
		return out;
	}

	int main()
	{
		list<cherry> data;

		default_random_engine dre;
		uniform_int_distribution<> dx(0, 1023);
		uniform_int_distribution<> dspeed(1, 10);

		꽃잎 하나 생성
		cherry(dx(dre), 0, dspeed(dre));

		for (int i = 0; i < 100; ++i)
		{
			data.emplace_back(dx(dre), 768, dspeed(dre));
		}

		print(data, 5, 10);


		int n = 10;
		while (0 < n)
		{
			list<cherry>::iterator p;

			 리스트의 모든 원소를 반복자 p를 사용하여 순회하면서 render() 와 update를 호출하라.
			p = data.begin();

			for (int i = 10; i > 0; --i)
			{
				if (n / i == 0)
					++p;
			}

			p->render();
			p->update();
			++p;

			--n;
		}

		n = 70;

		while (0 < n)
		{
			 범위기반 for lopp를 사용하여 리스트 원소의 render()와 update()를 호출하라. 실제 꽃잎의 위치가 변경되어야한다.
			for (auto i = data.begin(); i != data.end(); ++i)
			{
				i->update();
				i->render();
			}

			--n;
		}

		y를 기준으로정렬하라
		data.sort([](const cherry& a, const cherry& b) {
			return a.getxy().second < b.getxy().second;
		});

		print(data, 0, 10);

		 정렬된 리스트에서 속도가 9인 꽃잎을 찾아서 앞뒤로 5개씩 출력하라.

		auto p = find_if(data.begin(), data.end(), [](const cherry &a) {
			return (a.getspeed() == 9);
		});

		size_t size = distance(data.begin(), p) / 2;

		if (p != data.end())
		{
			for (int i = 0; i < 5; ++i, ++p)
			{
					p->render();
				cout << p->getspeed() << endl;
			}

			cout << "*****" << ends;
			p->render();
			cout << p->getspeed() << endl;
			++p;

			for (int i = 0; i < 5; ++i, ++p)
			{
				p->render();
				cout << p->getspeed() << endl;
			}
		}


		data.remove_if([](const cherry& a) {
			if (a.getxy().second < 0)
				return true;
			return false;
		});

		print(data, 0, 7);

		ofstream out("중간결과.txt");
		out << data;


	}

#include <iostream>
#include <random>
#include <algorithm>
#include <list>
#include <cmath>
#include <fstream>
#include <string>
	using namespace std;
	class zombie
	{
		int x, y;
		int hp{ 100 };
		bool alive;
	public:
		zombie(int x, int y) : x(x), y(y), hp(100), alive(true) {}
		zombie(int x, int y, int hp) : x(x), y(y), hp(hp), alive(true) {}
		getter
		int getx() const { return x; }
		int gety() const { return y; }
		int gethp() const { return hp; }
		bool isalive() const { return alive; }
		void render() const
		{
			cout << "위치(" << getx() << ", " << gety() << ") hp : " << gethp() << endl;
		}
		void dechp(int n)
		{
			hp -= n;
			if (hp <= 0)
				alive = false;
		}
	};
	void print(list<zombie> data, int step)
	{
		auto p = data.begin();
		int i = 0;
		for (; i < step - 5; ++i)
			++p;
		cout << "좀비의 수 : " << data.size() << endl;
		for (int j = 0; j < 5; ++j, ++i, ++p)
		{
			cout << i << ends;
			p->render();
		}

		cout << "***" << i << "***" << ends;
		p->render();
		++p;
		++i;
		for (int j = 0; j < 5; ++j, ++i, ++p)
		{
			cout << i << ends;
			p->render();
		}


	}
	ostream &operator <<(ostream &out, const list<zombie> &data)
	{
		for (auto i = data.begin(); i != data.end(); ++i)
		{
			out << i->getx() << ends << i->gety() << ends << i->gethp() << endl;
		}
		return out;
	}

	istream &operator >> (istream& in, list<zombie> &data)
	{
		int x;
		int y;
		int hp;
		char buf;
		int i = 0;
		while (!in.eof())
		{
			in >> x;
			in >> buf;
			in >> y;
			in >> buf;
			in >> hp;
			data.emplace_back(x, y, hp);

		}
		return in;
	}
	int main()
	{
		list<zombie> data;
		default_random_engine dre;
		uniform_int_distribution<int> di(-1000, 1000);
		for (int i = 0; i < 100; ++i)
		{
			data.emplace_back(di(dre), di(dre));
		}
		print(data, 8);

		int bx = 409, by = 200; // 폭탄위치
		double dist; // 폭탄과 좀비의 거리
		for (auto i = data.begin(); i != data.end(); ++i)
		{
			dist = sqrt((bx - i->getx()) * (bx - i->getx()) + (by - i->gety() * (by - i->gety()))); // 거리

			if (dist <= 0)
			{
				i->dechp(100);
			}

			i->dechp(10000 / dist);
		}

		data.sort([](const zombie& a, const zombie& b){
		 return a.gethp() < b.gethp();
		});
		data.remove_if([](const zombie& a) {
			if (!a.isalive())
				return true;
			return false;
		});
		int size = 100 - data.size();

		for (int i = 0; i < size; ++i)
		{
			data.insert(data.begin(), { di(dre), di(dre) });
		}
		print(data, 6);
		ofstream out("좀비저장.txt");
		out << data;
		out.close();
		data.clear();
		cout << endl;
		cout << "현재 좀비 수는 : " << data.size() << endl;
		ifstream in("좀비저장.txt");
		in >> data;
		in.close();
		print(data, 95);

	}


#include <iostream>
#include <vector>
#include <iterator>
	using namespace std;
	class data
	{
		int n;
	public:
		data() {}
		data(int n) : n(n) {}
		int operator*() {}
		int operator++() {}
	};
	template<class iter, class dest>
	void my_copy(iter begin, iter end, dest dest)
	{
		while (begin != end)
		 *dest++ = *begin++;
		while (begin != end)
		{
			(dest.operator++(1)).operator*() = (begin.operator++(1234242)).operator*();
			dest.operator*() = begin.operator*();
			dest.operator++();
			begin.operator++();
			*dest++ = *begin++;

		}
	}

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };
		vector<int> v2;

		 my_copy 세번째 인자인 back_inserter는 반복자 어댑터이다.
		 반복자에 요구되는 동작인 *, ++, == 등을 구현한 클래스이다.
		 back_inserter는 값을 쓰려는 동작을 값을 삽입하는 동작으로 구현한다.
		my_copy(v.begin(), v.end(), back_inserter(v2));
		my_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

		back_insert_iterator<vector<int>> p(v2);
		*p = 333; // p.operator*(333)
				   p.operator*(333)
				  {
				    p.push_back( 333 );
				  }
		cout << v2[0] << ends;
	}

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
	using namespace std;
	template<class iter, class dest>
	void my_copy(iter begin, iter end, dest dest)
	{
		while (begin != end)
		{
			dest.operator*() = begin.operator*();
			dest.operator++();
			begin.operator++();
			(dest.operator*()).operator = (begin.operator*());
			dest.operator++();
			begin.operator++();
		}
	}
	using my_back_inserter = back_insert_iterator<vector<int>> ;

	template<class cont>
	class my_back_inserter
	{
		cont* cont;
	public:
		my_back_inserter(cont& v)
		{
			cont = &v;
		};
		my_back_inserter& operator*()
		{
			return *this;
		}
		void operator++()
		{
		}
		void operator=(int n)
		{
			cont->emplace_back(n);
		}
	};

	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9 };
		list<int> v2;
		my_back_inserter<list<int>> p(v2);
		my_copy(v.begin(), v.end(), p);

		for (auto d : v2)
			cout << d << ends;
		cout << endl;
	}

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
	using namespace std;
	template<class iter, class dest>
	void my_copy(iter begin, iter end, dest dest)
	{
		while (begin != end)
		{
			/ -dest.operator*() = begin.operator*();
			dest.operator++();
			begin.operator++(); *-
				(dest.operator*()).operator = (begin.operator*());
			dest.operator++();
			begin.operator++();
		}
	}
	using my_back_inserter = back_insert_iterator<vector<int>> ;

	template<class cont>
	class my_back_inserter
	{
		cont* cont;
	public:
		my_back_inserter(cont& v)
		{
			cont = &v;
		};
		my_back_inserter& operator*()
		{
			return *this;
		}
		void operator++()
		{
		}
		void operator=(int n)
		{
			cont->emplace_back(n);
		}
	};

	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9 };
		list<int> v2;
		my_back_inserter<list<int>> p(v2);
		my_copy(v.begin(), v.end(), p);

		for (auto d : v2)
			cout << d << ends;
		cout << endl;
	}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>
	using namespace std;

	int main()
	{
		list<int> v{ 1, 2, 3, 4, 5, 6 };


		 문제 v에서 짝수를 지워주세요.
		 짝수라는 조건을 찾아서 지워야하므로 remove_if

		 리스트의 요소를 remove를 호출한다면 알고리즘은 지금 컨테이너가 리스트인지 모르기 때문에 

		v.remove_if([](int a) {
			return !(a & 1);
		});

		auto p = remove_if(v.begin(), v.end(), [](int a) {

			return a & 1;
			return a % 2 == 0;
		});

		v.erase(p, v.end());


		for (auto d : v)
			cout << d << ends;
		cout << endl;
	}
	template < class iter, class call >
	void foreach(iter begin, iter end, call func) // 콜러블 타입
	{
		for (; begin != end; ++begin)
		{
			func(*begin);
		}

		while (begin != end)
		{
			func(*begin++);
		}
	}

	void print(int n)
	{
		cout << n << ends;
	}

	int main()
	{
		list<int> coll{ 1, 2, 3, 4, 5, 6 };

		 모든 원소 출력
		 호출할 수 있는 것이라면 뭐든지 인자로 전달 가능하다.
		foreach(coll.begin(), coll.end(), print);
		cout << endl;
	}
	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6 };
		list<int> l{ 1, 2, 3, 4, 5, 6 };

		vector<int> c;
		 v*c의 결과를 화면에 출력하시오
		 함수 하나만 사용할 것.

		transform(v.begin(), v.end(), l.begin(), back_inserter(c), [](int a, int b) {
			return a* b;
		});

		transform(v.begin(), v.end(), l.begin(), ostream_iterator<int>(cout, " "), [](int a, int b) {
			return a* b;
		});


	}
		미리 정의되어 있는 함수 객체(291)
	class game
	{
		int n{ 0 };
	public:
		game() {}
		game(int n) : n(n) {}

		bool operator<(const game& g) const
		{
			return n < g.n;
		}

		int getn() const { return n; }

		operator int() const { return n; }
	};

	int main()
	{
		set<game, less<game>> s{ 1, 2, 3, 4, 5, 6 };

		for (auto d : s)
			cout << d << ends;

	}
	 바인더 binder
#include <deque>
#include <functional>
	int main()
	{
		set<int, greater<int>> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		deque<int> d;
		 transform을 써서 co11의 모든 원소를 coll2의 원소를 옮기면서 10을곱한다.
		transform(s.begin(), s.end(), back_inserter(d), [](int a) {
			return a * 10;
		});
		for (auto a : d)
			cout << a << ends;
		cout << endl;
	}

#include <iostream>
#include <vector>
#include <algorithm>

	using namespace std;

	class dog
	{
		int age;
	public:
		dog(int age) : age(age) {}

		int getage() const { return age; }

	};

	class test
	{
	public:
		bool operator()(const dog& a)
		{
			if (a.getage() >= 7)
				return true;
			return false;
		}
	};

	bool f(const dog& a)
	{
		return (a.getage() >= 7);
	}

	int main()
	{
		 조건에 맞는 객체가 몇 개 있는지 찾아보세요.
		 나이가 7살 이상인 객체가 몇 개 있는지 찾아보세요.

		vector<dog> v{ 5, 7, 3, 6, 9 };

		 1. 일반함수를 조건자로 사용

		int count = count_if(v.begin(), v.end(), f);

		 2. 람다를 조건자로 사용

		int count = count_if(v.begin(), v.end(), [](const dog& a)
		{
		 return (a.getage() >= 7);
		});

		 3. 함수객체를 조건자로 사용


		int count = count_if(v.begin(), v.end(), test());





		cout << count << endl;



	}
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
	using namespace std;
	class dog
	{
		int age;
	public:
		dog() {}
		dog(int age) : age(age) {}
	};
	int main()
	{
		vector<dog> v{ 1, 2, 3, 4, 5 };
		vector<dog> u{ 1, 2, 3, 4, 5, 6, 7 };
		vector<dog> u(move(v)); // 이동 생성
		vector<dog> u = move(v); // 이동 생성
		vector<dog> u = (vector<dog>&&) v; // 이동 생성
		u = v;
		cout << v.size() << ends;
		cout << u.size();
		vector<dog> v{ 1, 2, 3, 4, 5 };
		v.~vector<dog>();
		cout << v.size();
		vector<dog> v{ 1, 2, 3, 4, 5 };
		vector<dog> u;
		u.swap(v);
		v.erase(v.begin(), v.end());

		v.~vector<dog>();
		cout << u.capacity() << endl;
		cout << v.capacity() << endl;

		vector<dog> v(100, dog(10)); // dog객체 1000개 만들기 v(n, t)
		cout << v.size();
		vector<int> s{ 1, 2, 3, 4, 5 };
		vector<int> v(s.rbegin(), s.rend());
		for (auto d : v)
			cout << d << ends;
		cout << endl;

		 키보드에서 원하는 만큼 숫자를 입력해서 v를 만들어 주세요.
		vector<int> v;
		int s;
		while (1)
		{
			cin >> s;
			if (s == 0)
				break;
			v.emplace_back(s);
		}
		int sum = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum += v[i];
		}
		cout << sum << endl; *-

			 이게 안되는 이유는 자료형
			vector<int> v{ istream_iterator<int>(cin), istream_iterator<int>() }; // 키보드 시작 부터 키보드 끝까지
		int sum = 0;

		for (auto d : v)
			sum += d;
		cout << sum << endl;
	}

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
	using namespace std;
	 컨테이너 기능 306쪽
	 1. 모든 컨테이너는 값 문맥을 제공한다.
	 2. 내부 원소는 특정 순서대로 저장된다.
	 3. 모든 연산은 일반적으로 오류를 검사하지 않는다.
	 만약 복사생성이동생성을 못할경우에는 컨테이너의 원소를 포인터로 접근하여 사용한다.
	 컨테이너는 항상 원소를 일정한 순서로 순회할 수 있어야 한다.
	 314쪽 array - 메모리를 스택에 잡는데 크기가 고정이 되어있다.
	 reserve 멤버 함수의 의미 - 486쪽에 나와있다.
	 reserve를 호출한 후에 삽입해서 크기가 100개가 안넘었으면 유효화한채로 남아있을 것이다.
	 333쪽 벡터에 관하여 잘 나와있다.

	int main()
	{
		 한 문장을 이용해서 입력받은 단어를 오름차순으로 정렬하라

		multiset<string> s{ istream_iterator<string>(cin), istream_iterator<string>() };


		for (string d : s)
			cout << d << " ";
		cout << endl;

	}
	int main()
	{
		multiset<int> s{ 1, 1, 2, 3, 4, 6, 6, 7 };

		auto p = s.find(2);

		if (p != s.end())
			cout << *p << endl;
		else
			cout << "없다." << endl;

	}
	class game
	{
	public:
		int a[100];
	};

	int main()
	{
		array<int, 10> a;
		array<int, 11> b;


		cout << (a == b) << endl;
	}

	int main()
	{
		array<char, 40> a{ "12345677" };

		int len = strlen(&a[0]);
		int len = strlen(a.data());


		for (char d : a)
			cout << d << ends;
		cout << endl;
	}
	int main()
	{
		vector<game> v{ 1, 6, 2, 5, 3, 4 };

		auto p = v.begin();
		cout << *p << endl;

		 100개까지 원소가 늘어날 예정

		v.reserve(3);

		p = v.begin();
		cout << *p << endl;

		for (game d : v)
			cout << d << endl;


	}
	class game
	{
		int n;
	public:
		game(int n) : n(n) {}
		operator int() const { return n; }
	};

	int main()
	{
		list <game> c1{ 1, 2, 3, 7, 8, 9 };
		list <game> c2{ 4, 5, 6 };
		 리스트는 노드 기반의 컨테이너이다.
		 c2를 c1의 3, 7 원소 사이에 끼워넣은 것쯤은 일도아니다.
		c1.
	}

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <array>
#include <string>
#include <iterator>
#include <fstream>
#include <functional>
#include <deque>
	using namespace std;


	class game
	{
		int n;
	public:
		game(int n) : n(n) {}
		operator int() const { return n; }
	};

	int main()
	{
		list <game> c1{ 1, 2, 3, 7, 8, 9 };
		list <game> c2{ 4, 5, 6 };
		 리스트는 노드 기반의 컨테이너이다.
		 c2를 c1의 3, 7 원소 사이에 끼워넣은 것쯤은 일도아니다.


		auto p = find(c1.begin(), c1.end(), 3);
		++p;

		for (auto i = c2.begin(); i != c2.end(); ++i)
		{
			c1.insert(p, i->operator int());
		}


		for (auto d : c1)
			cout << d << ends;
		cout << endl;
	}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

	using namespace std;

	447쪽 꼭 읽어보기
		항상 같은 컨테이너를 쓰는 것은 그러한 이유가 있어야 사용하는것이다.
		컨테이너를 사용하려면 기본적으로 vector를 사용하라.
		vector는 메모리나 성능을 불편하지 않게 사용할 수 있다.
		맵 원소를 삽입 삭제 하는 경우가 많을 경우 deque, list를 사용한다.
		컨테이너 중간에 삽입 삭제하는 일이 잦다면 list를 사용한다.

		반복자는 포인터를 일반화함으로써 c++ 프로그램에서 서로 다른 데이터 구조를 이용하더라도 일관적인 방법으로 프로그램 작업을 할 수 있도록 한다.

		알고리즘 함수 distance는 두 반복자 간의 거리를 계산해주는 함수이다.

		dereferencable 역참조 가능한
		알고리즘 함수 입장에서는 전달되는 begin, end 반복자가 reachable(도달 가능한) begin에서 ++연산자로 end에 도달하여야 함을 의미한다.
		valid range - reachable한 반복자의 쌍
		dereferebceable - 반복자에 *연산으로 값에 access 가능함을 의미
		mutable - 반복자가 가리키는 위치에 값을 쓸 수 있음을 의미

		void f() { cout << "f()" << endl; }
	void f(int) { cout << "f(int" << endl; }
	class test
	{
	public:
		void operator++() { cout << "인자없는 함순" << endl; }
		void operator++(int) { cout << "인자있는 함수" << endl; }
	};

	int main()
	{

		f(), f(1);
	}

	전달된 인자로부터 그 인자가 어떤 속성을 갖는지 판달할 수 있다.
		반복자로부터 다음 특성을 알아낼 수 있다.


		template<class iter>
	int dist(iter begin, iter end)
	{
		이것은 현재 반복자가 어떤 종류인가를 나타낸다.
			반복자의 종류에 따라 거리 계산이 달라져야 한다.
			이것은 다른 함수를 호출하여 해결한다.

			iterator_traits<iter>::value_type;
		iterator_traits<iter>::difference_type;
		iterator_traits<iter>::pointer;
		iterator_traits<iter>::reference;

		return dist(begin, end, iterator_traits<iter>::iterator_category());

	}

	벡터인 경우
		template<class iter>
	int dist(iter begin, iter end, random_access_iterator_tag)
	{
		cout << "랜덤 액세스 반복자가 인자로 전달되었다." << endl;

		return end - begin;
	}

	벡터가 아닌 경우
		template<class iter>
	int dist(iter begin, iter end, forward_iterator_tag)
	{
		int count = 0;
		cout << "순 방향 반복자가 인자로 전달되었다." << endl;

		while (begin != end)
		{
			++count;
			++begin;
		}
		return count;
	}

	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag {} : public input_iterator_tag;
	struct bidirectional_iterator_tag {} : public forward_iterator_tag;

	*는 반복자의 특성을 모두 갖고 있기 떄문에,
		iterator_traits<t*>에 대해 specialization 되어있기 때문이다.


		int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		auto dis = dist(v.begin(), v.end());

		cout << dis << endl;
	}

#include <iostream>
#include <set>
#include <string>
#include <vector>

	using namespace std;

	class game
	{
		int n;
	public:
		game(int n) : n(n) {}
		bool operator<(const game& other)
		{
			return n < other.n;
		}

		int getn() const { return n; }
	};

	class test
	{
		int n;
	public:
		bool operator()(const game& a, const game& b)
		{
			return a.getn() < b.getn();
		}
	};

	int main()
	{
		set<game, test> s{ 3, 1, 5, 2, 4 };

		for (auto d : s)
			cout << d.getn() << ends;
		cout << endl;

	}

#include <iostream>
#include <set>
#include <string>

	using namespace std;

	class intsequence
	{
		int value;
	public:
		intsequence(int value) : value(value) {}

		int operator()() { return ++value; }
	};

	540쪽 상태를 갖는 구조체
		542쪽과 같은 프로그램을 할 수 있다.

		int main()
	{
		intsequence i(10);

		i();
		i();
		i();

		cout << i() << endl;

	}

#include <iostream>
#include <vector>
#include <iterator>

	using namespace std;

	class meanvalue
	{
		int sum{ 0 };
		int count{ 0 };
	public:
		void operator()(int n)
		{
			sum += n;
			count++;
		}

		double value() const
		{
			return (double)sum / count;
		}
		operator double() { return value(); }
	};

	template<class iter, class call>
	call foreach(iter begin, iter end, call c)
	{
		while (begin != end)
		{
			c(*begin++);
		}
		return c;
	}

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
		vector<int> v{ istream_iterator<int>(cin), istream_iterator<int>() };

		meanvalue ave = foreach(v.begin(), v.end(), meanvalue());

		cout << "평균 값은 : " << ave.value() << endl;
	}

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
		vector<int> v{ istream_iterator<int>(cin), istream_iterator<int>() };


		cout << "평균 값은 : " << foreach(v.begin(), v.end(), meanvalue()) << endl;

	}

#include <iostream>
#include <vector>
#include <algorithm>

	using namespace std;

	int main()
	{
		vector <int> v{ 1, 3, 5 };

		cout << all_of(v.begin(), v.end(), [](int n)
		{
			return n & 1;
		});
	}

#include <iostream>
#include <vector>
#include <algorithm>
	using namespace std;

	int main()
	{
		vector<int> v{ 1, 1, 2, 2, 3, 3, 3, 1 };

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		for (auto d : v)
			cout << d << ends;
	}

#include <iostream>
#include <vector>
#include <algorithm>
	using namespace std;

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		stable_partition(v.begin(), v.end(), [](int n)
		{
			return n & 1;
		});

		for (auto d : v)
			cout << d << ends;
		cout << endl;
	}

	2016. 6. 8. 수 23(월수)(14주)1
		14주 2 알고리즘 / 애너그램 종강
		15주 1 기말고사
		15주 2 점수확인

		10. stl 함수 객체와 람다 사용.

#include<iostream>
#include<set>
#include"save.h"

		10장 함수 객체와 람다 사용.
		using namespace std;

	class game
	{
	private:
		int level{ 19 };
	public:
		game(int n)
			: level(n) {}
		bool operator<(const game& other) const
		{
			return level < other.level;
		}
		int get_n() const { return level; }

	};

	void main()
	{
		정렬의 기준으로 함수 객체를 사용할수 있다.
			set<game> s;

		s.insert({ 1, 10, 5, 3, 19 });
	}


	== == == == == == == == == == == == == == == == == == == == == == =
		mon may 30 10:48 : 31 2016
		== == == == == == == == == == == == == == == == == == == == == == =
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		
		반복자는 포인터를 일반화함으로써 c++ 프로그램에서 서로 다른
		데이터 구조를
		------------------------------------------------------------ -

		알고리즘 함수 distance는 두 반복자 간의 거리를 계산해 주는 함수이다.

		using namespace std;

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		int id = distance(v.begin(), v.end());
		cout << id << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		int id = distance(v.end(), v.begin());
		cout << id << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	void main()
	{
		set<int> v{ 1, 2, 3, 4, 5 };

		int id = distance(v.end(), v.begin());
		set is not working with end to begin.

			cout << id << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		int cnt{};
		while (b != e) {
			++b;
			++cnt;
		}
		return cnt;
	}

	void main()
	{
		set<int> v{ 1, 2, 3, 4, 5 };

		int d = dist(v.begin(), v.end());

		cout << d << endl;
		save();
	}


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	class test {
	public:
		void operator++() { cout << "인자 있는 함수 " << endl; }
		void operator++(int) { cout << "인자 있는 함수" << endl; }
	};
	void main()
	{

		test a;
		++a; // a.operator++ (인자 x) - 선연산(++) 후대입(=)
		a++; // a.operator++ (인자 o) - 선대입(=)  후연산(++)
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	class test {
	public:
		void operator++() { cout << "인자 있는 함수 " << endl; }
		void operator++(int) { cout << "인자 있는 함수" << endl; }
	};

	void f() { cout << "f()" << endl; }
	void f(int) { cout << "f(int)" << endl; }
	void main()
	{
		f();
		f(1);
		인자를 사용하는것이 아니라, 찾아가는 용도로 쓰인다.
			save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		전달된 인자로부터 그 인자가 어떤 속성을 갖는지 판단할 수 있다.
			(528쪽)
			반복자로부터 다음 특성을 알아낼 수 있다.
			iterator_traits<iter>::iterator_category;
		iterator_traits<iter>::value_type;
		iterator_traits<iter>::difference_type;
		iterator_traits<iter>::pointer;
		iterator_traits<iter>::reference;

		if () {
			int cnt{};
			while (b != e) {
				++b;
				++cnt;
			}
			return cnt;
		}
		else return e - b;
	}

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };
		set<int> s{ 1, 2, 3, 4, 5 };

		int d = dist(v.begin(), v.end());
		cout << "거리는" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		전달된 인자로부터 그 인자가 어떤 속성을 갖는지 판단할 수 있다.
			(528쪽)
			반복자로부터 다음 특성을 알아낼 수 있다.
			iterator_traits<iter>::iterator_category; -- > 자료형
			이것은 현재 박본자가 어떤 종류인가를 나타낸다.
			반복자의 종류에 따라 거리 계산이 달라져야 한다.
			이것은 다른 함수를 호출하여 해결한다.
			return dist(b, e, iterator_traits<iter>::iterator_category());
		인자 3개 다른함수 오버로딩
	}

	벡터인 경우
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "랜덤 액세스 반복자가 인자로 전달 되었다" << endl;
		return e - b;
	}

	527쪽
		bidirectional(양방향)
		input(입력만)
		ouput(출력만)

		벡터가 아닌 경우
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "순방향 반복자가 전달되었다" << endl;
		while (b != e) {
			cnt++;
			b++;
		}
		return cnt;
	}

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };
		set<int> s{ 1, 2, 3, 4, 5 };

		int d = dist(v.end(), v.begin());
		cout << "거리는" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		return dist(b, e, iterator_traits<iter>::iterator_category());
	}

	벡터인 경우
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "랜덤 액세스 반복자가 인자로 전달 되었다" << endl;
		return e - b;
	}

	벡터가 아닌 경우
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "순방향 반복자가 전달되었다" << endl;
		while (b != e) {
			cnt++;
			b++;
		}
		return cnt;
	}

	void main()
	{
		int v[]{ 1, 2, 3 };

		int d = dist(v + 3, v);
		cout << "거리는" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		return dist(b, e, iterator_traits<iter>::iterator_category());
	}

	벡터인 경우
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "랜덤 액세스 반복자가 인자로 전달 되었다" << endl;
		return e - b;
	}

	벡터가 아닌 경우
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "순방향 반복자가 전달되었다" << endl;
		while (b != e) {
			cnt++;
			b++;
		}
		return cnt;
	}

	void main()
	{
		int a = 10;
		int b = 20;

		int d = dist(&a, &b);
		cout << "거리는" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class iter>
	int dist(iter b, iter e)
	{
		return dist(b, e, iterator_traits<iter>::iterator_category());
	}

	벡터인 경우
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "랜덤 액세스 반복자가 인자로 전달 되었다" << endl;
		return e - b;
	}

	벡터가 아닌 경우
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "순방향 반복자가 전달되었다" << endl;
		while (b != e) {
			cnt++;
			b++;
		}
		return cnt;
	}

	*는 반복자의 특성을 모두 갖고 있기떄문에
		iterator_tranits<t*>에 대해 specialization 되어있기 떄문이다.
		결국 9장에서는 527쪽이 가장중요하다.
		void main()
	{
		int a = 10;
		int b = 20;
		cout << &a << endl;
		cout << &b << endl;

		int d = dist(&a, &b);
		cout << "거리는" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class bi_iterator>   // 양방향 반복자.
	void myreverse(bi_iterator beg, bi_iterator end)
	{
		원소들의 갯수를 세보자.
			iterator_traits<bi_iterator>::difference_type
			n = distance(beg, end);
		cout << "바꿔야할 원소의 수 : " << n << endl;

		while (n > 0)
		{
			swap 하기 위한 임시 변수.
				iterator_traits<bi_iterator>::value_type
				tmp = *beg;
			*beg++ = *--end;
			*end = tmp;
			n -= 2;
		}

	}
	void main()
	{
		알고리즘 함수 revese()는 구간[b, e)의 원소 순서를
		반대로 바꾸는 함수이다.
			이 함수를 직접 구현하라.
			vector<int> v{ 1, 2, 3, 4, 5 };
		reverse()
			myreverse(v.begin(), v.end());
		for (int d : v)
			cout << d << " ";
		cout << endl;
		save();
	}
	== == == == == == == == == == == == == == == == == == == == == == =
		wed jun 01 11:16 : 10 2016
		== == == == == == == == == == == == == == == == == == == == == == =
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class fow_iterator>   // 순방향 반복자.
	void shift_left(fow_iterator beg, fow_iterator end)
	{
		while (beg != end)
		{

		}

	}

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		반복자를 인자로 받아 왼쪽으로 원소를 한 자리 이동 시키는 함수를 작성하라.
			shift_left(v.begin(), v.end());
		rotate(v.begin(), v.begin() + 1, v.end());

		2, 3, 4, 5, 6, 7, 8, 9, 10, 1
			for (int d : v)
				cout << d << " ";
		cout << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class fwditer>   // 순방향 반복자.
	void shift_left(fwditer beg, fwditer end)
	{
		auto d = distance(beg, end);

		auto tmp = *beg;
		for (int i = 0; i < d - 1; ++i)
		{
			*beg++ = *(beg + 1);
		}
		*beg = tmp;
	}

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		반복자를 인자로 받아 왼쪽으로 원소를 한 자리 이동 시키는 함수를 작성하라.
			shift_left(v.begin(), v.end());
		rotate(v.begin(), v.begin() + 1, v.end());

		2, 3, 4, 5, 6, 7, 8, 9, 10, 1
			for (int d : v)
				cout << d << " ";
		cout << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<forward_list>
#include"save.h"

		using namespace std;

	template<class fwditer>   // 순방향 반복자.
	void shift_left(fwditer beg, fwditer end)
	{
		528쪽의 내용.
			iterator_traits<int*>::difference_type
			d = distance(beg, end);

		auto tmp = *beg;
		auto mid = beg;
		mid++;
		for (int i = 0; i < d - 1; ++i)
		{
			*beg++ = *(mid++);
		}
		*beg = tmp;
	}

	void main()
	{
		forward_list<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		반복자를 인자로 받아 왼쪽으로 원소를 한 자리 이동 시키는 함수를 작성하라.
			shift_left(v.begin(), v.end());
		rotate(v.begin(), v.begin() + 1, v.end());


		이 프로그램은 왜 실행되는가 ?
			포인터는 반복자를 갖춰야할 특성을 갖고 있기 때문에
			포인터의 폭을 넓혀 일반화한 개념.
			디자인패턴 - 반복자 패턴이 존재.

			2, 3, 4, 5, 6, 7, 8, 9, 10, 1
			for (int d : v)
				cout << d << " ";
		cout << endl;
		save();
	}


#include<iostream>
#include<algorithm>
#include<vector>
#include"save.h"

		using namespace std;

	531쪽.
		표준문서의 예
		사용자가 자신이 만든 이진트리를 순회할 수 있는
		binarytreeiterator를 정의 한다고 생각해보자.
		template<class t>
	class binarytreeiterator<t>
	{

	};

	template<class t>
	struct iterator_traits<binarytreeiterator<t>> // 1.
	{
		5가지 type
			typedef ptrdiff_t      difference;
		typedef t            value_type;
		typedef t*            pointer;
		typedef t&            reference;
		typedef bidirectional_iterator_tag
			iterator_category;
	};
	class myiter
	{
	private:
	public:

	};

	이와 같이 정의할 수도 있지만

		531쪽 아랫부분과 같이 클래스를 상속받아 만들 수도 있다.
		532쪽에서 실행되는 사용자 정의 반복자 클래스를 볼 수 있다.

		void main()
	{
		나만의 반복자를 만들고 싶다.어떻게 하면 되나 ?
			1. iterator_traits 구조를 위한 필수 다섯가지 자료형을 제공한다.
			2. iterator_traits 구조에 대한(부분) 특수화를 제공한다.


	}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

	using namespace std;

	struct ps : pair<string, string>
	{
		ps() : pair<string, string>(string(), string()) {}
		ps(const string& s) : pair<string, string>(s, s) {
			sort(first.begin(), first.end());
		}

		operator string() const { return second; }
	};

	int main()
	{
		vector<ps> v;
		v.reserve(20159);

		cout << "anagram을 찾는 프로그램" << endl;

		cout << "사전 파일을 입력하세요." << flush;


		cout << endl;
		ifstream ifs("diction");

		if (!ifs.is_open())
		{
			cout << "파일을 읽을 수 없습니다." << endl;
			exit(0);
		}

		copy(istream_iterator<string>(ifs), istream_iterator<string>(), back_inserter(v));

		cout << "모두" << v.size() << "개의 단어를 읽었습니다." << endl;

		아이디어 //

			읽은 단어와 그 단어를 정렬한 단어를 하나의 쌍으로 만든다.
			v의 first 기준으로 정렬한다.

			sort(v.begin(), v.end(), [](const ps& a, const ps& b)
		{
			return a.first < b.first;
		});

		처음부터 끝까지 정렬해놓은 단어를 기준으로 현재 위치와 다음 위치의 단어가 같은 것을 찾는다.
			발견했다면(if) 발견한 위치부터 같지 않은 단어가 나오는 위치를 찾는다.

			int i = 1;
		vector<ps>::const_iterator j = v.begin(), end = v.end(), k;
		while (true)
		{
			j = adjacent_find(j, end, [](const ps& a, const ps& b) {
				return a.first == b.first;
			});

			if (j == end)
				break;

			k = find_if_not(j + 1, end, [j](const ps& a) {
				return a.first == j->first;
			});

			구간(j, k)까지는 anagram 이다.
				cout << "[" << i++ << "] ";
			copy(j, k, ostream_iterator<string>(cout, " "));
			cout << endl;

			j = k;

		}


	}

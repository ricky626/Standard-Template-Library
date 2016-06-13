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

	 �������� ������ ����Ȯ�� ������ ����Ͽ� �����Ѵ�.

	default_random_engine dre; // �⺻ ���� ���

							   normal_distribution<> nd(0, 1.0); //Ȯ�� ����
	uniform_int_distribution<> ui; // ��� ���� ���� ���� �����ϵ��� 

	for (int i = 0; i < 1000000; i++)
	{
		a[i] = ui(dre);
	}

	auto test = compare;

	qsort(a, 1000000, sizeof(a[0]), test);


	ofstream out("�鸸������.txt");

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
	ifstream in("�鸸������.txt", ios::binary);

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
 ����� Ư�� 
 auto, �ϰ��� �ʱ�ȭ, ���� ����� for loop
 �̵����ư� r-vaule ����( Ŭ���� ��ü ���� �ǽ� )
 ����

using namespace std;

int main()
{
	vector : ���� �迭
	vector<string> v{ "������", "3��", "14��", "ȭ��Ʈ", "����" };

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
	������� �̸��� ���̸� ���´�.

	wizard a[] = { wizard("2��", 20), wizard("1��", 10), wizard("7��", 3), wizard("3��", 5) };
	wizard a[] = { { "2��", 20 },{ "1��", 10 },{ "7��", 3 },{ "3��", 5 } };

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
	monster x("���", 333), y("ogre", 777);

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

	 c�Լ� qsort�� �̿��Ͽ� a�� �����Ͻÿ�

	qsort(a, 10, sizeof(a[0]), compare);

	for (auto d : a)
		cout << d << " "; //�������� ����
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

	 �������� ������ ����Ȯ�� ������ ����Ͽ� �����Ѵ�.

	default_random_engine dre; // �⺻ ���� ���

							   normal_distribution<> nd(0, 1.0); //Ȯ�� ����
	uniform_int_distribution<> ui; // ��� ���� ���� ���� �����ϵ��� 

	for (int i = 0; i < 1000000; i++)
	{
		a[i] = ui(dre);
	}

	auto test = compare;

	qsort(a, 1000000, sizeof(a[0]), test);


	ofstream out("�鸸������.txt");

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
	ifstream in("�鸸������.txt", ios::binary);

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

 �������� ����
int f(int a, int b)
{
	return a > b;
}


int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	c++������ a�� ������ ���� �����Ѵ�.

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

 �������� ���� ���
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	c++������ a�� ������ ���� �����Ѵ�.

	sort(a, a + 10, [](int a, int b) //����
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
	������� �̸��� ���̸� ���´�.

	wizard a[] = { wizard("2��", 20), wizard("1��", 10), wizard("7��", 3), wizard("3��", 5) };
	wizard a[] = { { "2��", 20 },{ "1��", 10 },{ "7��", 3 },{ "3��", 5 } };

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
 ����� Ư�� 
 auto, �ϰ��� �ʱ�ȭ, ���� ����� for loop
 �̵����ư� r-vaule ����( Ŭ���� ��ü ���� �ǽ� )
 ����

using namespace std;

int main()
{
	vector : ���� �迭
	vector<string> v{ "������", "3��", "14��", "ȭ��Ʈ", "����" };

	vector<string>::const_iterator it = v.begin();

	for (auto it = v.begin(); it < v.end(); ++it)
		cout << *it << endl;

	save();


#include <iostream>
#include <string>
#include <vector>
	using namespace std;

	 ���յ� �ʱ�ȭ (uniform initialization c++)
	
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
			cout << id << " �⺻ ������" << endl;
		};
		model(int _size) : size(_size)
		{
			data = new char[size];
			id = gid++;
			cout << id << " ũ�⸦ ���� ������ " << size << endl;
		};
		model(const model& other) : size(other.size)
		{
			data = new char[size];
			�����͸� �����ؿ´�.
			memcpy(data, other.data, size);
			���� �����ڸ� ������ٸ� ��������� �����ϰ� ������ ���� �� �� �ִ�.
			-this = other;
			id = gid++;
			cout << id << " ���� ������ " << size << endl;
		};
		model(model&& other) : data(nullptr), size(other.size), id(gid++)
		{ // && : r-value reference
			data = other.data;
			other.data = nullptr;
			other.size = 0;
			cout << id << " �̵�������(���� ��ü) " << size << " id " << other.id << endl;
		}
		 move assignment operator
		model& operator = (model&& other)
		{
			 �ڱ� �ڽ��� �����Ѵٸ� �ƹ��͵� ���ص� �ȴ�.
			if (this == &other)
				return *this;
			 ���� ���� �Ҵ��� �޸𸮰� �ִٸ� ������
			if (data != nullptr)
			{
				delete[] data;
			}
			 ������ �޸𸮿� ���� ������ �����.
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
			cout << id << " �Ҹ��� " << size << endl;
		}
		 assignment operator ���� ������
		model& operator = (const model& other)
		{
			 �ڱ� �ڽ��� �����Ѵٸ� �ƹ��͵� ���ص� �ȴ�.
			if (this == &other)
				return *this;
			 ���� ���� �޸𸮸� ���� ������ �Ѵ�.
			if (data != nullptr)
				delete[] data;
			 ������ �޸𸮿� ���� ������ �����.
			size = other.size;
			data = new char[size];
			memcpy(data, other.data, size);
			cout << id << " ���Կ����� " << size << endl;
			return *this;
		}

	};
	int main()
	{
		model a;
		model b(1000);
		model c(b);
		a = c; // a.operator = (c); // ���� ������
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
	 ���� �̸����� �Լ�
	 �Լ��� ���α׷��Ӱ� ȣ���� ���� ������
	 �Լ��� ���(body)�� �ʿ�� �ϴ� ���� �����
	 [=]()
	
	 stl�� �ӵ��� ����ȭ�� ���̺귯���Դϴ�.
	 �� ���� ����ó�� ������ ���� �ʴ´ٴ� �̾߱� �Դϴ�.
	 ����ó���� �ʿ��ϴٸ� �׷��� ���ִ� Ư�������� ���̺귯���� �Լ��� ����ؾ� �մϴ�.
	 ���� 81�� dynamic_cast
	class animal
	{
	public:
		virtual void move() = 0;
	};
	class dog : public animal
	{
	public:
		virtual void move() override final { cout << "�� �ڴ�." << endl; }
	};
	class bird : public animal
	{
	public:
		virtual void move() override final { cout << "�� ����." << endl; }
	};
	int main()
	{
		animal* a[3]{ new dog, new bird, new dog };
		for (animal* d : a)
		{
			if (dynamic_cast<dog*>(d) != nullptr) //�� �϶��� for loop ������
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
	 ���� �̸����� �Լ�
	 �Լ��� ���α׷��Ӱ� ȣ���� ���� ������
	 �Լ��� ���(body)�� �ʿ�� �ϴ� ���� �����
	 [=]()
	
	 stl�� �ӵ��� ����ȭ�� ���̺귯���Դϴ�.
	 �� ���� ����ó�� ������ ���� �ʴ´ٴ� �̾߱� �Դϴ�.
	 ����ó���� �ʿ��ϴٸ� �׷��� ���ִ� Ư�������� ���̺귯���� �Լ��� ����ؾ� �մϴ�.
	 ���� 81�� dynamic_cast
	  if (dynamic_cast<bird*>(d) != nullptr) //�� �϶��� for loop ������
	   d->move();
	class animal
	{
	public:
		virtual void move() = 0;
	};
	class dog : public animal
	{
	public:
		virtual void move() override final { cout << "�� �ڴ�." << endl; }
	};
	class bird : public animal
	{
	public:
		virtual void move() override final { cout << "�� ����." << endl; }
	};
	void f(animal& a)
	{
		 ���� a�� ���� �����ٸ� move()�� ȣ���϶�

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
	 ȣ�� ���� Ÿ��(callable type)
	 1. �Լ�
	 2. ��� �Լ�
	 3. �Լ� ��ü : �Լ� ȣ�⿬���ڸ� �����ε��� Ŭ����
	 4. ����
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
	 6. bind : ���� �Լ��� ���� ������ �ٲ� �� �Լ��� ����� �ش�.#include <functional>
	int add(int a, int b)
	{
		return a + b;
	}
	int main()
	{
		auto f = bind(add, 5, 10);
		cout << f() << endl;
	}
	 pair<>, ����Ʈ ������, tyep traits 5��
	 pair : ����(heterogeneous)�� �ڷ����� �ϳ��� ���� ����� �� �ֵ��� �Ѵ�.
	int main()
	{
		 �̸��� �����
		pair<string, int> onepiece[]{ { "����", 400 },{ "����", 300 },{ "���", 100 } };

		sort(begin(onepiece), end(onepiece), [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.first < b.first;
		});
		for (pair<string, int> d : onepiece)
		{
			cout << "�̸� �� : " << d.first << ends << d.second << endl;
		}
		sort(begin(onepiece), end(onepiece), [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.second < b.second;
		});
		for (pair<string, int> d : onepiece)
		{
			cout << "����� �� : " << d.first << ends << d.second << endl;
		}
	}
	 pair<>, ����Ʈ ������, tyep traits 5��
	 pair : ����(heterogeneous)�� �ڷ����� �ϳ��� ���� ����� �� �ֵ��� �Ѵ�.

	int main()
	{
		 pair<double, double> point2d;
		 2���� ��ǥ 100��(-100 ~ 100 ���̰�)�� ��������
		 �������� �ݰ� 10�̳��� ���鸸 ȭ�鿡 ���
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

	 ����Ʈ ������ - �ڽ��� ȹ���� �ڿ��� �ڽ��� �Ҹ�� �� ������ �ִ� ������
	 p = new int[100]; - ȹ���� �ڿ� -> �����Ͱ� ����� �� ����
	 c++11 ������ unique_ptr - �ڿ��� �����ϴ� ������ // shared_ptr - �ڿ��� �����ϴ� ������
	
	 ������ -
	 1. �ڿ��� ȹ���Ѵ�.(heap)
	 2. �ڿ��� �̿��Ѵ�.
	 3. ��ȯ�Ѵ�.
	
	 5.3 numeric_limits
	 5.4 type traits
	 
	 ���ø� �ڵ忡���� ���޵� ������ Ÿ���� ������ �ʿ䰡 �ִ�.
	 ������ Ÿ���� �����ϱ� ���� type traits�� �̿��Ѵ�. ���� 167��
	class mini
	{
	public:
		mini() { cout << "������ " << endl; }
		~mini()
		{
			cout << "�Ҹ���" << endl;
		}
		void f() { cout << "��� �Լ�" << endl; }
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
		 �ڿ��� �����ϴ� ������ unique_ptr
		 ���۷����� ī�����ϴ� ������ shared_ptr
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

		 � �Լ��� �ִµ� �Ѱ��ִ� ���� �������̸� �װ��� ����Ű�� ����
		 �׳� ���̶�� �� ���� ����ϴ� �Լ��� �ۼ��ϰ� �ʹ�.
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
		 ���� 10���� ��� array�� ����� ����
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

		 stl �ݺ��ڸ� �̿��� �����̳� ���� ����
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
			v.push_back({ string("�̸�") + itoa(i + 1, buf, 10), ui(dre) });
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
			cout << p->first << ends << p->second << "ã��" << endl;
			cout << v[f].first << ends << v[f].second << "ã��" << endl;
		}

		else
			cout << "����" << endl;
	}
	class april
	{
	public:
		april() { cout << "������" << endl; }
		~april() { cout << "�Ҹ���" << endl; }
		april(const april& other) { cout << "���������" << endl; }

	};
	int main()
	{
		vector<april> v;
		v.push_back(april());
		cout << "�����Լ� ��" << endl;
		vector<april> v;
		april a;
		v.push_back(a);

		cout << "�����Լ� ��" << endl;

		vector<april> v;
		v.reserve(3);
		v.emplace_back();
		v.emplace_back();
		cout << endl << "���� �Լ� " << endl << endl;

		����Ʈ�� a ~ z�� �־��

		list<char> clist;
		for (char i = 'a'; i <= 'z'; ++i)
		{
			clist.push_back(i);
		}
		 'o'��ġ�� 3�� 'a', 'b', 'c'�� �����غ���.
		auto p = find(clist.begin(), clist.end(), 'o');
		clist.insert(p, 'a');
		clist.insert(p, 'b');
		clist.insert(p, 'c');

		for (auto i = clist.begin(); i != clist.end(); ++i)
			cout << *i << endl;

		for (auto d : clist)
			cout << d << endl;


		 ���� �����̳� set<int>�� ���� ���� 100�� �־��.

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
	 �ݺ���(iterator)
	 �����̳ʰ� �ڽ��� ����(private)�� ��ȸ�� �� �ֵ��� �����ϴ� ��ġ ������ó�� ����� �� �ִ� �������̽��̴�.
	
	 �����̳��� ����Լ�
	  begin() - �����̳��� ó�� ���Ҹ� ����Ų��.
	  end() - �����̳��� ������ ���Ҹ� �ϳ� ���� ���Ҹ� ����Ų��.
	
	
	 �ݺ��ڷ� �� �� �ִ� ����
	  *  - ������(dereferancing operator)
	  ++ - �������ҷ� �̵��Ѵ�.
	  == - �ݺ��ڳ��� ���Ѵ�.
	
	 �ݺ����� ����(category)
	
	 stl ǥ�� �����̳ʰ� �����ϴ� �ݺ��ڴ� ���� ī�װ� �� �ϳ��̴�.
	 1. ������(forward) �ݺ���    forward_list
	 2. �����(bidirectional) �ݺ���  list
	 3. ���� �׼���(random access) �ݺ��� array, vector, deque
	 �� �ܿ�
	 4. �Է� �ݺ���
	 5. ��� �ݺ���

	int main()
	{
		set<int> s;
		for (int i = 0; i < 100; ++i)
			s.insert(rand() % 100);
		for (auto d : s)
			cout << d << endl;

		auto p = s.find(94);
		if (p != s.end())
			cout << "ã��" << endl;
		set <int, greater<int>> s; // greater : �������� // less : ��������
		for (int i = 0; i < 100; ++i)
			s.insert(rand() % 100);

		for (auto d : s)
			cout << d << ends;
		���� �����̳� map map<key, value>
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
		 map�� subscript operator�� overloading �Ѵ�.
		 ����ڴ� map�� ���� �迭(associative array)ó�� ����� �� �ִ�.
		m["��Ӵ�"] = 1; // ���ο���� insert�� ���� �ִ�.
		m.operator[]("ö��") = 333; // ���ο���� insert�ϰų� key���� value�� ������ ���� �ִ�.
								   map�� ���������� �����Ҽ� ����. ���� ���ڸ� ���� ���� ���� ���� ������ �����ؾ��Ѵ�.
		map<int, string> mm;
		auto p = m.begin();
		for (int i = 0; i < m.size(); ++i, ++p)
		{
			mm.insert({ p->second, p->first });
		}

		for (auto d : mm)
			cout << d.first << ends << d.second << endl;
		���� ���Ͽ� �ִ� ������ �󵵼��� ����϶�.
		ifstream ifs("��������.txt");
		string str;
		map<char, int> m;

		string s("1234567890");

		for (auto p = s.rbegin(); p != s.rend(); ++p)
		{
			cout << *p << ends;
		}
		cout << endl;
	}

	 �˰��� (250��)
	
	 �˰����� ���׸��� �����Լ��̴�.
	 �˰����� ���ڴ� �ݺ��� �����̴�.
	 �Լ��� �̸��� ����(verb)�̴�.
	 ��� �˰����� �׻� ȿ������ ���� ����.
	
	
	
	
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
	using namespace std;

	int main()
	{
		vector<int> v(10, 1); // 1�� 10�� ����.

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
			cout << "ã��" << ends << *p << endl;
		else
			cout << "��ã��" << endl;
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

		 s���� m�� ã�Ƽ� m���� �ٲ�� myfind�� �Ἥ
		auto p = myfind(s.begin(), s.end(), '0');

		if (p != s.end())
			*p = 'm';

		cout << s << endl;

	}

	template<class iter>
	iter mymin_element(iter begin, iter end) // �ּҰ� ã��
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


		copy �˰��� �Լ��� �ϳ��� ������ �ٸ� �������� �����Ѵ�.

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

			-dest++ = *begin++; ������ �����ε�
		}
	}

	int main()
	{
		vector<int> v{ 1, 3, 5, 7, 9 };
		vector<int> vcopy;

		copy �˰��� �Լ��� �ϳ��� ������ �ٸ� �������� �����Ѵ�.
		mycopy(v.begin(), v.end(), back_inserter(vcopy));
		for (auto d : vcopy)
			cout << d << ends;
		cout << endl;
	}

	����1
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

		vector<data> v; // ���� �����Ͱ� �� vector


		time_t system_time = time(0);
		default_random_engine dre(system_time); // �⺻ ���� ���
		uniform_int_distribution<> ui(0, 1000); // ���� ����
		uniform_int_distribution<> nui(5, 10); // ���̵��� ����
		uniform_int_distribution<> stui(65, 90); // ���ĺ� ���� ����

		string str = ""; // id�� �� ���ڿ��� ��� ����
		int max = 0; // ���̵��� ���̿� ���� ������ ��� ����
		double mynumber = -1; // ���� ������ ��Ÿ�� ����

		ofstream ofs("��������.txt");


		for (int i = 0; i < max; ++i)
		{
			���ڿ� �ʱ�ȭ
			str = "";
			 id�� ���̸� �����ϰ� ����
			max = nui(dre);

			for (int j = 0; j < max; ++j)
			{
				 ���ڿ��� ������ ���̷� ����
				str += stui(dre);
			}

			 vector�� ����
			v.push_back({ str, ui(dre) });

			 ������ ���Ͽ� ����
			ofs << v[i].first << endl << v[i].second << endl;
		}

		������ ������ �ݴ´�.
		ofs.close();

		ifstream ifs("��������.txt");
		vector<data> readv; // ���Ͽ� ����� ���� �о�ͼ� ������ vector


		cout << "**���� �б�**" << endl;

		string s = "";
		int n = 0;

		for (int i = 0; i < max; ++i)
		{
			ifs >> s;
			ifs >> n;
			readv.push_back({ s, n });
			cout << readv[i].first << ends << readv[i].second << endl;
		}

		cout << "**���� �б�**" << endl << endl;
		ifs.close();


		���� ���� ������ �־���
		vector<data> my; // ���� ������ �� vector
		my.push_back({ v[0].first, v[0].second });


		 id�� �������� �������� ����
		sort(v.begin(), v.end());

		cout << "**id�� �������� �������� ����**" << endl;
		printall(v); // ���

					  ������ �������� �������� ����
		sort(v.begin(), v.end(), [](const data& a, const data& b) {
			return a.second > b.second;
		});

		cout << endl << "**������ �������� �������� ����**" << endl;
		printall(v); // ���


					  ���� ���� ������ ���°���� �˻�
		for (int i = 0; i < max; ++i)
		{
			if (my[0].first == v[i].first)
			{
				mynumber = i + 1;
				break;
			}
		}

		 �� ������ �������� ���� 10�� �Ʒ��� 10���� �Ǻ�
		int nummin = (mynumber <= 10) ? 0 : (mynumber - 1) - 10;
		int nummax = (mynumber >= max - 10) ? max : mynumber + 10;

		cout << "**�� ������ �������� ���� 10�� ������ ǥ��**" << endl;
		for (int i = nummin; i < mynumber - 1; ++i)
			cout << v[i].first << ends << v[i].second << "  " << i + 1 << "��" << endl;
		cout << endl;

		cout << "**�� ������ �������� �Ʒ��� 10�� ������ ǥ��**" << endl;
		for (int i = mynumber; i < nummax; ++i)
			cout << v[i].first << ends << v[i].second << "  " << i + 1 << "��" << endl;
		cout << endl;

		cout << endl << "���� id : " << my[0].first << ends << my[0].second << endl;
		cout << "���� ���� : " << mynumber << "��" << endl;

		 ���� �� %���� ���
		double d = mynumber / max * 100;

		cout << "���� : " << d << "% �Դϴ�." << endl << endl;


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
		string name = "Ư��";
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

		string name = "Ư��";
		char buf[10];

		������ ���� �� ���� ������ ������ �� �ִ�.
		treasure(name, ui(dre), ui(dre), ui(dre));

		 �����Կ� ���� 500���� �־��

		for (int i = 0; i < 500; ++i)
		{
			box.push_back({ name, ui(dre), ui(dre), ui(dre) });
		}


		 �������� ������ ������ ��ġ�������� ������ ������ ����ϴ� �Լ� print()
		print(box, 20, 5);

		 �ɷ��� �հ������ ���ĵ� ������


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

		ofstream out("������.txt");
		out << box.size() << endl;
		out << box;
		out.close();

		box.clear();

		ifstream in("������.txt");

		in >> box;

		cout << "������ �� : " << box.size() << endl;


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
			cout << "����" << "{" << x << ends << y << ")" << endl;
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

		���� �ϳ� ����
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

			 ����Ʈ�� ��� ���Ҹ� �ݺ��� p�� ����Ͽ� ��ȸ�ϸ鼭 render() �� update�� ȣ���϶�.
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
			 ������� for lopp�� ����Ͽ� ����Ʈ ������ render()�� update()�� ȣ���϶�. ���� ������ ��ġ�� ����Ǿ���Ѵ�.
			for (auto i = data.begin(); i != data.end(); ++i)
			{
				i->update();
				i->render();
			}

			--n;
		}

		y�� �������������϶�
		data.sort([](const cherry& a, const cherry& b) {
			return a.getxy().second < b.getxy().second;
		});

		print(data, 0, 10);

		 ���ĵ� ����Ʈ���� �ӵ��� 9�� ������ ã�Ƽ� �յڷ� 5���� ����϶�.

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

		ofstream out("�߰����.txt");
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
			cout << "��ġ(" << getx() << ", " << gety() << ") hp : " << gethp() << endl;
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
		cout << "������ �� : " << data.size() << endl;
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

		int bx = 409, by = 200; // ��ź��ġ
		double dist; // ��ź�� ������ �Ÿ�
		for (auto i = data.begin(); i != data.end(); ++i)
		{
			dist = sqrt((bx - i->getx()) * (bx - i->getx()) + (by - i->gety() * (by - i->gety()))); // �Ÿ�

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
		ofstream out("��������.txt");
		out << data;
		out.close();
		data.clear();
		cout << endl;
		cout << "���� ���� ���� : " << data.size() << endl;
		ifstream in("��������.txt");
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

		 my_copy ����° ������ back_inserter�� �ݺ��� ������̴�.
		 �ݺ��ڿ� �䱸�Ǵ� ������ *, ++, == ���� ������ Ŭ�����̴�.
		 back_inserter�� ���� ������ ������ ���� �����ϴ� �������� �����Ѵ�.
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


		 ���� v���� ¦���� �����ּ���.
		 ¦����� ������ ã�Ƽ� �������ϹǷ� remove_if

		 ����Ʈ�� ��Ҹ� remove�� ȣ���Ѵٸ� �˰����� ���� �����̳ʰ� ����Ʈ���� �𸣱� ������ 

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
	void foreach(iter begin, iter end, call func) // �ݷ��� Ÿ��
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

		 ��� ���� ���
		 ȣ���� �� �ִ� ���̶�� ������ ���ڷ� ���� �����ϴ�.
		foreach(coll.begin(), coll.end(), print);
		cout << endl;
	}
	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6 };
		list<int> l{ 1, 2, 3, 4, 5, 6 };

		vector<int> c;
		 v*c�� ����� ȭ�鿡 ����Ͻÿ�
		 �Լ� �ϳ��� ����� ��.

		transform(v.begin(), v.end(), l.begin(), back_inserter(c), [](int a, int b) {
			return a* b;
		});

		transform(v.begin(), v.end(), l.begin(), ostream_iterator<int>(cout, " "), [](int a, int b) {
			return a* b;
		});


	}
		�̸� ���ǵǾ� �ִ� �Լ� ��ü(291)
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
	 ���δ� binder
#include <deque>
#include <functional>
	int main()
	{
		set<int, greater<int>> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		deque<int> d;
		 transform�� �Ἥ co11�� ��� ���Ҹ� coll2�� ���Ҹ� �ű�鼭 10�����Ѵ�.
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
		 ���ǿ� �´� ��ü�� �� �� �ִ��� ã�ƺ�����.
		 ���̰� 7�� �̻��� ��ü�� �� �� �ִ��� ã�ƺ�����.

		vector<dog> v{ 5, 7, 3, 6, 9 };

		 1. �Ϲ��Լ��� �����ڷ� ���

		int count = count_if(v.begin(), v.end(), f);

		 2. ���ٸ� �����ڷ� ���

		int count = count_if(v.begin(), v.end(), [](const dog& a)
		{
		 return (a.getage() >= 7);
		});

		 3. �Լ���ü�� �����ڷ� ���


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
		vector<dog> u(move(v)); // �̵� ����
		vector<dog> u = move(v); // �̵� ����
		vector<dog> u = (vector<dog>&&) v; // �̵� ����
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

		vector<dog> v(100, dog(10)); // dog��ü 1000�� ����� v(n, t)
		cout << v.size();
		vector<int> s{ 1, 2, 3, 4, 5 };
		vector<int> v(s.rbegin(), s.rend());
		for (auto d : v)
			cout << d << ends;
		cout << endl;

		 Ű���忡�� ���ϴ� ��ŭ ���ڸ� �Է��ؼ� v�� ����� �ּ���.
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

			 �̰� �ȵǴ� ������ �ڷ���
			vector<int> v{ istream_iterator<int>(cin), istream_iterator<int>() }; // Ű���� ���� ���� Ű���� ������
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
	 �����̳� ��� 306��
	 1. ��� �����̳ʴ� �� ������ �����Ѵ�.
	 2. ���� ���Ҵ� Ư�� ������� ����ȴ�.
	 3. ��� ������ �Ϲ������� ������ �˻����� �ʴ´�.
	 ���� ��������̵������� ���Ұ�쿡�� �����̳��� ���Ҹ� �����ͷ� �����Ͽ� ����Ѵ�.
	 �����̳ʴ� �׻� ���Ҹ� ������ ������ ��ȸ�� �� �־�� �Ѵ�.
	 314�� array - �޸𸮸� ���ÿ� ��µ� ũ�Ⱑ ������ �Ǿ��ִ�.
	 reserve ��� �Լ��� �ǹ� - 486�ʿ� �����ִ�.
	 reserve�� ȣ���� �Ŀ� �����ؼ� ũ�Ⱑ 100���� �ȳѾ����� ��ȿȭ��ä�� �������� ���̴�.
	 333�� ���Ϳ� ���Ͽ� �� �����ִ�.

	int main()
	{
		 �� ������ �̿��ؼ� �Է¹��� �ܾ ������������ �����϶�

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
			cout << "����." << endl;

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

		 100������ ���Ұ� �þ ����

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
		 ����Ʈ�� ��� ����� �����̳��̴�.
		 c2�� c1�� 3, 7 ���� ���̿� �������� ������ �ϵ��ƴϴ�.
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
		 ����Ʈ�� ��� ����� �����̳��̴�.
		 c2�� c1�� 3, 7 ���� ���̿� �������� ������ �ϵ��ƴϴ�.


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

	447�� �� �о��
		�׻� ���� �����̳ʸ� ���� ���� �׷��� ������ �־�� ����ϴ°��̴�.
		�����̳ʸ� ����Ϸ��� �⺻������ vector�� ����϶�.
		vector�� �޸𸮳� ������ �������� �ʰ� ����� �� �ִ�.
		�� ���Ҹ� ���� ���� �ϴ� ��찡 ���� ��� deque, list�� ����Ѵ�.
		�����̳� �߰��� ���� �����ϴ� ���� ��ٸ� list�� ����Ѵ�.

		�ݺ��ڴ� �����͸� �Ϲ�ȭ�����ν� c++ ���α׷����� ���� �ٸ� ������ ������ �̿��ϴ��� �ϰ����� ������� ���α׷� �۾��� �� �� �ֵ��� �Ѵ�.

		�˰��� �Լ� distance�� �� �ݺ��� ���� �Ÿ��� ������ִ� �Լ��̴�.

		dereferencable ������ ������
		�˰��� �Լ� ���忡���� ���޵Ǵ� begin, end �ݺ��ڰ� reachable(���� ������) begin���� ++�����ڷ� end�� �����Ͽ��� ���� �ǹ��Ѵ�.
		valid range - reachable�� �ݺ����� ��
		dereferebceable - �ݺ��ڿ� *�������� ���� access �������� �ǹ�
		mutable - �ݺ��ڰ� ����Ű�� ��ġ�� ���� �� �� ������ �ǹ�

		void f() { cout << "f()" << endl; }
	void f(int) { cout << "f(int" << endl; }
	class test
	{
	public:
		void operator++() { cout << "���ھ��� �Լ�" << endl; }
		void operator++(int) { cout << "�����ִ� �Լ�" << endl; }
	};

	int main()
	{

		f(), f(1);
	}

	���޵� ���ڷκ��� �� ���ڰ� � �Ӽ��� ������ �Ǵ��� �� �ִ�.
		�ݺ��ڷκ��� ���� Ư���� �˾Ƴ� �� �ִ�.


		template<class iter>
	int dist(iter begin, iter end)
	{
		�̰��� ���� �ݺ��ڰ� � �����ΰ��� ��Ÿ����.
			�ݺ����� ������ ���� �Ÿ� ����� �޶����� �Ѵ�.
			�̰��� �ٸ� �Լ��� ȣ���Ͽ� �ذ��Ѵ�.

			iterator_traits<iter>::value_type;
		iterator_traits<iter>::difference_type;
		iterator_traits<iter>::pointer;
		iterator_traits<iter>::reference;

		return dist(begin, end, iterator_traits<iter>::iterator_category());

	}

	������ ���
		template<class iter>
	int dist(iter begin, iter end, random_access_iterator_tag)
	{
		cout << "���� �׼��� �ݺ��ڰ� ���ڷ� ���޵Ǿ���." << endl;

		return end - begin;
	}

	���Ͱ� �ƴ� ���
		template<class iter>
	int dist(iter begin, iter end, forward_iterator_tag)
	{
		int count = 0;
		cout << "�� ���� �ݺ��ڰ� ���ڷ� ���޵Ǿ���." << endl;

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

	*�� �ݺ����� Ư���� ��� ���� �ֱ� ������,
		iterator_traits<t*>�� ���� specialization �Ǿ��ֱ� �����̴�.


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

	540�� ���¸� ���� ����ü
		542�ʰ� ���� ���α׷��� �� �� �ִ�.

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

		cout << "��� ���� : " << ave.value() << endl;
	}

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
		vector<int> v{ istream_iterator<int>(cin), istream_iterator<int>() };


		cout << "��� ���� : " << foreach(v.begin(), v.end(), meanvalue()) << endl;

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

	2016. 6. 8. �� 23(����)(14��)1
		14�� 2 �˰��� / �ֳʱ׷� ����
		15�� 1 �⸻���
		15�� 2 ����Ȯ��

		10. stl �Լ� ��ü�� ���� ���.

#include<iostream>
#include<set>
#include"save.h"

		10�� �Լ� ��ü�� ���� ���.
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
		������ �������� �Լ� ��ü�� ����Ҽ� �ִ�.
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

		
		�ݺ��ڴ� �����͸� �Ϲ�ȭ�����ν� c++ ���α׷����� ���� �ٸ�
		������ ������
		------------------------------------------------------------ -

		�˰��� �Լ� distance�� �� �ݺ��� ���� �Ÿ��� ����� �ִ� �Լ��̴�.

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
		void operator++() { cout << "���� �ִ� �Լ� " << endl; }
		void operator++(int) { cout << "���� �ִ� �Լ�" << endl; }
	};
	void main()
	{

		test a;
		++a; // a.operator++ (���� x) - ������(++) �Ĵ���(=)
		a++; // a.operator++ (���� o) - ������(=)  �Ŀ���(++)
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
		void operator++() { cout << "���� �ִ� �Լ� " << endl; }
		void operator++(int) { cout << "���� �ִ� �Լ�" << endl; }
	};

	void f() { cout << "f()" << endl; }
	void f(int) { cout << "f(int)" << endl; }
	void main()
	{
		f();
		f(1);
		���ڸ� ����ϴ°��� �ƴ϶�, ã�ư��� �뵵�� ���δ�.
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
		���޵� ���ڷκ��� �� ���ڰ� � �Ӽ��� ������ �Ǵ��� �� �ִ�.
			(528��)
			�ݺ��ڷκ��� ���� Ư���� �˾Ƴ� �� �ִ�.
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
		cout << "�Ÿ���" << d << endl;
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
		���޵� ���ڷκ��� �� ���ڰ� � �Ӽ��� ������ �Ǵ��� �� �ִ�.
			(528��)
			�ݺ��ڷκ��� ���� Ư���� �˾Ƴ� �� �ִ�.
			iterator_traits<iter>::iterator_category; -- > �ڷ���
			�̰��� ���� �ں��ڰ� � �����ΰ��� ��Ÿ����.
			�ݺ����� ������ ���� �Ÿ� ����� �޶����� �Ѵ�.
			�̰��� �ٸ� �Լ��� ȣ���Ͽ� �ذ��Ѵ�.
			return dist(b, e, iterator_traits<iter>::iterator_category());
		���� 3�� �ٸ��Լ� �����ε�
	}

	������ ���
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "���� �׼��� �ݺ��ڰ� ���ڷ� ���� �Ǿ���" << endl;
		return e - b;
	}

	527��
		bidirectional(�����)
		input(�Է¸�)
		ouput(��¸�)

		���Ͱ� �ƴ� ���
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "������ �ݺ��ڰ� ���޵Ǿ���" << endl;
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
		cout << "�Ÿ���" << d << endl;
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

	������ ���
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "���� �׼��� �ݺ��ڰ� ���ڷ� ���� �Ǿ���" << endl;
		return e - b;
	}

	���Ͱ� �ƴ� ���
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "������ �ݺ��ڰ� ���޵Ǿ���" << endl;
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
		cout << "�Ÿ���" << d << endl;
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

	������ ���
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "���� �׼��� �ݺ��ڰ� ���ڷ� ���� �Ǿ���" << endl;
		return e - b;
	}

	���Ͱ� �ƴ� ���
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "������ �ݺ��ڰ� ���޵Ǿ���" << endl;
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
		cout << "�Ÿ���" << d << endl;
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

	������ ���
		template<class iter>
	int dist(iter b, iter e, random_access_iterator_tag)
	{
		cout << "���� �׼��� �ݺ��ڰ� ���ڷ� ���� �Ǿ���" << endl;
		return e - b;
	}

	���Ͱ� �ƴ� ���
		template<class iter>
	int dist(iter b, iter e, forward_iterator_tag)
	{
		int cnt{ 0 };
		cout << "������ �ݺ��ڰ� ���޵Ǿ���" << endl;
		while (b != e) {
			cnt++;
			b++;
		}
		return cnt;
	}

	*�� �ݺ����� Ư���� ��� ���� �ֱ⋚����
		iterator_tranits<t*>�� ���� specialization �Ǿ��ֱ� �����̴�.
		�ᱹ 9�忡���� 527���� �����߿��ϴ�.
		void main()
	{
		int a = 10;
		int b = 20;
		cout << &a << endl;
		cout << &b << endl;

		int d = dist(&a, &b);
		cout << "�Ÿ���" << d << endl;
		save();
	}

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include"save.h"

		using namespace std;

	template<class bi_iterator>   // ����� �ݺ���.
	void myreverse(bi_iterator beg, bi_iterator end)
	{
		���ҵ��� ������ ������.
			iterator_traits<bi_iterator>::difference_type
			n = distance(beg, end);
		cout << "�ٲ���� ������ �� : " << n << endl;

		while (n > 0)
		{
			swap �ϱ� ���� �ӽ� ����.
				iterator_traits<bi_iterator>::value_type
				tmp = *beg;
			*beg++ = *--end;
			*end = tmp;
			n -= 2;
		}

	}
	void main()
	{
		�˰��� �Լ� revese()�� ����[b, e)�� ���� ������
		�ݴ�� �ٲٴ� �Լ��̴�.
			�� �Լ��� ���� �����϶�.
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

	template<class fow_iterator>   // ������ �ݺ���.
	void shift_left(fow_iterator beg, fow_iterator end)
	{
		while (beg != end)
		{

		}

	}

	void main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		�ݺ��ڸ� ���ڷ� �޾� �������� ���Ҹ� �� �ڸ� �̵� ��Ű�� �Լ��� �ۼ��϶�.
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

	template<class fwditer>   // ������ �ݺ���.
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
		�ݺ��ڸ� ���ڷ� �޾� �������� ���Ҹ� �� �ڸ� �̵� ��Ű�� �Լ��� �ۼ��϶�.
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

	template<class fwditer>   // ������ �ݺ���.
	void shift_left(fwditer beg, fwditer end)
	{
		528���� ����.
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
		�ݺ��ڸ� ���ڷ� �޾� �������� ���Ҹ� �� �ڸ� �̵� ��Ű�� �Լ��� �ۼ��϶�.
			shift_left(v.begin(), v.end());
		rotate(v.begin(), v.begin() + 1, v.end());


		�� ���α׷��� �� ����Ǵ°� ?
			�����ʹ� �ݺ��ڸ� ������� Ư���� ���� �ֱ� ������
			�������� ���� ���� �Ϲ�ȭ�� ����.
			���������� - �ݺ��� ������ ����.

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

	531��.
		ǥ�ع����� ��
		����ڰ� �ڽ��� ���� ����Ʈ���� ��ȸ�� �� �ִ�
		binarytreeiterator�� ���� �Ѵٰ� �����غ���.
		template<class t>
	class binarytreeiterator<t>
	{

	};

	template<class t>
	struct iterator_traits<binarytreeiterator<t>> // 1.
	{
		5���� type
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

	�̿� ���� ������ ���� ������

		531�� �Ʒ��κа� ���� Ŭ������ ��ӹ޾� ���� ���� �ִ�.
		532�ʿ��� ����Ǵ� ����� ���� �ݺ��� Ŭ������ �� �� �ִ�.

		void main()
	{
		������ �ݺ��ڸ� ����� �ʹ�.��� �ϸ� �ǳ� ?
			1. iterator_traits ������ ���� �ʼ� �ټ����� �ڷ����� �����Ѵ�.
			2. iterator_traits ������ ����(�κ�) Ư��ȭ�� �����Ѵ�.


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

		cout << "anagram�� ã�� ���α׷�" << endl;

		cout << "���� ������ �Է��ϼ���." << flush;


		cout << endl;
		ifstream ifs("diction");

		if (!ifs.is_open())
		{
			cout << "������ ���� �� �����ϴ�." << endl;
			exit(0);
		}

		copy(istream_iterator<string>(ifs), istream_iterator<string>(), back_inserter(v));

		cout << "���" << v.size() << "���� �ܾ �о����ϴ�." << endl;

		���̵�� //

			���� �ܾ�� �� �ܾ ������ �ܾ �ϳ��� ������ �����.
			v�� first �������� �����Ѵ�.

			sort(v.begin(), v.end(), [](const ps& a, const ps& b)
		{
			return a.first < b.first;
		});

		ó������ ������ �����س��� �ܾ �������� ���� ��ġ�� ���� ��ġ�� �ܾ ���� ���� ã�´�.
			�߰��ߴٸ�(if) �߰��� ��ġ���� ���� ���� �ܾ ������ ��ġ�� ã�´�.

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

			����(j, k)������ anagram �̴�.
				cout << "[" << i++ << "] ";
			copy(j, k, ostream_iterator<string>(cout, " "));
			cout << endl;

			j = k;

		}


	}

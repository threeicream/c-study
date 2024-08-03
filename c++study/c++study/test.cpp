#include <iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏
#include"test.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;

int xyz()
{
	static int a = -1;
	return ++a;
}

void diaohuan(int* i, int* j)
{
	int a;
	a = *i;
	*i = *j;
	*j = a;
}

void diaohuan_1(int &i, int &j)
{
	int a;
	a = i;
	i = j;
	j = a;
}

size_t find_char(const string& a, char b, size_t& c)
{
	auto ret = a.size();
	c = 0;
	for (decltype(ret)i = 0; i != a.size(); i++)
	{
		if (a[i] == b)
		{
			if (ret == a.size())
				ret = i;
			++c;
		}
	}
	return ret;
}

int daxie(const string& a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		if (isupper(*i))
		{
			return 1;
		}
	return 0;
}

void bianxiaoxie(string& a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		*i = tolower(*i);
}

int daxiao(int a, int* b)
{
	if (a > *b)
		return a;
	else
		return *b;
}

void jiaohuan_zhizhen(int*& a, int*& b)
{
	int *i = a;
	a = b;
	b = i;
}

void print(int(&a)[2])
{
	for (auto b : a)
		cout << b << endl;
}

void msg(initializer_list<string> a)
{
	for (auto x = a.begin(); x != a.end(); ++x)
		cout << *x << endl;
}

int sum_int(initializer_list<int> a)
{
	int i = 0;
	for (auto x = a.begin(); x != a.end(); ++x)
		i += *x;
	return i;
}

char &get_val(string& str, rsize_t ix)//这个&符号代表返回的类型是char &，是引用类型，可以修改的
{
	return str[ix];
}

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size)i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return i;
	}
}

void fac(vector<int>x,unsigned y)
{
	unsigned vz = x.size();
	if (!x.empty() && y < vz)
	{
		cout << x[y] << endl;
		fac(x, y + 1);
	}
}

string(&funct(int i))[10]
{
		string a[10] = { "f"};
		return a;
}

using act = string[10];
act& funct_1(int i)
{
	string a[10] = { "f" };
	return a;
}

auto funct_2(int i) -> string(&)[10]
	{
		string a[10] = { "f" };
		return a;
	}

string biemingtest[10] = { "f" };
decltype(biemingtest)& funct_3(int i)
{
	string a[10] = { "f" };
	return a;
}

string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

void factorial(vector<int>x,unsigned index)
{
	unsigned i = x.size();
	if (!x.empty() && index != i)
	{
		cout << x[index] << endl;
		factorial(x, ++index);
	}
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

//Person类的输入和输出函数
istream& read(istream& is, Person& item)
{
	is >> item.Name >> item.Address;
	return is;
}
ostream& print(ostream& os, const Person& item)
{
	os << item.re_name() << item.re_address();
	return os;
}
#ifndef TEST_H
#define TEST_H

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;

class Person//Person类
{
	string Name;
	string Address;
public:
	// 默认构造函数
	Person() = default;

	string re_name()const { return Name; }
	string re_address()const { return Address; }
	// 将 read 函数声明为友元函数
	friend istream& read(istream& is, Person& item);
	friend ostream& print(ostream& os, const Person& item);
};
istream& read(istream& is, Person& item);
ostream& print(ostream& os, const Person& item);

class Person1 {
private:
	string name;
	int age;

public:
	// 默认构造函数
	Person1() : name(""), age(0) {}

	// 带参数的构造函数
	Person1(string n, int a) : name(n), age(a) {}

	// 只有名字的构造函数
	Person1(string n) : name(n), age(0) {}

	// 拷贝构造函数
	Person1(const Person1& other) : name(other.name), age(other.age) {}

	// 成员函数
	void display() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};
/*Person1 p1;                  // 调用默认构造函数
	Person1 p2("Alice", 25);     // 调用带两个参数的构造函数
	Person1 p3("Bob");           // 调用只有名字的构造函数
	Person1 p4 = p2;             // 调用拷贝构造函数*/

int xyz();
void diaohuan(int* i, int* j);
void diaohuan_1(int& i, int& j);
size_t find_char(const std::string& a, char b, size_t& c);
int daxie(const string& a);
void bianxiaoxie(string& a);
int daxiao(int a, int* b);
void jiaohuan_zhizhen(int*& a, int*& b);
void print(int(&a)[2]);
void msg(initializer_list<string> a);
int sum_int(initializer_list<int> a);
char& get_val(string& str, rsize_t ix);
bool str_subrange(const string& str1, const string& str2);
void fac(vector<int>x, unsigned y);
string make_plural(size_t ctr, const string& word, const string& ending = "s");
constexpr int new_sz()
{
	return 42;
}
constexpr int scale(size_t i)
{
	return new_sz() * i;
}
inline bool isshorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
void factorial(vector<int>x, unsigned index);
int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divide(int a, int b);

#endif
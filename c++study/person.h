#ifndef PERSON_H
#define PERSON_H

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
	mutable size_t access;
public:
	// 默认构造函数
	Person() = default;
	Person(const string& n, const string& a) :Name(n), Address(a) {}
	explicit Person(istream& is) { read(is, *this); }
	//接口函数，通过此函数才能访问private成员
	string re_name()const { return Name; }
	string re_address()const { return Address; }
	void some_member() const { ++access; }
	// 将 read 函数声明为友元函数,从而可以直接访问私有成员
	friend void read(istream& is, Person& item);
	friend ostream& print(ostream& os, const Person& item);
};
void read(istream& is, Person& item);
ostream& print(ostream& os, const Person& item);
//Person::Person(istream& is)
//{
//	read(is, *this);
//}
//void Person::some_member()const//外部构建成员函数时格式，显示构造
//{
//	++access;
//}

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
/*	Person1 p1;                  // 调用默认构造函数
	Person1 p2("Alice", 25);     // 调用带两个参数的构造函数
	Person1 p3("Bob");           // 调用只有名字的构造函数
	Person1 p4 = p2;             // 调用拷贝构造函数*/

class house
{
private:
	vector<Person>persons{ Person("jack","china") };

};

#endif // !PERSON_H




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

class Person//Person��
{
	string Name;
	string Address;
	mutable size_t access;
public:
	// Ĭ�Ϲ��캯��
	Person() = default;
	Person(const string& n, const string& a) :Name(n), Address(a) {}
	explicit Person(istream& is) { read(is, *this); }
	//�ӿں�����ͨ���˺������ܷ���private��Ա
	string re_name()const { return Name; }
	string re_address()const { return Address; }
	void some_member() const { ++access; }
	// �� read ��������Ϊ��Ԫ����,�Ӷ�����ֱ�ӷ���˽�г�Ա
	friend void read(istream& is, Person& item);
	friend ostream& print(ostream& os, const Person& item);
};
void read(istream& is, Person& item);
ostream& print(ostream& os, const Person& item);
//Person::Person(istream& is)
//{
//	read(is, *this);
//}
//void Person::some_member()const//�ⲿ������Ա����ʱ��ʽ����ʾ����
//{
//	++access;
//}

class Person1 {
private:
	string name;
	int age;

public:
	// Ĭ�Ϲ��캯��
	Person1() : name(""), age(0) {}

	// �������Ĺ��캯��
	Person1(string n, int a) : name(n), age(a) {}

	// ֻ�����ֵĹ��캯��
	Person1(string n) : name(n), age(0) {}

	// �������캯��
	Person1(const Person1& other) : name(other.name), age(other.age) {}

	// ��Ա����
	void display() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};
/*	Person1 p1;                  // ����Ĭ�Ϲ��캯��
	Person1 p2("Alice", 25);     // ���ô����������Ĺ��캯��
	Person1 p3("Bob");           // ����ֻ�����ֵĹ��캯��
	Person1 p4 = p2;             // ���ÿ������캯��*/

class house
{
private:
	vector<Person>persons{ Person("jack","china") };

};

#endif // !PERSON_H




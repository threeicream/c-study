#ifndef TEST_H
#define TEST_H

#include <iostream>//��д����������
#include<fstream>//��д�����ļ�������
//#include <filesystem>//C++17���ļ�ϵͳ��
#include<sstream>//��д�ڴ�string���������
#include <typeinfo>
//˳������
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<array>

#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
#include"person.h"

using namespace std;//һ���Ͱ�����usingȫ��Ч��
typedef string::size_type sz;


class screen
{
public:
	using pos = string::size_type;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
public:
	//���캯����ʼ������=���Ÿ�ֵ������е�
	screen() = default;
	//screen() :screen(1, 0, 0, ' ') { cout << "�������κ���Ϣ" << endl; }
	screen(const pos& h, const pos& w) :screen(0, h, w, ' ') { cout << "����������Ϣ" << endl; }
	screen(const pos& h, const pos& w, char c) :screen(0,h,w,'c') { cout << "����������Ϣ" << endl; }
	screen(const pos& cu,const pos& h, const pos& w, char c) :cursor(cu),height(h), width(w), contents(h* w, c) { cout << "�����ĸ���Ϣ" << endl; }
	void re_width(pos i) { width = i; }
	//pos re_width() { return width; }
	pos re_height()const { return height; }//��ʽ����
	string re_contents() { return contents; }//��ʽ����
	pos size_t()const;
	screen& set(char);//screen s1;s1.set('h');
	screen& set(pos, pos, char);
	screen& move(pos, pos);
	screen& display(ostream& os) { do_display(os); return *this; }
	const screen& display(ostream& os) const { do_display(os); return *this; }
	friend class windows_ctr;
	//friend void windows_ctr::clear(screenindex);
private:
	void do_display(ostream& os) const { os << contents; }
};
inline screen& screen::set(char c)//��ʾ����
{
	contents[cursor] = c;
	return *this;
}
inline screen& screen::set(pos h, pos cu, char c)
{
	contents[h * width + cu] = c;
	return *this;
}

class windows_ctr
{
public:
	using screenindex = vector<screen>::size_type;
	void clear(screenindex);
	screenindex addscreen(const screen&);
	void c_out()const { cout << screens[0].height << ' ' << screens[0].width << '\n' << screens[0].contents << endl; }
private:
	vector<screen>screens{ screen(5,6,'x') };
};

class X
{
	int i;
	int j;
public:
	X(int val):j(val),i(j){}
};

//void someFunction(const screen& s) {
//	s.display(cout); // ���Ե��� const ��Ա����
//	s.re_contents();// ���ܵ��÷� const ��Ա����
//}

class NoDefault
{
public:
	NoDefault(int i) { x = i; }
	int x;
};

class C
{
public:
	NoDefault no;
	C(int i=0):no(i){}
};

class Debug
{
public:
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() const { return hw || io || other; }
	void set_hw(bool b) { hw = b; }
	void set_io(bool b) { io = b; }
	void set_other(bool b) { other = b; }
private:
	bool hw;
	bool io;
	bool other;
};

class Point {
public:
	constexpr Point(int x = 0, int y = 0) : x_(x), y_(y) {}

	constexpr int getX() const { return x_; }
	constexpr int getY() const { return y_; }

private:
	int x_;
	int y_;
};

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
string(&funct())[10];
istream& f(istream& in);
void forwardlist(forward_list<string>& x, const string i, const string j);
void ins(string& s, const string& oldval, const string& newval);
void replace_string(string& s, const string& oldVal, const string& newVal);
void replace1_string(string& s, const string& oldVal, const string& newVal);
string inis(string& s, const string& n, const string& o);
string name_string(string& s, const string& n, const string& o);
void find_string1(string& s, const string& chars);
void find_string2(string& s, const string& chars);
vector<string> nn(istream& in, const string& shang, const string& xia);
bool five_or_more(const string& s1, string::size_type sz);
bool isshorter1(const string& a, const string& b);
#endif
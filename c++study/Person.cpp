#include <iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏
//#include"test.h"
#include"person.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;

//Person类的输入和输出函数
void read(istream& is, Person& item)
{
	is >> item.Name >> item.Address;
	//return is;
}
ostream& print(ostream& os, const Person& item)
{
	os << item.re_name() << ' ' << item.re_address();
	return os;
}
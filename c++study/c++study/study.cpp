#include <iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏  assert(x);x为假，输出信息并终止程序运行
#include"test.h"


//#include "Sales_item.h"
/*
一、
输出>>要接着<<std::endl，这个保证buffer里面所有的数据都输出到输出流中
二、
int a = 09;//有个0就自动变成八进制
初始化：
int a=0;
int a={0}
int a{0}
int a(0)

声明：extern int i;//使得名字为程序所知
定义：extern int i=10;//负责创建名字关联的实体
声明且定义：int i;
引用：int a=5; int &b=a;//b就是a的别名，引用只能绑定变量
	int i = 10;
	int* p = &i;
	int*& a = p;
	*a = 4;
	std::cout << i;

 ::i是全局变量 外层作用域
 i是局部变量 内层作用域

 空指针：
 int *p=0；
 int *p=NULL；//nullptr
 NULL和nullptr区别：
 类型：NULL 是一个整数常量，通常定义为 0。nullptr 是类型为 std::nullptr_t 的常量。
 转换：NULL 可以隐式转换为整数类型，这可能导致函数重载选择的问题。nullptr 只能隐式转换为指针类型，避免了上述问题。
 安全性：使用 nullptr 更加安全和明确，尤其是在函数重载和模板编程中。

 void*类型可以存放任意对象的地址

 const初始化：const的对象一定要初始化,除了指针，但是没啥意义
 const int *const i=&a\\指向int类型常量的常量指针
 const int &r=1;\\合法
 int &r=1;\\不合法，变量不能引用常量
 const int* p;\\合法，但是p没有值，没有任何意义
 
 constexpr
 顶层const：对象，常量指针			    不允许改变 允许拷贝赋值（指针：本身是常量，能修改指向常量的值，但是不可以修改指向的地址）
 底层const：指向常量的指针,引用         允许改变   不允许拷贝赋值（指针：通过指针或者引用指向常量，不能修改指向常量的值，但是可以修改指向的地址）
 1.对象：	                            const=变量 不合法，但是变量=const 合法
 2.指向常量的指针or引用：			    变量=const 不合法，但是const=变量 合法//常量
	int i = 10;
	const int a = 5;
	i = a;//合法
	a = i;//非法
	int* p2;
	const int& p1 = i;//合法
	p2 = &a;//非法
	std::cout << p1;
 3.常量指针：无论无何都不能改变，一创建就要初始化 常量指针只能=变量，不能=const
	int * const p1=NULL;
	constexpr const int *p2=NULL;
	constexpr int *p3=NULL;
 2和3的区别：
 指向常量的指针
 指向常量的指针是一个指向常量数据的指针，这意味着通过这个指针不能修改它所指向的值。
 常量指针
 常量指针是指针本身是常量，这意味着一旦指针初始化后，不能改变它的指向，但可以通过指针修改它所指向的数据。

 const char*p="love";//right
 char*p="love";//erro
 cout<<p;//输出love
 cout<<*p;//输出l

 const constexpr 区别：
 计算时间:
 const 在运行时计算。
 constexpr 在编译时计算。
 使用范围:
 const 可以用于任何需要不可变值的地方，但值可能在运行时计算。
 constexpr 用于需要在编译时确定值的地方，如数组大小、模板参数等。
 限制:
 const 常量可以在运行时初始化，也可以通过复杂的表达式来赋值。
 constexpr 常量必须在编译时初始化，表达式中的所有值和操作都必须是编译时常量。

 size_t
 定义：size_t 是标准库中的一种类型定义，通常用于表示对象的大小和数组的索引。它在 <cstddef> 头文件中定义。
 用途：size_t 被广泛用于标准库函数，如 malloc、sizeof 等，表示内存大小和数组索引。由于它是无符号类型，可以确保不会出现负值。
 标准定义：size_t 的定义依赖于平台，它通常被定义为无符号整数类型，能够表示最大可能的内存大小。
 size_type
 定义：size_type 是 C++ 标准库容器（如 std::vector、std::string 等）中的一种类型定义。每个容器都有自己的 size_type。
 用途：size_type 主要用于表示容器的大小和索引。由于不同容器可能有不同的实现，size_type 提供了一种与容器实现无关的方式来表示大小和索引。
 容器相关：size_type 是与具体容器相关的类型定义。例如，std::vector<int>::size_type 是 std::vector<int> 的大小类型。std::vector<int>::size_type i = 0代表索引
 iterator:迭代器的专属类型，每个容器都有自己的iterator

 类型别名：
 typedef double wage;
 typedef wage base,*p;
 using SI=Sales_item;
 typedef int arr[10];//与下面等效
 using arr = int[10];

 typedef char *pstring;
 const pstring cstr = 0;              //使用别名时，定义了一个本身是常量的指针（const修饰pstring这个整体）
 const char *cstr1 = 0;               //直接替换时，定义了一个指向常量的指针（const修饰char）

 auto类型：编译器通过初始值判断类型，所以必须得有初始值
 auto忽略顶层，保留底层
 对常量对象取地址是一种底层const

 decltype()：编译器不实际计算表达式的值//引用其他变量的类型
 保留顶层
 对于表达式，或者多个（），全部视为int &类型，解引用操作的变量也视为int &类型
 typeid(p).name()

 string s1
 string s2(s1)
 string s2=s1
 string s3(n,"c")
 string s1 = "fuck you baby";
 s1.empty();
 s1.length(); s1.size();//字符长度
 s1.find("baby");
 s1.replace(6, 3, "me");
 s1.erase(6, 2);//删除
 s1.insert(4,"you")；//插入
 getline(cin,s);//返回一行，只有收到换行符了才返回

 string+字面值：必须string类型在前面
 string s4=s+",";
 	isalnum(c);
	isalpha(c);
	iscntrl(c);
	isdigit(c);
	isgraph(c);
	islower(c);
	isprint(c);
	ispunct(c);
	isspace(c);
	isupper(c);
	isxdigit(c);
	tolower(c);
	toupper(c);
	针对字符串s1的每一个字符
	for (auto b : s1)
		cout << b << endl;

 vector(容器、类模板),大小不固定，这点比数组好
 vector<int>a;//列表，拥有多个元素，就是动态数组
 vector<int>a(10,1);//构造十个元素，值都为1
 vector<int>a{10,1};//构造两个元素，分别为10、1
 v1.push_back(1);//尾端插入1个元素，值为1

 迭代器：跟指针比较像(指针也是迭代器)
 vector<int>v;
 v.begin()元素/字符首位 变量()
 v.end()元素/字符末位 变量
 const vector<int>cv;
 cv.cbeign()	常量
 cv.cend() 常量
 auto i=v.begin()
 (*i).empty()==i->empty()
 *(v.begin())就是v第一个元素的值

 数组：从内到外的顺序来阅读理解含义
 指针：可以使用begin()、end()函数查找数组的首元素和尾元素
 数组初始化vector：
 int a[]={1,2,3,4};
 vector<int>x={begin(a),end(b)};//1 2 3 4
 vector<int>x = { a + 1,a + 4 };//2 3 4
 c++可以说没有多维数组，多维数组就是数组的数组
 for循环控制多维数组，除了内层循环，其他循环的控制变量都必须是&引用类型
 int it[3][4];
 for (auto p = it; p != it + 3; p++)
		for (auto q = *p; q != *p+4; q++)
			cout << *q << ' ';

 移位运算符适用左结合律，？：适用右结合律
 条件运算优先级高于逗号

 显示转换：（一般不推荐）
 1.static_cast:强制转换除了底层const以外的类型(有点鸡肋，指针方面只能针对void)用于相关类型之间的转换，如基本类型之间（如 int 到 float）、类层次结构中基类和派生类之间的转换、以及 void 指针与具体类型指针之间的转换。
 int a = 1;
 void* c = &a;
 double* b = static_cast<double*>(c);
 2.const_cast:主要用于移除或添加底层const性，转换为其他类型不行
 const char* a;
 char* b = const_cast<char*>(a);//right
 string* b = const_cast<string*>(a);//erro，不能将char*转换为string*
 3.reinterpret_cast:用于在几乎任意类型之间进行转换，通常是用于指针类型之间的转换。这种转换是逐比特进行的，没有任何形式的检查和保证。
 int*a;
 char*b=reinterpret_cast<char*>(a);

 cin.get(a);//不会忽略其他特殊符号
 范围for循环
 for(auto b:v)//遍历v中的所有元素

 try语句如何使用
 while(cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("除数不能为0");//用于引发异常，可以引发任何类型的异常（如整数、字符串、自定义异常类等）。一旦执行到 throw 语句，try 块中剩余的代码将不再执行。
			cout << a / b << endl;
		}
		catch (runtime_error &e)//用于捕捉和处理异常。
		{
			cerr << e.what() << "需要继续吗" << endl;//e.what()弹出“除数不能为0”
			char ch;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
				break;
		}
		catch (...)
		{
			cerr << "unknown exception" << endl;
		}
	}
 
 对于循环
 值传递：传统方式
 引用传递：1.避免拷贝过多对象2.直接操作实参3.可以引用形参从而传出更多的值(一般用于类类型或容器类型（如string），避免拷贝对象过多)

 数组作为形参：三者等价，且都是将数组转换成指针类型
 void print(const int*)
 void print(const int[])
 void print(const int[10])//这种限制了使用大小，可以大，不能小
 数组不能直接被函数返回，有四种迂回方式：
 1.直接引用 funct
 2.别名
 3.尾置返回
 4.decltype

 int a[10];//a是一个含有10个整数的数组
 int*p1[10];//p1是一个含有10个整型指针的数组
 int(*p2)[10]=&a;//p2是一个指向含有10个整型数组的指针

 含有可变形参的函数：
 initializer_lists<int>x;//跟vector比较像，但是ini只能只读，对应元素是常量

 函数重载：
 同一命名的函数，不一样的功能
 顶层const无法区分函数
 形参数量或者形参类型不同才能区分出来

 默认实参应该放在头文件中，而且必须使用全局变量
 某个形参被赋予了默认实参，则它后面的所有形参都必须有默认实参。
 (a) int ff(int a, int b = 0, int c = 0);//right
 (b) char *init(int ht = 24, int wd, char bckgrnd);//error
 不能修改一个已经设定好的默认值

 constexpr、内联inlink函数都必须在头文件中定义
 constexpr：1.只有一条return语句2.返回值必须是常量表达式

 函数指针：（函数作为形参就是指针类型）
 1假设我们有一个函数int func(int, int)，定义函数指针的方法如下
 int (*func_ptr)(int, int);
 2将函数地址赋值给函数指针
 func_ptr = &func; // 或者直接 func_ptr = func;
 3使用函数指针调用函数
 int result = func_ptr(2, 3);
 
 函数指针形参
 1定义接受函数指针作为参数的函数
 void callFunction(int (*func)(int, int), int a, int b) 
 {
	int result = func(a, b);
	std::cout << "Result: " << result << std::endl;
 }
 2调用带有函数指针形参的函数
 int add(int a, int b) 
 {
	return a + b;
 }

int main() 
{
	callFunction(add, 5, 3);
	return 0;
 }
 数组(指针和引用)和函数指针都不能直接返回，只能迂回
 1.别名
   using PF=int(*)(int*);//PF为函数指针类型
   using F=int(int*);//F为函数类型
   PF f1(int);等效为F *f2(int);
 2.直接引用
   int(*f1(int))(int*);
 3.尾置返回
   auto f1(int)->int (*)(int*);
 4.decltype
   int xyz(int*);
   decltype(xyz) *f1(int);
 定义返回函数指针的函数
 int (*getFunction(char op))(int, int) 
 {
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }

	if (op == '+') {
		return add;
	} else if (op == '-') {
		return subtract;
	} else {
		return nullptr;
	}
 }
 调用返回函数指针的函数
 int main() {
	char op = '+';
	int (*func_ptr)(int, int) = getFunction(op);

	if (func_ptr != nullptr) {
		int result = func_ptr(10, 5);
		std::cout << "Result: " << result << std::endl;
	} else {
		std::cout << "Invalid operation" << std::endl;
	}

	return 0;
}

类：关键词 public private protected
class成员一律默认私有
struct成员一律默认公共
通用惯例：
成员变量private，成员函数public
类定义外部:
class xyz{int area();};
int xyz::area(){return w;}:

this指针（隐式执行）：
int area(){return w;};     r1.area();
int area(xyz *this){return (this->w)};    r1.area(&r1);
注意事项：
1.this为系统生成，不可自己定义
2.仅可在成员执行内部使用（member function）
3.this指针指向不能改变，为const pointer类型（顶层const）
 
 常量成员函数：
 string isbn() const { return bookno; }//这种写法表示的是 isbn 函数是一个 常量成员函数，它不会修改类的任何成员变量。
 具体作用
 1保护成员变量：在常量成员函数中，不能修改类的成员变量。这样可以防止无意中改变对象的状态，提高代码的安全性和可靠性。
 2允许常量对象调用：只有常量成员函数才能被常量对象（用 const 修饰的对象）调用。
 class Book {
public:
	string isbn() const { return bookno; } // 常量成员函数
private:
	string bookno;
};

int main() {
	const Book myBook;  // 常量对象
	cout << myBook.isbn() << endl;  // 合法，调用常量成员函数
	// myBook.setBookno("12345");  // 非法，常量对象不能调用非常量成员函数
	return 0;
}
*/

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;

//编写冒泡排序

int main()
{
	using namespace std;
	
	return 0;
}

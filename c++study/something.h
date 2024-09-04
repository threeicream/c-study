/*
C++ 和 C 是两种广泛使用的编程语言，它们在多个方面有显著区别：

### 1. **面向对象编程 (OOP)**
- **C++**: 支持面向对象编程。它引入了类和对象的概念，可以封装数据和函数，还支持继承和多态。
- **C**: 是面向过程的编程语言，不支持类和对象的概念。

### 2. **函数和方法**
- **C++**: 函数可以是类的一部分（称为方法）。C++ 支持函数重载和运算符重载。
- **C**: 所有的函数都是全局的，不支持函数重载和运算符重载。

### 3. **标准库**
- **C++**: 拥有丰富的标准模板库 (STL)，包括容器类、算法和迭代器。
- **C**: 标准库相对简单，主要包括输入/输出操作、字符串操作和内存分配等基本功能。

### 4. **内存管理**
- **C++**: 除了传统的 C 风格的内存管理（`malloc` 和 `free`），还支持新的和删除操作符（`new` 和 `delete`），并引入了 RAII（资源获取即初始化）等高级特性来简化内存管理。
- **C**: 主要依赖手动管理内存，使用 `malloc` 和 `free` 函数。

### 5. **模板**
- **C++**: 支持模板编程，允许编写泛型代码，可以创建通用的数据结构和算法。
- **C**: 不支持模板编程。

### 6. **异常处理**
- **C++**: 支持异常处理机制，使用 `try`、`catch` 和 `throw` 关键字。
- **C**: 不支持异常处理机制，错误处理通常通过返回值和全局变量（如 `errno`）来实现。

### 7. **命名空间**
- **C++**: 引入了命名空间（`namespace`）以避免命名冲突。
- **C**: 没有命名空间的概念，命名冲突是一个常见的问题。

### 8. **编译器支持**
- **C++**: 现代编译器（如 g++, clang++）支持 C++ 的所有特性，并持续更新。
- **C**: 传统编译器（如 gcc，clang）支持 C 的所有特性，并相对稳定。

### 9. **使用领域**
- **C++**: 广泛应用于系统软件、游戏开发、实时系统、大型项目等需要高性能和复杂性的领域。
- **C**: 主要用于系统编程（如操作系统、嵌入式系统）、底层编程和性能要求极高的领域。

### 10. **兼容性**
- **C++**: 基本上是 C 的超集，几乎所有 C 程序都可以在 C++ 编译器下编译运行，但反之不成立。
- **C**: 不支持 C++ 特性，因此 C++ 代码不能直接在 C 编译器下编译。

通过这些差异可以看出，C++ 提供了更多的高级特性和编程工具，使得编写复杂应用程序更加方便，而 C 则以其简单和高效被广泛应用于底层系统和性能关键的场景。





面向对象编程 (OOP) 和面向过程编程 (POP) 是两种不同的编程范式，各有其特点和适用场景。下面对它们进行详细解释：

### 面向过程编程 (Procedural Programming)
面向过程编程是一种以过程（即函数或子程序）为中心的编程范式，主要关注的是解决问题的步骤和逻辑。

#### 主要特点：
1. **模块化**：将程序分解成若干个函数，每个函数完成特定的任务。
2. **函数调用**：通过调用函数来执行特定的任务，函数可以互相调用。
3. **顺序执行**：程序按照代码的顺序逐步执行。
4. **全局数据**：数据可以在函数之间共享，通常通过全局变量。
5. **重用性**：通过函数的复用，提高代码的重用性。

#### 优点：
- 简单直接，容易理解和实现。
- 对于小型、简单的程序非常有效。
- 执行效率高，内存占用少。

#### 缺点：
- 随着程序规模的增大，代码维护变得复杂。
- 数据和函数之间的关系较为松散，难以进行数据保护和隐藏。
- 缺乏抽象和封装，难以应对复杂的应用场景。

### 面向对象编程 (Object-Oriented Programming)
面向对象编程是一种以对象为中心的编程范式，主要关注的是数据及其操作方法的封装和抽象。

#### 主要特点：
1. **对象**：将数据和操作这些数据的方法封装在一起，称为对象。
2. **类**：对象的模板或蓝图，通过类可以创建多个具有相同属性和行为的对象。
3. **封装**：通过将数据和方法封装在对象内部，实现信息隐藏。
4. **继承**：子类继承父类的属性和方法，代码重用性高。
5. **多态**：通过接口或继承，实现不同对象对同一方法的不同实现。
6. **抽象**：通过抽象类和接口，定义对象的通用行为。

#### 优点：
- 提高代码的可维护性和可扩展性。
- 通过封装实现信息隐藏，提高代码的安全性。
- 通过继承和多态实现代码的重用和灵活性。
- 更容易实现复杂的应用场景和大型项目。

#### 缺点：
- 初学者学习曲线较陡峭，理解和实现复杂。
- 程序执行效率可能低于面向过程编程。
- 需要更多的内存和处理能力。

### 总结
- **面向过程编程**：适用于小型、简单的程序，强调过程和函数，关注解决问题的步骤。
- **面向对象编程**：适用于大型、复杂的程序，强调对象和类，关注数据和操作方法的封装和抽象。

这两种编程范式各有其适用场景，开发者可以根据具体需求选择合适的编程方法。

int main()//针对读取行的一种方法，另一种方法是使用istringstream L(s)构建字符串流，再使用while(L>>word)读取单词
{
	using namespace std;
	vector<string>v1 ;
	string s;
	while (getline(cin, s))
		v1.push_back(s);
	for (auto it = v1.begin(); it != v1.end() && !it->empty(); it++)
	{
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
			*it2 = toupper(*it2);
	}
	for (auto a : v1)
		cout << a << endl;

	return 0;
}
//其中，v1.begin() 返回的是一个指向 vector<string> 中第一个 string 元素的迭代器，而 it->begin() 返回的是一个指向 string 中第一个字符的迭代器。
在你的代码中，it 是一个 vector<string>::iterator，因此 it->begin() 是一个 string::iterator。
这两个迭代器的类型和语义完全不同，所以不能将 v1.begin() 直接替换为 it->begin()。

{
int it[3][4];
	size_t cnt = 0;
	for(auto &row:it)
		for (auto& col : row)
		{
			col = cnt;
			cnt++;
		}
	/*for (int(&a)[4] : it)
		for (int b : a)
			cout << b << ' ';*/

	/*for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++)
			cout << it[i][j] << ' ';*/

	//for (int_arry* p = begin(it); p != end(it); p++)
		//for (int* q = begin(*p); q != end(*p); q++)
			//cout << *q << ' ';

	/*for (auto p = it; p != it + 3; p++)
		for (auto q = *p; q != *p+4; q++)
			cout << *q << ' ';*/
//}
/*
 __func__
 __FILE__
 __TIME__
 __DATE__
 NDEBUG 是一个预处理宏，用于控制 C++ 中的断言（assertions）。
 当定义了 NDEBUG 时，所有的 assert 宏调用都会被忽略，即断言会被禁用。
 这通常在发布（release）版本中使用，以提高程序的运行效率，因为在发布版本中不需要进行断言检查。
*/



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
 顶层const：对象，常量指针			    不允许改变 允许拷贝赋值（指针：本身是常量，能修改指向常量的值，但是不可以修改指向的地址）变量本身是常量，不能修改。意味着指针/对象本身是一个常量
 底层const：指向常量的指针,引用         允许改变   不允许拷贝赋值（指针：通过指针或者引用指向常量，不能修改指向常量的值，但是可以修改指向的地址）指针或引用所指向的对象是常量，不能通过指针或引用修改对象。
 1.对象：	                            const=变量 不合法，但是变量=const 合法        不对，不要理解
 2.指向常量的指针or引用：			    变量=const 不合法，但是const=变量 合法//常量  不对，不要理解
	int i = 10;
	const int a = 5;//这是初始化
	i = a;//合法，这是拷贝赋值
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
 // 声明一个函数类型
typedef int (PTypeFun1)(int, int);

// 声明一个函数指针类型
typedef int (*PTypeFun2)(int, int);


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
封装、继承、多态是类的三个特性，本题首先考查封装的含义。
封装是指保护类的成员不被随意访问的能力。通过把类的实现细节设置为private，我们就能完成类的封装。封装实现了类的接口和实现的分离。
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

 构造函数：
 1.默认构造函数：当没有提供构造函数时，编译器会自动生成一个默认构造函数，默认构造函数的作用是创建一个对象，并将对象的成员变量初始化为默认值。
 2.有参数的构造函数：有参数的构造函数的作用是创建一个对象，并将对象的成员变量初始化为提供的参数值。
 3.拷贝构造函数：拷贝构造函数的作用是创建一个对象并将它的成员变量初始化为一个已存在对象的成员变量的值。
 不能是const，可以是constexpr，没有return
 在内的外部定义构造函数：
 Person1::Person1(istream &is)
 {
	read(is, *this);//调用Person类中的read函数，从is中读取数据到*this
 }

 const screen& display(ostream& os) const { do_display(os); return *this; }
 1.第一个 const（返回值前的 const）：
 这个 const 修饰返回值类型 screen&。它表示返回的 screen 对象是一个常量引用。这意味着：
 返回的对象不能被修改
 通过这个返回值只能调用 const 成员函数
 这保证了函数调用后不能通过返回的引用来修改对象的状态。
 2.第二个 const（函数参数列表后的 const）：
 这个 const 修饰整个成员函数。它表示这是一个常量成员函数。这意味着：
 该函数不能修改调用它的对象的任何非 mutable 成员变量
 该函数只能调用其他的 const 成员函数
 该函数可以被 const 对象调用
 这保证了函数不会改变对象的状态，增加了代码的安全性和可读性。
 这两个 const 的组合使得：
 函数可以被 const screen 对象调用
 函数不会修改调用它的 screen 对象
 函数返回一个不可修改的 screen 引用

 友元函数：friend istream& read(istream& is, Person& item);//read函数可以调用Person类的item成员
 类型成员：using pos=std::string::size_type;
 Person类型成员函数：Person(const string &n, const string &a) :Name(n), Address(a) {}//其实也是构造函数，初始化变量成员
 内联函数：inline pos re_height()const { return height; }//也分显示和隐式
 重载成员函数：Person(const string &n, const string &a) :Name(n), Address(a) {}   Person(istream& is) { read(is, *this); }//函数const也是重载成员函数 const{...}
 可变数据成员：mutable size_t a;//即使在const对象内也可以修改
 链式调用：myscreen.move(4, 0).set('#').display(cout);//不带引用&就影响不到原对象，比如move没有&，返回的值就是myscreen的一个复制，set就无法改变原myscreen对象
 类类型：screen*x;//指向screen类型的指针x
 友元大家庭
 友元类：friend Person；//Person类可以调用screen类的private部分
 友元成员函数:
 1前向声明：在定义Window_mgr类之前，先进行screen类的前向声明。
 2友元函数声明：在screen类中声明Window_mgr类的clear函数为友元函数。
 3定义顺序：确保在定义Window_mgr类的成员函数clear时，screen类已经完全定义
 函数重载友元：每个函数都得声明一次，不然没用
 友元函数即使在类的内部定义过，也要在类的外部提供声明，不然不可调用

 类型名需要特殊处理：一般来说内层作用域可以重新定义外层作用域的名字，但是类不能重新定义
 委托构造函数：
 screen(const pos& h, const pos& w) :screen(0,h,w,' ') {}
 screen(const pos& h, const pos& w, char c) :screen(0,h,w,'c') {}
 screen(const pos& cu,const pos& h, const pos& w, char c) :cursor(cu),height(h), width(w), contents(h* w, c) {}

 explicit screen x();//防止隐式类型转换。具体来说，当一个构造函数被 explicit 修饰时，该构造函数只能通过显式调用来使用，而不能通过隐式转换来调用。
 explicit构造函数只能用于直接初始化，因为拷贝形式初始化会发生隐式转换
 class Number {
 public:
	 Number(int num) : value(num) {}
	 int getValue() const { return value; }
 private:
	 int value;
 };

 void printNumber(Number n) {
	 std::cout << "Number: " << n.getValue() << std::endl;
 }
	Number n1 = 10;  // 隐式转换
	cout << n1.getValue() << endl;
	Number n2(10);stream
	cout << n2.getValue() << endl;
	printNumber(20); // 隐式转换

 聚合类：
 1.所有成员public
 2.没有定义构造函数
 3.没有类内初始值
 4.没有基类，没有virtual函数
 struct data
 {
	int ival;
	string s;
 };

 字面值常量类：
 1.数据成员为字面值类型
 2.类必须包含一个constexpr构造函数
 3.若数据成员含有类内初始值，则初始值必须是常量表达式；若成员属于某种类型，则初始值必须使用成员自己的constexpr构造函数
 4.类必须使用析构函数的默认定义，负责销毁类的对象
 见class Debug

 类的静态成员：
 1.对象中不会包含任何静态成员有关的数据
 2.静态成员函数不包括this指针
 3.可以使用作用域访问静态成员；使用类的对象、引用、指针访问静态成员；成员函数可以直接访问静态成员
 4.在类的外部定义静态成员时，不能重复static关键词，static只能出现在类内部的声明中
 5.一般只能在类外部定义和初始化静态成员且只能一次；
 若在类内部初始化，要求一、静态成员是字面值类型的constexpr二、初始值为const整数类型
 6.即使静态成员在类内初始化了，在外部也需要声明
 7.静态、指针、成员可以是不完全类型
 静态成员是指声明语句之前带有关键字 static 的类成员，静态成员不是任意
 单独对象的组成部分，而是由该类的全体对象所共享。
 静态成员的优点包括：作用域位于类的范围之内，避免与其他类的成员或者全
 局作用域的名字冲突；可以是私有成员，而全局对象不可以；通过阅读程序可以非
 常容易地看出静态成员与特定类关联，使得程序的含义清晰明了。
 静态成员与普通成员的区别主要体现在普通成员与类的对象关联，是某个具体
 对象的组成部分；而静态成员不从属于任何具体的对象，它由该类的所有对象共享。
 另外，还有一个细微的区别，静态成员可以作为默认实参，而普通数据成员不能作为默认实参。
 class Example {
 public:
	 static constexpr double rate = 6.5; // 使用 constexpr
	 static const int vecSize = 20;      // 合法，const 整型
	 static vector<double> vec;          // 声明静态成员
 };
 constexpr double Example::rate; // 定义并初始化 rate
 vector<double> Example::vec(Example::vecSize); // 定义并初始化 vec

 std::ios::iostate的4个状态标志：
 std::ios::goodbit：表示流处于良好状态，没有错误。这个值通常为0。
 std::ios::eofbit：表示流已到达文件末尾（EOF）。
 std::ios::failbit：表示一个输入/输出操作失败，但流仍然可以使用。
 std::ios::badbit：表示流已崩溃，无法继续使用。
 
 istream 是输入流的基类，提供基本的输入功能。
 ifstream 专门用于从文件中读取数据。
 istringstream 专门用于从字符串中读取数据。

 fstream：读写皆可；ifstream：只读；ofstream：只写；
 fstream fstrm(s);//创建fstrm并打开名为s的文件，s可以是string类型or指向c风格字符串的指针，此构造函数为explicit
 fstream fstrm(s,mode);//指定mode打开文件
 fstrm.open(s);
 fstrm.close();
 fstrm.is_open();//返回一个bool值，指出关联的文件是否成功打开并未关闭
 in：只读
 out：只写
 app：写操作前定位到末尾
 ate：打开文件后定位到末尾
 trunc：截断文件
 binary：以二进制进行IO

 stringstream：string中读写皆可；istringstream：使用 >> 操作符使对象从字符串流中读取数据；ostringstream:使用 << 操作符将数据写入字符串流strm<<"love"；
 stringstream strm(s);//保存string s的拷贝，此构造函数为explicit
 strm.str();//返回strm所保存的string类型拷贝
 strm.str(s);//将string s拷贝到strm中，返回void
 strm.clear();//重置标志位，不会影响strm的内容

 顺序容器：
 vector：可变大小数组，快速随机访问，尾部插入删除数据快，insert慢，不能插头部
 deque：双端队列，快速随机访问，头尾位置插入删除数据都很快，insert不知道快不快
 list：双向链表，只支持双向顺序访问，任何位置插入删除数据都很快
 forward_list：单向链表，只支持单向顺序访问，任何位置插入删除数据都很快
 array：固定大小数组，快速随机访问，不能添加删除元素
 string：与vector类似，但专门用于保存字符，快速随机访问，尾部插入删除数据快，其他慢
 创建一个容器为另一个容器的拷贝，必须容器类型、元素类型都一致；	拷贝范围的话就不用
	vector<const char*>art = { "s","b" };
	vector<string>a{art};//不对
	forward_list<string>wrods{ art.begin(),art.end() };//对
 array定义：
 array<string,10>a1;//类型为:保存10个string的数组
 内置数组不支持拷贝，但是array支持
 a1.swap(a2);//交换a1和a2之间的元素

 assign操作不适用于关联容器和array//用于将一个对象的值赋给另一个对象。
 s1.assign(b,e);//将s1中的元素复制为迭代器b到e范围内的元素

 +-运算符不适用于list、forward_list，但是可以多次调用i++
 必须容器类型、元素类型都一致才能使用关系运算符

 添加元素
 c.push_back(x);//在c尾部插入一个值x，返回void  emplace直接构造，push是复制拷贝
 c.push_front(x);在c头部插入一个值x，返回void   emplace
 c.insert(p,t);在迭代器p指向的元素之前插入一个值t，返回指向新元素的迭代器 emplace
 c.insert(p,n,t);在迭代器p指向的元素之前插入n个值t，返回第一个指向新元素的迭代器，若n=0，则返回p
 c.insert(p,b,e);将迭代器b到e指定范围的元素插入到p指向的元素之前，b、e不能指向c中的元素，返回第一个指向新元素的迭代器，若范围=0，则返回p
 c.insert(p,i1);i1是一个花括号包围的元素值列表，将这些给定值插入到迭代器p指向的元素之前，返回第一个指向新元素的迭代器，若范围=0，则返回p
 上述操作都必须元素类型相同
 insert操作会使现有指向容器的迭代器、指针、引用都失效（list、forward_list除外）
 访问元素
 包括array在内的顺序容器都有front成员函数，除了forward_list都有back成员函数，都是返回引用
 c.back();
 c.front();
 c[n];//返回的也是引用  n不可>=c.size();只适用于string、vector、deque、array
 c.at(0);和上面等效

 删除元素（array不支持）
 删除操作都会导致指向容器的迭代器、指针、引用都失效（list、forward_list除外）
 c.pop_back();删除尾元素，返回void
 c.pop_front();删除头元素，返回void
 c.erase(p);删除迭代器p指向的元素，返回后一个元素的迭代器，若p指向尾元素，返回尾后迭代器，若p为尾后迭代器，报警
 c.erase(b,e);删除迭代器b到e范围内的元素，返回最后一个被删元素的后一个元素的迭代器，若e为尾后迭代器，则返回e
 c.clear();删除所有元素，返回void
 forward_list专属添加删除操作
 lst.before_begin();//返回指向链表首元素之前不存在元素的迭代器
 lst.cbefore_begin();//返回格式多个const
 lst.insert_after(p,t);//在迭代器p指向的元素之后的位置插入一个值t 返回一个指向最后一个插入元素的迭代器。如果范围为空，则返回 p。若 p 为尾后迭代器，则函数行为未定义
 lst.insert_after(p,n,t);//n为范围
 lst.insert_after(p,b,e);//b 和 e 是表示范围的一对迭代器 （b 和 e 不能指向 lst 内）
 lst.insert_after(p,il);//i1 是一个花括号列表。
 emplace_after(p,arg);//使用arg在p之后的位置创建一个元素，返回一个指向最后一个插入元素的迭代器 emplace是直接构造
 lst.erase_after(p);//删除p指向之后的元素，返回再下个的迭代器
 lst.erase_after(b,e);

 改变容器大小（array不支持）
 c.resize(n);//调整c的大小为n个，新元素初始化
 c.resize(n,t);//调整大小为n个，新元素初始化为t

 管理容量的成员函数：
 c.shrink_to_fit();//只适用于vector、string、deque，将容量capacity减少到与size相同
 c.capacity();//只适用于vector、string，不扩容内存空间时最大元素容量
 c.reserve(n);//只适用于vector、string，分配至少能容纳n个元素的内存空间

 顺序函数总结：
 1. vector
定义：vector 是一个动态数组，可以自动调整大小，支持快速随机访问。 常用成员函数：

push_back(value)：在末尾添加元素
pop_back()：删除末尾元素
size()：返回元素个数
empty()：判断是否为空
at(index)：访问指定位置的元素，带边界检查
c.insert(p,t);在迭代器p指向的元素之前插入一个值t，返回指向新元素的迭代器 emplace
c.erase(p);删除迭代器p指向的元素，返回后一个元素的迭代器，若p指向尾元素，返回尾后迭代器，若p为尾后迭代器，报警
clear()：清空所有元素
2. deque
定义：deque 是双端队列，支持在两端快速插入和删除元素。 常用成员函数：

push_back(value)：在末尾添加元素
push_front(value)：在头部添加元素
pop_back()：删除末尾元素
pop_front()：删除头部元素
size()：返回元素个数
c.insert(p,t);在迭代器p指向的元素之前插入一个值t，返回指向新元素的迭代器 emplace
c.erase(p);删除迭代器p指向的元素，返回后一个元素的迭代器，若p指向尾元素，返回尾后迭代器，若p为尾后迭代器，报警
at(index)：访问指定位置的元素，带边界检查
3. list
定义：list 是双向链表，支持在任意位置快速插入和删除元素，但不支持随机访问。 常用成员函数：

push_back(value)：在末尾添加元素
push_front(value)：在头部添加元素
pop_back()：删除末尾元素
pop_front()：删除头部元素
size()：返回元素个数
insert(iterator, value)：在指定位置插入元素
erase(iterator)：删除指定位置的元素
4. forward_list
定义：forward_list 是单向链表，只支持单向遍历和插入删除元素。 常用成员函数：

push_front(value)：在头部添加元素
pop_front()：删除头部元素
insert_after(iterator, value)：在指定位置后插入元素
erase_after(iterator)：删除指定位置后的元素
std::distance(flist.begin(), flist.end());：返回元素个数（C++17引入）
5. array
定义：array 是一个固定大小的数组，大小在编译时确定。 常用成员函数：

at(index)：访问指定位置的元素，带边界检查
size()：返回元素个数
empty()：判断是否为空
front()：返回第一个元素
back()：返回最后一个元素
fill(value)：用指定值填充整个数组
6. string
定义：string 是一个用于表示和操作字符串的容器，实际上是一个特化的 vector<char>。 常用成员函数：

append(str)：在末尾添加字符串
substr(pos, len)：返回从指定位置开始的子字符串
find(str)：查找子字符串的位置
replace(pos, len, str)：替换子字符串
size()：返回字符串长度
empty()：判断是否为空
c.insert(p,t);在迭代器p指向的元素之前插入一个值t，返回指向新元素的迭代器 emplace
c.erase(p);删除迭代器p指向的元素，返回后一个元素的迭代器，若p指向尾元素，返回尾后迭代器，若p为尾后迭代器，报警

迭代器失效
1. vector 和 string
添加元素：如果添加元素导致重新分配内存（即容量不足时），所有迭代器、引用和指针都会失效。如果没有重新分配内存，插入位置之后的迭代器、引用和指针会失效。
删除元素：删除位置及其之后的迭代器、引用和指针会失效。
2. deque
添加元素：在首尾之外的任何位置添加元素，所有迭代器、引用和指针都会失效。在首尾添加元素时，迭代器会失效，但引用和指针不会失效。
删除元素：在首尾之外的任何位置删除元素，所有迭代器、引用和指针都会失效。删除首尾元素时，除了尾后迭代器失效外，其他迭代器、引用和指针都不受影响。
3. list 和 forward_list
添加元素：不会使任何迭代器、引用和指针失效。
删除元素：指向被删除元素的迭代器、引用和指针会失效，但其他的不会失效。
4. array
添加/删除元素：array 是固定大小的容器，不能动态添加或删除元素，因此不存在迭代器、引用和指针失效的问题。
5. 关联容器（如 map, set, multimap, multiset）
添加元素：不会使任何迭代器、引用和指针失效。
删除元素：指向被删除元素的迭代器、引用和指针会失效，但其他的不会失效。
6. 无序关联容器（如 unordered_map, unordered_set, unordered_multimap, unordered_multiset）
添加元素：不会使任何迭代器、引用和指针失效。
删除元素：指向被删除元素的迭代器、引用和指针会失效，但其他的不会失效。

 string s(cp,n);//s 是 cp 指向的数组中前 n 个字符的拷贝。此数组至少应该包含 n 个字符
 string s(s2,pos2);//s 是 string s2 从下标 pos2 开始的字符的拷贝。 若pos2>s2.si ze （）， 构造函数的行为未定义
 string s(s2,pos2,len2);//s 是 string s2 从下标 pos2 开始 1en2 个字符的拷贝。 若 pos2>s2.si ze （），构造函数的行为未定义。 不管 1en2的值是多少， 构造函数至多拷贝 s2.si ze （）-pos2 个字符

 substr:返回一个string的一部分或者全部拷贝
 string s("hello world");
 s.substr(0,5);//hello
 s.substr(6);//world

 string类型的特殊操作：
 s1.assign(c,7);//将c的前7个元素复制到s1中，返回一个指向s1的引用
 s.insert(0,c);//在s的第0个字符后，插入c的所有元素（如果是c+1，则插入第一个元素之后的剩下元素），返回一个指向s的引用
 s.erase(0,4);//从s的第0个字符开始，删除四个字符，返回一个指向s的引用
 s.append("fjf");//在s的末尾插入“fjf”，返回一个指向s的引用
 s.replace(11,2,"fjf");//在第11位后，删除2位字符，再插入“fjf”，返回一个指向s的引用

 string搜索函数：
 s.find(arg);//第一次出现的位置 返回第一次出现位置的下标值  s,pos s为字符串，pos为位置
 s.rfind(arg);//最后一次出现的位置
 s.find_first_of(arg);//arg中任意一个字符第一次出现的位置
 s.find_last_of(arg);//arg中任意一个字符最后一次出现的位置
 s.find_first_not_of(arg);查找第一个不在arg中的字符
 s.find_last_not_of(arg);查找最后一个不在arg中的字符

 string数值转化：
 to_string(val);//返回数值val的string表示
 stoi(s,p,b);//返回s的起始子串（表示整数内容）的数值，返回类型分别为int、long、unsigned long、long long、unsigned long long。b表示转换所用的基数，默认10.p是size_t指针，用来保存s中第一个非数值字符下标，默认0
 stol
 stoul
 stoll
 stof(s,p);//返回s的起始子串（表示浮点内容）的数值，返回类型分别为float、double、long double，p见上
 stod(s,p);
 stold(s,p);

 容器适配器：
 stack：实现了栈的功能，遵循后进先出（LIFO）原则。元素只能从栈的 顶端 插入（push）和移除（pop）
 s.pop();//移除并返回队列前端元素。
 s.push(item);//创建一个新元素压入栈顶，通过拷贝或移动item而来，或者由args构造
 s.emplace(args);
 s.top();//返回栈顶元素，但不将元素弹出栈

 queue：实现了队列的功能，遵循先进先出（FIFO）原则。元素只能从队列的 末尾 插入（enqueue），从队列的 前端 移除（dequeue）
 priority_queue：实现了优先队列的功能，元素按优先级排序。
 q.pop();//移除并返回队列前端元素。
 q.front();//返回首元素或尾元素，但不删除此元素，只适用于queue
 q.back();
 q.top();//返回最高优先级元素，但不删除此元素，只适用于priority
 q.push(item);//在queue末尾或者priority中恰当位置创建一个元素，其值为item，或者由args构造
 q.emplace(args);

 算法函数：（标准库的函数都不能对容器进行添加/删除操作，除了back_inserter,运行拷贝等操作时确保拷贝对象的空间足够）
 find(e,q,t);//e、q都是迭代器，查找范围[e,q)，未找到返回q，找到t就返回t的位置，返回值必定是迭代器类型
 count(e,q,t);//返回的是t出现的次数
 只读算法：
 accumulate(e,q,t);//求和，和的初值为t，第三个参数决定返回类型，以及+的使用（string类型也可以相加）accumulate(x.begin(), x.end(), string("i "));
 equal(i1.begin(),i1.end(),i2.begin());//比较i1和i2是否相同，i2的序列>=i1的序列，两者类型相容，可以进行比较即可，比如vector<string>和list<const char*>都可以相互比较
 写容器元素算法：
 fill(e,q,t);//将每个元素重置为t
 fill_n(e,n,t);//e指向一个元素，从e开始n个元素重置为t
 插入迭代器：
 auto i=back_inserter(vector<int>a);//此时给*i赋值即可添加元素
 拷贝算法：
 copy(a.begin(),a.end(),b.begin());//把a的内容拷贝到b中 必须保证a、b两者有一样多的元素（copy无法从容器进行添加/删除操作）
 replace(a.begin(),a.end(),0,5);//把a中为0的值改为5
 replace_copy(a.cbegin(), a.cend(), back_inserter(b), 0, 55);//将a的内容拷贝到b，并将b中为0的值改为55
 重排算法：标准库算法（如 std::sort）要求比较函数的参数是 const 引用。这是因为这些算法在内部可能会对元素进行多次比较，而不希望这些比较操作改变元素的状态。
 sort(e,q);//按字母/大小排序容器 该函数也可以自定义规则进行排序sort(e,q,lambda);
 stable_sort(e,q);//和sort一样，如果两个元素相等，它们在排序后的相对顺序不会改变。
 unique(e,q，lambda);//消除相邻的重复项，返回指向不重复区域之后一个位置的迭代器（说是消除，其实是将其移动到末尾，并将元素等于原来的end）
 unique_copy(e,q,result);//result结果范围的起始输出迭代器
	sort(x.begin(), x.end(), [](int a, int b) {
		if (a < 5 && b >= 5) return true;
		if (a >= 5 && b < 5) return false;
		return a < b;
	});
	auto last=unique(x.begin(), x.end(), [](int a,int b) {return a%2==0&&b%2==0; });
	x.erase(last, x.end());


 partition(e,q,predicate);//用于根据给定的谓词（predicate）将范围内的元素重新排列，使得满足谓词的元素位于范围的前半部分，而不满足谓词的元素位于范围的后半部分。
 谓词（predicate）：
 一个函数，其返回结果是一个能作为条件的值（最多调用两个参数j，且返回值为bool）
 bool compare(int a, int b) {
	return a < b;
}
 Lambda：
 表达式：4,3  3,2 2,1 1,0  3
 capture -> return_type {
	// function body
}
 [capture](parameters){function body}
 capture：捕获外部变量的方式，可以是值捕获（=）或引用捕获（&）。//[=,&a][&,a]隐式捕获
 parameters：函数参数列表。
 return_type：返回类型（可以省略，编译器会自动推断）。
 function body：函数体，包含具体的操作。
 对于拷贝的变量，如果需要修改，必须加上mutable(值捕获）[]( int& m)mutable ->int {--m; return m; };
 size_t v1=42
 auto f=[v1]()mutable(return ++v1;};
 v1=0
 auto j=f();//j=43
 对于非const变量的引用，可以通过引用进行修改
 size_t v1=42
 auto f=[v1]()mutable(return ++v1;};
 v1=0
 auto j=f();//j=1
 为lambda定义返回类型：
 find_if(e,q,[](int n)->int{if(n<0)return -n;else return n;};
 适用于lambda的函数：
 find_if(e,q,Lambda);//用于在范围内查找第一个满足特定条件的元素。它接受一个Lambda作为参数，并返回一个指向第一个满足条件的元素的迭代器。如果没有找到满足条件的元素，则返回指向范围末尾的迭代器。
 count_if(e,q,Lambda);//返回满足要求的元素的个数
 for_each(e,q,Lambda);//对e-q范围内的元素进行操作，看Lambda表达式返回的值
 transform(numbers.begin(), numbers.end(), results.begin(),Lambda);//是用于对容器中的元素应用指定的操作,并将结果存储到另一个容器中。确保results的空间>=numbers

 bind函数：解决find_if等算法只能接受一元谓词的限制，经常使用的情况也用bind（lambda每次都写太麻烦）使用bind就要用std::placeholders
 auto newcallable=bind(callable,arg_list);
 callable：这是一个可调用对象，可以是函数指针、函数对象、或者 lambda 表达式。
 newcallable：新生成的可调用对象
 arg_list：这是一个参数列表，用于绑定到 callable 的参数上。
 auto g=bind(ff,a,b,_2,c_1);
 g(X,Y)等效于ff(a,b,X,c,Y)
 bind(isshorter1,_2,_1)和bind(isshorter1,_1,_2)的结果刚好相反

 插入迭代器：
 back_inserter(a)，创建一个push_back迭代器
 front_inserter(a)，创建一个push_front迭代器，生成的迭代器总是指向容器的第一个元素
 inserter(a,a.begin())，创建一个使用insert的迭代器，插入指定迭代器之前的位置，使用该操作时，迭代器还是指向原来的元素
 相关操作：
 auto it = std::back_inserter(vec);
 it=t;//相当于在it指定的位置插入值t
 *it,++it,it++ 都只会返回it

 iostream迭代器：
 输入：
 相关操作：
 istream_iterator<T> in(is); in从输入流is读取类型为T的值
 istream_iterator<T> end;    读取类型为T的值的istream_iterator迭代器，表示尾后位置
 in1==in2					 in1和in2必须读取相同类型。如果都是尾后迭代器或者绑定相同输入，则两者相等
 in1!=in2
 *in						 返回从流中读取的值
 in->mem					 等于(in).men
 ++in,in++					 使用元素类型所定义的>>运算符从输入流中读取下一个值。++in返回指向递增后迭代器的引用，in++返回旧值
 各类操作方式：
 1.读取插入
 vector<string>x;
 ifstream is("H://examtest//a.txt");
 istream_iterator<string>int_in(is);
 istream_iterator<string>eof;
 while (int_in != eof)
		x.push_back(*int_in++);//*int_in++：先移动到下一位，然后旧的参数传输给x，也就说，从1移动到2，传输1的数据给x
 vector<string>y(int_in, eof);//和上面while操作等效
 2.算法操作
 cout<<accumulate(is,eof,0)<<endl;
 
 输出：
 相关操作：
 ostream_iterator<T> out(os);	   out将类型T的值写到输出流os中
 ostream_iterator<T> out(os,d);    out将类型T的值写道输出流os中，每个值后面都输出一个d。d指向一个空字符结尾的字符数组				 
 out=val						   用<<运算符将val写入到out所绑定的ostream中。val类型必须与out可写的类型兼容
 *out,++out,out++				   都只会返回out
 各类操作方式：
 1.读取插入
 ostream_iterator<string> os(cout, " ");
 for (auto e : y)
	*os++ = e;//等效为os=e;
 2.算法操作
 copy(y.begin(), y.end(), os);//和上面效果一样

 反向迭代器（forward_list不支持反向迭代器）反向迭代器的特性是它指向的元素实际上是它前一个位置的元素
 完全相反
 crend()在begin前面，crbegin()在end前面
 com.base();//获得一个正向迭代器
 下述代码复制范围为3->7
  vector<int>y{ 1,2,3,4,5,6,7,8,9,10 };
	list<int>z;
	vector<int>::reverse_iterator rb(y.begin() + 2);
	vector<int>::reverse_iterator rs(y.begin() + 7);
	copy(rs, rb, back_inserter(z));

 5个迭代器类别：
 输入：			p392
 输出：			p392
 前向：			p392
 双向：			p392
 随机访问：		p392

 算法形参模式：
 alg(beg,end,other args);
 alg(beg,end,dest,other args);//dest可以是插入迭代器，输出迭代器等
 alg(beg,end,beg2,other args);//默认beg2的容器空间>=beg的
 alg(beg,end,beg2,end2,other args);

 特定容器算法（list、forward_list）都返回void
 lst.merge(lst2);		使用<运算符进行合并（还得有序）
 lst.merge(lst2,comp);	使用给定的比较操作进行合并
 lst.remove(val);		删掉一个值相同的
 lst.remove_if(pred);	删掉一个满足一元谓词的
 lst.reserve();
 lst.sort();
 lst.sort(comp);		
 lst.unique();
 lst.unique(pred);
 splice算法是链式结构特有，用于将一个列表的元素插入到另一个列表中
 lst.splice(args);
 flst.splice_after(args);
 (p,lst2)(p,lst2,p2),(p,lst2,b,e)

 关联容器：按关键字来保存和访问
 有序保存：map<key,valve> set<key>
 map、set 关键字——值、只保存关键字 set常常作为黑名单、白名单的实现方式
 multimap、multiset 关键字可重复出现
 相关操作和解释可以看add_family函数
 关键字valve必须能够支持<=等运算符（严格弱序）
 通常不对关联容器使用泛式算法
 pair对象：(默认情况下成员为public）
 只有值，调用函数pair.first、second，用于将两个数据组合成一个单一的对象。
 类型别名：
 key_type				关键字类型
 mapped_type			值类型，只适用于map
 valve_type				对于set，相当于key_type
						对于map，为pair<const key_type,mapped_type>
 无序保存：
 unordered_map、unordered_set 使用哈希函数组织
 unordered_multimap、unordered_multiset
*/

//IO库

//struct personinfo {
//	string name;
//	vector<string>phones;
//};
/*int main()
{
	string folderPath = "H://examtest//";
	string fileName = "a.txt";
	string filePath = folderPath + fileName;
	fstream in(filePath, ios::in);
	if (!in)
	{
		cerr << "无法打开文件：" << filePath << endl;
		return -1;
	}
	string line;
	vector<string> xy;
	while (getline(in, line))
	{
		xy.push_back(line);
	}
	in.close();
	for (auto it = xy.begin(); it != xy.end() && !it->empty(); ++it)
	{
		istringstream ini(*it);
		f(ini);
	}
	ifstream in("H://examtest//a.txt");
	if (!in)
	{
		cerr << "无法打开文件：H://examtest//a.txt" << endl;
		return -1;
	}
	string line, word;
	vector<personinfo>people;
	istringstream record;
	while (getline(in, line))
	{
		personinfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	in.close();
	ostringstream os;
	for (auto a : people)
	{
		os << a.name << ' ';
		for (auto b : a.phones)
			os << b << ' ';
		os << endl;
	}
	ofstream out("H://examtest//abc.txt");
	if (!out)
	{
		cerr << "无法打开文件：H://examtest//abc.txt" << endl;
		return -1;
	}
	for (auto a : people)
	{
		out << a.name << ' ';
		for (auto b : a.phones)
			out << b << ' ';
		out << endl;
	}
	string result = os.str();
	out << result;
	cout << result;
	out.close();
	return 0;
}*/////IO库

//main函数输入数据

//int main(int argc, char* argv[]) //./c++study H://examtest//a.txt 即可进行参数传递H://examtest//a.txt
//{
//    // 检查是否传递了文件名参数
//    if (argc < 3) {
//        cerr << "请提供输入文件名和输出文件名作为参数。" << endl;
//        return -1;
//    }
//
//    // 获取文件名
//    string infile = argv[1];
//    string outfile = argv[2];
//
//    // 打开文件
//    ifstream inFile(infile);
//    if (!inFile) {
//        cerr << "无法打开文件: " << infile << endl;
//        return -1;
//    }
//
//    // 打开输出文件
//    ofstream OUTfile(outfile,ios::app);
//    if (!OUTfile) {
//        cerr << "无法打开文件: " << outfile << endl;
//        return -1;
//    }
//
//    // 读取文件内容
//    string line;
//    vector<string> lines;
//    while (getline(inFile, line)) {
//        lines.push_back(line);
//        OUTfile << line << '\n';
//    }
//    OUTfile << "fuck you" << endl;
//    inFile.close();
//    OUTfile.close();
//
//    for (auto& l : lines) {
//        cout << l << endl;
//    }
//    return 0;
//}

//class date {
//public:
//	friend ostream& operator<<(ostream&, const date&);
//	date() = default;
//	date(string& ds);
//	unsigned y() const { return year; }
//	unsigned m() const { return month; }
//	unsigned d() const { return day; }
//
//private:
//	unsigned year, month, day;
//};
//
//// 月份全称 
//const string month_name[] = { "January", "February", "March",
//			  "April", "May", "June", "July", "August", "September",
//			  "October", "November", "December" };
//
//// 月份简写 
//const string month_abbr[] = { "Jan", "Feb", "Mar", "Apr", "May",
//			  "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };
//
//// 每月天数 
//const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//inline int get_month(string& ds, int& end_of_month)
//{
//	int i, j;
//	for (i = 0; i < 12; i++) {
//		// 检查每个字符是否与月份简写相等 
//		for (j = 0; j < month_abbr[i].size(); j++)
//			if (ds[j] != month_abbr[i][j])      // 不是此月简写 
//				break;
//		if (j == month_abbr[i].size())    // 与简写匹配 
//			break;
//	}
//
//	if (i == 12)           // 与所有月份名都不相同 
//		throw invalid_argument("不是合法月份名");
//
//	if (ds[j] == ' ') {     // 空白符，仅是月份简写 
//		end_of_month = j + 1;
//		return i + 1;
//	}
//
//	for (; j < month_name[i].size(); j++)
//		if (ds[j] != month_name[i][j])
//			break;
//
//	if (j == month_name[i].size() && ds[j] == ' ') { // 月份全称 
//		end_of_month = j + 1;
//		return i + 1;
//	}
//
//	throw invalid_argument("不是合法月份名");
//}
//
//inline int get_day(string& ds, int month, int& p)
//{
//	size_t q;
//	int day = stoi(ds.substr(p), &q); // 从p开始的部分转换为日期值 
//	if (day < 1 || day > days[month])
//		throw invalid_argument("不是合法日期值");
//	p += q;        // 移动到日期值之后 
//	return day;
//}
//
//inline int get_year(string& ds, int& p)
//{
//	size_t q;
//	int year = stoi(ds.substr(p), &q);  // 从p开始的部分转换为年 
//	if (p + q < ds.size())
//		throw invalid_argument("非法结尾内容");
//	return year;
//}
//
//date::date(string& ds)
//{
//	int p;
//	size_t q;
//
//	if ((p = ds.find_first_of("0123456789")) == string::npos)
//		throw invalid_argument("没有数字，非法日期");
//
//	if (p > 0) {        // 月份名格式 
//		month = get_month(ds, p);
//		day = get_day(ds, month, p);
//		if (ds[p] != ' ' && ds[p] != ',')
//			throw invalid_argument("非法间隔符");
//		p++;
//		year = get_year(ds, p);
//	}
//	else {         // 月份值格式 
//		month = stoi(ds, &q);
//		p = q;
//		if (month < 1 || month > 12)
//			throw invalid_argument("不是合法月份值");
//		if (ds[p++] != '/')
//			throw invalid_argument("非法间隔符");
//		day = get_day(ds, month, p);
//		if (ds[p++] != '/')
//			throw invalid_argument("非法间隔符");
//		year = get_year(ds, p);
//	}
//}
//
//ostream& operator<<(ostream& out, const date& d)
//{
//	out << d.y() << "年" << d.m() << "月" << d.d() << "日" << endl;
//	return out;
//}
//
//int main()
//{
//	string dates[] = { "Jan 1,2014", "February 1 2014", "3/1/2014",
//		// "Jcn 1,2014", 
//		// "Janvary 1,2014", 
//		// "Jan 32,2014", 
//		// "Jan 1/2014", 
//		"3 1 2014 ",
//	};
//	try {
//		for (auto ds : dates) {
//			date d1(ds);
//			cout << d1;
//		}
//	}
//	catch (invalid_argument e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//enum obj_type { LP, RP, ADD, SUB, VAL, cheng, chu };
//struct obj {
//	obj(obj_type type, double val = 0) { t = type; v = val; }
//	obj_type t;
//	double v;
//};
//inline void skipws(string& exp, size_t& p)
//{
//	p = exp.find_first_not_of(" ", p);
//}
//
//inline void new_val(stack<obj>& so, double v)
//{
//	if (so.empty() || so.top().t == LP) {        // 空栈或左括号 
//		so.push(obj(VAL, v));
//		// cout << "push " << v << endl; 
//	}
//	else if (so.top().t == cheng || so.top().t == chu)
//	{
//		obj_type type = so.top().t;
//		so.pop();
//		if (type == cheng)
//			v *= so.top().v;
//		else if (type == chu)
//			v /= so.top().v;
//		so.pop();
//		so.push(obj(VAL, v));
//	}
//	else if (so.top().t == ADD || so.top().t == SUB) {
//		// 之前是运算符 
//		obj_type type = so.top().t;
//		so.pop();
//		/*if (type == ADD)
//		  cout << "pop +" << endl;
//		else cout << "pop -" << endl;*/
//		// cout << "pop " << so.top().v << endl; 
//		// 执行加减法 
//		if (type == ADD)
//			v += so.top().v;
//		else v = so.top().v - v;
//		so.pop();
//		so.push(obj(VAL, v));        // 运算结果压栈 
//		// cout << "push " << v << endl; 
//	}
//	else throw invalid_argument("缺少运算符");
//}
//
//int main()
//{
//	stack<obj> so;
//	string exp;
//	size_t p = 0, q;
//	size_t i = 1;
//	double v;
//
//	cout << "请输入表达式：";
//	getline(cin, exp);
//
//	while (p < exp.size()) {
//		skipws(exp, p);            // 跳过空格 
//		if (exp[p] == '(') {        // 左括号直接压栈 
//			so.push(obj(LP));
//			p++;
//			// cout << "push LP" << endl; 
//		}
//		else if (exp[p] == '*' || exp[p] == '/')
//		{
//			if (so.empty() || so.top().t != VAL)
//				throw invalid_argument("缺少运算数");
//			if (exp[p] == '*')
//				so.push(obj(cheng));
//			else
//				so.push(obj(chu));
//			p++;
//		}
//		else if (exp[p] == '+' || exp[p] == '-') {
//			// 新运算符 
//			if (so.empty() || so.top().t != VAL)
//				// 空栈或之前不是运算数 
//				throw invalid_argument("缺少运算数");
//
//			if (exp[p] == '+')          // 运算符压栈 
//				so.push(obj(ADD));
//			else so.push(obj(SUB));
//			p++;
//			i++;
//			// cout << "push " << exp[p - 1] << endl; 
//		}
//		else if (exp[p] == ')') {   // 右括号 
//			p++;
//			if (so.empty())        // 之前无配对的左括号 
//				throw invalid_argument("未匹配右括号");
//
//			if (so.top().t == LP)        // 一对括号之间无内容 
//				throw invalid_argument("空括号");
//
//			if (so.top().t == VAL) {     // 正确：括号内运算结果 
//				//v = so.top().v;
//				//so.pop();
//				// cout << "pop " << v << endl; 
//
//				while (i > 0)
//				{
//					v = so.top().v;
//					so.pop();
//
//					// cout << "pop LP" << endl; 
//					new_val(so, v);      // 与新运算数逻辑一致 
//					--i;
//				}
//				so.pop();
//				if (so.empty() || so.top().t != LP)
//					throw invalid_argument("未匹配右括号");
//
//				so.pop();
//				if (so.size() != 1 || so.top().t != VAL)
//					new_val(so, v);
//
//			}
//			else        // 栈顶必定是运算符 
//				throw invalid_argument("缺少运算数");
//		}
//		else {        // 应该是运算数 
//			v = stod(exp.substr(p), &q);
//			p += q;
//			if (so.empty() || so.top().t == chu || so.top().t == cheng)
//				new_val(so, v);
//			else
//				so.push(obj(VAL, v));
//		}
//	}
//	//5 * (3 + 2 * 2 + 2)
//
//	if (so.size() != 1 || so.top().t != VAL)
//		throw invalid_argument("非法表达式");
//
//	cout << so.top().v << endl;
//	return 0;
//}

//如何使用operator<<

// 定义一个自定义类型
//class Person {
//public:
//	Person(const std::string& name, int age) : name_(name), age_(age) {}
//
//	// 友元声明，使得operator<<可以访问私有成员
//	friend std::ostream& operator<<(std::ostream& out, const Person& person);
//
//private:
//	std::string name_;
//	int age_;
//};
//
//// 重载operator<<
//std::ostream& operator<<(std::ostream& out, const Person& person) {
//	out << "Name: " << person.name_ << ", Age: " << person.age_;
//	return out;
//}
//
//int main() {
//	Person person("Alice", 30);
//	std::cout << person << std::endl; // 使用重载的operator<<输出Person对象
//	return 0;
//}
//
// 
// 
// class Empty {
//public:
//	Empty& operator=(const Empty& rhs) {
//		if (this != &rhs) {
//			// 执行赋值操作
//		}
//		return *this;
//	}
//};
// 
//赋值运算符(= )：赋值运算符用于将一个对象的值赋给另一个对象。它是一个成员函数，通常返回对当前对象的引用（* this），以便支持链式赋值。例如：
//class Empty {
//public:
//	Empty& operator=(const Empty& rhs) {
//		// 赋值操作
//		return *this;
//	}
//};
// 
//插入运算符(<< )：插入运算符通常用于输出流操作，例如将对象的内容输出到控制台或文件。它通常是一个非成员函数，并且返回输出流的引用。例如：
//std::ostream& operator<<(std::ostream& os, const Empty& obj) {
//	// 输出操作
//  os << "Empty object";
//	return os;
//}
// 
//int main() {
//Empty e1, e2;
//e1 = e2; // 使用赋值运算符
//std::cout << e1 << std::endl; // 使用插入运算符
//return 0;
//}
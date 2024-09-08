/*
对于char：
char*p="love";
cout<<p<<endl;//p是指针，直接输出p所指向的整个字符串，直到遇到\0
cout << *p << endl;//p 指向字符串 "love" 的第一个字符 'l'
const char* p[] = {"love", "you"};
cout << p << endl;   // 输出 p 的地址,p是一个数组，数组成员都是char类型的指针，指针分别指向字符串
cout << *p << endl;  // 输出 p[0] 指向的字符串 "love"
cout << p[0] << endl; // 输出 "love"
cout << p[1] << endl; // 输出 "you"
cout << **p << endl;  // 输出 p[0][0]，即 'l'
字符数组有\0

在 C++ 中，解析复杂声明时有一套优先级规则，帮助我们正确理解声明的含义。以下是这些规则的详细说明：
从标识符开始：
声明的解析从标识符（变量名）开始。
优先处理括号：
如果标识符后面有括号 ()，先处理括号内的内容。这通常表示函数参数列表。
处理后缀操作符：
接下来处理后缀操作符，如数组下标 [] 和函数调用 ()。这些操作符的优先级高于指针 *。
处理前缀操作符：
最后处理前缀操作符，如指针 * 和修饰符 const。
从里到外解析：
解析复杂声明时，通常从最内层的括号开始，然后逐步向外扩展。
举个例子，解析 int(*p[10])(int)：
找到标识符 p：
p 是声明的名字。
处理后缀操作符 []：
p 是一个包含 10 个元素的数组。
处理前缀操作符 *：
数组中的每个元素都是一个指针。
处理括号 ()：
这些指针指向一个接受 int 参数并返回 int 类型的函数。
通过这些步骤，我们可以确定 int(*p[10])(int) 是一个包含 10 个指向函数的指针的数组，每个函数接受一个 int 参数并返回一个 int 类型的值。

动态分配内存：实际运行中，可能无法预先确定字符数组的大小。动态分配内存允许根据需要调整数组的大小，从而更灵活地管理内存。
int main() {
    // 动态分配内存
    char* arr = (char*)malloc(6 * sizeof(char));
    if (arr == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }

    // 赋值和使用
    strcpy(arr, "hello");
    std::cout << "字符数组: " << arr << std::endl;

    // 释放内存
    free(arr);

    return 0;
}

 union的大小取决于所占空间最大的变量的大小 并且是倍数  int a32位占4字节，所以uni的大小就是4字节
 struct的大小由于内存对齐问题，int a四个字节,char b虽然是1个字节 但是为了存取效率，char
 b也被分配了一块4字节的空间，所以整个结构体所占空间为8字节


内存分区模型：意义 不同区域存放的数据，赋予不同的生命周期，灵活编程
1和2在程序运行之前就存在
1.代码区：存放函数二进制代码，系统管理
存放cpu执行的机器指令，1是共享和只读的
2.全局区：存放全局变/常量、静态变量、字符串常量，系统管理释放
3.栈区：存放函数参数值（形参）、局部变/常量等，系统管理开辟和释放
4.堆区：程序员分配和释放，程序结束时系统自动释放
new：
利用new操作符，可以将数据开辟到堆区
int *p=new int(10);//new返回的是一个int类型的指针
delete p;
int*p=new int[10];//new动态分配了一个包含 10 个 int 元素的数组，并返回一个指向该数组首元素的指针
delete[]p;//释放内存
new与malloc的区别：
1.new是操作符，malloc是c的函数
2.new和delete操作符配合使用，malloc和free函数配合使用
3.new 返回指定类型的指针，不需要类型转换，malloc 返回 void*，需要显式类型转换

函数高级应用：
函数的默认参数：int asf(int a=0,int b=0);//默认参数必须在没有默认参数形参的右边；若函数声明有默认函数，函数定义就不能有默认参数
函数的占位参数：int asf(int,int);//只有一个int
函数重载：同一作用域下，函数名称相同，函数参数类型不同or个数不同or顺序不同

类的封装：
类中的属性和行为统一称为成员
属性：成员属性 成员变量
行为：成员函数 成员方法
访问权限：公共、保护、私有  保护特有的是子类可以访问父类的保护内容
成员变量通过公共成员函数进行输入输出
对象的初始化和清理通过 构造函数（创建对象时进行成员变量赋值，编译器自动调用）、析构函数（对象销毁前系统自动调用，进行清理）来进行
构造函数：1.没有返回值不写void；2.函数名称=类名；3.构造函数可以有参数，可以重载；4.自动调用一次
析构函数：1.没有返回值不写void；2.函数名称=类名，在名称前加~；3.不能有参数，不能重载；4.对象销毁前自动调用一次

构造函数分类：
1.1有参构造 Circle(const double& x, const double& y, const double& r){}
1.2无参构造（默认构造函数）Person()=default;
2.1普通构造
2.2拷贝构造 Circle(const Circle& p) { circle_point_x = p.circle_point_x; }
构造函数调用方法：
1.括号法 Circle x(1,2,3);Cricle y(x); 
2.显示法 Circle x=Circle(1,2,3);Circle y=Circle(x);//Circle(1,2,3)；为匿名对象，执行结束后会被系统立即回收
3.隐式转换法 Circle x={1,2,3};
拷贝构造函数调用时机：
1.初始化新对象
Circle p1(1,2,3);
Circle p2(p1);
2.值传递的方式给函数参数传值
void works1(Circle p){}
void test1(){Circle p3;works1(p3);}//p3进行默认构造函数，运行works1时拷贝一个新的Circle值传递给函数形参
3.值方式返回局部变量
void works2(){Circle p4;return p4}//p4进行默认构造函数看，return时拷贝一个新的Circle值传递给p5
void test1(){Circle p5=work2();}
构造函数调用规则：
系统默认添加1构造函数、2析构函数、3拷贝构造函数自定义了拷贝构造函数，则系统不提供其他构造函数
深拷贝：在堆区重新申请空间，进行拷贝操作
浅拷贝：简单的赋值拷贝操作
自己实现拷贝构造函数，解决浅拷贝带来的问题//Circle 有一个int *height成员
Circle(const Circle &p)//拷贝构造函数
{
    //height=p.height;//编译器默认浅拷贝
    height=new int(*p.height);//深拷贝操作，避免析构函数中的delete操作符被重复调用删除同一个地址
    //为什么添加*解引用操作，因为height是一个指针，我们需要它指向的值，所以需要解引用
}
~Circle() //析构函数
{
    if(height!=NULL)
    {delete height; height=NULL;}// 释放内存
}
Circle& operator=(Circle& p)//赋值运算符重载
{
    if(height!=nullptr){delete height; height=nullptr;}
    height=new int(*p.height);
    return *this;
}
上述总结：若属性有在堆区开辟，一定要自己提供析构函数、拷贝构造函数、赋值运算符重载，避免出现浅拷贝问题
初始化列表：初始化成员属性
语法 构造函数():属性1(值1),属性2(值2){}
类对象作为类成员：构造时会先构造类成员，再构造自身；析构时先析构自身，再析构类成员
静态成员：成员变量或成员函数加上关键字static
静态成员变量：1.所有对象共享一份数据2.编译阶段分配内存3.类内声明，类外初始化 访问方式：1.通过对象访问；2.可以通过类名进行访问Circle::m_A
静态成员函数：1.所有成员共享一个函数2.静态成员函数之恶能访问静态成员变量 访问方式：1.通过对象访问；2.可以通过类名进行访问
成员变量 和 成员函数是分开储存的
this指针指向被调用的成员函数所属的对象（return *this主要应用于成员函数的链式编程）this指针本质上就是指针常量，不可修改指向的地址，但是可以修改指向地址的值
空指针访问成员函数：注意成员函数是否使用this指针
const修饰成员函数==常函数： void asd()const{this->age=100;}//不可修改age  
1.常函数内不可修改成员属性  添加const此时this指针多了顶层const，指向地址和地址的值皆不可修改
2.声明时加mutable关键字后，就可以在常函数中修改成员 mutable int age;//即可在常函数中修改age
常对象： const Circle p;
1.声明对象前加const称该对象为常对象
2.常对象只能调用常函数
友元：
1.全局函数做友元 可以访问类内私有成员变量
2.类做友元  friend class x;
3.类中成员函数做友元  friend void x::visit();//使用2、3时成员函数都要类外定义
运算符重载：对已有的运算符重新定义，赋予另一种功能，以适应不同的数据类型（尽量都是用全局函数，否则会有局限性）
1.加号重载 
通过成员函数重载+号
Circle operator+(Circle &p)
Circle p3=p1.operator+(p2)->简化为p3=p1+p2;
通过全局函数重载+号
Circle operator+(Circle &p1,Circle& p2)
Circle p3=operator+(p1,p2)->简化为p3=p1+p2;
2.左移重载
只能全局函数重载
ostream& operator<<(ostream& os,Circle& p);//没有&就只会对对象操作一次，再链式调用时的对象就不是该对象了
3.递增重载
前置递增
cir& operator++()
    {
        num++;
        return *this;
    }
后置递增
cir_proxy cir::operator++(int)
{
    cir_proxy temp(*this);//cir类型调用cir_proxy构造函数初始化cir_proxy
    num++;
    return temp;
}

cir_proxy cir_proxy::operator++(int)
{
    cir_proxy temp(*this);//cir_proxy类型括号法初始化cir_proxy
    ref_.num++;
    return temp;
}
4.赋值重载
Circle& operator=(Circle& p)//赋值运算符重载，利用深拷贝
{
    if(height!=nullptr){delete height; height=nullptr;}
    height=new int(*p.height);
    return *this;
}
5.关系重载
bool operator==(pp& p)
    {
        if (m_name == p.m_name && m_age == p.m_age)
            return true;
        else
            return false;
    }
6.函数调用运算符()重载
由于重载后使用的方式非常像函数的调用，因此称为仿函数，其非常灵活，没有固定写法
输出：
void operator()(string test)
{
    cout << test << endl;
}
Myprint x;
x("hello world");
加法：
int operator()(int num1,int num2)
{
    retrun num1+num2;
}
Myadd x;
int a = x(10,20);
cout << Myadd()(10,20);//匿名函数对象

继承  下级别成员除了拥有上一级的共性，还有自己的特性，可以使用继承技术，减少重复代码
基本语法

*/

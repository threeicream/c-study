/*
对于char：
char*p="love";
cout<<p<<endl;//p是指针，直接输出p所指向的整个字符串，直到遇到\0
cout << *p << endl;//p 指向字符串 "love" 的第一个字符 'l'
const char* p[] = {"love", "you"};
cout << p << endl;   // 输出 p 的地址
cout << *p << endl;  // 输出 p[0] 指向的字符串 "love"
cout << p[0] << endl; // 输出 "love"
cout << p[1] << endl; // 输出 "you"
cout << **p << endl;  // 输出 p[0][0]，即 'l'
字符数组有\0

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
函数的占位参数：int asf(int,int);//
函数重载：同一作用域下，函数名称相同，函数参数类型不同or个数不同or顺序不同

类的封装：
类中的属性和行为统一称为成员
属性：成员属性 成员变量
行为：成员函数 成员方法

*/

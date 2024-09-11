#include <iostream>//读写流基本类型
#include<fstream>//读写命名文件的类型
//#include <filesystem>//C++17的文件系统库
#include<sstream>//读写内存string对象的类型
#include <typeinfo>
//顺序容器
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<array>
//关联容器
#include<map>
#include<set>
#include<utility>
//适配器
#include<stack>
#include<queue>
//算法
#include<algorithm>
#include<numeric>
#include<functional>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏  assert(x);x为假，输出信息并终止程序运行
#include"test.h"
#include"cp.h"
//#include"person.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;
using namespace std;//一个就把上面using全等效了
using namespace placeholders;

class CPU
{
public:
    virtual void caculate1() = 0;
};

class GPU
{
public:
    virtual void caculate2() = 0;
};

class neicun
{
public:
    virtual void caculate3() = 0;
};

class computer
{
public:
    computer( CPU* x, GPU* y, neicun* z):c(x),g(y),n(z){}
    void computerWork()
    {
        c->caculate1();
        g->caculate2();
        n->caculate3();
    }
    virtual ~computer()//释放三个电脑零件内存
    {
        if (c != nullptr)
        {
            delete c;
            c = nullptr;
        }

        if (g != nullptr)
        {
            delete g;
            g = nullptr;
        }

        if (n != nullptr)
        {
            delete n;
            n = nullptr;
        }
    }
private:
    CPU* c;
    GPU* g;
    neicun* n;
};

class intelcpu :public CPU
{
public:
    virtual void caculate1()
    {
        cout << "intel CPU 工作中" << endl;
    }
};
class intelgpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "intel GPU 工作中" << endl;
    }
};
class intelneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "intel 内存 工作中" << endl;
    }
};

class weixingcpu :public CPU
{
public:
    virtual void caculate1()
    {
        cout << "weixing CPU 工作中" << endl;
    }
};
class weixinggpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "weixing GPU 工作中" << endl;
    }
};
class weixingneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "weixing 内存 工作中" << endl;
    }
};

void test1()
{
    CPU* inte = new weixingcpu;
    GPU* gp = new weixinggpu;
    neicun* nei = new weixingneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    cout << endl;
    computer p2(new intelcpu, new weixinggpu, new intelneicun);
    p2.computerWork();
    //delete inte, gp, nei;//第一种释放方式
}

void test2()
{
    CPU* inte = new intelcpu;
    GPU* gp = new weixinggpu;
    neicun* nei = new intelneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    //delete inte, gp, nei;
}

void test3()
{
    CPU* inte = new intelcpu;
    GPU* gp = new intelgpu;
    neicun* nei = new intelneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    //delete inte, gp, nei;
}

int main()
{   
    const char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
    const char** cp[] = { c + 3, c + 2, c + 1, c };
    const char*** cpp = cp;
    printf("%s", **++cpp);
    printf("%s", *-- * ++cpp + 3);
    printf("%s", *cpp[-2] + 3);
    printf("%s\n", cpp[-1][-1] + 1);
    
    return 0;
}

//int main()
//{
//    string folderPath = "H://examtest//";
//    string fileName = "a.txt";
//    string fileName1 = "b.txt";
//    string filePath = folderPath + fileName;
//    string filePath1 = folderPath + fileName1;
//    fstream in(filePath, ios::in);
//    if (!in)
//    {
//        cerr << "无法打开文件：" << filePath << endl;
//        return -1;
//    }
//    vector<string>xy = nn(in, "df", "pg");
//    in.close();
//    fstream out(filePath1, ios::out);
//    if (!out)
//    {
//        cerr << "无法打开文件：" << filePath1 << endl;
//        return -1;
//    }
//    for (auto a : xy)
//        out << a << ' ';
//    out.close();
//    return 0;
//}

/*if (!in)
    {
        cerr << "can't open file" << endl;
        return -1;
    }
    string line;
    vector<string>words;
    while (in>>line)
        words.push_back(line);
    in.close();
    auto it = words.begin();
    while (it != words.end())
    {
        cout << *it << endl;
        ++it;
    }*/
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
//��������
#include<map>
#include<set>
#include<utility>
//������
#include<stack>
#include<queue>
//�㷨
#include<algorithm>
#include<numeric>
#include<functional>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
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
using namespace std;//һ���Ͱ�����usingȫ��Ч��
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
    virtual ~computer()//�ͷ�������������ڴ�
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
        cout << "intel CPU ������" << endl;
    }
};
class intelgpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "intel GPU ������" << endl;
    }
};
class intelneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "intel �ڴ� ������" << endl;
    }
};

class weixingcpu :public CPU
{
public:
    virtual void caculate1()
    {
        cout << "weixing CPU ������" << endl;
    }
};
class weixinggpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "weixing GPU ������" << endl;
    }
};
class weixingneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "weixing �ڴ� ������" << endl;
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
    //delete inte, gp, nei;//��һ���ͷŷ�ʽ
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
//        cerr << "�޷����ļ���" << filePath << endl;
//        return -1;
//    }
//    vector<string>xy = nn(in, "df", "pg");
//    in.close();
//    fstream out(filePath1, ios::out);
//    if (!out)
//    {
//        cerr << "�޷����ļ���" << filePath1 << endl;
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
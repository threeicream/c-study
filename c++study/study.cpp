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
//������
#include<stack>
#include<queue>

#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
#include"test.h"
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
using namespace std;//һ���Ͱ�����usingȫ��Ч��

 /*string xyy(string& x,string&y)
{
	 x = x + y;
	return x;
}*/

 //class X
 //{
	// Y y;
 //};
 //class Y
 //{
	// X* x;
 //};

//vector<int>::iterator asd(const vector<int>::iterator beg, const vector<int>::iterator en, int i)
//{
//    for (auto x = beg; x != en; ++x)
//        if (*x == i)
//            return x;
//    return en;
//}

//void vector_int_sum(const vector<string>& x,double &j)
//{
//    j = 0.0;
//    for (auto a : x)
//    {
//        j += stod(a);
//    }
//}

class A
{
    int a;
public:
    A(int x = 0) :a(x) {}
   const void show1() const
    {
        cout << a << endl;
    }
    void show2()
    {
        cout << a << endl;
    }
};

int main()
{
    int a = 2;
    int b = 3;
    const int c = b;
    
    const int* i = &a;
    i = &c;
    int* const j = &a;
    *j = 4;
    cout << *i << endl;
    /*int* const u = &c;
    u = &b;*/
    
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
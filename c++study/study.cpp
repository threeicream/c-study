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

//class A
//{
//    int a;
//public:
//    A(int x = 0) :a(x) {}
//   const void show1() const
//    {
//        cout << a << endl;
//    }
//    void show2()
//    {
//        cout << a << endl;
//    }
//};
//
//struct A1 {
//    virtual ~A1(){}
//};
//
//struct A2 {
//    virtual ~A2(){}
//};
//struct B1 :A1, A2 {};

//class Base {
//public:
//    int Bar(char x) {
//        return (int)(x);
//    }
//    virtual int Bar(int x) {
//        return (2 * x);
//    }
//};
//class Derived : public Base {
//public:
//    int Bar(char x) {
//        return (int)(-x);
//    }
//    int Bar(int x) {
//        return (x / 2);
//    }
//};

string& trans(string& s)
{
    for (int p = 0; p < s.size(); p++) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main()
{
    //B1 d;
    //A1* pb1 = &d;
    //A2* pb2 = dynamic_cast<A2*>(pb1);
    ////A2* pb22 = static_cast<A2*>(pb1);
    
    //map<string, vector<string>> families;
    ////add_family(families, "��");
    //add_child(families, "��", "ǿ");
    //add_child(families, "��", "��");
    //add_child(families, "��", "��");
    ////add_family(families, "��");
    //for (const auto &f : families) {
    //    cout << f.first << "�ҵĺ��ӣ�";
    //    for (const auto &c : f.second)
    //        cout << c << " ";
    //    cout << endl;
    //}

    map<string, list<int>>x;
    list<int>y;
    string words,line;
    istringstream ss;
    int i = 0;
    ifstream in("H://examtest//a.txt");
    if (!in)
       {
          cerr << "�޷����ļ���"  << endl;
          return -1;
       }
    while (getline(in, line))
    {
        ++i;
        ss.str(line);
        while (ss >> words)
        {
            trans(words);
            x[words].push_back(i);
        }
        ss.clear();
    }
    for (const auto& a : x)
    {
        cout << a.first << "�����У�";
        for (auto& b : a.second)
            cout << b << " ";
        cout << endl;
    }
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
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
//适配器
#include<stack>
#include<queue>
//算法
#include<algorithm>
#include<numeric>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏  assert(x);x为假，输出信息并终止程序运行
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
using namespace std;//一个就把上面using全等效了

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

bool five_or_more(const string& s1)
{
    return s1.size() >= 5;
}

int main()
{
    //B1 d;
    //A1* pb1 = &d;
    //A2* pb2 = dynamic_cast<A2*>(pb1);
    ////A2* pb22 = static_cast<A2*>(pb1);
    //size_t i, j, k;
    //vector<int>x{ 1,3,4,5,6,7 };
    //string words{ "you" };
    ///*auto l=[]() {return 1; };
    //auto a = l();
    //std::partition(x.begin(), x.end(), [&,i,j,k](const string& s1){return s1.size() >= 5; });
    //for (const auto& i : x) {
    //    std::cout << i << ' ';
    //}
    //ostream& os=cout;*/
    //std::vector<int> vec = { 1, 2, 6, 4, 5, 6, 7, 8, 9, 0 };
    //vector<int>xy(vec.size());

    //// 使用lambda表达式作为谓词，查找第一个偶数
    //auto it = find_if(vec.begin(), vec.end(), [](int n) {return n % 3 == 0; });
    //transform(vec.begin(), vec.end(), xy.begin(), [](int n) {return n * n; });
    //for (auto a : xy)
    //    cout << a << ' ';
    vector<string>ff{ "love","you","baby11" };
    auto sum = count_if(ff.begin(), ff.end(), [](string& n) {return n.size() >= 5; });
    cout << sum;
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
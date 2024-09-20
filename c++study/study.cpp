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
//哈希表容器
#include<unordered_map>
#include<unordered_set>
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

template<class nametype=string, class agetype=int>
class ppp
{
public:
    agetype age;
    nametype name;
    ppp(agetype a, nametype n)
    {
        age = a;
        name = n;
    }
    void show()
    {
        cout << age << endl;
        cout << name << endl;
    }
};

class xcv
{
public:
    int x;
    int y;
    xcv() = default;
    xcv(int a,int b,int c):x(a),y(b),z(c){}
    friend void show(xcv& a);
    friend xcv operator+(xcv& a, xcv& b);
private:
    int z;
};

xcv operator+(xcv& a, xcv& b)
{
    xcv p;
    p.x = a.x + b.x;
    p.y = a.y + b.y;
    return p;
}

void show(xcv&a)
{
    cout << a.z;
}

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;//记住mid要Left+
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    ///*ppp <>x(15, "erw");
    //x.show();*/
    //xcv a(1, 2,3);
    //xcv b(2, 3,4);
    //xcv c = a + b;
    //cout << c.x;
    //show(c);
    vector<int>x{ -2,-1,3 };
    cout << search(x, 3);

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
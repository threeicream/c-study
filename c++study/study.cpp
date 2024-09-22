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

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    int compare(string version1, string version2) {
        // write code here
        int i = 0, j = 0;
        int len1 = version1.size(), len2 = version2.size();
        while (i < len1 || j < len2)
        {
            int num1 = 0, num2 = 0;
            while (i < len1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                ++i;
            }
            while (j < len2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }
            if (num1 > num2)
                return 1;
            if (num1 < num2)
                return -1;
            ++i;
            ++j;
        }
        return 0;

    }
};

int i = 0;
class Base {
private:
    int value=1;

public:
    Base() = default;
    Base(int v) : value(v) { cout << "base show" << endl; }
    ~Base() { cout << "~base" <<i++<< endl; }

    // 声明友元函数
    friend void showValue(Base& b);
};

// 友元函数定义
void showValue(Base& b) {
    cout << "Base Value: " << b.value << endl;
}

class Derived : public Base {
    int age;
public:
    Derived(int v) : age(v) { cout << "derived show" << endl; }
    ~Derived() { cout << "~derived" << endl; }
};

int main() {
    Base base(10);
    Derived derived(20);

    // 友元函数可以访问Base类的私有成员
    showValue(base);
    showValue(derived); // 访问Derived对象中的Base部分的私有成员

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
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
//��ϣ������
#include<unordered_map>
#include<unordered_set>
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
        int mid = left + (right - left) / 2;//��סmidҪLeft+
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
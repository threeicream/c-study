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

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return bool������
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

    // ������Ԫ����
    friend void showValue(Base& b);
};

// ��Ԫ��������
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

    // ��Ԫ�������Է���Base���˽�г�Ա
    showValue(base);
    showValue(derived); // ����Derived�����е�Base���ֵ�˽�г�Ա

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
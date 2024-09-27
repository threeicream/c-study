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
//多线程
#include <thread>
//智能指针
#include<memory>

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



class Base {
private:
    int value;

public:
    Base(int v) : value(v) {
        cout << "Base constructor called with value: " << v << endl;
    }
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
    virtual int xyzz() = 0; // 纯虚函数，使Base成为抽象类
};

class Derived : public Base {
private:
    int age;

public:
    Derived(int v, int a) : Base(v), age(a) {
        cout << "Derived constructor called with age: " << a << endl;
    }
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
    int xyzz() override {
        return age;
    }
};

const pair<int, string> valuesy[]{
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
private:
    

public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int num1 = 0, num2 = 0;
        /*int flag1 = 0, flag2 = 0;*/
        long long ans = 0;
        
        for (auto a : text)
        {
            if (a == pattern[1])
            {
                ans += num1;
                ++num2;
            }
            if (a == pattern[0])
            {
                ++num1;
            }
        }
        return ans = max(ans + num1, ans + num2);
    }
    //负二进制
    string baseNeg2(int n) {
        // 如果 n 为 0，直接返回字符串 "0"
        if (n == 0) return "0";

        std::string result = "";

        while (n != 0) {
            // 计算余数
            int remainder = n % -2;
            n /= -2;  // 计算新的商

            // 如果余数为负数，则进行修正
            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }

            // 将当前的余数（0 或 1）添加到结果的前面
            result = std::to_string(remainder) + result;
        }

        return result;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {   
        int a = 0, b = 0;
        ListNode* test1 = l1, *test2 = l2;
        while (test1 != nullptr || test2 != nullptr)
        {
            if (test1) { test1 = test1->next; ++a;}
            if (test2) { test2 = test2->next; ++b;}
        }
        ListNode* result;
        if (a > b)
        {
            result = l1;
        }
        else
        {
            result = l1;
            l1 = l2;
            l2 = result;
            result = l1;
        }
        int flag = 0;

        //新建一条链表储存
        /*ListNode* head = nullptr, * tail = nullptr;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + flag;
            if (!head)
                head = tail = new ListNode(sum % 10);
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            flag = sum / 10;
            if (l1)l1 = l1->next;
            if (l2)l2 = l2->next;
        }
        if (flag > 0)
            tail->next = new ListNode(flag);*/

        while (l1 != nullptr && l2 != nullptr)
        {
            l1->val += l2->val;
            flag = l1->val / 10;
            if (flag)
            {
                l1->val = l1->val % 10;
            }

            if (l1->next) {
                l1 = l1->next;
                l1->val += flag;
                flag = 0;
            }
            else if (flag)
            {
                l1->next = new ListNode();
                l1 = l1->next;
                l1->val += flag;
                flag = 0;
            }
            else
                break;

            if (l2->next) l2 = l2->next;
            else
                break;
        }
        flag = l1->val / 10;
        l1->val = l1->val % 10;
        while (flag)
        {
            if (l1->next) {
                l1 = l1->next;
                l1->val += flag;
                flag = l1->val / 10;
                l1->val = l1->val % 10;
            }
            else
            {
                l1->next = new ListNode();
                l1 = l1->next;
                l1->val += flag;
                flag = 0;
            }
        }
        return result;
    }
	bool isPalindrome(int x) {
		if (x < 0)return false;
		vector<int>u;
		while (x)
		{
			int i = x % 10;
            x = x / 10;
			u.push_back(i);
		}
        int a = 0, b = u.size() - 1;
        while (b > a)
        {
            if (u[a] == u[b])
            {
                ++a;
                --b;
            }
            else
                return false;
        }
        return true;
	}
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int index = 0, n = str.size(), sign = 1, res = 0;
		// 处理前置空格
		while (index < n && str[index] == ' ') {
			++index;
		}
		// 处理符号
		if (index < n && (str[index] == '+' || str[index] == '-')) {
			sign = str[index++] == '+' ? 1 : -1;
		}
		// 处理数字
		while (index < n && isdigit(str[index])) {
			int digit = str[index] - '0';
			// 判断是否溢出
			if (res > (INT_MAX - digit) / 10) {
				return sign == 1 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + digit;
			++index;
		}
		return res * sign;
	}
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
				return 0;
			}
			int digit = x % 10;
			x /= 10;
			rev = rev * 10 + digit;
		}
		return rev;
	}

};



class A
{
public:
	void foo() {
		std::cout << "hello" << std::endl; // 访问已经被销毁的指针
	}
};

int main() {
	/*ListNode* l1 = new ListNode(0, nullptr);
	ListNode* le = new ListNode(9, l1);
	ListNode* ld = new ListNode(9, le);
	ListNode* lc = new ListNode(9, ld);
	ListNode* la = new ListNode(9, lc);
	ListNode* lb = new ListNode(9, la);

	ListNode* l2 = new ListNode(3, nullptr);
	ListNode* lx = new ListNode(7, l2);
	ListNode* ly = new ListNode(9, lx);*/
    
	Solution x;
    cout << x.reverse(-123);
    
    /*std::shared_ptr<A> a = std::make_shared<A>();
    thread t(&A::foo,a);
    t.join();*/
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
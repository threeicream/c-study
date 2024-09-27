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
//���߳�
#include <thread>
//����ָ��
#include<memory>

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
    virtual int xyzz() = 0; // ���麯����ʹBase��Ϊ������
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
    //��������
    string baseNeg2(int n) {
        // ��� n Ϊ 0��ֱ�ӷ����ַ��� "0"
        if (n == 0) return "0";

        std::string result = "";

        while (n != 0) {
            // ��������
            int remainder = n % -2;
            n /= -2;  // �����µ���

            // �������Ϊ���������������
            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }

            // ����ǰ��������0 �� 1����ӵ������ǰ��
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

        //�½�һ��������
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
		// ����ǰ�ÿո�
		while (index < n && str[index] == ' ') {
			++index;
		}
		// �������
		if (index < n && (str[index] == '+' || str[index] == '-')) {
			sign = str[index++] == '+' ? 1 : -1;
		}
		// ��������
		while (index < n && isdigit(str[index])) {
			int digit = str[index] - '0';
			// �ж��Ƿ����
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
		std::cout << "hello" << std::endl; // �����Ѿ������ٵ�ָ��
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
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

//class 

//class Solution {
//private:
//    
//
//public:
//    long long maximumSubsequenceCount(string text, string pattern) {
//        int num1 = 0, num2 = 0;
//        /*int flag1 = 0, flag2 = 0;*/
//        long long ans = 0;
//        
//        for (auto a : text)
//        {
//            if (a == pattern[1])
//            {
//                ans += num1;
//                ++num2;
//            }
//            if (a == pattern[0])
//            {
//                ++num1;
//            }
//        }
//        return ans = max(ans + num1, ans + num2);
//    }
//    //负二进制
//    string baseNeg2(int n) {
//        // 如果 n 为 0，直接返回字符串 "0"
//        if (n == 0) return "0";
//
//        std::string result = "";
//
//        while (n != 0) {
//            // 计算余数
//            int remainder = n % -2;
//            n /= -2;  // 计算新的商
//
//            // 如果余数为负数，则进行修正
//            if (remainder < 0) {
//                remainder += 2;
//                n += 1;
//            }
//
//            // 将当前的余数（0 或 1）添加到结果的前面
//            result = std::to_string(remainder) + result;
//        }
//
//        return result;
//    }
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//    {   
//        int a = 0, b = 0;
//        ListNode* test1 = l1, *test2 = l2;
//        while (test1 != nullptr || test2 != nullptr)
//        {
//            if (test1) { test1 = test1->next; ++a;}
//            if (test2) { test2 = test2->next; ++b;}
//        }
//        ListNode* result;
//        if (a > b)
//        {
//            result = l1;
//        }
//        else
//        {
//            result = l1;
//            l1 = l2;
//            l2 = result;
//            result = l1;
//        }
//        int flag = 0;
//
//        //新建一条链表储存
//        /*ListNode* head = nullptr, * tail = nullptr;
//        while (l1 || l2)
//        {
//            int n1 = l1 ? l1->val : 0;
//            int n2 = l2 ? l2->val : 0;
//            int sum = n1 + n2 + flag;
//            if (!head)
//                head = tail = new ListNode(sum % 10);
//            else
//            {
//                tail->next = new ListNode(sum % 10);
//                tail = tail->next;
//            }
//            flag = sum / 10;
//            if (l1)l1 = l1->next;
//            if (l2)l2 = l2->next;
//        }
//        if (flag > 0)
//            tail->next = new ListNode(flag);*/
//
//        while (l1 != nullptr && l2 != nullptr)
//        {
//            l1->val += l2->val;
//            flag = l1->val / 10;
//            if (flag)
//            {
//                l1->val = l1->val % 10;
//            }
//
//            if (l1->next) {
//                l1 = l1->next;
//                l1->val += flag;
//                flag = 0;
//            }
//            else if (flag)
//            {
//                l1->next = new ListNode();
//                l1 = l1->next;
//                l1->val += flag;
//                flag = 0;
//            }
//            else
//                break;
//
//            if (l2->next) l2 = l2->next;
//            else
//                break;
//        }
//        flag = l1->val / 10;
//        l1->val = l1->val % 10;
//        while (flag)
//        {
//            if (l1->next) {
//                l1 = l1->next;
//                l1->val += flag;
//                flag = l1->val / 10;
//                l1->val = l1->val % 10;
//            }
//            else
//            {
//                l1->next = new ListNode();
//                l1 = l1->next;
//                l1->val += flag;
//                flag = 0;
//            }
//        }
//        return result;
//    }
//	bool isPalindrome(int x) {
//		if (x < 0)return false;
//		vector<int>u;
//		while (x)
//		{
//			int i = x % 10;
//            x = x / 10;
//			u.push_back(i);
//		}
//        int a = 0, b = u.size() - 1;
//        while (b > a)
//        {
//            if (u[a] == u[b])
//            {
//                ++a;
//                --b;
//            }
//            else
//                return false;
//        }
//        return true;
//	}
//	int myAtoi(string str) {
//		if (str.empty()) return 0;
//		int index = 0, n = str.size(), sign = 1, res = 0;
//		// 处理前置空格
//		while (index < n && str[index] == ' ') {
//			++index;
//		}
//		// 处理符号
//		if (index < n && (str[index] == '+' || str[index] == '-')) {
//			sign = str[index++] == '+' ? 1 : -1;
//		}
//		// 处理数字
//		while (index < n && isdigit(str[index])) {
//			int digit = str[index] - '0';
//			// 判断是否溢出
//			if (res > (INT_MAX - digit) / 10) {
//				return sign == 1 ? INT_MAX : INT_MIN;
//			}
//			res = res * 10 + digit;
//			++index;
//		}
//		return res * sign;
//	}
//	int reverse(int x) {
//		int rev = 0;
//		while (x != 0) {
//			if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
//				return 0;
//			}
//			int digit = x % 10;
//			x /= 10;
//			rev = rev * 10 + digit;
//		}
//		return rev;
//	}
//	string longestPalindrome(string s) {//中心扩散法
//        if (s.empty())return "";
//        int maxlen = 1;
//        int start = 0;
//
//        for (int i = 0; i < s.size(); ++i)
//        {
//            int low = i, high = i;
//            while (low >= 0 && high < s.size() && s[low] == s[high])
//            {
//                if (high - low + 1 > maxlen)
//                {
//                    start = low;
//                    maxlen = high - low + 1;
//                }
//                --low, ++high;
//            }
//
//			low = i, high = i + 1;
//			while (low >= 0 && high < s.size() && s[low] == s[high]) {
//				if (high - low + 1 > maxlen) {
//					start = low;
//					maxlen = high - low + 1;
//				}
//				--low;
//				++high;
//			}
//        }
//        return s.substr(start, maxlen);
//	}
//	string longestPalindrome1(string s) {//动态规划
//		int n = s.size();
//		if (n < 2) {
//			return s;
//		}
//
//		int maxLen = 1;
//		int begin = 0;
//		// dp[i][j] 表示 s[i..j] 是否是回文串
//		vector<vector<int>> dp(n, vector<int>(n));
//		// 初始化：所有长度为 1 的子串都是回文串
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = true;
//		}
//		// 递推开始
//		// 先枚举子串长度
//		for (int L = 2; L <= n; L++) {
//			// 枚举左边界，左边界的上限设置可以宽松一些
//			for (int i = 0; i < n; i++) {
//				// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//				int j = L + i - 1;
//				// 如果右边界越界，就可以退出当前循环
//				if (j >= n) {
//					break;
//				}
//
//				if (s[i] != s[j]) {
//					dp[i][j] = false;
//				}
//				else {
//					if (j - i < 3) {
//						dp[i][j] = true;
//					}
//					else {
//						dp[i][j] = dp[i + 1][j - 1];
//					}
//				}
//
//				// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//				if (dp[i][j] && j - i + 1 > maxLen) {
//					maxLen = j - i + 1;
//					begin = i;
//				}
//			}
//		}
//		return s.substr(begin, maxLen);
//	}
//	string longestCommonPrefix(vector<string>& strs) {
//        if (!strs.size())
//            return "";
//        string pre = strs[0];
//        for (int i = 1; i < strs.size(); ++i)
//        {
//            pre = longestCommonPrefix(pre, strs[i]);
//            if (!pre.size())
//                break;
//        }
//        return pre;
//	}
//    string longestCommonPrefix(string& str1, string& str2)
//    {
//        int len = min(str1.size(), str2.size());
//        string s;
//
//        for (int i = 0; i < len; ++i)
//        {
//            if (str1[i] == str2[i])
//                s += str1[i];
//            else
//                break;
//        }
//        return s;
//    }
//    string longestCommonPrefix1(vector<string>& strs)
//    {
//        if (!strs.size())
//            return "";
//        
//        int len = strs[0].size();
//        for (int i = 0; i < len; ++i)
//        {
//            char ch = strs[0][i];
//            for (int j = 0; j < strs.size(); ++j)
//            {
//                if (i == strs[j].size() || strs[j][i] != ch)
//                    return strs[0].substr(0, i);
//            }
//        }
//        return strs[0];
//    }
//	bool isValid(string s) {
//        if (s.empty())return true;
//        stack<char>u;
//        u.push(s[0]);
//        char ch = 0, sh = 0;;
//        for (int i = 1; i < s.size(); ++i)
//        {
//            if(!u.empty())
//                ch = u.top();
//            u.push(s[i]);
//            sh = u.top();
//            if (sh - ch == 2 || sh - ch == 1)
//            {
//                u.pop();
//                u.pop();
//                ch = 0, sh = 0;
//            }
//        }
//        if (u.empty())
//            return true;
//        else
//            return false;
//
//	}
//    bool isValid1(string s)//栈+哈希表
//    {
//        if (s.size() == 1)
//            return false;
//        unordered_map<char, char>pairs{
//            {')','('},
//            {']','['},
//            {'}','{'}
//        };
//        stack<char>u;
//        for (char ch : s)
//        {
//            if (pairs.count(ch))
//            {
//                if (u.empty() || u.top() != pairs[ch])
//                    return false;
//                u.pop();
//            }
//            else
//                u.push(ch);
//        }
//        return u.empty();
//    }
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {//递归
//		if (l1 == nullptr) {
//			return l2;
//		}
//		else if (l2 == nullptr) {
//			return l1;
//		}
//		else if (l1->val < l2->val) {
//			l1->next = mergeTwoLists(l1->next, l2);
//			return l1;
//		}
//		else {
//			l2->next = mergeTwoLists(l1, l2->next);
//			return l2;
//		}
//	}
//    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2)//迭代
//    {
//        ListNode* prehead = new ListNode();
//        ListNode* pre = prehead;
//        while (l1 && l2)
//        {
//            if (l1->val < l2->val)
//            {
//                pre->next = l1;
//                l1 = l1->next;
//            }
//            else
//            {
//                pre->next = l2;
//                l2 = l2->next;
//            }
//            pre = pre->next;
//        }
//        pre->next = l1 == nullptr ? l2 : l1;
//        return prehead->next;
//    }
//	int removeElement(vector<int>& nums, int val) {
//        int num = 0;
//        vector<int>x;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (nums[i] != val)
//            {
//                ++num;
//                x.push_back(nums[i]);
//            }
//        }
//        for (int i = 0; i < x.size(); ++i)
//        {
//            nums[i] = x[i];
//        }
//        return num;
//	}
//    int removeElement1(vector<int>& nums, int val)
//    {
//        int left = 0;
//        for (int right = 0; right < nums.size(); ++right)
//        {
//            if (nums[right] != val)
//            {
//                nums[left] = nums[right];
//                ++left;
//            }
//        }
//        return left;
//    }
//    int removeElement2(vector<int>& nums, int val)
//    {
//		int left = 0;
//		int right = nums.size();
//        while (left < right)
//        {
//            if (nums[left] == val)
//            {
//                nums[left] = nums[right - 1];
//                --right;
//            }
//            else
//                ++left;
//
//        }
//        return left;
//    }
//};

class Solution
{
public:
	string convert(string s, int numRows) {
        int n = s.size(), r = numRows;
        if (r == 1 || r >= n)
            return s;
        int t = 2 * (r - 1);
        int zq = n / t;
        if (n % t)
            ++zq;
        int c = zq * (r - 1);
        vector<string>ls(r);

        int i = 0, j = 0;
        int a = 0;
        while (a < n)
        {
            ls[i] += s[a];
            if (a % t < r - 1 )
			{
                ++i;
            }
            else
            {
                --i;
            }
            ++a;
        }
		string ans;
        for (auto& row : ls)
            ans += row;

        return ans;
	}
	int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;

        while (i < m && j < n)
		{
            for (j; j < n; ++j)
                if (haystack[j] == needle[0])
                    break;

			for (i = 0; i < m ; ++i)
			{
                if (haystack[i + j] != needle[i])
                {
                    ++j;
                    break;
                }
			}
		}
        if (i == m)
            return j;
        else
            return -1;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int k = n - 1;
            int target = -nums[i];
            for (int j = i + 1; j < n; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (j<k && nums[j] + nums[k]>target)
                {
                    --k;
                }
                if (j == k)
                    break;
                if (j < k && nums[j] + nums[k] == target)
                    ans.push_back({ nums[i],nums[j],nums[k] });
            }
        }
        return ans;
	}
	int divide(int dividend, int divisor) {
        bool fu = ((dividend >> 31) ^ (divisor >> 31));
		if (dividend > 0) dividend = -dividend;
		if (divisor > 0) divisor = -divisor;
        
	}
	int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        while(i<s.size())
            if (s[i] == ' ')
            {
                ++i;
                continue; 
            }
            else 
                break;
        if (i == s.size())return 0;
        int j = i;
        for (j; j < s.size(); ++j)
            if (s[j] == ' ')
                break;
        return j - i;
	}
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;
        int high = 0;
        for (int i = digits.size() - 1; i > 0; --i)
        {
            high = digits[i] / 10;
            digits[i] %= 10;
            if (high)
                digits[i - 1] += high;
            else
                break;
        }
        if (digits[0] == 10)
        {
            digits[0] = 1; digits.push_back(0);
        }
        return digits;
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
    ListNode* l1 = new ListNode(4, nullptr);
    ListNode* le = new ListNode(3, l1);
    ListNode* ld = new ListNode(2, le);
    ListNode* lc = new ListNode(1, ld);
    ListNode* la = new ListNode(9, lc);
    ListNode* lb = new ListNode(9, la);

    ListNode* l2 = new ListNode(5, nullptr);
    ListNode* lx = new ListNode(3, l2);
    ListNode* ly = new ListNode(2, lx);
    
	Solution x;
    vector<int>nums{ 9,9 };
    x.plusOne(nums);
    //cout << (int)'<' << " " << (int)'>' << " " << (int)'[' << " " << (int)']' << " " << (int)'{' << " " << (int)'}';
    
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
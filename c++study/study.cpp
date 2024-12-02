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
#include <mutex>
#include <condition_variable>
//智能指针
#include<memory>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏  assert(x);x为假，输出信息并终止程序运行
#include"test.h"
#include"cp.h"
//#include"person.h"

#include <bit>


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

//class 
//string convert(string s, int numRows) {
//    int n = s.size(), r = numRows;
//    if (r == 1 || r >= n)
//        return s;
//    int t = 2 * (r - 1);
//    int zq = n / t;
//    if (n % t)
//        ++zq;
//    int c = zq * (r - 1);
//    vector<string>ls(r);
//
//    int i = 0, j = 0;
//    int a = 0;
//    while (a < n)
//    {
//        ls[i] += s[a];
//        if (a % t < r - 1)
//        {
//            ++i;
//        }
//        else
//        {
//            --i;
//        }
//        ++a;
//    }
//    string ans;
//    for (auto& row : ls)
//        ans += row;
//
//    return ans;
//}
//int strStr(string haystack, string needle) {
//    int n = haystack.size();
//    int m = needle.size();
//    int i = 0, j = 0;
//
//    while (i < m && j < n)
//    {
//        for (j; j < n; ++j)
//            if (haystack[j] == needle[0])
//                break;
//
//        for (i = 0; i < m; ++i)
//        {
//            if (haystack[i + j] != needle[i])
//            {
//                ++j;
//                break;
//            }
//        }
//    }
//    if (i == m)
//        return j;
//    else
//        return -1;
//}
//vector<vector<int>> threeSum(vector<int>& nums) {
//    int n = nums.size();
//    sort(nums.begin(), nums.end());
//    vector<vector<int>>ans;
//
//    for (int i = 0; i < n; ++i)
//    {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//        int k = n - 1;
//        int target = -nums[i];
//        for (int j = i + 1; j < n; ++j)
//        {
//            if (j > i + 1 && nums[j] == nums[j - 1])
//                continue;
//            while (j<k && nums[j] + nums[k]>target)
//            {
//                --k;
//            }
//            if (j == k)
//                break;
//            if (j < k && nums[j] + nums[k] == target)
//                ans.push_back({ nums[i],nums[j],nums[k] });
//        }
//    }
//    return ans;
//}
//int divide(int dividend, int divisor) {
//    bool fu = ((dividend >> 31) ^ (divisor >> 31));
//    if (dividend > 0) dividend = -dividend;
//    if (divisor > 0) divisor = -divisor;
//
//}
//int lengthOfLastWord(string s) {
//    reverse(s.begin(), s.end());
//    int i = 0;
//    while (i < s.size())
//        if (s[i] == ' ')
//        {
//            ++i;
//            continue;
//        }
//        else
//            break;
//    if (i == s.size())return 0;
//    int j = i;
//    for (j; j < s.size(); ++j)
//        if (s[j] == ' ')
//            break;
//    return j - i;
//}
//vector<int> plusOne(vector<int>& digits) {
//    digits[digits.size() - 1] += 1;
//    int high = 0;
//    for (int i = digits.size() - 1; i > 0; --i)
//    {
//        high = digits[i] / 10;
//        digits[i] %= 10;
//        if (high)
//            digits[i - 1] += high;
//        else
//            break;
//    }
//    if (digits[0] == 10)
//    {
//        digits[0] = 1; digits.push_back(0);
//    }
//    return digits;
//}
//string addBinary(string a, string b) {
//    string Max, Min;
//    Max = a.size() >= b.size() ? a : b;
//    Min = a.size() < b.size() ? a : b;
//    int m = Max.size(), n = Min.size();
//
//    for (int i = 1; i <= Min.size(); ++i)
//    {
//        Max[m - i] += Min[n - i] - '0';
//    }
//
//    int ch = 0;
//    for (int i = Max.size() - 1; i > 0; --i)
//    {
//        ch = (Max[i] - '0') / 2;
//        Max[i] = '0' + (Max[i] - '0') % 2;
//        Max[i - 1] += ch;
//    }
//
//    string s;
//    while (Max[0] - '0' > 1)
//    {
//        int t = (Max[0] - '0') / 2;
//        s += ('0' + t);
//        //int t = (Max[0] - '0') / 2;
//        int h = (Max[0] - '0') % 2;
//        Max[0] = '0' + h;
//    }
//    s += Max;
//    return s;
//}
//int climbStairs(int n) {
//    vector<int>dp(n + 1, 0);
//    dp[0] = 1, dp[1] = 1;
//    if (n == 0)return 0;
//    if (n < 2)return 1;
//
//    for (int i = 2; i <= n; ++i)
//    {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    return dp[n];
//}
//ListNode* deleteDuplicates(ListNode* head) {
//    ListNode* test = head;
//    while (test && test->next != nullptr)
//    {
//        if (test->val == test->next->val)
//        {
//            test->next = test->next->next; continue;
//        }
//        test = test->next;
//    }
//    return head;
//}
//
//vector<int>memo;
//int dfs(int n)
//{
//    if (n <= 2)return n;
//    if (memo[n] != INT_MAX)
//        return memo[n];
//    int ans = memo[n];
//    for (int i = 1; i <= n; ++i)
//    {
//        int broken = i - 1;
//        int notbroken = dfs(n - i);
//        int wrost = max(broken, notbroken) + 1;
//        ans = min(ans, wrost);
//    }
//    memo[n] = ans;
//    return ans;
//}
//int twoEggDrop(int n) {
//    /*vector<int>memo(n + 1,INT_MAX);
//    memo[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int k = 1; k <= i; ++k) {
//            memo[i] = min(memo[i], max(k - 1, memo[i - k]) + 1);
//        }
//    }
//    return memo[n];*/;
//    memo = vector<int>(n + 1, INT_MAX);
//    return memo[n];
//}
//
//int searchInsert(vector<int>& nums, int target) {
//    int left = 0;
//    int right = nums.size() - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] == target)
//            return mid;
//        if (nums[mid] < target)
//        {
//            left = mid + 1;
//        }
//        if (nums[mid] > target)
//        {
//            right = mid - 1;
//        }
//    }
//    return target;
//}
//
//unordered_map<int, int>memo1;
//int dp(int k, int n)
//{
//    if (memo1.find(n * 100 + k) == memo1.end()) {
//        int ans;
//        if (n == 0) {
//            ans = 0;
//        }
//        else if (k == 1)
//            ans = n;
//        else {
//            int lo = 1, hi = n;
//            while (lo <= hi)
//            {
//                int x = lo + (hi - lo) / 2;
//                int t1 = dp(k - 1, x - 1);
//                int t2 = dp(k, n - x);
//
//                if (t1 < t2)
//                    lo = x + 1;
//                else if (t1 > t2)
//                    hi = x - 1;
//                else
//                {
//                    hi = lo = x;
//                    break;
//                }
//            }
//            ans = 1 + min(max(dp(k - 1, lo - 1), dp(k, n - lo)), max(dp(k - 1, hi - 1), dp(k, n - hi)));
//        }
//        memo1[n * 100 + k] = ans;
//    }
//    return memo1[n * 100 + k];
//}
//int superEggDrop(int k, int n) {
//    return dp(k, n);
//}
//
//int maxHeightOfTriangle(int red, int blue) {
//    if (red <= 1 && blue <= 1)return red < blue ? red : blue;
//
//    int num1 = 1;
//    int t1 = red;
//    int t2 = blue;
//    while (t1 >= 0 && t2 >= 0) {
//        t1 -= num1;
//        ++num1;
//        if (t2 > 0 && t1 >= 0) {
//            t2 -= num1;
//            ++num1;
//        }
//        else if (t2 == 0)
//            break;
//    }
//    if (t1 < 0) --num1;
//    if (t2 < 0)--num1;
//
//    int num2 = 1;
//    int s1 = blue;
//    int s2 = red;
//    while (s1 >= 0 && s2 >= 0) {
//        s1 -= num2;
//        ++num2;
//        if (s2 > 0 && s1 >= 0) {
//            s2 -= num2;
//            ++num2;
//        }
//        else if (s2 == 0)
//            break;
//    }
//    if (s1 < 0) --num2;
//    if (s2 < 0)--num2;
//    return (num1 > num2 ? num1 : num2) - 1;
//}
//double minimumAverage(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    double min = INT_MAX;
//    for (int i = 0; i < nums.size() / 2; ++i)
//    {
//        min = min < (nums[i] + nums[nums.size() - 1 - i]) ? min : (nums[i] + nums[nums.size() - 1 - i]);
//    }
//    return  min / 2;
//}
//string destCity(vector<vector<string>>& paths) {
//    unordered_map<string, int>Tmap;
//    for (int i = 0; i < paths.size(); ++i)
//        Tmap[paths[i][0]] = i;
//    int a = 0;
//    for (a; a < paths.size(); ++a) {
//        if (Tmap.find(paths[a][1]) == Tmap.end())
//            break;
//    }
//    return paths[a][1];
//}
//int maxArea(vector<int>& height) {
//    int nums = height.size();
//    int ans = INT_MIN;
//    int i = 0, j = nums - 1;
//    while (i < j)
//    {
//        int x = j - i;
//        int y = min(height[i], height[j]);
//        ans = max(ans, x * y);
//        if (height[i] < height[j])
//            ++i;
//        else
//            --j;
//    }
//    return ans;
//}
//int minOperations(vector<int>& nums) {//从第一个0开始处理
//    int ans = 0;
//    for (int i = 0; i < nums.size() - 2; ++i) {
//        if (nums[i] == 0) {
//            ++ans;
//            if (i > nums.size() - 3)return-1;
//            for (int j = i; j < i + 3; ++j)
//                nums[j] = 1 - nums[j];
//        }
//    }
//    return ans;
//}
//int minOperations1(vector<int>& nums) {
//    int ans = 1 - nums[0];
//    for (int i = 0; i < nums.size() - 1; ++i) {
//        if (nums[i] != nums[i + 1])
//            ++ans;
//    }
//    return ans;
//}
//int smallestRangeI(vector<int>& nums, int k) {
//    int Max = *std::max_element(nums.begin(), nums.end());
//    int Min = *std::min_element(nums.begin(), nums.end());
//    int ans = Max - Min;
//    if (ans < 2 * k)
//        return 0;
//    else
//        return ans - 2 * k;
//}
//int threeSumClosest(vector<int>& nums, int target) {
//    if (nums.size() < 3)return 0;
//    if (nums.size() == 3)return nums[0] + nums[1] + nums[2];
//
//    int best = 1e7;
//    sort(nums.begin(), nums.end());
//    for (int i = 0; i < nums.size(); ++i) {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//        int j = i + 1;
//        int k = nums.size() - 1;
//
//        while (j < k) {
//            int sum = nums[i] + nums[j] + nums[k];
//
//            if (sum == target) return target;
//
//            if (abs(sum - target) < abs(best - target)) {
//                best = sum;
//            }
//
//            if (sum > target) {
//                --k;
//                while (j < k && nums[k] == nums[k + 1]) --k;
//            }
//            else {
//                ++j;
//                while (j < k && nums[j] == nums[j - 1]) ++j;
//            }
//        }
//    }
//
//    return best;
//}
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//    if (m == 0) {
//        for (int j = 0; j < nums1.size(); ++j) {
//            nums1[j] = nums2[j];
//        }
//        return;
//    }
//    else if (n == 0)return;
//
//    int i = nums1.size() - 1;
//
//    while (i >= 0) {
//        if (n > 0 && m > 0)
//        {
//            /* nums1[i] = nums1[m - 1] > nums2[n - 1] ? nums1[m - 1] : nums2[n - 1]; */
//            if (nums1[m - 1] > nums2[n - 1]) {
//                nums1[i] = nums1[m - 1];
//                nums1[m - 1] = INT_MIN;
//                --m;
//            }
//            else {
//                nums1[i] = nums2[n - 1];
//                --n;
//            }
//        }
//        else if (m == 0) {
//            nums1[i] = INT_MIN;
//            nums1[i] = nums1[i] > nums2[n - 1] ? nums1[i] : nums2[n - 1];
//            --n;
//        }
//        --i;
//    }
//}
//int countCompleteDayPairs(vector<int>& hours) {
//    unordered_map<int, int>hash;
//    int ans = 0;
//    for (auto a : hours) {
//        int n = a % 24;
//        int gap = (24 - n) % 24;
//        ans += hash[gap];
//        ++hash[n];
//    }
//    return ans;
//}
//*vector<int> twoSum(vector<int>& nums, int target) {
//    unordered_map<int, int>hash;
//    vector<int>ans;
//    for (int i = 0; i < nums.size(); ++i) {
//        int n = target - nums[i];
//        auto it = hash.find(n);
//        if (it!=hash.end()) {
//            return{ it->second,i };
//        }
//        hash[nums[i]] = i;
//    }
//    return {};
//}*/
//int findWinningPlayer(vector<int>& skills, int k) {
//    int ans = 0;
//    if (k > skills.size()) {
//        auto a = max_element(skills.begin(), skills.end());
//        ans = distance(skills.begin(), a);
//        return ans;
//    }
//
//    int win = k;
//    //unordered_map<int, int>loser;
//    int i = 0;
//    int s = 1;
//    int j = 0;
//    while (win > 0) {
//        if (i + s < skills.size())
//            if (skills[i] > skills[i + s]) {
//                --win;
//                ++s;
//                //loser.insert(i + s, skills[i + s]);
//                ans = i;
//            }
//            else {
//                ++i;
//                s = 1;
//                win = k - 1;
//                ans = i;
//            }
//        else if (i + s == skills.size())
//            break;
//        else if (i + s > skills.size())
//        {
//            ans = skills.size() - 1;
//            break;
//        }
//    }
//    return ans;
//}
//void panduan(TreeNode* p, TreeNode* q, bool& ans) {
//    if (p == nullptr && q == nullptr)
//    {
//        ans = 1;
//        return;
//    }
//    else if (!p || !q)
//    {
//        ans = 0;
//        return;
//    }
//    if (p->val != q->val)
//    {
//        ans = 0;
//        return;
//    }
//    if (!ans)return;
//    panduan(p->left, q->left, ans);
//    if (!ans)return;
//    panduan(p->right, q->right, ans);
//    if (!ans)return;
//}
//bool isSameTree(TreeNode* p, TreeNode* q) {
//    bool ans = 1;
//    panduan(p, q, ans);
//    return ans;
//}
//bool isPowerOfTwo(int n) {
//    if (n == 1)return true;
//    if (!n)return false;
//    if (n % 2)return false;
//
//    while (n > 1) {
//        n /= 2;
//        if (n == 1)break;
//        if (n % 2)return false;
//    }
//    return true;
//}
//
//long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
//    int n = energyDrinkA.size();
//    vector<vector<long long>>dp(n + 1, vector<long long>(2, 0));
//
//    for (int i = 1; i <= n; ++i) {
//        dp[i][0] = dp[i - 1][0] + energyDrinkA[i - 1];
//        dp[i][1] = dp[i - 1][1] + energyDrinkB[i - 1];
//        if (i >= 2) {
//            dp[i][0] = max(dp[i][0], dp[i - 2][1] + energyDrinkA[i - 1]);
//            dp[i][1] = max(dp[i][1], dp[i - 2][0] + energyDrinkB[i - 1]);
//        }
//    }
//    return max(dp[n][0], dp[n][1]);
//}
//int rob(vector<int>& nums) {
//    int n = nums.size();
//    if (n == 1)return nums[0];
//
//    vector<int>dp(n + 1, -1);
//    dp[0] = nums[0];
//    dp[1] = max(nums[0], nums[1]);
//    for (int i = 2; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//    }
//    return dp[n - 1];
//}
//
//void swap(int& a, int& b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//
//void maopaoSort(vector<int>& nums) {
//    int lastchange = 0;
//    int sortborder = nums.size() - 1;
//
//    for (int i = 0; i < nums.size() - 1; ++i) {
//        bool flag = true;
//        for (int j = 0; j < sortborder; ++j) {
//            if (nums[j] >= nums[j + 1])
//            {
//                swap(nums[j], nums[j + 1]);
//                flag = false;
//                lastchange = j;
//            }
//        }
//        sortborder = lastchange;
//        if (flag)
//            break;
//    }
//}
//
//void selSort(vector<int>& nums) {
//    for (int i = 0; i < nums.size() / 2; ++i) {
//        int minIndex = i;
//        int maxIndex = i;
//        for (int j = i; j < nums.size() - i; ++j) {
//            if (nums[minIndex] > nums[j])
//                minIndex = j;
//            if (nums[maxIndex] < nums[j])
//                maxIndex = j;
//        }
//        swap(nums[i], nums[minIndex]);
//        // 如果最大值被交换到了最小值的位置，需要更新最大值的索引 
//        if (maxIndex == i) maxIndex = minIndex;
//        swap(nums[nums.size() - i - 1], nums[maxIndex]);
//    }
//}
//
//void insSort(vector<int>& nums) {
//    for (int i = 1; i < nums.size(); ++i) {
//        int key = nums[i];
//        int j = i - 1;
//        while (j >= 0 && nums[j] > key) {
//            nums[j + 1] = nums[j];
//            --j;
//        }
//        nums[j + 1] = key;
//    }
//}
//
//void shellSort(vector<int>& nums) {
//    int n = nums.size();
//    int i, j, inc, key;
//    //初始增量：n/2，每一趟之后除以2
//    for (inc = n / 2; inc > 0; inc /= 2) {
//        //每一趟采用插入排序
//        for (i = inc; i < n; ++i) {
//            key = nums[i];
//            j = i - inc;
//            while (j >= 0 && nums[j] > key) {
//                nums[j + inc] = nums[j];
//                j -= inc;
//            }
//            nums[j + inc] = key;
//        }
//    }
//}
//
//void countSort(vector<int>& nums, vector<int>& ans) {
//    int Min = *min_element(nums.begin(), nums.end());
//    int Max = *max_element(nums.begin(), nums.end());
//    int d = Max - Min;
//    vector<int>count(d + 1, 0);
//    //计数数组
//    for (auto i : nums)
//        ++count[i - Min];
//    //累计数组
//    for (int i = 1; i < count.size(); ++i)
//        count[i] += count[i - 1];
//    //最终结果
//    for (int i = 0; i < nums.size(); ++i) {
//        int a = count[nums[i] - Min];
//        --count[nums[i] - Min];
//        ans[a - 1] = nums[i];
//    }
//
//
//}
//
//void quickSort(vector<int>& nums, int left, int right) {
//    if (left >= right)return;
//    int pivot = nums[right];
//    int i = left, j = right - 1;
//    while (i <= j)
//    {
//        while (i <= j && nums[i] <= pivot)//找到左边比pivot大的
//            ++i;
//        while (i <= j && nums[j] > pivot)//找到右边比pivot小的
//            --j;
//        if (i < j)//交换两者，升序排序
//            swap(nums[i], nums[j]);
//    }
//    swap(nums[i], nums[right]);//将pivot移动到正确的位置
//    quickSort(nums, left, i - 1);
//    quickSort(nums, i + 1, right);
//
//}
//
//vector<int> sortedSquares(vector<int>& nums) {
//    int k = nums.size() - 1;
//    vector<int>ans(k + 1, INT_MIN);
//    int i = 0, j = k;
//    while (i <= j) {
//        if (nums[i] * nums[i] > nums[j] * nums[j])
//        {
//            ans[k] = nums[i] * nums[i];
//            --k;
//            ++i;
//        }
//        else {
//            ans[k] = nums[j] * nums[j];
//            --k;
//            --j;
//        }
//    }
//    return ans;
//}
//
//vector<vector<int>> generateMatrix(int n) {
//    vector<vector<int>>ans(n, vector<int>(n, 0));
//    int startIndex = 0, startIndey = 0;
//    int offset = 1;
//    int i = 0, j = 0;
//    int num = 1;
//    int loop = n;
//    while (loop /= 2)
//    {
//        for (j = startIndex; j < n - offset; ++j) {
//            ans[i][j] = num++;
//        }
//
//        for (i = startIndey; i < n - offset; ++i) {
//            ans[i][j] = num++;
//        }
//
//        for (; j > startIndex; --j) {
//            ans[i][j] = num++;
//        }
//
//        for (; i > startIndey; --i) {
//            ans[i][j] = num++;
//        }
//
//        ++startIndex;
//        ++startIndey;
//        ++offset;
//    }
//    if (n % 2)
//        ans[n / 2][n / 2] = num;
//    return ans;
//}
//vector<int> twoSum(vector<int>& numbers, int target) {
//    int a = 0, b = numbers.size() - 1;
//    vector<int>ans;
//    while (a < b) {
//        if (numbers[a] + numbers[b] == target) {
//            ans.push_back(a + 1);
//            ans.push_back(b + 1);
//        }
//        if (a + b < target)
//            ++a;
//        else
//            --b;
//    }
//    return ans;
//}
//
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    ListNode* dummy = new ListNode(0, head);
//    ListNode* low = dummy;
//    ListNode* quick = dummy;
//    int len = n;
//    while (quick->next != nullptr && len > 0) {
//        quick = quick->next;
//        --len;
//    }
//    if (len > 0)return head;
//    else if (quick->next == nullptr) {
//        dummy->next = dummy->next->next;
//        return dummy;
//    }
//    else {
//        while (quick->next != nullptr) {
//            low = low->next;
//            quick = quick->next;
//        }
//        low->next = low->next->next;
//    }
//    return head;
//}
//vector<int> resultsArray(vector<int>& nums, int k) {
//    int n = nums.size() - k;
//    if (k == 1)return nums;
//    if (n == 0)return{ nums[nums.size() - 1] };
//    vector<int>results(n + 1, -1);
//    int u = 0;
//    int count = 1;
//    for (int i = 1; i < nums.size(); ++i) {
//        if (nums[i] == nums[i - 1] + 1)
//            ++count;
//        else
//        {
//            count = 1;
//            ++u;
//        }
//        if (count >= k)
//            results[u++] = nums[i];
//    }
//    return results;
//}
//int getmaxvalue(unordered_map<int, int>& map) {
//    int maxv = INT_MIN;
//    for (auto& a : map)
//        maxv = max(maxv, a.second);
//    return maxv;
//}
//
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    queue<int>three;
//    vector<int>ans;
//    unordered_map<int, int>map;
//    int len = 0;
//    int test = 0;
//
//    for (int i = 0; i < nums.size(); ++i) {
//        if (three.size() < k) {
//            map[len++] = nums[i];
//            three.push(nums[i]);
//            if (len == k) {
//                len = 0;
//                int maxv = getmaxvalue(map);
//                ans.push_back(maxv);
//            }
//            continue;
//        }
//        map[test++] = nums[i];
//        if (test == k)
//            test = 0;
//        int maxv = getmaxvalue(map);
//        ans.push_back(maxv);
//    }
//    return ans;
//}
//
//class compare {
//public:
//    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
//        return a.second > b.second;
//    }
//};
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int, int>map;
//    for (auto& a : nums)
//        map[a]++;
//
//    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>minheap;
//    for (auto& pair : map) {
//        minheap.emplace(pair);
//        if (minheap.size() > k)
//            minheap.pop();
//    }
//
//    vector<int>ans;
//    while (!minheap.empty()) {
//        ans.emplace_back(minheap.top().first);
//        minheap.pop();
//    }
//    return ans;
//}
//int dfs(TreeNode* node, int& depth) {
//    if (!node->left && !node->right)
//        return depth;
//    if (node->left || node->right)
//        ++depth;
//    if (node->left)dfs(node->left, depth);
//    if (node->right)dfs(node->right, depth);
//    return depth;
//}
//int minDepth(TreeNode* root) {
//    if (!root)return 0;
//    int a = 0;
//    int ans = dfs(root, a);
//    return ans + 1;
//}
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
// int findBottomLeftValue(TreeNode* root) {
//if (!root)return 0;
//int ans = root->val;
//queue<TreeNode*>que;
//que.emplace(root);
//while (!que.empty()) {
//	int size = que.size();
//	TreeNode* node = que.front();
//	que.pop();
//	for (int i = 0; i < size; ++i) {
//		TreeNode* t = node->left;
//		if (t && !t->left && t->right) {
//			ans = node->left->val;
//			continue;
//		}
//		if (node->left) que.emplace(node->left);
//		if (node->right) que.emplace(node->right);
//	}
//}
//return ans;
//	}
//
//	bool sumval(TreeNode* node, int targetSum, int sum) {
//		if (!node)return false;
//		if (node && !node->left && !node->right) {
//			if (sum + node->val == targetSum)return true;
//			else return false;
//		}
//		bool leftsum = sumval(node->left, targetSum, sum + node->val);
//		bool rightsum = sumval(node->right, targetSum, sum + node->val);
//		if (leftsum || rightsum)
//			return true;
//		else
//			return false;
//	}
//	bool hasPathSum(TreeNode* root, int targetSum) {
//		bool ans = sumval(root, targetSum, 0);
//		return ans;
//	}
//
//	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//		//if(img.empty())return{};
//		int m = img.size(), n = img[0].size();
//		vector<vector<int>>ans(m, vector<int>(n));
//		for (int i = 0; i < m; ++i) {
//			for (int j = 0; j < n; ++j) {
//				int num = 0, sum = 0;
//				for (int x = i - 1; x <= i + 1; ++x) {
//					for (int y = j - 1; y <= j + 1; ++y) {
//						if (x >= 0 && x < m && y >= 0 && y < n) {
//							++num;
//							sum += img[x][y];
//							//cout << "sum:" << sum << " " << "x:" << x << " " << "y:" << y << " ";
//						}
//						//cout << "sum:" << sum << "\n";
//					}
//				}
//				ans[i][j] = sum / num;
//				cout << ans[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		return ans;
//	}
//
//	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//		int n = nums.size();
//		vector<int>stk;
//		vector<int>left(n, -1), right(n, -1);
//		vector<TreeNode*>tree(n);
//		for (int i = 0; i < n; ++i) {
//			tree[i] = new TreeNode(nums[i]);
//			while (!stk.empty() && nums[i] > nums[stk.back()]) {
//				right[stk.back()] = i;
//				stk.pop_back();
//			}
//			if (!stk.empty()) {
//				left[i] = stk.back();
//			}
//			stk.push_back(i);
//		}
//
//		for (auto& a : left)
//			cout << a << " ";
//		cout << endl;
//		for (auto& a : right)
//			cout << a << " ";
//		cout << endl;
//		for (auto& a : tree)
//			cout << a->val << " ";
//
//		TreeNode* root = nullptr;
//		for (int i = 0; i < n; ++i) {
//			if (left[i] == -1 && right[i] == -1) {
//				root = tree[i];
//			}
//			else if (right[i] == -1 || (left[i] != -1 && nums[left[i]] < nums[right[i]])) {
//				tree[left[i]]->right = tree[i];
//			}
//			else {
//				tree[right[i]]->left = tree[i];
//			}
//		}
//		return root;
//	}
//	int bfs(int n, vector<vector<int>>& neighbors) {
//		vector<int>dist(n, -1);
//		queue<int>q;
//		q.emplace(0);
//		dist[0] = 0;
//		while (!q.empty()) {
//			int x = q.front();
//			q.pop();
//			for (int y : neighbors[x]) {
//				if (dist[y] >= 0)
//					continue;
//				q.emplace(y);
//				dist[y] = dist[x] + 1;
//			}
//		}
//		return dist[n - 1];
//	}
//
//	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//		vector<vector<int>>neighbors(n);
//		for (int i = 0; i < n - 1; ++i) {
//			neighbors[i].emplace_back(i + 1);
//		}
//		vector<int>ans;
//		for (auto& query : queries) {
//			neighbors[query[0]].emplace_back(query[1]);
//			ans.emplace_back(bfs(n, neighbors));
//		}
//		return ans;
//	}
//
//	TreeNode* pre = nullptr;
//	void dfs(TreeNode* node, int& ans) {
//		if (!node)return;
//		dfs(node->left, ans);
//		if (pre)
//			ans = min(ans, abs(node->val - pre->val));
//		pre = node;
//		dfs(node->right, ans);
//	}
//	int getMinimumDifference(TreeNode* root) {
//		int ans = INT_MAX;
//		dfs(root, ans);
//		return ans;
//	}
//
//	vector<vector<string>> ret;
//	vector<string> ans;
//	int n;
//	void backtracking(string& s, int i, vector<vector<bool>>& dp) {
//		if (i == n) {
//			ret.push_back(ans);
//			return;
//		}
//		for (int j = i; j < n; ++j) {
//			if (dp[i][j]) {
//				ans.push_back(s.substr(i, j - i + 1));
//				backtracking(s, j + 1, dp);
//				ans.pop_back();
//			}
//		}
//	}
//
//	vector<vector<string>> partition(string s) {
//		n = s.size();
//		vector<vector<bool>>dp(n, vector<bool>(n, false));
//		for (int i = 0; i < n; ++i)
//			dp[i][i] = true;
//		for (int i = 0; i < n - 1; ++i) {
//			if (s[i] == s[i + 1])
//				dp[i][i + 1] = true;
//		}
//		for (int len = 3; len <= n; ++len) {
//			for (int i = 0; i <= n - len; ++i) {
//				int j = i + len - 1;
//				if (s[i] == s[j] && dp[i + 1][j - 1])
//					dp[i][j] = true;
//			}
//		}
//		backtracking(s, 0, dp);
//		return ret;
//	}
//};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode* makePreTree(vector<int>& nums, int& index) {
		if (index >= nums.size() || nums[index] == -1) {
			++index;
			return nullptr;
		}
		TreeNode* node = new TreeNode(nums[index++]);
		node->left = makePreTree(nums, index);
		node->right = makePreTree(nums, index);
		return node;
	}

	TreeNode* makeTree(vector<int>& nums) {
		if (nums.empty())return nullptr;

		TreeNode* root = new TreeNode(nums[0]);
		queue<TreeNode*>q;
		q.emplace(root);
		int i = 1;
		while (i<nums.size()) {
			TreeNode* curnode = q.front();
			q.pop();

			if (i < nums.size() && nums[i] != -1) {
				curnode->left = new TreeNode(nums[i++]);
				q.emplace(curnode->left);
			}
			if (i < nums.size() && nums[i] != -1) {
				curnode->right = new TreeNode(nums[i++]);
				q.emplace(curnode->right);
			}
		}
		return root;
	}
	

	vector<vector<int>>ans;
	vector<int>path;
	void backtracking(vector<int>& nums, int index) {
		//if(index==nums.size())return;
		if (path.size() > 1) {
			ans.emplace_back(path);
		}
		for (int i = index; i < nums.size(); ++i) {
			if (path.size() > 0 && path[path.size() - 1] > nums[i])
				continue;
			if (i > index && nums[i - 1] == nums[i])
				continue;
			path.emplace_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		backtracking(nums, 0);
		for (auto& item : ans) {
			for (auto& a : item)
				std::cout << a << ' ';
			std::cout<<std::endl;
		}
		return ans;
	}

	int countOfPairs(vector<int>& nums) {
		const int MOD = 1'000'000'007;
		int n = nums.size();
		int m = ranges::max(nums);
		vector f(n, vector<long long>(m + 1));
		vector<long long>s(m + 1);
		fill(f[0].begin(), f[0].begin() + nums[0] + 1, 1);
		for (int i = 1; i < n; ++i) {
			partial_sum(f[i - 1].begin(), f[i - 1].end(), s.begin());//f[i-1]的前缀和
			for (int j = 0; j <= nums[i]; ++j) {
				int max_k = j + min(nums[i - 1] - nums[i], 0);
				f[i][j] = max_k >= 0 ? s[max_k] % MOD : 0;
			}
		}
		return reduce(f[n - 1].begin(), f[n - 1].begin() + nums[n - 1] + 1, 0LL) % MOD;
	}

	int largestSumAfterKNegations(vector<int>& nums, int k) {
		ranges::sort(nums);
		int m = INT_MAX;
		for (int i = 0; i < nums.size(); ++i) {
			if (k == 0)break;
			if (nums[i] < 0) {
				nums[i] = -nums[i];
				--k;
			}
			m = min(m, nums[i]);
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (!(k ^ 1)) {
			sum -= 2 * m;
		}
		return sum;
	}
	//vector<string> letterCombinations(string digits) {//回溯
 //       unordered_map<char, string>map;
 //       string x = "abc";
 //       for (int i = 2; i <= 6; ++i) {
 //           map.insert({i+'0', x});
 //           for (int j = 0; j < 3; ++j) {
 //               x[j] += 3;
 //           }
 //       }
 //       map.insert({ '7',"pqrs" });
 //       map.insert({ '8',"tuv" });
 //       map.insert({ '9',"wxyz" });
 //
 //       vector<string>ans{ "" };
 //       ans.reserve(150);
 //       if (digits.empty())
 //           return{};
 //       string tmp;

 //       for (auto& a : digits) {
 //           int n = ans.size();
 //           for (int i = 0; i < n; ++i) {
 //               tmp = ans[0];
 //               ans.erase(ans.begin());
 //               for (auto& j : map[a]) {
 //                   ans.push_back(tmp + j);
 //               }
 //           }
 //       }
 //       return ans;
	//}
};




class A
{
public:
	void foo() {
		std::cout << "hello" << std::endl; // 访问已经被销毁的指针
	}
};

class animal {
public:
    virtual void say() {
        std::cout << "animal" << std::endl;
    }
    string tetet="animal";
};

class dog :public animal {
public:
    virtual void say() {
        std::cout << "dog" << std::endl;
    }
    string tetet="dog";
};

class cat :public animal {
public:
	virtual void say() {
		std::cout << "cat" << std::endl;
	}
};

void ssay(animal* x) {
    x->say();
}

void printhello(/*shared_ptr<int>*/ int*a) {
	std::cout << *a << std::endl;
}

void modifyPointer(int*& ptr) {
	ptr = new int(100); // 修改指针的地址 
}

int ttttt = 0;
std::timed_mutex mtx;
void func() {
	for (int i = 0; i < 2; ++i) {
		std::unique_lock<std::timed_mutex>lg(mtx, std::defer_lock);
		if (lg.try_lock_for(std::chrono::seconds(2))) {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			ttttt += 1;
		}
		
	}
}

//void print_erro() {
//	Log::getInstance().showMessage("erro");
//}

std::queue<int>q_queue;
std::condition_variable q_cv;
std::mutex Mtx;
void producer() {
	for (int i = 0; i < 10; ++i) {
		std::unique_lock<std::mutex>lock(Mtx);
		q_queue.emplace(i);
		std::this_thread::sleep_for(std::chrono::microseconds(2000000));
		q_cv.notify_all();
		//通知消费者取任务
		std::cout << "producer:" << i << std::endl;
	}
}

void consumer() {
	while (true) {
		std::unique_lock<std::mutex>lock(Mtx);

		bool isempty = q_queue.empty();
		q_cv.wait(lock,[](){return !q_queue.empty(); });
		//如果队列为空，进行等待
		int value = q_queue.front();
		q_queue.pop();
		lock.unlock();
		std::cout << "customer1:" << value << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}
void consumer1() {
	while (true) {
		std::unique_lock<std::mutex>lock(Mtx);

		bool isempty = q_queue.empty();
		q_cv.wait(lock, []() {return !q_queue.empty(); });
		//如果队列为空，进行等待
		int value = q_queue.front();
		q_queue.pop();
		std::cout << "customer2:" << value << std::endl;
		lock.unlock();
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

#include <numeric> // 包含 accumulate 函数

int main() {
	ListNode* l1 = new ListNode(6, nullptr);
	ListNode* le = new ListNode(5, l1);
	ListNode* ld = new ListNode(4, le);
	ListNode* lc = new ListNode(3, ld);
	ListNode* la = new ListNode(2, lc);
	ListNode* lb = new ListNode(1, la);

	ListNode* l2 = new ListNode(5, nullptr);
	ListNode* lx = new ListNode(3, l2);
	ListNode* ly = new ListNode(2, lx);

	Solution x;
    vector<int>nums1 = { 1,3,2,6,7,9 };
	vector<vector<string>>paths = { {"B", "C"} ,{"D", "B"},{"C", "A"} };
    
	unordered_map<int, vector<int>>map;
	map[0] = { 1,2 };

    vector<int>uu{ 1, 7, 4, 9, 2, 5 };
    vector<int>tt(6, 0);
    vector<vector<int>>grid({{ 2,4 }, { 0,2 }, { 0,4 }});
    

	x.largestSumAfterKNegations(nums1,3);
	std::accumulate(nums1.begin(),nums1.end(), 0);
	
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
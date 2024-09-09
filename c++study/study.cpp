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

class maxheap
{
private:
    vector<int>heap;
    void shiftup(int index)
    {
        while (index > 0 && heap[index] < heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void shiftdown(int index)
    {
        int leftchild, rightchild, large;
        while (index * 2 + 1 < heap.size())
        {
            leftchild = index * 2 + 1;
            rightchild = index * 2 + 2;
            large = index;
            if (leftchild < heap.size() && heap[leftchild] < heap[large])
                large = leftchild;
            if (rightchild < heap.size() && heap[rightchild] < heap[large])
                large = rightchild;
            if (large != index)
            {
                swap(heap[large], heap[index]);
                //large = index;
                index = large;//˳�����Ҫ����Ҫ�����³����ڵ�
            }
            else
                break;
        }
    }
public:
    maxheap() = default;
    maxheap(const vector<int>&x) :heap(x) {}
    void insert(int value)
    {
        heap.push_back(value);
        shiftup(heap.size()-1);
    }

    void delete_heap(int index)
    {
        if (heap.size() == 0)return;
        swap(heap[index], heap[heap.size() - 1]);
        heap.pop_back();
        shiftdown(index);
    }
    void sort_heap()
    {
        //heap = num;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            shiftdown(i);
    }
    void print_heap()
    {
        for (auto a : heap)
            cout << a << " ";
        cout << endl;
    }
};


int main()
{   
    //maxheap maxHeap;
    /*maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(35);
    maxHeap.insert(80);*/
    //maxHeap.delete_heap(1);
    vector<int> nums = { 10, 20, 5, 30, 15 };
    maxheap maxHeap(nums);
    maxHeap.sort_heap();
    maxHeap.print_heap(); 

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
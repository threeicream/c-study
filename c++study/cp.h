#ifndef CP_H
#define CP_H

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
//������
#include<stack>
#include<queue>
//�㷨
#include<algorithm>
#include<numeric>
#include<functional>
#include<cmath>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
#include"person.h"

using namespace std;//һ���Ͱ�����usingȫ��Ч��

class Point; // ǰ������

class Circle
{
public:
	Circle() = default;
	Circle(const double& x, const double& y, const double& r) : circle_point_x(x), circle_point_y(y), Reter(r) {}
	//Circle(const Circle& p) { circle_point_x = p.circle_point_x; }//�������캯��
	friend ostream& operator<<(ostream& os, const Circle& a);
	friend void compare_cp(const Circle& x, const Point& y);
private:
	double circle_point_x;
	double circle_point_y;
	double Reter;
};

class Point
{
public:
	Point() = default;
	Point(const double& x, const double& y) :point_x(x), point_y(y) {}
	friend ostream& operator<<(ostream& os, const Point& a);
	friend void compare_cp(const Circle& x, const Point& y);
private:
	double point_x;
	double point_y;
};

#endif

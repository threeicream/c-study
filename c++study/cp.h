#ifndef CP_H
#define CP_H

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
//适配器
#include<stack>
#include<queue>
//算法
#include<algorithm>
#include<numeric>
#include<functional>
#include<cmath>

#include<cstring>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//预处理宏  assert(x);x为假，输出信息并终止程序运行
#include"person.h"

using namespace std;//一个就把上面using全等效了

class Point; // 前向声明

class Circle
{
public:
	Circle() = default;
	Circle(const double& x, const double& y, const double& r) : circle_point_x(x), circle_point_y(y), Reter(r) {}
	//Circle(const Circle& p) { circle_point_x = p.circle_point_x; }//拷贝构造函数
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

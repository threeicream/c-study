#include"cp.h"

ostream& operator<<(ostream& os, const Circle& a)
{
	os << a.circle_point_x << " " << a.circle_point_y << " " << a.Reter << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point& a)
{
	os << a.point_x << " " << a.point_y << endl;
	return os;
}

void compare_cp(const Circle& x, const Point& y)
{
	double a = x.circle_point_x-y.point_x;
	double b = x.circle_point_y - y.point_y;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	double r = sqrt(a * a + b * b);
	if (r > x.Reter)
		cout << "点在圆的外面" << endl;
	else if (r < x.Reter)
		cout << "点在圆的内部" << endl;
	else
		cout << "点在圆上" << endl;
}

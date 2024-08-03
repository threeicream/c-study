#include <iostream>
#ifndef SALES_H
#define SALES_H
#include<string>
struct sales_data {
	std::string bookno;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif
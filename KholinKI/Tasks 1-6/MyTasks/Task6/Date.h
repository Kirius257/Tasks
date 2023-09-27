#ifndef _DATE_H
#define _DATE_H

using namespace std;
#include "framework.h"
#include <string>
#include <time.h>


struct Date {//date of birth
	int day;
	int month;
	int year;

	Date();
	Date(int day, int month, int year);
	Date(const Date& obj);
	const Date& operator=(const Date& obj);
	friend ostream& operator<<(ostream& stream, const Date& obj);
};

#endif
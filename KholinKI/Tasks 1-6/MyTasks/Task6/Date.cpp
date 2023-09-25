#include "Date.h"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}


Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}

Date& Date::operator=(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
	return *this;
}
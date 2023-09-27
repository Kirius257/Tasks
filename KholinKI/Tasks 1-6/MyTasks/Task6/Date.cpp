#include "Date.h"
#include <string>
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

const Date& Date::operator=(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
	return *this;
}

ostream& operator<<(ostream& stream, const Date& obj) {
	string s_day = to_string(obj.day);
	string s_month = to_string(obj.month);
	string s_year = to_string(obj.year);
	if (obj.day > 0 && obj.day < 10) {
		s_day = "0" + s_day;;
	}
	if (obj.month > 0 && obj.month < 10) {
		s_month = "0" + s_month;
	}
	stream << s_day << "." << s_month << "." << s_year;
	return stream;
}
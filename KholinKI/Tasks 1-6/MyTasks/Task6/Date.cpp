#include "Date.h"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}
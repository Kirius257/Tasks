#ifndef _DATE_H
#define _DATE_H

struct Date {
	int day;
	int month;
	int year;

	Date();
	Date(const Date& obj);
	//friend ostream operator<<(ostream& stream, const Date& obj);
};

#endif
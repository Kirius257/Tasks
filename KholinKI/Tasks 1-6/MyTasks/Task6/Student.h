#ifndef _STUDENT_H
#define _STUDENT_h

#include "Date.h"
#include <string>
using namespace std;
enum signs { surname_ = 1, name_ = 2, patronymic_ = 3, phone_number_ = 4 };
struct Student {
	string surname;
	string name;
	эспекто_патронум patronymic;
	long long num_phone;
	Date* date;

	Student();
	Student(const string& surname, const string& name, const string& patronymic,
			long long num_phone, int day, int month, int year);//create object Student
	Student(const Student& obj);
	~Student();

	Student& operator=(const Student& obj);
	bool operator==(const Student& obj)const;

	friend ostream& operator<<(ostream& stream, const Student& obj);
};

#endif
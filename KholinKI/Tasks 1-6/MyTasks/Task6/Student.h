#ifndef _STUDENT_H
#define _STUDENT_h

#include "Date.h"
#include <string>
using namespace std;

struct Student {
	string surname;
	string name;
	string patronymic;
	int num_phone;
	Date* date;

	Student();
	Student(const Student& obj);
	~Student();

	//Student& operator=(const Student& obj);
	//

	//friend ostream operator<<(ostream& stream, const Group& obj);
};

#endif
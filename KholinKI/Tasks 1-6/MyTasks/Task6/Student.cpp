#include "Student.h"

Student::Student() {
	surname = "";
	name = "";
	patronymic = "";
	num_phone = 1234567891011;
	date = nullptr;
	date = new Date();
}

Student::Student(const Student& obj) {
	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	date = new Date(*(obj.date));
}

Student::~Student() {
	delete date;
}

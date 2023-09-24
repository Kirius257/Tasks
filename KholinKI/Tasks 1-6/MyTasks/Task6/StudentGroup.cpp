#include "StudentGroup.h"
#include <iostream>
using namespace std;

Group::Group() {
	data = nullptr;
	num_students = 0;
}

Group::Group(int num_students_) {
	data = new Student*[num_students_];
	num_students = num_students_;
	int num_dates = num_students;
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student();
	}
}

Group::Group(const Group& obj) {
	num_students = obj.num_students;
	data = new Student * [num_students];
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student(*(obj.data[i]));
	}
}

Group::~Group() {
	for (int i = 0; i < num_students; i++) {
		delete data[i];
	}
	delete[] data;
	num_students = 0;
}

void Group::set_data(int index, const string& surname, const string& name, const string& patronymic,
							const string& num_phone, int day, int month, int year)
{
	data[index]->surname = surname;
	data[index]->name = name;
	data[index]->patronymic = patronymic;
	data[index]->num_phone = stoi(num_phone);
	data[index]->date->day;
	data[index]->date->month;
	data[index]->date->year;
}
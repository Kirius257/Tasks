#include "StudentGroup.h"
#include <iostream>
using namespace std;


Group::Group(int num_students_,int step) {//
	this->step = step;
	current_num = 0;
	num_students = num_students_;
	data = new Student*[num_students_];
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student();
	}
}

Group::Group(const Group& obj) {
	num_students = obj.num_students;
	step = obj.step;
	data = new Student * [num_students];
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student(*(obj.data[i]));
	}
	current_num = obj.current_num;
}

Group::~Group() {
	for (int i = 0; i < num_students; i++) {
		delete data[i];
	}
	delete[] data;
	num_students = 0;
	step = 0;
}

int Group::end() {
	return current_num;
}


void Group::realloc() {
	num_students += step;
	Student** tmp = new Student*[num_students];
	int i = 0;
	for (i = 0; i < current_num; i++) {
		tmp[i] = new Student(*(data[i]));
	}
	for (i = current_num; i < num_students; i++) {
		tmp[i] = new Student();
	}
	data = tmp;
}

void Group::add_entry(const Student& person) {
	if (current_num == num_students) {
		realloc();
	}
	int index = end();
	*(data[index]) = person;
	current_num++;
}

Group& Group::operator=(const Group& obj) {
	num_students = obj.num_students;
	current_num = obj.current_num;
	step = obj.step;
	for (int i = 0; i < num_students; i++) {
		*(data[i]) = *(obj.data[i]);
	}
	return *this;
}
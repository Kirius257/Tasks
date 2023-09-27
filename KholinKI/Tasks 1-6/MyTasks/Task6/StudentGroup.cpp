#include "StudentGroup.h"
#include <iostream>
using namespace std;




Group::Group(int num_students_,int step) {//
	this->step = step;
	current_num = 0;
	number = 0;
	num_students = num_students_;
	data = new Student*[num_students_];
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student();
	}
}

Group::Group(const Group& obj) {
	num_students = obj.num_students;
	step = obj.step;
	number = obj.number;
	data = new Student * [num_students];
	for (int i = 0; i < num_students; i++) {
		data[i] = new Student(*(obj.data[i]));
	}
	current_num = obj.current_num;
}

Group::~Group() {
	for (int i = 0; i < num_students; i++) {
		if (data[i-1] == data[i]) {
			continue;
		}
		delete data[i];
	}
	delete[] data;
	data = nullptr;
	num_students = 0;
	step = 0;
	number = 0;
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

void Group::enrol_student(const Student& person) {
	int test = find(person);
	if (test < 0) {
		if (current_num == num_students) {
			realloc();
		}
		int index = end();
		*(data[index]) = person;
		current_num++;
	}
	else { cout << "such a student already is located in group!" << test << endl; }
}

void Group::expel_student(int index) {
	if (index < 0 || index >= current_num) {
		throw Exeptions<int>(NotExistIndex, index);
	}
	for (int i = index; i < current_num; i++) {
		data[i] = data[i + 1];
	}
	current_num--;
}

int* Group::find_student_surname(const Student& sign)const {
	int count = 0;
	for (int i = 0; i < current_num; i++) {
		if (data[i]->surname == sign.surname) {
			count++;
		}
	}
	
	if (count == 0) {
		int* indices = new int[count+1];
		indices[0] = -1;
		return indices;
	}
	else {
		int* indices = new int[count];
		int j = 0;
		for (int i = 0; i < current_num; i++) {
			if (data[i]->surname == sign.surname) {
				indices[j] = i;
				j++;
			}
		}
		return indices;
	}
}

int* Group::find_student_name(const Student& sign)const {
	int count = 0;
	for (int i = 0; i < current_num; i++) {
		if (data[i]->name == sign.name) {
			count++;
		}
	}
	
	if (count == 0) {
		int* indices = new int[count+1];
		indices[0] = -1;
		return indices;
	}
	else {
		int* indices = new int[count];
		int j = 0;
		for (int i = 0; i < current_num; i++) {
			if (data[i]->name == sign.name) {
				indices[j] = i;
				j++;
			}
		}
		return indices;
	}
}

int* Group::find_student_patronymic(const Student& sign)const {
	int count = 0;
	for (int i = 0; i < current_num; i++) {
		if (data[i]->patronymic == sign.patronymic) {
			count++;
		}
	}
	
	if (count == 0) {
		int* indices = new int[count+1];
		indices[0] = -1;
		return indices;
	}
	else {
		int* indices = new int[count];
		int j = 0;
		for (int i = 0; i < current_num; i++) {
			if (data[i]->patronymic == sign.patronymic) {
				indices[j] = i;
				j++;
			}
		}
		return indices;
	}
}

int Group::find_student_number(const Student& sign)const {
	for (int index = 0; index < current_num; index++) {
		if (data[index]->num_phone == sign.num_phone) {
			return index;
		}
	}
	return -1;
}

int Group::find(const Student& obj)const {
	for (int index = 0; index < current_num; index++) {
			if (*(data[index]) == obj) {
				return index;
			}
	}
	return -1;
}

void Group::show(int index) {
	cout << *data[index];
}

void Group::expel_student(const Student& person) {
	int index = find(person);
	if (index >= 0 && index < current_num) {
		for (int i = index; i < current_num; i++) {
			data[i] = data[i + 1];
		}
		current_num--;
	}
	else {
		throw Exeptions<int>(NotExistIndex, index);
	}
}


const Group& Group::operator=(const Group& obj) {
	num_students = obj.num_students;
	current_num = obj.current_num;
	step = obj.step;
	for (int i = 0; i < num_students; i++) {
		*(data[i]) = *(obj.data[i]);
	}
	return *this;
}

Student& Group::operator[](int index){
	return *(data[index]);
}

ostream& operator<<(ostream& stream, const Group& obj) {
	cout << "		  STUDENT GROUP " << endl;
	for (int i = 0; i < obj.current_num; i++) {
		stream << *(obj.data[i]);
	}
	cout << endl << endl << endl;
	return stream;
}

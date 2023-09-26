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
		if (data[i-1] == data[i]) {
			continue;
		}
		delete data[i];
	}
	delete[] data;
	data = nullptr;
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

int Group::find(const Student& obj)const {
	for (int index = 0; index < current_num; index++) {
			if (*(data[index]) == obj) {
				return index;
			}
	}
	return -1;
}

void Group::search_to_output(const string& param,signs sign)const {
	switch (sign) {
	case surname_:
	{
		for (int i = 0; i < current_num; i++) {
		if (data[i]->surname == param) {
			cout << *data[i];
			}
		}
		break;
	}
	case name_:
	{
		for (int i = 0; i < current_num; i++) {
			if (data[i]->name == param) {
				cout << *data[i];
			}
		}
		break;
	}
	case patronymic_:
	{
		for (int i = 0; i < current_num; i++) {
			if (data[i]->patronymic == param) {
				cout << *data[i];
			}
		}
		break;
	}
	case phone_number_:
	{
		for (int i = 0; i < current_num; i++) {
			if (data[i]->num_phone == param) {
				cout << *data[i];
			}
		}
		break;
	}
	default: cout << "Student with parametr " << param << " in other group or not exist!" << endl; 
	}
}

int Group::find_student()const {
	cout << "Choose sign: " << endl;
	cout << "1. Search on surname" << endl;
	cout << "2. Search on name" << endl;
	cout << "3. Search on patronymic" << endl;
	cout << "4. Search on phone number" << endl;


	int choice;
	cin >> choice;

	switch (choice) {
	case surname_:
	{cout << "Enter surname student: " << endl;
	string param; cin >> param;
	search_to_output(param,surname_); break; }

	case name_:
	{cout << "Enter name student: " << endl;
	string param; cin >> param;
	search_to_output(param,name_); break; }

	case patronymic_:
	{cout << "Enter patronymic student: " << endl;
	string param; cin >> param;
	search_to_output(param,patronymic_); break; }

	case phone_number_:
	{cout << "Enter phone number student: " << endl;
	string param; cin >> param;
	search_to_output(param,phone_number_); break; }
	default: throw Exeptions<int>(CaseNotFound, choice); 
	}
	
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


Group& Group::operator=(const Group& obj) {
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

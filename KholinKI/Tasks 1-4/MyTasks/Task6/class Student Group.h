#ifndef _CLASS_STUDENT_GROUP_H
#define _CLASS_STUDENT_GROUP_H

#include <iostream>
using namespace std;

class ListGroups {
private:
	Group** list;
	int count_groups;
public:
	//конструкторы и деструктор
};

class Group {
private:
	Students data;
	int num_students;
public:
	//конструкторы
	void add_entry(const string& new_entry);
	void find();
	void delete_entry() 
};


struct Students {
	//конструкторы
	string surname;
	string name;
	string patronymic;
	string gender;
	string nation;
	string height;
	string weight;
	string num_phone;
	string postal_code;
	Date date;
};

struct Date {
	int day;
	int month;
	int year;
};


#endif
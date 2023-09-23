#ifndef _CLASS_STUDENT_GROUP_H
#define _CLASS_STUDENT_GROUP_H

#include <iostream>
#include <string>
using namespace std;

class ListGroups {
private:
	Group** list;
	int count_groups;
	void realloc();
public:
	ListGroups(const string& path);
	~ListGroups();

	
	void add_entry(const Student& person);
	void delete_entry(int index);

	ListGroups& operator=(const ListGroups& obj);
};

class Group {
private:
	Student* data;
	int num_students;
public:
	Group(int num_students_);
	~Group();

	int find_student();//swtich
	void set_data(const string& surname, const string& name, const string& patronymic,
				  const string& num_phone,int day,int month,int year);

	Student& operator[](int index);
	Student& operator=(const Student& obj);

	
};


struct Student {
	string surname;
	string name;
	string patronymic;
	string num_phone;
	Date* date;
	int num_dates;

	Student(int num_dates_);
	Student(const Student& obj);


	Student& operator=(const Student& obj);
	~Student();

	friend ostream operator<<(ostream& stream, const Group& obj);
};

struct Date {
	int day;
	int month;
	int year;

	Date(int day, int month, int year);

	friend ostream operator<<(ostream& stream, const Date& obj);
};


#endif
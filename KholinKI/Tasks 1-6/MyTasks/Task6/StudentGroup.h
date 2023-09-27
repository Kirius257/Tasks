#ifndef _STUDENTGROUP_H
#define _STUDENTGROUP_H



#include "Student.h"


class Group {
private:
	Student** data;//information about students group
	int num_students;//max size data
	int step;//new place for new students
	int number;//number group
	void realloc();//change size data
public:
	//#create list
	Group(int num_students_ = 25,int step = 10);//standard count students in group
	Group(const Group& obj);//copy group
	~Group();

	//#auxiliary methonds
	int end();//get index end of list group
	void set_number(int number) { this->number = number; };
	
	//#major instruments
	void enrol_student(const Student& person);//add student in group
	void expel_student(int index);//expel a student
	void expel_student(const Student& person);//expel on student

	//#search
	int* find_student_surname(const Student& sign)const;//find student on surname

	int* find_student_name(const Student& sign)const;//find student on name

	int* find_student_patronymic(const Student& sign)const;//find student on patronymic

	int find_student_number(const Student& sign)const;//find student on number

	int find(const Student& obj)const;//get number student in group

	//#get data about students
	int get_num_students()const {return num_students;}
	int get_current_num()const  {return current_num; }
	int get_number()const { return number; }
	
	//#overload operators
	const Group& operator=(const Group& obj);
	Student& operator[](int index);
	
	//#output
	void show(int index);//output on index
	friend ostream& operator<<(ostream& stream, const Group& obj);
protected:
	int current_num;//current size data
};
//
//

//



#endif
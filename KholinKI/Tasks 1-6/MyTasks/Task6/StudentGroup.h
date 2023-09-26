#ifndef _STUDENTGROUP_H
#define _STUDENTGROUP_H



#include "Student.h"


class Group {
private:
	Student** data;//information about students group
	int num_students;//max size data
	int step;//new place for newe students
	void realloc();//change size data
	void search_to_output(const string& param, signs sign)const;//search student and show info
public:
	//#create list
	Group(int num_students_ = 25,int step = 10);//standard count students in group
	Group(const Group& obj);//copy group
	~Group();

	//#auxiliary methonds
	int end();//get index end of list group
	int find(const Student& obj)const;//get number student in group
	
	//#major instruments
	void enrol_student(const Student& person);//add student in group
	void expel_student(int index);//expel a student
	void expel_student(const Student& person);//expel on student
	int find_student()const;//find student on characteristic

	//#get data about students
	int get_num_students()const {return num_students;}
	
	
	//#overload operators
	Group& operator=(const Group& obj);
	Student& operator[](int index);
protected:
	int current_num;//current size data
};
//
//

//



#endif
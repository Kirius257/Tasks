#ifndef _STUDENTGROUP_H
#define _STUDENTGROUP_H



#include "Student.h"


class Group {
private:
	Student** data;//information about students group
	int num_students;//max size data
	int step;//new place for newe students
	void realloc();//change size data
public:
	Group(int num_students_ = 25,int step = 10);//standard count students in group
	Group(const Group& obj);//copy group
	~Group();

	//int find_student();//switch
	int end();//get index end of list group
	void add_entry(const Student& person);//add student in group
	//void delete_entry(int index);//expel a student
	int get_num_students() {return num_students;}
	//Student& operator[](int index);
	Group& operator=(const Group& obj);

protected:
	int current_num;//current size data
};
//
//

//



#endif
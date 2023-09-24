#ifndef _STUDENTGROUP_H
#define _STUDENTGROUP_H



#include "Student.h"


class Group {
private:
	Student** data;
	int num_students;
public:
	Group();
	Group(int num_students_);
	Group(const Group& obj);
	~Group();

	//int find_student();//switch
	void set_data(int index,const string& surname, const string& name, const string& patronymic,
				  const string& num_phone,int day,int month,int year);
	int get_num_students() {return num_students;}
	//Student& operator[](int index);
	//Group& operator=(const Student& obj);

	
};
//
//

//



#endif
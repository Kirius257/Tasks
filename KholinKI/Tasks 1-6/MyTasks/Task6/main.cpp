#include "ListGroup.h"

//#test 1
//Student st("Smith", "John", "Michael", 1234567890, 15, 9, 1995);


//# test 2
//Student me("Холин", "Кирилл", "Игоревич", 79202524290, 29, 4, 2004);


int main() {
	setlocale(LC_ALL, "rus");
	const string student_groups = "Students.txt";
	ListGroups faculty(student_groups);
	cout << faculty;
	return 0; 
}                                                                                                                                                                                                                  
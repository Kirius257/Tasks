#include "ListGroup.h"

ListGroups::ListGroups() {
	list = nullptr;
	count_groups = 0;
}

ListGroups::ListGroups(const string& path) {
	ifstream file(path);
	if (!file.is_open()) {
		throw Exeptions<int>(closed_file, 0);
	}

	int num_students;
	int residue_students;
	file >> count_groups >> num_students;//number of groups and number of students in the group
	num_students = num_students / count_groups;
	residue_students = num_students % count_groups;
	list = new Group*[count_groups];
	for (int i = 0; i < count_groups; i++) {
		list[i] = new Group();
	}
	for (int i = 0; i < count_groups; i++) {
		for (int j = 0; j < num_students; j++) {
			string sur, name, patr, phone;
			int day, month, year;
			file >> sur >> name >> patr >> phone >> day >> month >> year;
			Student new_student(sur, name, patr, phone, day, month, year);
			list[i]->add_entry(new_student);
		}
	}
	//учесть остаток студентов и добавить в любую группу
}
//
ListGroups::ListGroups(const ListGroups& obj) {
	count_groups = obj.count_groups;
	list = new Group * [count_groups];
	for (int i = 0; i < count_groups; i++) {
		list[i] = new Group(*(obj.list[i]));
	}
}

ListGroups::~ListGroups() {
	for (int i = 0; i < count_groups; i++) {
		delete list[i];
	}
	delete[] list;
	count_groups = 0;
}

ListGroups& ListGroups::operator=(const ListGroups& obj) {
	count_groups = obj.count_groups;
	for (int i = 0; i < count_groups; i++) {
		*(list[i]) = *(obj.list[i]);
	}
	return *this;
}



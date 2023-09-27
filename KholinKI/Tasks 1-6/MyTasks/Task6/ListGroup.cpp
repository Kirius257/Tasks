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
	int tmp_num_students;
	file >> count_groups >> num_students;//number of groups and number of students in the group
	residue_students = num_students % count_groups;//residue
	num_students = num_students / count_groups;//equal distribution
	tmp_num_students = num_students;//save old num students
	list = new Group*[count_groups];
	for (int i = 0; i < count_groups; i++) {
		list[i] = new Group();
		list[i]->set_number(i + 1);
	}
	for (int i = 0; i < count_groups; i++) {
		if (i == 0) {//default
			num_students += residue_students;
		}
		else {
			num_students = tmp_num_students;
		}
		for (int j = 0; j < num_students; j++) {
			string sur, name, patr;
			int day, month, year;
			long long phone;
			file >> sur >> name >> patr >> phone >> day >> month >> year;
			Student new_student(sur, name, patr, phone, day, month, year);
			list[i]->enrol_student(new_student);
		}
	}
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
		list[i] = nullptr;
	}
	delete[] list;
	list = nullptr;
	count_groups = 0;
}

ListGroups& ListGroups::operator=(const ListGroups& obj) {
	count_groups = obj.count_groups;
	for (int i = 0; i < count_groups; i++) {
		*(list[i]) = *(obj.list[i]);
	}
	return *this;
}

ostream& operator<<(ostream& stream, const ListGroups& obj) {
	for (int i = 0; i < obj.count_groups; i++) {
		cout << "			" << obj.list[i]->get_number();
		cout << endl;
		stream << *(obj.list[i]);
	}
	return stream;
}


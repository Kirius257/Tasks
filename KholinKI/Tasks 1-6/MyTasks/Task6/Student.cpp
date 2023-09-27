#include "Student.h"

Student::Student() {
	surname = "";
	name = "";
	patronymic = "";
	num_phone = 0;
	date = new Date();
}

Student::Student(const string& surname, const string& name, const string& patronymic,
					long long num_phone, int day, int month, int year) {
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->num_phone = num_phone;
	date = new Date(day, month, year);
}

Student::Student(const Student& obj) {
	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	num_phone = obj.num_phone;
	date = new Date(*(obj.date));
}

Student::~Student() {
	delete date;
	date = nullptr;
}


const Student& Student::operator=(const Student& obj) {
	surname = obj.surname;
	name = obj.name;
	patronymic = obj.patronymic;
	num_phone = obj.num_phone;
	*date = *(obj.date);
	return *this;
}

bool Student::operator==(const Student& obj)const {
	if (num_phone == obj.num_phone) {//numbers phones are different in the one country!
		return true;
	}
	else { return false; }
}

ostream& operator<<(ostream& stream, const Student& obj) {
	stream << obj.surname << " " << obj.name << " " << obj.patronymic << " " << obj.num_phone << " " << *(obj.date) << endl;
	return stream;
}

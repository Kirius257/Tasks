#include "ListGroup.h"

//#test 1
//Student st("Smith", "John", "Michael", 1234567890, 15, 9, 1995);


//# test 2
//Student me("Холин", "Кирилл", "Игоревич", 79202524290, 29, 4, 2004);


int main() {
	setlocale(LC_ALL, "rus");
	const string student_groups = "Students.txt";
	ListGroups faculty(student_groups);

	int choice;

	cout << "perform a student search?(1/0)" << endl;
	cin >> choice;

	if (choice == 1) {
		int number;
		cout << "Enter number group:" << endl;
		cin >> number;
		number--;

		
		cout << "1. Search on surname" << endl;
		cout << "2. Search on name" << endl;
		cout << "3. Search on patronymic" << endl;
		cout << "4. Search on phone number" << endl;
		do {
			cout << "Choose sign: " << endl;
			cin >> choice;

			switch (choice) {
			case surname_: {
				cout << "Enter surname student: " << endl;
				string param; cin >> param;
				Student sign; sign.surname = param;

				int* indices = faculty.list[number]->find_student_surname(sign);
				if (indices[0] < 0) {
					cout << "Student not found or not exist!" << endl;
					delete[] indices;
					break;
				}
				int size = _msize(indices) /sizeof(int);
				for (int i = 0; i < size; i++) {
					faculty.list[number]->show(indices[i]);
				}
				delete[] indices;
				break;
			}
			case name_:
			{
				cout << "Enter name student: " << endl;
				string param; cin >> param;

				Student sign; sign.name = param;

				int* indices = faculty.list[number]->find_student_name(sign);
				if (indices[0] < 0) {
					cout << "Student not found or not exist!" << endl;
					delete[] indices;
					break;
				}
				int size = _msize(indices) / sizeof(int);
				for (int i = 0; i < size; i++) {
					faculty.list[number]->show(indices[i]);
				}

				delete[] indices;
				break;
			}
			case patronymic_:
			{
				cout << "Enter patronymic student: " << endl;
				string param; cin >> param;
				Student sign; sign.patronymic = param;

				int* indices = faculty.list[number]->find_student_patronymic(sign);
				if (indices[0] < 0) {
					cout << "Student not found or not exist!" << endl;
					delete[] indices;
					break;
				}
				int size = _msize(indices) / sizeof(int);
				for (int i = 0; i < size; i++) {
					faculty.list[number]->show(indices[i]);
				}
				delete[] indices;
				break;
			}
			case phone_number_:
			{
				cout << "Enter phone number student: " << endl;
				string param; cin >> param;
				Student sign; sign.num_phone = stoll(param);
				
				int index = faculty.list[number]->find_student_number(sign);
				if (index < 0) {
					cout << "Student not found or not exist!" << endl;
					break;
				}
				faculty.list[number]->show(index);
				break;
			}
			default: throw Exeptions<int>(CaseNotFound, choice);
			}
			cout << "Reset?(1/0)" << endl;
			cin >> choice;
		} while (choice == 1);
	}

	/*cout << faculty;*/
	return 0; 
}                                                                                                                                                                                                                  
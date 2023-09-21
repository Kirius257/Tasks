#include "Vector.h"
#include <iostream>
using namespace std;
//ВЕКТОРЫ ДОЛЖНЫ БЫТЬ разного имени

int main() {
	setlocale(LC_ALL, "rus");
	try {
		Vector<float> v1(4), v2(4),res(4),result(4);
		cout << "Input components vector: " << endl;
		v1.input();
		cout << "Input components vector: " << endl;
		v2.input();

		res = v1 + v2;
		result = v1 - v2;

		v1.output();
		cout << endl;
		v2.output();
		cout << endl;
		cout << "Result +" << endl;
		res.output();
		cout << endl;
		cout << "Result -" << endl;
		result.output();
		cout << endl;
		double len = v1.length();
		cout << "Lenght v1 " << len << endl;
		cout << endl;
		double scal = v1 * v2;
		cout << "Scal product v1 and v2 " << scal << endl;
		cout << endl;
	}
	catch (const Exeptions<int>& ex) {
		ex.what();
	}
	return 0;
}
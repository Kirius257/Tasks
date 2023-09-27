#include "Vector.h"
#include <iostream>
using namespace std;



int main() {
	setlocale(LC_ALL, "rus");
	try {
		int l1, l2;
		cout << "Input size vector v1: " << endl;
		cin >> l1;
		

		cout << "Input size vector v2: " << endl;
		cin >> l2;
	

		Vector<float> v1(l1), v2(l2), res, result;

		cout << "Input components vector v1: " << endl;
		cin >> v1;
		cout << "Input components vector v2: " << endl;
		cin >> v2;

		res = v1 + v2;
		result = v1 - v2;

		cout << v1;
		cout << endl;
		cout << v2;
		cout << endl;
		cout << "Result +" << endl;
		cout << res;
		cout << endl;
		cout << "Result -" << endl;
		cout << result;
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
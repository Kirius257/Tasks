#include "Vector.h"
#include <iostream>
using namespace std;


int main() {
	Vector<float> v1(5), v2(4),res(5);
	cout << "Input components vector: " << endl;
	cin >> v1;
	cout << "Input components vector: " << endl;
	cin >> v2;
	res = v1 + v2;
	return 0;
}
#include <iostream>
#include "prototypes2.h"
#include "Arrays.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	float* arr;
	int size;
	cout << "Введите чётный размер массива: " << endl;
	do { 
		cin >> size;

	} while (size % 2 != 0);
	cout << "Заполните массив вещественными числами: " << endl;
	create_array(arr, size);
	swap_halves(arr, size);
	output(arr, size);
	delete[] arr;
	return 0;
}
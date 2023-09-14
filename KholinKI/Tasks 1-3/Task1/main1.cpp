#include <iostream>
#include <cstdlib>
#include <clocale>
#include "prototypes1.h"
#include "C:\Users\Кирилл\Статические библиотеки\StaticLibrary\Create_array\Header.h"

using namespace std;

//задача:
//реализовать функцию,которая заменяет массив вещественных чисел,все элементы большие 10 на их квадратный корень.


int main() {
	setlocale(LC_ALL, "rus");
	float* arr;
	int size;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	cout << "Заполните массив вещественными числами: " << endl;
	create_array(arr, size);
	changer(arr, size);
	output(arr, size);
	delete[] arr;
	return 0;
}
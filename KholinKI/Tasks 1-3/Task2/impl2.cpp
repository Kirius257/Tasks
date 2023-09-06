#include "prototypes2.h"
#include <iostream>
#include <iomanip>

using namespace std;

void create_array(float*& arr, int size) {
	arr = new float[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}


void swap_halves(float* arr, int size) {
	int middle = (size / 2);
	float temp;
	for (int i = 0; i < middle; i++) {
		temp = arr[i];
		arr[i] = arr[middle + i];
		arr[middle + i] = temp;
	}
}

void output(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << left << setw(10) << arr[i] << " ";
	}
}
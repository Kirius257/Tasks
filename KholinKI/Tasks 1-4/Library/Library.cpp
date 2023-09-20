#include "framework.h"

void create_array(float*& arr, int size) {
	arr = new float[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void output(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << left << setw(10) << arr[i] << " ";
	}
}


#include "prototypes1.h"
#include <math.h>
#include <iostream>
using namespace std;

void create_array(float*& arr, int size) {
	arr = new float[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void changer(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > 10) {
			arr[i] = sqrtf(arr[i]);
		}
	}
}

void output(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " " << endl;
	}

}
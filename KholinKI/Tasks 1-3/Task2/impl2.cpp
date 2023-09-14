#include "prototypes2.h"
#include <iostream>
#include <iomanip>


using namespace std;




void swap_halves(float* arr, int size) {
	int middle = (size / 2);
	float temp;
	for (int i = 0; i < middle; i++) {
		temp = arr[i];
		arr[i] = arr[middle + i];
		arr[middle + i] = temp;
	}
}

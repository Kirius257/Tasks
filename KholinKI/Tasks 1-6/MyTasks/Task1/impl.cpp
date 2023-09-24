#include "prototypes.h"
#include <math.h>
#include <iostream>
using namespace std;



void changer(float* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > 10) {
			arr[i] = sqrtf(arr[i]);
		}
	}
}


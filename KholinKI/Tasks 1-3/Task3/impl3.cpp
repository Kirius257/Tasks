#include <iostream>
#include "prototypes3.h"

using namespace std;

int count_elements(int* arr, int size) {
	int count = 1;
	int i, j;
	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				break;
			}
			if (j + 1 == i) {
				break;
			}
		}
		if (arr[i] == arr[j]) {
			continue;
		}
		count++;
	}
	return count;
}


void unique_array::create_array(unique_array& obj,int* arr, int size) {
	int count = count_elements(arr, size);
	int i, j, k;
	k = 0;
	obj.new_arr = new int[count];
	obj.size = count;
	obj.new_arr[k] = arr[0];
	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				break;
			}
			if (j + 1 == i) {
				break;
			}
		}
		if (arr[i] == arr[j]) {
			continue;
		}
		k++;
		obj.new_arr[k] = arr[i];
	}
}


ostream& operator<<(ostream& os, const unique_array& obj) {
	for (int i = 0; i < obj.size; i++) {
		os << obj.new_arr[i] << " ";
	}
	return os;
}
#include <iostream>
#include "prototypes3.h"

using namespace std;



void unique_array::create_array(int* arr, int size) {
	int* tmp_arr = new int[size];
	int dublicate = 0;
	int count = 0;
	int k = -1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] == tmp_arr[j]) {
				dublicate = 1;
				break;
			}
		}
		
		if (dublicate == 1) {
			dublicate = 0;
			continue;
		}
		else {
			count++;
			k++;
			tmp_arr[k] = arr[i];
		}
	}
	new_arr = new int[count];
	this->size = count;
	for (int i = 0; i < count; i++) {
		new_arr[i] = tmp_arr[i];
	}
	delete[] tmp_arr;

}


ostream& operator<<(ostream& os, const unique_array& obj) {
	for (int i = 0; i < obj.size; i++) {
		os << obj.new_arr[i] << " ";
	}
	return os;
}
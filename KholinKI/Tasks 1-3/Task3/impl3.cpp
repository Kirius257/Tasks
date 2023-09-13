#include <iostream>
#include "prototypes3.h"

using namespace std;



void unique_array::create_array(unique_array& obj,int* arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				continue;
			}
		}
		if (i = 0) {
			continue;
		}
		count++;
	}
	cout << count << endl;
}


ostream& operator<<(ostream& os, const unique_array& obj) {
	for (int i = 0; i < obj.size; i++) {
		os << obj.new_arr[i] << " ";
	}
	return os;
}
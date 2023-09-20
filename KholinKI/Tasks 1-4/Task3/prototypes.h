#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

#include <iostream>

using namespace std;

int count_elements(int* arr, int size);

struct unique_array {

	int* new_arr;
	int size;

	void create_array(unique_array& obj, int* arr, int size);


	~unique_array(void) {
		delete[] new_arr;
		size = 0;
	}


};
ostream& operator<<(ostream& os, const unique_array& obj);


#endif#pragma once

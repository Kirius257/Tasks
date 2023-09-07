#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

struct unique_array {
	int* new_arr;
	int size;

	void create_array(int* arr, int size);
	void output();

	~unique_array(void) {
		delete[] new_arr;
		size = 0;
	}

};



#endif
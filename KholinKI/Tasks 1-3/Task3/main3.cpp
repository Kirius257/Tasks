#include <iostream>
#include "prototypes3.h"

using namespace std;

#define N 10

int main() {
	int arr[N] = { 3,5,2,8,0,4,4,3,10,8 };
	unique_array my_arr;
	my_arr.create_array(arr, N);
	my_arr.output();
	return 0;
}
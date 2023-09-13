#include <iostream>
#include "prototypes3.h"

using namespace std;

#define N 15

int main() {
	int arr[N] = { 1,9,1,0,0,12,8,9,6,34,90,21,12,84};
	unique_array obj;
	obj.create_array(obj,arr, N);
	cout << obj << endl;
	return 0;
}
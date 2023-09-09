#include <iostream>
#include "prototypes3.h"

using namespace std;

#define N 15

int main() {
	int arr[N] = { 3,5,2,8,0,4,4,3,10,8,2834,0,0,0,0 };
	unique_array obj;
	obj.create_array(arr, N);
	cout << obj << endl;
	return 0;
}
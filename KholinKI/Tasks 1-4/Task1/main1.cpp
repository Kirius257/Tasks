#include <iostream>
#include <cstdlib>
#include <clocale>
#include "prototypes1.h"
#include "C:\Users\������\����������� ����������\StaticLibrary\Create_array\Arrays.h"

using namespace std;

//������:
//����������� �������,������� �������� ������ ������������ �����,��� �������� ������� 10 �� �� ���������� ������.


int main() {
	setlocale(LC_ALL, "rus");
	float* arr;
	int size;
	cout << "������� ������ �������: " << endl;
	cin >> size;
	cout << "��������� ������ ������������� �������: " << endl;
	create_array(arr, size);
	changer(arr, size);
	output(arr, size);
	delete[] arr;
	return 0;
}
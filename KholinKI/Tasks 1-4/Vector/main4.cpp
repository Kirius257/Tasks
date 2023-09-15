#include <iostream>
#include "Vector.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Vector v1;
	Vector v2;

	cout << "������� ���������� ������� v1: " << endl;
	cin >> v1;
	cout << "������� ���������� ������� v2: " << endl;
	cin >> v2;
	
	float res1 = v1.length();
	float res2 = v2.length();
	cout << " ����� ������� v1: " << res1 << endl;
	cout << " ����� ������� v2: " << res2 << endl;

	float res3 = v1.angle(v2);
	cout << "������� ���� ����� ��������� v1 � v2: "<< res3 << endl;
	
	Vector res4 = v1 + v2;
	Vector res5 = v1 - v2;

	cout << "��������� �������� �������� v1 � v2: "<< res4 << endl;
	cout << "��������� ��������� �������� v1 � v2: " << res5 << endl;

	cout << "������ v1: " << endl;
	cout << v1;
	cout << "������ v2: " << endl;
	cout << v2;
	return 0;
}
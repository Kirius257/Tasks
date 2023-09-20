#include <iostream>
#include "Vector.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Vector v1;
	Vector v2;

	cout << "Введите компоненты вектора v1: " << endl;
	cin >> v1;
	cout << "Введите компоненты вектора v2: " << endl;
	cin >> v2;

	float res1 = v1.length();
	float res2 = v2.length();
	cout << " Длина вектора v1: " << res1 << endl;
	cout << " Длина вектора v2: " << res2 << endl;

	float res3 = v1.angle(v2);
	cout << "Косинус угла между векторами v1 и v2: " << res3 << endl;

	Vector res4 = v1 + v2;
	Vector res5 = v1 - v2;

	cout << "Результат сложения векторов v1 и v2: " << res4 << endl;
	cout << "Результат вычитания векторов v1 и v2: " << res5 << endl;

	cout << "Вектор v1: " << endl;
	cout << v1;
	cout << "Вектор v2: " << endl;
	cout << v2;


	cout << "проверка присваивания и сравнения" << endl;
	v1 = v1;
	cout << v1;

	return 0;
}
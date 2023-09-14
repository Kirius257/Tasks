#include <cmath>
#include "Vector.h"
#include "C:\Users\Кирилл\Статические библиотеки\StaticLibrary\Create_array\class Exeption.h"




Vector::Vector(int size = 3) {
	vec = new float[size];
	n = size;
	cout << "Введите компоненты вектора: " << endl;
	cin >> *this;
}


Vector::Vector(float fill, int size = 3) {
	vec = new float[size];
	n = size;
	for (int i = 0; i < n; i++) {
		vec[i] = fill;
	}
}


Vector::Vector(const Vector& obj) {
	n = obj.n;
	vec = new float[n];
	for (int i = 0; i < n; i++) {
		vec[i] = obj.vec[i];
	}
}


Vector::~Vector() {
	delete[] vec;
	n = 0;
	cout << "Object successfully deleted!" << endl;
}



//Vector operator+(const Vector& obj1,const Vector& obj2) {
//	Vector result();
//	if (obj1.n != obj2.n) {
//		throw Exeptions<int>(different_vectors, n);
//	}
//	for (int i = 0; i < obj1.n; i++) {
//		
//	}
//}


//Vector operator-(const Vector& obj) {
//	
//}


float Vector::operator*(const Vector& obj){
	float res = (this->vec[0] * obj.vec[0] + this->vec[1] * obj.vec[1] + this->vec[2] * obj.vec[2]);
	return res;
}

float Vector::length(const Vector& obj) {
	float len = sqrtf((*this) * obj);
	return len;
}


float Vector::angle(const Vector& obj) {
	float value = ((*this) * obj) / (length(obj) * length(obj));
	return value;
}

istream& operator>>(istream& stream, Vector& obj) {
	for (int i = 0; i < obj.n; i++) {
		cin >> obj.vec[i];
	}
	return stream;
}

//ostream& operator<<(ostream& stream, const Vector& obj) {
//	for (int i = 0; i < obj.n; i++) {
//		cout << obj.vec[i] << " ";
//	}
//	return stream;
//}
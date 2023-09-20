#include <cmath>
#include "Vector.h"
#include "class Exeption.h"




Vector::Vector(int size) {
	vec = new float[size];
	n = size;
}//default constructor


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



Vector Vector::operator+(const Vector& obj) {
	Vector result;
	if (n != obj.n) {
		throw Exeptions<int>(different_vectors, n);
	}
	for (int i = 0; i < obj.n; i++) {
		result.vec[i] = vec[i] + obj.vec[i];
	}
	return result;
}


Vector Vector::operator-(const Vector& obj) {
	Vector result;
	if (n != obj.n) {
		throw Exeptions<int>(different_vectors, n);
	}
	for (int i = 0; i < obj.n; i++) {
		result.vec[i] = vec[i] - obj.vec[i];
	}
	return result;
}


float Vector::operator*(const Vector& obj)const{
	float res = (this->vec[0] * obj.vec[0] + this->vec[1] * obj.vec[1] + this->vec[2] * obj.vec[2]);
	return res;
}

float Vector::length()const {
	float len = sqrtf((*this) * (*this));
	return len;
}


float Vector::angle(const Vector& obj)const {
	float value = cos(((*this) * obj) / (length() * obj.length()));
	return value;
}

bool Vector::operator==(const Vector& obj){
	if (n == obj.n) {
		return false;
	}
	else{	
		for (int i = 0; i < n; i++) {
			if (vec[i] == obj.vec[i]) {
				return false;
			}
		}
	}
	return true;
}

Vector& Vector::operator=(const Vector& obj) {
	if (*this == obj) {
		return *this;
	}
	if (n != obj.n) {
		n = obj.n;
		delete[] vec;
		vec = new float[n];
	}
	for (int i = 0; i < n; i++) {
		vec[i] = obj.vec[i];
	}
	return *this;
}


istream& operator>>(istream& stream, Vector& obj) {
	for (int i = 0; i < obj.n; i++) {
		cin >> obj.vec[i];
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Vector& obj) {
	for (int i = 0; i < obj.n; i++) {
		cout << obj.vec[i] << " ";
	}
	cout << endl;
	return stream;
}
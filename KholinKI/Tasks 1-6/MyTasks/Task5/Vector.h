#ifndef _VECTOR_H
#define _VECTOR_H

#include "framework.h"
#include <iostream>


template <class T> class Vector {
private:
	T* vec;
	int size;
public:
	Vector(int size);
	Vector(const Vector<T>& obj);
	~Vector();


	
	double length()const;//lenght of vector


	double operator*(const Vector<T>& obj)const;// scalar product
	Vector operator+(const Vector<T>& obj);
	Vector operator-(const Vector<T>& obj);
	Vector& operator=(const Vector<T>& obj);
	bool operator==(const Vector<T>& obj)const;
	
	void output()const;
	void input();
};

template <class T>
Vector<T>::Vector(int size) {
	this->size = size;
	vec = new T[size];
	for (int i = 0; i < size; i++) {
		vec[i] = 0;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T>& obj) {
	this->size = size;
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
}

template <class T>
Vector<T>::~Vector() {
	delete[] vec;
	size = 0;
}

template <class T>
double Vector<T>::operator*(const Vector<T>& obj)const{
	double res = 0.0;
	for (int i = 0; i < size; i++) {
		res += (this->vec[i] * obj.vec[i]);
	}
	return res;
}	//scalar product

template <class T>
double Vector<T>::length()const {
	double len = sqrtf((*this) * (*this));
	return len;
}//lenght of vector


template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& obj) {
	Vector<T>res1(size);
	if (size != obj.size) {
		throw Exeptions<int>(different_vectors, size);
	}
	else {
		for (int i = 0; i < size; i++) {
			res1.vec[i] = vec[i] + obj.vec[i];
		}
	}
	return res1;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& obj) {
	Vector<T>res1(size);
	if (size != obj.size) {
		throw Exeptions<int>(different_vectors, size);
	}
	else {
		for (int i = 0; i < size; i++) {
			res1.vec[i] = vec[i] - obj.vec[i];
		}
	}
	return res1;
}


template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {
	if (*this == obj) {
		return *this;
	}
	else {
		if (size != obj.size) {
			delete[] vec;
			size = obj.size;
			vec = new T[size];
		}
		for (int i = 0; i < size; i++) {
			vec[i] = obj.vec[i];
		}
	}
	return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& obj)const {
	if (size != obj.size) {
	return false;
	}
	for (int i = 0; i < size; i++) {
		if (vec[i] != obj.vec[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
void Vector<T>::input(){
	for (int i = 0; i < size; i++) {
		cin >> vec[i];
	}
}

template <class T>
void Vector<T>::output()const {
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
#endif
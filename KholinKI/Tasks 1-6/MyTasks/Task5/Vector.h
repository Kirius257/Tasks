#ifndef _VECTOR_H
#define _VECTOR_H

#include "framework.h"
#include <iostream>



template <class T> class Vector {
private:
	T* vec;
	int size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector<T>& obj);
	~Vector();


	
	double length()const;//lenght of vector


	double operator*(const Vector<T>& obj)const;// scalar product
	Vector operator+(const Vector<T>& obj);
	Vector operator-(const Vector<T>& obj);
	const Vector& operator=(const Vector<T>& obj);
	bool operator==(const Vector<T>& obj)const;
	
	void set_size(int size) { this->size = size; }

	friend istream& operator>>(istream& stream, Vector<T>& obj) {
		for (int i = 0; i < obj.size; i++) {
			stream >> obj.vec[i];
		}
		return stream;
	}
	
	friend ostream& operator<<(ostream& stream, const Vector<T>& obj) {
		for (int i = 0; i < obj.size; i++) {
			stream << obj.vec[i] << " ";
		}
		stream << endl;
		return stream;
	}
};

template <class T>
Vector<T>::Vector() {
	size = 0;
	vec = nullptr;
}

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
	this->size = obj.size;
	vec = new T[size];
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
	Vector<T>res1(*this);
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
	Vector<T>res1(*this);
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
const Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {
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







#endif
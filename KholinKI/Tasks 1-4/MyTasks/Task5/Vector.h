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
	/*Vector operator-(const Vector<T>& obj);
	Vector operator=(const Vector<T>& obj);
	bool operator==(const Vector<T>& obj)const;*/
	\
	//friend ostream& operator<<(ostream& s, const Vector<T>& obj);
	friend istream& operator>>(istream& s,		 Vector<T>& obj);
};

template <class T>
Vector<T>::Vector(int size) {
	this->size = size;
	vec = new T[size];
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
	Vector<T> res(size);
	if (size != obj.size) {
		T* tmp = new T[obj.size];
		for (int i = 0; i < obj.size; i++) {
			tmp[i] = obj.vec[i];
		}
		delete[] vec;
		size = obj.size;
		vec = tmp;
	}
	for (int i = 0; i < size; i++) {
		res.vec[i] = vec[i] + obj.vec[i];
	}
	return res;
}

template <class T>
istream& operator>>(istream& s, Vector<T>& obj) {
	for (int i = 0; i < obj.size; i++) {
		s >> obj.vec[i];
	}
	return s;
}

//template <class T>
//ostream& operator<<(ostream& s, const Vector<T>& obj) {
//	for (int i = 0; i < obj.size; i++) {
//		s << obj.vec[i] << " ";
//	}
//	s << endl;
//	return s;
//}
//Vector operator-(const Vector<T>& obj);
//Vector operator=(const Vector<T>& obj);
//bool operator==(const Vector<T>& obj)const;

#endif
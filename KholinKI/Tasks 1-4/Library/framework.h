﻿

#ifndef _FRAMEWORK_H
#define _FRAMERWORK_H
#include <iostream>
#include <iomanip>

using namespace std;


enum TypeExeption { different_vectors };//набор исключений
template <class T>
class Exeptions {
private:
	TypeExeption type;
	T wrong_value;
public:
	Exeptions(TypeExeption type, T wrong_value);

	void what()const;
};

template <class T>
Exeptions<T>::Exeptions(TypeExeption type, T wrong_value) {
	this->type = type;
	this->wrong_value = wrong_value;
}

template <class T>
void Exeptions<T>::what()const {
	switch (type) {//метки для описания исключений(что произошло?Почему?Как исправить и прочее
	case different_vectors: cout << "Векторы различны по количеству компонент!" << endl;
	default: {cout << "Exeption not found!" << endl; abort(); }
	}
}



void output(float* arr, int size);
void create_array(float*& arr, int size);
#endif
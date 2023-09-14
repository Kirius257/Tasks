#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>
using namespace std;


class Vector {
private:
	float* vec;
	int n;
public:
	Vector(int size);//default constructor
	Vector(float fill, int size);//initialiser-constructor
	Vector(const Vector& obj);//copy constructor
	~Vector();//destructor
	

	
	float angle(const Vector& obj);//cosinus angle between vectors
	float length(const Vector& obj);//lenght of vector

	
	float operator*(const Vector& obj);// scalar product


	friend istream& operator>>(istream& stream, Vector& obj);//input
	friend ostream& operator<<(ostream& stream, const Vector& obj);//output
	

};



#endif
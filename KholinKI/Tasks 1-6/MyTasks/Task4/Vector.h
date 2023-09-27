#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>
using namespace std;


class Vector {
private:
	float* vec;
	int n;
public:
	Vector(int size = 3);//default constructor
	Vector(float fill, int size);//initialiser-constructor
	Vector(const Vector& obj);//copy constructor
	~Vector();//destructor



	float angle(const Vector& obj)const;//cosinus angle between vectors
	float length()const;//lenght of vector


	float operator*(const Vector& obj)const;// scalar product
	Vector operator+(const Vector& obj);
	Vector operator-(const Vector& obj);
	const Vector& operator=(const Vector& obj);
	bool operator==(const Vector& obj)const;

	friend istream& operator>>(istream& stream, Vector& obj);//input
	friend ostream& operator<<(ostream& stream, const Vector& obj);//output


};



#endif
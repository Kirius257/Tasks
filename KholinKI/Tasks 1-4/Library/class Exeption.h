#ifndef _EXEPTION_H
#define _EXEPTION_H

enum TypeExeption {different_vectors};//����� ����������
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
	switch (type) {//����� ��� �������� ����������(��� ���������?������?��� ��������� � ������
	case different_vectors: cout << "������� �������� �� ���������� ���������!" << endl;
	default: {cout << "Exeption not found!" << endl; abort(); }
	}
}
#endif
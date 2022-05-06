#pragma once
#include <iostream>
#include <exception>
#include <cassert>

//����� ������ ��� ������ � ������������ ��������
//����� ������� ��������� �������� ���-20-1


template <class T>
class Vector
{
private:
	T* ptr;						//��������� �� ������
	int size;					//������ �������

public:

	Vector() {
		ptr = nullptr;
		size = 0;
	}

	Vector(int size) {							//�����������, �������� ������ � ��������� ������
		assert(size > 0);
		this->size = size;
		ptr = new T[size];
		// memset 
		for (int i = 0; i < size; i++) {
			ptr[i] = 0;
		}
	}

	Vector(const Vector&& v2)						//����������� �����������
	{
		this->ptr = v2.ptr;
		v2.ptr = nullptr;
		this->size = v2.size;							
	}

	Vector(int size, T value) {							//�����������, �������� ������ � ��������� ������
		assert(size > 0);
		this->size = size;
		ptr = new T[size];
		// memset 
		for (int i = 0; i < size; i++) {
			ptr[i] = value;
		}
	}



	Vector (const Vector& v2)						//����������� �����������
	{

		this->ptr = new T[v2.size];							//�������� ������ ��� ��� ���� ������
		this->size = v2.size;

		for (int i = 0; i < size; i++) {				//�������� �������� �� ������ ������� � ������
			this->ptr[i] = v2.ptr[i];
		}

		//return ptr;										//���������� ������
	}

	void push_back(const T& value)						//���������� �������� � ����� �������
	{
		T* ptr2 = new T[size + 1];				//�������� ������ ��� ����� ������

		for (int i = 0; i < size; i++) {		//�������� ��� �������� ��
			ptr2[i] = ptr[i];					//������ ������� � ������
		}

		// memcpy

		ptr2[size] = value;						//��������� ��������� �������

		delete[] ptr;							//������� ������ �� ������� �������
		ptr = ptr2;								//��������� ��������� �� ����� ������

		this->size++;
	}

	void pop_back()								//�������� ���������� ��������
	{
		T* ptr2 = new T[size - 1];				//�������� ������ �� ����� ������ �� ������ 1 ������

		this->size--;							//��������� ������ ������� �� 1

		for (int i = 0; i < size; i++) {		//�������� ��� �������� ��
			ptr2[i] = ptr[i];					//������ ������� � ������
		}

		delete[] ptr;							//������� ������ ������
		ptr = ptr2;								//������ ��������� �� ����� ������
	}

	int get_size() const								//���������� ������ �������
	{
		return this->size;
	}

	void resize(int new_size)						//��������� ������� �������
	{
		T* ptr2 = new T[new_size];					//�������� ������ ��� ����� ������

		if (new_size > size)
		{
			for (int i = 0; i < size; i++) {		//�������� ��� �������� ��
				ptr2[i] = ptr[i];					//������ ������� � ������
			}

			for (int i = size; i < new_size; i++){	//��������� ������ ���������� ��������
				ptr2[i] = 0;
			}
		}
		else
		{
			for (int i = 0; i < new_size; i++) {	//�������� ��� �������� ��
				ptr2[i] = ptr[i];					//������ ������� � ������
			}
		}
		size = new_size;
		delete[] ptr;									//������� ������ ������

		ptr = ptr2;										//������������� ��������� �� ������
	}

	Vector operator = (const Vector &v2)						//����������� �������
	{	
		// this->ptr del, write new
		if (ptr != nullptr)
		{
			delete[] this->ptr;
		}
		

		this->ptr = new T[v2.size];							//�������� ������ ��� ��� ���� ������
		this->size = v2.size;

		for (int i = 0; i < size; i++) {				//�������� �������� �� ������ ������� � ������
			this->ptr[i] = v2.ptr[i];
		}

		return *this;										//���������� ������
	}

	// Vector<int> v, v1, v2;
	// v = v1
	// v = v1 = v2
	// v.operator=(v1)

	void insert(unsigned index, const T& Value)				//��������� ������� � ������� �� ���������� �������
	{
		if (index < 0 || index >= size) {
			throw std::invalid_argument("Does not match the size of the array!");
		}
		else {

			T* ptr2 = new T[size + 1];					//�������� ������ ��� ����� ������
			this->size++;

			for (int i = 0; i < index; i++) {			//�������� �������� �� �������
				ptr2[i] = ptr[i];						//������ ������� � ������
			}

			ptr2[index] = Value;

			for (int i = index + 1; i < size; i++) {	//�������� ���������� ��������
				ptr2[i] = ptr[i - 1];
			}

			delete[] ptr;								//������� ������ �� ������� �������
			ptr = ptr2;									//��������� ��������� �� ����� ������
		}
	}

	void swap(int index1, int index2) {					//������ ������� �������� ������� �� ��������� ��������
		
		//assert(index1 >= 0 && index1 < size && index2 >= 0 && index2 < size);		//�����

		if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {			//�������� �� �������� ��������
			throw std::invalid_argument("Does not match the size of the array!");
		}
		else
		{
			T buffer;									//������� ����� �������� ����� ��������� ����������
			buffer = ptr[index1];
			ptr[index1] = ptr[index2];
			ptr[index2] = buffer;
		}
	}

	T get(int index)	const								//���������� �������� ������� �� ������� �������
	{									
		if (index < 0 || index >= size) {				//�������� �� �������� ��������
			throw std::invalid_argument("Does not match the size of the array!");
		}
		return ptr[index];
	}

	void set(int index, const T& Value) 
	{
		if (index < 0 || index >= size) {				//�������� �� �������� ��������
			throw std::invalid_argument("Does not match the size of the array!");
		}
		ptr[index] = Value;
	}

	T& operator [] (int index)							//������ � �������� �������� �� ������� �������
	{
		assert(index >= 0 && index < size);
		return ptr[index];
	}

	void erase(int index, int count)					//�������� ������� �� ������� ������� � ���������� ������� ������ ���-��
	{
		assert(index >= 0 && index < size);
		T* ptr2 = new T[size - count];					//�������� ������ ��� ����� ������
		
		for (int i = 0; i < index; i++) {					//�������� ��� �� �������
			ptr2[i] = ptr[i];
		}

		for (int i = index + count; i < size; i++) {	//�������� ��� ����� ���������� �����
			ptr2[i - count] = ptr[i];
		}
		size = size - count;
		delete[] ptr;									//������� ������ ������
		ptr = ptr2;										//�������������� ��������� �� ������
	}

	void clear()										//������� ������ �� �������
	{
		delete[] ptr;
		this->size = 0;
		ptr = nullptr;
	}

	T last()
	{
		return ptr[size - 1];
	}
		
	~Vector()											//����������, ������� ������
	{
		clear();
	}
};


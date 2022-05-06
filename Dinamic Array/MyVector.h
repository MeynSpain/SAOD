#pragma once
#include <iostream>
#include <exception>
#include <cassert>

//Класс вектор для работы с динамическим массивом
//Автор Сорокин Александр Егорович ВМК-20-1


template <class T>
class Vector
{
private:
	T* ptr;						//Указатель на массив
	int size;					//Размер массива

public:

	Vector() {
		ptr = nullptr;
		size = 0;
	}

	Vector(int size) {							//Конструктор, выделяет память и заполняет нулями
		assert(size > 0);
		this->size = size;
		ptr = new T[size];
		// memset 
		for (int i = 0; i < size; i++) {
			ptr[i] = 0;
		}
	}

	Vector(const Vector&& v2)						//Конструктор перемещения
	{
		this->ptr = v2.ptr;
		v2.ptr = nullptr;
		this->size = v2.size;							
	}

	Vector(int size, T value) {							//Конструктор, выделяет память и заполняет числом
		assert(size > 0);
		this->size = size;
		ptr = new T[size];
		// memset 
		for (int i = 0; i < size; i++) {
			ptr[i] = value;
		}
	}



	Vector (const Vector& v2)						//Конструктор копирования
	{

		this->ptr = new T[v2.size];							//Выделяем память под еще один массив
		this->size = v2.size;

		for (int i = 0; i < size; i++) {				//Копируем значения из одного массива в другой
			this->ptr[i] = v2.ptr[i];
		}

		//return ptr;										//Возвращаем массив
	}

	void push_back(const T& value)						//Добавление элемента в конец массива
	{
		T* ptr2 = new T[size + 1];				//Выделяем память под новый массив

		for (int i = 0; i < size; i++) {		//Копируем все значения из
			ptr2[i] = ptr[i];					//одного массива в другой
		}

		// memcpy

		ptr2[size] = value;						//добавляем последний элемент

		delete[] ptr;							//очищаем память от старого массива
		ptr = ptr2;								//переводим указатель на новый массив

		this->size++;
	}

	void pop_back()								//Удаление последнего элемента
	{
		T* ptr2 = new T[size - 1];				//Выделяем память по новый массив на размер 1 меньше

		this->size--;							//Уменьшаем размер массива на 1

		for (int i = 0; i < size; i++) {		//Копируем все значения из
			ptr2[i] = ptr[i];					//одного массива в другой
		}

		delete[] ptr;							//Удаляем старый массив
		ptr = ptr2;								//Меняем указатель на новый массив
	}

	int get_size() const								//Возвращает размер массива
	{
		return this->size;
	}

	void resize(int new_size)						//Изменение размера массива
	{
		T* ptr2 = new T[new_size];					//Выделяем память под новый массив

		if (new_size > size)
		{
			for (int i = 0; i < size; i++) {		//Копируем все значения из
				ptr2[i] = ptr[i];					//одного массива в другой
			}

			for (int i = size; i < new_size; i++){	//Заполняем нулями оставшиеся элементы
				ptr2[i] = 0;
			}
		}
		else
		{
			for (int i = 0; i < new_size; i++) {	//Копируем все значения из
				ptr2[i] = ptr[i];					//одного массива в другой
			}
		}
		size = new_size;
		delete[] ptr;									//Удаляем старый массив

		ptr = ptr2;										//Переопределям указатель на массив
	}

	Vector operator = (const Vector &v2)						//Копирование вектора
	{	
		// this->ptr del, write new
		if (ptr != nullptr)
		{
			delete[] this->ptr;
		}
		

		this->ptr = new T[v2.size];							//Выделяем память под еще один массив
		this->size = v2.size;

		for (int i = 0; i < size; i++) {				//Копируем значения из одного массива в другой
			this->ptr[i] = v2.ptr[i];
		}

		return *this;										//Возвращаем массив
	}

	// Vector<int> v, v1, v2;
	// v = v1
	// v = v1 = v2
	// v.operator=(v1)

	void insert(unsigned index, const T& Value)				//Вставляет элемент в массиве по указанному индексу
	{
		if (index < 0 || index >= size) {
			throw std::invalid_argument("Does not match the size of the array!");
		}
		else {

			T* ptr2 = new T[size + 1];					//Выделяем память под новый массив
			this->size++;

			for (int i = 0; i < index; i++) {			//Копируем значения до индекса
				ptr2[i] = ptr[i];						//одного массива в другой
			}

			ptr2[index] = Value;

			for (int i = index + 1; i < size; i++) {	//Копируем оставшиеся значения
				ptr2[i] = ptr[i - 1];
			}

			delete[] ptr;								//очищаем память от старого массива
			ptr = ptr2;									//переводим указатель на новый массив
		}
	}

	void swap(int index1, int index2) {					//Меняет местами значения лежащие по указанным индексам
		
		//assert(index1 >= 0 && index1 < size && index2 >= 0 && index2 < size);		//провк

		if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {			//Проверка на верность индексов
			throw std::invalid_argument("Does not match the size of the array!");
		}
		else
		{
			T buffer;									//Обычная смена значений через буфферную переменную
			buffer = ptr[index1];
			ptr[index1] = ptr[index2];
			ptr[index2] = buffer;
		}
	}

	T get(int index)	const								//Возвращает значение лежащее по данному индексу
	{									
		if (index < 0 || index >= size) {				//Проверка на верность индексов
			throw std::invalid_argument("Does not match the size of the array!");
		}
		return ptr[index];
	}

	void set(int index, const T& Value) 
	{
		if (index < 0 || index >= size) {				//Проверка на верность индексов
			throw std::invalid_argument("Does not match the size of the array!");
		}
		ptr[index] = Value;
	}

	T& operator [] (int index)							//Доступ к элементу лежащему по данному индексу
	{
		assert(index >= 0 && index < size);
		return ptr[index];
	}

	void erase(int index, int count)					//Вырезать элеметы из массива начиная с указанного индекса нужное кол-во
	{
		assert(index >= 0 && index < size);
		T* ptr2 = new T[size - count];					//Выделяем память под новый массив
		
		for (int i = 0; i < index; i++) {					//Копируем все до индекса
			ptr2[i] = ptr[i];
		}

		for (int i = index + count; i < size; i++) {	//Копируем все после выреззаной части
			ptr2[i - count] = ptr[i];
		}
		size = size - count;
		delete[] ptr;									//Удаляем старый массив
		ptr = ptr2;										//Переопределяем указатель на массив
	}

	void clear()										//Очистка памяти от массива
	{
		delete[] ptr;
		this->size = 0;
		ptr = nullptr;
	}

	T last()
	{
		return ptr[size - 1];
	}
		
	~Vector()											//Деструктор, очищает память
	{
		clear();
	}
};


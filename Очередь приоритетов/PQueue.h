#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// Класс очереди, но с приоритетом на 200 эл-в.
/// Поэтому если хотите хранить внутри свои структуры, то нужно
/// переопределить оператор меньше.
/// </summary>
/// <typeparam name="Type"></typeparam>
template<typename Type>
class PQueue
{
private:

	int count;			//кол-во элементов

	Type arr[200];		//массив для хранения

	/// <summary>
	/// Находит индекс первого в очереди по приоритету
	/// </summary>
	/// <returns></returns>
	int find_first();

public:

	//Конструктор
	PQueue();			

	/// <summary>
	/// Вставка элемента в очередь
	/// </summary>
	/// <param name="item">- вставляемый элемент</param>
	void push(const Type& item);		

	/// <summary>
	/// Удаляет элемент из очереди и возвращает значение
	/// по приоритету
	/// </summary>
	/// <returns></returns>
	Type pop();

	/// <summary>
	/// Возвращает эл-т который 1й в очереди по приоритету, но не удаляет его
	/// </summary>
	/// <returns></returns>
	Type front();

	/// <summary>
	/// Очищает очередь
	/// </summary>
	void clear();

	/// <summary>
	/// Пустая очередь или нет
	/// </summary>
	/// <returns>true - пустой, false - не пустой</returns>
	bool empty();

	/// <summary>
	/// Возвращает кол-во элементов в очереди
	/// </summary>
	/// <returns></returns>
	int size();

};

template<typename Type>
inline int PQueue<Type>::find_first()
{
	//Нужно найти минимальный эл-т
		//Задаем начальное минимальное значение
	int i_min = 0;

	//Проходимся по массиву и находим минимальный
	for (int i = 0; i < count; i++)
	{
		//Если текущий элемент меньше минимального, то запоминаем индекс
		if (arr[i] < arr[i_min])
		{
			i_min = i;
		}
	}
	//Возвращаем найденное значение
	return i_min;
}

template<typename Type>
inline PQueue<Type>::PQueue()
{
	count = 0;
}

template<typename Type>
inline void PQueue<Type>::push(const Type& item)
{
	if (count < 200)
	{
		arr[count] = item;
		count++;
	}
	else
	{
		throw out_of_range("queue is full!");
	}
}

template<typename Type>
inline Type PQueue<Type>::pop()
{
	if (count > 0)
	{
		//Находим индекс первого в очереди
		int i_min = find_first();

		//Мы будем возвращать это значение
		Type min = arr[i_min];

		//Теперь удаляем это значение из массива
		arr[i_min] = arr[count - 1];
		count--;
		
		//Возвращаем найденное значение
		return min;
	}
	else
	{
		throw out_of_range("queue is empty!");
	}
	
}

template<typename Type>
inline Type PQueue<Type>::front()
{
	if (count > 0)
	{
		//Находим нужный нам индекс
		int i_min = find_first();

		//И возвращаем это значение
		return arr[i_min];
	}
	else
	{
		throw out_of_range("queue is empty!");
	}
}

template<typename Type>
inline void PQueue<Type>::clear()
{
	count = 0;
}

template<typename Type>
inline bool PQueue<Type>::empty()
{
	return count == 0;
}

template<typename Type>
inline int PQueue<Type>::size()
{
	return count;
}

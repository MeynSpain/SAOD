#pragma once
#include <exception>

/// <summary>
/// Класс простой очереди.
/// Основан на статическом массиве на 200 эл-в
/// </summary>
/// <typeparam name="Type"></typeparam>
template<class Type>
class SimpleQueue
{
private:

	int first;				//указатель на начало очереди
	int last;				//указатель на конец очереди
	int count;				//Кол-во элементов в очереди
	Type arr[200];

public:

	//Инициализируем нулями
	SimpleQueue();

	/// <summary>
	/// Вставка элемента в очередб
	/// </summary>
	/// <param name="item">- вставляемый элемент</param>
	void insert(Type& item);

	/// <summary>
	/// Возвращает передний элемент и удаляет его из очереди
	/// </summary>
	/// <returns>Передний элемент</returns>
	Type delet()
	{
		Type buffer;

		if (count == 0)
		{
			throw std::invalid_argument("Queue is empty");
		}
		else
		{
			buffer = arr[first];
			count--;
			//Закольцовываем
			first = (first + 1) % 200;

			return buffer;
		}
	}

	/// <summary>
	/// Очищает очередь
	/// </summary>
	void clear();

	/// <summary>
	/// Возвращает размер очереди
	/// </summary>
	/// <returns></returns>
	int leght();

	/// <summary>
	/// Возвращает размер очереди
	/// </summary>
	/// <returns></returns>
	int size();
	
	/// <summary>
	/// Проверяет пуста очередь или нет
	/// </summary>
	/// <returns>true - пуста, false - нет</returns>
	bool empty();

	/// <summary>
	/// Возвращает переднее значение очереди, не удаляя его из очереди
	/// </summary>
	/// <returns>переднее значение</returns>
	Type front()
	{
		return arr[first];
	}
};

template<class Type>
inline SimpleQueue<Type>::SimpleQueue()
{
	first = 0;
	last = 0;
	count = 0;
}

template<class Type>
inline void SimpleQueue<Type>::insert(Type& item)
{
	//Проверяем не переполнили мы массив
	if (count < 200)
	{
		//вставляем элемент
		arr[last] = item;
		//и увеличиваем кол-во и указатель
		count++;
		//Делаем так, чтобы закольцевать очередь
		last = (last + 1) % 200;
	}
	else
	{
		throw std::invalid_argument("Queue is full");
	}
}

template<class Type>
inline void SimpleQueue<Type>::clear()
{
	count = 0;
	first = 0;
	last = 0;
}

template<class Type>
inline int SimpleQueue<Type>::leght()
{
	return count;
}

template<class Type>
inline int SimpleQueue<Type>::size()
{
	return count;
}

template<class Type>
inline bool SimpleQueue<Type>::empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

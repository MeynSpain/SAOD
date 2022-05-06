#pragma once
#include <exception>

/// <summary>
/// Стек на основе статического массива
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class MyStack
{
private:

	int capacity = 200;

	T arr[200];

	int top;		//Указатель на верхний элемент

public:

	MyStack()
	{
		top = -1;
	}

	/// <summary>
	/// Добавляет значение в стек
	/// </summary>
	void push(T value)
	{
		if (top == capacity - 1)
		{
			top = -1;			//циклим
		}
		top++;
		arr[top] = value;
	}

	/// <summary>
	/// Возвращает верхнее значение стека
	/// </summary>
	/// <returns>Верхнее значение стека</returns>
	T peek()
	{
		if (top > -1)
			return arr[top];
		else
			throw std::invalid_argument("Stack is empty!");
	}

	/// <summary>
	/// Удаление верхнего элемента из стека, также возвращает этот элемент
	/// </summary>
	/// <returns>Верхний элемент стека</returns>
	T pop()
	{
		if (top > -1)
		{
			top--;
			return arr[top + 1];
		}
		else
		{
			throw std::invalid_argument("Stack is empty!");
		}
	}

	/// <summary>
	/// Очистка стека
	/// </summary>
	void clear()
	{
		top = -1;
	}

	/// <summary>
	/// Размер стека
	/// </summary>
	/// <returns>Размер стека</returns>
	int size()
	{
		return top + 1;

	}


	/// <summary>
	/// Проверяет пустой стек или нет
	/// </summary>
	/// <returns>Если пустой - false, не пустой - true</returns>
	bool empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};

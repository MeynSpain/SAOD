#pragma once

#include <iostream>
#include <vector>

using namespace std;


/// <summary>
/// Алгоритм быстрой сортировки массива класса vector
/// </summary>
/// <typeparam name="Type">int, double, char</typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
/// <param name="first">- индекс начала сортировки</param>
/// <param name="last">- индекс конца сортировки</param>
template<typename Type>
void QuickSort(vector<Type>& arr, int first, int last);


/// <summary>
/// Пузырьковая сортировка. P.S. Не рекомендую
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
template<typename Type>
void BubbleSort(vector<Type>& arr);

/// <summary>
/// Сортировка выбором. P.S. Мне она нравится больше, но по сути скорость выполнения не особо отличается от 
/// ненавистной мне пузырьковой сортировки
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
template<typename Type>
void SelectionSort(vector<Type>& arr);

/// <summary>
/// Сортировка вставками
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void InsertionSort(vector<Type>& arr);

/// <summary>
/// Сортировка Шелла, быстрее нее только быстрая сортировка
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void ShellSort(vector<Type>& arr);









// //////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// Алгоритм быстрой сортировки массива класса vector
/// </summary>
/// <typeparam name="Type">int, double, char</typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
/// <param name="first">- индекс начала сортировки</param>
/// <param name="last">- индекс конца сортировки</param>
template<typename Type>
void QuickSort(vector<Type>& arr, int first, int last)
{
	if (first < last)
	{
		//Указываем на левый и правые индексы массива
		int left = first;
		int right = last;
		//Находим значение, которое лежит в центре, причем так, чтобы не получить переполнение
		int mid = arr[left + (right - left) / 2]; 

		do
		{
			//Идем по левой стороне массива и ищем
			//эл-т, который больше серединного значения
			while (arr[left] < mid)
			{
				left++;
			}
			//Теперь идем по правой стороне массива и ищем
			//эл-т, который меньше серединного значения
			while (arr[right] > mid)
			{
				right--;
			}

			//Как только мы нашли эти эл-ты, и левый и правые индексы не поменялись местами
			//меняем эл-ты местами
			if (left <= right)
			{
				Type buffer = arr[left];
				arr[left] = arr[right];
				arr[right] = buffer;
				//И передвигаем индексы
				left++;
				right--;
			}
		} while (left < right);

		//Теперь снова вызываем нашу функцию для левой части массива и правой
		QuickSort(arr, first, right);	//Левая
		QuickSort(arr, left, last);	//Правая
	}
	else
	{
		return;
	}
}

/// <summary>
/// Пузырьковая сортировка. P.S. Не рекомендую
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
template<typename Type>
void BubbleSort(vector<Type>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			//Если следующий эл-т меньше текущего, то меняем их местами
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/// <summary>
/// Сортировка выбором. P.S. Мне она нравится больше, но по сути скорость выполнения не особо отличается от 
/// ненавистной мне пузырьковой сортировки
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- массив, который нужно отсортировать</param>
template<typename Type>
void SelectionSort(vector<Type>& arr)
{
	//Внешний цикл, в котором ставим уже нужные значения
	for (int i = 0; i < arr.size() - 1; i++)
	{
		//Устанавливаем начальный индекс минимального значения
		int i_min = i;
		//Внутрений, в котором будем искать минимум
		for (int j = i + 1; j < arr.size(); j++)
		{
			//Находим минимум в этой части массива
			if (arr[j] < arr[i_min])
			{
				i_min =j;
			}
		}
		//Меняем эти значения местами
		swap(arr[i], arr[i_min]);
	}
}


/// <summary>
/// Сортировка вставками
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void InsertionSort(vector<Type>& arr)
{
	//Начинаем со 2го эл-ты, потому что будем идти назад и смотреть на радужное прошлое
	for (int i = 1; i < arr.size(); i++)
	{
		int value = arr[i];	
		int j = i;
		while (j > 0 && arr[j - 1] > value)
		{
			//Смещаем эл-ты вправо
			arr[j] = arr[j - 1];
			j--;
		}
		//Ставим наш эл-т
		arr[j] = value;
	}
}

/// <summary>
/// Сортировка Шелла, быстрее нее только быстрая сортировка
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void ShellSort(vector<Type>& arr)
{
	int j;
	int step;
	//Шаг которым мы будем делить массив на части
	for (step = arr.size() / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arr.size(); i++)
		{
			Type buffer = arr[i];
			for ( j = i; j >= step; j -= step)
			{
				//Ну и по сути в дело вступают обычные вставки
				if (buffer < arr[j - step])
				{
					arr[j] = arr[j - step];
				}
				else
				{
					break;
				}
			}
			arr[j] = buffer;
		}	
	}
}

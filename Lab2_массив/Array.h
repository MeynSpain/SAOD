#pragma once
#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
void fill_random(vector<T>& arr, int left, int right);		//«аполнение массива случайными числами

template<typename T>
void print_arr(vector<T>& arr);								//¬ывод массива на экран

template<typename T>
int count_in_range(vector<T>& arr, T left, T right);		// ол-во элементов массива наход€щиес€ в данном диапозоне

template<typename T>
int find_left(vector<T>& arr, T left_value);				//Ѕинарный поиск левого индекса

template<typename T>
int find_right(vector<T>& arr, T right_value);				//Ѕинарный поиск правого индекса

template<typename T>
T sum_after_value(vector<T>& arr, T value);					//—умма элементов массива после заданного значени€

template<typename T>
void sort_decrease_abs(vector<T>& arr);						//—ортировка массива по убыванию модулей

template<typename T>
void write_tofile(vector<T>& arr, ofstream& f);		//запись массива в файл

//////////////////////////////////////  –еализаци€  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

template<typename T>
void fill_random(vector<T>& arr, int left, int right)	//«аполнение массива случайными числами
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); i++)
	{
		float n = rand() % (right * 100);

		if (left < 0)									//”становка левой границы
		{
			arr[i] = 0.01 * n - rand() % left;			//≈сли граница меньше 0, то сдвигаем влево
		}
		else
		{
			arr[i] = 0.01 * n + rand() % left;			//≈сли больше то вправо
		}
	}
}

template<typename T>
void print_arr(vector<T>& arr)							//¬ывод массива на экран		
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << "  ";
		if (i % 9 == 0 && i != 0)
		{
			std::cout << "\n";
		}
	}
}

template<typename T>
int count_in_range(vector<T>& arr, T left, T right)		// ол-во элементов массива наход€щиес€ в данном диапозоне
{
	if (left > arr[arr.size() - 1] || right < arr[0] || left > right)
	{
		return 0;
	}
	else
	{
		int l = find_left(arr, left);		//находим значение индекса левого границы
		int r = find_right(arr, right);		//находим значение индекса правой границы
		
		if (r == l && arr[r] <= right && arr[r] >= left)
		{
			return 1;
		}
		else
		{			
			return r - l + 1;				//возвращаем их разницу					
		}
		
	}
}

template<typename T>
int find_left(vector<T>& arr, T left_value)				//Ѕинарный поиск левого индекса
{
	int left = 0, right = arr.size() - 1;				//устанавливаем изначальные границы
	
	while (left < right)								//пока они не пересекутс€ будем искать
	{
		int mid = (left + right) / 2;					//находим центр
		
		if (arr[mid] >= left_value)						//если искомое значение больше центрального
		{
			right = mid;								//то сдвигаем правую границу
		}
		else
		{
			left = mid + 1;								//если нет, то левую
		}
	}
	return left;
}

template<typename T>
int find_right(vector<T>& arr, T right_value)			//Ѕинарный поиск правого индекса
{
	int left = 0, right = arr.size() - 1;				//устанавливаем изначальные границы

	while (left < right)								//пока они не пересекутс€ будем искать
	{	
		int mid = (left + right + 1) / 2;				//находим центр

		if (arr[mid] <= right_value)					//если искомое значение больше центрального	
		{
			left = mid;									//то сдвигаем правую границу
		}
		else
		{
			right = mid - 1;							//если нет, то левую		
		}	
	}
	return left;
}

template<typename T>
T sum_after_value(vector<T>& arr, T value)				//—умма элементов массива после заданного значени€
{	
	T summ = 0;
	if (value == arr[arr.size() - 1])					//если элемент последний, то возвращаем 0
	{
		return 0.00;
	}
	else
	{
		int i = 0;
		while (arr[i] < value)							//ƒоходим до нужного элемента
		{
			i++;
		}
		i++;
		for (; i < arr.size(); i++)
		{
			summ += arr[i];								//считаем сумму
		}
		return summ;
	}
	
}


template<typename T>
void sort_decrease_abs(vector<T>& arr)					//—ортировка массива по убыванию модулей
{
	
	for (int i = 0; i < arr.size(); i++)
	{
		int i_max = i;
		for (int j = i; j < arr.size(); j++)				//ищем индекс самого максимального числа
		{
			if (abs(arr[j]) > abs(arr[i_max]))				//если j элемент больше i_max-го элемента (по модулю), то запоминаем его
			{
				i_max = j;
			}
		}
		swap(arr[i], arr[i_max]);
	}
}

template<typename T>
void write_tofile(vector<T>& arr, ofstream& f)			//запись массива в файл
{
	for (int i = 0; i < arr.size(); i++)
	{
		f << arr[i] << "  ";
		if (i % 9 == 0 && i != 0)
		{
			f << "\n";
		}
	}
}

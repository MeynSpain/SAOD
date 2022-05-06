#pragma once
#include <exception>
#include <vector>
#include <fstream>
#include <time.h>



/// <summary>
/// Последовательный поиск по ключу
/// </summary>
/// <typeparam name="T"> Тип массива и искомого элемента </typeparam>
/// <param name="arr"> - Массив, в котором будет производиться поиск </param>
/// <param name="size"> - Размер массива </param>
/// <param name="key"> - Значение элемента, который будет искаться </param>
/// <returns>Индекс элемента в массиве</returns>
template<typename T>
int search_sequential(std::vector<T>& arr, T key);



/// <summary>
/// Бинарный поиск в массиве, массив должен быть предварительно отсортирован,
/// иначе поиск будет работать некоректно
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"> - Массив, в котором будет поиск</param>
/// <param name="size"> - размер массива</param>
/// <param name="key"> - ключ для поиска(значение, которе ищется)</param>
/// <returns> Индекс искомого элемента</returns>
template<typename T>
int search_binary(std::vector<T>& arr, T key);


/// <summary>
/// Заполняет вектор вручную
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">Имя заполняемого массива</param>
template<typename T>
void fill_hand_vector(std::vector<T>& arr);

/// <summary>
/// Заполняет вектор случайными числами
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">Имя заполняемого массива</param>
template<typename T>
void fill_rand_vector(std::vector<T>& arr);

/// <summary>
/// Выводит массив на экран
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">Массив, выводимый на экран</param>
template<typename T>
void print_vector(const std::vector<T>& arr);


/// <summary>
/// Выводит массив в текстовый файл
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">-Массив, выводимый на экран</param>
/// <param name="f">-файловая переменная, файл должен быть открыт</param>
template<typename T>
void printTofile_vector(const std::vector<T>& arr, std::ofstream& f);

///////////////////////////////////////////////////////////////////////////////////////// 

template<typename T> 
int search_sequential(std::vector<T>& arr, T key)		/// Последовательный поиск по ключу
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == key)							//Просто сверяем с ключом
		{
			return i;
		}
	}
	throw std::invalid_argument("Не удалось найти элемент!\n");
}


template<typename T>
int search_binary(std::vector<T>& arr, T key)			///Бинарный поиск
{
	int left = 0, right = arr.size() - 1;

	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;					//находим индекс центрального значения

		//И смотрим какую границу двигать, в зависимости от того с какой стороны лежит искомое значение
		if (arr[mid] >= key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (arr[left] != key)
	{
		throw std::invalid_argument("Не удалось найти нужный элемент, возможно массив был не отсортирован!\n");
	}

	return left;

}


template<typename T>
void fill_hand_vector(std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cin >> arr[i];
	}
}

template<typename T>
void fill_rand_vector(std::vector<T>& arr)
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = (rand() % 100) / (rand() % 10 + 1);
	}
}

template<typename T>
void print_vector(const std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << "  ";
		if (i > 0 && i % 9 == 0)
		{
			std::cout << "\n";
		}
	}
}

template<typename T>
void printTofile_vector(const std::vector<T>& arr, std::ofstream& f)
{
	for (int i = 0; i < arr.size(); i++)
	{
		f << arr[i] << "  ";
		if (i > 0 && i % 9 == 0)
		{
			f << "\n";
		}
	}
}
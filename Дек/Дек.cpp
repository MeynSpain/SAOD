// Дек.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <deque>
#include "Deque.h"

int main()
{
	//Выделяем память под дек
	Deque<int> d;

	//Добавляем значения в конец
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);
	d.push_back(7);

	//Добавляем значения в начало
	d.push_front(10);
	d.push_front(11);
	d.push_front(12);
	d.push_front(13);
	d.push_front(14);
	d.push_front(15);
	d.push_front(16);


	//Пройдемся и выведем значения с начала
	while (!d.empty())
	{
		cout << d.pop_front() << "\n";
	}

	
	
	
	
}


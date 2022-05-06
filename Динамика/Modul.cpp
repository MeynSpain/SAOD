#include <iostream>
#include "Modul.h"

namespace myspace {

	void fill_hand_array(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cin >> arr[i];
		}
	}

	void show_array(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << "  ";

			if (i > 0 && i % 9 == 0)		//������� �� ����� ������, ��� ������ 10� ��������
			{
				std::cout << "\n";
			}
		}
	}
}


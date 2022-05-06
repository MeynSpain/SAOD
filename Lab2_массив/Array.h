#pragma once
#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
void fill_random(vector<T>& arr, int left, int right);		//���������� ������� ���������� �������

template<typename T>
void print_arr(vector<T>& arr);								//����� ������� �� �����

template<typename T>
int count_in_range(vector<T>& arr, T left, T right);		//���-�� ��������� ������� ����������� � ������ ���������

template<typename T>
int find_left(vector<T>& arr, T left_value);				//�������� ����� ������ �������

template<typename T>
int find_right(vector<T>& arr, T right_value);				//�������� ����� ������� �������

template<typename T>
T sum_after_value(vector<T>& arr, T value);					//����� ��������� ������� ����� ��������� ��������

template<typename T>
void sort_decrease_abs(vector<T>& arr);						//���������� ������� �� �������� �������

template<typename T>
void write_tofile(vector<T>& arr, ofstream& f);		//������ ������� � ����

//////////////////////////////////////  ����������  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

template<typename T>
void fill_random(vector<T>& arr, int left, int right)	//���������� ������� ���������� �������
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); i++)
	{
		float n = rand() % (right * 100);

		if (left < 0)									//��������� ����� �������
		{
			arr[i] = 0.01 * n - rand() % left;			//���� ������� ������ 0, �� �������� �����
		}
		else
		{
			arr[i] = 0.01 * n + rand() % left;			//���� ������ �� ������
		}
	}
}

template<typename T>
void print_arr(vector<T>& arr)							//����� ������� �� �����		
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
int count_in_range(vector<T>& arr, T left, T right)		//���-�� ��������� ������� ����������� � ������ ���������
{
	if (left > arr[arr.size() - 1] || right < arr[0] || left > right)
	{
		return 0;
	}
	else
	{
		int l = find_left(arr, left);		//������� �������� ������� ������ �������
		int r = find_right(arr, right);		//������� �������� ������� ������ �������
		
		if (r == l && arr[r] <= right && arr[r] >= left)
		{
			return 1;
		}
		else
		{			
			return r - l + 1;				//���������� �� �������					
		}
		
	}
}

template<typename T>
int find_left(vector<T>& arr, T left_value)				//�������� ����� ������ �������
{
	int left = 0, right = arr.size() - 1;				//������������� ����������� �������
	
	while (left < right)								//���� ��� �� ����������� ����� ������
	{
		int mid = (left + right) / 2;					//������� �����
		
		if (arr[mid] >= left_value)						//���� ������� �������� ������ ������������
		{
			right = mid;								//�� �������� ������ �������
		}
		else
		{
			left = mid + 1;								//���� ���, �� �����
		}
	}
	return left;
}

template<typename T>
int find_right(vector<T>& arr, T right_value)			//�������� ����� ������� �������
{
	int left = 0, right = arr.size() - 1;				//������������� ����������� �������

	while (left < right)								//���� ��� �� ����������� ����� ������
	{	
		int mid = (left + right + 1) / 2;				//������� �����

		if (arr[mid] <= right_value)					//���� ������� �������� ������ ������������	
		{
			left = mid;									//�� �������� ������ �������
		}
		else
		{
			right = mid - 1;							//���� ���, �� �����		
		}	
	}
	return left;
}

template<typename T>
T sum_after_value(vector<T>& arr, T value)				//����� ��������� ������� ����� ��������� ��������
{	
	T summ = 0;
	if (value == arr[arr.size() - 1])					//���� ������� ���������, �� ���������� 0
	{
		return 0.00;
	}
	else
	{
		int i = 0;
		while (arr[i] < value)							//������� �� ������� ��������
		{
			i++;
		}
		i++;
		for (; i < arr.size(); i++)
		{
			summ += arr[i];								//������� �����
		}
		return summ;
	}
	
}


template<typename T>
void sort_decrease_abs(vector<T>& arr)					//���������� ������� �� �������� �������
{
	
	for (int i = 0; i < arr.size(); i++)
	{
		int i_max = i;
		for (int j = i; j < arr.size(); j++)				//���� ������ ������ ������������� �����
		{
			if (abs(arr[j]) > abs(arr[i_max]))				//���� j ������� ������ i_max-�� �������� (�� ������), �� ���������� ���
			{
				i_max = j;
			}
		}
		swap(arr[i], arr[i_max]);
	}
}

template<typename T>
void write_tofile(vector<T>& arr, ofstream& f)			//������ ������� � ����
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

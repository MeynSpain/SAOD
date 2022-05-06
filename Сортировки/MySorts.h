#pragma once

#include <iostream>
#include <vector>

using namespace std;


/// <summary>
/// �������� ������� ���������� ������� ������ vector
/// </summary>
/// <typeparam name="Type">int, double, char</typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
/// <param name="first">- ������ ������ ����������</param>
/// <param name="last">- ������ ����� ����������</param>
template<typename Type>
void QuickSort(vector<Type>& arr, int first, int last);


/// <summary>
/// ����������� ����������. P.S. �� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
template<typename Type>
void BubbleSort(vector<Type>& arr);

/// <summary>
/// ���������� �������. P.S. ��� ��� �������� ������, �� �� ���� �������� ���������� �� ����� ���������� �� 
/// ����������� ��� ����������� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
template<typename Type>
void SelectionSort(vector<Type>& arr);

/// <summary>
/// ���������� ���������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void InsertionSort(vector<Type>& arr);

/// <summary>
/// ���������� �����, ������� ��� ������ ������� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void ShellSort(vector<Type>& arr);









// //////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// �������� ������� ���������� ������� ������ vector
/// </summary>
/// <typeparam name="Type">int, double, char</typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
/// <param name="first">- ������ ������ ����������</param>
/// <param name="last">- ������ ����� ����������</param>
template<typename Type>
void QuickSort(vector<Type>& arr, int first, int last)
{
	if (first < last)
	{
		//��������� �� ����� � ������ ������� �������
		int left = first;
		int right = last;
		//������� ��������, ������� ����� � ������, ������ ���, ����� �� �������� ������������
		int mid = arr[left + (right - left) / 2]; 

		do
		{
			//���� �� ����� ������� ������� � ����
			//��-�, ������� ������ ����������� ��������
			while (arr[left] < mid)
			{
				left++;
			}
			//������ ���� �� ������ ������� ������� � ����
			//��-�, ������� ������ ����������� ��������
			while (arr[right] > mid)
			{
				right--;
			}

			//��� ������ �� ����� ��� ��-��, � ����� � ������ ������� �� ���������� �������
			//������ ��-�� �������
			if (left <= right)
			{
				Type buffer = arr[left];
				arr[left] = arr[right];
				arr[right] = buffer;
				//� ����������� �������
				left++;
				right--;
			}
		} while (left < right);

		//������ ����� �������� ���� ������� ��� ����� ����� ������� � ������
		QuickSort(arr, first, right);	//�����
		QuickSort(arr, left, last);	//������
	}
	else
	{
		return;
	}
}

/// <summary>
/// ����������� ����������. P.S. �� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
template<typename Type>
void BubbleSort(vector<Type>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			//���� ��������� ��-� ������ ��������, �� ������ �� �������
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/// <summary>
/// ���������� �������. P.S. ��� ��� �������� ������, �� �� ���� �������� ���������� �� ����� ���������� �� 
/// ����������� ��� ����������� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr">- ������, ������� ����� �������������</param>
template<typename Type>
void SelectionSort(vector<Type>& arr)
{
	//������� ����, � ������� ������ ��� ������ ��������
	for (int i = 0; i < arr.size() - 1; i++)
	{
		//������������� ��������� ������ ������������ ��������
		int i_min = i;
		//���������, � ������� ����� ������ �������
		for (int j = i + 1; j < arr.size(); j++)
		{
			//������� ������� � ���� ����� �������
			if (arr[j] < arr[i_min])
			{
				i_min =j;
			}
		}
		//������ ��� �������� �������
		swap(arr[i], arr[i_min]);
	}
}


/// <summary>
/// ���������� ���������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void InsertionSort(vector<Type>& arr)
{
	//�������� �� 2�� ��-��, ������ ��� ����� ���� ����� � �������� �� �������� �������
	for (int i = 1; i < arr.size(); i++)
	{
		int value = arr[i];	
		int j = i;
		while (j > 0 && arr[j - 1] > value)
		{
			//������� ��-�� ������
			arr[j] = arr[j - 1];
			j--;
		}
		//������ ��� ��-�
		arr[j] = value;
	}
}

/// <summary>
/// ���������� �����, ������� ��� ������ ������� ����������
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="arr"></param>
template<typename Type>
void ShellSort(vector<Type>& arr)
{
	int j;
	int step;
	//��� ������� �� ����� ������ ������ �� �����
	for (step = arr.size() / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arr.size(); i++)
		{
			Type buffer = arr[i];
			for ( j = i; j >= step; j -= step)
			{
				//�� � �� ���� � ���� �������� ������� �������
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

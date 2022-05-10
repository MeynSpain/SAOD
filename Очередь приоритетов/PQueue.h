#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// ����� �������, �� � ����������� �� 200 ��-�.
/// ������� ���� ������ ������� ������ ���� ���������, �� �����
/// �������������� �������� ������.
/// </summary>
/// <typeparam name="Type"></typeparam>
template<typename Type>
class PQueue
{
private:

	int count;			//���-�� ���������

	Type arr[200];		//������ ��� ��������

	/// <summary>
	/// ������� ������ ������� � ������� �� ����������
	/// </summary>
	/// <returns></returns>
	int find_first();

public:

	//�����������
	PQueue();			

	/// <summary>
	/// ������� �������� � �������
	/// </summary>
	/// <param name="item">- ����������� �������</param>
	void push(const Type& item);		

	/// <summary>
	/// ������� ������� �� ������� � ���������� ��������
	/// �� ����������
	/// </summary>
	/// <returns></returns>
	Type pop();

	/// <summary>
	/// ���������� ��-� ������� 1� � ������� �� ����������, �� �� ������� ���
	/// </summary>
	/// <returns></returns>
	Type front();

	/// <summary>
	/// ������� �������
	/// </summary>
	void clear();

	/// <summary>
	/// ������ ������� ��� ���
	/// </summary>
	/// <returns>true - ������, false - �� ������</returns>
	bool empty();

	/// <summary>
	/// ���������� ���-�� ��������� � �������
	/// </summary>
	/// <returns></returns>
	int size();

};

template<typename Type>
inline int PQueue<Type>::find_first()
{
	//����� ����� ����������� ��-�
		//������ ��������� ����������� ��������
	int i_min = 0;

	//���������� �� ������� � ������� �����������
	for (int i = 0; i < count; i++)
	{
		//���� ������� ������� ������ ������������, �� ���������� ������
		if (arr[i] < arr[i_min])
		{
			i_min = i;
		}
	}
	//���������� ��������� ��������
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
		//������� ������ ������� � �������
		int i_min = find_first();

		//�� ����� ���������� ��� ��������
		Type min = arr[i_min];

		//������ ������� ��� �������� �� �������
		arr[i_min] = arr[count - 1];
		count--;
		
		//���������� ��������� ��������
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
		//������� ������ ��� ������
		int i_min = find_first();

		//� ���������� ��� ��������
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

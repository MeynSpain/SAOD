#pragma once
#include <exception>

/// <summary>
/// ����� ������� �������.
/// ������� �� ����������� ������� �� 200 ��-�
/// </summary>
/// <typeparam name="Type"></typeparam>
template<class Type>
class SimpleQueue
{
private:

	int first;				//��������� �� ������ �������
	int last;				//��������� �� ����� �������
	int count;				//���-�� ��������� � �������
	Type arr[200];

public:

	//�������������� ������
	SimpleQueue();

	/// <summary>
	/// ������� �������� � �������
	/// </summary>
	/// <param name="item">- ����������� �������</param>
	void insert(Type& item);

	/// <summary>
	/// ���������� �������� ������� � ������� ��� �� �������
	/// </summary>
	/// <returns>�������� �������</returns>
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
			//��������������
			first = (first + 1) % 200;

			return buffer;
		}
	}

	/// <summary>
	/// ������� �������
	/// </summary>
	void clear();

	/// <summary>
	/// ���������� ������ �������
	/// </summary>
	/// <returns></returns>
	int leght();

	/// <summary>
	/// ���������� ������ �������
	/// </summary>
	/// <returns></returns>
	int size();
	
	/// <summary>
	/// ��������� ����� ������� ��� ���
	/// </summary>
	/// <returns>true - �����, false - ���</returns>
	bool empty();

	/// <summary>
	/// ���������� �������� �������� �������, �� ������ ��� �� �������
	/// </summary>
	/// <returns>�������� ��������</returns>
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
	//��������� �� ����������� �� ������
	if (count < 200)
	{
		//��������� �������
		arr[last] = item;
		//� ����������� ���-�� � ���������
		count++;
		//������ ���, ����� ������������ �������
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

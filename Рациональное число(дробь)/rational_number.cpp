#include "rational_number.h"
#include <cassert>
#include <math.h>
//////////////////////////  �����������  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

rational_number::rational_number()			//����������� �� ���������
{
	Numerator = 0;
	Denominator = 1;
}

rational_number::rational_number(int numerator, int denominator)		//����������� � �����������
{
	set_numerator(numerator);
	set_denominator(denominator);
}

rational_number::rational_number(const rational_number& number2)		//����������� �����������
{
	Numerator = number2.Numerator;
	Denominator = number2.Denominator;
}

//////////////////////////  �������  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void rational_number::set_numerator(int numerator)						//������ �������� ���������
{
	Numerator = numerator;
}

void rational_number::set_denominator(int denominator)					//������ �������� ���������
{
	assert(denominator != 0);
	if (denominator < 0)
	{
		Numerator *= -1;
		denominator *= -1;
	}
	Denominator = denominator;
}

//////////////////////////  �������  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int rational_number::get_numerator()									//������� �������� ���������
{
	return Numerator;
}

int rational_number::get_denominator()									//������� �������� �����������
{
	return Denominator;
}

std::string rational_number::info()													//��������� ������ � ������
{
	std::string str;
	str = std::to_string(Numerator) + "/" + std::to_string(Denominator);
	return str;
}

//////////////////////////  ���������  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

rational_number rational_number::operator+(const rational_number& number2)			//�������� ������
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;
	int OD;	//����� �����������
	if (Denominator != number2.Denominator)
	{
		OD = new_number.Denominator * number2.Denominator;		//����� ����� �����������
		new_number.Numerator *= number2.Denominator;			//�������� ��������� �� ����������� ������ �����
		int num = number2.Numerator;				//����� ��������� ������ �����
		num *= new_number.Denominator;
		new_number.Numerator = new_number.Numerator + num;				//���������� ���������
		new_number.Denominator = OD;
		new_number.Reduction();								//��������� �����
	}
	else
	{
		new_number.Numerator += number2.Numerator;
		new_number.Reduction();
	}
	
	return new_number;									//���������� ��������� �� ������
}

rational_number rational_number::operator-(const rational_number& number2)				//��������� ������
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	int OD;	//����� �����������
	if (Denominator != number2.Denominator)
	{
		OD = new_number.Denominator * number2.Denominator;		//����� ����� �����������
		new_number.Numerator *= number2.Denominator;			//�������� ��������� �� ����������� ������ �����
		int num = number2.Numerator;							//����� ��������� ������ �����
		num *= new_number.Denominator;
		new_number.Numerator = new_number.Numerator - num;		//�������� ���������
		new_number.Denominator = OD;
		new_number.Reduction();											//��������� �����
	}
	else
	{
		new_number.Numerator -= number2.Numerator;
		new_number.Reduction();
	}

	return new_number;											//���������� ��������� �� ������
}

rational_number rational_number::operator*(const rational_number& number2)		//��������� ������
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	new_number.Numerator *= number2.Numerator;					//���������*���������
	new_number.Denominator *= number2.Denominator;				//�����������*�����������

	new_number.Reduction();												//���������

	return new_number;											//���������� ��������� �� ������
}

rational_number rational_number::operator/(const rational_number& number2)
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	//��������� �� ������������ �����
	new_number.Numerator *= number2.Denominator;
	new_number.Denominator *= number2.Numerator;

	new_number.Reduction();

	return new_number;									//���������� ��������� �� ������
}

void rational_number::operator=(const rational_number& number2)					//�������� ������������
{
	Numerator = number2.Numerator;
	Denominator = number2.Denominator;	
}


bool rational_number::operator==(rational_number number2)						//����������� ������
{
	Reduction();
	number2.Reduction();
	if (Numerator == number2.Numerator && Denominator == number2.Denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void rational_number::Reduction()												//���������� �����
{
	int i;
	int num = abs(Numerator);
	int den = abs(Denominator);
	
	if (num > den)
	{
		i = den;
	}
	else
	{
		i = num;
	}

	for (; i >= 1; i--)
	{
		if (Numerator % i == 0 && Denominator % i == 0)
		{
			Numerator /= i;
			Denominator /= i;
		}
	}

	/*
	if (Numerator != 0)
	{
		int m = Denominator,
			n = Numerator,
			ost = m % n;
		// ���������� ���(���������, �����������)
		// ���������� �������
		while (ost != 0)
		{
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1)
		{
			Numerator /= nod; Denominator /= nod;
		}
	}
	*/

}


#include "rational_number.h"
#include <cassert>
#include <math.h>
//////////////////////////  Кострукторы  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

rational_number::rational_number()			//Конструктор по умолчанию
{
	Numerator = 0;
	Denominator = 1;
}

rational_number::rational_number(int numerator, int denominator)		//Конструктор с параметрами
{
	set_numerator(numerator);
	set_denominator(denominator);
}

rational_number::rational_number(const rational_number& number2)		//Конструктор копирования
{
	Numerator = number2.Numerator;
	Denominator = number2.Denominator;
}

//////////////////////////  Сеттеры  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void rational_number::set_numerator(int numerator)						//Задать значение числителя
{
	Numerator = numerator;
}

void rational_number::set_denominator(int denominator)					//Задать значение числителя
{
	assert(denominator != 0);
	if (denominator < 0)
	{
		Numerator *= -1;
		denominator *= -1;
	}
	Denominator = denominator;
}

//////////////////////////  Геттеры  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int rational_number::get_numerator()									//Вернуть значение числителя
{
	return Numerator;
}

int rational_number::get_denominator()									//Вернуть значение знаменателя
{
	return Denominator;
}

std::string rational_number::info()													//Возращает строку с числом
{
	std::string str;
	str = std::to_string(Numerator) + "/" + std::to_string(Denominator);
	return str;
}

//////////////////////////  Операторы  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

rational_number rational_number::operator+(const rational_number& number2)			//Сложение дробей
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;
	int OD;	//общий знаменатель
	if (Denominator != number2.Denominator)
	{
		OD = new_number.Denominator * number2.Denominator;		//Нашли общий знаменатель
		new_number.Numerator *= number2.Denominator;			//Умножили числитель на знаменатель правой дроби
		int num = number2.Numerator;				//Берем числитель правой дроби
		num *= new_number.Denominator;
		new_number.Numerator = new_number.Numerator + num;				//Складываем числители
		new_number.Denominator = OD;
		new_number.Reduction();								//Сокращаем дробь
	}
	else
	{
		new_number.Numerator += number2.Numerator;
		new_number.Reduction();
	}
	
	return new_number;									//Возвращаем указатель на объект
}

rational_number rational_number::operator-(const rational_number& number2)				//Вычитание дробей
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	int OD;	//общий знаменатель
	if (Denominator != number2.Denominator)
	{
		OD = new_number.Denominator * number2.Denominator;		//Нашли общий знаменатель
		new_number.Numerator *= number2.Denominator;			//Умножили числитель на знаменатель правой дроби
		int num = number2.Numerator;							//Берем числитель правой дроби
		num *= new_number.Denominator;
		new_number.Numerator = new_number.Numerator - num;		//Вычитаем числители
		new_number.Denominator = OD;
		new_number.Reduction();											//Сокращаем дробь
	}
	else
	{
		new_number.Numerator -= number2.Numerator;
		new_number.Reduction();
	}

	return new_number;											//Возвращаем указатель на объект
}

rational_number rational_number::operator*(const rational_number& number2)		//Умножение дробей
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	new_number.Numerator *= number2.Numerator;					//Числитель*Числитель
	new_number.Denominator *= number2.Denominator;				//Знаменатель*Знаменатель

	new_number.Reduction();												//Сокращаем

	return new_number;											//Возвращаем указатель на объект
}

rational_number rational_number::operator/(const rational_number& number2)
{
	rational_number new_number;
	new_number.Numerator = Numerator;
	new_number.Denominator = Denominator;

	//Умножение на перевернутую дробь
	new_number.Numerator *= number2.Denominator;
	new_number.Denominator *= number2.Numerator;

	new_number.Reduction();

	return new_number;									//Возвращаем указатель на объект
}

void rational_number::operator=(const rational_number& number2)					//Оператор присваивания
{
	Numerator = number2.Numerator;
	Denominator = number2.Denominator;	
}


bool rational_number::operator==(rational_number number2)						//Сравнивание дробей
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

void rational_number::Reduction()												//Сокращение дроби
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
		// вычисление НОД(числитель, знаменатель)
		// алгоритмом Евклида
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


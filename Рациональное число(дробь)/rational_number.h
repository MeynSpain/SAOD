#pragma once
#include <string>
class rational_number
{
	//Поля
private:
	int Numerator;				//Числитель
	int Denominator;			//Знаменатель

public:
	//Конструкторы
	rational_number();			//Конструктор по умолчанию

	rational_number(int Numerator, int Denominator);	//Конструктор с параметрами

	rational_number(const rational_number& number2);	//Конструктор копирования

//Сеттеры
	void set_numerator(int numerator);					//Задать значение числителя

	void set_denominator(int denominator);				//Задать значение числителя

//Геттеры
	int get_numerator();								//Вернуть значение числителя

	int get_denominator();								//Вернуть значение знаменателя

	std::string info();									//Возращает строку с числом

//Операторы

	rational_number operator + (const rational_number& number2);	//Сложение дробей

	rational_number operator - (const rational_number& number2);	//Вычитание дробей

	rational_number operator * (const rational_number& number2);	//Умножение дробей

	rational_number operator / (const rational_number& number2);	//Деление дробей

	void operator = (const rational_number& number2);				//Оператор присваивания(Копирует все значения

	bool operator == (rational_number number2);						//Сравнивание дробей

public:
	void Reduction();												//Сокращение дроби
};



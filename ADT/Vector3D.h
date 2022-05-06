#pragma once
#include <iostream>
#include <vector>
//Класс вектор в 3х мерном пространстве
//Имеющий поля координат(x,y,z) и модуль(длина) вектора abs
//
class Vector3D
{
private:
//Координаты вектора в полярынх координатах
	double r;
	double zenith;
	double azimuth;
	const double pi = acos(-1);

//Координаты вектора в декартовых координатах
	double X;
	double Y;
	double Z;

//Модуль(длина) вектора
	double abs;

public:
//Конструкторы
	Vector3D();									//Конструктор по умолчанию (все поля равны 0)

	Vector3D(double r, double zenith, double azimuth); //Конструктор с параметрами

	Vector3D(const Vector3D& vector2);			//Конструктор копирования(копирует значения vector2 в этот)
//Сеттеры

	//Полярные
	void set_r(double r);						//Задает расстояние

	void set_zenith(double zenith);				//Задает зенит

	void set_azimuth(double azimuth);			//Задает азимут

	void set_all(double r, double zenith, double azimuth);	//Задает сразу все координаты

/*	//Декартовы
	void set_x(double x);						//Задает координату X

	void set_y(double y);						//Задает координату Y

	void set_z(double z);						//Задает координату Y

	void set_all(double x, double y, double z);	//Задает все координаты
*/

//Вычисление модуля(длины)
private:
	void set_abs();								//Задает значение молудя(длины) вектора

//Геттеры
public:

	double get_r() const;						//Возвращает r

	double get_zenith() const;					//Возвращает zenith

	double get_azimuth() const;					//Возвращает azimuth

	double get_abs() const;						//Возвращает abs

	double get_x() const;						//Возвращает X

	double get_y() const;						//Возвращает Y

	double get_z() const;						//Возвращает Z

	std::vector<double> get_dekart_vector() const; //Возвращает декартовый вектор

	std::string information() const;			//Возвращает строку с данными о векторе

//Перевод координат
private:
	void polar_in_dekart();						//Перевод полярных координат в декартовые

	void dekart_in_polar();						//Перевод декартовых координат в полярные

//Операторы
public:
	Vector3D operator * (double value);			//Умножение вектора на число

	Vector3D operator = (const Vector3D& vector2); //Копирует правый вектор в левый

	bool operator == (const Vector3D& vector2);
	
};


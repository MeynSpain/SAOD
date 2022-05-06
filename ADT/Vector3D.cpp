#include <math.h>
#include <cassert>
#include "Vector3D.h"
#include <string>



/////////////////////////////////////////    Конструкторы    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

Vector3D::Vector3D()			//Конструктор по умолчанию (все поля равны 0)
{
	r = 0;
	zenith = 0;
	azimuth = 0;
	X = 0;
	Y = 0;
	Z = 0;
	abs = 0;
}

Vector3D::Vector3D(double r, double zenith, double azimuth)		//Конструктор с параметрами
{
	set_r(r);
	set_zenith(zenith);
	set_azimuth(azimuth);
	set_abs();
	//set_x(x);
	//set_y(y);
	//set_z(z);
	
}

Vector3D::Vector3D(const Vector3D& vector2)				//Конструктор копирования(копирует значения vector2 в этот)
{
	this->r = vector2.r;
	this->zenith = vector2.zenith;
	this->azimuth = vector2.azimuth;
	this->X = vector2.X;
	this->Y = vector2.Y;
	this->Z = vector2.Z;
	this->abs = vector2.abs;
}

void Vector3D::set_r(double r)							//Задает расстояние
{
	assert(r >= 0);
	this->r = r;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_zenith(double zenith)				//Задает зенит
{
	assert(zenith >= 0 && zenith <= 180);
	this->zenith = zenith;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_azimuth(double azimuth)				//Задает азимут
{
	assert(azimuth >= 0 && azimuth < 360);
	this->azimuth = azimuth;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_all(double r, double zenith, double azimuth) // Задает сразу все координаты
{
	set_r(r);
	set_zenith(zenith);
	set_azimuth(azimuth);
	polar_in_dekart();
	set_abs();
}

/////////////////////////////////////////   Сеттеры   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
void Vector3D::set_x(double x)							//Задает координату X
{
	X = x;
	set_abs();
}

void Vector3D::set_y(double y)							//Задает координату Y
{
	Y = y;
	set_abs();
}

void Vector3D::set_z(double z)							//Задает координату Z
{
	Z = z;
	set_abs();
}

void Vector3D::set_all(double x, double y, double z)	//Задает все координаты
{
	X = x;
	Y = y;
	Z = z;
	//set_x(x);
	//set_y(y);
	//set_z(z);
	set_abs();

}

*/

//Вычисление модуля(длины)
void Vector3D::set_abs()								//Задает значение молудя(длины) вектора
{
	abs = sqrt(X * X + Y * Y + Z * Z);
}

double Vector3D::get_r() const
{
	return r;
}

double Vector3D::get_zenith() const
{
	return zenith;
}

double Vector3D::get_azimuth() const
{
	return azimuth;
}


/////////////////////////////////////////   Геттеры    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

double Vector3D::get_x() const							//Возвращает X
{
	return X;
}

double Vector3D::get_y() const							//Возвращает Y
{
	return Y;
}

double Vector3D::get_z() const							//Возвращает Z
{
	return Z;
}

double Vector3D::get_abs() const						//Возвращает abs
{
	return abs;
}

std::vector<double> Vector3D::get_dekart_vector() const	//Возвращает декартовый вектор
{
	std::vector<double> dekart(3);
	dekart[1] = X;
	dekart[2] = Y;
	dekart[3] = Z;
	return dekart;
}

std::string Vector3D::information() const				//Возвращает строку с данными о векторе
{
	std::string str;
	str = "Dekart:\n(" + 
		   std::to_string(X) + ", " + std::to_string(Y) + ", " + std::to_string(Z) + ")\n";
	str += "abs = " + std::to_string(abs) + "\n";
	str += "Polar:\n(" +
			std::to_string(r) + ", " + std::to_string(zenith) + ", " + std::to_string(azimuth) + ")\n";
	return str;
}

/////////////////////////////////////////   Перевод из системы в систему    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Vector3D::polar_in_dekart()						//Перевод из полярных координат в декартовые
{
	X = r * sin(zenith * pi / 180) * cos(azimuth * pi / 180);
	Y = r * sin(zenith * pi / 180) * sin(zenith * pi / 180);
	Z = r * cos(zenith * pi / 180);
}

void Vector3D::dekart_in_polar()						//Перевод декартовых координат в полярные
{
	r = sqrt(X * X + Y * Y + Z * Z);
	zenith = acos(Z / sqrt(X * X + Y * Y + Z * Z));
	azimuth = atan(Y / X);
}

/////////////////////////////////////////   Операторы    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

Vector3D Vector3D::operator*(double value)				//Умножение вектора на число
{
	assert(value != 0);		//Множитель должен быть не равен 0
	X *= value;				
	Y *= value;				//Умножаем все координаты на число
	Z *= value;
	set_abs();				//И вычисляем новую длину вектора
	dekart_in_polar();
	return *this;
}

Vector3D Vector3D::operator=(const Vector3D& vector2)	//Копирует правый вектор в левый
{
	this->r = vector2.r;
	this->zenith = vector2.zenith;
	this->azimuth = vector2.azimuth;
	this->X = vector2.X;
	this->Y = vector2.Y;
	this->Z = vector2.Z;
	this->abs = vector2.abs;
	return *this;
}

bool Vector3D::operator==( const Vector3D& vector2)
{
	if (
		X == vector2.get_x() && 
		Y == vector2.get_y() &&
		Z == vector2.get_z() &&
		abs == vector2.get_abs()
		)
		return true;
	else
		return false;
}




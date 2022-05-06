#include <math.h>
#include <cassert>
#include "Vector3D.h"
#include <string>



/////////////////////////////////////////    ������������    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

Vector3D::Vector3D()			//����������� �� ��������� (��� ���� ����� 0)
{
	r = 0;
	zenith = 0;
	azimuth = 0;
	X = 0;
	Y = 0;
	Z = 0;
	abs = 0;
}

Vector3D::Vector3D(double r, double zenith, double azimuth)		//����������� � �����������
{
	set_r(r);
	set_zenith(zenith);
	set_azimuth(azimuth);
	set_abs();
	//set_x(x);
	//set_y(y);
	//set_z(z);
	
}

Vector3D::Vector3D(const Vector3D& vector2)				//����������� �����������(�������� �������� vector2 � ����)
{
	this->r = vector2.r;
	this->zenith = vector2.zenith;
	this->azimuth = vector2.azimuth;
	this->X = vector2.X;
	this->Y = vector2.Y;
	this->Z = vector2.Z;
	this->abs = vector2.abs;
}

void Vector3D::set_r(double r)							//������ ����������
{
	assert(r >= 0);
	this->r = r;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_zenith(double zenith)				//������ �����
{
	assert(zenith >= 0 && zenith <= 180);
	this->zenith = zenith;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_azimuth(double azimuth)				//������ ������
{
	assert(azimuth >= 0 && azimuth < 360);
	this->azimuth = azimuth;
	polar_in_dekart();
	set_abs();
}

void Vector3D::set_all(double r, double zenith, double azimuth) // ������ ����� ��� ����������
{
	set_r(r);
	set_zenith(zenith);
	set_azimuth(azimuth);
	polar_in_dekart();
	set_abs();
}

/////////////////////////////////////////   �������   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
void Vector3D::set_x(double x)							//������ ���������� X
{
	X = x;
	set_abs();
}

void Vector3D::set_y(double y)							//������ ���������� Y
{
	Y = y;
	set_abs();
}

void Vector3D::set_z(double z)							//������ ���������� Z
{
	Z = z;
	set_abs();
}

void Vector3D::set_all(double x, double y, double z)	//������ ��� ����������
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

//���������� ������(�����)
void Vector3D::set_abs()								//������ �������� ������(�����) �������
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


/////////////////////////////////////////   �������    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

double Vector3D::get_x() const							//���������� X
{
	return X;
}

double Vector3D::get_y() const							//���������� Y
{
	return Y;
}

double Vector3D::get_z() const							//���������� Z
{
	return Z;
}

double Vector3D::get_abs() const						//���������� abs
{
	return abs;
}

std::vector<double> Vector3D::get_dekart_vector() const	//���������� ���������� ������
{
	std::vector<double> dekart(3);
	dekart[1] = X;
	dekart[2] = Y;
	dekart[3] = Z;
	return dekart;
}

std::string Vector3D::information() const				//���������� ������ � ������� � �������
{
	std::string str;
	str = "Dekart:\n(" + 
		   std::to_string(X) + ", " + std::to_string(Y) + ", " + std::to_string(Z) + ")\n";
	str += "abs = " + std::to_string(abs) + "\n";
	str += "Polar:\n(" +
			std::to_string(r) + ", " + std::to_string(zenith) + ", " + std::to_string(azimuth) + ")\n";
	return str;
}

/////////////////////////////////////////   ������� �� ������� � �������    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Vector3D::polar_in_dekart()						//������� �� �������� ��������� � ����������
{
	X = r * sin(zenith * pi / 180) * cos(azimuth * pi / 180);
	Y = r * sin(zenith * pi / 180) * sin(zenith * pi / 180);
	Z = r * cos(zenith * pi / 180);
}

void Vector3D::dekart_in_polar()						//������� ���������� ��������� � ��������
{
	r = sqrt(X * X + Y * Y + Z * Z);
	zenith = acos(Z / sqrt(X * X + Y * Y + Z * Z));
	azimuth = atan(Y / X);
}

/////////////////////////////////////////   ���������    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

Vector3D Vector3D::operator*(double value)				//��������� ������� �� �����
{
	assert(value != 0);		//��������� ������ ���� �� ����� 0
	X *= value;				
	Y *= value;				//�������� ��� ���������� �� �����
	Z *= value;
	set_abs();				//� ��������� ����� ����� �������
	dekart_in_polar();
	return *this;
}

Vector3D Vector3D::operator=(const Vector3D& vector2)	//�������� ������ ������ � �����
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




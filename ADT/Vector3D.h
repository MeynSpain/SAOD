#pragma once
#include <iostream>
#include <vector>
//����� ������ � 3� ������ ������������
//������� ���� ���������(x,y,z) � ������(�����) ������� abs
//
class Vector3D
{
private:
//���������� ������� � �������� �����������
	double r;
	double zenith;
	double azimuth;
	const double pi = acos(-1);

//���������� ������� � ���������� �����������
	double X;
	double Y;
	double Z;

//������(�����) �������
	double abs;

public:
//������������
	Vector3D();									//����������� �� ��������� (��� ���� ����� 0)

	Vector3D(double r, double zenith, double azimuth); //����������� � �����������

	Vector3D(const Vector3D& vector2);			//����������� �����������(�������� �������� vector2 � ����)
//�������

	//��������
	void set_r(double r);						//������ ����������

	void set_zenith(double zenith);				//������ �����

	void set_azimuth(double azimuth);			//������ ������

	void set_all(double r, double zenith, double azimuth);	//������ ����� ��� ����������

/*	//���������
	void set_x(double x);						//������ ���������� X

	void set_y(double y);						//������ ���������� Y

	void set_z(double z);						//������ ���������� Y

	void set_all(double x, double y, double z);	//������ ��� ����������
*/

//���������� ������(�����)
private:
	void set_abs();								//������ �������� ������(�����) �������

//�������
public:

	double get_r() const;						//���������� r

	double get_zenith() const;					//���������� zenith

	double get_azimuth() const;					//���������� azimuth

	double get_abs() const;						//���������� abs

	double get_x() const;						//���������� X

	double get_y() const;						//���������� Y

	double get_z() const;						//���������� Z

	std::vector<double> get_dekart_vector() const; //���������� ���������� ������

	std::string information() const;			//���������� ������ � ������� � �������

//������� ���������
private:
	void polar_in_dekart();						//������� �������� ��������� � ����������

	void dekart_in_polar();						//������� ���������� ��������� � ��������

//���������
public:
	Vector3D operator * (double value);			//��������� ������� �� �����

	Vector3D operator = (const Vector3D& vector2); //�������� ������ ������ � �����

	bool operator == (const Vector3D& vector2);
	
};


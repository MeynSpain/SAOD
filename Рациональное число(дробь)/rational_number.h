#pragma once
#include <string>
class rational_number
{
	//����
private:
	int Numerator;				//���������
	int Denominator;			//�����������

public:
	//������������
	rational_number();			//����������� �� ���������

	rational_number(int Numerator, int Denominator);	//����������� � �����������

	rational_number(const rational_number& number2);	//����������� �����������

//�������
	void set_numerator(int numerator);					//������ �������� ���������

	void set_denominator(int denominator);				//������ �������� ���������

//�������
	int get_numerator();								//������� �������� ���������

	int get_denominator();								//������� �������� �����������

	std::string info();									//��������� ������ � ������

//���������

	rational_number operator + (const rational_number& number2);	//�������� ������

	rational_number operator - (const rational_number& number2);	//��������� ������

	rational_number operator * (const rational_number& number2);	//��������� ������

	rational_number operator / (const rational_number& number2);	//������� ������

	void operator = (const rational_number& number2);				//�������� ������������(�������� ��� ��������

	bool operator == (rational_number number2);						//����������� ������

public:
	void Reduction();												//���������� �����
};



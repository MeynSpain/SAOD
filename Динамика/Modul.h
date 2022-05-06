#pragma once


/// <summary>
/// ��� ����������� ����, � ������� ����� ��������� �������, ����� �������� � ��� ������
/// ����� �������� myspace::���_�������, ��������
/// myspace::fill_hand_array(arr, 10); 
/// ���� ����� ��������� ���������� ������������ ���� ��� ��� ���:
/// using namespace myspace;
/// </summary>
namespace myspace {	
					

	/// <summary>
	/// ��������� ������ �������
	/// </summary>
	/// <param name="arr">����������� ������</param>
	/// /// <param name="size">������ �������</param>
	void fill_hand_array(int* arr, int size);


	/// <summary>
	/// ������� ������ � �������
	/// </summary>
	/// <param name="arr">��� �������</param>
	/// /// <param name="size">������ �������</param>
	void show_array(int* arr, int size);
}



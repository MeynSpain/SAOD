// Динамика.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <algorithm>
#include "Modul.h"
typedef long long ll;

using namespace std;


/// <summary>
/// Функция треугольник паскаля возвращает 2-мерный вектор , который является треугольником паскаля
/// </summary>
/// <param name="size"> Кол-во строк, которое будет содержать треугольник паскаля</param>
/// <returns></returns>
vector<vector<ll>> pascals_triangle(int size);

/// <summary>
/// Выводит 2-мерный вектор на экран
/// </summary>
/// <param name="arr"> Вектор, который надо вывести на экран </param>
void print_matrix(const vector<vector<ll>>& arr);

/// <summary>
/// Выводит 2-мерный вектор в текстовый файл
/// </summary>
/// <param name="arr"> Вектор, который надо вывести в текстовый файл </param>
/// <param name="f"> файловая переменная связанная с файлом, в который вы хотите вывести. Файл, должен быть уже открыт </param>
void print_matrix_to_file(vector<vector<ll>> arr, ofstream& f);





int main()
{
    //Примеры для Алины
    
    //Обычный динамический массив
    int* arr_ex = new int[10];

    myspace::fill_hand_array(arr_ex, 10);    //заполнение вручную
    myspace::show_array(arr_ex, 10);         //вывод на экран
   
    //Как создать динамическую матрицу
    int** matrix = new int* [5];    //Выделяем память под строку с указателями на столбцы
    for (int i = 0; i < 5; i++)      //Пробегаемся по этой строке
    {
        matrix[i] = new int[10];    //и выделяем память под 10 столбцов в каждой строке
    }


    //Примеры с классов vector
    vector<int> arr(10);

    arr.push_back(24);
    arr.push_back(12);
    arr.resize(0);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 20;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }

    //Один из способов создать матрицу с помошью вектора
    vector<vector<int>> mtr(10);
    for (int i = 0; i < mtr.size(); i++)
    {
        mtr[i].resize(5);
    }

    //Начало нормальной программы

    system("chcp 1251");

    ofstream f("result.txt");

    cout << "Введите кол-во строк, которое вы хотите увидеть в треугольнике Паскаля:";
    int row;
    cin >> row;

    f << "Введите кол-во строк, которое вы хотите увидеть в треугольнике Паскаля:";
    f << row << "\n";

    vector<vector<ll>> a = pascals_triangle(row); //Считаем треугольник

    print_matrix(a);                              //Выводим на экран
    print_matrix_to_file(a, f);                   //Выводим в текстовик  

    f.close();                                    //Закрываем файл


}

vector<vector<ll>> pascals_triangle(int size)
{
    vector<vector<ll>> dp(size);                        //Выделяем память под матрицу(пока что только строки)

    for (int i = 0; i < size; i++)                      //Начинаем с 1-й строки
    {
        for (int j = 0; j <= i; j++)                    //и 1-го столбца
        {
            dp[i].resize(i + 1);                        //Теперь выделяем память под столбцы

            if (i == j || j == 0)                       //Смотрим является ли элемент первым в строке или стоит на главной диагонали
            {
                dp[i][j] = 1;                           //если да, то с
            }
            else                                        //В противном случае считаем, берем 2 верхник элемента и складываем
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
    return dp;
}

void print_matrix(const vector<vector<ll>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}

void print_matrix_to_file(vector<vector<ll>> arr, ofstream& f)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            f << arr[i][j] << "  ";
        }
        f << "\n";
    }
}
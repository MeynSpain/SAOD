// Сортировка очередью.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "SimpleQueue.h"

using namespace std;


/// <summary>
/// Заполняет массив случайными числами
/// </summary>
/// <param name="arr"></param>
/// <param name="count">число разрядов</param>
void random(vector<int>& arr, int count);

/// <summary>
/// Вывод массива на экран
/// </summary>
/// <param name="arr"></param>
void print_arr(vector<int>& arr);

/// <summary>
/// Вывод массива в файл
/// </summary>
/// <param name="arr"></param>
void txt_arr(vector<int>& arr, ofstream& f);

/// <summary>
/// Распределяет числа по очередям разрядов
/// </summary>
/// <param name="numbers">- массив чисел</param>
/// <param name="digits">- массив очередей(разрядов)</param>
/// <param name="digit">- разряд по которому будет распределение</param>
void Distribute(vector<int>& numbers, vector<SimpleQueue<int>>& digits, int digit);

/// <summary>
/// Записывает числа обратно из очередей в массив
/// </summary>
/// <param name="digits">- массив очередей разрядов</param>
/// <param name="numbers">- массив чисел для записи</param>
void Collect(vector<SimpleQueue<int>>& digits, vector<int>& numbers);

int main()
{
    system("chcp 1251");
    ofstream f("result.txt");
    //Массив очередей для сортировки
    vector<SimpleQueue<int>> arr_digit(10);
    
    //Массив на случайных чисел
    vector<int> arr(50);        

    int count_digits;

    cout << "Введите кол-во разрядов:";
    cin >> count_digits;

    f << "Введите кол-во разрядов:" << count_digits << "\n";
    
    random(arr, count_digits);

    print_arr(arr);
    txt_arr(arr, f);

    for (int i = 1; i <= count_digits; i++)
    {
        Distribute(arr, arr_digit, i);
        Collect(arr_digit, arr);
    }

    cout << "\nПосле сортировки:\n";
    print_arr(arr);

    f << "\nПосле сортировки:\n";
    txt_arr(arr, f);
   
}

void random(vector<int>& arr, int count)
{
    srand(time(NULL));
    //это чтобы правильно взять кол-во разрядов, чтобы все числа были одинаковой длины
    int a = (int)pow(10, count) - (int)pow(10, count - 1);
    int b = (int)pow(10, count - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % a + b ;
        //arr[i] = rand() % a;
    }
}


void print_arr(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
        if (i > 0 && i % 10 == 9)
            cout << "\n";
    }
}

void txt_arr(vector<int>& arr, ofstream& f)
{
    for (int i = 0; i < arr.size(); i++ )
    {
        f << arr[i] << "  ";
        if (i > 0 && i % 10 == 9)
            f << "\n";
    }
}

void Distribute(vector<int>& numbers, vector<SimpleQueue<int>>& digits, int digit)
{
    int mod = (int)pow(10, digit);
    int div = (int)pow(10, digit - 1);

    //Пройдемся по массиву чисел и распределим их по очередям  
    for (int i = 0; i < numbers.size(); i++)
    {
        //Опрелеяем в какую очередь положить и кладем
        digits[numbers[i] % mod / div].insert(numbers[i]);
    }
}

void Collect(vector<SimpleQueue<int>>& digits, vector<int>& numbers)
{
    int j = 0;
    //Пробегаемся по массиву очередей
    for (int i = 0; i < digits.size(); i++)
    {
        //Пока очередь не опустеет
        //записываем все обратно в массив
        
        while (!digits[i].empty())
        {
            numbers[j] = digits[i].delet();
            //cout << j << ")" << numbers[j] << "\n";
            j++;
        }
    }
}

#include <iostream>
#include <vector>
#include <algorithm>                //Для быстрой сортировки
#include <chrono>                   //для замера времени
#include <fstream>                  //файлы
#include "Array.h"

using namespace std;


int main()
{
    auto start_program = chrono::high_resolution_clock::now();    //время начала работы программы

    ofstream write("Result.txt");       //файлик с результатом



    system("chcp 1251");                //русский язык

    cout << "Введите размер массива:";
    write << "Введите размер массива:";
    int size;
    cin >> size;
    write << size << "\n";
    vector<float> arr(size);            //создаем массив на size элементов
    
    fill_random(arr, -5, 10);           //заполняем случайными числами
    print_arr(arr);                     //выводим на экран
    write_tofile(arr, write);           //и в файл

    vector<float> arr_copy(size);       //создаем копию массива
    arr_copy = arr;                     
    cout << "\nОтсортированный массив:\n";
    write << "\nОтсортированный массив:\n";
    sort(arr.begin(), arr.end());       //сортируем

    print_arr(arr);                     //выводим на экран
    write_tofile(arr, write);           //и в файл

    ////////////////////////////  Поиск в диапозоне  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    cout << "\n\nВведите диапазон поиска\nВведите левую границу поиска:";
    write << "\n\nВведите диапазон поиска\nВведите левую границу поиска:";
    float left;
    cin >> left;
    write << left << "\n";
    cout << "Введите правую границу поиска:";
    write << "Введите правую границу поиска:";
    float right;
    cin >> right;
    write << right << "\n";

    cout << "\nКол-во элементов находящихся в данном диапазоне:";
    write << "\nКол-во элементов находящихся в данном диапазоне:";

    cout << "\nИндекс левой границы:" << find_left(arr,left);
    cout << "\nИндекс правой границы:" << find_right(arr, right);
    cout << "\nКол-во элементов внутри заданного диапазона:" << count_in_range(arr, left, right);

    write << "\nИндекс левой границы:" << find_left(arr, left);
    write << "\nИндекс правой границы:" << find_right(arr, right);
    write << "\nКол-во элементов внутри заданного диапазона:" << count_in_range(arr, left, right);

    ////////////////////////////  Сумма эл-в после максимального  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    cout << "\n\nТ.к. массив отсортирован, то сумма элементов после максимального равна 0,\n" <<
            "но если брать массив до сортировки, то вот:\n";
    write << "\n\nТ.к. массив отсортирован, то сумма элементов после максимального равна 0,\n" <<
            "но если брать массив до сортировки, то вот:\n";

    auto start = chrono::high_resolution_clock::now();                  //замеряем время выполнения функции суммирования(начало работы ф-ии
    float summ = sum_after_value(arr_copy, arr[arr.size() - 1]);        //суммируем
    auto end = chrono::high_resolution_clock::now();                  //конец работы ф-ии

    chrono::duration<float>  duration = end - start;
    cout << "Сумма элементов после максимального значения:" << summ ;  //передаем неотсортированный массив и значение последнего элемента в отсортированном массиве, тк оно максимальное 
    write << "Сумма элементов после максимального значения:" << summ;
    printf_s("\nВремя работы ф - ии суммирования :%.7f", duration.count());
    write << "\nВремя работы ф - ии суммирования :" << duration.count();
    
    cout << "\n\nСортировка по убыванию модулей:\n";
    write << "\n\nСортировка по убыванию модулей:\n";
    sort_decrease_abs(arr);
    print_arr(arr);
    write_tofile(arr, write);
    auto end_program = chrono::high_resolution_clock::now();            //время конца работы программы
    duration = end_program - start_program;                             //вычитаем из времени конца работы программы, начало, таким образом находим время работы
    cout << "\nВремя работы:" << duration.count();
    write << "\nВремя работы:" << duration.count();
}



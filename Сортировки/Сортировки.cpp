// Сортировки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <time.h>
#include <fstream>
#include "MySorts.h"

using namespace std;


/// <summary>
/// Вывовд массива на экран
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
template<typename T>
void print_arr(vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
        if (i > 0 && i % 14 == 0)
        {
            cout << "\n";
        }
    }
}

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    ofstream f("result.txt");

    vector<int> arr(5000);
    
    cout << "Проверка идет на массиве размером в 5000 элементов и после каждой сортировки\nмассив заполняется новыми значениями\n";

    f << "Проверка идет на массиве размером в 5000 элементов и после каждой сортировки\nмассив заполняется новыми значениями\n";

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }

    //Замеряем время для сортировки
    //Пузырьком
    auto start = chrono::high_resolution_clock::now();

    BubbleSort(arr);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> count = end - start;

    cout << "Время сортировки пузырьком:" << count.count() << "\n";
    f    << "Время сортировки пузырьком:" << count.count() << "\n";


    //Замеряем время для сортировки
    //Выбором

    //Перегрузим массив
    arr.clear();
    arr.resize(5000);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }

    start = chrono::high_resolution_clock::now();

    SelectionSort(arr);

    end = chrono::high_resolution_clock::now();

    count = end - start;

    cout << "Время сортировки выбором:" << count.count() << "\n";
    f    << "Время сортировки выбором:" << count.count() << "\n";


    //Замеряем время для сортировки
    //Вставками

    //Перегрузим массив
    arr.clear();
    arr.resize(5000);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }

    start = chrono::high_resolution_clock::now();

    InsertionSort(arr);

    end = chrono::high_resolution_clock::now();

    count = end - start;

    cout << "Время сортировки вставками:" << count.count() << "\n";
    f    << "Время сортировки вставками:" << count.count() << "\n";


    //Замеряем время для сортировки
    //Быстрой сортировки

    //Перегрузим массив
    arr.clear();
    arr.resize(5000);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }

    start = chrono::high_resolution_clock::now();

    QuickSort(arr, 0, arr.size() - 1);

    end = chrono::high_resolution_clock::now();

    count = end - start;

    cout << "Время быстрой сортировки:" << count.count() << "\n";
    f    << "Время быстрой сортировки:" << count.count() << "\n";

    //Замеряем время для сортировки
    //Шелла

    //Перегрузим массив
    arr.clear();
    arr.resize(5000);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10000 - 5000;
    }

    start = chrono::high_resolution_clock::now();

    ShellSort(arr);

    end = chrono::high_resolution_clock::now();

    count = end - start;

    cout << "Время сортировки Шелла:" << count.count() << "\n";
    f    << "Время сортировки Шелла:" << count.count() << "\n";


   


}

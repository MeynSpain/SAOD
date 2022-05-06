// Lab3_рекурсия.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <exception>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;

long long iteration(int* arr, int size) //Произведение элементов массива с помощью итераций
{
    long long itog = arr[0];

    for (int i = 1; i < size; i++)      //Просто идем по массиву
    {
        itog *= arr[i];                 //И переменожаем
    }
    return itog;
}

long long f(int* arr, int i)            //Произведение элементов массива с помощью рекурсии(предсказываю что будет выполняться дольше)
{
    if (i == 0)                         //условие выхода из рекурсии
    {
        return arr[i];
    }
    return arr[i] * f(arr, i - 1);      //тынешний элемент умножаем на следующий(но следующий в обратном порядке)
}

void feel_random(int* arr, int size)    //Заполнение массива
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void show(int* arr, int size)           //Вывод массива на экран
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void tofile(int* arr, int size, ofstream &write)    //Вывод массива в файл
{
    for (int i = 0; i < size; i++)
    {
        write << arr[i] << " ";
    }
    write << "\n";
}




int main()
{
    system("chcp 1251");

    ofstream write("Result.txt");       //файлик с результатом

    int size = 5;
    
    int* arr = new int[size];           //выделяем память под массив

    feel_random(arr, size);             //Заполеняем
    
    show(arr, size);                    //Выводим на экран

    write << "Массив:\n";
    tofile(arr, size, write);           //Выводим в файл
     


    //////////////////////////////// Рекурсия \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
    
    long long itog;                     //переменная в которую запишем значение произведения

    auto start = chrono::high_resolution_clock::now();    //время начала работы 
    itog = f(arr, size - 1);        //вызываем рекурсию                    
    auto end = chrono::high_resolution_clock::now();      //конец работы ф-ии
    
    cout << itog;                   //выводим итог на экран
    
    write << "Произведение всех элементов:" << itog;    //итог в файл  

    chrono::duration<float>  duration = end - start;    //Считаем время выполнения рекурсии


  
    //////////////////////////////// Итерация \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
  
    
    long long itog1;

    auto start_iteration = chrono::high_resolution_clock::now();    //время начала работы 
    itog1 = iteration(arr, size);
    auto end_iteration = chrono::high_resolution_clock::now();      //конец работы ф-ии
    
    chrono::duration<float>  duration_iteration = end_iteration - start_iteration;  //снова считае время, но для итерации


     //////////////////////////////// Вывод \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 

    //вывод времени рекурсии
    cout << setprecision(10);
    cout << "\nВремя выполнения рекурсии:" << duration.count() ;
    write << setprecision(10);
    write << "\nВремя выполнения рекурсии:" << duration.count();

    //вывод времени итерации
    cout << setprecision(10);
    cout << "\nВремя выполнения итерационнного метода:" << duration_iteration.count();
    write << setprecision(10);
    write << "\nВремя выполнения итерационнного метода:" << duration_iteration.count();
    
    

   
}


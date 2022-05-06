// Dinamic Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
    Vector<int> a(20,15);

    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << " ";
    }

    Vector<int> b = a;
    cout << "\n";
    for (int i = 0; i < b.get_size(); i++)
    {
        cout << b[i] << " ";
    }
    
    a.clear();
    cout << "\n";
    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < b.get_size(); i++)
    {
        cout << b[i] << " ";
    }

    b.resize(10);
    cout << "\n";
    for (int i = 0; i < b.get_size(); i++)
    {
        b[i] = i;
        cout << b[i] << " ";
    }


}


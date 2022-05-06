// Рациональное число(дробь).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

#include "rational_number.h"

using namespace std;

int main()
{
    ofstream write("Result.txt");
    
    rational_number number1(1, 3);
   // write << "Создано число number1 = " << number1.info() << "\n";
    
    rational_number number2;
    number2.set_numerator(4);
    number2.set_denominator(9);
    
    rational_number res;
    //Сложение
    res = number1 + number2;
    write << number1.info() << " + " << number2.info() << " = " << res.info();
    cout << number1.info() << " + " << number2.info() << " = " << res.info();
    
    cout << "\n";
    write << "\n";
    //Вычитание
    res = number1 - number2;
    write << number1.info() << " - " << number2.info() << " = " << res.info();
    cout << number1.info() << " - " << number2.info() << " = " << res.info();


    cout << "\n";
    write << "\n";
    //Умножение
    res = number1 * number2;
    write << number1.info() << " * " << number2.info() << " = " << res.info();
    cout << number1.info() << " * " << number2.info() << " = " << res.info();

    cout << "\n";
    write << "\n";
    //Деление
    res = number1 / number2;
    write << number1.info() << " / " << number2.info() << " = " << res.info();
    cout << number1.info() << " / " << number2.info() << " = " << res.info();

    cout << "\n";
    write << "\n";
    //Сравнение
    if (number1 == number2)
    {
        write << number1.info() << " = " << number2.info();
        cout << number1.info() << " = " << number2.info();
    }
    else
    {
        write << number1.info() << " != " << number2.info();
        cout << number1.info() << " != " << number2.info();
    }

    number1.set_numerator(1);
    number1.set_denominator(5);

    number2.set_numerator(5);
    number2.set_denominator(25);

    cout << "\n";
    write << "\n";
    //Сравнение
    if (number1 == number2)
    {
        write << number1.info() << " = " << number2.info();
        cout << number1.info() << " = " << number2.info();
    }
    else
    {
        write << number1.info() << " != " << number2.info();
        cout << number1.info() << " != " << number2.info();
    }

    write.close();
}


#include <iostream>
#include <string>
#include "MyStack.h"
#include "Calculator_postfix.h"

using namespace std;

/// <summary>
/// Добавляет символы строки в стек
/// </summary>
/// <param name="stack">- стек типа char в который добавляются символы</param>
/// <param name="str">- строка, которая разбирается на символы</param>
template <typename Type>
void push_to_stack(MyStack<Type>& stack, string& str);


/// <summary>
/// Проверяет строку на то палиндром это или нет
/// </summary>
/// <param name="str">- проверяемая строка</param>
/// <returns></returns>
bool check_palindrom(string& str);

/// <summary>
/// Преобразует число из 10-й системы счисления
/// в заданную (до 10)
/// </summary>
/// <param name="value">-число</param>
/// <param name="base">-система счисления</param>
/// <returns>строку с числом</returns>
string number(int value, int base);


int main()
{
    system("chcp 1251");
   
    //Палиндром

    //Считываем строку
    string str;
    cout << "Введите строку:";
    cin >> str;

    if (check_palindrom(str))
    {
        cout << "Строка является палиндромом\n";
    }
    else
    {
        cout << "К сожалению данная строка не палиндром\n";
    }

    //Перевод в систему счисления

    cout << "Введите число:";
    int value;
    cin >> value;
    cout << "Введите основание системы счисления:";
    int base;
    cin >> base;

    cout << number(value, base);

    
    

    //Постфиксный калькулуятор
    Caclulator_postfix calc;

    cout << "\nВведите выражение для постфиксного калькулятора:";
    cin.ignore();
    ll a = calc.calculate();

    cout << "\nОтвет:" << a;



}






string number(int value, int base)
{
    MyStack<int> stack;

    while (value != 0)
    {
        stack.push(value % base);   //делим на основание системы счисления и записываем в стек
        value /= base;
    }

    string str;
    //Пока стек не пустой
    while (!stack.empty())
    {
        str += to_string(stack.pop());
    }
    return str;

}

template <typename Type>
void push_to_stack(MyStack<Type>& stack, string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        stack.push(str[i]);
    }

}

bool check_palindrom(string& str)
{
    MyStack<char> stack;
    push_to_stack(stack, str);

    bool flag = true;
    //Проходим по строки и проверяем на символы строки и стека
    for (int i = 0; i < str.size(); i++)
    {
        if (stack.pop() != str[i])
            flag = false;
    }

    return flag;

}

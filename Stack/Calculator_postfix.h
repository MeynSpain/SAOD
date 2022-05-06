#pragma once
#include "MyStack.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>

typedef long long ll;

using namespace std;

/// <summary>
/// Постфиксный калькулятор, вводите строку и закончите ввод
/// комбинацией Ctrl+Z + Enter
/// </summary>
class Caclulator_postfix
{
private:

	MyStack<ll> stack_number;		//Стек с числами
	
	vector<char> arr_operation;		//Массив с операциями

    ll op_left;                     //Левый операнд
    ll op_right;                    //Правый операнд
	

	/// <summary>
	/// Считывает строку и заполняет стек с числами и 
    /// массив с операциями
	/// </summary>
	void read()
	{
        string str_number;
        char symb;
        //cin.ignore();
        string str;
     
        getline(cin, str);

        for (int i = 0; i < str.length(); i++)
        {
            
            //Если это цифра, то добавляем в строку
            if (str[i] >= '0' && str[i] <= '9')
            {
                str_number += str[i];
            }
            else
            {
                if (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
                {
                    //Если символ, то переводим в число и записывае в стек
                    //после очищаем строку
                    int number = stoi(str_number);
                    stack_number.push(number);
                    str_number.clear();
                }
                

                //После записываем операцию в массив
                if (str[i] == '+' || str[i] == '-' || str[i] == '*' || 
                    str[i] == '/' || str[i] == '^')
                    arr_operation.push_back(str[i]);
            }

        }
	}

    /// <summary>
    /// Производит операцию между операндами
    /// </summary>
    /// <param name="i"> - индекс операции в массиве </param>
    void operation(int i)
    {
        switch (arr_operation[i])   //Берем операцию, лежащую в массиве
        {
        case '+':
            stack_number.push(op_left + op_right);
            break;

        case '-':
            stack_number.push(op_left - op_right);
            break;
            
        case '*':
            stack_number.push(op_left * op_right);
            break;

        case '/':
            if (op_right == 0)
                throw invalid_argument("Деление на нуль!");
            else
                stack_number.push(op_left / op_right);
            break;
            
        case '^':
            stack_number.push(pow(op_left, op_right));
            break;

        default:
            break;
        }
    }

public:

    /// <summary>
    /// Возвращает число типа long long
    /// и нужно ввести строку состоящую из чисел и операций 
    /// + - * / ^
    /// окончите ввод комбинацией Ctrl+Z + Enter
    /// </summary>
    /// <returns></returns>
    ll calculate()
    {
        read();
        //Проходимся по операциям и считаем
        for (int i = 0; i < arr_operation.size(); i++)
        {
            //Проверяем пустой ли стек
            if (!stack_number.empty())
            {
                //Берем правый операнд
                op_right = stack_number.pop();
                //снова проверяем пустой ли стек
                if (!stack_number.empty())
                {
                    //Берем левый операнд
                    op_left = stack_number.pop();

                    //Считаем
                    operation(i);

                }
                else
                {
                    throw invalid_argument("Слишком много операций, не хватает чисел для вычислений");
                }
            }
            else
            {
                throw invalid_argument("Слишком много операций, не хватает чисел для вычислений");
            }
            
        }
        return stack_number.peek();
    }




};

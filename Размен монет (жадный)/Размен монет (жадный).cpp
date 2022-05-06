// Размен монет (жадный).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <fstream>

using namespace std;

vector<int> greedy_alg(vector<int>& arr, int summ)  //размен монет с помощью жадного алгоритма
{
    sort(arr.begin(), arr.end());                   //Сначала сортируем массив, чтобы идти с конца
    
    vector<int> result;                             //Массив в который будем записывать наши номиналы

    int i = arr.size() - 1;                         //Ставим указатель на конец массива

    while (summ > 0)                                //Пока не разменяем сумму
    {

        if (summ - arr[i] >= 0)                     //если мы можем вычесть из суммы, то вычитаем
        {
            summ -= arr[i];
            result.push_back(arr[i]);               //И сохраняем наш результат
        }
        else
        {
            if (i == 0)                             //Если не можем, то смотрим не дошли ли мы до конца массива
            {
                break;
            }
            i--;                                    //Если нет, то переходим к следующему элементу
        }

    }

    if (summ > 0)
        throw invalid_argument("К сожалению не получилось разменять данную сумму, нет подходящих купюр!");

    return result;
}

template<typename T>
void print_arr(vector<T> arr)                   //Вывод массива на экран
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

template<typename T>
void toFile_arr(vector<T> arr, ofstream& f)                   //Вывод массива на экран
{
    
    for (int i = 0; i < arr.size(); i++)
    {
        f << arr[i] << " ";
    }
}


int main()
{
    system("chcp 1251");
    ofstream f("result.txt");


    //Считывам кол-во номиналов
    cout << "Введите кол-во разновидностей номиналов:";    
    int size;
    cin >> size;

    f << "Введите кол-во разновидностей номиналов:";        //Всю информацию в файл
    f << size << "\n";

    cout << "Теперь вводите сами номиналы:\n";
    f << "Теперь вводите сами номиналы:\n";


    vector<int> nominal(size);
    //Теперь сами номиналы
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "-й: ";
        cin >> nominal[i];
    }

    //их же файл
    for (int i = 0; i < size; i++)
    {
        f << i + 1 << "-й: " << nominal[i] << "\n";
    }

    //То что надо разменять
    int summ;
    cout << "Введите сумму, которую нужно разменять: ";
    cin >> summ;

    f << "Введите сумму, которую нужно разменять: " << summ << "\n";    //в файл



    try {
        vector<int> res = greedy_alg(nominal, summ);

        cout << "\nРАЗМЕН:\n";
        print_arr(res);

        //в файлик
        f << "\nРАЗМЕН:\n";
        toFile_arr(res, f);

    }
    catch (exception e)
    {
        cout << "\n" << e.what();

        f << "\n" << e.what();
    }
    

    
    



    
    
}


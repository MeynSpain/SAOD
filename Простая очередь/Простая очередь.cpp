// Простая очередь.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <queue>
#include "SimpleQueue.h"
#include <random>
#include <math.h>

using namespace std;

struct Person
{
    string sex;         //пол
    string name;        //имя
};

int main()
{

    system("chcp 1251");
    SimpleQueue<Person> male, woman;

    Person person;

    ifstream f_persons;
    ofstream f("result.txt");

    f_persons.open("dance.txt");
    //Если файл открылся
    if (f_persons.is_open())
    {
        //Пока не дойдем до конца файл, считываем все данные
        while (!f_persons.eof())
        {
            //Считывание в доп переменную, потому что в конце файла создавалась еще одна запись
            string sex;
            f_persons >> sex;
           // if (person.sex[0] == 'M' || person.sex[0] == 'm' || person.sex[0] == 'F' || person.sex[0] == 'f')
            if (sex[0] == 'M' || sex[0] == 'm' || sex[0] == 'F' || sex[0] == 'f')
            {
                person.sex = sex;
                char name[20];
                f_persons.getline(name, 20);
                person.name = name;
                //Смотрим на пол и заносим в соответствующую очередь
                if (person.sex[0] == 'M' || person.sex[0] == 'm')
                {
                    male.insert(person);
                }
                else if (person.sex[0] == 'F' || person.sex[0] == 'f')
                {
                    woman.insert(person);
                }
            }           
            else
            {
                cout << "Не получается считать пол\n";
            }
        }

        cout << "Партнеры по танцам:\n";
        f << "Партнеры по танцам:\n";
        
        //Пока одна из очередь не опустеет
        while (!male.empty() && !woman.empty())
        {
            cout << male.front().name << " и " << woman.front().name << "\n";
            f << male.delet().name << " и " << woman.delet().name << "\n";
        }
        cout << "\n";

        if (!male.empty())
        {
            cout << "Танца ожидает еще " << male.size() << " кавалера";
            cout << " и первый на очереди " << male.front().name << "\n";
            f << "Танца ожидает еще " << male.size() << " кавалера";
            f << " и первый на очереди " << male.front().name << "\n";
        }

        if (!woman.empty())
        {
            if (!male.empty())
            {
                cout << "А также ";
                f << "А также ";
            }
            cout << " Танца ожидает еще " << woman.leght() << " дамы";
            cout << " и первая из них " << woman.front().name;
            f << " Танца ожидает еще " << woman.leght() << " дамы";
            f << " и первая из них " << woman.front().name;
        }

    }
    else
    {
        cout << "Не получилось открыть файл";
        f << "Не получилось открыть файл";
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

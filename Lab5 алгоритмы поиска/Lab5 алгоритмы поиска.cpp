#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include "MySearch.h"
using namespace std;

int main()
{
    system("chcp 1251");
    ofstream f("result.txt");

    try
    {       

        //Массив заполненный вручную
        cout << "Введите размер массива:";       
        int size;
        cin >> size;

        f << "Введите размер массива:" << size << "\n";

        vector<int> arr_hand(size);
        fill_hand_vector(arr_hand);     //заполняем массив ручками

        printTofile_vector(arr_hand, f);//Выводим массив в файл

        int key;
        cout << "Введите искомый элемент:";
        cin >> key;

        f << "\nВведите искомый элемент:" << key << "\n"; //в файл

        auto start_hand = chrono::high_resolution_clock::now();

        int i = search_sequential(arr_hand, key);
        
        auto end_hand = chrono::high_resolution_clock::now();
     
        cout << "Индекс найденного элемента:" << i + 1 << "\n";
        f    << "Индекс найденного элемента:" << i + 1 << "\n";
        chrono::duration<float> hand_time = end_hand - start_hand;
        cout << "Время выполения последовательного поиска вручную заполненного массива:" << hand_time.count() << "\n";
        f    << "Время выполения последовательного поиска вручную заполненного массива:" << hand_time.count() << "\n";


        
        start_hand = chrono::high_resolution_clock::now();

        sort(arr_hand.begin(), arr_hand.end());
        i = search_binary(arr_hand, key);

        end_hand = chrono::high_resolution_clock::now();
        
        cout << "Т.к. бинарный поиск работает только в отсортированном массиве, то вот как теперь выглядит этот массив:\n";
        f    << "Т.к. бинарный поиск работает только в отсортированном массиве, то вот как теперь выглядит этот массив:\n";

        print_vector(arr_hand);
        printTofile_vector(arr_hand, f);

        hand_time = end_hand - start_hand;
        cout << "Индекс найденного элемента:" << i + 1 << "\n";
        f    << "Индекс найденного элемента:" << i + 1 << "\n";
        cout << "Время выполения бинарного поиска вручную заполненного массива:" << hand_time.count() << "\n";
        f    << "Время выполения бинарного поиска вручную заполненного массива:" << hand_time.count() << "\n";


        ///Заполенный случайными числами
        cout << "Введите размер массива:";
        cin >> size;
        f    << "Введите размер массива:" << size << "\n";

        vector<int> arr_rand(size);
        fill_rand_vector(arr_rand);
        print_vector(arr_rand);
        printTofile_vector(arr_rand, f);

        cout << "Введите искомый элемент:";
        cin >> key; 
        f    << "Введите искомый элемент:" << key << "\n";

        

        auto start_rand = chrono::high_resolution_clock::now();

        i = search_sequential(arr_rand, key);       //последовательный поиск

        auto end_rand = chrono::high_resolution_clock::now();

        cout << "Индекс найденного элемента:" << i + 1 << "\n";
        f << "Индекс найденного элемента:" << i + 1 << "\n";
        chrono::duration<float> rand_time = end_rand - start_rand;
        cout << "Время выполения последовательного поиска радномно заполненного массива:" << rand_time.count() << "\n";
        f << "Время выполения последовательного поиска радномно заполненного массива:" << rand_time.count() << "\n";



        start_rand = chrono::high_resolution_clock::now();

        sort(arr_rand.begin(), arr_rand.end());
        i = search_binary(arr_rand, key);

        end_rand = chrono::high_resolution_clock::now();
        rand_time = end_rand - start_rand;

        cout << "Т.к. бинарный поиск работает только в отсортированном массиве, то вот как теперь выглядит этот массив:\n";
        f << "Т.к. бинарный поиск работает только в отсортированном массиве, то вот как теперь выглядит этот массив:\n";

        print_vector(arr_rand);
        printTofile_vector(arr_rand, f);

        cout << "Индекс найденного элемента:" << i + 1 << "\n";
        f << "Индекс найденного элемента:" << i + 1 << "\n";
        cout << "Время выполения бинарного поиска вручную радномно массива:" << rand_time.count() << "\n";
        f << "Время выполения бинарного поиска радномно заполненного массива:" << rand_time.count() << "\n";


        

       

        f.close();
    }
    catch (exception error)
    {
        cout << error.what();
        f << error.what();
    }
    


}


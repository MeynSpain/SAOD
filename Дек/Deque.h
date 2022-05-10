#pragma once
#include <exception>
#include <iostream>

using namespace std;

/// <summary>
/// Класс дек на 200 элементов
/// </summary>
/// <typeparam name="Type"></typeparam>
template<class Type>
class Deque
{
private:

    int const n = 200;

    //Сделал динамический массив, потому что надоело
    //хочу написать n и потом, если что поменять его
    Type* arr = new Type[n];

    //указатель на голову
    int head = 0;
    //указатель на хвост
    int tail = 0;
    //кол-во эл-в в деке
    int count = 0;

public:

    /// <summary>
    /// Добавляет эл-т в конец дека
    /// </summary>
    /// <typeparam name="Type"></typeparam>
    void push_back(Type item);

    /// <summary>
    /// Добавляет эл-т в начало дека
    /// </summary>
    /// <param name="value"></param>
    void push_front(int value);

    /// <summary>
    /// Удаляет эл-т с конца дека и возвращает его
    /// </summary>
    /// <returns></returns>
    Type pop_back();
    
    /// <summary>
    /// Удаляет эл-т с начала дека и возвращает его
    /// </summary>
    /// <returns></returns>
    Type pop_front();

    /// <summary>
    /// Возвращает эл-т с конца дека, не удаляя его
    /// </summary>
    /// <returns></returns>
    Type back();

    /// <summary>
    /// Возвращает эл-т с начала дека, не удаляя его
    /// </summary>
    /// <returns></returns>
    Type front();
    
    /// <summary>
    /// Возвращает кол-во эл-в в деке
    /// </summary>
    /// <returns></returns>
    int size();

    /// <summary>
    /// Проверка на то пустой стек или нет
    /// </summary>
    /// <returns>true - пустой, false - не пустой</returns>
    bool empty();

    /// <summary>
    /// Очищает дек
    /// </summary>
    void clear();

};



template<class Type>
inline void Deque<Type>::push_back(Type item)
{
    if (tail == head && count > 0)
    {
        throw out_of_range("Deque is full!");
    }
    //Сначала добвляем эл-т
    arr[tail] = item;
    count++;
    //а после сдвигаем указатель
    tail = (tail + 1) % n;      //кольцуем
}

template<class Type>
inline void Deque<Type>::push_front(int value)
{
    //если хвост и голова сейчас сойдутся, то кидаем исключение
    if ((head - 1 + n) % n == tail && count > 0)
    {
        throw out_of_range("Deque is full!");
    }
    //сначала сдвигаем указатель
    head = (head - 1 + n) % n;  //кольцуем
    //и только потом добавляем
    arr[head] = value;
    count++;
}

template<class Type>
inline Type Deque<Type>::pop_back()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {      
        //Сдвигаем указатель на этот эл-т
        tail = (tail - 1 + n) % n;
        count--;
        
        //И возвращаем его
        return arr[tail];
    }

}

template<class Type>
inline Type Deque<Type>::pop_front()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        //Сдвигаем указатель вправо
        head = (head + 1) % n;
        count--;

        //Возвращаем эл-т, с которого только что ушли
        return arr[(head - 1 + n) % n];
    }
}

template<class Type>
inline Type Deque<Type>::back()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        return arr[(tail - 1 + n) % n];
    }

}

template<class Type>
inline Type Deque<Type>::front()
{
    if (count == 0)
    {
        throw out_of_range("Deque is empty!");
    }
    else
    {
        return arr[head];
    }

}

template<class Type>
inline int Deque<Type>::size()
{
    return count;
}

template<class Type>
inline bool Deque<Type>::empty()
{
    return count == 0;
}

template<class Type>
inline void Deque<Type>::clear()
{
    head = 0;
    tail = 0;
    count = 0;
}
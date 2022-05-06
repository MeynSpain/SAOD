#pragma once


/// <summary>
/// Мое простанство имен, в котором будут храниться функции, чтобы получить к ним доступ
/// нужно написать myspace::имя_функции, например
/// myspace::fill_hand_array(arr, 10); 
/// Либо можно полностью подключить пространство имен вот так вот:
/// using namespace myspace;
/// </summary>
namespace myspace {	
					

	/// <summary>
	/// Заполняет массив вручную
	/// </summary>
	/// <param name="arr">Заполняемый массив</param>
	/// /// <param name="size">Размер массива</param>
	void fill_hand_array(int* arr, int size);


	/// <summary>
	/// Выводит массив в консоль
	/// </summary>
	/// <param name="arr">Имя массива</param>
	/// /// <param name="size">Размер массива</param>
	void show_array(int* arr, int size);
}



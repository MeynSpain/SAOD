/*
* Лаб.работа № 10. Очереди приоритетов.
* 1. Создать класс PQueue.
* 2. Реализовать программу №5.6, Выполнение заданий.
*/

#include <iostream>
#include <fstream>
#include "PQueue.h"
#include "job.h"

using namespace std;

int main()
{
	system("chcp 1251");
	PQueue<JobRequest> jobpool;

	ifstream f;

	int jobServiceUse[3] = { 0, 0, 0 };

	JobRequest PR;
	
	char ch;

	f.open("job.txt", ios::in | ios::_Nocreate);
	
	if (f.is_open())
	{
		//Читаем файл
		while (f >> ch)
		{
			//Смотрим что за работник
			switch (ch)
			{
			case 'M':
				PR.staffPerson = Manager;
				break;

			case 'S':
				PR.staffPerson = Supervisor;
				break;

			case 'W':
				PR.staffPerson = Worker;
				break;

			default:
				cout << "Я не знаю кто это такой\n";
				break;
			}

			//Читаем остальные данные по работнику
			f >> PR.jobId;
			f >> PR.jobTime;

			//вставляем в очередь
			jobpool.push(PR);
		}

		cout << "Категория    Номер      Время\n\n";
		while (!jobpool.empty())
		{
			PR = jobpool.pop();
			PrintJobInfo(PR);

			//Добавляем время
			jobServiceUse[(int)PR.staffPerson] += PR.jobTime;
		}
		PrintJobSummery(jobServiceUse);
	}
	else
	{
		cout << "Не получилось открыть файл";
	}


}

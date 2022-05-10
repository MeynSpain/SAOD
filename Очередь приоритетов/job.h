#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//��������� ����������
enum Staff { Manager, Supervisor, Worker};

//�����, ����������� �� ������ ��� ������ ��������� �����������
int jobServiceUse[3] = { 0 , 0 , 0 };


//��������� ������������ ������
struct JobRequest
{
	Staff staffPerson;
	int jobId;
	int jobTime;
};


/// <summary>
/// ���������� ��������� ������ ��� 
/// ���� �������� JobRequest
/// </summary>
/// <param name="job1"></param>
/// <param name="job2"></param>
/// <returns></returns>
bool operator < (const JobRequest& job1, const JobRequest& job2)
{
	return job1.staffPerson < job2.staffPerson;
}


/// <summary>
/// ������ ����� ������ JobRequest
/// </summary>
/// <param name="PR"></param>
void PrintJobInfo(JobRequest PR)
{
	switch (PR.staffPerson)
	{
	case Manager:
		cout << "Manager       " << PR.jobId << "         " <<PR.jobTime << "\n";
		break;

	case Supervisor:
		cout << "Supervisor    " << PR.jobId << "         " << PR.jobTime << "\n";
		break;

	case Worker:
		cout << "Worker        " << PR.jobId << "         " << PR.jobTime << "\n";
		break;

	default:
		break;
	}
}

//������ ������ ������� ������ �����������
void PrintJobSummery(int jobServiceUse[])
{
	cout << "\n����� ������������ �� ����������:\n";
	cout << "Manager     " << setw(3) 
		 << jobServiceUse[0] << "\n";
	cout << "Supervisor  " << setw(3)
		<< jobServiceUse[1] << "\n";
	cout << "Worker      " << setw(3)
		<< jobServiceUse[2] << "\n";
}

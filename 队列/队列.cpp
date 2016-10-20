// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include "iostream"
#include "AdditionProblem.h"
#include "Queue.h"
//#include <queue>
using namespace std;

int main()
{
	int numProblems, maxAddend;//Ҫ������������������е�������
	const int MAX_ROUNDS = 3;//���Իش���������غ���
	//initialize();
	cout << "888Let's practice our addition skills! ***\n\n"
		"how many problems would you like?";
	cin >> numProblems;
	cout << "what's the largetst addend you would like?";
	cin >> maxAddend;
	Queue problemQueue;
	for (int i=1;i<=numProblems;i++)
	{
		AdditionProblem problem(maxAddend);
		problemQueue.enqueue(problem);
	}

	//��ʼʵ���غ�
	AdditionProblem problem(maxAddend);//��һ���ӷ�����
	int userAnswer, //�û�������Ļش�
		numberMissed;//�ش�����������
	for (int round=1;round<=MAX_ROUNDS;round++)
	{
		numberMissed = 0;
		for (int count=1;count<=numProblems;count++)
		{
			// �������һ���غ�
			problem = problemQueue.front();
			problemQueue.dequeue();
			cout << problem;
			cin >> userAnswer;
			if(userAnswer==problem.answer())
			{
				cout << "correct!\n\n";
			}
			else
			{
				cout << "sorry--try again!\n\n";
				problemQueue.enqueue(problem);
				numberMissed++;
			}
		}
		if (numberMissed == 0)
		{
			cout << "congratulations! you correctly answered all the problems in round #" << round << endl;
			break;
		}
		else
		{
			cout << "\nYou missed" << numberMissed << "problems in Round #" << round << ".\n";
			if (round < MAX_ROUNDS)
				cout << "you may now try them again.good luck!\n";
			numProblems = numberMissed;
		}
	}
	
	if (numberMissed==0)
	{
		cout << "You havve finished the quiz and have successfully.\n answered all the problem.good job!" << endl;
	} 
	else
	{
		cout << "\n You have reached the limit on the number of tries allowed.\nHere are the problems you missed:\n\n";
		while (!problemQueue.empty())
		{
			problem = problemQueue.front();
			problemQueue.dequeue();
			cout << problem << "Answer:" << problem.answer() << endl << endl;
		}
		cout << "perhaps it would be a good idea to practice some more.\n";
	}
    return 0;
}


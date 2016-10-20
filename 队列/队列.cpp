// 队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "iostream"
#include "AdditionProblem.h"
#include "Queue.h"
//#include <queue>
using namespace std;

int main()
{
	int numProblems, maxAddend;//要提出的问题数，问题中的最大加数
	const int MAX_ROUNDS = 3;//尝试回答问题的最大回合数
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

	//开始实践回合
	AdditionProblem problem(maxAddend);//下一个加法问题
	int userAnswer, //用户对问题的回答
		numberMissed;//回答错误的问题数
	for (int round=1;round<=MAX_ROUNDS;round++)
	{
		numberMissed = 0;
		for (int count=1;count<=numProblems;count++)
		{
			// 提问题的一个回合
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


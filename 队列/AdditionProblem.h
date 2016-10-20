#pragma once
#include <iostream>
using namespace std;
#ifndef ADDITION_PROBLEM
#define ADDITION_PROBLEM

class AdditionProblem
{
public:
	AdditionProblem(int maxAddend=10);
	~AdditionProblem();

	void display(ostream & out)const;
	int answer()const;
private:
	int myAddend1;
	int myAddend2;
	int myAnswer;
	void initialize();
	friend ostream &operator<<(ostream &out, const AdditionProblem &problem);
};

#endif // !ADDITION_PROBLEM

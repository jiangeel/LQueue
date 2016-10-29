#include "stdafx.h"
#include "AdditionProblem.h"
#include <cstdlib>
#include <ctime>
using namespace std;

AdditionProblem::AdditionProblem(int maxAddend=10)
{
	myAddend1 = rand() % (maxAddend + 1);
	myAddend2 = rand() % (maxAddend + 1);
	myAnswer = myAddend1 + myAddend2;
}


AdditionProblem::AdditionProblem(int maxAddend)
{
}

AdditionProblem::~AdditionProblem()
{
}

void AdditionProblem::display(ostream & out) const
{
	out << myAddend1 << "+" << myAddend2 << "=" << "=?";
}

int AdditionProblem::answer() const
{

	return myAddend1+myAddend2;
}

void AdditionProblem::initialize()
{
	long seed = long(time(0));
	srand(seed);
}


ostream &operator<<(ostream & out, const AdditionProblem & problem)
{
	problem.display(out);
	return;
	// TODO: 在此处插入 return 语句
}

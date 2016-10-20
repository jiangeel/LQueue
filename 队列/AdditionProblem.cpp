#include "stdafx.h"
#include <cstdlib>
#include <ctime>
using namespace std;
#include "AdditionProblem.h"

AdditionProblem::AdditionProblem(int maxAddend)
{
	myAddend1 = rand() % (maxAddend + 1);
	myAddend2 = rand() % (maxAddend + 1);
	myAnswer = myAddend1 + myAddend2;
}




AdditionProblem::~AdditionProblem()
{
}

void AdditionProblem::display(ostream &out) const
{
	out << myAddend1 << "+" << myAddend2 << "=" << "=?";
}

int AdditionProblem::answer() const
{

	return myAddend1+myAddend2;
}

void initialize()
{
	long seed = long(time(0));
	srand(seed);
}



 ostream &operator<<(ostream & out, const AdditionProblem & problem)
{
	problem.display(out);
	return out;
	// TODO: 在此处插入 return 语句
}

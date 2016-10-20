#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue()
	:myFront(0),myBack(0)
{
}

bool Queue::empty() const
{
	return (myBack==myFront);
}

void Queue::enqueue(const QueueElement & value)
{
	int newBack = (myBack + 1) % QUEUE_CAPACITY;
	if (newBack != myFront)//队列未满
	{
		myArray[myBack] = value;
		myBack = newBack;
	}
	else
	{
		cout << "错误：队列满了" << endl;
	}
}

void Queue::dequeue()
{
	if(!empty() )
	{
		myFront = (myFront + 1) % QUEUE_CAPACITY;
	}
	else
	{
		cout << "错误：队列是空的" << endl;
	}

}

void Queue::display(ostream & out) const
{
	for (int i = myFront; i < myBack; i = (i + 1) % QUEUE_CAPACITY)
	{
		cout << myArray[i] << " ";
	}
	cout << endl;
}

QueueElement Queue::front() const
{
	if (!empty())
	{
		return myArray[myFront];
	}
	else
	{
		cout << "错误：队列是空的" << endl;
		QueueElement garbage;
		return garbage;
	}
}


Queue::~Queue()
{
}

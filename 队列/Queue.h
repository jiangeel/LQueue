#pragma once
#include <iostream>
#include "AdditionProblem.h"
#ifndef QUEUE
#define QUEUE

const int QUEUE_CAPACITY = 128;
typedef AdditionProblem QueueElement;


class Queue
{
public:
	Queue();
	bool empty() const;
	void enqueue(const QueueElement &value);
	void dequeue();
	void display(ostream &out) const;
	QueueElement front()const;

	~Queue();
private:
	int myFront;
	int myBack;
	QueueElement myArray[QUEUE_CAPACITY];

};

#endif // QUEUE

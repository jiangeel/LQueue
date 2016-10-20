#include "stdafx.h"
#include "LQueue.h"
#include <new>
using namespace std;

LQueue::LQueue()
	:myFront(0),myBack(0)
{
}

LQueue::LQueue(const LQueue&original)
{
	myFront = myBack = 0;
	if (!original.empty())
	{
		//复制第一个节点
		myFront = myBack = new LQueue::Node(original.front());
		//令指针遍历original的链表
		LQueue::NodePoint origPtr = original.myFront->next;
		while (origPtr!=NULL)
		{
			myBack->next = new LQueue::Node(origPtr->data);
			myBack = myBack->next;
			origPtr = origPtr->next;
		}
	}
}

const LQueue & LQueue::operator=(const LQueue & rightHandSide)
{
	if (this!=&rightHandSide)//检查不是q=q
	{
		this->~LQueue();
		if (rightHandSide.empty())//空列队
		{
			myFront = myBack = 0;
		}
		else
		{							//复制rightHandSide的列表
			//复制第一个节点
			myFront = myBack = new LQueue::Node(rightHandSide.front());
			//令指针遍历rightHandSide的链表
			LQueue::NodePoint rhsPtr = rightHandSide.myFront->next;
			while (rhsPtr!=NULL)
			{
				myBack->next = new LQueue::Node(rhsPtr->data);
				myBack = myBack->next;
				rhsPtr = rhsPtr->next;
			}
		}
	}
	return *this;
}

bool LQueue::empty() const
{
	return (myFront==NULL);
}

void LQueue::enqueue(const QueueElement & value)
{
	LQueue::NodePoint newptr = new LQueue::Node(value);
	if (empty())
	{
		myFront = myBack = newptr;
	}
	myBack->next = newptr;
	myBack = newptr;

}

void LQueue::display(ostream & out) const
{
	LQueue::NodePoint ptr;
	for (ptr=myFront;ptr!=NULL;ptr=ptr->next)
	{
		out << ptr->data << " ";
	}
	out << endl;
}

QueueElement LQueue::front() const
{
	if (!empty())
	{
		return myFront->data;
	} 
	else
	{
		cerr << "***Queue is empty***"
			"-- returning garbage ***\n";
		QueueElement *temp = new(QueueElement);
		QueueElement garbage = *temp;
		delete temp;
		return garbage;
	}
	return QueueElement();
}

void LQueue::dequeue()
{
	if (!empty())
	{
		LQueue::NodePoint ptr = myFront;
		myFront = myFront->next;
		delete ptr;
		if (myFront==NULL)
		{
			myBack = NULL;
		}
	}
	else
	{
		cerr << "***Queue is empty --can't remove a value***\n";
	}
}

LQueue::~LQueue()
{
	LQueue::NodePoint prev = myFront,
		ptr;
	while (prev!=NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

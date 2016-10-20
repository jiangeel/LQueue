#pragma once
#include <iostream>
#ifndef LQUEUE
#define LQUEUE
using namespace std;
typedef int QueueElement;
class LQueue
{
public:
	LQueue();
	LQueue(const LQueue &original);
	const LQueue &operator=(const LQueue&rightHandSide);
	bool empty() const;
	void enqueue(const QueueElement &value);
	void display(ostream & out)const;
	QueueElement front() const;
	void dequeue();
	~LQueue();
private:
	class Node
	{
	public:
		QueueElement data;
		Node * next;
		Node(QueueElement value, Node * link = 0)//���캯��
			:data(value), next(link)
		{};

	};
	typedef Node * NodePoint;

	NodePoint myFront, //ָ�����ǰ�˵�ָ��
				myBack;//ָ����к�˵�ָ��
};

#endif

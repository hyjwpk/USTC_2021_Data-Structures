#include "Quene.h"
#include <iostream>

QNode::QNode()
{
	for (int i = 0; i < 3; i++)
		this->data[i] = 0;
	next = NULL;
}

QNode::QNode(int(&data)[3])
{
	for (int i = 0; i < 3; i++)
		this->data[i] = data[i];
	next = NULL;
}

LinkQunene::LinkQunene() :front(NULL), rear(NULL) {};

Quene::Quene() :length(0) {}

void Quene::enQuene(int(&data)[3])
{
	QuenePtr node = new QNode(data);
	if (node == NULL)
		abort();
	if (length == 0)
		quene.front = quene.rear = node;
	else
	{
		quene.rear->next = node;
		quene.rear = node;
	}
	length++;
}

void Quene::deQuene(int(&data)[3])
{
	if (length == 0)
		abort();
	QuenePtr front = quene.front;
	quene.front = front->next;
	for (int i = 0; i < 3; i++)
		data[i] = front->data[i];
	free(front);
	length--;
	if (length == 0)
		quene.rear = NULL;
}


void Quene::enQueneInOrder(int(&data)[3])
{
	QuenePtr front = quene.front;
	if (front == NULL)
	{
		enQuene(data);
	}
	else
	{
		QuenePtr node = new QNode(data);
		if (node == NULL)
			abort();
		if (node->data[0] < front->data[0])
		{
			node->next = front;
			quene.front = node;
		}
		else
		{
			QuenePtr pre = quene.front;
			QuenePtr cur = pre->next;
			while (cur)
			{
				if (pre->data[0] <= data[0] && data[0] <= cur->data[0])
					break;
				pre = cur;
				cur = pre->next;
			}
			pre->next = node;
			node->next = cur;
			if (!cur)
				quene.rear = node;
		}
		length++;
	}
}

void Quene::moveFrontToRear()
{
	if (length > 1)
	{
		QuenePtr front = quene.front;
		quene.front = front->next;
		front->next = NULL;
		quene.rear->next = front;
		quene.rear = front;
	}
}

int Quene::getLength() { return length; }

QNode* Quene::getFront() { return quene.front; }

void Quene::print()
{
	QuenePtr cur = quene.front;
	while (cur)
	{
		std::cout << "(" << cur->data[0] << "," << cur->data[1] << "," << cur->data[2] << ")" << std::endl;
		cur = cur->next;
	}
}

Quene::~Quene()
{
	QuenePtr pre, cur = quene.front;
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
	}
}
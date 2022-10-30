#pragma once

/**
 * @brief 队列的基本节点
 * @details data数组在客户队列中存储[0]-ArrivalTime [1]-money [2]-duration
 * @details data数组在事件队列中存储[0]-OccurTime [1]-Type
*/
typedef struct QNode
{
	QNode();
	QNode(int(&data)[3]);
	int data[3];
	QNode* next;
} QNode, * QuenePtr;

typedef struct LinkQunene
{
	LinkQunene();
	QuenePtr front;
	QuenePtr rear;
} LinkQunene;

class Quene
{
public:
	Quene();
	void enQuene(int(&data)[3]);
	void deQuene(int(&data)[3]);

	/**
	 * @brief 根据data[0]中存储的值升序排列
	*/
	void enQueneInOrder(int(&data)[3]);
	void moveFrontToRear();
	int getLength();
	QNode* getFront();
	void print();
	~Quene();

private:
	LinkQunene quene;
	int length;
};

#include "Bank.h"
#include<iostream>

Bank::Bank(const int totalMoney, const int closeTime, const int moneyScope, const int durationScope, const int intertimeScope) : totalMoney(totalMoney),
closeTime(closeTime), totalTime(0), customerNum(0), dealingWithdrawMoneyList(false), moneyScope(moneyScope), durationScope(durationScope),
intertimeScope(intertimeScope), bottomMoney(0)
{
	//插入第一个到达事件
	int arrive[3] = { 0, 0, 0 };
	eventList.enQueneInOrder(arrive);
}

void Bank::handleEvent()
{
	int event[3];
	eventList.deQuene(event);
	switch (event[1])
	{
	case 0:
		customerArrived(event[0]);
		break;
	case 1: case 2:
		departure(event[0], event[1]);
		break;
	}
}

bool Bank::isEventListNotEmpty() { return eventList.getLength() != 0; }

int Bank::printResult()
{
	std::cout << totalTime / customerNum;
	return totalTime / customerNum;
}

void Bank::printCurrentCondition()
{
	std::cout << "event list:" << std::endl;
	eventList.print();
	std::cout << "customerList1:" << std::endl;
	customerList1.print();
	std::cout << "withdrawMoneyList:" << std::endl;
	withdrawMoneyList.print();
	std::cout << "totalMoney:" << totalMoney << std::endl;
	std::cout << "totalTime:" << totalTime << std::endl;
	std::cout << "customerNum:" << customerNum << std::endl;
	std::cout << "dealingWithdrawMoneyList:" << dealingWithdrawMoneyList << std::endl;
	std::cout << std::endl;
}

void Bank::customerArrived(const int arriveTime)
{
	int money = rand() % moneyScope;
	money = (rand() % 2) > 0 ? money : -money;
	int duration = rand() % durationScope + 1;
	int customer[3] = { arriveTime, money, duration };

	//customerList1队尾插入新客户
	customerList1.enQuene(customer);
	int intertime = rand() % intertimeScope + 1;

	//在营业结束前新客户到来则插入到来事件
	if (arriveTime + intertime < closeTime)
	{
		int newarrive[3] = { arriveTime + intertime, 0, 0 };
		eventList.enQueneInOrder(newarrive);
	}

	//若此时未处理取钱客户 且 customerList1仅有1位刚到达客户
	//试图处理这位客户
	if (!dealingWithdrawMoneyList && customerList1.getLength() == 1)
	{
		int condition = generateLeaveEvent(arriveTime, 2);
		if (condition == -1)
		{
			int customer[3];
			customerList1.deQuene(customer);
			withdrawMoneyList.enQuene(customer);
		}
	}
}

void Bank::departure(const int leaveTime, const int type)
{
	int customer[3];
	if (type == 1)
	{
		withdrawMoneyList.deQuene(customer);
		dealingWithdrawMoneyList = false;
		withdrawMoneyListCheck(leaveTime);
	}
	else if (type == 2)
		customerList1.deQuene(customer);
	else
	{
		abort();
	}

	//客户等待时间为离开时间-到达时间
	totalTime += leaveTime - customer[0];
	totalMoney += customer[1];
	customerNum++;
	if (customer[1] > 0)
	{
		bottomMoney = totalMoney - customer[1];
		withdrawMoneyListCheck(leaveTime);
	}

	//若没有正在处理的客户
	if (!dealingWithdrawMoneyList)
	{

		//循环检查customerList1队头顾客并将银行钱不够取的顾客插入withdrawMoneyList
		//直到队列为空
		while ((customerList1.getLength() != 0) && generateLeaveEvent(leaveTime, 2) == -1)
		{
			int customer[3];
			customerList1.deQuene(customer);
			withdrawMoneyList.enQuene(customer);
		}
	}
}

void Bank::withdrawMoneyListCheck(const int startTime)
{
	if (withdrawMoneyList.getLength() == 0 || totalMoney <= bottomMoney || dealingWithdrawMoneyList)
		return;
	QuenePtr oldfirst = withdrawMoneyList.getFront();
	do
	{
		int condition = generateLeaveEvent(startTime, 1);
		if (condition == 0)
		{
			dealingWithdrawMoneyList = true;
			break;
		}
		else
		{
			withdrawMoneyList.moveFrontToRear();
		}
	} while (withdrawMoneyList.getFront() != oldfirst);
}

int Bank::generateLeaveEvent(const int startTime, const int type)
{
	QuenePtr front;
	if (type == 1)
	{
		front = withdrawMoneyList.getFront();
	}
	else if (type == 2)
	{
		front = customerList1.getFront();
	}
	else
	{
		abort();
	}
	if (totalMoney + front->data[1] < 0) return -1;
	if (startTime + front->data[2] >= closeTime) return 1;
	int leave[3] = { startTime + front->data[2], type, 0 };
	eventList.enQueneInOrder(leave);
	return 0;
}
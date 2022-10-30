#include "BankAdvanced.h"
#include<iostream>

BankAdvanced::BankAdvanced(const int totalMoney, const int closeTime, const int moneyScope, const int durationScope, const int intertimeScope, const int listNum) :
	totalMoney(totalMoney), closeTime(closeTime), totalTime(0), dealingWithdrawMoneyList(false), customerNum(0), moneyScope(moneyScope), durationScope(durationScope),
	intertimeScope(intertimeScope), listNum(listNum)
{
	//插入第一个到达事件
	int arrive[3] = { 0, 0, 0 };
	customerList = new Quene[listNum];
	eventList.enQueneInOrder(arrive);
}

void BankAdvanced::handleEvent()
{
	int event[3];
	eventList.deQuene(event);
	switch (event[1])
	{
	case 0:
		customerArrived(event[0]);
		break;
	default:
		departure(event[0], event[1]);
		break;
	}
}

bool BankAdvanced::isEventListNotEmpty() { return eventList.getLength() != 0; }

int BankAdvanced::printResult()
{
	std::cout << totalTime / customerNum;
	return totalTime / customerNum;
}

void BankAdvanced::printCurrentCondition()
{
	std::cout << "event list:" << std::endl;
	eventList.print();
	for (int i = 0; i < listNum; i++)
	{
		std::cout << "customerList" << i << std::endl;
		customerList[i].print();
	}
	std::cout << "withdrawMoneyList:" << std::endl;
	withdrawMoneyList.print();
	std::cout << "totalMoney:" << totalMoney << std::endl;
	std::cout << "totalTime:" << totalTime << std::endl;
	std::cout << "customerNum:" << customerNum << std::endl;
	std::cout << std::endl;
}

void BankAdvanced::customerArrived(const int arriveTime)
{
	int money = rand() % moneyScope;
	money = (rand() % 2) > 0 ? money : -money;
	int duration = rand() % durationScope + 1;
	int customer[3] = { arriveTime, money, duration };

	//选择人少的队尾插入新客户
	int type = getSmallerListNum();
	Quene* quene;
	if (type >= 2)
		quene = &customerList[type - 2];
	else
	{
		abort();
	}
	quene->enQuene(customer);
	int intertime = rand() % intertimeScope + 1;

	//在营业结束前新客户到来则插入到来事件
	if (arriveTime + intertime < closeTime)
	{
		int newarrive[3] = { arriveTime + intertime, 0, 0 };
		eventList.enQueneInOrder(newarrive);
	}

	//若此时未处理取钱客户 且新到达队列仅有1位刚到达客户
	//试图处理这位客户
	if (quene->getLength() == 1)
	{
		int condition = generateLeaveEvent(arriveTime, type);
		if (condition == -1)
		{
			int customer[3];
			quene->deQuene(customer);
			withdrawMoneyList.enQuene(customer);
		}
	}
}

void BankAdvanced::departure(const int leaveTime, const int type)
{
	int customer[3];
	if (type == 1)
	{
		withdrawMoneyList.deQuene(customer);
		dealingWithdrawMoneyList = false;
		withdrawMoneyListCheck(leaveTime);
	}
	else if (type >= 2)
		customerList[type - 2].deQuene(customer);
	else
	{
		abort();
	}

	//客户等待时间为离开时间-到达时间
	totalTime += leaveTime - customer[0];
	customerNum++;
	if (customer[1] > 0)
	{
		withdrawMoneyListCheck(leaveTime);
	}

	if (type >= 2)
	{
		Quene* quene = &customerList[type - 2];

		//循环检查队头顾客并将银行钱不够取的顾客插入withdrawMoneyList
		//直到队列为空
		while ((quene->getLength() != 0) && generateLeaveEvent(leaveTime, type) == -1)
		{
			int customer[3];
			quene->deQuene(customer);
			withdrawMoneyList.enQuene(customer);
		}
	}
}

void BankAdvanced::withdrawMoneyListCheck(const int startTime)
{
	if (withdrawMoneyList.getLength() == 0 || dealingWithdrawMoneyList)
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

int BankAdvanced::generateLeaveEvent(const int startTime, const int type)
{
	QuenePtr front;
	if (type == 1)
	{
		front = withdrawMoneyList.getFront();
	}
	else if (type >= 2)
	{
		front = customerList[type - 2].getFront();
	}
	else
	{
		abort();
	}
	if (totalMoney + front->data[1] < 0) return -1;
	if (startTime + front->data[2] >= closeTime) return 1;
	int leave[3] = { startTime + front->data[2], type, 0 };
	totalMoney += front->data[1];
	eventList.enQueneInOrder(leave);
	return 0;
}

int BankAdvanced::getSmallerListNum()
{
	int min = customerList[0].getLength(), minNum = 2;
	for (int i = 1; i < listNum; i++)
	{
		if (customerList[i].getLength() < min)
		{
			min = customerList[i].getLength();
			minNum = i + 2;
		}
	}
	return minNum;
}
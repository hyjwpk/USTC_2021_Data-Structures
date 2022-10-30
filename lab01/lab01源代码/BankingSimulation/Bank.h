#pragma once
#include"Quene.h"

class Bank
{
public:
	/**
	 * @brief 构造函数
	 * @details 存取金额范围为 [-moneyScope, moneyScope-1]
	 * @details 处理业务时间范围为 [1,durationScope]
	 * @details 到来间隔时间范围为 [1,intertimeScope]
	 * @param totalMoney 总金额
	 * @param closeTime 营业时间
	 * @param moneyScope 客户存取金额范围
	 * @param durationScope 客户处理业务时间范围
	 * @param intertimeScope 客户到来间隔时间范围
	*/
	Bank(const int totalMoney, const int closeTime, const int moneyScope, const int durationScope, const int intertimeScope);

	/**
	 * @brief 处理事件
	 * @details data[1]存储事件种类Type，0-到达事件， 1-withdrawMoneyList离开事件，2-customerList1离开事件
	 * @deatils 事件的发生时间必须小于closeTime
	*/
	void handleEvent();
	bool isEventListNotEmpty();

	/**
	 * @brief 输出模拟结果
	 * @return 客户平均耗时
	*/
	int printResult();

	/**
	 * @brief 输出当前银行状态
	*/
	void printCurrentCondition();
	Quene withdrawMoneyList;
	Quene customerList1;
	Quene eventList;

	/**
	* @brief 总金额
	*/
	int totalMoney;


private:

	/**
	 * @brief 营业时间
	*/
	int closeTime;

	/**
	 * @brief 客户总等待时间
	*/
	int totalTime;

	/**
	 * @brief 客户总等待时间
	*/
	int customerNum;

	bool dealingWithdrawMoneyList;
	int moneyScope;
	int durationScope;
	int intertimeScope;
	int bottomMoney;

	/**
	 * @brief 处理客户的离开事件
	 * @param leaveTime 离开事件的发生时间
	 * @param type 1-withdrawMoneyList 2-customerList1
	*/
	void departure(const int leaveTime, const int type);
	void customerArrived(const int arriveTime);

	/**
	 * @brief 检查并处理withdrawMoneyList中的客户
	 * @details 每次检查队头客户，若银行钱不够取则将将该客户排到队尾
	 * @details 直到所有客户都被检查一遍
	 * @details 或者银行钱已经少于上一个客户存钱之前的金额
	 * @param startTime 上一个存钱客户的离开时间
	*/
	void withdrawMoneyListCheck(const int startTime);

	/**
	 * @brief 生成离开事件并插入事件表
	 * @details 插入的客户一定在队头
	 * @details 若银行钱足够并且能在营业时间完成则插入成功
	 * @param startTime 开始处理顾客的时间
	 * @param type 1-withdrawMoneyList 2-customerList1
	 * @return 0-插入成功 -1-银行缺钱 1-超出营业时间
	*/
	int generateLeaveEvent(const int startTime, const int type);
};
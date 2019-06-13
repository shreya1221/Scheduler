
#pragma once
#ifndef NR_SCHEDULAR_PRIORITY_H
#define NR_SCHEDULART_PRIORITY_H

#include<iostream>
#include<fstream>
#include<string>
#include "Non_Recurring.h"


class NR_Schedular_Priority :public Non_Recurring
{
	int Prio;
public:
	NR_Schedular_Priority();
	void setprio(int x);
	int getprio();
	void display();
	~NR_Schedular_Priority();
	int gettype();

};
#endif // !Non_Recurring_H


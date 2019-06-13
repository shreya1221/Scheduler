#pragma once
#ifndef NR_S_FCFS
#define NR_S_FCFS

#include<iostream>
#include<fstream>
#include<string>
#include "Non_Recurring.h"

class NR_Schedular_FCFS:public Non_Recurring
{
public:
	NR_Schedular_FCFS();
	void display();
	~NR_Schedular_FCFS();
	int gettype();
};

#endif // !NR_S_FCFS

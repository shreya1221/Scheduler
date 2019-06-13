#pragma once
#ifndef NR_SCHEDULAR_SJF_H
#define NR_SCHEDULAR_SJF_H

#include<iostream>
#include<fstream>
#include<string>
#include<deque>
#include"PCB.h"

#include "Non_Recurring.h"
class NR_Schedular_SJF:public Non_Recurring
{
public:
	NR_Schedular_SJF();
	void display();
	~NR_Schedular_SJF();
	int gettype();

};
#endif 

#pragma once
#ifndef R_SCHEDULAR_PRIORITY_H
#define R_SCHEDULAR_PRIORITY_H

#include<iostream>
#include<fstream>
#include<string>
#include "Recurring.h"

class R_Schedular_Priority :public Recurring
{
	int Prio;
public:
	R_Schedular_Priority();
	void setprio(int x);
	int getprio();
	void display();
	~R_Schedular_Priority();
	int gettype();

};
#endif 


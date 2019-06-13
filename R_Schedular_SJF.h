#pragma once
#ifndef R_SCHEDULAR_SJF_H
#define R_SCHEDULAR_SJF_H

#include<iostream>
#include<fstream>
#include<string>
#include "Recurring.h"
class R_Schedular_SJF :public Recurring
{
public:
	R_Schedular_SJF();
	void display();
	~R_Schedular_SJF();
	int gettype();

};
#endif 


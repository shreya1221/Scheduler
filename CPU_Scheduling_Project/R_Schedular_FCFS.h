#pragma once
#ifndef R_SCHEDULAR_FCFS_H
#define R_SCHEDULAR_FCFS_H

#include<iostream>
#include<fstream>
#include<string>
#include "Recurring.h"

class R_Schedular_FCFS :public Recurring
{
public:
	R_Schedular_FCFS();
	void display();
	~R_Schedular_FCFS();
	int gettype();

};
#endif 


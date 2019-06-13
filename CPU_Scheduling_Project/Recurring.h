#ifndef RECURRING_H
#define RECURRING_H

#include<iostream>
#include<fstream>
#include<string>
#include<deque>
#include<iterator>
#include<string.h>
#include "PCB.h"

class Recurring :public PCB
{
  
public:
	//int Sleep;
	Recurring();
	void display();
	~Recurring();
	virtual int gettype();
	int gettyper();
   

};
#endif 


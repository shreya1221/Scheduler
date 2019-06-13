#ifndef NON_RECURRING_H
#define NON_RECURRING_H

#include<iostream>
#include<fstream>
#include<string>
#include<deque>
#include<iterator>
#include<string.h>
#include "PCB.h"

class Non_Recurring: public PCB
{
public:
	Non_Recurring();
	void display();
	~Non_Recurring();
	virtual int gettype();
    int gettyper();
};
#endif 

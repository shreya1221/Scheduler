#pragma once
#ifndef PCB_H
#define PCB_H

#include<iostream>
#include<fstream>
#include<ostream>
#include<deque>
#include<string>

class PCB
{

	int id;
	int  arrtime, starttime, endtime, bursttime, waittime, turnaroundtime;
public:
	int Sleep=0;
	int counter = 1;
	PCB();
	int getid();
	int getarrtime();
	int getbursttime();
	int getendtime();
	int getwaittime();
	int getstarttime();
	int getturnaroundtime();
	void setid(int);
	void setarrtime(int);
	void setbursttime(int);
	void setstarttime(int);
	void setendtime(int);
	void setwaittime(int);
	void setturnaroundtime(int);
	virtual void display();
	virtual int gettype()=0;
	virtual int gettyper();
	
};
#endif

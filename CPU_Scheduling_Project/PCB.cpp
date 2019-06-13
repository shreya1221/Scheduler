#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "PCB.h"
using namespace std;
PCB::PCB()
{
	
	/*id = 0;
	arrtime = 0;
	bursttime = 0;
	starttime = 0;
	endtime = 0;
	nq = 0; dq = 0;*/
}

void PCB::display()
{
	cout << "\n" << "Data";
	cout << "\n" << "ID" << id;
	cout << "\n" << "Arr time" << arrtime;
	cout << "\n" << "burst time" << bursttime;
}
int PCB::getid()
{
	return id;
}

int PCB::getbursttime()
{
	return bursttime;
}int PCB::getarrtime()
{
	return arrtime;
}
int PCB::getstarttime()
{
	return starttime;
}
int PCB::getendtime()
{
	return endtime;
}
int PCB::getwaittime()
{
	return waittime;
}
int PCB::getturnaroundtime()
{
	return turnaroundtime;
}
void PCB::setid(int idnum)
{
	id = idnum;
}
void PCB::setarrtime(int at)
{
	arrtime = at;
}
void PCB::setbursttime(int bt)
{
	bursttime = bt;
}
void PCB::setstarttime(int st)
{
	starttime = st;
}
void PCB::setwaittime(int wt)
{
	waittime = wt;
}
void PCB::setturnaroundtime(int tt)
{
	turnaroundtime = tt;
}
void PCB::setendtime(int et)
{
	endtime = et;
}
 int PCB::gettyper() {
	return 0;
}
 
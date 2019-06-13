#include<iostream>
#include<fstream>
#include<string>
#include "NR_Schedular_Priority.h"
using namespace std;

NR_Schedular_Priority::NR_Schedular_Priority()
{
	
}


void NR_Schedular_Priority::setprio(int x) {
	Prio = x;

}
int  NR_Schedular_Priority::getprio() {
	return Prio;
}

void NR_Schedular_Priority::display()
{
	Non_Recurring::display();
	cout << "NR_Schedular_Priority" << endl;
	cout << "priority" << Prio << endl;;
	PCB::display();

}
NR_Schedular_Priority::~NR_Schedular_Priority()
{
}

int NR_Schedular_Priority::gettype() {
	return 1;
}
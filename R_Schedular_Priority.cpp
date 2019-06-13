#include<iostream>
#include<fstream>
#include<string>
#include "R_Schedular_Priority.h"
using namespace std;
R_Schedular_Priority::R_Schedular_Priority()
{
	
}
void R_Schedular_Priority::setprio(int x) {
	Prio = x;

}
int  R_Schedular_Priority::getprio() {
	return Prio;
}

void R_Schedular_Priority::display()
{
	Recurring::display();
	cout << "R_Schedular_Priority" << endl;
	cout << "Piority" << Prio<<endl;
	PCB::display();

}

R_Schedular_Priority::~R_Schedular_Priority()
{
}

int R_Schedular_Priority::gettype() {
	return 1;
}

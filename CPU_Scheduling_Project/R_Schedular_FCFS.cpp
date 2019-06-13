#include<iostream>
#include<fstream>
#include<string>
#include "R_Schedular_FCFS.h"
using namespace std;
R_Schedular_FCFS::R_Schedular_FCFS()
{
	
}

void R_Schedular_FCFS::display()
{
	Recurring::display();
	cout << "R_Schedular_FCFS" << endl;
	PCB::display();
	

}

R_Schedular_FCFS::~R_Schedular_FCFS()
{
}

int R_Schedular_FCFS::gettype() {
	return 3;
}

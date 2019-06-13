#include<iostream>
#include<fstream>
#include<string>
#include "NR_Schedular_FCFS.h"

using namespace std;


NR_Schedular_FCFS::NR_Schedular_FCFS() {
	

}
void NR_Schedular_FCFS::display()
{
	Non_Recurring::display();
	cout << "NR_Schedular_FCFS" << endl;
	
	PCB::display();
	
}
NR_Schedular_FCFS::~NR_Schedular_FCFS() {

}

int NR_Schedular_FCFS::gettype() {
	return 3;
}

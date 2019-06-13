#include<iostream>
#include<fstream>
#include<string>
#include "R_Schedular_SJF.h"
using namespace std;
R_Schedular_SJF::R_Schedular_SJF()
{
	
}
void R_Schedular_SJF::display()
{
	Recurring::display();
	cout << "R_Schedular_SJF" << endl;

	PCB::display();

}

R_Schedular_SJF::~R_Schedular_SJF()
{
}

int R_Schedular_SJF::gettype() {
	return 2;
}
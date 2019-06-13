#include<iostream>
#include<fstream>
#include<string>
#include "NR_Schedular_SJF.h"

using namespace std;



NR_Schedular_SJF::NR_Schedular_SJF()
{
	
}
void NR_Schedular_SJF::display()
{
	Non_Recurring::display();
	cout << "NR_Schedular_SJF" << endl;

	PCB::display();

}


NR_Schedular_SJF::~NR_Schedular_SJF()
{
}

int NR_Schedular_SJF::gettype() {
	return 2;
}
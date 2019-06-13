#include<iostream>
#include<fstream>
#include<string>
#include "Recurring.h"
#include"Schedular.h"

using namespace std;
Recurring::Recurring()
{
	//cout << "Recurring" << endl;
}
void Recurring::display()
{
	cout << "\n"<<endl<<"Recurring "<<endl;
	//PCB::display();

}

Recurring::~Recurring()
{
}

int Recurring::gettype() {
	return 0;
}
int Recurring::gettyper() {
	return 1;
}

		
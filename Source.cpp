#include<iostream>
#include<deque>
#include<cstdio>
#include<string>
#include<time.h>
#include"NR_Schedular_SJF.h"
#include"R_Schedular_Priority.h"
#include "Schedular.h"
#include"TimingWheel.h"
using namespace std;
int main()
{
	cout << "CPU Scheduling Project" << endl;
	//deque<PCB*> pri, sjf, fcfs;
	Schedular my_sch;
	int prob, prior;
	string infile;
	PCB *bp;
	TimingWheel t;

	//cout<<"Probability of PCB Arrival (%):\n";
	//cin>>prob;
	my_sch.set_arr_prob(60);
	//cout << "level of priority:\n";
	//cin >> prior;
	my_sch.set_level_prior(3);

	//cout<<"Please specify the file name that contains the PCB generation specs \n";
	//cin>>infile;
	my_sch.loadInput("infile.txt");

	srand(time(NULL));
	for (int i = 0; i <= 10; i++)
	{

		bp = my_sch.gen_init_pool();
		//cout << endl;
		if (bp == 0)
		{
			cout << "\n pcb not generated";
		}
		else
		{
			my_sch.loadPCB(bp);
			//cout << "\n PCB generated:";
			bp->display();


			getchar();
		}
	}
	my_sch.showQueue();
	t.schedule(my_sch);
	delete bp;


	getchar();

	//cout << "sequence of hierarchy when we call recurring schedular Priority"<<endl;
	//R_Schedular_Priority rsp;
	return 0;
}

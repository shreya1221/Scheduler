#include<iostream>
#include<fstream>
#include<deque>
#include<iterator>
#include<string.h>
#include<sstream>
#include<time.h>
#include "Schedular.h"
using namespace std;
Schedular::Schedular()
{
}
	

void Schedular::set_arr_prob(int prob) {
	probab = prob;
}
void Schedular::set_level_prior(int l) {
	level = l;
}
/*
int Schedular::getmaxburst()
{
	if (pri_max_burst > sjf_max_burst)
	{
		if (pri_max_burst > fcfs_max_burst)
		{
			max_burst = pri_max_burst;
		}
		else 
		{
			max_burst = fcfs_max_burst;
		}
	}
	else
	{
		if (sjf_max_burst > fcfs_max_burst)
		{
			max_burst=sjf_max_burst;
		}
		else
		{
			max_burst = fcfs_max_burst;
		}
	}
	return max_burst;
}*/
void Schedular::loadInput(string infile) {
	fstream f;
	f.open(infile);
	string line;
	getline(f, line);
	int temp, i = 1;
	while (getline(f, line))
	{
		istringstream iss(line);
		string id;
		while (iss >> id)
		{
			switch (i) {
			case 1:
				iss >> temp;
				min_sleep = temp;
				iss >> temp;
				max_sleep = temp;
				break;
			case 2:
				iss >> temp;
				min_starv = temp;
				iss >> temp;
				max_starv = temp;

				break;
			case 3:
				iss >> pri_prob;
				iss >> id;
				iss >> pri_prob_r;
				iss >> id;
				iss >> pri_prob_nr;
				iss >> id;
				iss >> pri_min_burst;
				iss >> pri_max_burst;
				break;
			case 4:
				iss >> sjf_prob;
				iss >> id;
				iss >> sjf_prob_r;
				iss >> id;
				iss >> sjf_prob_nr;
				iss >> id;
				iss >> sjf_min_burst;
				iss >> sjf_max_burst;
				break;
			case 5:
				iss >> fcfs_prob;
				iss >> id;
				iss >> fcfs_prob_r;
				iss >> id;
				iss >> fcfs_prob_nr;
				iss >> id;
				iss >> fcfs_min_burst;
				iss >> fcfs_max_burst;
				break;
			default:
				cout << "Default";
				break;
			}
			i++;

		}
	}
	/*
	cout << "\n" << "Min sleep" << min_sleep << " " << "max sleep" << max_sleep;
	cout << "\n" << "min starv" << min_starv << " " << "max starv" << max_starv;
	cout << "\n" << "priority" << pri_prob << "Pri recc " << pri_prob_r << " pri nr " << pri_prob_nr << " b " << pri_min_burst << " " << pri_max_burst;
	cout << "\n" << "sjf " << sjf_prob << "sjf recc " << sjf_prob_r << " sjf nr " << sjf_prob_nr << " b " << sjf_min_burst << " " << sjf_max_burst;
	cout << "\n" << "fcfs" << fcfs_prob << "fcfs recc " << fcfs_prob_r << " fcfs nr " << fcfs_prob_nr << " b " << fcfs_min_burst << " " << fcfs_max_burst;
	cout << endl;
	*/
}
PCB* Schedular::gen_init_pool()
{
	int r, pr;
	
	 r = rand() % 100+1;
	//cout << "max prior  ";
	//cout << "\n" << r;
	if (r <= probab) {
		//srand(time(NULL));

		 pr = rand() % 60 + 1;
		//cout << " pr  " << pr;
		if (pr >= 1 && pr <= (probab*pri_prob / 100)) //for pririty
		{
			if (pr == 1)
			{
				id++;
				//cout << "recurring";
				//recurring priority
				rp =new R_Schedular_Priority;
				rp->setid(id);
				rp->setarrtime(id);
				
				int r2 = rand() % pri_max_burst + 1;
				rp->setbursttime(r2);
				
				int r3 = rand() % level + 1;
				rp->setprio(r3);
				//cout << "r prio" << endl;
				//cout << "r"<<r << "r1" << r1;
				//p = &rp;
				return rp;
			}
			else {
				//non-recurring priority
				id++;

				nrp =new NR_Schedular_Priority;
				nrp->setid(id);
				nrp->setarrtime(id);
				int r2 = rand() % pri_max_burst+1;
				nrp->setbursttime(r2);
				int r3 = rand() % level + 1;
				nrp->setprio(r3);
				//p = &nrp;
				return nrp;
				
				//cout << "nr prio" << endl;
				//cout << "r" << r << "r1" << r1;
			}
		}
		else if (((probab*pri_prob / 100) + 1) <= pr && pr < ((probab*pri_prob / 100) + (probab*sjf_prob / 100)))
		{
			if (pr > 1 && pr <= ((probab*pri_prob / 100)*pri_prob_r) / 100)
			{
				id++;
				//recurring sjf
				rs =new R_Schedular_SJF;
				rs->setid(id);
				rs->setarrtime(id);
				int r2 = rand() % (sjf_max_burst-pri_min_burst) + sjf_min_burst;
				rs->setbursttime(r2);
				//p = &rs;
				//cout << "r sjf" << endl;
				//cout << "r" << r << "r1" << r1;
				return rs;
			}
			else {
				//non-recurring sjf
				id++;
				nrs =new NR_Schedular_SJF;
				nrs->setid(id);
				nrs->setarrtime(id);
				
				int r2 = rand() % (sjf_max_burst-sjf_min_burst) + sjf_min_burst;
				nrs->setbursttime(r2);
				//p = &nrs;
				return nrs;
				
				//cout << "nr sjf" << endl;
				//cout << "r" << r << "r1" << r1;
			}


		}
		else if (pr >= ((fcfs_prob*probab) / 100 )&& pr <= probab)
		{
			int fcfsp = (fcfs_prob*probab) / 100;
			//cout << "fcfsp"<<fcfsp;
			if (pr >= (fcfsp) && pr <=((fcfsp)+((fcfsp*fcfs_prob_r)/100)))
			{
					//recurring fcfs
				id++;
					rf =new R_Schedular_FCFS;
					rf->setid(id);
					rf->setarrtime(id);
					
					int r2 = rand() % fcfs_max_burst + 1;
					rf->setbursttime(r2);
					//p = &rf;
					return rf;
					//cout << r << "" << r1;
				//cout << "r fcfs" << endl;
			//cout << "r" << r << "r1" << r1;
		}
		else {
			//non-recurring fcfs
			id++;
			nrf =new NR_Schedular_FCFS;
			nrf->setid(id);
			nrf->setarrtime(id);
			//p = &nrf;
			int r2 = rand() % fcfs_max_burst + 1;
			nrf->setbursttime(r2);
			return nrf;
			//cout << "nr fcfs" << endl;
			//cout << "r" << r << "r1" << r1;
		}

	
		}
		
	}
	else {
		//cout << "PCB not generated";
		return NULL;
	}
	//srand(time(NULL));
	getchar();

}
void Schedular::loadPCB(PCB *pjob)
{
	//if (pjob != 0) {
		if (pjob->gettype() == 1)
		{
			pri.push_back(pjob);
		}
		else if (pjob->gettype() == 2)
		{
			sjf.push_back(pjob);
		}
		else if (pjob->gettype() == 3)
		{
			fcfs.push_back(pjob);
		}
	//}
//	else
	//	pjob++;

}
void Schedular::showQueue()
{
	deque <int>::size_type spri = pri.size();
	deque <int>::size_type ssjf =sjf.size();
	deque <int>::size_type sfcfs = fcfs.size();
	if (!pri.empty())
	{
		//cout << "\n";
		//cout << "                 PCB Priority Queue(";
		cout << "(";
		for (unsigned int i = 0; i < spri; i++)
		{
			cout << "PCB#"; 
			cout<<pri[i]->getid();
		}
		cout << ")";
	}
	else
		cout << " Queue Empty";

if (!sjf.empty())
{
	//cout << "\n";
	//cout << "                 PCB SJF Queue(";
	cout << "(";
	for (unsigned int i = 0; i < ssjf; i++)
	{
		

		cout << "PCB#";
		cout << sjf[i]->getid();
	}
	cout << ")";
}
else
cout << " Queue Empty";

 if (!fcfs.empty())
{
	// cout << "\n";
	//cout << "                 PCB FCFS Queue(";
	 cout << "(";
	for (unsigned int i = 0; i < sfcfs; i++)
	{
		
		cout << "PCB#";
		cout << fcfs[i]->getid();
	}
	cout << ")";
 }
else
cout << " Queue Empty";
}
void Schedular::sleepupdate()
{
	deque <int>::size_type ssleep = sleep.size();
	for (unsigned int i = 0; i < ssleep; i++)
	{
		if(sleep[i]->Sleep<30)
		 sleep[i]->Sleep++;
	}
}



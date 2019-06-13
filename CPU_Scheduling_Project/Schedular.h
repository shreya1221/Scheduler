#pragma once
#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include<iostream>
#include<fstream>
#include<string>
#include<deque>
#include<iterator>
#include<string.h>
#include"PCB.h"
#include "NR_Schedular_Priority.h"
#include "NR_Schedular_SJF.h"
#include "NR_Schedular_FCFS.h"
#include "R_Schedular_FCFS.h"
#include "R_Schedular_Priority.h"
#include "R_Schedular_SJF.h"

using namespace std;
class Schedular
{
	int probab,level;
	int pri_prob, pri_prob_r, pri_prob_nr, pri_min_burst, pri_max_burst;
	int sjf_prob, sjf_prob_r, sjf_prob_nr, sjf_min_burst, sjf_max_burst;
	int fcfs_prob, fcfs_prob_r, fcfs_prob_nr, fcfs_min_burst, fcfs_max_burst;
	int id=0, clock=0;
	R_Schedular_Priority* rp;
	NR_Schedular_Priority* nrp;
	R_Schedular_SJF* rs;
	NR_Schedular_SJF* nrs;
	R_Schedular_FCFS* rf;
	NR_Schedular_FCFS* nrf;

	PCB *p;

public:
	int  min_sleep, max_sleep, min_starv, max_starv;
	deque<PCB*> pri, sjf, fcfs,sleep;
	PCB* current[4];
	//static int max_burst;
	Schedular();
	//int getmaxburst();
	void loadInput(string infile);
	void set_arr_prob(int prob);
	void set_level_prior(int l);
	PCB* gen_init_pool();
	void loadPCB(PCB *);
	void showQueue();
	void sleepupdate();
	//~Schedular();
};
#endif

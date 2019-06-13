#include"Partition.h"
#include"Schedular.h"
#include"PCB.h"
#define MAX_BURST 10
class TimingWheel {

	Partition * slot[MAX_BURST+1];
	//max_delay (max burst time of a job/PCB)
	int current_slot=0;
	int endtime=50;
	int count= 0;
	PCB* p;

public:
	TimingWheel();
	void printstatus(Schedular &);
	void insert(Schedular &,int burst_time, int CPU_num, PCB* p1);
	void schedule(Schedular &);
	void clear_curr_slot(int);
};
#pragma once

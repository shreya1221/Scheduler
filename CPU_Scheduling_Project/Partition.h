#include"PCB.h"
class Partition {

	PCB* pb;
	int cpu;
	Partition *nextp;

public:
	Partition();
	void setcpunum(int);
	void setpb(PCB *);
	void setnext(Partition *);
	int getcpunum();
	PCB* getpb();
	Partition* getnext();
	// all needed accessor functions

};
#pragma once

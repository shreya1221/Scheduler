#include<iostream>
#include"Partition.h"
#include"pcb.h"
 Partition::Partition()
{
	pb = NULL;
	cpu = NULL;
	nextp = NULL;

}
void Partition::setcpunum(int c)
{
	cpu = c;
}
int Partition::getcpunum()
{
	return cpu;
}
void Partition::setpb(PCB* p)
{
	pb = p;
}
void Partition::setnext(Partition *n)
{
	nextp = n;
}
PCB* Partition::getpb()
{
	return pb;
}
Partition* Partition::getnext()
{
	return nextp;
}
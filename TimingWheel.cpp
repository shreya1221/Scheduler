#include"Partition.h"
#include"TimingWheel.h"
#include"Schedular.h"
#include"PCB.h"
#include<time.h>
TimingWheel::TimingWheel()
{
	/*for(int i=0;i<=MAX_BURST+1;i++)
	{
		slot[i] = new Partition();
		slot[i]->setpb(NULL);
	}*/
}
void TimingWheel::insert(Schedular &s, int burst_time, int CPU_num, PCB* p1)
{

	if (slot[(current_slot + burst_time-1) % 10] == NULL)
	{
		slot[(current_slot + burst_time-1) % 10] = new Partition();
		slot[(current_slot+burst_time-1)%10]->setpb(p1);
		slot[(current_slot+burst_time-1)%10]->setcpunum(CPU_num);
		slot[(current_slot+burst_time-1)%10]->setnext(NULL);
	}
	/*Partition *tmp = slot[(current_slot + burst_time - 1) % 10];
	while (tmp->getnext() != NULL)
		tmp = tmp->getnext();
*/
	else if (slot[(current_slot + burst_time - 1) % 10]->getnext() == NULL)

//	else if (slot[(current_slot+burst_time-1)%10]->getnext()->getpb() == NULL)
	{
		Partition *pp = new Partition();
		slot[(current_slot + burst_time-1) % 10]->setnext(pp);
		slot[(current_slot+burst_time-1)%10]->getnext()->setpb(p1);
		slot[(current_slot+burst_time-1)%10]->getnext()->setcpunum(CPU_num);
		slot[(current_slot+burst_time-1)%10]->getnext()->setnext(NULL);
	}
	//else if (slot[(current_slot + burst_time - 1) % 10]->getnext() == NULL)

     else if (slot[(current_slot+burst_time-1)%10]->getnext()->getnext() == NULL)
	{
		Partition *pp = new Partition();
		slot[(current_slot + burst_time-1) % 10]->getnext()->setnext(pp);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->setpb(p1);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->setcpunum(CPU_num);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->setnext(NULL);
	}
	else
	{
		Partition *pp = new Partition();
		slot[(current_slot + burst_time-1) % 10]->getnext()->getnext()->setnext(pp);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->getnext()->setpb(p1);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->getnext()->setcpunum(CPU_num);
		slot[(current_slot+burst_time-1)%10]->getnext()->getnext()->getnext()->setnext(NULL);
	}
	p1->setstarttime(count);
}
		
void  TimingWheel::schedule(Schedular &s)
{
	
	current_slot = 0;
	cout << "\n" << "CPU1	CPU2	CPU3	CPU4	PRIQUEUE	SJFQUEUE	FCFSQUEUE";
	for (int i = 1; i <= 4; i++)
	{
		if (!s.pri.empty())
		{
			p = s.pri.front();
			s.current[i-1] = p;
			insert(s, p->getbursttime(), i, p);
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << i;
			s.pri.pop_front();
		}
		else if (!s.sjf.empty())
		{
			p = s.sjf.front();
			s.current[i-1] = p;
			insert(s, p->getbursttime(), i, p);
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << i;
			s.sjf.pop_front();
		}
		else if (!s.fcfs.empty())
		{
			p = s.fcfs.front();
			s.current[i-1] = p;
			insert(s, p->getbursttime(), i, p);
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << i;
			s.fcfs.pop_front();
		}
	}
	//current_slot = (current_slot + 1) % MAX_BURST;
	//counter++;
	do {
		p = s.gen_init_pool();
		//cout << endl;
		if (p == 0)
		{
			//cout << "\n pcb not generated";
		}
		else
		{
			s.loadPCB(p);
		}
		//current_slot = counter;
printstatus(s);

if (slot[current_slot] != NULL)
//if (slot[counter]->getpb() != NULL)

{

	if (!s.pri.empty())
	{
		do {
			p = s.pri.front();
			insert(s, p->getbursttime(), slot[current_slot]->getcpunum(), p);
			s.current[slot[current_slot]->getcpunum()-1] = p;
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << slot[current_slot]->getcpunum();
			clear_curr_slot(current_slot);
			s.pri.pop_front();
		} while (slot[current_slot]!=NULL);

	}
	//SJF
	if (!s.sjf.empty())
	{
		do {
			p = s.sjf.front();
			insert(s, p->getbursttime(), slot[current_slot]->getcpunum(), p);
			s.current[slot[current_slot]->getcpunum()-1] = p;
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << slot[current_slot]->getcpunum();
			clear_curr_slot(current_slot);

			s.sjf.pop_front();
		} while (slot[current_slot]!=NULL);
	}
	//fcfs
	if (!s.fcfs.empty())
	{
		do {
			if (slot[current_slot] == NULL)
				break;

			p = s.fcfs.front();

			insert(s, p->getbursttime(), slot[current_slot]->getcpunum(), p);
			s.current[slot[current_slot]->getcpunum()-1] = p;
			//cout << "\n" << "process" << p->getid() << " " << "cpunum" << slot[current_slot]->getcpunum();
			clear_curr_slot(current_slot);

			s.fcfs.pop_front();
		} while (slot[current_slot] != NULL);
	}
	current_slot = (current_slot + 1) % MAX_BURST;
	count++;
	s.sleepupdate();
}
else
{
	current_slot = (current_slot + 1) % MAX_BURST;
	count++;
	s.sleepupdate();
}

//srand(time(NULL));


	} while (count < endtime);
}
void  TimingWheel::clear_curr_slot(int pos)
{
	Partition* temp;

	if (slot[pos]->getnext() == NULL)
	{
		//		Partition* temp;// = new Partition();
		temp = slot[pos];
		slot[pos] = NULL;
		delete temp;
	}

	else if (slot[pos]->getnext() != NULL)
	{
		//		Partition* temp;// = new Partition();
		temp = slot[pos];
		slot[pos] = slot[pos]->getnext();
		delete temp;
	}

}
void TimingWheel::printstatus(Schedular &s)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (s.current[i]->counter != s.current[i]->getbursttime()) {


			s.current[i]->counter++;
		}
		else {
			s.current[i]->counter = 1;
			s.current[i]->setendtime(count);

		}
	}
	cout << "\n";
	cout << "" << s.current[0]->getid() << "(" << s.current[0]->counter << "/" << s.current[0]->getbursttime() << ") ";
	cout << "" << s.current[1]->getid() << "(" << s.current[1]->counter << "/" << s.current[1]->getbursttime() << ") ";
	cout << "" << s.current[2]->getid() << "(" << s.current[2]->counter << "/" << s.current[2]->getbursttime() << ") ";
	cout << "" << s.current[3]->getid() << "(" << s.current[3]->counter << "/" << s.current[3]->getbursttime() << ") ";
	s.showQueue();
	
	
}
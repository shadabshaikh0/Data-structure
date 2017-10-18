//============================================================================
// Name        : Assignment9_PriorityQueue.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : Assignment9_Queue.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10
class Priority_Queue
{
	int front,rear,job,djob;
	int PQueue[MAX];
public:
	void init();
	int isfull();
	int isempty();
	void add_job();
	int delete_job();
	void display();
};
void Priority_Queue::init()
{
	front=rear=-1;
}
int Priority_Queue::isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}
int Priority_Queue::isempty()
{
	if(front==-1 && rear==-1 )
		return 1;
	else
		return 0;
}
void Priority_Queue::add_job()
{
int i;
	if(!isfull())
	{
		cout<<"\nEnter job\n";
		cin>>job;
		if(front==-1)
		{
			rear=front=0;
			PQueue[rear]=job;
		}
		else if(job<PQueue[rear])
		{
		i=rear;
			while(job<PQueue[i])
			{
				PQueue[i+1]=PQueue[i];
				i--;
			}
			i++;
			PQueue[i]=job;
			rear++;

		}
		else
		{
			rear=rear+1;
			PQueue[rear]=job;
		}
	}
	else
	{
		cout<<"\nOverflow\n";
	}
}
int Priority_Queue::delete_job()
{
	if(!isempty())
	{
		if(front==rear)
		{
			djob=PQueue[front];
			front=rear=-1;
		}
		else
		{
			djob=PQueue[front];
			front=front+1;
		}
	}
	else
	{
		cout<<"\nUnderflow\n";
	}
return djob;
}
void Priority_Queue::display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<PQueue[i]<<"->";
	}
}
int main()
{
	int options;
	Priority_Queue q;
	q.init();
	do
	{
	cout<<"\n1.Add Job\n";
	cout<<"\n2.Delete Job\n";
	cout<<"\n3.Display Queue\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch (options)
		{
			case 1:
				q.add_job();
				break;
			case 2:
				q.delete_job();
				break;
			case 3:
				q.display();
				break;
			default:
				break;
		}
	}while(options!=0);
	return 0;
}

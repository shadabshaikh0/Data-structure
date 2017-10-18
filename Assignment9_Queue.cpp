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
class Simple_Queue
{
	int front,rear,job,djob;
	int SQueue[MAX];
public:
	void init();
	int isfull();
	int isempty();
	void add_job();
	int delete_job();
	void display();
};
void Simple_Queue::init()
{
	front=rear=-1;
}
int Simple_Queue::isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}
int Simple_Queue::isempty()
{
	if(front==-1 && rear==-1 )
		return 1;
	else
		return 0;
}
void Simple_Queue::add_job()
{

	if(!isfull())
	{
		cout<<"\nEnter job\n";
		cin>>job;
		if(front==-1)
		{
			rear=front=0;
			SQueue[rear]=job;
		}
		else
		{
			rear=rear+1;
			SQueue[rear]=job;
		}
	}
	else
	{
		cout<<"\nOverflow\n";
	}
}
int Simple_Queue::delete_job()
{
	if(!isempty())
	{
		if(front==rear)
		{
			djob=SQueue[front];
			front=rear=-1;
		}
		else
		{
			djob=SQueue[front];
			front=front+1;
		}
	}
	else
	{
		cout<<"\nUnderflow\n";
	}
return djob;
}
void Simple_Queue::display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<SQueue[i]<<"->";
	}
}
int main()
{
	int options;
	Simple_Queue q;
	q.init();
	do
	{
	cout<<"\n1.Add Job\n";
	cout<<"\n2.Delete Job\n";
	cout<<"\n3.Display Queue\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch (options) {
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

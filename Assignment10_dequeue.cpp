//============================================================================
// Name        : Assignment10_dequeue.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
#define MAX 10
class Dequeue
{
	int front,rear,job,djob;
	int Dequeue[MAX];
public:
	void init();
	int isfull();
	int isempty();
	void add_job_at_rear();
	int delete_job_from_front();
	void add_job_at_front();
	int delete_job_from_rear();
	void display();
};
void Dequeue::init()
{
	front=rear=-1;
}
int Dequeue::isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}
int Dequeue::isempty()
{
	if(front==-1 && rear==-1 )
		return 1;
	else
		return 0;
}
void Dequeue::add_job_at_rear()
{

	if(!isfull())
	{
		cout<<"\nEnter job\n";
		cin>>job;
		if(front==-1)
		{
			rear=front=0;
			Dequeue[rear]=job;
		}
		else
		{
			rear=rear+1;
			Dequeue[rear]=job;
		}
	}
	else
	{
		cout<<"\nOverflow\n";
	}
}
int Dequeue::delete_job_from_front()
{
	if(!isempty())
	{
		if(front==rear)
		{
			djob=Dequeue[front];
			front=rear=-1;
		}
		else
		{
			djob=Dequeue[front];
			front=front+1;
		}
	}
	else
	{
		cout<<"\nUnderflow\n";
	}
return djob;
}
void Dequeue::display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<Dequeue[i]<<"->";
	}
}
void Dequeue::add_job_at_front()
{
int i;
	if(!isfull())
	{
		cout<<"\nEnter job\n";
		cin>>job;
		if(front==-1)
		{
			rear=front=0;
			Dequeue[front]=job;
		}
		else
		{
		  for(i=front+rear;i>=0;i--)
		  {
			  Dequeue[i+1]=Dequeue[i];
		  }
		  Dequeue[front]=job;
		  rear=rear+1;
		}
	}
	else
	{
		cout<<"\nOverflow\n";
	}

}
int Dequeue::delete_job_from_rear()
{
	if(!isempty())
	{
		if(front==rear)
		{
			djob=Dequeue[rear];
			front=rear=-1;
		}
		else
		{
			djob=Dequeue[rear];
			rear=rear-1;
		}
	}
	else
	{
		cout<<"\nUnderflow\n";
	}
return djob;

}

int main()
{
	int options;
	Dequeue q;
	q.init();
	do
	{
	cout<<"\n1.Add Job at Rear\n";
	cout<<"\n2.Delete Job from Front\n";
	cout<<"\n3.Add Job at Front\n";
	cout<<"\n4.Delete Job from Rear\n";
	cout<<"\n5.Display Queue\n";

	cout<<"\nEnter your choice\n";
	cin>>options;
		switch (options)
		{
			case 1:
				q.add_job_at_rear();
				break;
			case 2:
				q.delete_job_from_front();
				break;
			case 3:
				q.add_job_at_front();
				break;
			case 4:
				q.delete_job_from_rear();
				break;
			case 5:
				q.display();
				break;
			default:
				break;
		}
	}while(options!=0);
	return 0;
}

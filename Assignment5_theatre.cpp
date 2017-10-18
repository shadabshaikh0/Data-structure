//============================================================================
// Name        : Assignment5_theatre.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

struct node
{
	int flag;
	char name[10];
	node *next;
	node *prev;
};
struct hnode
{
	int count;
	node *next;
};
class Cinemax
{
	hnode *head[11];
	node *temp,*t1,*p;
	int n,i,j,k;
public:
	Cinemax()
	{
		for(i=1;i<=10;i++)
		{
			head[i]=new hnode;
			head[i]->count=0;
			head[i]->next=NULL;
		}
		p=temp=t1=NULL;
		i=j=n=k=0;
	}

	void create();
	void show();
	int bookshow(int,int);
	int cancelshow(int,int);
};
void Cinemax::create()
{
	node *f1;
	for(i=1;i<=10;i++)
	{
		p=new node;
		p->next=NULL;
		p->prev=NULL;
		p->flag=0;
		strcpy(p->name,"NIL");

		if(head[i]->next==NULL)
		{
			head[i]->next=p;
			p->next=p;
			p->prev=p;
		}
		temp=head[i]->next;
		f1=temp;
		for(int k=1;k<=6;k++)
		{
			t1=new node;
			t1->flag=0;
			strcpy(t1->name,"NIL");
			t1->next=head[k]->next;
			temp->next=t1;
			t1->prev=temp;
			f1->prev=t1;
			temp=t1;
		}
	}


}
void Cinemax::show()
{
	cout<<"\nRow status are follows:\n";
	cout<<"\nHead Node\t\tCol1\t\tCol2\t\tCol3\t\tCol4\t\tCol5\t\tCol6\t\tCol7\n";
		for(k=1;k<=10;k++)
		{
			cout<<"\nRow: "<<k<<"["<<head[k]->count<<"]-->\t\t";
			temp=head[k]->next;
			for(i=1;i<=7;i++)
			{
				cout<<"["<<temp->flag<<"|"<<temp->name<<"]->\t";
				temp=temp->next;
			}
		}
}
int Cinemax::bookshow(int r,int n)
{
	cout<<"\nYou request for "<<n<<"tickets\n";
	temp=head[r]->next;
	int max=head[r]->count;
	if(max==7)
	{
		cout<<"\nSorry no available seats in this row \n";
		return 0;
	}
	else
	{
		int seat[5],cnt=0,seatno;
		for(i=0;i<n;i++)
		{
			cout<<"\nEnter seat nos\n";
			cin>>seatno;
			seat[i]=seatno-1;
		}
		i=0;
		while(temp->next!=head[r]->next)
		{
			if(cnt!=seat[i])
			{
				cnt++;
				temp=temp->next;
			}
			else
			{
				if(temp->flag==0)
				{
					temp->flag=1;
					cout<<"\nEnter your name\n";
					cin>>temp->name;
					cnt=0;
					head[r]->count=head[r]->count+1;
					temp=head[r]->next;
					i++;
					if(i==n)
						break;
				}
			}
		}
	}
		if(temp->next==head[r]->next)
		{
			if(temp->flag==0)
			{
				temp->flag=1;
				cout<<"\nEnter your name\n";
				cin>>temp->name;
				head[r]->count=head[r]->count+1;
			}

		}

	return 1;

}
int Cinemax::cancelshow(int r,int n)
{
	cout<<"\nYou request for "<<n<<"tickets\n";
	temp=head[r]->next;
	int max=head[r]->count;
	if(max==0)
	{
		cout<<"\nSorry no available seats in this row for cancel \n";
		return 0;
	}
	else
	{
		int seat[5],cnt=0,seatno;
		for(i=1;i<n;i++)
		{
			cout<<"\nEnter seat nos\n";
			cin>>seatno;
			seat[i]=seatno-1;
		}
		i=0;
		while(temp->next!=head[r]->next)
		{
			if(cnt!=seat[i])
			{
				cnt++;
				temp=temp->next;
			}
			else
			{
				if(temp->flag==1)
				{
					temp->flag=0;
					strcpy(temp->name,"NILL");
					cnt=0;
					head[r]->count=head[r]->count+1;
					temp=head[r]->next;
					i++;
					if(i==n)
						break;
				}
			}
		}
	}
		if(temp->next==head[r]->next)
		{
			if(temp->flag==1)
			{
				temp->flag=0;
				strcpy(temp->name,"NULL");
				head[r]->count=head[r]->count+1;
			}

		}

	return 1;

}
int main()
{
	Cinemax theatre;
	int row,n,success;
	theatre.create();
	int options;
	do
	{
	cout<<"\n1.The list of available seats is to be displayed\n";
	cout<<"\n2.The seats are to be booked \n";
	cout<<"\n3.The booking can be cancelled.\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch (options)
		{
			case 1:
				cout<<"\n The Booking status of the Cinemax Theator are as follows...\n\n";
				theatre.show();
				break;
			case 2:
				theatre.show();
				cout<<"\nEnter the row number to book u r ticket: \n";
				cin>>row;
				cout<<"\nHow many Tickets u want to Book:\n ";
				cin>>n;
				success=theatre.bookshow(row,n);
				if(success!=0)
				{
					theatre.show();
			         cout<<"\n\nYour booking is confirmed please see the status: ..\n\n";
				}
				else
				{
			         cout<<"\n\nTry for another row...\n";
				}
				break;
			case 3:
				cout<<"\nEnter the row number to cancel u r ticket:\n ";
				cin>>row;
				cout<<"\nHow many Tickets u want to cancel:\n ";
				cin>>n;
				if(success!=0)
				{
			         cout<<"\n\nYour booking is canceled please see the status: ..\n\n";
				}
				else
				{
			         cout<<"\n\nTry for another row...\n";
				}
				break;
		}
	}while(options!=0);
	return 0;
}

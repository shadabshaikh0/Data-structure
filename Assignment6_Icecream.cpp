//============================================================================
// Name        : Assignment6_Icecream.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node;
class Butterscotch;
class Vanila
{

	node *head=NULL;
	int n;

public:
	void createlist();
	void display();
	friend int union_of_butterscotch_and_vanila(Vanila,Butterscotch);
	friend void intersection_of_butterscotch_and_vanila(Vanila,Butterscotch);
	friend void only_vanila(Vanila,Butterscotch);
	friend void only_butterscotch(Vanila,Butterscotch);

};
class Butterscotch
{
	node *head=NULL;
	int n;

public:

	void createlist();
	void display();
	friend int union_of_butterscotch_and_vanila(Vanila,Butterscotch);
	friend void intersection_of_butterscotch_and_vanila(Vanila,Butterscotch);
	friend void only_vanila(Vanila,Butterscotch);
	friend void only_butterscotch(Vanila,Butterscotch);

};

void Vanila::createlist()
{
	node *ptr;

	cout<<"\nEnter no of students \n";
	cin>>n;
	cout<<"\nEnter  what student who  like  vanila\n";
	for(int i=1;i<=n;i++)
	{
		node *newnode=new node;
		newnode->next=NULL;
		cin>>newnode->data;
		if(head==NULL)
		{
			head=ptr=newnode;
		}
		else
		{
			ptr->next=newnode;
			ptr=ptr->next;
		}
	}
}

void Vanila::display()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
	cout<<endl;
}

void Butterscotch::createlist()
{
	node *ptr;

	cout<<"\nEnter no of students \n";
	cin>>n;
	cout<<"\nEnter  what student who  like  Butterscotch\n";
	for(int i=1;i<=n;i++)
	{
		node *newnode=new node;
		newnode->next=NULL;
		cin>>newnode->data;
		if(head==NULL)
		{
			head=ptr=newnode;
		}
		else
		{
			ptr->next=newnode;
			ptr=ptr->next;
		}
	}
}

void Butterscotch::display()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
	cout<<endl;
}

int union_of_butterscotch_and_vanila(Vanila v,Butterscotch b)
{
	int cnt=0;
	node *x=v.head;
	node *y;
	int found;
	while(x!=NULL)
	{
		cout<<"\t"<<x->data;
		cnt++;
		x=x->next;
	}

	for(y=b.head;y!=NULL;y=y->next)
	{
		found=0;
		for(x=v.head;x!=NULL;x=x->next)
		{
			if(x->data==y->data)
			{
				found=1;
				break;
			}
		}
		if(found!=1)
		{
			cnt++;
			cout<<"\t"<<y->data;
		}
	}
	return cnt;
}
void intersection_of_butterscotch_and_vanila(Vanila v,Butterscotch b)
{
node *x,*y;
int found;
	for(y=b.head;y!=NULL;y=y->next)
	{
		found=0;
		for(x=v.head;x!=NULL;x=x->next)
		{
			if(x->data==y->data)
			{
				found=1;
				break;
			}
		}
		if(found==1)
		{
			cout<<"\t"<<y->data;
		}
	}

}
 void only_vanila(Vanila v,Butterscotch b)
 {
	 node *x,*y;
	 int found;
		for(x=v.head;x!=NULL;x=x->next)
		{
			found=0;
	 		 	for(y=b.head;y!=NULL;y=y->next)
	 		 	{

	 			if(x->data==y->data)
	 			{
	 				found=1;
	 				break;
	 			}
	 		}
	 		if(found!=1)
	 		{
	 			cout<<"\t"<<x->data;
	 		}
	 	}

 }
 void only_butterscotch(Vanila v,Butterscotch b)
 {
	 node *x,*y;
	 int found;
	 	for(y=b.head;y!=NULL;y=y->next)
	 	{
	 		found=0;
	 		for(x=v.head;x!=NULL;x=x->next)
	 		{
	 			if(x->data==y->data)
	 			{
	 				found=1;
	 				break;
	 			}
	 		}
	 		if(found!=1)
	 		{
	 			cout<<"\t"<<y->data;
	 		}
	 	}

 }

int main()
{
	Vanila v;
	Butterscotch b;
	int m,c=0;
	cout<<"\nEnter total no of students\n";
	cin>>m;
	int options;
	do
	{
	cout<<"\n1.Create list\n";
	cout<<"\n2.Display lists\n";
	cout<<"\n3.Set of students who like either vanilla or butterscotch or both  Set of students who like both vanilla and butterscotch \n";
	cout<<"\n4.Set of students who like both vanilla and butterscotch \n";
	cout<<"\n5.Set of students who like only vanilla not butterscotch \n";
	cout<<"\n6.Set of students who like only butterscotch not vanilla \n";
	cout<<"\n7.Number of students who like neither vanilla nor butterscotch.\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch(options)
		{
		case 1:
			cout<<"\nSet of student who like vanila\n";
			v.createlist();
			cout<<"\nSet of student who like Butterscotch\n";
			b.createlist();
			break;
		case 2:
			cout<<"\nSet of student who like vanila\n";
			v.display();
			cout<<"\nSet of student who like Butterscotch\n";
			b.display();
			break;
		case 3:
			cout<<"\nSet of students who like either vanilla or butterscotch or both  Set of students who like both vanilla and butterscotch \n";
			c=union_of_butterscotch_and_vanila(v,b);
			break;
		case 4:
			cout<<"\nSet of students who like both vanilla and butterscotch \n";
			intersection_of_butterscotch_and_vanila(v,b);
			break;
		case 5:
			cout<<"\nSet of students who like only vanilla not butterscotch \n";
			only_vanila(v,b);
			break;
		case 6:
			cout<<"\nSet of students who like only butterscotch not vanilla \n";
			only_butterscotch(v,b);
			break;
		case 7:
			cout<<"\nNumber of students who like neither vanilla nor butterscotch :"<<m-c;
			break;
		}
	}while(options!=0);
	return 0;
}

//============================================================================
// Name        : Assignment5_binarynumber.cpp
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
	struct node *next,*prev;
}node;

class Binaryop
{
	node *head=NULL;
	int sum,carry;
public:
	void create();
	void display();
	void onescomplement();
	void twoscomplement();
	Binaryop addition(Binaryop b);
	void add(int value)
	{
		node *sumlist=new node;
		sumlist->data=value;
		sumlist->next=NULL;
		sumlist->prev=NULL;
		if(head==NULL)
		{
			head=sumlist;
		}
		else
		{
			sumlist->next=head;
			head->prev=sumlist;
			head=sumlist;
		}
	}
};

void Binaryop::create()
{
	node *newnode,*ptr;
	int n;
	cout<<"Enter how many digits of your binary number is:\n";
	cin>>n;

	cout<<"\nEnter binary number\n";
	for(int i=1;i<=n;i++)
	{
		newnode=new node;
		cin>>newnode->data;
		newnode->next=NULL;
		newnode->prev=NULL;
			if(head==NULL)
			{
				head=ptr=newnode;
			}
			else
			{
				ptr->next=newnode;
				newnode->prev=ptr;
				ptr=ptr->next;
			}
	}

}
void Binaryop::display()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<"  "<<ptr->data;
		ptr=ptr->next;
	}
}
void Binaryop::onescomplement()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==1)
		{
			ptr->data=0;
		}
		else
		{
			ptr->data=1;
		}
		ptr=ptr->next;
	}

}
void Binaryop::twoscomplement()
{
	onescomplement();
	int carry=1;
	node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	while(ptr!=NULL)
	{
		if(ptr->data==1 && carry==1)
		{
			ptr->data=0;
			carry=1;
		}
		else if(ptr->data==0 && carry==1)
		{
			ptr->data=1;
			carry=0;
		}
		else
		{
			if(carry==0)
				break;
		}
		ptr=ptr->prev;
	}
}
Binaryop Binaryop:: addition(Binaryop b)
{
	Binaryop sum;
	node *n1=head;
	node *n2=b.head;
	cout<<"hi";
	int  carry=0;
	while(n1->next!=NULL)
	{
		n1=n1->next;
	}
	while(n2->next!=NULL)
	{
		n2=n2->next;
	}
	while(n1!=NULL && n2!=NULL)
	{
			sum.add(n1->data ^ n2->data ^ carry);
			carry=((n1->data && n2->data)||(n1->data && carry)|| (n2->data && carry));
			n1=n1->prev;
			n2=n2->prev;
	}
			while(n1!=NULL)
			{
				sum.add(n1->data^carry);
				if(n1->data==1 && carry==1)
				{
					carry=1;
				}
				else if(n1->data==0 && carry==1)
				{
					carry=0;
				}
				n1=n1->prev;
			}
			while(n2!=NULL)
			{
				sum.add(n2->data^carry);
				if(n2->data==1 && carry==1)
				{
					carry=0;
				}
				else if(n2->data==0 && carry==1)
				{
					carry=1;
				}
				n2=n2->prev;
			}

	sum.add(carry);
	return sum;
}
int main()
{
	int options;
	Binaryop num1,num2,num3;
	do
	{
	cout<<"\n1.Ones Complement\n";
	cout<<"\n2.Twos Complement\n";
	cout<<"\n3.Binary Addition\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch(options)
		{
		case 1:
			num1.create();
			cout<<"\nBefore ones complement\n";
			num1.display();
			num1.onescomplement();
			cout<<"\nAfter ones complement\n";
			num1.display();
			break;
		case 2:
			num1.create();
			cout<<"\nBefore Twos complement\n";
			num1.display();
			num1.twoscomplement();
			cout<<"\nAfter Twos complement\n";
			num1.display();
			break;
		case 3:
			cout<<"\nEnter two binary numbers\n";
			num1.create();
			num2.create();
			cout<<"byt";
			num3=num1.addition(num2);
			cout<<"\nAddition is:\n";
			num3.display();
			break;
		}
	}while(options!=0);
	return 0;
}

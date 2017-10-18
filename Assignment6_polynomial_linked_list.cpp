//============================================================================
// Name        : Assignment6_polynomial_linked_list.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<math.h>
using namespace std;
typedef struct node
{
	int coeff,exp;
	struct node *next;
}node;
class polynomial_linkedlist
{
	int degree;
	node *head=NULL;
public:
	void input();
	void display();
	void evaluate();
	void addition();
/*	polynomial_linkedlist addition(polynomial_linkedlist q);
	void add(int coeff,int exp)
	{
		node *newnode=new node;
		newnode->coeff=coeff;
		newnode->exp=exp;
			if(head==NULL)
			{
				head=newnode;
				head=head->next;
			}
			else
			{
				newnode->next=head->next;
					head->next=newnode;
					head=newnode;
			}
	}
*/
};
void polynomial_linkedlist::input()
{
	cout<<"\nEnter degree of linked list\n";
	cin>>degree;
	cout<<"\nEnter coefficient and exponent\n";
	for(int i=degree;i>=0;i--)
	{
		cout<<"hi\n";
		node *newnode=new node;
		newnode->next=newnode;
		cin>>newnode->coeff;
		cin>>newnode->exp;
		if(head==NULL)
		{
			head=newnode;
			head->next=head;
		}
		else
		{
			newnode->next=head->next;
			head->next=newnode;
			head=newnode;
		}

	}

}
void polynomial_linkedlist::display()
{
	node *ptr=head->next;
	do
	{
		cout<<"("<<ptr->coeff<<"x^"<<ptr->exp<<")+";
		ptr=ptr->next;
	}while(ptr!=head->next);
}

void polynomial_linkedlist::evaluate()
{
	int result=0;
	node *ptr=head->next;
	int x;
	cout<<"\nEnter value of x\n";
	cin>>x;
			do
			{
				result+=ptr->coeff*pow(x,ptr->exp);
				ptr=ptr->next;
			}while(ptr!=head->next);
		cout<<"\nEvaluation:"<<result<<endl;
}
/*
polynomial_linkedlist polynomial_linkedlist::addition(polynomial_linkedlist p)
{
	polynomial_linkedlist sum;

	node *n1=head->next;
	node *n2=p.head->next;
			do
			{
				if(n1->exp>n2->exp)
				{
					sum.add(n1->coeff,n1->exp);
					n1=n1->next;
				}
				else if(n1->exp<n2->exp)
				{
					sum.add(n2->coeff,n2->exp);
					n2=n2->next;
				}
				else
				{
					sum.add(n1->coeff+n2->coeff,n1->exp);
					n1=n1->next;
					n2=n2->next;
				}

			}while(n1!=head->next || n2!=head->next);

			do
			{
				sum.add(n1->coeff,n1->exp);
				n1=n1->next;
			}while(n1!=head->next);

			do
			{
				sum.add(n2->coeff,n2->exp);
				n2=n2->next;
			}while(n2!=head->next);

	return sum;
}
*/
void polynomial_linkedlist::addition()
{
	polynomial_linkedlist nn1,nn2;
	cout<<"hiiiiiiiiii";
	nn1.input();
	nn2.input();
	cout<<"hi";
	node *n1=nn1.head->next;
	node *n2=nn2.head->next;
	node *r3,*n3;
			do
			{
				if(n3==NULL)
				{
					n3=r3=new node;
					n3->next=n3;
				}
				else
				{
					r3->next=new node;
					r3=r3->next;
					r3->next=n3;
				}

				if(n1->exp>n2->exp)
				{
					r3->exp=n1->exp;
					r3->coeff=n1->coeff;
					n1=n1->next;
				}
				else if(n1->exp<n2->exp)
				{
					r3->exp=n2->exp;
					r3->coeff=n2->coeff;
					n2=n2->next;
				}
				else
				{
					r3->exp=n1->exp;
					r3->coeff=n1->coeff+n2->coeff;
					n1=n1->next;
					n2=n2->next;
				}

			}while(n1!=head->next || n2!=head->next);

			do
			{
				if(n3==NULL)
				{
					n3=r3=new node;
					n3->next=n3;
				}
				else
				{
					r3->next=new node;
					r3=r3->next;
					r3->next=n3;
				}
				r3->exp=n1->exp;
				r3->coeff=n1->coeff;
				n1=n1->next;
			}while(n1!=head->next);

			do
			{
				if(n3==NULL)
				{
					n3=r3=new node;
					n3->next=n3;
				}
				else
				{
					r3->next=new node;
					r3=r3->next;
					r3->next=n3;
				}
				r3->exp=n2->exp;
				r3->coeff=n2->coeff;

				n2=n2->next;
			}while(n2!=head->next);

			node *ptr=n3;
			do
			{
				cout<<"("<<ptr->coeff<<"x^"<<ptr->exp<<")+";
				ptr=ptr->next;
			}while(ptr!=head->next);

}
int main()
{
	polynomial_linkedlist p,q,add;
	int options;
	do
	{
	cout<<"\n1.Enter polynomial\n";
	cout<<"\n2.Display polynomial\n";
	cout<<"\n3.Evaluate polynomial\n";
	cout<<"\n4.Addition of polynomial\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
	switch(options)
	{
	case 1:
		q.input();
		p.input();
		break;
	case 2:
		q.display();
		break;
	case 3:
		q.evaluate();
		break;
	case 4:
		p.addition();
	}
	}while(options!=0);
	return 0;
}

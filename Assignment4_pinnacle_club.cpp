//============================================================================
// Name        : Assignment4_pinnacle_club.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct node
{
	int prn;
	char name[10];
	struct node *next;
}node;
class pinnacle_club
{
public:
	node *head=NULL;
	node *president,*secretary;
	node *ptr,*temp;


	void add_president();
	void add_secretary();
	void add_member();
	void delete_president();
	void delete_secretary();
	void delete_member();
	void total_members();
	void display();
	void display_reverse(node *);
	void sort();
	void concatenate(node *second);
	void merge1(node *second);
};
void pinnacle_club::add_president()
{
	node *newnode=new node;
	cout<<"\nEnter prn and name of president \n";
	cin>>newnode->prn>>newnode->name;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=president=newnode;
	}
}
void pinnacle_club::add_secretary()
{

	node *newnode=new node;
	cout<<"\nEnter prn and name of secretary \n";
	cin>>newnode->prn>>newnode->name;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		secretary=newnode;
	}

}
void pinnacle_club::add_member()
{
	int position;
	node *newnode=new node;
	cout<<"\nEnter prn and name of member \n";
	cin>>newnode->prn>>newnode->name;
	newnode->next=NULL;
	if(head==NULL)
	{
		add_president();
	}
	else
	{
		cout<<"\nEnter position to add member\n";
		cin>>position;

		ptr=head;
		for(int i=1;i<position-1;i++)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
	}

}
void pinnacle_club::delete_president()
{
	if(head==NULL)
	{
		cout<<"\nUnderflow\n";
	}
	else if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		temp=head;
		head=head->next;
		president=head;
		delete(temp);
	}
}
void pinnacle_club::delete_secretary()
{
	if(head==NULL)
	{
		cout<<"\nUnderflow\n";
	}
	else if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		ptr=head;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		temp=ptr->next;
		secretary=ptr;
		ptr->next=NULL;
		delete(temp);
	}

}
void pinnacle_club::delete_member()
{
	int position;

	if(head==NULL)
	{
		cout<<"\nUnderflow\n";
	}
	else if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		cout<<"\nEnter position of member to be deleted\n";
		cin>>position;
		ptr=head;
		for(int i=1;i<position-1;i++)
		{
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		delete(temp);
	}

}
void pinnacle_club::display()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<"prn:"<<ptr->prn<<"->"<<"name:"<<ptr->name<<endl;
		ptr=ptr->next;
	}
}
void pinnacle_club::total_members()
{
	int cnt=0;
	node *ptr=head;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\nTotalno of elements :"<<cnt;
}

void pinnacle_club::display_reverse(node *head)
{
		if(head==NULL)
			return;
		display_reverse(head->next);
		cout<<"prn:"<<head->prn<<"->"<<"name:"<<head->name<<endl;

}
void pinnacle_club::sort()
{
	node *ptr1,*ptr2;
	char temp[10];
	int temp=0,n=0;
	ptr=ptr1=head;
	ptr2=ptr1->next;
	while(ptr!=NULL)
	{
		n++;
		ptr=ptr->next;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if((ptr1->prn)>(ptr2->prn))
			{
				temp=ptr1->prn;
				strcpy(temp,ptr1->name);
				ptr1->prn=ptr2->prn;
				strcpy(ptr1->name,ptr2->name);
				ptr2->prn=temp;
				strcpy(ptr2->name,temp);
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		ptr1=head;
		ptr2=ptr1->next;
		}

}
void pinnacle_club::concatenate(node *second)
{
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=second;
}
 void pinnacle_club::merge1(node *second)
{

	 cout<<"hii";

node *first=head;
	 temp=NULL;
	if(first->prn<second->prn)
	{
		temp=ptr=first;
		first=first->next;
	}
	else
	{
		temp=ptr=second;
		second=second->next;
	}
	while(first!=NULL && second!=NULL)
	{
		if(first->prn<second->prn)
		{
			ptr->next=first;
			first=first->next;
			ptr=ptr->next;
		}
		else
		{
			ptr->next=second;
			second=second->next;
			ptr=ptr->next;
		}
	}
	 while(first!=NULL)
	 {
		 ptr->next=first;
	 }
	 while(second!=NULL)
	 {
		 ptr->next=second;
	 }
	head=temp;
}
int main()
{
	pinnacle_club p,q;

	int options;
	do
	{
	cout<<"\n1.Add President\n";
	cout<<"\n2.Add Secretary\n";
	cout<<"\n3.Add Member\n";
	cout<<"\n4.Delete President\n";
	cout<<"\n5.Delete Secretary\n";
	cout<<"\n6.Delete Member\n";
	cout<<"\n7.Compute total number of members of club\n";
	cout<<"\n8.Display members\n";
	cout<<"\n9.sDisplay list in reverse order using recursion\n";
	cout<<"\n10.sort linked list\n";
	cout<<"\n11.Create second list\n";
	cout<<"\n12.Concatenate two lists\n";
	cout<<"\n13.Merge two sorted list\n";
	cout<<"\n14.Display second list\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
		switch(options)
		{
		case 1:
			p.add_president();
			break;
		case 2:
			p.add_secretary();
			break;
		case 3:
			p.add_member();
			break;
		case 4:
			p.delete_president();
			break;
		case 5:
			p.delete_secretary();
			break;
		case 6:
			p.delete_member();
			break;
		case 7:
			p.total_members();
			break;
		case 8:
			p.display();
			break;
		case 9:
			p.display_reverse(p.head);
			break;
		case 10:
			p.sort();
			break;
		case 11:
			int n;
			cout<<"\nCreate second list\n";
			q.add_president();
			q.add_secretary();
			cout<<"\nHow many members want in second list\n";
			cin>>n;
			for(int i=1;i<=n;i++)
			{
			q.add_member();
			}
			break;
		case 12:
			p.concatenate(q.head);
			break;
		case 13:
			p.merge1(q.head);
			cout<<"vb";
			break;
		case 14:
			q.display();
			break;
		}
	}while(options!=0);
	return 0;
}

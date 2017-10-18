//============================================================================
// Name        : Assignment1_set_by_cpp.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class badminton;
class cricket;
class student
{
	int students[40],m;
public:
	void get_all_class_student()
	{
		cout<<"\nEnter no of students \n";
		cin>>m;
		cout<<"\nEnter roll no of students \n";
		for(int i=0;i<m;i++)
		{
			cin>>students[i];
		}

	}
	friend void Union(cricket,badminton);
	friend void Intersection(cricket,badminton);
	friend void C_minus_B(cricket,badminton);
	friend void B_minus_C(cricket,badminton);
	friend void U_minus_C_union_B(cricket,badminton,student);

};
class cricket:public student
{
	int cricket_students[10],c;

public:

	void get_cricket_students()
	{
		cout<<"\nEnter no of students who play cricket\n";
		cin>>c;
		cout<<"\nEnter roll no of students who play badminton\n";
		for(int i=0;i<c;i++)
		{
			cin>>cricket_students[i];
		}
	}
	friend void Union(cricket,badminton);
	friend void Intersection(cricket,badminton);
	friend void C_minus_B(cricket,badminton);
	friend void B_minus_C(cricket,badminton);
	friend void U_minus_C_union_B(cricket,badminton,student);

};
class badminton:public student
{

	int badminton_students[10],b;

public:

	void get_badminton_students()
	{
		cout<<"\nEnter no of students who play badminton\n";
		cin>>b;
		cout<<"\nEnter roll no of students who play badminton\n";
		for(int i=0;i<b;i++)
		{
			cin>>badminton_students[i];
		}

	}
	friend void Union(cricket,badminton);
	friend void Intersection(cricket,badminton);
	friend void C_minus_B(cricket,badminton);
	friend void B_minus_C(cricket,badminton);
	friend void U_minus_C_union_B(cricket,badminton,student);

};
void  Union(cricket cr,badminton ba)
{
	int union_candb[20],k=0,flag;

		for(int i=0;i<cr.c;i++)
		{
			union_candb[k++]=cr.cricket_students[i];
		}

		for(int j=0;j<ba.b;j++)
		{
			flag=0;
			for(int i=0;i<cr.c;i++)
			{
				if(ba.badminton_students[j]==cr.cricket_students[i])
				{
				flag=1;
				}
			}
			if(flag==0)
			{
				union_candb[k++]=ba.badminton_students[j];

			}
		}
		for(int i=0;i<k;i++)
		{
			cout<<"\t"<<union_candb[i];
		}
}

void  Intersection(cricket cr,badminton ba)
{
	int Intersection_candb[20],k=0,flag;

		for(int j=0;j<ba.b;j++)
		{
			flag=0;
			for(int i=0;i<cr.c;i++)
			{
				if(ba.badminton_students[j]==cr.cricket_students[i])
				{
				flag=1;
				}
			}
			if(flag==1)
			{
				Intersection_candb[k++]=ba.badminton_students[j];

			}
		}
		for(int i=0;i<k;i++)
		{
			cout<<"\t"<<Intersection_candb[i];
		}
}

void C_minus_B(cricket cr,badminton ba)
{
	int c_minus_b[20],k=0,flag;
			for(int i=0;i<cr.c;i++)
			{
				flag=0;
				for(int j=0;j<ba.b;j++)
				{
					if(ba.badminton_students[j]==cr.cricket_students[i])
					{
						flag=1;
					}
				}

				if(flag==0)
				{
					c_minus_b[k++]=cr.cricket_students[i];
				}
		}
		for(int i=0;i<k;i++)
		{
			cout<<"\t"<<c_minus_b[i];
		}

}


void B_minus_C(cricket cr,badminton ba)
{
	int b_minus_c[20],k=0,flag;
			for(int j=0;j<ba.b;j++)
			{
					flag=0;
					for(int i=0;i<cr.c;i++)
					{

					if(ba.badminton_students[j]==cr.cricket_students[i])
					{
						flag=1;
					}
				}

				if(flag==0)
				{
					b_minus_c[k++]=ba.badminton_students[j];
				}
			}
		for(int i=0;i<k;i++)
		{
			cout<<"\t"<<b_minus_c[i];
		}

}

 void U_minus_C_union_B(cricket cr,badminton ba,student st)
 {
	 int union_candb[20],k=0,flag;

	 		for(int i=0;i<cr.c;i++)
	 		{
	 			union_candb[k++]=cr.cricket_students[i];
	 		}

	 		for(int j=0;j<ba.b;j++)
	 		{
	 			flag=0;
	 			for(int i=0;i<cr.c;i++)
	 			{
	 				if(ba.badminton_students[j]==cr.cricket_students[i])
	 				{
	 				flag=1;
	 				}
	 			}
	 			if(flag==0)
	 			{
	 				union_candb[k++]=ba.badminton_students[j];

	 			}
	 		}

	int u_minus_c_union_b[20],x=0,flag1=0;

	for(int j=0;j<st.m;j++)
	{
			flag1=0;
			for(int i=0;i<k;i++)
			{
				if(st.students[j]==union_candb[i])
				{
				flag1=1;
				}
			}

		if(flag1==0)
		{
			u_minus_c_union_b[x++]=st.students[j];
		}
	}

	for(int i=0;i<x;i++)
	{
		cout<<"\t"<<u_minus_c_union_b[i];
	}
	cout<<"\nNumber of students who play neither cricket nor badminton  : "<<x;

 }

int main()
{
	int options;
	cricket cc;
	badminton bb;
	student s;
	s.get_all_class_student();
	do
	{
	cout<<"\n1.Enter students roll no of sports students\n";
	cout<<"\n2.Set of students who play either cricket or badminton or both\n";
	cout<<"\n3.Set of students who play both cricket and badminton\n";
	cout<<"\n4.Set of students who play only cricket\n";
	cout<<"\n5.Set of students who play only badminton\n";
	cout<<"\n6.Number of students who play neither cricket nor badminton\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
	switch(options)
	{
		case 1:
			cc.get_cricket_students();
			bb.get_badminton_students();
			break;
		case 2:
			Union(cc,bb);
			break;
		case 3:
			Intersection(cc,bb);
			break;
		case 4:
			C_minus_B(cc,bb);
			break;
		case 5:
			B_minus_C(cc,bb);
			break;
		case 6:
			U_minus_C_union_B(cc,bb,s);
			break;


	}
	}while(options!=0);


	return 0;
}

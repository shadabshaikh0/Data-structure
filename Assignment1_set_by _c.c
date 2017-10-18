/*
 ============================================================================
 Name        : Assignment1_set_by.c
 Author      : shadab shaikh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Union(int[],int,int[],int);
void Intersection(int[],int,int[],int);
void C_minus_B(int[],int,int[],int);
void B_minus_C(int[],int,int[],int);
void U_minus_C_union_B(int [],int ,int[],int ,int[],int s);

int main(void)
{
	int students[20],cricket[10],badminton[10];
	int m,c,b;
	printf("\nEnter no of students \n");
	scanf("%d",&m);
	printf("\nEnter roll no of students \n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&students[i]);
	}
	int options;
	do
	{
	printf("\n1.Enter students roll no of sports students\n");
	printf("\n2.Set of students who play either cricket or badminton or both\n");
	printf("\n3.Set of students who play both cricket and badminton\n");
	printf("\n4.Set of students who play only cricket\n");
	printf("\n5.Set of students who play only badminton\n");
	printf("\n6.Number of students who play neither cricket nor badminton\n");
	printf("\nEnter your choice\n");
	scanf("%d",&options);
	switch(options)
	{
		case 1:
			printf("\nEnter no of students  who play cricket\n");
			scanf("%d",&c);
			printf("\nEnter roll no of students \n");
			for(int i=0;i<c;i++)
			{
				scanf("%d",&cricket[i]);
			}
			printf("\nEnter no of students who play badminton\n");
			scanf("%d",&b);
			printf("\nEnter roll no of students \n");
			for(int i=0;i<b;i++)
			{
				scanf("%d",&badminton[i]);
			}


			break;
		case 2:
			Union(cricket,c,badminton,b);
			break;
		case 3:
			Intersection(cricket,c,badminton,b);
			break;
		case 4:
			C_minus_B(cricket,c,badminton,b);
			break;
		case 5:
			B_minus_C(cricket,c,badminton,b);
			break;
		case 6:
			U_minus_C_union_B(cricket,c,badminton,b,students,m);
			break;

	}
	}while(options!=0);

//==========

	return EXIT_SUCCESS;
}
void Union(int cricket[],int c,int badminton[],int b)
{
	int union_candb[20],k=0,flag;

		for(int i=0;i<c;i++)
		{
			union_candb[k++]=cricket[i];
		}

		for(int j=0;j<b;j++)
		{
			flag=0;
			for(int i=0;i<c;i++)
			{
				if(badminton[j]==cricket[i])
				{
				flag=1;
				}
			}
			if(flag==0)
			{
				union_candb[k++]=badminton[j];

			}
		}
		for(int i=0;i<k;i++)
		{
			printf("\t%d",union_candb[i]);
		}

}
void Intersection(int cricket[],int c,int badminton[],int b)
{
	int intersection_candb[20],k=0,flag;

		for(int j=0;j<b;j++)
		{
			flag=0;
			for(int i=0;i<c;i++)
			{
				if(badminton[j]==cricket[i])
				{
				flag=1;
				}
			}
			if(flag==1)
			{
				intersection_candb[k++]=badminton[j];

			}
		}
		for(int i=0;i<k;i++)
		{
			printf("\t%d",intersection_candb[i]);
		}

}
void C_minus_B(int cricket[],int c,int badminton[],int b)
{
	int c_minus_b[20],k=0,flag;
			for(int i=0;i<c;i++)
			{
				flag=0;
				for(int j=0;j<b;j++)
				{
					if(badminton[j]==cricket[i])
					{
						flag=1;
					}
				}

				if(flag==0)
				{
					c_minus_b[k++]=cricket[i];
				}
		}
		for(int i=0;i<k;i++)
		{
			printf("\t%d",c_minus_b[i]);
		}

}

void B_minus_C(int cricket[],int c,int badminton[],int b)
{
	int b_minus_c[20],k=0,flag;
				for(int j=0;j<b;j++)
				{
						flag=0;
						for(int i=0;i<c;i++)
						{

						if(badminton[j]==cricket[i])
						{
							flag=1;
						}
					}

					if(flag==0)
					{
						b_minus_c[k++]=badminton[j];
					}
				}
			for(int i=0;i<k;i++)
			{
				printf("\t%d",b_minus_c[i]);
			}

}
void U_minus_C_union_B(int cricket[],int c,int badminton[],int b,int students[],int m)
 {
	int union_candb[20],k=0,flag;

		for(int i=0;i<c;i++)
		{
			union_candb[k++]=cricket[i];
		}

		for(int j=0;j<b;j++)
		{
			flag=0;
			for(int i=0;i<c;i++)
			{
				if(badminton[j]==cricket[i])
				{
				flag=1;
				}
			}
			if(flag==0)
			{
				union_candb[k++]=badminton[j];

			}
		}

	int u_minus_c_union_b[20],x=0,flag1=0;

	for(int j=0;j<m;j++)
	{
			flag1=0;
			for(int i=0;i<k;i++)
			{
				if(students[j]==union_candb[i])
				{
				flag1=1;
				}
			}

		if(flag1==0)
		{
			u_minus_c_union_b[x++]=students[j];
		}
	}

	for(int i=0;i<x;i++)
	{
		printf("\t%d",u_minus_c_union_b[i]);
	}
	printf("\nNumber of students who play neither cricket nor badminton  : %d",x);

 }

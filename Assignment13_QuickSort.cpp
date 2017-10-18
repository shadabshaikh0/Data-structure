//============================================================================
// Name        : Assignment13_QuickSort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class QuickSort
{
public:
	float a[10];
	int n;
	void input();
	void quick_sort(float[],int ,int);
	int partition(float[],int ,int);
	void output();
};
void QuickSort::input()
{
	cout<<"\nEnter no of students\n";
	cin>>n;
	cout<<"\nEnter percentage of student\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void QuickSort::quick_sort(float a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}

}
int QuickSort::partition(float a[],int l,int u)
{
	int i,j;
	float v,temp;
	v=a[l];
	i=l;
	j=u+1;
		do
		{
			do
			{
				i++;
			}while(v>a[i] && i<=u);
			do
			{
				j--;
			}while(v<a[j]);
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

		}while(i<j);
		a[l]=a[j];
		a[j]=v;
	return j;
}

void QuickSort::output()
{
	cout<<"\nTop 5 students in sorted order\n";
	for(int i=0;i<5;i++)
	{
		cout<<"\t"<<a[i];
	}

	cout<<"\n==============================\n";
	cout<<"\nAll students in sorted order\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}

}
int main()
{
	QuickSort b;
	b.input();
	b.quick_sort(b.a,0,b.n-1);
	b.output();
	return 0;
}

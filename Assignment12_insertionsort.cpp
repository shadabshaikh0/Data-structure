//============================================================================
// Name        : Assignment12_insertionsort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
class InsertioSort
{
	float a[10];
	int n;
public:
	void input();
	void insertion_sort();
};
void InsertioSort::input()
{
	cout<<"\nEnter no of students\n";
	cin>>n;
	cout<<"\nEnter percentage of student\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void InsertioSort::insertion_sort()
{
	int i,j;
	float temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && temp<a[j];j--)
		{
			a[j+1]=a[j];
			a[j]=temp;
		}
	}
	cout<<"\nTop 5 students in sorted order\n";
	for(int i=0;i<n;i++)
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
	InsertioSort b;
	b.input();
	b.insertion_sort();
	return 0;
}

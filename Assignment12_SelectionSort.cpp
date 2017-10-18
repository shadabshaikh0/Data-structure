//============================================================================
// Name        : Assignment12_SelectionSort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
class SelectionSort
{
	float a[10];
	int n,min;
public:
	void input();
	void selection_sort();
};
void SelectionSort::input()
{
	cout<<"\nEnter no of students\n";
	cin>>n;
	cout<<"\nEnter percentage of student\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void SelectionSort::selection_sort()
{
	int i,j;
	float temp=0;
	for( i=0;i<n-1;i++)
	{
		min=i;
		for( j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
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
	SelectionSort b;
	b.input();
	b.selection_sort();
	return 0;
}

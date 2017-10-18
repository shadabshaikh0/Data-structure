//============================================================================
// Name        : Assignment12_BubbleSort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class BubbleSort
{
	float a[10];
	int n;
public:
	void input();
	void bubble_sort();
};
void BubbleSort::input()
{
	cout<<"\nEnter no of students\n";
	cin>>n;
	cout<<"\nEnter percentage of student\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void BubbleSort::bubble_sort()
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				float temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
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
	BubbleSort b;
	b.input();
	b.bubble_sort();
	return 0;
}

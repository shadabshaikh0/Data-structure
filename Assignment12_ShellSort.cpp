//============================================================================
// Name        : Assignment12_ShellSort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : Assignment12_insertionsort.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
class ShellSort
{
	float a[10];
	int n;
public:
	void input();
	void shell_sort();
};
void ShellSort::input()
{
	cout<<"\nEnter no of students\n";
	cin>>n;
	cout<<"\nEnter percentage of student\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void ShellSort::shell_sort()
{
	int i,j,step;
	float temp;
	for(step=n/2;step>0;step=step/2)
	{
		for(i=step;i<n;i++)
		{
			temp=a[i];
			for(j=i;j>=step;j=j-step)
			{
				if(a[j]<a[j-step])
				{
					temp=a[j];
					a[j]=a[j-step];
					a[j-step]=temp;
				}
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
	ShellSort b;
	b.input();
	b.shell_sort();
	return 0;
}

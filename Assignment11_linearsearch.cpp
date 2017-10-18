//============================================================================
// Name        : Assignment11_linearsearch.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class LinearSearch
{
	int a[10],search_element,flag,n;
public:
	void input();
	void linearsearch();
};
void LinearSearch::input()
{
	cout<<"\nEnter no of elements\n";
	cin>>n;
	cout<<"\nEnter elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void LinearSearch::linearsearch()
{
	flag=0;
	cout<<"\nEnter element to be search\n";
	cin>>search_element;
	for(int i=0;i<n;i++)
	{
		if(a[i]==search_element)
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"\nElement found\n";
	}
	else
	{
		cout<<"\nElement not found\n";
	}

}
int main()
{
	LinearSearch l;
	l.input();
	l.linearsearch();
	return 0;
}

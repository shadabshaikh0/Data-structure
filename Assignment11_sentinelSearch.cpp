//============================================================================
// Name        : Assignment11_sentinelSearch.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
class SentinelSearch
{
	int a[10],search_element,n;
public:
	void input();
	void sentinelSearch();
};
void SentinelSearch::input()
{
	cout<<"\nEnter no of elements\n";
	cin>>n;
	cout<<"\nEnter elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void SentinelSearch::sentinelSearch()
{

	cout<<"\nEnter element to be search\n";
	cin>>search_element;
	a[n+1]=search_element;
	int i=0;
	while(a[i]!=search_element)
	{
		i++;
	}
	if(i==n+1)
	{
		cout<<"\nElement not found\n";
	}
	else
	{
		cout<<"\nElement found\n";
	}
}
int main()
{
	SentinelSearch l;
	l.input();
	l.sentinelSearch();
	return 0;
}

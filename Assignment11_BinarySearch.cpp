//============================================================================
// Name        : Assignment11_BinarySearch.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
class BinarySearch
{
	int a[10],search_element,n,low,mid,high;
public:
	void input();
	void Binary_Search();
};
void BinarySearch::input()
{
	cout<<"\nEnter no of elements\n";
	cin>>n;
	cout<<"\nEnter elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void BinarySearch::Binary_Search()
{
	cout<<"\nEnter element to be search\n";
	cin>>search_element;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high && a[mid]!=search_element)
	{
		if(search_element<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
		mid=(low+high)/2;
	}
	if(a[mid]==search_element)
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
	BinarySearch l;
	l.input();
	l.Binary_Search();
	return 0;
}

//============================================================================
// Name        : Assignment11_fibbonacci_search.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class fibboanaccisearch
{
public:
	int a[20],n,fibm,fibm1,fibm2,offset,i,x;
	void input();
	int min(int,int);
	void fibbonaccisearch(int[],int,int);
};
void fibboanaccisearch::input()
{
	cout<<"\nEnter no of elements\n";
	cin>>n;
	cout<<"\nEnter elements of array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nEnter search elements\n";
	cin>>x;

}
void fibboanaccisearch::fibbonaccisearch(int a[],int x,int n)
{
	fibm2=0;
	fibm1=1;
	fibm=fibm1+fibm2;
	while(fibm<n)
	{
		fibm2=fibm1;
		fibm1=fibm;
		fibm=fibm1+fibm2;
	}
		offset=-1;
		while(fibm>1)
		{
			i=min(offset+fibm2,n-1);
			if(x>a[i])
			{
				fibm=fibm1;
				fibm1=fibm2;
				fibm2=fibm-fibm1;
				offset=i;
			}
			else if(x<a[i])
			{
				fibm=fibm2;
				fibm1=fibm1-fibm2;
				fibm2=fibm-fibm1;
			}
			else
			{
				cout<<"\nElement found at "<<i+1<<" position\n";
				return;
			}
		}
		if(fibm1 && a[offset+1]==x)
		{
			cout<<"\nElement found at "<<offset+1<<" position\n";
			return;
		}
		else
		{
			cout<<"\nElement not found \n";
			return;
		}
}
int fibboanaccisearch::min(int x,int y)
{
	return (x<=y)?x:y;
}
int main()
{

	fibboanaccisearch f;
	f.input();
	f.fibbonaccisearch(f.a,f.x,f.n);
	return 0;
}

//============================================================================
// Name        : Assignment3_polynomial.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<math.h>
using namespace std;
class polynomial
{
	int poly[10],degree;
public:
	friend istream& operator>>(istream &in,polynomial &p)
	{
		cout<<"\nEnter degree of polynomial\n";
		cin>>p.degree;
		cout<<"\nEnter coefficient of polynomial\n";
		for(int i=p.degree;i>=0;i--)
		{
			in>>p.poly[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream &out,polynomial &p)
	{
		for(int i=p.degree;i>=0;i--)
		{
			if(i==0)
			{
				out<<"("<<p.poly[i]<<")";
			}
			else
			{
			out<<"("<<p.poly[i]<<"x^"<<i<<")+";
			}
		}
		return out;
	}

	friend polynomial operator+(polynomial p1,polynomial p2)
	{
		int i,j,k=0;
		polynomial temp;
		for(i=0,j=0;i<=p1.degree && j<=p2.degree;)
		{
			if(i<j)
			{
				temp.poly[k++]=p2.poly[j];
				j++;
			}
			else if(j<i)
			{
				temp.poly[k++]=p1.poly[i];
				i++;
			}
			else
			{
				temp.poly[k++]=p1.poly[i]+p2.poly[j];
				i++;
				j++;
			}
		}
		temp.degree=k-1;
		return temp;
	}

	friend polynomial operator*(polynomial p1,polynomial p2)
	{

		int i,j,k=0;
		polynomial temp;
		for(int i=0;i<10;i++)
		{
			temp.poly[i]=0;
		}
		for(int i=p1.degree;i>=0;i--)
		{
			for(int j=p2.degree;j>=0;j--)
			{
				k=i+j;
				temp.poly[k]+=p1.poly[i]*p2.poly[j];
			}
		}
		temp.degree=p1.degree+p2.degree;
		return temp;
	}


	void evaluate();
};

void polynomial::evaluate()
{
	int x,result=0;
	cout<<"\nEnter value of x\n";
	cin>>x;

	for(int i=degree;i>=0;i--)
	{
		result+=poly[i]*pow(x,i);
	}
	cout<<"Evaluation of polynimial: "<<result<<endl;
}
int main()
{
	polynomial p1,p2,p3,p4;
	int options;
	do
	{
	cout<<"\n1.input\n";
	cout<<"\n2.output\n";
	cout<<"\n3.evaluate\n";
	cout<<"\n4.addition\n";
	cout<<"\n5.Multiplication\n";

	cout<<"\nEnter your choice\n";
	cin>>options;
		switch(options)
		{
		case 1:
				cin>>p1;
				break;
		case 2:
				cout<<p1;
				break;
		case 3:
				p1.evaluate();
				break;
		case 4:
				cout<<"\nINPUT 1ST POLYNOMIAL \n";
				cin>>p1;
				cout<<"\nINPUT 2ND POLYNOMIAL \n";
				cin>>p2;
				p3=p1+p2;
				cout<<p3;
				break;
		case 5:
				cout<<"\nINPUT 1ST POLYNOMIAL \n";
				cin>>p1;
				cout<<"\nINPUT 2ND POLYNOMIAL \n";
				cin>>p2;
				p4=p1*p2;
				cout<<p4;
				break;

		}
	}while(options!=0);
	return 0;
}

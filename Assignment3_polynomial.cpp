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
//============================================================================
2
// Name        : Assignment3_polynomial.cpp
3
// Author      : shadab shaikh
4
// Version     :
5
// Copyright   : Your copyright notice
6
// Description : Hello World in C++, Ansi-style
7
//============================================================================
8
​
9
#include <iostream>
10
#include<math.h>
11
using namespace std;
12
class polynomial
13
{
14
        int poly[10],degree;
15
public:
16
        friend istream& operator>>(istream &in,polynomial &p)
17
        {
18
                cout<<"\nEnter degree of polynomial\n";
19
                cin>>p.degree;
20
                cout<<"\nEnter coefficient of polynomial\n";
21
                for(int i=p.degree;i>=0;i--)
22
                {
23
                        in>>p.poly[i];
24
                }
25
                return in;
26
        }
27
        friend ostream& operator<<(ostream &out,polynomial &p)
28
        {
29
                for(int i=p.degree;i>=0;i--)
30
                {
31
                        if(i==0)
32
                        {
33
                                out<<"("<<p.poly[i]<<")";
34
                        }
35
                        else
36
                        {
37
                        out<<"("<<p.poly[i]<<"x^"<<i<<")+";
38
                        }
39
                }
40
                return out;
41
        }
42
​
43
        friend polynomial operator+(polynomial p1,polynomial p2)
44
        {
45
                int i,j,k=0;
46
                polynomial temp;
47
                for(i=0,j=0;i<=p1.degree && j<=p2.degree;)
48
                {
49
                        if(i<j)		int i,j,k;
		polynomial temp;
		for(int i=0;i<10;i++)
		{
			temp.poly[i]=0;
		}
		if(p1.degree>p2.degree)
		{
			temp.degree=p1.degree;
		}
		else
		{
			temp.degree=p2.degree;
		}
		k=temp.degree;
		for(i=p1.degree,j=p2.degree;k>=0;)
		{
			if(i<j)
			{
				temp.poly[k--]=p2.poly[j];
				j--;
			}
			else if(j<i)
			{
				temp.poly[k--]=p1.poly[i];
				i--;
			}
			else
			{
				temp.poly[k--]=p1.poly[i]+p2.poly[j];
				i--;
				j--;
			}
		}
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

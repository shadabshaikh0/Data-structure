//============================================================================
// Name        : Assignment2_matrix.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int a[3][3],b[3][3],c[3][3];
	int row1,row2,column1,column2;
public:
	void getmatrix();
	void gettwomatrix();
	void uppertriangular();
	void sum_of_diagonal();
	void transpose();
	void addition();
	void substraction();
	void multiplication();
	void saddlepoint();
};
void matrix::getmatrix()
{
	cout<<"\nEnter no of rows and columns\n";
	cin>>row1>>column1;
	cout<<"\nEnter elements of matrix\n";
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cin>>a[i][j];
		}
	}

}
void matrix::gettwomatrix()
{
	cout<<"\nEnter no of rows and columns of 1st matrix\n";
	cin>>row1>>column1;
	cout<<"\nEnter elements of 1st matrix\n";
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nEnter no of rows and columns of 2nd matrix\n";
	cin>>row2>>column2;
	cout<<"\nEnter elements of 1st matrix\n";
	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<column2;j++)
		{
			cin>>b[i][j];
		}
	}

}
void matrix::uppertriangular()
{
	int flag1=0,flag2=0;
	getmatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			if(i<=j)
			{
				if(a[i][j]!=0)
				{
					flag1=0;
				}
				else
				{
					flag1=1;
					goto x;
				}
			}
			else
			{
				if(a[i][j]==0)
				{
					flag2=0;
				}
				else
				{
					flag2=1;
					goto x;
				}
			}
		}
	}
	if(flag1==0 && flag2==0)
	{
		cout<<"\nMatrix is upper triangular\n";
	}
	else
	{
		x:cout<<"\nMatrix is  not upper triangular\n";
	}

}
void matrix::sum_of_diagonal()
{
	int sum;
	getmatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			if(i==j)
			{
				sum+=a[i][j];
			}
		}
	}

	cout<<"\nSum of diagonal elements:"<<sum;
}
void matrix::transpose()
{
    getmatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cout<<"\t"<<a[j][i];
		}
		cout<<"\n";
	}

}
void matrix::addition()
{
	gettwomatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
				cout<<"\t"<<c[i][j];
			}
			cout<<"\n";
		}


}
void matrix::substraction()
{
	gettwomatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
				cout<<"\t"<<c[i][j];
			}
			cout<<"\n";
		}


}
void matrix::multiplication()
{
	gettwomatrix();
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			c[i][j]=0;
			for(int k=0;k<column1;k++)
			{
			c[i][j]+=a[i][k]+b[k][j];
			}
		}
	}
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<column1;j++)
			{
				cout<<"\t"<<c[i][j];
			}
			cout<<"\n";
		}


}

void matrix::saddlepoint()
{
	int rowvalue,colvalue,rowloc,colloc,i,j;
	getmatrix();
	for( i=0;i<row1;i++)
	{
		rowvalue=a[i][0];
		rowloc=0;
		for(int j=1;j<column1;j++)
		{
			if(rowvalue>a[i][j])
			{
				rowvalue=a[i][j];
				rowloc=j;
			}
		}
		colvalue=a[0][rowloc];
		colloc=0;

		for( j=1;j<row1;j++)
		{
			if(colvalue<a[j][rowloc])
			{
				colvalue=a[j][rowloc];
				colloc=j;
			}
		}
		if(i==colloc)
		{
			cout<<"\nSaddle point exists at "<<i <<","<<rowloc<<"point\n";

		}
	}
	cout<<"\nSaddle  point does not exists "<<endl;

}
int main()
{
	matrix m;
	int options;
	do
	{
	cout<<"\n1.Check whether given matrix is upper triangular or not\n";
	cout<<"\n2.Compute summation of diagonal elements \n";
	cout<<"\n3.Compute transpose of matrix \n";
	cout<<"\n4.Addition of matrix\n";
	cout<<"\n5.Substraction of matrix\n";
	cout<<"\n6.Multiplication of matrix\n";
	cout<<"\n7.Check saddle point is present or not.\n";
	cout<<"\nEnter your choice\n";
	cin>>options;
	switch(options)
	{
	case 1:
			m.uppertriangular();
			break;
	case 2:
		    m.sum_of_diagonal();
		    break;
	case 3:
		    m.transpose();
		    break;
	case 4:
			m.addition();
			break;
	case 5:
			m.substraction();
			break;
	case 6:
			m.multiplication();
			break;
	case 7:
			m.saddlepoint();
			break;
	}
	}while(options!=0);
	return 0;
}

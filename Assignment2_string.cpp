//============================================================================
// Name        : Assignment2_string.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
using namespace std;
class string_operations
{
	char string1[20],string2[20],string3[20];
public:

	void getstring();
	void gettwostring();
	void copy_string();
	void concatenate_string();
	void check_substring();
	void check_equal();
	void reverse_string();
	void find_length();
	void find_frequency();
	void delete_substring();
	void delete_all_occurence_of_character();
	void replace_string();
	void check_palindrome();
};
void string_operations::getstring()
{
	cout<<"\nEnter string\n";
	cin>>string1;
}

void string_operations::gettwostring()
{
	cout<<"\nEnter 1st string\n";
	cin>>string1;
	cout<<"\nEnter 2nd string\n";
	cin>>string2;

}
void string_operations::copy_string()
{
	getstring();
	int i,j;
	for(i=0,j=0;string1[i]!='\0';i++,j++)
	{
		string2[j]=string1[i];
	}
	string2[j]='\0';
	cout<<"\nstring1: "<<string1;
	cout<<"\nstring2: "<<string2;
}
void string_operations::concatenate_string()
{
	gettwostring();
	int i,j=0,k;
	for(i=0;string1[i]!='\0';i++)
	{
			string3[j++]=string1[i];
	}
	for(k=0;string2[k]!='\0';k++)
	{
		string3[j++]=string2[k];
	}
	string3[j]='\0';
	cout<<"\nstring1: "<<string1;
	cout<<"\nstring2: "<<string2;
	cout<<"\nstring3: "<<string3;

}
void string_operations::check_substring()
{
	getstring();
	char search_substring[20];
	cout<<"\nEnter substring to search\n";
	cin>>search_substring;
	int i=0,j=0,k;
	while(string1[i]!='\0')
	{
		while(string1[i]!=search_substring[0] && string1[i]!='\0')
		{
			i++;
		}
		k=i;
		while(string1[i]==search_substring[j] && string1[i]!='\0' && search_substring[j]!='\0')
		{
			i++;
			j++;
		}
		if(string1[i]=='\0')
		{
			cout<<"\nString not found\n";
			return;
		}
		if(search_substring[j]=='\0')
		{
			cout<<"\nString found at "<< k+1 <<"position\n";
			return;
		}
		i=k+1;
		j=0;
	}

}
void string_operations::check_equal()
{
	gettwostring();
	int i,j;
	for(i=0,j=0;string1[i]==string2[j] && string1[i]!='\0' && string2[j]!='\0';i++,j++);

	if(string1[i]=='\0' && string2[j]=='\0')
	{
		cout<<"\nStrings are equal\n";
	}
	else
	{
		cout<<"\nStrings are  not equal\n";

	}
}
void string_operations::reverse_string()
{
	getstring();
	int i,j,k;
	for(i=0;string1[i]!='\0';i++);
	for(j=i-1,k=0;j>=0;j--,k++)
	{
		string2[k]=string1[j];
	}
	string2[k]='\0';
	cout<<"\nReverse string: "<<string2;
}

void string_operations::find_length()
{
	getstring();
	int i;
	for(i=0;string1[i]!='\0';i++);
	cout<<"\nLength of string: "<<i<<endl;
}
void string_operations::find_frequency()
{
	char search;
	int frequency=0,i;
	getstring();
	cout<<"\nEnter character to find its frequency\n";
	cin>>search;
	for(i=0;string1[i]!='\0';i++)
	{
		if(search==string1[i])
		{
			frequency++;
		}
	}
	cout<<"\nFrequency of "<<search <<"is :"<<frequency ;
}
void string_operations::delete_substring()
{
	int start,length,i;
	getstring();
	cout<<"\nEnter start position and length to be deleted of string\n";
	cin>>start>>length;
	for( i=start-1;string1[i]!='\0';i++)
	{
		string1[i]=string1[i+length];
	}
	string1[i]='\0';
	cout<<"\nNew String: "<<string1;
}
void string_operations::delete_all_occurence_of_character()
{
	getstring();
	char delcharacter;
	cout<<"\nEnter character that you want to delete all occurene of character\n";
	cin>>delcharacter;
	int i=0,k;
	while(string1[i]!='\0')
	{
		while(string1[i]!='\0' && string1[i]!=delcharacter)
		{
			i++;
		}
		if(string1[i]=='\0')
		{
			goto x;
		}
		k=i;
		while(string1[i]!='\0')
		{
			string1[i]=string1[i+1];
			i++;
		}
		i=k;

	}
	x:cout<<"\nNew string: "<<string1;
}
void string_operations::replace_string()
{
	getstring();
	char replacesubstring[10],searchsubstring[10];
	cout<<"\nEnter substring that you want to search and replace\n";
	cin>>searchsubstring;
	cout<<"\nEnter substring to replace\n";
	cin>>replacesubstring;

	int i=0,j=0,k;
	while(string1[i]!='\0')
		{
			while(string1[i]!=searchsubstring[0] && string1[i]!='\0')
			{
				i++;
			}
			k=i;
			while(string1[i]==searchsubstring[j] && string1[i]!='\0' && searchsubstring[j]!='\0')
			{
				i++;
				j++;
			}
			if(string1[i]=='\0')
			{
				cout<<"\nString not found\n";
				return;
			}
			if(searchsubstring[j]=='\0')
			{
				goto x;
			}
			i=k;
			j=0;
		}

		x:cout<<endl;
		int length1;
		for( length1=0;searchsubstring[length1]!='\0';length1++);

		for(i=k;string1[i]!='\0';i++)
		{
			string1[i]=string1[i+length1];
		}
		string1[i]='\0';


		int length2;
		for( length2=0;replacesubstring[length2]!='\0';length2++);

		int length3;
		for( length3=0;string1[length3]!='\0';length3++);

		for(j=string1[length3-1];j>=k;j--)
		{
			string1[j+length2]=string1[j];
		}



		for(i=j+1,k=0;replacesubstring[k]!='\0';i++,k++)
		{
			string1[i]=replacesubstring[k];
		}

		cout<<"\nNew string: " <<string1;
}
void string_operations::check_palindrome()
{
	getstring();
	int i,j,k;
	for(i=0;string1[i]!='\0';i++);
	for(j=i-1,k=0;j>=0;j--,k++)
	{
		string2[k]=string1[j];
	}
	string2[k]='\0';

	for(i=0,j=0;string1[i]==string2[j] && string1[i]!='\0' && string2[j]!='\0';i++,j++);

	if(string1[i]=='\0' && string2[j]=='\0')
	{
		cout<<"\nStrings are palidrome\n";
	}
	else
	{
		cout<<"\nStrings are  not palindrome\n";

	}


}
int main()
{
	int option;
	string_operations s;
	do
	{
		cout<<"\n1.copy string\n";
		cout<<"\n2.concate string\n";
		cout<<"\n3.check substring\n";
		cout<<"\n4.check equal\n";
		cout<<"\n5.Reverse string\n";
		cout<<"\n6.Find Length\n";
		cout<<"\n7.find frequency\n";
		cout<<"\n8.delete substring\n";
		cout<<"\n9.delete all occurene of character\n";
		cout<<"\n10.replace substring\n";
		cout<<"\n11.check palindrome\n";
		cout<<"\nEnter option\n";
		cin>>option;
		switch(option)
		{
		case 1:
			s.copy_string();
			break;
		case 2:
			s.concatenate_string();
			break;
		case 3:
			s.check_substring();
			break;
		case 4:
			s.check_equal();
			break;
		case 5:
			s.reverse_string();
			break;
		case 6:
			s.find_length();
			break;
		case 7:
			s.find_frequency();
			break;
		case 8:
			s.delete_substring();
			break;
		case 9:
			s.delete_all_occurence_of_character();
			break;
		case 10:
			s.replace_string();
			break;
		case 11:
			s.check_palindrome();
			break;
		}

	}while(option!=0);
	return 0;
}

//============================================================================
// Name        : Assignme8_infix_postfix.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 20
class infixtopostfix
{
	char data[MAX];
	int top;
	char infix[20],postfix[20];
public:
	void init();
	void push(char);
	char pop();
	int isempty();
	int isfull();
	int precedence(char);
	char Return_top();
	void infix_to_postfix(char[],char[]);
};
void infixtopostfix::init()
{
	top=-1;
}
int infixtopostfix::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int infixtopostfix::isfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
void infixtopostfix::push(char x)
{
	top++;
	data[top]=x;
}
char infixtopostfix::pop()
{
	char x;
	x=data[top];
	top--;
	return x;
}
char infixtopostfix::Return_top()
{
	return data[top];
}
int infixtopostfix::precedence(char x)
{
	if(x=='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/'||x=='%')
		return 2;
	if(x=='^')
		return 3;
	return 0;
}
void infixtopostfix::infix_to_postfix(char infix[20],char postfix[20])
{
	cout<<"hi";
	int i,j;
	char x;
	char token;
	init();
	j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		token=infix[i];
		if(isalnum(token))
		{
			postfix[j++]=token;
		}
		else

		{
			if(token=='(')
			{
				push('(');
			}
			else
			{
				if(token==')')
				{
					while((x=pop())!='(')
					{
						postfix[j++]=x;
					}
				}
				else
				{
					while(precedence(token)<=precedence(top) && !isempty())
					{
						x=pop();
						postfix[j++]=x;
					}
					push(token);
				}
			}
		}

	}
	while(!isempty())
	{
		x=pop();
		postfix[j++]=x;
	}
	postfix[j]='\0';
	cout<<"\nPostfix: "<<postfix;

}

int main()
{
	infixtopostfix i;
	char infix[20],postfix[20];
	cout<<"\nEnter your infix expression\n";
	cin>>infix;
	i.infix_to_postfix(infix,postfix);
	cout<<"h";
	return 0;

}

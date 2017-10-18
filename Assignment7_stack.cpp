//============================================================================
// Name        : Assignment7_stack.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10
class stack
{
	char data[MAX];
	int top;
public:
	void init();
	void push(char);
	char pop();
	int isempty();
	int isfull();
};
void stack::init()
{
	top=-1;
}
int stack::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int stack::isfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
void stack::push(char x)
{
	top++;
	data[top]=x;
}
char stack::pop()
{
	char x;
	x=data[top];
	top--;
	return x;
}
int main()
{
	stack s;
	s.init();
	char ch;
	char expression[20];
	cout<<"\nEnter expression\n";
	cin>>expression;
	for(int i=0;expression[i]!='\0';i++)
	{
		ch=expression[i];
		switch(ch)
		{
		case '(':
			s.push('(');
			break;
		case '{':
			s.push('{');
			break;
		case '[':
			s.push('[');
			break;
		case ')':
			s.pop();
			break;
		case ']':
			s.pop();
			break;
		case '}':
			s.pop();
			break;
		}
	}
	if(s.isempty())
	{
		cout<<"\nExpression is well paranthesis\n";
	}
	else
	{
		cout<<"\nExpression is not well paranthesis\n";
	}
	return 0;

}

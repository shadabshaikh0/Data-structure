//============================================================================
// Name        : Assignme8_infix_postfix.cpp
// Author      : shadab shaikh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//===============RATTA MARNE KI KOSHISH MAT KARNA FAT JAYEGI==================
#include <iostream>
using namespace std;
#define MAX 20
//===char stack for infix to postfix conversion====
class stack
{
public:
	char data[MAX];
	int top;
};
//===integer stack for infix to postfix evaluation====
class stack2
{
public:
	int data[MAX];
	int top;
};
//===class for infix to postfix operation======
class infixtopostfix
{
	char infix[20],postfix[20];
public:
	//===functions of char stack for infix to postfix conversion===
	void init(stack *);
	void push(stack *,char);
	char pop(stack *);
	int isempty(stack *);
	int isfull(stack *);

	//===functions of integer stack for infix to postfix conversion===
	void init1(stack2 *);
	void push1(stack2 *,int);
	int pop1(stack2 *);
	int isempty1(stack2 *);
	int isfull1(stack2 *);

	//===============================================================
	int precedence(char);
	int precendenceoftop(stack *);
	void infix_to_postfix(char[],char[]);
	int  evaluate(char ,char ,char);
	void evaluation(char []);
};

//===functions of char stack for infix to postfix conversion===
void infixtopostfix::init(stack * s)
{
	s->top=-1;
}
int infixtopostfix::isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int infixtopostfix::isfull(stack *s)
{
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}
void infixtopostfix::push(stack *s,char x)
{
	s->top++;
	s->data[s->top]=x;
}
char infixtopostfix::pop(stack *s)
{
	char x;
	x=s->data[s->top];
	s->top--;
	return x;
}

//===functions of integer stack for infix to postfix conversion===
void infixtopostfix::init1(stack2 * s)
{
	s->top=-1;
}
int infixtopostfix::isempty1(stack2 *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int infixtopostfix::isfull1(stack2 *s)
{
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}
void infixtopostfix::push1(stack2 *s,int x)
{
	s->top++;
	s->data[s->top]=x;
}
int infixtopostfix::pop1(stack2 *s)
{
	int x;
	x=s->data[s->top];
	s->top--;
	return x;
}

int infixtopostfix::precendenceoftop(stack *s)
{
	   char b;
	    b=s->data[s->top];
	    switch(b)
	    {
	     case '(':return 0; break;
	     case '+':return 2; break;
	     case '-':return 2; break;
	     case '*':return 4; break;
	     case '/':return 4; break;
	     case '^':return 5; break;
	    }
}
int infixtopostfix::precedence(char x)
{
	   switch(x)
	    {
	     case '(':return 9; break;
	     case '+':return 2; break;
	     case '-':return 2; break;
	     case '*':return 4; break;
	     case '/':return 4; break;
	     case '^':return 5; break;
	    }
}
void infixtopostfix::infix_to_postfix(char infix[20],char postfix[20])
{
	stack s;
	int i,j;
	char x;
	char token;
	init(&s);
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
				push(&s,'(');
			}
			else
			{
				if(token==')')
				{
					while((x=pop(&s))!='(')
					{
						postfix[j++]=x;
					}
				}
				else
				{
					while(precedence(token)<=precendenceoftop(&s) && !isempty(&s))
					{
						x=pop(&s);
						postfix[j++]=x;
					}
					push(&s,token);
				}
			}
		}

	}
	while(!isempty(&s))
	{
		x=pop(&s);
		postfix[j++]=x;
	}
	postfix[j]='\0';
	cout<<"\nPostfix: "<<postfix;

}
//=================Evaluation=============================
int infixtopostfix::evaluate(char x,char ope1,char ope2)
{
	int op1,op2,result;
	op1=ope1;
	op2=ope2;

	if(x=='+')
		result=	(op1+op2);
	if(x=='-')
		result= (op1-op2);
	if(x=='*')
		result= (op1*op2);
	if(x=='/')
		result= (op1/op2);
	if(x=='%')
		result= (op1%op2);
	return result;
}

void infixtopostfix::evaluation(char postfix[])
{

	char operand1,operand2;
	char val;
	stack2 s;
	init1(&s);
	int i=0;
	while(postfix[i]!='\0')
	{

		if(isdigit(postfix[i]))
		{
			cout<<" "<<postfix[i];
			push1(&s,postfix[i]-48);
		}
		else
		{
			operand2=pop1(&s);
			operand1=pop1(&s);
			val=evaluate(postfix[i],operand1,operand2);
			push1(&s,val);
		}
		i++;
	}
	val=pop1(&s);
	cout<<"\nResult:"<<(int)val;
}
//======================================
int main()
{
	infixtopostfix i;
	//===conversion===
	char infix[20],postfix[20];
	cout<<"\nEnter your infix expression\n";
	cin>>infix;
	i.infix_to_postfix(infix,postfix);

	//===evaluation===
	i.evaluation(postfix);
	return 0;

}

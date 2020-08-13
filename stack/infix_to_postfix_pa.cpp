#include<bits/stdc++.h>

using namespace std;

bool isOperator(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return true;
	else
		return false;
}

int in_stack_precedence(char x)
{
	if(x=='+' || x=='-')
		return 2;
	else if(x=='*' || x=='/')
		return 4;
	else if(x=='^')
		return 5;
	else if(x=='(')
		return 0;
}

int out_stack_precedence(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 3;
	else if(x=='^')
		return 6;
	else if(x=='(')
		return 7;
}

char * infix_to_postfix(char str[])
{
	stack <char> st;
	int i=0,j=0;
	char *postfix;

	postfix=(char *)malloc(strlen(str)*sizeof(char)+1);

	while(str[i]!='\0')
	{
		if(str[i]=='(')
		{
			st.push(str[i]);
			i++;
		}
		else if(str[i]==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				postfix[j++]=st.top();
				st.pop();
			}
			if(st.top()=='(')
			{
				st.pop();
				i++;
			}
		}
		else if(isOperator(str[i]))
		{
			if(st.empty())
				st.push(str[i++]);
			else
			{
				if(out_stack_precedence(str[i]) > in_stack_precedence(st.top()))
				{
					st.push(str[i]);
					i++;
				}
				else
				{
					while(!st.empty() 
					&& (out_stack_precedence(str[i]) <= in_stack_precedence(st.top())))
					{
						postfix[j++]=st.top();
						st.pop();
					}
					st.push(str[i]);
					i++;
				}
			}
		}
		else//if operand is encountered
		{
			postfix[j++]=str[i++];
		}
	}
	while(!st.empty())//add leftover operators
	{
		postfix[j++]=st.top();
		st.pop();
	}
	postfix[j]='\0';
	return postfix;
}

int main()
{
	char infix[]="((a+b)*c)-d^e^f";

	char *postfix=infix_to_postfix(infix);

	cout<<postfix<<endl;

	return 0;
}
#include<iostream>
#include<string.h>
#include<stack>
#include<stdlib.h>

using namespace std;

int priority(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	else
		return 0;
}

bool isOperator(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
		return true;
	else
		return false;
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
				if(priority(str[i]) > priority(st.top()))
				{
					st.push(str[i]);
					i++;
				}
				else
				{
					while(!st.empty() && (priority(str[i]) <= priority(st.top())))
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
	char str[]="(c*(d/(a+b)*e)/f)";
	char *postfix;

	postfix=infix_to_postfix(str);

	cout<<postfix<<endl;

	return 0; 
}
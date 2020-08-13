#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
		return true;
	else
		return false;
}

float evaluate(char expression[])
{
	int i=0;
	stack <float> st;

	while(expression[i]!='\0')
	{
		if(isOperator(expression[i]))
		{
			float B=st.top();
			st.pop();
			float A=st.top();
			st.pop();

			float result;
			
			switch(expression[i])
			{
				case '+':
					result=A+B;
					break;

				case '-':
					result=A-B;
					break;

				case '*':
					result=A*B;
					break;

				case '/':
					result=A/B;
					break;
			}
			st.push(result);
		}
		else
		{
			float float_equivalent=(float)(expression[i]-'0');
			st.push(float_equivalent);
		}
		i++;
	}
	return st.top();
}

int main()
{
	char expression[]="934*8+4/-";

	cout<<"Ans = "<<evaluate(expression)<<endl;

	return 0;
}
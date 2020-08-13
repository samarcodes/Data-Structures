#include<iostream>
#include<stack>

using namespace std;

void enqueue(stack <int> s1,int value)
{
	s1.push(value);
}

int dequeue(stack <int> s1,stack <int> s2)
{
	int x=-1;
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		x=s2.top();
		s2.pop();
	}
	else
	{
		x=s2.top();
		s2.pop();
	}
	return x;
}

int main()
{
	stack <int> s1;
	stack <int> s2;

	enqueue(s1,1);
	enqueue(s1,2);
	enqueue(s1,3);

	cout<<dequeue(s1,s2);

	return 0;
}
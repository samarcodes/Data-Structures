#include<iostream>
#include<stack>
using namespace std;

void showStack(stack <int> st)
{
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
}

int main()
{
	stack <int> st;

	//push() adds element at top
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	showStack(st);

	//size() for size of stack
	cout<<"Size = "<<st.size()<<endl;
	//top() to know what is the top element
	cout<<"Top element = "<<st.top()<<endl;
	//empty() to if stack is empty or not
	st.empty()==0 ? cout<<"Not Empty"<<endl : cout<<"Empty"<<endl ;

	//to remove top element
	st.pop();

	showStack(st);
	return 0;
}
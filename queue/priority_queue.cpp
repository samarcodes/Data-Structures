#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue <int> q1;
	queue <int> q2;
	queue <int> q3;

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int element,priority;
		
		cout<<"enter element & priority"<<endl;
		cin>>element>>priority;
		if(priority==1)
			q1.push(element);
		else if(priority==2)
			q2.push(element);
		else
			q3.push(element);
	}
	while(!q1.empty())
	{
		cout<<q1.front()<<" ";
		q1.pop();
	}
	while(!q2.empty())
	{
		cout<<q2.front()<<" ";
		q2.pop();
	}
	while(!q3.empty())
	{
		cout<<q3.front()<<" ";
		q3.pop();
	}	
	return 0;
}
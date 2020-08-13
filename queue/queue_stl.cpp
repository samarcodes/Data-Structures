#include<iostream>
#include<queue>

using namespace std;

void display(queue <int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	cout<<endl;
}

int main()
{
	queue <int> q;

	//insert at rear
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	display(q);

	//delete from front
	q.pop();
	q.pop();
	q.pop();

	display(q);

	cout<<"Size = "<<q.size()<<endl;
	cout<<"Empty = "<<q.empty()<<endl;
	cout<<"front = "<<q.front()<<endl;
	cout<<"rear = "<<q.back()<<endl;

	return 0;
}
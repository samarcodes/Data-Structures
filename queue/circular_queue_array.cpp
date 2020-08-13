//queue using circular array

#include<bits/stdc++.h>

using namespace std;

struct Queue 
{
	int size;
	int front;
	int rear;
	int *Q;
};

void enqueue(struct Queue *q,int value)
{
	if( (q->rear+1) % q->size == q->front)
		cout<<"Queue Overflow"<<endl;
	else
	{
		q->rear = (q->rear+1) % q->size;
		q->Q[q->rear] = value;
	}
}

int dequeue(struct Queue *q)
{
	int x=-1;
	if(q->front==q->rear)
		cout<<"Queue Underflow"<<endl;
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

void display(struct Queue q)
{
	if(q.front==q.rear)
		cout<<"Queue Empty"<<endl;
	else
	{
		while(q.front!=q.rear)
		{
			q.front=(q.front+1)%q.size;
			cout<<q.Q[q.front]<<endl;
		}
	}
}

int main()
{
	struct Queue q;

	q.size=5;
	q.front=q.rear=0;
	q.Q = new int[q.size];

	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);

	display(q);

	dequeue(&q);
	dequeue(&q);

	display(q);

	enqueue(&q,5);
	enqueue(&q,6);
	
	display(q);

	return 0;
}
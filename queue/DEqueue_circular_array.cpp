//DEqueue using circular array

#include<bits/stdc++.h>

using namespace std;

struct Queue 
{
	int size;
	int front;
	int rear;
	int *Q;
};

void enqueue_rear(struct Queue *q,int value)
{
	if( (q->rear+1) % q->size == q->front)
		cout<<"Queue Overflow"<<endl;
	else
	{
		q->rear = (q->rear+1) % q->size;
		q->Q[q->rear] = value;
	}
}

void enqueue_front(struct Queue *q,int value)
{
	if( (q->front-1)%q->size == q->rear )
		cout<<"Queue Overflow"<<endl;
	else
	{
		q->Q[q->front] = value;
		q->front = (q->front-1) % q->size;
	}
}

int dequeue_front(struct Queue *q)
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

int dequeue_rear(struct Queue *q)
{
	int x=-1;
	if( (q->rear==0) || (q->rear-1)%q->size ==q->front )
		cout<<"Queue Underflow"<<endl;
	else
	{
		q->rear=(q->rear-1)%q->size;
		x=q->Q[q->rear];
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
		cout<<endl;
	}
}

int main()
{
	struct Queue q;

	q.size=5;
	q.front=q.rear=0;
	q.Q = new int[q.size];

	enqueue_rear(&q,1);
	enqueue_rear(&q,2);
	enqueue_rear(&q,3);
	enqueue_rear(&q,4);
	display(q);

	dequeue_front(&q);
	dequeue_front(&q);
	dequeue_front(&q);
	display(q);

	enqueue_rear(&q,5);
	enqueue_rear(&q,6);
	display(q);

	dequeue_rear(&q);
	display(q);

	return 0;
}
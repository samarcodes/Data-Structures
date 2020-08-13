//DEqueue using normal array

#include<bits/stdc++.h>

using namespace std;

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

//insert at rear end
void enqueue_rear(struct Queue *q,int element)
{
	//Full Queue
	if(q->rear == q->size-1)
		cout<<"Queue is Full"<<endl;
	else
	{
		q->rear++;
		q->Q[q->rear]=element;
	}
}

//insert at front end
void enqueue_front(struct Queue *q,int element)
{
	//Full Queue
	if(q->front==-1)
		cout<<"Queue is Full"<<endl;
	else
	{
		q->Q[q->front]=element;
		q->front--;
	}
}

//delete at front end
int dequeue_front(struct Queue *q)
{
	int x;
	//Empty Queue
	if(q->rear == q->front)
		cout<<"Queue is Empty"<<endl;
	else
	{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}

//delete at rear end
int dequeue_rear(struct Queue *q)
{
	int x;
	//Empty Queue
	if(q->rear == -1)
		cout<<"Queue is Empty"<<endl;
	else
	{
		x=q->Q[q->rear];
		q->rear--;
	}
	return x;
}

void display(struct Queue q)
{
		for(int i=q.front+1;i<=q.rear;i++)
			cout<<q.Q[i]<<endl;
		cout<<endl;	
}

int main()
{
	struct Queue q;
	q.size=10;
	q.front=q.rear=-1;
	q.Q = new int[q.size];

	enqueue_rear(&q,1);
	enqueue_rear(&q,2);
	enqueue_rear(&q,3);
	enqueue_rear(&q,4);
	enqueue_rear(&q,5);

	display(q);

	dequeue_front(&q);
	dequeue_front(&q);

	display(q);

	enqueue_front(&q,1);
	enqueue_front(&q,2);

	display(q);

	dequeue_rear(&q);
	dequeue_rear(&q);

	display(q);

	return 0;
}
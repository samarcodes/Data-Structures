//queue using normal array

#include<bits/stdc++.h>

using namespace std;

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

void enqueue(struct Queue *q, int element)
{
	//overflow condition
	if (q->rear == q->size - 1)
		cout << "Queue is Full" << endl;
	else
	{
		q->rear++;
		q->Q[q->rear] = element;
	}
}

int dequeue(struct Queue *q)
{
	int x;
	//underflow condition
	if (q->rear == q->front)
		cout << "Queue is Empty" << endl;
	else
	{
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}

void display(struct Queue q)
{
	for (int i = q.front + 1; i <= q.rear; i++)
		cout << q.Q[i] << endl;
}

int main()
{
	struct Queue q;
	q.size = 10;
	q.front = q.rear = -1;
	q.Q = new int[q.size];

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	enqueue(&q, 7);
	enqueue(&q, 8);
	enqueue(&q, 9);
	enqueue(&q, 10);

	display(q);

	return 0;
}
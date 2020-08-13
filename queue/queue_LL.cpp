//queue using linked lists

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void enqueue(struct Node **front_ref,struct Node **rear_ref,int value)
{
	struct Node *new_node = new Node;

	//if new_node not allocated
	if(new_node==NULL)
		cout<<"Queue Overflow(Heap Overflow)"<<endl;
	else
	{
		new_node->data=value;
		new_node->next=NULL;

		//for first node in queue
		if((*front_ref)==NULL)
			(*front_ref)=(*rear_ref) = new_node;
		else
		{
			(*rear_ref)->next = new_node;
			(*rear_ref) = new_node;
		}
	}
}

int dequeue(struct Node **front_ref,struct Node **rear_ref)
{
	int x=-1;

	if((*front_ref)==NULL)
		cout<<"Queue Underflow"<<endl;
	else
	{
		struct Node *p=(*front_ref);
		(*front_ref) = (*front_ref)->next;
		x=p->data;
		delete(p);
	}
	return x;
}

void display(struct Node *front,struct Node *rear)
{
	struct Node *p=front;
	if(front==NULL)
		cout<<"Queue Empty"<<endl;
	else
	{
		while(p)
		{	
			cout<<p->data<<endl;
			p=p->next;
		}
	}
}

int main()
{
	struct Node *front=NULL;
	struct Node *rear=NULL;

	enqueue(&front,&rear,1);
	enqueue(&front,&rear,2);
	enqueue(&front,&rear,3);
	enqueue(&front,&rear,4);
	enqueue(&front,&rear,5);

	display(front,rear);

	dequeue(&front,&rear);
	dequeue(&front,&rear);

	display(front,rear);

	return 0;
}
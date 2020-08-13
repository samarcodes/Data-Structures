#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node **top,int element)
{
	struct Node *new_node=new Node;

	//if memory not allocated
	if(new_node==NULL)
    {
        cout<<"Stack Overflow";
    }
    else
    {
        new_node->data = element;
        new_node->next = *top;
        *top = new_node;
    }

}

int pop(struct Node **top)
{
	int x=-1;
	struct Node *p=*top;

	//stack empty condition
	if(*top==NULL)
		cout<<"Stack Underflow";
	else
	{
		x = (*top)->data;
		*top = (*top)->next;
		delete(p);
	}
	return x;
}

void display(struct Node *p)
{
	if(p==NULL)
	{
		cout<<"Empty Stack";
		return;
	}

	while(p!=NULL)
	{
		cout<<p->data<<" "<<endl;
		p=p->next;
	}
}

int peek(struct Node *top,int index)
{
    for(int i=0;i<index-1;i++)
    {
        top=top->next;
    }

    if(top)
    {
        return top->data;
    }
    else
        return -1;
}

int stackTop(struct Node *top)
{
    if(top)
        return top->data;
    else
        return -1;
}

int isFull(struct Node *top)
{
    struct Node *new_node=new Node;
    int r=new_node ? 0 : 1 ;
    delete(new_node);
    return r;
}

int isEmpty(struct Node *top)
{
    return top ? 0 : 1;
}

int main()
{
	struct Node *head=NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	display(head);

	pop(&head);
	pop(&head);
	display(head);

	cout<<"\n";
	cout<<peek(head,2);

	isEmpty(head) ? cout<<"Empty" : cout<<"Not Empty";
	cout<<"\n";
	isFull(head) ? cout<<"Full" : cout<<"Not Full";

	return 0;
}

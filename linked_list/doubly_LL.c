#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

struct Node * create(int a[],int n)
{
    struct Node *p,*last_node,*new_node;

    p=(struct Node *)malloc(sizeof(struct Node));
    p->data = a[0];
    p->prev = p->next = NULL;
    last_node = p;

    for(int i=1;i<n;i++)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data = a[i];
        new_node->prev = last_node;
        new_node->next = last_node->next; //this will transfer the NULL to new node
        last_node->next = new_node;
        last_node = new_node;
    }
    printf("Linked List Created...\n");
    return p;
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int Length(struct Node *p)
{
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p,int index,int element)
{
    struct Node *new_node;
    int i;

    if(index < 0 && index>Length(p))
        return;

    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data = element;

    if(index==0)
    {
        new_node->prev = p->prev;
        new_node->next = p;
        p->prev = new_node;
        first=new_node;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;

        new_node->next = p->next;
        new_node->prev = p;

        if(p->next) //specifically if we are inserting at last
            p->next->prev = new_node;

        p->next = new_node;
    }
}

void delete_dll(struct Node *p,int index)
{
    int i;

    if(index >= 0 && index <= Length(p))
    {

        if(index==1)
        {
            first=first->next;
            free(p);

            if(first)
                first->prev=NULL;
        }
        else
        {
            for(int i=0;i<index-1;i++)
                p=p->next;

            p->prev->next = p->next;

            if(p->next)
                p->next->prev = p->prev;

            free(p);
        }
    }
}

void reverse(struct Node *p)
{
    struct Node *t;
    while(p!=NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;

        if(p!=NULL && p->next==NULL)
            first=p;


    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    first=create(a,n);

    /*
    printf("length=%d\n",Length(first));

    insert(first,5,10);

    delete_dll(first,5);
    */
    reverse(first);
    display(first);

	return 0;
}


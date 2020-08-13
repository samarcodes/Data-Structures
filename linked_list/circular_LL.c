#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first;

struct Node * create(int a[],int n)
{
    int i;
    struct Node *p,*t,*last;

    //create first node
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=a[0];
    p->next=p;
    last=p;      //set current node as last node

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
    printf("Linked List created\n");
    return p;
}

//to display a circular LL
void display(struct Node *p)
{
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=first);
}

int count_nodes(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=first);

    return len;
}

void insert(struct Node *p,int index,int element)
{
    struct Node *t,*q;
    int i;

    if(index>=0 && index<=count_nodes(p))
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=element;
        if(index==0)
        {
            if(p==NULL)
            {
                first=p=t;
                first->next=t;
            }
            else
            {
                while(p->next!=first)
                    p=p->next;

                p->next=t;
                t->next=first;
                first=t;
            }
        }
        else
        {
            for(i=0;i<index;i++)
            {
                q=p;
                p=p->next;
            }
            t->next=p;
            q->next=t;
        }
    }
}

void delete_cll(struct Node *p,int index)
{
    struct Node *q;

    if(index>=1 && index<=count_nodes(p))
    {
        if(index==1)
        {
            while(p->next!=first)
                    p=p->next;

            //if only one node in LL
            if(p==first)
            {
                free(first);
                first=NULL;
            }
            else
            {
                p->next=first->next;
                free(first);
                first=p->next;
            }

        }
        else
        {
            int i;
            for(i=0;i<index-1;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            free(p);
        }
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    first=create(a,n);

    /*
    insert(first,0,101);

    delete_cll(first,1);
    */

    display(first);
	return 0;
}


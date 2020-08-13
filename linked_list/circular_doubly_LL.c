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
    int i;

    p=(struct Node *)malloc(sizeof(struct Node));
    p->data = a[0];
    p->prev = NULL;
    p->next = p;
    last_node=p;

    for(i=1;i<n;i++)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data = a[i];
        new_node->prev = last_node;
        new_node->next = last_node->next;
        last_node->next = new_node;
        last_node = new_node;
    }

    p->prev = last_node;
    return p;
}

void display(struct Node *p)
{
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=first);
}

int count_nodes(struct Node *p)
{
    int count = 0;
    if(p==NULL) //if LL is empty (!important condition for insert method)
        return 0;
    do{
        count++;
        p=p->next;
    }while(p!=first);
    return count;
}

void insert(struct Node *p,int index,int element)
{
    struct Node *new_node;

    if(index>=0 && index<=count_nodes(p))
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data = element;
        new_node->prev = NULL;
        new_node->next = NULL;

        if(index==0)
        {
            if(first==NULL)//no node in LL
            {
                first=p = new_node;
                first->next = first;
                first->prev = first;
            }
            else
            {
                new_node->next = p;
                new_node->prev = p->prev;
                p->prev->next = new_node; //link last node to new node
                p->prev = new_node;
                first = new_node;
            }
        }
        else
        {
            for(int i=0;i<=index-2;i++)
                p=p->next;

            new_node->next = p->next;
            new_node->prev = p;

            p->next->prev = new_node;

            p->next = new_node;
        }
    }
}

void delete_C_LL(struct Node *p,int index)
{
    struct Node *q;
    int i;

    if(index>0 && index<=count_nodes(p))
    {
        if(index==1)
        {
            first = first->next;
            first->prev = p->prev;
            p->prev->next = first;
            free(p);
        }
        else
        {
            for(int i=0;i<index-1;i++)
                p = p->next;

            p->prev->next = p->next;
            p->next->prev = p->prev;
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
    insert(first,0,10);
    */
    delete_C_LL(first,0);
    display(first);

	return 0;
}


#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
}*first, *second, *third;

struct Node * create(int a[], int n)
{
	int i;
	struct Node *p, *t, *last;

	//create first node
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = a[0];
	p->next = NULL; //set next ptr to null
	last = p;    //set current node as last node

	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
	printf("Linked List created\n");
	return p;
}

//display
void display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

//recursive display
void Rdisplay(struct Node *p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		Rdisplay(p->next);
	}
}

//count nodes
int count_nodes(struct Node *p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

//recursive count
int Rcount_nodes(struct Node *p)
{
	if (p == NULL)
		return 0;
	return Rcount_nodes(p->next) + 1;
}

//sum of all nodes
int sum(struct Node *p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

//recursive sum
int Rsum(struct Node *p)
{
	if (p != NULL)
	{
		return p->data + sum(p->next);
	}
}

//max element
int max(struct Node *p)
{
	int max = p->data;
	p = p->next;
	while (p != NULL)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

//min element
int min(struct Node *p)
{
	int min = p->data;
	p = p->next;
	while (p != NULL)
	{
		if (p->data < min)
		{
			min = p->data;
		}
		p = p->next;
	}
	return min;
}

struct Node * Linear_search(struct Node *p, int key)
{
	struct Node *q;
	while (p != NULL)
	{
		if (key == p->data)
		{
			//move to head then return
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}

		q = p;
		p = p->next;
	}

	//return null if key not found
	return NULL;
}

struct Node * RLinear_search(struct Node *p, int key)
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RLinear_search(p->next, key);
}

//insert node in LL at given index
void insert(struct Node *p, int index, int element)
{
	struct Node *t;
	int i;

	if (index >= 0 && index <= count_nodes(p))
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = element;
		t->next = NULL;

		if (index == 0)
		{
			t->next = first;
			first = t;
		}
		else
		{
			for (i = 0; i < index - 1; i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
	else
		printf("Invalid Index!!!\n");
}

//insert at last in a given LL
void insert_last(struct Node *p, int element)
{
	int i;
	struct Node *last;
	struct Node *t;

	t = (struct Node *)malloc(sizeof(struct Node));

	last = p;
	t->data = element;
	t->next = NULL;

	for (i = 0; i < count_nodes(p) - 1; i++)
		last = last->next;

	if (second == NULL)
		second = last = t;
	else
	{
		last->next = t;
		last = t;
	}
}

void insert_in_sorted_LL(struct Node *p, int element)
{
	struct Node *t, *q;

	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = element;
	t->next = NULL;

	q = p;
	while (p && p->data < element)
	{
		q = p;
		p = p->next;
	}

	if (q == p)
	{
		t->next = q;
		first = t; //first m dalenge coz its global
	}
	else
	{
		t->next = q->next;
		q->next = t;
	}

}

int delete_node(struct Node *p, int index)
{
	int x;
	int i;
	struct Node *q;

	if (index < 1 || index > count_nodes(first))
		return NULL;

	if (index == 1)
	{
		first = first->next;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
	}
	if (p)
	{
		x = p->data;
		free(p);
		return x;
	}
}

void isSorted(struct Node *p)
{
	while (p->next != NULL)
	{
		if (p->data < p->next->data)
		{
			p = p->next;
		}
		else
			break;
	}

	if (p->next == NULL)
		printf("Sorted\n");
	else
		printf("Not Sorted\n");
}

void remove_duplicates(struct Node *p)
{
	struct Node * q = p->next;
	while (q != NULL)
	{
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
}

//reverse LL
void reverse(struct Node *p)
{
	struct Node *r, *q;
	q = r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

//recursive reverse LL
void Rreverse(struct Node *p, struct Node *q)
{
	if (p != NULL)
	{
		Rreverse(p->next, p);
		p->next = q;
	}
	else
		first = q;
}

void concat(struct Node *p, struct Node *q)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}

void merge(struct Node *p, struct Node *q)
{
	struct Node *last;

	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		last->next = NULL;
	}

	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}

	if (p != NULL)
		last->next = p;
	else
		last->next = q;
}

void isLoop(struct Node *p)
{
	struct Node *q;
	q = p;

	do {
		p = p->next;
		q = q->next;
		q = q != NULL ? q->next : NULL;

		if (p == q)
		{
			printf("LOOP");
			break;
		}

	} while (p && q);

	if (q == NULL)
		printf("No LOOP\n");
}

int main()
{
	struct Node *temp;
	int a[] = {30, 32, 33, 35, 37, 39, 40};
	int n = sizeof(a) / sizeof(a[0]);
	first = create(a, n);
	/*
	display(first);
	//Rdisplay(first);
	printf("\nnodes = %d",count_nodes(first));
	printf("\nsum = %d",sum(first));
	printf("\nmax = %d",max(first));
	printf("\nmin = %d",min(first));

	temp=Linear_search(first,7);
	if(temp)
	    printf("Key is found");
	else
	    printf("Key not found");

	insert(first,5,35);
	insert_last(first,67);
	insert_in_sorted_LL(first,34);

	printf("%d deleted\n",delete_node(first,4));

	isSorted(first);

	remove_duplicates(first);

	reverse(first);
	Rreverse(first,NULL);

	concat(first,second);

	merge(first,second);

	isLoop(first);
	*/
	display(first);
	return 0;
}

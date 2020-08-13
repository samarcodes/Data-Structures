#include<iostream>
using namespace std;

struct Stack
{
	int size;
	int top;
	int *s;
};

void push(struct Stack *st,int element)
{
	//overflow condition
	if(st->top == st->size-1)
		cout<<"Stack Overflow";
	else
	{
		st->top++;
		st->s[st->top]=element;
	}
}

int pop(struct Stack *st)
{
	int x=-1;
	//underflow condition
	if(st->top == -1)
		cout<<"Stack Underflow";
	else
	{
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

int peek(struct Stack st,int index)
{
    int x=-1;

    if(index > st.top+1)
        cout<<"Invalid Index ";
    else
    {
        x = st.s[st.top+1-index];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}

int main()
{
	struct Stack st;
	st.size=10;
	st.top=-1;
	st.s=new int[st.size];

	push(&st,10);
	push(&st,11);
	push(&st,12);

	cout<<"Elements are\n";
	for(int i=st.top;i>=0;i--)
	{
		cout<<st.s[i]<<" "<<endl;
	}

	cout<<peek(st,1);

	isEmpty(st) ? cout<<"Empty\n" : cout<<"Not Empty\n";
	isFull(st) ? cout<<"Full\n" : cout<<"Not Full\n";

	return 0;
}

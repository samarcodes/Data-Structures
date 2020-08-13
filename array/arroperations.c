#include<stdio.h>
struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr1)
{
    int i;
    for(i=0;i<arr1.length;i++)
        printf("%d ",arr1.A[i]);
}

void append(struct Array *arr1,int element)
{
    if(arr1->length < arr1->size)
    {
        arr1->A[arr1->length]=element;
        arr1->length+=1;
    }
}

void insert(struct Array *arr1,int index,int element)
{
    int i;
    if(arr1->length < arr1->size)
    {
        if(index >= 0 && index <= arr1->length)
        {
            for(i=arr1->length;i > index;i--)
            {
                arr1->A[i]=arr1->A[i-1];
            }
            arr1->A[index]=element;
            arr1->length+=1;
        }
    }
}

void del(struct Array *arr1,int index)
{
    int i;
    if(arr1->length > 0)
    {
        if(index >= 0 && index < arr1->length)
        {
            for(i=index;i<arr1->length-1;i++)
            {
                arr1->A[i] = arr1->A[i+1];
            }
            arr1->length-=1;
        }
    }
}

int main()
{
    struct Array arr={{1,3,2,4,5},20,5};
    append(&arr,10);
    display(arr);
    insert(&arr,2,0);
    printf("\n");
    display(arr);
    del(&arr,3);
    printf("\n");
    display(arr);
    return 0;
}

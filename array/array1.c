//insert element in sorted array
#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void insert_element(struct Array *arr,int element)
{
    int i=arr->length-1;
    if(arr->length<arr->size)
    {
        while(arr->A[i]>element)
        {
            arr->A[i+1]=arr->A[i];
            i--;
        }
        arr->A[i+1]=element;
        arr->length+=1;
    }
}

int isSorted(struct Array arr)
{
    int i=0;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return -1;
    }
    return 0;
}

void seperate(struct Array *arr)
{
    int i=0,j=arr->length-1,temp;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>0)
            j--;
        if(i<j)
        {
            temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}

int main()
{
    int i;
    struct Array a={{-1,4,6,-8,-9,15},10,6};
    //insert_element(&a,7);
    //printf("%d\n",isSorted(a));
    seperate(&a);
    for(i=0;i<a.length;i++)
        printf("%d ",a.A[i]);
    return 0;
}

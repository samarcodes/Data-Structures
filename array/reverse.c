#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void reverse(struct Array *arr)
{
    int i,j;
    int temp;
    for(i = 0 , j = arr->length-1 ; i < j ; i++ , j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
int main()
{
    int i;
    struct Array a={{1,5,2,77,0,4,3,2,99,100},10,10};
    reverse(&a);
    for(i=0;i<a.length;i++)
        printf("%d ",a.A[i]);
}

#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
int get(struct Array arr,int index) //getting element at particular index
{
    int k;
    if(index>=0 && index<arr.length)
        return arr.A[index];
}
void set(struct Array *arr,int index,int value) //replacing/overwriting value at given index
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=value;
    }
}
int max(struct Array arr) //to find max valued element in an array
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}
int min(struct Array arr) to find min valued element in an array
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}
int sum(struct Array arr) //to find sum of all elements of an array
{
    int i,sum=0;
    for(i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    return sum;
}
float avg(struct Array arr) //to find avg of array
{
    int i,sum=0;
    for(i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    return (float)sum/arr.length;
}
int main()
{
    int i;
    struct Array a={{1,5,2,77,0,4,3,2,99,100},10,10};
    printf("%d\n",get(a,5));
    set(&a,0,79);
    for(i=0;i<10;i++)
        printf("%d ",a.A[i]);
    printf("\n%d",max(a));
    printf("\n%d",min(a));
    printf("\n%d",sum(a));
    printf("\n%.3f",avg(a));
    return 0;
}

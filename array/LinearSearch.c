#include<stdio.h>
int linear_search(int arr[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            //swap(arr[i],arr[i-1]);//transposition
            //swap(arr[i],arr[0]);//move to front/head
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[]={0,100,25,26,35,477,89,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int num;
    printf("enter element : ");
    scanf("%d",&num);
    printf("%d",linear_search(arr,n,num));
    return 0;
}

#include<stdio.h>
int binary_search(int arr[],int l,int h,int k)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(k==arr[mid])
            return mid;
        else if(k<arr[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int Rbinary_search(int arr[],int l,int u,int key)
{
    int mid=0;
    if(l<=u)
    {
        mid=(l+u)/2;
        if(key==mid)
            return mid;
        else if(key<arr[mid])
            return Rbinary_search(arr,l,mid-1,key);
        else
            return Rbinary_search(arr,mid+1,u,key);
    }
    return -1;
}
int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9};//it must be a sorted array
    int n=10;
    int num;
    printf("enter element : ");
    scanf("%d",&num);
    printf("%d",Rbinary_search(arr,0,n-1,num));
    return 0;
}

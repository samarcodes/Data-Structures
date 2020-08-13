#include<stdio.h>
void pair_with_sum(int A[],int n,int sum) //native approach O(n2)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]+A[j]==sum)
                printf("%d,%d\n",A[i],A[j]);
        }
    }
}

void hash_pair_with_sum(int A[],int n,int sum) //using hashing to make it O(n)
{
    int i,j;
    int Hash[16]={0};
    for(i=0;i<n;i++)
    {
        if(A[i]<=sum)
        {
            if(Hash[sum-A[i]]!=0)
                printf("%d,%d\n",A[i],sum-A[i]);
            Hash[A[i]]++;
        }
    }
}

void sorted_pair_with_sum(int A[],int n,int sum)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(A[i]+A[j]==sum)
        {
            printf("%d,%d\n",A[i],A[j]);
            i++;
            j--;
        }
        else if(A[i]+A[j]>sum)
            j--;
        else
            i++;
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(A)/sizeof(A[0]);
    sorted_pair_with_sum(A,n,10);
    return 0;
}

#include<stdio.h>
int missing_element(int A[],int n)
{
    int sum=0,s;
    int i;
    for(i=0;i<n;i++) //sum of array
        sum+=A[i];
    s=A[n-1]*(A[n-1]+1)/2; //sum of A[n-1] natural nos.
    return s-sum;
}
int Amissing_element(int A[],int n)
{
    int i;
    int diff=A[0];
    for(i=0;i<n;i++)
    {
        if(A[i]-i!=diff)
        {
            return("%d",i+diff);
            break;
        }
    }
}

void Sorted_missing_elements(int A[],int n)
{
    int diff=A[0];
    int i,j;
    for(i=0;i<n;i++)
    {
        if(A[i]-i!=diff)
        {
            while(diff<A[i]-i)
            {
                printf("%d ",diff+i);
                diff++;
            }
        }
    }
}

void Unsorted_missing_elements(int a[],int n)
{
    int i;
    int max=a[0];
    int *hash;

    for(i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }

    hash=(int *)calloc((max+1),sizeof(int));

    for(i=0;i<n;i++)
    {
        hash[a[i]]+=1;
    }

    for(i=1;i<max+1;i++)
    {
        if(hash[i]==0)
            printf("%d ",i);
    }

    free(hash);
}

int main()
{
    int A[]={1,2,3,4,5,7,8,9,10,11,12};//single missing element in sorted array starting from 1 only
    int B[]={6,7,8,9,11,12,13,14};//single missing element in sorted array using element and index difference
    int C[]={6,7,8,9,10,12,16};//multiple missing element in sorted array
    int D[]={1,10,3,14,12,7};//multiple missing element in unsorted array

    int A_n=sizeof(A)/sizeof(A[0]);
    int B_n=sizeof(B)/sizeof(B[0]);
    int C_n=sizeof(C)/sizeof(C[0]);
    int D_n=sizeof(D)/sizeof(D[0]);

    //printf("%d\n",missing_element(A,A_n));
    //printf("%d\n",Amissing_element(B,B_n));
    //Sorted_missing_elements(C,C_n);
    Unsorted_missing_elements(D,D_n);
    return 0;
}

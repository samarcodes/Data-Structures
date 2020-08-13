#include<stdio.h>
void Sorted_duplicates(int A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            j=i+1;
            while(A[j]==A[i] && j<n)
            {
                j++;
            }
            printf("%d is duplicated %d times\n",A[i],j-i);
            i=j;
        }
    }
}

void Unsorted_duplicates(int A[],int n)
{
    int i,j,count;
    for(i=0;i<n;i++)
    {
        count=1;
        if(A[i]!=-1)
        {
            for(j=i+1;j<n;j++)
            {
                if(A[i]==A[j])
                {
                    A[j]=-1;
                    count++;
                }
            }
        if(count>1)
            printf("%d is duplicated %d times\n",A[i],count);
        }

    }
}
int main()
{
    int A[]={0,1,2,2,4,5,6,6};
    int n=sizeof(A)/sizeof(A[0]);
    Sorted_duplicates(A,n);
    //Unsorted_duplicates(A,n);
    return 0;
}

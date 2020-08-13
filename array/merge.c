#include<stdio.h>
int main()
{
    int A[]={1,3,5,7,9};
    int B[]={2,4,6,8,10};
    int C[10];
    int i=0,j=0,k=0;
    while(i<5 && j<5)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else
            C[k++]=B[j++];
    }
    while(i<5)
        C[k++]=A[i++];
    while(j<5)
        C[k++]=B[j++];

    for(i=0;i<10;i++)
        printf("%d ",C[i]);
}

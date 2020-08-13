//fibonacci series using recursion
//18-01-2020
#include<stdio.h>
#include<stdlib.h>
int F[20];
int fibo(int);
int Mfibo(int);//using memoization technique (reduced number of calls)
int main()
{
    int n,i;
    printf("enter no. of terms in series : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        F[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",Mfibo(i));
    }
    return 0;
}

int fibo(int n)
{
    if(n==0 || n==1)
        return n;
    else
        return (fibo(n-1)+fibo(n-2));
}

int Mfibo(int n)
{
    if(n==0 || n==1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=Mfibo(n-2);
        if(F[n-1]==-1)
            F[n-1]=Mfibo(n-1);
        F[n]=F[n-1]+F[n-2];
        return F[n-1]+F[n-2];
    }
}

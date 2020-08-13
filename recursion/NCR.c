//combination formula NCR using recursion
//used concept of pascal's triangle
//31-01-2020
#include<stdio.h>
int NCR(int,int);
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d",NCR(n,r));
    return 0;
}
int NCR(int n,int r)
{
    if(n==r || r==0)
        return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}

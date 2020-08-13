//program to calculate factorial using recursion
//22-01-2020
#include<stdio.h>
int factorial(int);
int main()
{
    int num;
    printf("enter number : ");
    scanf("%d",&num);
    printf("Factorial of %d = %d",num,factorial(num));
    return 0;
}
int factorial(int n)
{
    if(n==0)
        return 1;
    return(n*factorial(n-1));
}

//program to find power using recursion
//26-01-2020
#include<stdio.h>
int Power(int, int); //O(n)
int fastPower(int, int); //efficient power function O(logn)
int main()
{
	int base, exponent;
	printf("enter base : ");
	scanf("%d", &base);
	printf("enter exponent : ");
	scanf("%d", &exponent);
	printf("%d raised to %d = %d", base, exponent, fastPower(base, exponent));
}

int Power(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	return (base * Power(base, exponent - 1));
}

int fastPower(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent % 2 == 0)
		return (fastPower(base * base, exponent / 2));
	else
		return (base * fastPower(base * base, (exponent - 1) / 2));
}

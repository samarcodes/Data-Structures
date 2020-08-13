#include<stdio.h>
#include<string.h>

int check_palindrome(char str[])
{
    int i,j;
    i=0;
    j=strlen(str)-1;
    while(i<j)
    {
        if(str[i]!=str[j])
            break;
        i++;
        j--;
    }
    if(i<j)
        return -1;
    else
        return 0;
}

int main()
{
    int k;
    char str[20];
    scanf("%s",str);

    k=check_palindrome(str);

    if(k==0)
        printf("palindrome");
    else
        printf("Not palindrome");

	return 0;
}

#include<stdio.h>
int main()
{
    int i,length=0;
    char s[200];
    printf("Enter a String\n");
    gets(s);
    for(i=0;s[i]!='\0';i++)
        length++;
    printf("Length of string is: %d",length);
    return 0;
}

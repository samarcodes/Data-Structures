#include<stdio.h>
#include<string.h>

void swap(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}

void reverse_string(char str[])
{
    int i,j,len;
    len=strlen(str);
    i=0;
    j=len-1;
    while(i<j)
    {
        swap(&str[i],&str[j]);
        i++;
        j--;
    }
}

int main()
{
    char str[20];

    printf("Enter string : ");
    gets(str);

    reverse_string(str);

    printf("%s",str);

    return 0;
}

#include<stdio.h>

void string_duplicates(char str[])
{
    int Hash[26]={0};
    int i;

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=97 && str[i]<=122)
            Hash[str[i]-97]++;
        else if(str[i]>=65 && str[i]<=90)
            Hash[str[i]-65]++;
    }

    for(i=0;i<26;i++)
    {
        if(Hash[i]>1)
            printf("%c is repeated %d times\n",i+97,Hash[i]);
    }
}

void bitwise_string_duplicates(char str[])
{
    int H=0;
    int x;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        x=1;
        x=x<<str[i]-97;

        if(x&H>0)
            printf("%c is duplicate\n",str[i]);
        else
            H=x|H;
    }
}

int main()
{

    char str[20];

    scanf("%s",str);

    bitwise_string_duplicates(str);

	return 0;
}


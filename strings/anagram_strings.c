#include<stdio.h>

int check_anagram(char a[],char b[])
{
    int i;
    int Hash[26]={0};

    for(i=0;a[i]!='\0';i++)
    {
        Hash[a[i]-97]++;
    }

    for(i=0;b[i]!='\0';i++)
    {
        Hash[b[i]-97]--;
        if(Hash[b[i]-97]<0)
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    char a[]="triangle";
    char b[]="integral";

    int k=check_anagram(a,b);

    if(k==0)
        printf("Anagram");
    else
        printf("Not Anagram");

	return 0;
}


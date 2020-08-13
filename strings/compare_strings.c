#include<stdio.h>
#include<string.h>

int compare_string(char s1[],char s2[])
{
    int i;

    for(i=0; s1[i]!='\0' && s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
            break;
    }

    if(s1[i]==s2[i])
        return 0;
    else
        return -1;
}

int main()
{
    int k;
    char str1[20];
    char str2[20];
    gets(str1);
    gets(str2);

    k=compare_string(str1,str2);

    if(k==0)
        printf("Equal");
    else
        printf("Not Equal");
    return 0;
}

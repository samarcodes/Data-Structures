#include<stdio.h>
#include<string.h>

void toLower(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]+=32;
        i++;
    }
}

void toUpper(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>=97 && s[i]<=122)
            s[i]-=32;
        i++;
    }
}

int main()
{
    char str[20];
    int op;

    printf("Enter string : ");
    scanf("%s",str);

    printf("\nSelect Option");
    printf("\n1.To Lower Case");
    printf("\n2.To Upper Case");

    printf("\n\nYour Option : ");
    scanf("%d",&op);

    if(op==1)
    {
        toLower(str);
        printf("\nOutput = %s",str);
    }
    else
    {
        toUpper(str);
        printf("\nOutput = %s",str);
    }

    return 0;
}

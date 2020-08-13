#include<stdio.h>

int validate_string(char str[])
{
    int i;
    int flag=1;
    for(i=0;str[i]!='\0';i++)
    {
        if(!(str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122))
        {
            flag=0;
        }
    }
    return flag;
}

int main()
{

    char str[20];
    printf("Enter string : ");
    scanf("%s",str);

    if(validate_string(str))
        printf("Valid String!!!");
    else
        printf("Invalid String...");
}

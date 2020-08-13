#include<stdio.h>

//backtracking (backtracking uses recursion)
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void perm(char s[],int k)
{
    static int a[10]={0};
    static char res[10]={0};
    int i;
    if(s[k]=='\0')
    {
        res[k]='\0';
        printf("%s ",res);
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(a[i]==0)
            {
                res[k]=s[i];
                a[i]=1;
                perm(s,k+1);
                a[i]=0;
            }
        }
    }
}

//it contains error
void perm1(char s[],int l,int h)
{
    int i;
    if(l==h)
    {
        printf("%s ",s);
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(&s[l],&s[i]);
            perm1(s,l+1,h);
            swap(&s[l],&s[i]);
        }
    }
}

int main()
{
    char str[]="ABC";
    perm(str,0);
	return 0;
}


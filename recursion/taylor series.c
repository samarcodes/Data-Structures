//taylor series using recursion
//1+x/1!+x*x/2!+x*x*x/3!+x*x*x*x/4!+........+nterms
//26-01-2020
double taylor_series(int,int);
double Htaylor_series(int,int);//horner's rule
double Itaylor_series(int,int);//iterative taylor series
int main()
{
    int x,n;
    printf("enter value of x : ");
    scanf("%d",&x);
    printf("enter value of n : ");
    scanf("%d",&n);
    printf("%lf",Itaylor_series(x,n));
    return 0;
}

double taylor_series(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    r=taylor_series(x,n-1);
    p*=x;
    f*=n;
    return r+p/f;
}

double Htaylor_series(int x,int n)
{
    static double s;
    if(n==0)
        return s;
    s=1+(x*s)/n;
    return Htaylor_series(x,n-1);
}
double Itaylor_series(int x,int n)
{
    double num=1,den=1;
    double s=1;
    int i;
    for(i=1;i<=n;i++)
    {
        num*=x;
        den*=i;
        s=s+num/den;
    }
    return s;
}

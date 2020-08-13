#include<bits/stdc++.h>
using namespace std;

bool isBalanced(char exp[])
{
    stack <char> st;
    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            st.push(exp[i]);

        else if(exp[i]==')')
        {
            if(st.empty())
            {
                return false;
            }
            else
                st.pop();
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int main()
{
    char exp[]="(a+b)*(c+d)";

    isBalanced(exp) ? cout<<"Balanced"<<endl : cout<<"Not Balanced"<<endl;

    return 0;
}

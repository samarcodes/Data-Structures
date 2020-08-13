#include<iostream>
#include<string.h>

using namespace std;

void removeDuplicates(char s[])
{
	int l=strlen(s);

	if(l==1 || l==0)
		return;

	int prev=0;
	for(int current=1;current<l;current++)
	{
		if(s[current]!=s[prev])
		{
			prev++;
			s[prev]=s[current];
		}
	}
	s[prev+1]='\0';
}

int main()
{
	char s[]="ccooodinng";

	removeDuplicates(s);
	
	cout<<s<<endl;

	return 0;
}
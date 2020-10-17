#include<iostream>
using namespace std;
int fibbo(int n)
{
	if(n==1||n==0)
	{
		return n;
	}
	else{
		return (fibbo(n-1)+fibbo(n-2));
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<fibbo(n);
	return 0;
}

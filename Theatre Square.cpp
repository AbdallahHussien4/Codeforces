#include<iostream>
using namespace std;
int main()
{
	int n,m,a;
	cin>>n>>m>>a;
	long long x=n/a,y=m/a;
	if(n%a!=0)
		x++;
	if(m%a!=0)
		y++;
	cout<<x*y;
}
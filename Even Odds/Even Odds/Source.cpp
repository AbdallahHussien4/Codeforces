#include<iostream>
#include<vector>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	if (k <= n / 2 && n%2==0)
	{
		cout << k * 2 - 1;
	}
	else if ((k <= (n + 1) / 2) && (n % 2 == 1))
	{
		cout<<k*2-1;
	}
	else if (k > n / 2 && n % 2 == 0)
	{
		long long c = n / 2;
		cout << 2*k-2*c;
	}
	else if (k > (n+1)/2 && n % 2 == 1)
	{
		long long c = (n+1) / 2;
		
		cout << 2*k-2*c;
	}

}
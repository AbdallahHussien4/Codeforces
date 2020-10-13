#include <iostream>
using namespace std;
int main()
{
	int n;
	int count=0;
	int sum;
	cin>>n;
	int arr[3];
	for (int i=0;i<n;i++)
	{
		sum=0;
		for(int j=0;j<3;j++)
			{
				cin>>arr[j];
				sum+=arr[j];
			}
		if(sum>=2)
			count++;
	}
	cout<<count;
}
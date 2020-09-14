#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int arr[5][5];
	int R,C,n;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>arr[i][j];

	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(arr[i][j])
			{
				R=i+1;
				C=j+1;
				break;
			}
			n=abs(3-R)+abs(3-C);
			cout<<n;
}
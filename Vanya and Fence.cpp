#include <iostream>
using namespace std;
int main(){
	int n,h;
	int count=0;
	cout<<"Enter The Num. Of Friends :";
	cin>>n;
	cout<<endl<<"Enter The Height of the Fence :";
	cin>>h;
	cout<<endl<<"Enter the Height Of The friends";
	int *arr=new int[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n;i++)
	    if(arr[i]>h)
			count=count+2;
		else 
			count++;
	cout<<endl<<count<<endl;
}
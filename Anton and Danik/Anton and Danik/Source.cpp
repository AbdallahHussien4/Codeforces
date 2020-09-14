#include<iostream>
using namespace std ;

void Max(int x,int y)
{
	if (x>y)
		cout<<endl<<"Anton"<<endl;
	else if(x<y)
		cout<<endl<<"Danik"<<endl;
	else cout<<endl<<"friendship"<<endl;
}
int main()
{
	int n;
	int Anton=0;
	int Danik=0;
	//cout<<"Enter the number of games :";
	cin>>n;
	//cout<<endl<<"Enter 'A' If Anton won , 'D' if Danik won :";
	char*arr=new char[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		if(arr[i]=='A')
			Anton++;
		else 
			Danik++;
	Max(Anton,Danik);
}
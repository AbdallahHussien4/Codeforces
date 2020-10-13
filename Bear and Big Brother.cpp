#include <iostream>
using namespace std;
int main(){
	int k,l;
	int i=0;
	cin>>k>>l;
	while(k<=l)
	{
		k=k*3;
		l=l*2;
		i++;
	}
	cout<<endl<<i;
}
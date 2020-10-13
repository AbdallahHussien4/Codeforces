#include<iostream>
using namespace std;;

int main()
{
	char x [6][6];
	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
			cin>>x[i][j];
	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
			if((x[i][j]==x[i+1][j]&&x[i][j]==x[i][j+1]&&x[i][j]==x[i+1][j+1])||(x[i][j]==x[i-1][j]&&x[i][j]==x[i][j-1]&&x[i][j]==x[i-1][j-1])||(x[i][j]==x[i][j+1]&&x[i][j]==x[i-1][j]&&x[i][j]==x[i-1][j+1])||(x[i][j]==x[i][j-1]&&x[i][j]==x[i+1][j]&&x[i][j]==x[i+1][j-1]))
			{
				cout<<"YES";
				return 0;
			}

	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
			if(x[i][j]=='#')
			{
				if(j==1)
				{
					x[i][j-1]=-1;
					x[i-1][j-1]=-1;
					x[i+1][j-1]=-1;
				}
				if(j==4)
				{
					x[i][j+1]=-1;
					x[i-1][j+1]=-1;
					x[i+1][j+1]=-1;
				}
				if(i==1)
				{
					x[i-1][j]=-1;
					x[i-1][j-1]=-1;
					x[i-1][j+1]=-1;
				}
				if(i==4)
				{
					x[i+1][j]=-1;
					x[i+1][j-1]=-1;
					x[i+1][j+1]=-1;
				}
				x[i][j]='.';
				if((x[i][j]==x[i+1][j]&&x[i][j]==x[i][j+1]&&x[i][j]==x[i+1][j+1])||(x[i][j]==x[i-1][j]&&x[i][j]==x[i][j-1]&&x[i][j]==x[i-1][j-1])||(x[i][j]==x[i][j+1]&&x[i][j]==x[i-1][j]&&x[i][j]==x[i-1][j+1])||(x[i][j]==x[i][j-1]&&x[i][j]==x[i+1][j]&&x[i][j]==x[i+1][j-1]))
				{
					cout<<"YES";
					return 0;
				}
				 x[i][j]='#';
			}
			else 
			{
				if(j==1)
				{
					x[i][j-1]=-1;
					x[i-1][j-1]=-1;
					x[i+1][j-1]=-1;
				}
				if(j==4)
				{
					x[i][j+1]=-1;
					x[i-1][j+1]=-1;
					x[i+1][j+1]=-1;
				}
				if(i==1)
				{
					x[i-1][j]=-1;
					x[i-1][j-1]=-1;
					x[i-1][j+1]=-1;
				}
				if(i==4)
				{
					x[i+1][j]=-1;
					x[i+1][j-1]=-1;
					x[i+1][j+1]=-1;
				}
				x[i][j]='#';
				if((x[i][j]==x[i+1][j]&&x[i][j]==x[i][j+1]&&x[i][j]==x[i+1][j+1])||(x[i][j]==x[i-1][j]&&x[i][j]==x[i][j-1]&&x[i][j]==x[i-1][j-1])||(x[i][j]==x[i][j+1]&&x[i][j]==x[i-1][j]&&x[i][j]==x[i-1][j+1])||(x[i][j]==x[i][j-1]&&x[i][j]==x[i+1][j]&&x[i][j]==x[i+1][j-1]))
				{
					cout<<"YES";
					return 0;
				}
				x[i][j]='.';
			}
			cout<<"NO";
}
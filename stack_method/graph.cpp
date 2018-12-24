#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
static string expression;
static ld scale;

#include "stack.h"

int f(int x1)
{
	ld x = x1/scale,ans;
	ans = evaluate(x);
	return (ans*scale);
}


int main(int argc,char *argv[])
{
	if(argc != 2){
		cerr<<"Right way to execute command is: ./graph \"x*x\"\n";
		return 0;
	}

	int img[1024][1024]={};
	int i,j,x,y,k=0;
	for(i=0;i<1024;i++)
	{
		for(j=0;j<1024;j++)
			{
				x=j-512;y=512-i;
				if(x==0 || y==0)
				{
					img[i][j]=0;
					img[i+1][j]=0;
					img[i-1][j]=0;
					img[i][j-1]=0;
					img[i][j+1]=0;
				}
				else if(y%100 == 0 || x%100 == 0)
				img[i][j]=200;
				else img[i][j]=255;
			}
	}

	char *infix ;
	infix = (char *) malloc(strlen(argv[1])) ;
	for(i=0;i<strlen(argv[1]);i++)
	{
		if(argv[1][i] != ' ')
		infix[k++]=argv[1][i];
	}
	
	fstream fout("graph.pgm");
	fout<<"P2\n# "<<infix<<"\n1024 1024\n255\n";

	expression = infixtopostfix(infix);
	cout<<"Scale of co-ordinates:";
	cin>>scale;
	cout<<"1 unit of each axis = "<<100.00/scale;

	int flag=0,previ;
	for(x=-512;x<512;x++)
	{
		y=f(x);
		i=512-y;j=x+512;
		if(!(i >=0 && i<1024))
			continue;
		if(flag==0)
		{
			previ=i;
			flag=1;
		}
		int start=min(previ,i),end=max(previ,i);
		for(;start<=end;start++)
			img[start][j]=0;
		previ=i;
	}
	for(i=0;i<1024;i++)
	{
		for(j=0;j<1024;j++)
			fout<<img[i][j]<<" ";
		fout<<"\n";
	}
	return 0;
}
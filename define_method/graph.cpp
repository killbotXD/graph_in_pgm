#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

typedef long double ld;

ld scale;

#include "fun.h"

int f(int x0)
{
	ld x = x0/scale,ans;
	ans = fun(x);
	return (ans*scale);
}


int main()
{

	fstream fout("graph.pgm");
	fout<<"P2\n# graph.pgm\n1024 1024\n255\n";
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

	cout<<"Provide the required length of 1 unit of axes\nZoom_Scale:";
	cin>>scale;
	scale = 100.00/scale;
	cout<<"Graph is loading...";

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
	cout<<"\nGraph Completed -> graph.pgm\n";
	return 0;
}
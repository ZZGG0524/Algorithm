#include <iostream>
#include <bits/stdc++.h>

#define max 1000

using namespace std;

int n,c,v [max],w [max];
int x[max],m[max][max];

void k(){
	int  jmax=min(w [n]-1,c);
	for(int j=0;j<=jmax;j++)
	m[n][j]=0;
	for (int j=w[n];j<=c;j++)
	m[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		jmax=min(w[i]-1,c);
		for(int j=0;j<=jmax;j++)

			m[i][j]=m[i+1][j];
			for(int j=w[i];j<=c;j++)
			m[i][j]=m[i+1][j]>m[i+1][j-w[i]]+v[i]?m[i+1][j]:m[i+1][j-w[i]]+v[i];

	}
	m[1][c]=m[2][c];
	if(c>=w[1])
	m[1][c]= m[1][c]>m[2][c-w[1]]+v[1]?m[1][c]: m[2][c-w[1]]+v[1];
}
void t(){
	int cc=c;
	for(int i=1;i<n;i++)
	if(m[i][cc]==m[i+1][cc])
	x[i]=0;
	else
	{
		x[i]=1;
		cc-=w [i];
	}
	x[n]=(m[n][cc])?1:0;
}
int main(){
	cout<<"请输入容量，物品数"<<endl;
	cin>>c>>n;
	cout<<"请输入物品价值，重量"<<endl;
	for (int i=1;i<=n;++i)
	cin>>v[i]>>w[i];
	k();
	t();
	cout<<"价值最高： "<<m[1][c]<<endl;
	cout<<"物品是 :"<<endl;
	for(int i=1;i<=n;++i)
		if(x[i]==1)
			cout<<"第"<<i<<"个物品";
		cout<<endl;
	return 0;
}

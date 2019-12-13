#include<iostream>
using namespace std;
int *a=NULL;
int  max(int n,int *a){
	int sum=0,b=0;
	for (int i=0;i<=n;i++){
		if(b>0)
		b+=a[i];
		else
		b=a[i];
		if (b>sum)
		sum=b;
	}
	return sum;
}
main(){ 
 	int n,m;
 	cout<<"请输入字段的长度：";
 	cin>>n;
 	int a[n];
 
 	cout<<"输入数据："<<endl;
 	for (int i=0;i<n;i++){
	 	cin>>a[i]; 
 	}	
 	m=max(n,a);
	cout<<m<<endl;
}


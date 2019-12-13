#include<iostream>
//#include<fstream>
using namespace std;

//void swap(int &a,int &b){
//		temp=a;
//		list[k]=list[i];
//		list[i]=temp;
//} 
void p(int list[],int k,int m)
{
	//int temp;
	if(k==m)
	{
		for(int i=0;i<=m;i++)
		cout<<list[i]<<" ";
		cout<<endl;
	}
	else 
	{
		for( int i=k;i<=m;i++){
		
		int temp=list[k];
		list[k]=list[i];
		list[i]=temp;
		p(list,k+1,m);
		temp=list[k];
		list[k]=list[i];
		list[i]=temp;
}
	}
}
main()
{
	int k,m;
	cout<<"请输入排列的个数：";
	cin>>k;
	cout<<"请输入取几位排列的个数："; 
	cin>>m;
	if(m>=k){
		cout<<"输入错误"<<endl;
		return 0; 
	} 
	int list[k];
	cout<<"请输入数据："<<endl;
	for (int j=0;j<k;j++)
	{
		cin>>list[j];
		
	}
	p(list,0,m);
	return 0;
	
}

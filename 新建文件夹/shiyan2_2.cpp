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
	cout<<"���������еĸ�����";
	cin>>k;
	cout<<"������ȡ��λ���еĸ�����"; 
	cin>>m;
	if(m>=k){
		cout<<"�������"<<endl;
		return 0; 
	} 
	int list[k];
	cout<<"���������ݣ�"<<endl;
	for (int j=0;j<k;j++)
	{
		cin>>list[j];
		
	}
	p(list,0,m);
	return 0;
	
}

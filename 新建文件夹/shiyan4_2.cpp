#include <iostream> 
#include <algorithm>//sort()�����ĵ��ã�sort��n,n+i���ӵ�0����ʼ��i����С�������� 
using namespace std;
void load (int x[],int w[],int c,int n){//w��������x�Ǳ�ţ�c�Ǳ���������n�Ǹ���
	  
	int count=0;
	sort(x+1,x+n+1);
	sort(w+1 ,w+n+1);
	
	for( int i=1;i<=n;i++){
		cout<<"�������,������"<<x[i]<<' '<<w[i]<<endl;}
	for( int i=1;i<=n&&w[i]<=c;i++){
		 
		c-=w[i];
 	count++;
 	cout<<"װ�������Ϊ��"<<w[i]<<endl; 
	}
cout<<"װ�ؼ�����"<<count<<endl;
}
int main(){
	int s;
	int c;
	cout<<"�����뱳��������"<<endl;
	cin>>c;
	cout<<"�����뼯װ�������"<<endl;
	cin>>s;
	int *x=new int [s];
	int *t=new int [s];
	//int n;
	cout<<"�����뼯װ���ţ����� "<<endl;
	for(int i=1;i<=s;i++){
		cin>>t[i];
		cin>>x[i];
	}
	load( t, x,c,s);
	return 0;
}


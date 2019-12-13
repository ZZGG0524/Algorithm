#include <iostream> 
#include <algorithm>//sort()函数的调用，sort（n,n+i）从第0个开始到i个从小到大排序 
using namespace std;
void load (int x[],int w[],int c,int n){//w是重量，x是编号，c是背包容量，n是个数
	  
	int count=0;
	sort(x+1,x+n+1);
	sort(w+1 ,w+n+1);
	
	for( int i=1;i<=n;i++){
		cout<<"排序后编号,重量："<<x[i]<<' '<<w[i]<<endl;}
	for( int i=1;i<=n&&w[i]<=c;i++){
		 
		c-=w[i];
 	count++;
 	cout<<"装入的重量为："<<w[i]<<endl; 
	}
cout<<"装载件数："<<count<<endl;
}
int main(){
	int s;
	int c;
	cout<<"请输入背包的容量"<<endl;
	cin>>c;
	cout<<"请输入集装箱的数量"<<endl;
	cin>>s;
	int *x=new int [s];
	int *t=new int [s];
	//int n;
	cout<<"请输入集装箱编号，重量 "<<endl;
	for(int i=1;i<=s;i++){
		cin>>t[i];
		cin>>x[i];
	}
	load( t, x,c,s);
	return 0;
}


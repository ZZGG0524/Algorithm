#include<iostream>
#include<fstream>
using namespace std;
int paixu(int m,int n)
 {
 	int sum=1,sum1=1;
    for(int i=1; i<=n; i++)
    	sum*=i;
	for(int i=m; i>m-n; i--)
		sum1*=i;
	return sum1/sum;
 }
 
 
int main(){
	int n,i,j,len,a[10],sum=0,z;
	string m;
	cout<<"ÇëÊäÈë¸öÊı£º"<<endl;
	ifstream file("input2.txt");
	ofstream ofs("output2.txt");
	cin >>n;
	while (n--){
	//	cin>>m;
		file>>m;
		cout<<m;
		sum=0;
		len=m.length();
		for (i=1;i<len;i++){
			sum+=paixu(26,i);
		}
		for (i=0;i<len;i++){
			a[i]=m[i]-96;
		}
		int temp=1;
		for (i=len;i>0;i--){
			for(j=temp;j<a[len-i];j++){
				sum+=paixu(26-j,i-1);
			}
			temp=a[len-i]+1;
		}
      	ofs<<sum+1<<" ";

		cout<<sum+1<<endl;
		
	}
	file.close();
	ofs.close();
	return 0;
 } 

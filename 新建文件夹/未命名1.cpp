#include<iostream>
#include<cmath>

#include<fstream>
using namespace std;
int  main(){
	int a[10]={0};
	int n;
	ifstream file("input1.txt");
	file>>n;
	file.close();
	for (int i=1;i<=n;i++){
		int m=i;
		while (m){
			a[m%10]++;
			m/=10;
		}
	}
	ofstream ofs("output1.txt");
	for (int i=0;i<=9;i++){
	 	ofs<<a[i]<<endl;
	 }
	ofs.close();
	return 0;
} 

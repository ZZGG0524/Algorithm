#include <iostream>

using namespace std;

long long int f(int n){
	long long int f0 = 0;
	long long int f1 = 1;
	if(n<=1){
		return f0;
	}
	if(n == 2){
		return f1;
	}
	for(int i = 3;i<=n;++i){
		int t = f0+f1;
		f0 = f1;
		f1 = t;
	}
	return f1;
}

int main(){
	cout<<"请输入你要求解的fibonacci的第几项："<<endl;
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}

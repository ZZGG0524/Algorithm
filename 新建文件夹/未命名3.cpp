#include <stdio.h>

int f(int n){
	int f0 = 0;
	int f1 = 1;
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
	printf("��������Ҫ����fibonacci�ĵڼ��");
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}


#include <stdio.h>

int q(int x,int y){
	if((x<1)||(y<1)){
		return 0;
	}else if((x==1)||(y==1)){
		return 1;
	}else if(x<y){
		return q(x,x);
	}else if(x==y){
		return q(x,y-1)+1;
	}
	return q(x,y-1)+q(x-y,y);
}

int main(){
	int n = 0;
	printf("������һ����\n"); 
	scanf("%d",&n);
	int m  =  q(n,n);
	printf("����%d��",m); 
	return 0;
}


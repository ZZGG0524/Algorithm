#include <iostream>

using namespace std;

void GreedySelector(int n, int B[], int E[], bool A[]);
void time(int n,int B[], int E[]);

int main(){
  	int n;
  	cout<<"�������������:";
	cin>>n;
   	int B[n],E[n];
   	bool A[n];
   	cout<<"���������л��鿪ʼʱ��ͽ���ʱ�䣺 "<<endl;
   	for(int i=1;i<=n;i++){
      	cin>>B[i];
      	cin>>E[i];
   	}
   	for(int i=1;i<=n;i++){
    	A[i] = false;
    }
  	time(n,B,E);
   	GreedySelector(n,B,E,A);
    return 0;
}
void time(int n, int B[],int E[]){
	int i,j,temp1,temp2;
    for(j=1;j<n+1;j++){
     	for(i=1;i<n+1-j;i++){
	    	if(E[i]>E[i+1]){
            	temp1 = E[i];
            	E[i] = E[i+1];
            	E[i+1] = temp1;
		    	temp2 = B[i];
		   		B[i] = B[i+1];
		  		B[i+1] = temp2;
	  		}
	    }
	}
	cout<<"������ʱ�������Ļ������б�:"<<endl;
	for(i=1;i<=n;i++){
		cout<<i<<"  ";
	}
	cout<<endl;
	for(i=1;i<=n;i++){
	    cout<<B[i]<<"  ";
	}
	cout<<endl;
   	for(i=1;i<=n;i++){
        cout<<E[i]<<"  ";
	}
	cout<<endl;
}
void GreedySelector(int n, int B[], int E[], bool A[]){
	int i,j;
	A[1]=true;
	j=1;i=2;
	for(i=2;i<=n;i++){
		if(B[i]>=E[j]){
	    	A[i] = true;
        	j = i;
    	}
		else{
	    	A[i] = false;
		}
	}
	cout<<"���鼯��Ϊ{";
	for(int i=1;i<=n;i++){
        if(A[i]){
		    cout<<i<<",";
		}
	}
	cout<<"}"<<endl;
}

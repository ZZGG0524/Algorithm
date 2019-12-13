#include <iostream>

using namespace std;

void GreedySelector(int n, int B[], int E[], bool A[]);
void time(int n,int B[], int E[]);

int main(){
  	int n;
  	cout<<"请输入会议总数:";
	cin>>n;
   	int B[n],E[n];
   	bool A[n];
   	cout<<"请输入所有会议开始时间和结束时间： "<<endl;
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
	cout<<"按结束时间排序后的会议排列表:"<<endl;
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
	cout<<"会议集合为{";
	for(int i=1;i<=n;i++){
        if(A[i]){
		    cout<<i<<",";
		}
	}
	cout<<"}"<<endl;
}

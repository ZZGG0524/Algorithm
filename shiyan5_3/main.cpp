#include <iostream>
#include"stdio.h"

using namespace std;

#define MAX 30

int data[MAX] ;//����Ԫ��
int a[MAX] ;
int is=0;
int n;//�������
int c;//�Ӽ���
int first=1;

void copy(bool a1[MAX] ,bool a2[MAX]){//��a2�е�Ԫ�ظ��Ƶ�a1��
	for(int i=0;i<n;i++){
        a1[i]=a2[i];
	}
}

void dfs(int cur,int sum ,bool v[MAX])
{
	bool temp[MAX];
	if((cur==n&&sum!=c)||is){
        return;
	}
	else if(sum==c){//����Ӽ����Ѿ�����c�ˣ���������
        is=1;
		if(first){
            for(int i=0;i<cur;i++){
				if(i){
                    cout<<" ";
				}
				cout<<a[i];
            }
			cout<<endl;
			first=0;
		}
		return;
	}
    else if(sum>c) return;
    else{
		for(int i=0;i<n;i++){
			if(!v[i]){
				copy(temp,v);
				a[cur]=data[i];
				temp[i]=1;
				dfs(cur+1,sum+data[i],temp);
			}
		}
	}
}


int main(){
	bool v[MAX]={0} ;
	cout<<"�������Ӽ�������Ŀ��ֵ��"<<endl;
	cin>>n>>c;
	is=0;
	first=1;
	for(int i=0;i<n;i++){
		cout<<"������Ԫ��ֵ��";
		cin>>data[i];
		v[i]=0;
	}
	dfs(0,0,v) ;
	if(!is){
        cout<<"No solution!"<<endl;
	}
	return 0;
}

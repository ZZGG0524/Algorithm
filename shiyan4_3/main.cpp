#include <iostream>
#include <algorithm>
using namespace std;

void k(int n,float m,float *v,float *w,float *x,int *s){
	float a=0,b=0;
	for(int i=n;i>0;i--){
		if(m>=w[i]){
			m-=w[i];
			a+=v[i];
			b+=w[i];
			cout<<"װ����������ֵ"<<w[i]<<' '<<v[i]<<endl;
		 }
	}
    cout<<"��ֵװ��������"<<a<<' '<<"װ����������"<<b<<endl;
}

int main()
{
	int n;
	cout<<"��������Ʒ������"<<endl;
	cin>>n;
	float m;
	cout<<"�����뱳��������"<<endl;
	cin>>m;
	float *v =new float[n];
	float *w =new float[n];
	float *x =new float[n];
	int *s=new int [n];//״̬
	for(int i=1;i<=n;i++){
		cout<<"��������Ʒ��ֵ������"<<endl;
		cin>>v[i]>>w[i] ;
		x[i]=v[i]/w[i];
		cout<<x[i]<<endl;
	}
    float temp;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n-i+1;j++){
			if(x[j]>x[j+1]){
				temp=x[j+1];
				x[j+1]=x[j];
				x[j]=temp;
            }
        }
        s[i]=i;
    }
	for(int i=1;i<=n;i++){
		cout<<"��ţ�"<<s[i]<<' '<<"�Լ۱ȣ�"<<x[i]<<endl;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n-i+1;j++){
			if(v[j]/w[j]==x[i]){
				float tempv,tempw;
				tempv=v[i];
				v[i]=v[j];
				v[j]=tempv;
				tempw=w[i];
				w[i]=w[j];
				w[j]=tempw;
			}
		 }
	}
    for(int i=1;i<=n;i++){
        cout<<"��ֵ���������"<<v[i]<<' '<<w[i]<<endl;
	}
	k(  n,  m, v, w, x,s);
	return 0;
 }

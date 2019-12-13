#include <iostream>
#include <string.h>

#define N 100

using namespace std;

template<class Type>
inline void Swap(Type &a,Type &b){
    Type temp=a;
    a=b;
    b=temp;
}

template<class Type>
void Perm(Type list[],int k,int m){   //产生list[k:m]的所有排列
    if(k==m){
        for(int i=0;i<=m;i++){
            cout<<list[i];
        }
        cout<<endl;
    }
    else{
        for(int i=k;i<=m;i++){
            Swap(list[k],list[i]);
            Perm(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}

int main(){
    char a[N];
    cout<<"请输入待排列的元素:"<<endl;
    cin>>a;
    cout<<"全排列的输出:"<<endl;
    Perm(a,0,strlen(a)-1);
    return 0;
}

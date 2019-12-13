#include<iostream>

using namespace std;

char *a;
bool check(int i){
    for(int j = 0;j < i;j++){
        if(a[i] == a[j]){
            return false;
        }
    }
    return true;
}

void output(char *a,int n){
    for(int i = 0;i < n;i++){
        cout<<a[i] <<" ";
    }
    cout<<endl;
}

void backTrack(int i,int n,int m){
    if(i >= m){
        output(a,m);
    }
    else{
        for(int j = 0;j < n;j++){
            a[i] = 'A' + j;
            if(check(i)){
            backTrack(i + 1,n,m);
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"请输入前m个数:"<<endl;
    cin>>m;
    cout<<"请输入m个数中的n个数排序:"<<endl;
    cin>>n;
    a=new char[m];
    backTrack(0,m,n);
    return 0;
}

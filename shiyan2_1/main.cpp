#include <iostream>

using namespace std;

int q(int n,int m){
    if((n<1)||(m<1)){
        return 0;
    }
    if((n==1)||(m==1)){
        return 1;
    }
    if(n<m){
        return q(n,n);
    }
    if(n==m){
        return q(n,m-1)+1;
    }
    return q(n,m-1)+q(n-m,m);
}

int main()
{
    int m,n;
    int i,j;
    cout<<"请输入划分数:";
    cin>>n;
    cout<<"请输入最大加数:";
    cin>>m;
    cout<<"正整数 "<<n<<" 共有 "<<q(n,m)<<" 种不同的划分"<<endl;
    return 0;
}

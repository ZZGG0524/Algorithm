#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int dic(int m,int n){
    int letter=1;
    int a=1;
    int b=1;
    if(m!=0){
        for(int i=n;i>n-m;i++){
            a=a*i;
        }
        for(int j=2;j<=m;j++){
            b=b*j;
        }
        letter=a/b;
    }
    return letter;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int number;
    cin>>number;
    for(int k=0;k<number;k++){
        int i,j;
        char char1[10];
        char char2[10];
        cin>>char1;
        int sum=1;
        int start=1;
        int n=strlen(char1);
        for(i=1;i<n;i++){
            sum+=dic(i,26);
        }
        for(i=0;i<1;i++){
            char2[i]=char1[i]-96;
        }
        for(i=n;i>=1;i--){
            for(j=1;j<char2[n-i];j++){
                sum+=dic(i-1,26-j);
            }
            start=char2[n-j]+1;
        }
        cout<<sum<<endl;
    }
    return 0;
}

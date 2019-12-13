#include <iostream>
#include <cstdio>
#include <stdlib.h>

#define SIZE 512

using namespace std;

int main()
{
    int ch;
    //int len;
    char buffer[SIZE];
    int c[SIZE]={0};
    FILE *fp1;
    FILE *fp2;
    if(((fp1=fopen("input.txt","r"))==NULL)||((fp2=fopen("output.txt","w"))==NULL)){
        cout<<"文件打开失败!"<<endl;
        exit(1);
    }
    if(fgets(buffer,SIZE,fp1)!=NULL){
        //len=strlen(buffer);
        ch=atoi(buffer);
    }
    for(int i=1;i<=ch;i++){
        int tmp=i;
        while(tmp){
            c[tmp%10]++;
            tmp/=10;
        }
    }
    for(int i=0;i<10;i++){
        fprintf(fp2,"%d\n",c[i]);
    }
    cout<<"It's over!"<<endl;
    fclose(fp1);
    fclose(fp2);
    return 0;
}

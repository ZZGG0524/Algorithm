#include <iostream>
#include <math.h>

using namespace std;

int Board[100][100];
int tile=1;
int s;

void ChessBoard(int tr,int tc,int dr,int dc,int size) {
    if(size==1){
        return;
    }
    int t=tile++,       //L�͹��ƺ�
    s=size/2;           //�ָ�����

    //�������Ͻ�������
    if(dr<tr+s&&dc<tc+s){//���ⷽ���ڴ�������
        ChessBoard(tr,tc,dr,dc,s);
    }
    else{                     //�������������ⷽ��
        Board[tr+s-1][tc+s-1]=t; //��t��L�͹��Ƹ������½�
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);//�������෽��
    }
    if(dr<tr+s&&dc>=tc+s){//�������Ͻ�������
        ChessBoard(tr,tc+s,dr,dc,s);//���ⷽ���ڴ�������
    }
    else{                      //�������������ⷽ��
        Board[tr+s-1][tc+s]=t;//��t��L�͹��Ƹ������½�
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);//�������෽��
    }
    if(dr>=tr+s&&dc<tc+s){//�������½�������
        ChessBoard(tr+s,tc,dr,dc,s);//���ⷽ���ڴ�������
    }
    else{                           //��t��L�͹��Ƹ������Ͻ�
        Board[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);//�������෽��
    }
    if(dr>=tr+s&&dc>=tc+s){ //�������½�������
        ChessBoard(tr+s,tc+s,dr,dc,s);//���ⷽ���ڴ�������
    }
    else{                           //��t��L�͹��Ƹ������Ͻ�
        Board[tr+s][tc+s]=t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);//�������෽��
    }
}
int main()
{
    int dr,dc;
    int m,size;
    cout<<"������2�Ĵη���:";
    cin>>m;
    size=pow(2,m);
    cout<<"���������ⷽ���λ��:";
    cin>>dr>>dc;
    ChessBoard(0,0,dr,dc,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

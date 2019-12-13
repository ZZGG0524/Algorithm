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
    int t=tile++,       //L型骨牌号
    s=size/2;           //分割棋盘

    //覆盖左上角子棋盘
    if(dr<tr+s&&dc<tc+s){//特殊方格在此祺盘中
        ChessBoard(tr,tc,dr,dc,s);
    }
    else{                     //此棋盘中无特殊方格
        Board[tr+s-1][tc+s-1]=t; //用t号L型骨牌覆盖右下角
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);//覆盖其余方格
    }
    if(dr<tr+s&&dc>=tc+s){//覆盖右上角子棋盘
        ChessBoard(tr,tc+s,dr,dc,s);//特殊方格在此棋盘中
    }
    else{                      //此棋盘中无特殊方格
        Board[tr+s-1][tc+s]=t;//用t号L型骨牌覆盖左下角
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);//覆盖其余方格
    }
    if(dr>=tr+s&&dc<tc+s){//覆盖左下角子棋盘
        ChessBoard(tr+s,tc,dr,dc,s);//特殊方格在此棋盘中
    }
    else{                           //用t号L型骨牌覆盖右上角
        Board[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);//覆盖其余方格
    }
    if(dr>=tr+s&&dc>=tc+s){ //覆盖右下角子棋盘
        ChessBoard(tr+s,tc+s,dr,dc,s);//特殊方格在此棋盘中
    }
    else{                           //用t号L型骨牌覆盖左上角
        Board[tr+s][tc+s]=t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);//覆盖其余方格
    }
}
int main()
{
    int dr,dc;
    int m,size;
    cout<<"请输入2的次方数:";
    cin>>m;
    size=pow(2,m);
    cout<<"请输入特殊方格的位置:";
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

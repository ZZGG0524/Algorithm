#include<iostream>
#include<iomanip>
using namespace std;

int tile=0; 
int *(*board)=NULL;

void chess(int tr,int tc ,int dr,int dc,int size)
{
	if(size==1)
	return;
	int t=tile++,s=size/2;
	if(dr<tr+s&&dc<tc+s)
	chess(tr,tc,dr,dc,s);
	else
	{
		board[tr+s-1][tc+s-1]=t;
		chess(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if(dr<tr+s&&dc>=tc+s)
	chess(tr,tc+s,dr,dc,s);
	else
	{
		board[tr+s-1][tc+s]=t;
		chess(tr,tc+s,tr+s-1,tc+s,s);
		
	}
	if(dr>=tr+s&&dc<tc+s)
	chess(tr+s,tc,dr,dc,s);
	else
	{
		board[tr+s][tc+s-1]=t;
		chess(tr+s,tc,tr+s,tc+s-1,s);
	}
	if (dr >= tr + s && dc >= tc + s)  
	chess(tr + s, tc + s, dr, dc, s);
	
	else {

    board[tr + s][tc + s] = t;
    chess(tr + s, tc + s, tr + s, tc + s, s);
}
	
	
}

main()
{
int tx=0,ty=0,sp,dx,dy,size;
cout<<"请输入特殊方格行号，列号"<<endl;
cin>>dx>>dy;
cout<<"请输入需要充填的数字："<<endl;
cin>>sp;
cout<<endl;
cout<<"请输入棋盘的大小：";
cin>>size;
cout<<endl;
board=new int*[size];
for (int i=0;i<size;i++)
{
	board[i]=new int[size];
	
}
board[dx-1][dy-1]=sp;
chess(tx,ty,dx-1,dy-1,size);
for(int j=0;j<size;j++)
{
	for (int m=0;m<size;m++)
	{
		cout<<setw(6)<<board[j][m];
	}
	cout<<endl;
}
	return 0;
} 

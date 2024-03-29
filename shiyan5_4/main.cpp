#include <iostream>

using namespace std;

#define N 4                //城市数目
#define NO_PATH -1         //没有通路
#define MAX_WEIGHT 4000

int City_Graph[N+1][N+1];  //保存图信息
int x[N+1];                //x[i]保存第i步遍历的城市
int isIn[N+1];             //保存 城市i是否已经加入路径
int bestw;                 //最优路径总权值
int cw;                    //当前路径总权值
int bestx[N+1];            //最优路径
void Travel_Backtrack(int t){        //递归法
    int i,j;
    if(t>N){                         //走完了，输出结果
        for(i=1;i<=N;i++){            //输出当前的路径
            cout<<x[i];
        }
        cout<<endl;
        if(cw < bestw){              //判断当前路径是否是更优解
            for (i=1;i<=N;i++){
                bestx[i] = x[i];
            }
            bestw = cw;
        }
        return;
    }
    else{
        for(j=1;j<=N;j++){           //找到第t步能走的城市
            if(City_Graph[x[t-1]][j] != NO_PATH && !isIn[j]){ //能到而且没有加入到路径中
                isIn[j] = 1;
                x[t] = j;
                cw += City_Graph[x[t-1]][j];
                Travel_Backtrack(t+1);
                isIn[j] = 0;
                x[t] = 0;
                cw -= City_Graph[x[t-1]][j];
            }
        }
    }
}
int main(){
    int i;
    City_Graph[1][1] = NO_PATH;
    City_Graph[1][2] = 5;
    City_Graph[1][3] = 16;
    City_Graph[1][4] = 14;

    City_Graph[2][1] = 5;
    City_Graph[2][2] = NO_PATH;
    City_Graph[2][3] = 15;
    City_Graph[2][4] = 10;
    City_Graph[3][1] = 16;
    City_Graph[3][2] = 15;
    City_Graph[3][3] = NO_PATH;
    City_Graph[3][4] = 20;

    City_Graph[4][1] = 14;
    City_Graph[4][2] = 10;
    City_Graph[4][3] = 20;
    City_Graph[4][4] = NO_PATH;
    //递归法
    for (i=1;i<=N;i++){
        x[i] = 0;               //表示第i步还没有解
        bestx[i] = 0;           //还没有最优解
        isIn[i] = 0;            //表示第i个城市还没有加入到路径中
    }

    x[1] = 1;                   //第一步 走城市1
    isIn[1] = 1;                //第一个城市 加入路径
    bestw = MAX_WEIGHT;
    cw = 0;
    Travel_Backtrack(2);        //从第二步开始选择城市
    cout<<"最优值为:"<<bestw<<endl;
    cout<<"最优解为:"<<endl;
    for(i=1;i<=N;i++){
        cout<<bestx[i];
    }
    cout<<endl;
}

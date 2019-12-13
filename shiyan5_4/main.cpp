#include <iostream>

using namespace std;

#define N 4                //������Ŀ
#define NO_PATH -1         //û��ͨ·
#define MAX_WEIGHT 4000

int City_Graph[N+1][N+1];  //����ͼ��Ϣ
int x[N+1];                //x[i]�����i�������ĳ���
int isIn[N+1];             //���� ����i�Ƿ��Ѿ�����·��
int bestw;                 //����·����Ȩֵ
int cw;                    //��ǰ·����Ȩֵ
int bestx[N+1];            //����·��
void Travel_Backtrack(int t){        //�ݹ鷨
    int i,j;
    if(t>N){                         //�����ˣ�������
        for(i=1;i<=N;i++){            //�����ǰ��·��
            cout<<x[i];
        }
        cout<<endl;
        if(cw < bestw){              //�жϵ�ǰ·���Ƿ��Ǹ��Ž�
            for (i=1;i<=N;i++){
                bestx[i] = x[i];
            }
            bestw = cw;
        }
        return;
    }
    else{
        for(j=1;j<=N;j++){           //�ҵ���t�����ߵĳ���
            if(City_Graph[x[t-1]][j] != NO_PATH && !isIn[j]){ //�ܵ�����û�м��뵽·����
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
    //�ݹ鷨
    for (i=1;i<=N;i++){
        x[i] = 0;               //��ʾ��i����û�н�
        bestx[i] = 0;           //��û�����Ž�
        isIn[i] = 0;            //��ʾ��i�����л�û�м��뵽·����
    }

    x[1] = 1;                   //��һ�� �߳���1
    isIn[1] = 1;                //��һ������ ����·��
    bestw = MAX_WEIGHT;
    cw = 0;
    Travel_Backtrack(2);        //�ӵڶ�����ʼѡ�����
    cout<<"����ֵΪ:"<<bestw<<endl;
    cout<<"���Ž�Ϊ:"<<endl;
    for(i=1;i<=N;i++){
        cout<<bestx[i];
    }
    cout<<endl;
}

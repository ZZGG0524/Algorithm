//��֧�޽編
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>

using namespace std;

#define INF 100000

/*  n*n��һ������  */
int n;
int mp[22][22];//����3���㣬���15����
/*����������*/
void in(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                mp[i][j]=INF;
                continue;
            }
            scanf("%d",&mp[i][j]);
        }
    }
}
struct node{
    int visp[22];//�����Щ������
    int st;//���
    int st_p;//�����ڽӵ�
    int ed;//�յ�
    int ed_p;//�յ���ڽӵ�
    int k;//�߹��ĵ���
    int sumv;//����·���ľ���
    int lb;//Ŀ�꺯����ֵ
    bool operator <(const node &p )const{
        return lb>p.lb;
    }
};
priority_queue<node> q;
int low,up;
int inq[22];
//ȷ���Ͻ�
int dfs(int u,int k,int l)
{
    if(k==n) return l+mp[u][1];
    int minlen=INF , p;
    for(int i=1; i<=n; i++)
    {
        if(inq[i]==0&&minlen>mp[u][i])/*ȡ�����е����������С�ı�*/
        {
            minlen=mp[u][i];
            p=i;
        }
    }
    inq[p]=1;
    return dfs(p,k+1,l+minlen);
}
int get_lb(node p)
{
    int ret=p.sumv*2;//·���ϵĵ�ľ���
    int min1=INF,min2=INF;//�����յ��������ı�
    for(int i=1; i<=n; i++)
    {
        if(p.visp[i]==0&&min1>mp[i][p.st])
        {
            min1=mp[i][p.st];
        }
    }
    ret+=min1;
    for(int i=1; i<=n; i++)
    {
        if(p.visp[i]==0&&min2>mp[p.ed][i])
        {
            min2=mp[p.ed][i];
        }
    }
    ret+=min2;
    for(int i=1; i<=n; i++)
    {
        if(p.visp[i]==0)
        {
            min1=min2=INF;
            for(int j=1; j<=n; j++)
            {
                if(min1>mp[i][j])
                min1=mp[i][j];
            }
            for(int j=1; j<=n; j++)
            {
                if(min2>mp[j][i])
                min2=mp[j][i];
            }
            ret+=min1+min2;
        }
    }
    return ret%2==0?(ret/2):(ret/2+1);
}
void get_up()
{
    inq[1]=1;
    up=dfs(1,1,0);
}
void get_low()
{
    low=0;
    for(int i=1; i<=n; i++)
    {
        /*ͨ��������������Сֵ*/
        int min1=INF,min2=INF;
        int tmpA[22];
        for(int j=1; j<=n; j++)
        {
            tmpA[j]=mp[i][j];
        }
        sort(tmpA+1,tmpA+1+n);//����ʱ�������������
        low+=tmpA[1];
    }
}
int solve()
{
    /*̰�ķ�ȷ���Ͻ�*/
    get_up();

    /*ȡÿ����С�ı�֮����Ϊ�½�*/
    get_low();

    /*���ó�ʼ��,Ĭ�ϴ�1��ʼ */
    node star;
    star.st=1;
    star.ed=1;
    star.k=1;
    for(int i=1; i<=n; i++) star.visp[i]=0;
    star.visp[1]=1;
    star.sumv=0;
    star.lb=low;

    /*retΪ����Ľ�*/
    int ret=INF;

    q.push(star);
    while(!q.empty())
    {
        node tmp=q.top();
        q.pop();
        if(tmp.k==n-1)
        {
            /*�����һ��û���ߵĵ�*/
            int p;
            for(int i=1; i<=n; i++)
            {
                if(tmp.visp[i]==0)
                {
                    p=i;
                    break;
                }
            }
            int ans=tmp.sumv+mp[p][tmp.st]+mp[tmp.ed][p];
            node judge = q.top();

            /*�����ǰ��·���ͱ����е�Ŀ�꺯��ֵ��С������*/
            if(ans <= judge.lb)
            {
                ret=min(ans,ret);
                break;
            }
            /*����������������ܵ�·���ͣ��������Ͻ�*/
            else
            {
                up = min(up,ans);
                ret=min(ret,ans);
                continue;
            }
        }
        /*��ǰ�����������չ�ĵ������ȼ�����*/
        node next;
        for(int i=1; i<=n; i++)
        {
            if(tmp.visp[i]==0)
            {
                next.st=tmp.st;

                /*����·����*/
                next.sumv=tmp.sumv+mp[tmp.ed][i];

                /*�������һ����*/
                next.ed=i;

                /*���¶�����*/
                next.k=tmp.k+1;

                /*���¾����Ķ���*/
                for(int j=1; j<=n; j++) next.visp[j]=tmp.visp[j];
                next.visp[i]=1;

                /*��Ŀ�꺯��*/
                next.lb=get_lb(next);

                /*��������Ͻ�Ͳ��������*/
                if(next.lb>up) continue;
                q.push(next);
            }
        }
    }
    return ret;
}
int main()
{
    in();
    printf("%d\n",solve());
    return 0;
}

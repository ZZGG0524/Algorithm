#include<stdio.h>
#include<string.h>
int c[200][200];   
int b[200][200];   
char f[200];

int Max(int m,int n,int i,int j)
{
if(m > n)
{
b[i][j] = -1;
return m;
}
else
{
b[i][j] = 1;
return n;
}
}
void print(int i,int j,int s,char x[],char y[])
{
if(b[i][j] == 0)
{
f[s-1] = x[i-1];
i--;j--;s--;
print(i,j,s,x,y);
}
else if(b[i][j] == -1)
{
i--;
print(i,j,s,x,y);
}
else if(b[i][j] == 1)
{
j--;
print(i,j,s,x,y);
}
}
int LCS(char x[],char y[])
{
int i,j;
int x_len,y_len;
x_len = strlen(x);
y_len = strlen(y);
printf("   ");
for(i = 0;i < y_len;i++)
{
printf("%c  ",y[i]);
}
printf("\n");
for(i = 1;i <= x_len;i++)
{
printf("%c  ",x[i-1]);
for(j = 1;j <= y_len;j++)
{
if(x[i-1] == y[j-1])
{
c[i][j] = c[i-1][j-1] +1;
b[i][j] = 0;
printf("%d  ",c[i][j]);
}
else
{
c[i][j] = Max(c[i-1][j],c[i][j-1],i,j);
printf("%d  ",c[i][j]);
}
}
printf("\n");
}
printf("两个字符串的LCS是:");
print(x_len,y_len,c[x_len][y_len],x,y);
printf("%s",f);
printf("\n");
return c[x_len][y_len];
}

int  main()
{
char X[200],Y[200];
int i,j,s;
printf("请输入字符串:");
scanf("%s",X);
while(strlen(X) > 200)
{
printf("输入错误,请重新输入!");
scanf("%s",X);
}
printf("请输入字符串:");
scanf("%s",Y);
while(strlen(Y) > 200)
{
printf("输入错误,请重新输入!");
scanf("%s",Y);
}
s = LCS(X,Y);
printf("两个字符串的LCS的长度: %d \n",s);
return 0;
}

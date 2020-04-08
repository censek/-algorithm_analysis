#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

#define maxlength 110

int i,j;
int nx,ny;
char *x=new char[maxlength],*y=new char[maxlength];

class LCS
{
public:
    LCS(int nx,int ny) //对数据成员进行初始化
    {
        m=nx;
        n=ny; //对m和 n赋值
        a=new char[m+2]; //考虑下标为0的元素和字符串结束标记
        b=new char[n+2];
        strcpy(a,x);
        strcpy(b,y);
    }
    int LCSLength();
    void CLCS()    //构造最优解（最长公共子序列）
    {
        CLCS(m,n); //调用私有成员函数CLCS(int,int)
    }
private:
    void CLCS(int i,int j);
    int c[maxlength+1][maxlength+1],s[maxlength][maxlength]; //前者用来存最长子序列长度，后者用来存最长子序列
    int m,n;
    char *a,*b;
};

int LCS::LCSLength()
{
    //清零
    for(i=0 ; i<=m ; i++ )
        for( j=0 ; j<=n ; j++ )
        {
            c[i][j]=0;
            s[i][j]=0;
        }
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                s[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                s[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                s[i][j] = 3;
            }
        }
    }
    return c[m][n]; //返回最优解值
}

void LCS::CLCS(int i,int j)
{
    // cout<<"test:"<<"CLCS()"<<endl;
    if(i==0||j==0)
        return;
    if(s[i][j]==1)
    {
        CLCS(i-1,j-1);
        cout<<a[i-1];
    }
    else if(s[i][j] == 2)
        CLCS(i-1,j);
    else
        CLCS(i,j-1);
}

int main()
{
    printf("请输入两个字符串：(以空格或者回车间隔)：\n");
    cin>>x;
    cin>>y;
    nx=strlen(x); //字符串x长度
    ny=strlen(y); //字符串y长度
    // cout<<"test:"<<x<<" "<<nx<<endl;  //调试：用来测试输入情况
    // cout<<"test:"<<y<<" "<<ny<<endl;
    LCS lcs(nx,ny);
    int length=lcs.LCSLength();
    printf("最长公共子序列长度：%d\n",length);
    printf("最长公共子序列：");
    lcs.CLCS();
    printf("\n");
    delete []x;
    delete []y;
    return 0;
}

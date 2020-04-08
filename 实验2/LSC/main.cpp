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
    LCS(int nx,int ny) //�����ݳ�Ա���г�ʼ��
    {
        m=nx;
        n=ny; //��m�� n��ֵ
        a=new char[m+2]; //�����±�Ϊ0��Ԫ�غ��ַ����������
        b=new char[n+2];
        strcpy(a,x);
        strcpy(b,y);
    }
    int LCSLength();
    void CLCS()    //�������Ž⣨����������У�
    {
        CLCS(m,n); //����˽�г�Ա����CLCS(int,int)
    }
private:
    void CLCS(int i,int j);
    int c[maxlength+1][maxlength+1],s[maxlength][maxlength]; //ǰ��������������г��ȣ������������������
    int m,n;
    char *a,*b;
};

int LCS::LCSLength()
{
    //����
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
    return c[m][n]; //�������Ž�ֵ
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
    printf("�����������ַ�����(�Կո���߻س����)��\n");
    cin>>x;
    cin>>y;
    nx=strlen(x); //�ַ���x����
    ny=strlen(y); //�ַ���y����
    // cout<<"test:"<<x<<" "<<nx<<endl;  //���ԣ����������������
    // cout<<"test:"<<y<<" "<<ny<<endl;
    LCS lcs(nx,ny);
    int length=lcs.LCSLength();
    printf("����������г��ȣ�%d\n",length);
    printf("����������У�");
    lcs.CLCS();
    printf("\n");
    delete []x;
    delete []y;
    return 0;
}

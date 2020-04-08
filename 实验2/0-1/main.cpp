#include<stdio.h>
#include<time.h>
#include<iostream>

using namespace std;

int V[200][200];
int max(int a,int b)
{
    if(a>=b)
        return a;
    else return b;
}

int KnapSack(int n,int w[],int v[],int x[],int W)
{
    int i,j;

    for(i=0; i<=n; i++)
        V[i][0]=0;
    for(j=0; j<=W; j++)
        V[0][j]=0;
    for(i=0; i<=n-1; i++)
        for(j=0; j<=W; j++)
            if(j<w[i])
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
    j=W;
    for(i=n-1; i>=0; i--)
    {
        if(V[i][j]>V[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        else
            x[i]=0;
    }
    cout<<endl<<"����װ�뱳������Ʒ��: ";
    for(i=0; i<n; i++)
        cout<<x[i]<<" ";
    return V[n-1][W];
}

int main()
{
    int s;
    int w[15];
    int v[15];
    int x[15];
    int n,i;
    int W;
    n=5;
    cout<<"�������������:";
    cin>>W;
    cout<<"������Ʒ����:";
    cin>>n;
    cout<<"��ֱ�������Ʒ������:";
    for(i=0; i<n; i++)
        cin>>w[i];
    cout<<"��ֱ�������Ʒ�ļ�ֵ:";
    for(i=0; i<n; i++)
        cin>>v[i];
    s=KnapSack(n,w,v,x,W);
    cout<<endl<<"װ�뱳������Ʒ������ֵ��";
    cout<<s;
}

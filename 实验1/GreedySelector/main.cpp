#include <iostream>

using namespace std;

void GREEDY_ACTIVITY_SELECTOR(int n,int s[],int f[],bool A[])
{
    A[0]=true;
    int j=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]>=f[j])
        {
            A[i]=true;
            j=i;
        }
        else
            A[i]=false;
    }
}

void paixu(int n,int s[],int f[],int num[])
{
    int j,i,m;
    for(i=0; i<n; i++)
        for(j=i; j<n-1; j++)
        {
            if(f[j]>f[j+1])
            {
                m=f[j];
                f[j]=f[j+1];
                f[j+1]=m;
                m=s[j];
                s[j]=s[j+1];
                s[j+1]=m;
                m=num[j];
                num[j]=num[j+1];
                num[j+1]=m;
            }
        }
}

int main(int argc,char* argv[])
{
    int t=0;
    int s[11]={1,3,0,5,3,5,6,8,8,2,12};
    int f[11]={4,5,6,7,8,9,10,11,12,13,14};
    int num[11]={1,2,3,4,5,6,7,8,9,10,11};
    bool re[11];
    paixu(11,s,f,num);
    GREEDY_ACTIVITY_SELECTOR(11,s,f,re);
    cout << endl << "可以安排的活动如下：" << endl;
    for(int i=0; i<11; i++)
    {
        if(re[i])
        {
            cout << num[i] << " ";
            t++;
        }
    }
    cout << "；";
    cout << endl << "最多可以安排" << t << "个活动。" << endl;
    return 0;
}

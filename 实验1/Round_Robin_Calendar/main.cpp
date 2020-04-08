#include <iostream>
#include <math.h>

using namespace std;

void Round_Robin_Calendar(int k,int **a)
{
    int n=1,i,j,s;
    for(i=1;i<=k;i++)
        n *= 2;

    for(int i=1; i<=n; i++)
        a[1][i]=i;

    int m = 1;
    for(s=1; s<=k; s++)
    {
        n /= 2;
        for(int t=1; t<=n; t++)
        {
            for(i=m+1; i<=2*m; i++)
            {
                for(int j=m+1; j<=2*m; j++)
                {
                    a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
                    a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];
                }
            }
        }
        m *= 2;
    }
}

int main()
{
    int k;
    cout<<"（注：2的k次幂为参赛人数）"<<endl;
    cout<<"请输入k的值：";
    cin>>k;

    int n=1;

    for(int i=1; i<=k; i++)
        n *= 2;


    int **a = new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        a[i] = new int[n+1];
    }


    Round_Robin_Calendar(k,a);
    cout<<"参赛人数:"<<" "<<n<<endl;
    cout<<"循环日程表为："<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<=n; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


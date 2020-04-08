#include <vector>
#include <iostream>

using namespace std;

class PackBackTrack
{

protected:
    vector<int> v; //N个背包的价值
    vector<int> w; //N个背包的重量
    int c; //背包的容量
    int num; //物品的件数
    int bestV;            //背包最大价值
    int cv;        //当前背包中物品的价值
    int cw;        //当前背包中物品的重量

private:
    void BackTrack(int depth)
    {
        if(depth >= num)    //达到最大深度
        {
            if(bestV < cv)  //保存最优解
                bestV = cv;
            return ;
        }

        if(cw +w[depth] <= c)  //是否满足约束条件
        {
            cw += w[depth];
            cv += v[depth];

            //选取了第i件物品
            BackTrack(depth+1); //递归求解下一个结点

            //恢复背包的容量和价值
            cw -= w[depth];
            cv -= v[depth];
        }
        //不取第i件物品
        BackTrack(depth+1);
    }
public:
    //构造函数
    PackBackTrack();
    PackBackTrack(vector<int>& v,vector<int>& w, int c,int n)
        :v(v),w(w),c(c),num(n)
    {
        bestV =0;
        cv =0;
        cw =0;
    }
    //获取背包内物品的最大值
    int GetBestValue()
    {
        BackTrack(0);
        return bestV;
    }
};

int main(void)
{
    //测试程序
    int n;
    int c;
    cout<<"||回溯法求解0-1背包问题||"<<endl<<endl;
    cout << "请输入物品的件数:" << endl;
    cin >>n;
    cout << "请输入背包的容量:" << endl;
    cin >>c;
    vector<int> w(n);
    vector<int> v(n);
    cout << "请输入物品的重量:" << endl;
    for(int i=0; i<n; ++i)
        cin >> w[i];
    cout << "请输入物品的价值:" << endl;
    for(int j=0; j<n; ++j)
        cin >> v[j];
    PackBackTrack pack(v,w,c,n);
    int bestV = pack.GetBestValue();
    cout << "背包内的物品的最大价值为：" << bestV << endl;
    return 0;
}

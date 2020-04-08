#include <vector>
#include <iostream>

using namespace std;

class PackBackTrack
{

protected:
    vector<int> v; //N�������ļ�ֵ
    vector<int> w; //N������������
    int c; //����������
    int num; //��Ʒ�ļ���
    int bestV;            //��������ֵ
    int cv;        //��ǰ��������Ʒ�ļ�ֵ
    int cw;        //��ǰ��������Ʒ������

private:
    void BackTrack(int depth)
    {
        if(depth >= num)    //�ﵽ������
        {
            if(bestV < cv)  //�������Ž�
                bestV = cv;
            return ;
        }

        if(cw +w[depth] <= c)  //�Ƿ�����Լ������
        {
            cw += w[depth];
            cv += v[depth];

            //ѡȡ�˵�i����Ʒ
            BackTrack(depth+1); //�ݹ������һ�����

            //�ָ������������ͼ�ֵ
            cw -= w[depth];
            cv -= v[depth];
        }
        //��ȡ��i����Ʒ
        BackTrack(depth+1);
    }
public:
    //���캯��
    PackBackTrack();
    PackBackTrack(vector<int>& v,vector<int>& w, int c,int n)
        :v(v),w(w),c(c),num(n)
    {
        bestV =0;
        cv =0;
        cw =0;
    }
    //��ȡ��������Ʒ�����ֵ
    int GetBestValue()
    {
        BackTrack(0);
        return bestV;
    }
};

int main(void)
{
    //���Գ���
    int n;
    int c;
    cout<<"||���ݷ����0-1��������||"<<endl<<endl;
    cout << "��������Ʒ�ļ���:" << endl;
    cin >>n;
    cout << "�����뱳��������:" << endl;
    cin >>c;
    vector<int> w(n);
    vector<int> v(n);
    cout << "��������Ʒ������:" << endl;
    for(int i=0; i<n; ++i)
        cin >> w[i];
    cout << "��������Ʒ�ļ�ֵ:" << endl;
    for(int j=0; j<n; ++j)
        cin >> v[j];
    PackBackTrack pack(v,w,c,n);
    int bestV = pack.GetBestValue();
    cout << "�����ڵ���Ʒ������ֵΪ��" << bestV << endl;
    return 0;
}

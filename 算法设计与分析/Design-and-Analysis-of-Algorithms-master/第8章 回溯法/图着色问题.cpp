#include<bits/stdc++.h>
using namespace std;
const int n = 5;
int arc[n][n]= {{0,1,1,0,0},{1,0,1,1,1},{1,1,0,0,1},{0,1,0,0,1},{0,1,1,1,0}};
int color[n] = {0};
void GraphColor(int m);
int Ok(int k);
int main()
{
    GraphColor(3) ;
    return 0;

}

void GraphColor(int m)
{
    int i, k;
    for (i = 0; i < n; i++ )                     //������color[n]��ʼ��Ϊ0
        color[i] = 0;
    k = 0;
    while (k >= 0)
    {
        color[k] = color[k] + 1;
        while (color[k] <= m)
            if (Ok(k))
                break;
            else
                color[k] = color[k] + 1;             //������һ����ɫ
        if (color[k] <= m && k == n - 1)          //�����ϣ������
        {
            for (i = 0; i < n; i++)
                cout<<color[i]<<"  ";
            return;
        }
        else if (color[k] <= m && k < n - 1)
            k = k + 1;             //������һ������
        else
        {
            color[k] = 0;
            k = k - 1;    //����
        }
    }
}
int Ok(int k)   //�ж϶���k����ɫ�Ƿ�����ͻ
{
    for (int i = 0; i < k; i++)
        if (arc[k][i] == 1 && color[i] == color[k])
            return 0;
    return 1;
}

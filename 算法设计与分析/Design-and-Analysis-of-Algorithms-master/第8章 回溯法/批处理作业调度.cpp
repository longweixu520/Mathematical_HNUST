#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int BatchJob(int a[ ], int b[ ], int n);

int main()
{
    int a[n] = {2, 5, 4}, b[n] = {3, 2, 1};
    int bestTime = BatchJob(a, b, 3) ;
    cout<<"�����ҵʱ���ǣ�"<<bestTime<<endl;
    return 0;
}

int BatchJob(int a[ ], int b[ ], int n)
{
    int i, k;
    int x[6], sum1[6], sum2[6];
    int bestTime = 1000;                     //�ٶ�������ʱ�䲻����1000
    for (i = 1; i <= n; i++)
    {
        x[i] = -1;
        sum1[i] = 0;
        sum2[i] = 0;
    }
    sum1[0] = 0;
    sum2[0] = 0;
    k = 1;
    while (k >= 1)
    {
        x[k] = x[k] + 1;
        while (x[k] < n)
        {
            for (i = 1; i < k; i++)              //�����ҵx[k]�Ƿ��ظ�����
                if (x[i] == x[k])
                    break;
            if (i == k)                       //��ҵx[k]��δ����
            {
                sum1[k] = sum1[k-1] + a[x[k]];
                if (sum1[k] > sum2[k-1])
                    sum2[k] = sum1[k] + b[x[k]];
                else
                    sum2[k] = sum2[k-1] + b[x[k]];
                if (sum2[k] < bestTime)
                    break;
                else
                    x[k] = x[k] + 1;
            }
            else
                x[k] = x[k] + 1;             //��ҵx[k]�Ѵ���
        }
        if (x[k] < n && k < n)
            k = k + 1;                     //������һ����ҵ
        else
        {
            if (x[k] < n && k == n)        //�õ�һ����ҵ����
                if (bestTime > sum2[k])
                {
                    bestTime = sum2[k];
                    cout<<"��̵���ҵ�����ǣ�";
                    for (int j = 1; j <= n; j++)
                        cout<<x[j] + 1<<"  ";        ////�����±��0��ʼ����ӡ��ҵ��Ŵ�1��ʼ
                }
            x[k] = -1;
            k = k - 1;             //����x[k]������
        }
    }
    return bestTime;
}

#include<bits/stdc++.h>
using namespace std;
const int n = 4;
int SubCollAdd(int s[ ], int n, int C, double e);

int main()
{
    int s[n] = {104, 102, 201, 101};
    int C = 308;
    double e;
    cout<<"�����뾫��Ҫ��";
    cin>>e;
    int maxAdd = SubCollAdd(s, n, C, e);
    cout<<"����Ӽ����ǣ�"<<maxAdd<<endl;
    return 0;
}

int SubCollAdd(int s[ ], int n, int C,double e)
{
    int L1[1000], L2[1000], L3[1000];      //��L1��L2�ϲ���L3
    double d = e/n;                        //������������
    int i, j, k, m, t, x, z;
    int p, q;
    L1[0] = 0;
    m = 1;                      //��ʼ��
    for (i = 0; i < n; i++)                //���δ���s�е�ÿһ��Ԫ��
    {
        for (t = 0, j = 0; j < m; j++)     //����Li-1+si
        {
            x = L1[j] + s[i];
            if (x < C)
                L2[t++] = x;
        }
        p = 0, q = 0;
        k = 0;               //����Ϊ�ϲ�����
        while (p < m && q < t)
        {
            if (L1[p] == L2[q])
            {
                L3[k++] = L1[p++];
                q++;
            }
            else if (L1[p] < L2[q])
                L3[k++] = L1[p++];
            else
                L3[k++] = L2[q++];
        }
        while (p < m)
            L3[k++] = L1[p++];
        while (q < t)
            L3[k++] = L2[q++];
        for (t = 0, j = 0; j < k; j++)    //��Li��������
        {
            L1[t++] = L3[j];              //��������洢��L1��
            z = L3[j];
            while (j < k - 1)
                if (((1 - d) * L3[j + 1] <= z) && ( z <= L3[j + 1]))
                    j++;
                else
                    break;
        }
        m = t;                            //�Ӽ��͵ĸ���Ϊm
    }
    return L1[m-1];                       //���������Ӽ���
}

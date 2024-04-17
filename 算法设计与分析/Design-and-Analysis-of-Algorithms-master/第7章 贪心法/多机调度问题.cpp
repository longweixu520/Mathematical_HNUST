#include<bits/stdc++.h>
using namespace std;
const int n = 7;
const int m = 3;
void MultiMachine(int t[ ], int n, int d[ ], int m);

int main( )
{
    int t[n] = {16, 14, 6, 5, 4, 3, 2};
    int d[m] = {0};
    MultiMachine(t, n, d, m);
    return 0;
}

void MultiMachine(int t[ ], int n, int d[ ], int m)
{
    int S[3][7], rear[3];     //S[i]Ϊ�洢����i������ҵ�Ķ��У�rear[i]Ϊ��β�±�
    int i, j, k;
    for (i = 0; i < m; i++)          //����ǰm����ҵ
    {
        S[i][0] = i;
        rear[i] = 0;     //ÿ����ҵ���о�ֻ��һ����ҵ
        d[i] = t[i];
    }
    for (i = m; i < n; i++)             //���ΰ������µ�ÿһ����ҵ
    {
        for (j = 0, k = 1; k < m; k++)   //�������ȿ��еĻ���
            if (d[k] < d[j])
                j = k;
        rear[j]++;
        S[j][rear[j]] = i;     //����ҵi�������S[j]
        d[j] = d[j] + t[i];
    }
    for (i = 0; i < m; i++)               //���ÿ�������������ҵ
    {
        cout<<"����"<<i<<"��";
        for (j = 0; S[i][j] >= 0; j++)
            cout<<"��ҵ"<<S[i][j]<<"  ";
        cout<<endl;
    }
}

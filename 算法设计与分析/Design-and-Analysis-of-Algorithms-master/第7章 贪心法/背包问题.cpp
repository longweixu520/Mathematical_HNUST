#include<bits/stdc++.h>
using namespace std;
const int n = 3;
int KnapSack(int w[ ], int v[ ], int n, int C);

int main( )
{
    int w[n] = {10, 30, 20}, v[n] = {50, 120, 60};
    int C = 50;
    int value = KnapSack(w, v, 3, C);
    cout<<"������õ�����ֵ�ǣ�"<<value<<endl;
    return 0;
}

int KnapSack(int w[ ], int v[ ], int n, int C)
{
    double x[10] = {0};           //��Ʒ�ɲ���װ��
    int maxValue = 0;
    for (int i = 0; w[i] < C; i++)
    {
        x[i] = 1;                 //����Ʒiװ�뱳��
        maxValue += v[i];
        C = C - w[i];             //����ʣ������
    }
    x[i] = (double)C/w[i];        //��Ʒiװ��һ����
    maxValue += x[i] * v[i];
    return maxValue;              //���ر�����õļ�ֵ
}

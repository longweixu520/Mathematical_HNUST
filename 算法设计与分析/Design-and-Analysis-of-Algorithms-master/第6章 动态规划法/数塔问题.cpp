#include<bits/stdc++.h>
using namespace std;
#define n 5
int DataTorwer(int d[n][n]);

int main()
{
    int d[n][n]= {{8},{12,6},{3,9,4},{6,5,7,8},{1,2,3,4,5}};
    int max=DataTorwer(d);
    cout<<max<<endl;
    return 0;
}

int DataTorwer(int d[n][n])         //����������⣬�����洢������d[n][n]��
{
    int maxAdd[n][n] = {0}, path[n][n] = {0};       //��ʼ��
    int i, j;
    for (j = 0; j < n; j++)                         //��ʼ���ײ���߽��
        maxAdd[n-1][j] = d[n-1][j];
    for (i = n-2; i >= 0; i--)                       //���е�i��ľ���
        for (j = 0; j <= i; j++)                 //��дaddMax[i][j]��ֻ��д������
            if (maxAdd[i + 1][j]>maxAdd[i + 1][j + 1])
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j];
                path[i][j] = j;                  //���ξ���ѡ���±�j��Ԫ��
            }
            else
            {
                maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j + 1];
                path[i][j] = j + 1;               //���ξ���ѡ���±�j+1��Ԫ��
            }
    printf("·��Ϊ��%d", d[0][0]);         //����������
    j = path[0][0];        //���������ѡ����һ�����±�Ϊpath[0][0]��Ԫ��
    for (i = 1; i < n; i++)
    {
        printf("-->%d", d[i][j]);
        j = path[i][j];        //���������ѡ����һ�����±�Ϊpath[i][j]��Ԫ��
    }
    printf("\n�����ֵ��Ϊ��");
    return maxAdd[0][0];               //���������ֵ�ͣ������յľ��߽��
}

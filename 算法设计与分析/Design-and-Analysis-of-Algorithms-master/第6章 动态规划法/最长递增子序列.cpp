#include<bits/stdc++.h>
using namespace std;
int IncreaseOrder(int a[ ], int n);

int main()
{
    int a[]= {5,2,8,6,3,6,9,7};
    int len = IncreaseOrder(a, 8);
    cout<<"����������еĳ����ǣ�"<<len<<endl;
    return 0;
}
int IncreaseOrder(int a[ ], int n)
{
    int i, j, k, index;
    int L[10], x[10][10];                 //�������10��Ԫ��
    for (i = 0; i < n; i++)                 //��ʼ��������������г���Ϊ1
    {
        L[i] = 1;
        x[i][0] = a[i];
    }
    for (i = 1; i < n; i++)                //���μ���a[0]~a[i]�������������
    {
        int max = 1;                    //��ʼ�����������г��ȵ����ֵ
        for (j = i - 1; j >= 0; j--)           //�����е�aj < ai
        {
            if ((a[j] < a[i]) && (max < L[j] + 1))
            {
                max = L[j] + 1;
                L[i] = max;
                for (k = 0; k < max-1; k++)    //�洢�����������
                    x[i][k] = x[j][k];
                x[i][max-1]= a[i];
            }
        }
    }
    for (index = 0, i = 1; i < n; i++)       //�����е��������е���󳤶�
        if (L[index] < L[i])
            index = i;
    cout<<"������������ǣ�";
    for (i = 0; i < L[index]; i++)         //��������������
        cout<<x[index][i]<<"  ";
    return L[index];                  //��������������еĳ���
}

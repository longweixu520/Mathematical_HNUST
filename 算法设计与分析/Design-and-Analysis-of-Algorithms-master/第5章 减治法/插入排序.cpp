#include<bits/stdc++.h>
using namespace std;
void InsertSort(int r[ ], int n);

int main()
{
    int r[]= {0,12,15,9,20,10,6};
    InsertSort(r,6);
    for(int i=1; i<7; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void InsertSort(int r[ ], int n)              //�������¼���д洢��r[1]~r[n]��
{
    for (int i = 2; i <= n; i++)               //�ӵ�2����¼��ʼִ�в������
    {
        r[0] = r[i];                         //�ݴ�����¼�������ڱ�
        for (int j = i - 1; r[0] < r[j]; j--)        //Ѱ�Ҳ���λ��
            r[j + 1] = r[j];                    //��¼����
        r[j + 1] = r[0];
    }
}

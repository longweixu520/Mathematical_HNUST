#include<bits/stdc++.h>
using namespace std;
void MergeSort(int r[ ],  int s, int t);
void Merge(int r[ ], int r1[ ], int s, int m, int t);
int main()
{
    int r[8]= {8,1,2,9,6};
    MergeSort(r,0,4);
    for(int i=0; i<5; i++)
        cout<<r[i]<<" ";
    return 0;
}

void Merge(int r[ ], int r1[ ], int s, int m, int t)          //�ϲ�������
{
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])                     //ȡr[i]��r[j]�н�С�߷���r1[k]
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    }
    while (i <= m)                  //����һ��������û�����꣬�������β����
    {
        r1[k++] = r[i++];
    }
    while (j <= t)                   //���ڶ���������û�����꣬�������β����
    {
        r1[k++] = r[j++];
    }
}
void MergeSort(int r[ ], int s, int t)
{
    int m;
    int r1[1000] = {0};
    if (s == t)
        return;                 //�ݹ�ı߽�����
    else
    {
        m = (s + t)/2;                  //����
        MergeSort(r, s, m);           //���������1���鲢����ǰ���������
        MergeSort(r, m+1, t);         //���������2���鲢�������������
        Merge(r, r1, s, m, t);            //�ϲ��⣬�ϲ���������������
        for (int i = s; i <= t; i++)
            r[i] = r1[i];
    }
}




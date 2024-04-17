#include<bits/stdc++.h>
using namespace std;
int Partition(int r[ ], int  first, int end);
void RandQuickSort(int r[ ], int low, int high);
int Random(int a, int b);

int main()
{
    int r[]= {23,13,50,28,35,6,19};
    RandQuickSort(r,0,6);
    for(int i=0; i<7; i++)
        cout<<r[i]<<" ";
    return 0;
}
int Partition(int r[ ], int low, int high)          //����
{
    int i = low, j = high;                       //��ʼ������������
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;          //�Ҳ�ɨ��
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //����С��¼������ǰ��
            i++;
        }
        while (i < j && r[i] <= r[j])
            i++;         //���ɨ��
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;     //���ϴ��¼����������
            j--;
        }
    }
    return i;                                // ������ֵ��¼��λ��
}
void RandQuickSort(int r[ ], int low, int high)         //��������
{
    int k, i, temp;
    if (low < high)
    {
        i = Random(low, high);
        temp = r[low];
        r[low] = r[i];
        r[i] = temp;
        k = Partition(r, low, high);    //���֣�pivot����ֵ�������е�λ��
        RandQuickSort(r, low, k-1);      //���������1������������н��п�������
        RandQuickSort(r, k+1, high);      //���������2�����Ҳ������н��п�������
    }
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}

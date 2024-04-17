#include<bits/stdc++.h>
using namespace std;
int Partition(int r[ ], int  first, int end);
void QuickSort(int r[ ], int first, int end);

int main()
{
    int r[]= {23,13,35,6,19,50,28};
    QuickSort(r,0,6);
    for(int i=0; i<7; i++)
        cout<<r[i]<<" ";
    return 0;
}
int Partition(int r[ ], int first, int end)          //����
{
    int i = first, j=end;                       //��ʼ������������
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
void QuickSort(int r[ ], int first, int end)        //��������
{
    int pivot;
    if (first < end)
    {
        pivot = Partition(r, first, end);    //���֣�pivot����ֵ�������е�λ��
        QuickSort(r, first, pivot-1);      //���������1������������н��п�������
        QuickSort(r, pivot+1, end);      //���������2�����Ҳ������н��п�������
    }
}

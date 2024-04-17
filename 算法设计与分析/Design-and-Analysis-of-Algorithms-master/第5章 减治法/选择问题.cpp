#include<bits/stdc++.h>
using namespace std;
int MinK(int r[ ],int low,int high,int k);
int Partition(int r[ ], int low, int high);

int main()
{
    int r[]= {5,3,8,1,10,6,9,12,17};
    int k = 3;
    int x = MinK(r,0,8,k-1);
    cout<<"��"<<k<<"С��Ԫ����"<<x<<endl;
    return 0;
}

int Partition(int r[ ], int low, int high)          //����
{
    int i = low, j=high;                       //��ʼ������������
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

int MinK(int r[ ],int low,int high,int k)  //kΪ��kСԪ��
{
    int s;              //sΪ��ֵλ��
    s = Partition(r, low, high);
    if (s == k)
        return r[s];
    if(s > k)
        return MinK(r, low, s-1, k);
    else
        return MinK(r, s+1, high, k);
}

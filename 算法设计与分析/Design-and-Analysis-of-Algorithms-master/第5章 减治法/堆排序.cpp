#include<bits/stdc++.h>
using namespace std;
void HeapSort(int r[ ], int n);
void SiftHeap(int r[ ], int k, int n);

int main()

{
    int r[]= {47,33,35,2,18,71,26,13};
    HeapSort(r,8);
    for(int i=0; i<8; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void SiftHeap(int r[ ], int k, int n)
{
    int i, j, temp;
    i = k;
    j = 2 * i +1;                      //��iΪҪɸ�Ľ�㣬jΪi������
    while (j < n)                       //ɸѡ��û�н��е�Ҷ��
    {
        if (j < n-1  && r[j] < r[j+1])
            j++;    //�Ƚ�i�����Һ��ӣ�jΪ�ϴ���
        if (r[i] > r[j])                     //������Ѿ��������Һ����еĽϴ���
            break;
        else
        {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;            //����ɸ�������j����
            i = j;
            j = 2 * i+1;                 //��ɸ���λ��ԭ�����j��λ��
        }
    }
}
void HeapSort(int r[ ], int n)
{
    int i, temp;
    for (i = (n-1)/2; i >= 0; i--)       //��ʼ���ѣ������һ����֧����������
        SiftHeap(r, i, n) ;
    for (i = 1; i <= n-1; i++)         //�ظ�ִ�����߶Ѷ����ؽ��ѵĲ���
    {
        temp = r[0];
        r[0] = r[n-i];
        r[n-i] = temp;
        SiftHeap(r, 0, n-i);            //ֻ����������
    }
}



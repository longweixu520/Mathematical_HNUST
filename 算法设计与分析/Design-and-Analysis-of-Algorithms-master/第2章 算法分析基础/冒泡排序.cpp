#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int r[ ], int n);

int main()
{
    int i, r[]= {4,3,9,2,6,1};
    cout<<"����ǰ��";
    for(i=0; i<6; i++)
        cout<<r[i]<<" ";
    cout<<endl;
    BubbleSort(r,6);
    cout<<"�����";
    for(i=0; i<6; i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
void BubbleSort(int r[ ], int n)
{
    int bound, exchange = n - 1;           //��һ�����������������[0, n-1]
    while (exchange != 0)                //����һ�������м�¼����ʱ
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)       //һ����������������[0, bound]
            if (r[j] > r[j + 1])
            {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;       //������¼
                exchange = j;              //����ÿһ�μ�¼������λ��
            }
    }
}

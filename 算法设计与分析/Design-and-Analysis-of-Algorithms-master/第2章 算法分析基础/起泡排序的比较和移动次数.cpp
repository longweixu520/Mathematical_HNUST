#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int r[ ], int n);

int main()
{
    int r[]= {5,4,6,2,1,3};
    BubbleSort(r, 6);
    return 0;
}

void BubbleSort(int r[ ], int n)
{
    int count1 = 0, count2 = 0;     //count1��count2���رȽϴ������ƶ�����
    int bound, exchange = n - 1;         //��һ�����������������[0, n-1]
    while (exchange != 0)              //����һ�������м�¼����ʱ
    {
        bound = exchange;
        exchange = 0;
        for (int j = 0; j < bound; j++)        //һ����������������[0, bound]
            if (++count1 && r[j] > r[j+1])     //ע�ⲻ��д��count1++
            {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                count2 = count2 + 3;      //1�ν�����3���ƶ�����
                exchange = j;            //����ÿһ�μ�¼������λ��
            }
    }
    cout<<"�Ƚϴ�����:"<<count1<<endl;
    cout<<"�ƶ�������:"<<count2<<endl;
}

#include<bits/stdc++.h>
using namespace std;
const int n = 20;
int a[n];
void PrimeCircle(int n);
int Check(int k);
int Prime(int x);

int main( )
{
    int n;
    cout<<"������һ��������";
    cin>>n;
    PrimeCircle(n);
    return 0;
}

void PrimeCircle(int n)
{
    int i, k;
    for (i = 0; i < n; i++ )               //������a[n]��ʼ��Ϊ0
        a[i] = 0;
    a[0] = 1;
    k = 1;           //ָ����1��λ����д1��ע�������±��0��ʼ
    while (k >=1)
    {
        a[k] = a[k]+1;
        while (a[k] <= n)
            if (Check(k) == 1)
                break;         //λ��k������д����a[k]
            else
                a[k] = a[k] + 1;              //��̽��һ����
        if (a[k] <= n && k == n - 1)          //�����ϣ������
        {
            for (i = 0; i < n; i++)
                cout<<a[i]<<"  ";
            return;
        }
        if (a[k] <= n && k < n - 1)
            k = k + 1;               //������һ��λ��
        else
        {
            a[k] = 0;
            k = k - 1;        //����
        }
    }
}
int Check(int k)                    //�ж�λ��k����д�Ƿ�����Լ������
{
    int flag = 0;
    for (int i = 0; i < k; i++)           //�ж��Ƿ��ظ�
        if (a[i] == a[k])
            return 0;
    flag = Prime(a[k] + a[k - 1]);
    if (flag == 1 && k == n - 1)
        flag = Prime(a[k] + a[0]);
    return flag;
}
int Prime(int x)                   //�ж��Ƿ�����
{
    int i, n;
    n = (int)sqrt(x);
    for (i = 2; i <= n; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

#include<bits/stdc++.h>
using namespace std;
int Pollard(int n);
int Random(int a, int b);
int CommFactor(int m, int n);

int main()
{
    int x, y;
    cout<<"������һ��������";
    cin>>x;
    y = Pollard(x);
    if (y == 0)
        cout<<"��������ʧ��"<<endl;
    else
        cout<<x<<"��һ�������ǣ�"<<y<<endl;
    return 0;
}

int Pollard(int n)
{
    int a, b, c, d;
    a = Random(1, n - 1);                // aΪ[1, n-1]������������
    b = (a * a) % n;
    while (b < n - 1)
    {
        c = (int)sqrt(b);
        if (c * c != b * b)
            b = b + n;         //����Ӧ��b������b��һ����ȫƽ����
    }
    if (b == n - 1)
        return 0;              //�����㷨ִ��ʧ��
    else
        d = CommFactor(a + b, n);      //����ŷ������㷨�����Լ��
    if (d > 1)
        return d;                  //��dΪn�ķ�ƽ������
    else
        return 0;                      //�����㷨ִ��ʧ��
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}
int CommFactor(int m, int n)
{
    int r = m % n;
    while (r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

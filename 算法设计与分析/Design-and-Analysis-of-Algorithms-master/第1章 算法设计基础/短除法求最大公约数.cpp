#include<bits/stdc++.h>
using namespace std;
int CommFactor1(int m, int n);

int main()
{
    int a, b, r;
    cout<<"������������Ȼ����";
    cin>>a>>b;
    r = CommFactor1(a, b);
    cout<<a<<"��"<<b<<"�����Լ���ǣ�"<<r<<endl;
    return 0;
}
int CommFactor1(int m, int n)
{
    int i, factor = 1;
    for (i = 2; i <= m && i <= n; i++)
    {
        while (m % i == 0 && n % i == 0)              //�˴�������if���
        {
            factor = factor * i;
            m = m / i;
            n = n / i;
        }
    }
    return factor;
}

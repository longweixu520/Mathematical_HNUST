#include<bits/stdc++.h>
using namespace std;
int CommFactor2(int m, int n);

int main()
{
    int a, b, r;
    cout<<"������������Ȼ����";
    cin>>a>>b;
    r = CommFactor2(a, b);
    cout<<a<<"��"<<b<<"�����Լ���ǣ�"<<r<<endl;
    return 0;
}

int CommFactor2(int m, int n)
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

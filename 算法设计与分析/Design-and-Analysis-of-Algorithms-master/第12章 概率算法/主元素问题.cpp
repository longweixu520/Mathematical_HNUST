#include<bits/stdc++.h>
using namespace std;
const int n = 10;
int Random(int a, int b);
int MajorityMC(int T[ ], int n);

int main()
{
    int r[n] = {1,2,3,3,2,3,5,2,6,3};
    int flag = MajorityMC(r, n);
    if (flag)
        cout<<"������Ԫ��"<<endl;
    else
        cout<<"��������Ԫ��"<<endl;
    return 0;
}

int MajorityMC(int T[ ], int n)
{
    int i, j, x, count;
    i = Random(0, n-1);
    x = T[i];              //���ѡ��һ������Ԫ��
    count = 0;
    for (j = 0; j < n; j++)
        if (T[j] == T[i])
            count++;
    if (count > n/2)
        return 1;                  //T[i]����Ԫ��
    else
        return 0;
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}

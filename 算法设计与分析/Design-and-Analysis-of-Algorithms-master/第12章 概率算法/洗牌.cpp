#include<bits/stdc++.h>
using namespace std;
const int n = 10;
void RandomShuffle(int r[ ], int n);
int Random(int a, int b);

int main()
{
    int r[n] = {1,2,9,10,3,4,5,6,7,8};
    RandomShuffle(r, n);
    for (int i = 0; i < n; i++)
        cout<<r[i]<<"  ";
    return 0;
}

void RandomShuffle(int r[ ], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        j = Random(0, n-1);                           //���ѡ��һ��Ԫ��
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;                  //����r[i]��r[j]
    }
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}



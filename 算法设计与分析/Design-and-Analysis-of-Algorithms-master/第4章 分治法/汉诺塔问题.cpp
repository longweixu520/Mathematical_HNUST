#include<bits/stdc++.h>
using namespace std;
void Hanoi(int n, char A, char B, char C);

int main()
{
    char A, char B, char C;
    Hanoi(3,'A','B','C');
    cout<<endl;
    return 0;
}
void Hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        cout<< A<<"->"<<C<<"  ";   //�����Ӵ�A�Ƶ�C�ϣ��ݹ����
    else
    {
        Hanoi(n-1, A, C, B);            //��n-1�����Ӵ�A����C�Ƶ�B��
        cout<<A<<"->"<<C<<"  ";          //�����Ӵ�A�Ƶ�C��
        Hanoi(n-1, B, A, C);            //��n-1�����Ӵ�B����A�Ƶ�C��
    }
}

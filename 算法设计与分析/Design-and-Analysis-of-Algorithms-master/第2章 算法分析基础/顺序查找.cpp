#include<bits/stdc++.h>
using namespace std;
int SeqSearch(int A[ ], int n, int k);
int main()
{
    int A[]= {4,1,8,6,3,9};
    int i=SeqSearch(A,6,3);
    cout<<"���������ǵ�"<<i<<"��Ԫ��"<<endl;
    return 0;
}
int SeqSearch(int A[ ], int n, int k)   //������A[n]�в���ֵΪk�ļ�¼
{
    for (int i = 0; i < n; i++)
        if (A[i] == k)
            break;
    if (i == n)
        return 0;             //����ʧ�ܣ�����0
    else
        return i + 1;	              //���ҳɹ������ؼ�¼�����
}

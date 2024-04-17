#include<bits/stdc++.h>
using namespace std;
int SearchMid(int A[ ], int B[ ], int n);
int main()
{
    int A[]= {1,2,3,5,7};
    int B[]= {2,4,6,8,10};
    int mid=SearchMid(A,B,5);
    cout<<"�������е���λ���ǣ�"<<mid<<endl;
    return 0;
}
int SearchMid(int A[ ], int B[ ], int n)
{
    int s1 = 0, e1 = n - 1, s2 = 0, e2 = n-1;           //��ʼ���������е����½�
    int mid1, mid2;
    while (s1 < e1 && s2 < e2)                   //ѭ��ֱ������ֻ��һ��Ԫ��
    {
        mid1= (s1 + e1)/2;                        //����A����λ�����±�
        mid2 = (s2 + e2)/2;                       //����B����λ�����±�
        if (A[mid1] == B[mid2])
            return A[mid1];     //�ڢ������
        if (A[mid1] < B[mid2])                    //�ڢ������
        {
            if ((s1 + e1) % 2 == 0)
                s1 = mid1;
            else
                s1 = mid1 + 1;
            e2 = mid2;
        }
        else
        {
            if ((s2 + e2) % 2 == 0)
                s2 = mid2;
            else
                s2 = mid2 + 1;
            e1 = mid1;

        }
    }
    if (A[s1] < B[s2])
        return A[s1];              //��С��Ϊ����
    else
        return B[s2];
}

#include<bits/stdc++.h>
using namespace std;
int L[10][10],S[10][10];
int CommonOrder(char x[ ], int m, char y[ ], int n, char z[ ]);
int main()
{
    char x[]= {'a', 'b', 'c', 'b', 'd', 'b'};
    char y[]= {'a','c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'};
    char z[10];
    cout<<"����Ϊ��"<<CommonOrder(x,6,y,9,z)<<endl;
    return 0;
}
int CommonOrder(char x[ ], int m, char y[ ], int n, char z[ ])
{
    int i, j, k;
    for (j = 0; j <= n; j++)                       //��ʼ����0��
        L[0][j] = 0;
    for (i = 0; i <= m; i++)                      //��ʼ����0��
        L[i][0]=0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i-1] == y[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 1;
            }
            else if (L[i][j-1] >= L[i-1][j])
            {
                L[i][j] = L[i][j-1];
                S[i][j] = 2;
            }
            else
            {
                L[i][j] = L[i-1][j];
                S[i][j] = 3;
            }
        }
    }
    i = m;
    j = n;
    k = L[m][n];               //�����������д洢������z[k]��
    while (i >0 && j >0)
    {
        if (S[i][j] == 1)
        {
            z[k] = x[i-1];
            k--;
            i--;
            j--;
        }
        else if (S[i][j] == 2)
            j--;
        else
            i--;
    }
    for (k =1; k <=L[m][n]; k++)          //��������������
        cout<<z[k]<<" ";
    cout<<endl;
    return L[m][n];                     //���ع��������г���
}

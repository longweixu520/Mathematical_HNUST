#include<bits/stdc++.h>
using namespace std;
const int n = 10;
int FirstFit(int s[ ], int n, int b[ ], int C);

int main()
{
    int s[n] = {4, 2, 7, 3, 5, 4, 2, 3, 6, 2};
    int b[n] = {0}, C = 10;
    int num = FirstFit(s, n, b, C);
    cout<< "��Ҫ���ӵĸ����ǣ�"<<num<<endl;
    return 0;
}

int FirstFit(int s[ ], int n, int b[ ], int C)
{
    int i, j, k = -1;                  //k��ʾ��װ����Ʒ�����ӵ�����±�
    for (j = 0; j < n; j++)             //�������ӵ������ʼ��Ϊ0
        b[j] = 0;
    for (i = 0; i < n; i++)             //װ���i����Ʒ
    {
        j = 0;
        while (C - b[j] < s[i])          //���ҵ�1����������Ʒi������
            j++;
        b[j] = b[j] + s[i];
        if (k < j)
            k = j;
    }
    return (k + 1);                        //ע�������±��0��ʼ��kΪ�±�
}

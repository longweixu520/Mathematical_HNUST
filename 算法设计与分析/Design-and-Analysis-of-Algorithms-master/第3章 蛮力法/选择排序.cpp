#include<bits/stdc++.h>
using namespace std;
void SelectSort(int r[ ], int n);

int main()
{
    int r[]= {1,6,7,5,3,8,9,2};
    SelectSort(r,8);
    for(int i=0; i<8; i++)
        cout<<r[i]<<"  ";
    return 0;
}
void SelectSort(int r[ ], int n)
{
    int i, j, index, temp;
    for (i = 0; i < n - 1; i++)  	            //��n����¼����n-1��ѡ������
    {
        index = i;
        for (j = i + 1; j < n; j++)           //���������в�����С��¼
            if (r[j] < r[index])
                index = j;
        if (index != i)
        {
            temp = r[i];
            r[i] = r[index];
            r[index] = temp;
        }//������¼
    }
}

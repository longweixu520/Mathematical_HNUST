#include<bits/stdc++.h>
using namespace std;
int MaxSum(int a[ ], int left, int right);
int main()
{
    int a[]= {-20,11,-4,13,-5,-2};
    int sum=MaxSum(a,0,5);
    cout<<sum;
    return 0;
}
int MaxSum(int a[ ], int left, int right)      //������a[left]~a[right]������Ӷκ�
{
    int sum = 0, midSum = 0, leftSum = 0, rightSum = 0,i,j;
    int center, s1, s2, lefts, rights;
    if (left == right)                      //������г���Ϊ1��ֱ�����
        sum = a[left];
    else
    {
        center = (left + right)/2;             //����
        leftSum = MaxSum(a, left, center);          //��Ӧ����٣��ݹ����
        rightSum = MaxSum(a, center+1, right);      //��Ӧ����ڣ��ݹ����
        s1 = 0;
        lefts = 0;                         //���¶�Ӧ����ۣ������s1
        for (i = center; i >= left; i--)
        {
            lefts += a[i];
            if (lefts > s1)
                s1 = lefts;
        }
        s2 = 0;
        rights = 0;                        //�����s2
        for (j = center + 1; j <= right; j++)
        {
            rights += a[j];
            if (rights > s2)
                s2 = rights;
        }
        midSum = s1 + s2;                          //��������۵�����Ӷκ�
        if (midSum < leftSum)
            sum = leftSum;           //�ϲ��⣬ȡ�ϴ���
        else
            sum = midSum;
        if (sum < rightSum)
            sum = rightSum;
    }
    return sum;
}

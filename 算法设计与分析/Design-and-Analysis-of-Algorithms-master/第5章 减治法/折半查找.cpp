#include<bits/stdc++.h>
using namespace std;
int BinSearch1(int r[ ], int n, int k);

int main()
{
    int r[]= {7, 14, 18, 21, 23, 29, 31, 35, 38};
    int i=BinSearch1(r,9,18);
    cout<<"�������е��±��ǣ�"<<i<<endl;
    return 0;
}

int BinSearch1(int r[ ], int n, int k)
{
    int low = 0, high = n - 1;               //���ò������䣬ע�������±��0��ʼ
    int mid;
    while (low <= high)                //���������ʱ
    {
        mid = (low + high) / 2;
        if (k < r[mid])
            high = mid - 1;
        else	if (k > r[mid])
            low = mid + 1;
        else
            return mid;                      //���ҳɹ�������Ԫ�����
    }
    return 0;                                  //����ʧ�ܣ�����0
}

#include<bits/stdc++.h>
using namespace std;
void Chicken( );

int main()
{
    Chicken( );
    return 0;
}

void Chicken( )
{
    int x, y, z;                //x��y��z�ֱ��ʾ������ĸ����С���ĸ���
    int count = 0;                          //��ĸ�����ʼ��Ϊ0
    for (x = 0; x <= 20; x++)                 //��������x�ķ�Χ��0��20
    {
        for (y = 0; y <= 33; y++)               //ĸ������y�ķ�Χ��0��33
        {
            z = 100 - x - y;                    //���㷽��x + y + z = 100
            if ((z % 3 == 0) && (5 * x + 3 * y + z/3 == 100))  //�����ܼ���100Ԫ
            {
                count++;                       //��ĸ�����1
                cout<<"������"<<x<<"  ĸ����"<<y<<"  С����"<<z<<endl;
            }
        }
    }
    if (count == 0)
        cout<<"�����޽�"<<endl;
}

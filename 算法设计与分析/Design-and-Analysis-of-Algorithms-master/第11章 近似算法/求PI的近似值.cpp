#include<bits/stdc++.h>
using namespace std;
double Pi(double e);

int main()
{
    double e, PI;
    cout<<"�����뾫��Ҫ��";
    cin>>e;
    PI = Pi(e);
    cout<<"Pi="<<PI<<endl;           //�����ֵ
    return 0;
}

double Pi(double e)                      //�������Ƶľ���Ҫ��
{
    int i = 6;                           // ����6���ο�ʼ
    double  b, x = 1;                   //2bΪ������η���֮ǰ�ı߳���xΪ����֮��ı߳�
    do
    {
        b = x/2;                        //��6���εı߳�Ϊ1����2b=1
        i = i * 2;                      //������εı�������
        x = sqrt(2-2*sqrt(1.0-b*b));         //����Բ�ڽ�������η�����ı߳�
    }
    while (i * x - i * b > e);          //���ȴﵽҪ����ֹͣ����
    cout<<"Բ���ڽӶ���εı����ǣ�"<<i<<endl;
    return (i * x)/2;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 100;                                //�ٶ������100�ʺ�����
void Queue(int n);                                              //��������
int Place(int x[ ], int k);                                                //��������
int Random(int a, int b);
//���У�������������
int main( )
{
    int n;
    cout<<"������ʺ�ĸ���:";                    //�����ʾ��Ϣ
    cin>>n;                                      //����ʺ�ĸ���
    srand(time(NULL));
    Queue(n);                                  //�������ã����n�ʺ�����
    return 0;                         //��0���ز���ϵͳ������������������
}
//���У�������������������
void Queue(int n)                              //�������壬���n�ʺ�����
{
    int i, j, count = 0;
    int x[1000];
    for (i = 0; i < n; i++)
        x[i] = 0;
    for (i = 0; i < n; )
    {
        j = Random(1, n);
        x[i] = j;
        count++;
        if (!Place(x, i))
        {
            count = 0;
            i++;
        }
        else if (count == n)
        {
            cout<<"��������ʧ��"<<endl;
            break;
        }
    }
    for (i = 0; i < n; i++)
        cout<<x[i]<<"  ";
    cout<<endl;
}
int Place(int x[ ], int k)                    //����ʺ�k������x[k]���Ƿ�����ͻ
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))             //Υ��Լ������
            return 1;                                          //��ͻ������1
    return 0;                                            //����ͻ������0
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )����[0, 32767]֮����������
}

#include<bits/stdc++.h>
using namespace std;
int data[100][100];
void Full(int number, int begin, int size);

int main()
{
    int size;
    cout<<"���뷽��Ĵ�С��";
    cin>>size;
    Full(1,0,size);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            cout<<data[i][j]<<setw(4);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
void Full(int number, int begin, int size)
{
    //��number ��ʼ��дsize �׷������Ͻǵ��±�Ϊ(begin, begin)
    int i, j, k;
    if (size == 0)             //�ݹ�ı߽����������size����0����������д
        return;
    if (size == 1)                         //�ݹ�ı߽����������size����1
    {
        data[begin][begin] = number;         //��ֻ����дnumber
        return;
    }
    i = begin;
    j = begin;                   //��ʼ�����Ͻ��±�
    for (k = 0; k < size - 1; k++)            //��д����A������дsize - 1����
    {
        data[i][j] = number;                 //�ڵ�ǰλ����дnumber
        number++;
        i++;                    //���±��1
    }
    for (k = 0; k < size - 1; k++)            //��д����B������дsize - 1����
    {
        data[i][j] = number;                 //�ڵ�ǰλ����дnumber
        number++;
        j++;                    //���±��1
    }
    for (k = 0; k < size - 1; k++)            //��д����C������дsize - 1����
    {
        data[i][j] = number;                //�ڵ�ǰλ����дnumber
        number++;
        i--;                    //���±��1
    }
    for (k = 0; k < size - 1; k++)            //��д����D������дsize - 1����
    {
        data[i][j] = number;                //�ڵ�ǰλ����дnumber
        number++;
        j--;                    //���±��1
    }
    Full(number, begin + 1, size - 2);       //�ݹ���⣬���Ͻ��±�Ϊbegin + 1
}

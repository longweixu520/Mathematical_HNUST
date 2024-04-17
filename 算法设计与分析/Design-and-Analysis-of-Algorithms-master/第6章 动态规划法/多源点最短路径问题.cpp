#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int n = 3;                             //����ͼ����ඥ�����
void Floyd(int arc[n][n], int dist[n][n]);

int main()
{
    int arc[n][n]= {{0,4,11},{6,0,2},{3,MAX,0}};
    int dist[n][n];
    Floyd(arc,dist);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<dist[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
void Floyd(int arc[n][n], int dist[n][n])
{
    int i, j, k;
    for (i = 0; i < n; i++)                     //��ʼ������dist
        for (j = 0; j < n; j++)
            dist[i][j] = arc[i][j];
    for (k = 0; k < n; k++)                   //����n�ε���
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

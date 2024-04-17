#include<bits/stdc++.h>
using namespace std;
const int N = 20;
const int MAX = 1000;
int arc[N][N];               //�洢���ϵ�Ȩֵ
int Backpath(int n);
int creatGraph();

int main()
{
    int n = creatGraph( );
    int pathLen = Backpath(n);
    cout<<"���·���ĳ����ǣ�"<<pathLen<<endl;
    return 0;
}
int creatGraph()
{
    int i, j, k;
    int weight;
    int vnum, arcnum;
    cout<<"�����붥��ĸ����ͱߵĸ�����";
    cin>>vnum>>arcnum;
    for (i = 0; i < vnum; i++)
        for (j = 0; j < vnum; j++)
            arc[i][j] = MAX;
    for (k = 0; k < arcnum; k++)
    {
        cout<<"������ߵ����������Ȩֵ��";
        cin>>i>>j>>weight;
        arc[i][j] = weight;
    }
    return vnum;
}
int Backpath(int n)
{
    int i, j, temp;
    int cost[N];
    int path[N];
    for(i = 0; i < n; i++)
    {
        cost[i] = MAX;
        path[i] = -1;
    }
    cost[0] = 0;
    for(j = 1; j < n; j++)
    {
        for(i = j - 1; i >= 0; i--)
        {
            if (arc[i][j] + cost[i] < cost[j])
            {
                cost[j] = arc[i][j] + cost[i];
                path[j] = i;
            }
        }
    }
    cout<<n-1;
    i = n-1;
    while (path[i] >= 0)
    {
        cout<<"<-"<<path[i];
        i = path[i];
    }
    cout<<endl;
    return cost[n-1];
}

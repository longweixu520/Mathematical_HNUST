#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int t = 0;
void  ChessBoard(int tr, int tc, int dr, int dc, int size);
int main()
{
    ChessBoard(0,0,2,2,4);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<board[i][j]<<setw(6);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
void  ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    int s, t1;
    if (size == 1)
        return;                  //����ֻ��һ�������������ⷽ��
    t1 = ++t;    // L�͹��Ʊ��
    s = size/2;                          // ��������
    if (dr < tr + s && dc < tc + s)           //���ⷽ�������Ͻ���������
        ChessBoard(tr, tc, dr, dc, s);          //�ݹ鴦��������
    else                //�� t ��L�͹��Ƹ������½ǣ��ٵݹ鴦��������
    {
        board[tr + s - 1][tc + s - 1] = t1;
        ChessBoard(tr, tc, tr+s-1, tc+s-1, s);
    }
    if (dr < tr + s && dc >= tc + s)          //���ⷽ�������Ͻ���������
        ChessBoard(tr, tc+s, dr, dc, s);        //�ݹ鴦��������
    else                 //�� t ��L�͹��Ƹ������½ǣ��ٵݹ鴦��������
    {
        board[tr + s - 1][tc + s] = t1;
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);
    }
    if (dr >= tr + s && dc < tc + s)         //���ⷽ�������½���������
        ChessBoard(tr+s, tc, dr, dc, s);       //�ݹ鴦��������
    else                //�� t ��L�͹��Ƹ������Ͻǣ��ٵݹ鴦��������
    {
        board[tr + s][tc + s - 1] = t1;
        ChessBoard(tr+s, tc, tr+s, tc+s-1, s);
    }
    if (dr >= tr + s && dc >= tc + s)        //���ⷽ�������½���������
        ChessBoard(tr+s, tc+s, dr, dc, s);      //�ݹ鴦��������
    else                //�� t ��L�͹��Ƹ������Ͻǣ��ٵݹ鴦��������
    {
        board[tr + s][tc + s] = t1;
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);
    }
}

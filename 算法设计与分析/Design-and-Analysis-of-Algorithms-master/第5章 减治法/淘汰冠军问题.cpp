#include<bits/stdc++.h>
using namespace std;
char Game(char r[ ], int n);
int Comp(char a,char b);

int main()
{
    char r[]="AFGBEHCD";
    char c=Game(r,8);
    cout<<"���Ĺھ��ǣ�"<<c<<endl;
    return 0;
}
int Comp(char a,char b)
{
    if(a>b)
        return 1;
    else
        return 0;
}
char Game(char r[ ], int n)
{
    int i = n;
    while (i > 1)                        //����ֱ��ʣ��1�˼�Ϊ�ھ�
    {
        i = i/2;
        for (int j = 0; j < i; j++)
            if (Comp(r[j+i], r[j]))            //ʤ�ߴ���r[j]��
                r[j] = r[j+i];
    }
    return r[0];
}

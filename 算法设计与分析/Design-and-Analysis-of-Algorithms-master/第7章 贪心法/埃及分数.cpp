#include <iostream.h>
int CommFactor(int m, int n);
void EgyptFraction(int A, int B);

int main( )
{
	int A, B;
	cout<<"������������ķ��ӣ�";
	cin>>A;
	cout<<"������������ķ�ĸ��";
	cin>>B;
    EgyptFraction(A, B);
	return 0;
}

void EgyptFraction(int A, int B)  
{                      
    int E, R;
    cout<<A<<"/"<<B<<" = ";            //��������A/B
    do
    {
		E = B/A + 1;                    //�������A/B��������󰣼�����
		cout<<"1/"<<E<<" + ";                //���1/E
		A = A * E - B;                   //��������������A/B - 1/E
		B = B * E;
		R = CommFactor(B, A);        //�������ã���A��B�����Լ��
		if (R > 1)                      //���Լ������1����A/B���Ի���
		{
			A = A/R; B = B/R;             //��A/B����
		}
	} while (A > 1);                   //��A/B���ǰ�������ʱִ��ѭ��
    cout<<"1/"<<B<<endl;                //������һ����������1/B
    return;                         
}
int CommFactor(int m, int n)
{
   int r = m % n;
   while (r != 0) 
   {
    m = n;
    n = r;
    r = m % n;
   }
   return n;
}

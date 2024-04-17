#include<bits/stdc++.h>
using namespace std;
typedef struct BiNode
{
    int data;                      //����ֵ��������Ҽ��ϵ�Ԫ��Ϊ����
    BiNode *lchild, *rchild;         //ָ������������ָ��
} BiNode;
BiNode * SearchBST(BiNode *root, int k);
BiNode * insertBST(BiNode *tree,int data);
BiNode * createBST(int a[],int n);

int main()
{
    BiNode *root, *t;
    int a[]= {55,42,10,70,63,58,83,67,90,45};
    root=createBST(a,10);
    t=SearchBST(root,58);
    if(t != NULL)
        cout<<"���ҳɹ�"<<endl;
    else
        cout<<"����ʧ��"<<endl;
    return 0;
}
BiNode *insertBST(BiNode *root, int data)
{
    if(root == NULL)
    {
        root = new BiNode;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if(data <= root->data)
        root->lchild = insertBST(root->lchild, data);
    else
        root->rchild = insertBST(root->rchild, data);
    return root;
}
BiNode *createBST(int a[], int n)
{
    BiNode *T = NULL;
    for (int i=0; i < n; i++)
        T = insertBST(T, a[i]);
    return T;
}
BiNode * SearchBST(BiNode *root, int k)
{
    if (root == NULL)
        return NULL;            //���������Ϊ�գ�����ʧ��
    else if (root->data == k)
        return root;           //���ҳɹ�
    else if (k < root->data)                   //����������
        return SearchBST(root->lchild, k);
    else                               //����������
        return SearchBST(root->rchild, k);
}

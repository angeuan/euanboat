#include <stdio.h>
#include "btree.h"//用到了btree.h

int Nodes(BTNode *b)
{
if (b==NULL)
return 0;//空树返回0
else
return Nodes(b->lchild)+Nodes(b->rchild)+1;//递归求解
}
int main()
{
BTNode *b;
CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
printf("二叉树节点个数: %d\n", Nodes(b));
DestroyBTNode(b);
return 0;
}
/*
//叶节点个数：

#include <stdio.h>
#include "btree.h"

int LeafNodes(BTNode *b)//求二叉树b的叶子节点个数
{
int num1,num2;
if (b==NULL)//空树
return 0;
else if (b->lchild==NULL && b->rchild==NULL)//为页结点
return 1;
else//递归求解
{
num1=LeafNodes(b->lchild);
num2=LeafNodes(b->rchild);
return (num1+num2);
}
}

int main()
{
BTNode *b;
CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
printf("二叉树b的叶子节点个数: %d\n",LeafNodes(b));
DestroyBTNode(b);
return 0;
}*/
#include <stdio.h>
#include <malloc.h>
#include "sqstack.h"

void InitStack(SqStack *&s)
{
 s=(SqStack *)malloc(sizeof(SqStack));
 s->top=-1;
}
bool Push(SqStack *&s,ElemType e)
{
 if (s->top==MaxSize-1)//栈满的情况
return false;
 s->top++;
 s->data[s->top]=e;
 return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
 if (s->top==-1) //栈为空的情况
 {
return false;
 }
 e=s->data[s->top];
 s->top--;
 return true;
}
void DispStack(SqStack *s) //倒序输出顺序栈
{
 int i=s->top;
 int j=0;
 for (j;j<=i;j++)
 printf("%d ",s->data[j]);
 printf("\n");
}
void Locate(SqStack *&l)
{
 l->top=-1;
 printf("input:");
 int y;
 int s=0;
 int x[110];
 int i=0;
 char a;
 while ((a=getchar())!='\n') //将输入的数字存入数组
 {
 x[s]=a-'0';
 s++;
 }
 if (s==0)
 {
 printf("stack is null!");
 return;
 }
 else if (s==100)
 {
 printf("stack is full!");
 }
 while (x[i]>=0) //将数组中的数字送入栈
 {
 if (x[i]==0)
 {
 Pop(l,y);
 }
 else
 {
 Push(l,x[i]);
 }
 i++;
 if (i==s)
 {
 break;
 }
 }
 printf("output:");
 DispStack(l);
}

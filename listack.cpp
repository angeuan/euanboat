#include <stdio.h>
#include <malloc.h>
#include "listack.h"

void InitStack(LiStack *&s)  //初始化栈
{
    s=(LiStack *)malloc(sizeof(LiStack));
    s->next=NULL;
}

void DestroyStack(LiStack *&s)  //销毁栈
{
    LiStack *p=s->next;
    while (p!=NULL)
    {
        free(s);
        s=p;
        p=p->next;
    }
    free(s);    //s指向尾结点,释放其空间
}

int StackLength(LiStack *s)  //返回栈长度
{
    int i=0;
    LiStack *p;
    p=s->next;
    while (p!=NULL)
    {
        i++;
        p=p->next;
    }
    return(i);
}

bool StackEmpty(LiStack *s)  //判断栈是否为空
{
    return(s->next==NULL);
}

void Push(LiStack *&s,ElemType e)  //入栈
{
    LiStack *p;
    p=(LiStack *)malloc(sizeof(LiStack));
    p->data=e;              //新建元素e对应的节点*p
    p->next=s->next;        //插入*p节点作为开始节点
    s->next=p;
}

bool Pop(LiStack *&s,ElemType &e)  //出栈
{
    LiStack *p;
    if (s->next==NULL)      //栈空的情况
        return false;
    p=s->next;              //p指向开始节点
    e=p->data;
    s->next=p->next;        //删除*p节点
    free(p);                //释放*p节点
    return true;
}

bool GetTop(LiStack *s,ElemType &e)  //取栈顶元素
{
    if (s->next==NULL)      //栈空的情况
        return false;
    e=s->next->data;
    return true;
}

void DispStack(LiStack *s)  //输出栈中元素
{
    LiStack *p=s->next;
    while (p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

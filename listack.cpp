#include <stdio.h>
#include <malloc.h>
#include "listack.h"

void InitStack(LiStack *&s)  //��ʼ��ջ
{
    s=(LiStack *)malloc(sizeof(LiStack));
    s->next=NULL;
}

void DestroyStack(LiStack *&s)  //����ջ
{
    LiStack *p=s->next;
    while (p!=NULL)
    {
        free(s);
        s=p;
        p=p->next;
    }
    free(s);    //sָ��β���,�ͷ���ռ�
}

int StackLength(LiStack *s)  //����ջ����
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

bool StackEmpty(LiStack *s)  //�ж�ջ�Ƿ�Ϊ��
{
    return(s->next==NULL);
}

void Push(LiStack *&s,ElemType e)  //��ջ
{
    LiStack *p;
    p=(LiStack *)malloc(sizeof(LiStack));
    p->data=e;              //�½�Ԫ��e��Ӧ�Ľڵ�*p
    p->next=s->next;        //����*p�ڵ���Ϊ��ʼ�ڵ�
    s->next=p;
}

bool Pop(LiStack *&s,ElemType &e)  //��ջ
{
    LiStack *p;
    if (s->next==NULL)      //ջ�յ����
        return false;
    p=s->next;              //pָ��ʼ�ڵ�
    e=p->data;
    s->next=p->next;        //ɾ��*p�ڵ�
    free(p);                //�ͷ�*p�ڵ�
    return true;
}

bool GetTop(LiStack *s,ElemType &e)  //ȡջ��Ԫ��
{
    if (s->next==NULL)      //ջ�յ����
        return false;
    e=s->next->data;
    return true;
}

void DispStack(LiStack *s)  //���ջ��Ԫ��
{
    LiStack *p=s->next;
    while (p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
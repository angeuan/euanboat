/*
 *Copyright(c)2017,烟台大学计算机学院
 *All right reserved.
 *文件名称：0.cpp
 *作者：李小同
 *完成日期；2017年9月27日
 *版本号；v1.1
 *
 *问题描述：定义单链表存储结构，用头插法和尾插法建立单链表，并显示建立好以后的结果。
 *输入描述：创建单链表
 *程序输出：输出单链表
*/
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode        //定义单链表结点类型
{
    ElemType data;
    struct LNode *next;     //指向后继结点
} LinkList;
 
void CreateListF(LinkList *&L,ElemType a[],int n);//头插法建立单链表
void CreateListR(LinkList *&L,ElemType a[],int n);//尾插法建立单链表
void DestroyList(LinkList *&L); //销毁单链表
void DispList(LinkList *L);  //输出单链表
 
int main()
{
    LinkList *L1, *L2;
    ElemType a[8]= {7, 9, 8, 2, 0, 4, 6, 3};
    CreateListF(L1, a, 8);
    printf("头插法建表结果：");
    DispList(L1);
    CreateListR(L2, a, 6);
    printf("尾插法建表结果：");
    DispList(L2);
    DestroyList(L1);
    DestroyList(L2);
    return 0;
}
 
void CreateListF(LinkList *&L,ElemType a[],int n)//头插法建立单链表
{
    LinkList *s;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //创建头结点
    L->next=NULL;
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//创建新结点
        s->data=a[i];
        s->next=L->next;            //将*s插在原开始结点之前,头结点之后
        L->next=s;
    }
}
void CreateListR(LinkList *&L,ElemType a[],int n)//尾插法建立单链表
{
    LinkList *s,*r;
    int i;
    L=(LinkList *)malloc(sizeof(LinkList));     //创建头结点
    L->next=NULL;
    r=L;                    //r始终指向终端结点,开始时指向头结点
    for (i=0; i<n; i++)
    {
        s=(LinkList *)malloc(sizeof(LinkList));//创建新结点
        s->data=a[i];
        r->next=s;          //将*s插入*r之后
        r=s;
    }
    r->next=NULL;           //终端结点next域置为NULL
}
 
void DestroyList(LinkList *&L)  //销毁单链表
{
    LinkList *p=L,*q=p->next;
    while (q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);    //此时q为NULL,p指向尾结点,释放它
}
 
void DispList(LinkList *L)  //输出单链表
{
    LinkList *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
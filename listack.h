#ifndef LISTACK_H_INCLUDED
#define LISTACK_H_INCLUDED

typedef char ElemType;
typedef struct linknode
{
    ElemType data;              //数据域
    struct linknode *next;      //指针域
} LiStack;                      //链栈类型定义

void InitStack(LiStack *&s);  //初始化栈
void DestroyStack(LiStack *&s);  //销毁栈
int StackLength(LiStack *s);  //返回栈长度
bool StackEmpty(LiStack *s);  //判断栈是否为空
void Push(LiStack *&s,ElemType e);  //入栈
bool Pop(LiStack *&s,ElemType &e);  //出栈
bool GetTop(LiStack *s,ElemType &e);  //取栈顶元素
void DispStack(LiStack *s);  //输出栈中元素


#endif // LISTACK_H_INCLUDED

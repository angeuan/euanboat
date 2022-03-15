#ifndef LISTACK_H_INCLUDED
#define LISTACK_H_INCLUDED

typedef char ElemType;
typedef struct linknode
{
    ElemType data;              //������
    struct linknode *next;      //ָ����
} LiStack;                      //��ջ���Ͷ���

void InitStack(LiStack *&s);  //��ʼ��ջ
void DestroyStack(LiStack *&s);  //����ջ
int StackLength(LiStack *s);  //����ջ����
bool StackEmpty(LiStack *s);  //�ж�ջ�Ƿ�Ϊ��
void Push(LiStack *&s,ElemType e);  //��ջ
bool Pop(LiStack *&s,ElemType &e);  //��ջ
bool GetTop(LiStack *s,ElemType &e);  //ȡջ��Ԫ��
void DispStack(LiStack *s);  //���ջ��Ԫ��


#endif // LISTACK_H_INCLUDED
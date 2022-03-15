//#ifndef SEQLIST_H_INCLUDED
//#define SEQLIST_H_INCLUDED

/*定义顺序栈*/
#define maxsize 50
typedef struct
{
    int stack[maxsize];
    int top;//定义顺序栈的栈顶
} seqlist;

/*初始化顺序栈*/
void seqinit(seqlist *l)
{
    l->top=-1;//初始化栈顶为-1
}

/*顺序栈栈长函数listlength()*/
int listlength(seqlist *l)
{
    return l->top+1;//返回顺序栈的长度
}

/*入栈函数seqbulid()*/
int seqbulid(seqlist *l,int x)
{
	l->top++;
	if(l->top >= maxsize){//判断栈是否已满
        std::cout<<"该顺序栈已满！！"<<std::endl;
        return 0;
	}
    l->stack[l->top]=x;
    return 1;
}

/*打印顺序栈函数seqprinter ()*/
void seqprinter(seqlist *l)
{
    if(l->top < 0){//判断栈是否为空
        std::cout<<"该栈为空"<<std::endl;
        return ;
    }
	for(int i=0;i<=l->top;i++)
    {
        std::cout<<"  "<<l->stack[i];
    }
    std::cout<<"\n";
}

/*出栈函数seqdelete ()*/
int seqdelete(seqlist *l)
{
	int x;
	x = l->stack[l->top];//保留被弹出的元素
    l->top--;
    return x;
}

/*逆序输出*/
void seqsetter(seqlist *l)
{
if(l->top < 0){//判断栈是否为空
        std::cout<<"该栈为空"<<std::endl;
        return ;
    }
	for(int i=l->top;i>=0;i--)
    {
        std::cout<<"  "<<l->stack[i];
    }
    std::cout<<"\n";
}

/*行编辑函数1.0版本seqlocate ()*/
int seqlocate1(seqlist *l)
{
	l->top=-1;//清空之前的顺序栈
	std::cout<<"请输入行编辑之前的数据:"<<std::endl;
	int x;
	while(std::cin>>x && x >=0)
	{
		if(x == 0){//判断该元素是否为零，如为零，则将之前的数弹出
			seqdelete(l);
		}else{
			seqbulid(l,x);
		}
	}
	std::cout<<"行编辑之后的数据："<<std::endl;
	seqprinter(l);
	return 1;
}

/*行编辑函数2.0版本seqlocate ()*/
int seqlocate2(seqlist *l)
{
	l->top=-1;
	std::cout<<"请输入行编辑之前的数据:"<<std::endl;
	int x;
	while(std::cin>>x && x >=0)
	{
		if(x == 0){//判断该元素是否为零，如为零，则将之前的数+1
			l->stack[l->top]++;
		}else{
			seqbulid(l,x);
		}
	}
	std::cout<<"行编辑之后的数据："<<std::endl;
	seqprinter(l);
	return 1;
}

//#endif // SEQLIST_H_INCLUDED

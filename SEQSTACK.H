typedef struct
{
    DataType stack[MaxStackSize];
    int top;
} SeqStack;

void StackInitiate(SeqStack *s)
{
    s->top=0;
}
int StackNotEmpty(SeqStack s)
{
    if(s.top<=0)  return 0;
    else return 1;
}
int StackPush(SeqStack *s,DataType x)
{
    if(s->top>=MaxStackSize)
    {
        printf("堆栈已满无法插入！\n");
        return 0;
    }
    else
    {
        s->stack[s->top]=x;
        s->top++;
        return 1;
    }
}
int StackPop(SeqStack *s,DataType *d)
{
    if(s->top<=0)
    {
        printf("堆栈已空无数据出栈！\n");
        return 0;

    }
    else
    {
        s->top--;
        *d=s->stack[s->top];
        return 1;
    }
}
int StackTop(SeqStack *s,DataType *d)
{
    if(s->top<=0)
    {
        printf("堆栈已空！\n");
        return 0;
    }
    else
    {
        *d=s->stack[s->top-1];
        return 1;
    }
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 64
#define MaxStackSize 64
typedef struct
{
    int x;
    int y;
} coo;
typedef coo DataType;
#include "SeqList.h"
#include "SeqStack.h"
int TTM(coo Knight,SeqList p,SeqStack *solution,int *k)
{
    if(p.size==0)//已经吃完
    {
        StackPush(solution,Knight);
        return 1;
    }
    else//棋盘上还有兵
    {
        SeqList possible;
        int i,a[8],j=0;
        coo NewKnight;
        ListInitiate(&possible);
        for(i=0; i<8; i++) //初始化
        {
            a[i]=-1;
        }
        for(i=0; i<p.size; i++) //记录可以吃的兵
        {
            if(abs(Knight.x-p.list[i].x)*abs(Knight.y-p.list[i].y)==2)
            {
                a[j]=i;
                j++;
            }
        }
        if(j==0)
        {
            ++(*k);
            return 0;
        }//如果吃不到，说明失败了
        for(i=0; i<j; i++)
        {
            possible=p;
            ListDelete(&possible,a[i],&NewKnight);
            if(TTM(NewKnight,possible,solution,k))
            {
                StackPush(solution,Knight);
                return 1;
            }
        }
        return 0;
    }
}
int main()
{
    coo Knight,h;
    SeqList p;
    SeqStack solution;
    ListInitiate(&p);
    StackInitiate(&solution);
    int i,j,n,k,a,b;
    char sp[10];
    printf("马的坐标：");
    gets(sp);
    Knight.x=sp[0]-'a'+1;
    Knight.y=sp[1]-'0';///马的坐标
    while(1)
    {
        printf("\n兵的坐标：");
        scanf("%d",&a);
        if(a!=0) scanf("%d",&b);
        n=0;
        while(a!=0)
        {
            if(a!=Knight.x||b!=Knight.y)
            {
                p.list[n].x=a;
                p.list[n].y=b;
                ++n;
            }
            scanf("%d",&a);
            if(a!=0) scanf("%d",&b);
        }
        p.size=n;
        k=1;
        if(TTM(Knight,p,&solution,&k))
        {
            while(StackNotEmpty(solution))
            {
                StackPop(&solution,&h);
                a='a'+h.x-1;
                printf("%c%d->",a,h.y);
            }
            printf("(END)\n这是第%d次尝试\n\n",k);
            Knight.x=h.x;
            Knight.y=h.y;
        }
        else
        {
            printf("计算了%d个情况，无解!!\n\n",k);
            break;
        }
    }
    system("pause");
    return 0;
}

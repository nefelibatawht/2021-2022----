//设计一个算法，要求将顺序表倒置
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR 0
typedef int datatype;
typedef struct node
{
    datatype a[MAXSIZE];
    int size;
} sequence_list;
void init(sequence_list *slt);
void append(sequence_list *slt, datatype x);
void display(sequence_list slt);
void change(sequence_list slt);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    display(slt);
    change(slt);
}

//初始化置空顺序表
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("初始化成功");
}

//从首个节点开始输入一组数据，并且以0为结尾
void append(sequence_list *slt, datatype x)
{
    datatype a;
    slt->a[0] = x;
    slt->size = 1;
    scanf("%d", &a);
    while (a)
    {
        slt->a[slt->size++] = a; //先赋值再自增
        scanf("%d", &a);
    }
}
//打印顺序表各个节点的值
void display(sequence_list slt)
{
    int i;
    if (slt.size == 0)
    {
        printf("顺序表是空");
    }
    else
    {
        for (i = 0; i < slt.size; i++)
        {
            printf("%3d", slt.a[i]);
        }
    }
}
//将所给的顺序表倒置
void change(sequence_list slt)
{
    int i;
    if (slt.size == 0)
    {
        printf("顺序表是空");
    }
    else
    {
        for (i = slt.size - 1; i >= 0; i--)
        {
            printf("%3d", slt.a[i]);
        }
    }
}
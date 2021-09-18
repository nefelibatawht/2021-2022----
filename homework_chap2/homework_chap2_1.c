//设计一个算法，求顺序表中值为x的结点的个数

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
int query(sequence_list *slt, datatype x);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    int count = query(&slt, 3);
    printf("%d", count);
    return 0;
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

//查询值为x的结点个数
int query(sequence_list *slt, datatype x)
{
    int i = 0;
    int count;
    for (i; i < slt->size; i++)
    {
        if (slt->a[i] == x)
        {
            count++;
        }
    }
    return count;
}
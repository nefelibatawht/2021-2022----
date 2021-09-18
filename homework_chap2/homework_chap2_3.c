//已知顺序表中各个节点值从小到大有序，设计一个算法，要求插入一个值为x的结点，使顺序表中结点仍然从小到大有序
/**
 * 2007040136王瀚霆 
 * 第二章第一题
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR 0
#define TRUE 1
//定义顺序表并定义新的类型
typedef int datatype;
typedef struct sequence_list
{
    datatype a[MAXSIZE];
    int size;

} sequence_list;
void init(sequence_list *slt);
void append(sequence_list *slt, datatype x);
void display(sequence_list slt);
int find(sequence_list slt, datatype x);
void insert(sequence_list slt, datatype x);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    display(slt);
    insert(slt, 7);
}
//置空表
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("%s", "置空表成功");
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
//顺序表的插入
int find(sequence_list slt, datatype x)
{
    int i;
    for (i = 0; i < slt.size; i++)
    {
        if (x < slt.a[i])
        {
            return i;
        }
    }
    return i;
}
void insert(sequence_list slt, datatype x)
{
    int p, i;
    p = find(slt, x);
    for (i = slt.size - 1; i >= p; i--)
        slt.a[i + 1] = slt.a[i];
    slt.a[p] = x;
    slt.size++;
    for (i = 0; i < slt.size; i++)
    {
        printf("%3d", slt.a[i]);
    }
}

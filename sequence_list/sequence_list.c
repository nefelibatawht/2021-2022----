//关于顺序表的相关功能

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
int find(sequence_list *slt, datatype x);
void insert(sequence_list *slt, datatype x, int position);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 20);
    display(slt);
    append(&slt, 30);
    append(&slt, 40);
    display(slt);
    find(&slt, 30);
    insert(&slt, 909, 5);
    display(slt);

    return 0;
}

//置空表
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("%s", "置空表成功");
}

//后插加入元素
void append(sequence_list *slt, datatype x)
{
    if (slt->size == MAXSIZE)
    {
        printf("线性表已经满");
        exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
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
//判断顺序表是否为空
int ifEmpty(sequence_list slt)
{
    return (slt.size == 0 ? 0 : 1);
}

//查找顺序表中某个结点的位置
int find(sequence_list *slt, datatype x)
{
    int i = 0;
    if (!slt->size < MAXSIZE)
    {
        exit(1);
    }
    if (slt->a[i] != x)
    {
        i++;
    }
    return (i);
}

//顺序表的插入
void insert(sequence_list *slt, datatype x, int position)
{
    int i;
    if (slt->size > MAXSIZE)
    {
        printf("表已经满");
        exit(1);
    }
    if (position > slt->size || position < 0)
    {
        printf("位置非法");
        exit(1);
    }
    for (i = slt->size; i > position; i--) //在某个位置插入，需要从后面开始到指定位置将结点向后移动
    {
        slt->a[i] = slt->a[i - 1];
    }
    slt->a[position] = x;
    slt->size++;
}

//顺序表的删除
void del(sequence_list *slt, int position)
{
    int i;
    if (slt->size == 0)
    {
        printf("顺序表为空");
        exit(1);
    }
    if (position >= slt->size || position < 0)
    {
        printf("位置非法");
    }
    for (i = position; i < slt->size - 1; i++)
    {
        slt->a[i] = slt->a[i + 1];
    }
    slt->size--;
}

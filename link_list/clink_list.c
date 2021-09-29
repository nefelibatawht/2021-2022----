//循环单链表的实现
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
typedef int datatype;
typedef struct clink_list
{
    datatype info;
    struct clink_list *next;
} node;
void display(node *head);
node *insert(node *head, datatype x, int i);
int main(void)
{
    node *head, *p;
    head = (node *)malloc(sizeof(node));
    head->info = 1;
    p = insert(head, 2, 1);
    display(head);
}

//获得循环链表最后一个节点的存储地址
node *rearAddress(node *head)
{
    node *p;
    if (!head)
    {
        printf("单链表为空");
        exit(1);
    }
    else
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
    }
    return p;
}
//输出循环链表每个结点的值
void display(node *head)
{
    node *p;
    if (!head)
    {
        printf("单链表为空");
    }
    else
    {
        printf("\n各个结点的值是\n");
        printf("%d", head->info);
        p = head->next;
        printf("%d", p->info);
    }
}

//查找循环链表中值为x的结点，返回他的地址
node *find(node *head, datatype x)
{
    node *p;
    if (!head)
    {
        printf("单链表为空");
        exit(1);
    }
    p = head;
    while (p->info != x && p->next != head)
    {
        p = p->next;
    }
    if (p->info == x)
    {
        return p;
    }
    else
    {
        return NULL;
    }
    //为什么还要再判断一遍，因为一旦第二个条件为假，也会退出，但是并没有找到
}
//循环链表在第i位置插入结点
node *insert(node *head, datatype x, int i)
{
    node *p, *q, *myrear; //循环链表还需要考虑最后一个节点
    int j;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    if (i < 0)
    {
        printf("位置值有误");
        free(p);
        return head;
    }
    if (i == 0 && !head)
    {
        p->next = p;
        head = p;
        return head;
    }
    if (i == 0 && head)
    {
        myrear = rearAddress(head);
        p->next = head;
        myrear->next = p;
        return head;
    }
    if (i > 0 && !head)
    {
        printf("没有指定位置");
        free(p);
        return head;
    }
    if (i > 0 && head)
    {
        j = 1;
        q = head;
        while (i != j && q->next != head)
        {
            q = q->next;
            j++;
        } //找遍所有还没有找到指定位置
        if (i != j)
        {
            printf("没有指定位置");
            return head;
        }
        else
        {
            p->next = q->next;
            q->next = p;
            return head;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
typedef int datatype;
typedef struct link_node
{
    datatype info;
    struct link_node *next;
} node;
node *init();
void display(node *head);
void showi(node *head, int i);
node *find(node *head, int i);
int insert(node *head, datatype x, int i);
int dele(node *head, datatype x);

//判断单链表为空的条件：head结点是否为空
int main(void)
{
    node *head, *p;
    head = (node *)malloc(sizeof(node));
    head->info = 0;
    p = head->next;
    showi(head, 1);
    int x = insert(head, 1, 1);
    printf("%d", x);
    showi(head, 2);
}
// 初始化定义一个单链表
node *init()
{
    return NULL;
}

//输出单链表各个节点的值（有问题）
void display(node *head)
{
    node *p;
    p = head;
    if (!p)
    {
        printf("单链表为空");
        exit(1);
    }
    else
    {
        printf("\n单链表各个节点的值为 \n");
        while (p)
        {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}
//查询单链表第i个结点的值
void showi(node *head, int i)
{
    node *p;
    p = head;
    int j = 1;
    if (!p)
    {
        printf("单链表为空");
        exit(1);
    }
    else
    {
        while (j != i && p->next != NULL)
        {
            p = p->next;
            j++;
        }
        printf("第%d个值是%d \n", i, p->info);
    }
}
//查找单链表第i个结点
node *find(node *head, int i)
{
    int j = 1;
    node *p = head;
    if (i < 1)
    {
        return NULL;
    }
    while (p && i != j)
    {
        p = p->next;
        j++;
    }
    return p;
}
//单链表的插入操作
int insert(node *head, datatype x, int i)
{
    node *j;
    j = find(head, i);
    if (!j && i != 0)
    {
        printf("找不到这个节点");
        exit(1);
    }
    else
    {
        node *m;
        m = (node *)malloc(sizeof(node));
        m->info = x;
        if (i == 0)
        {
            m->next = head;
            head = m;
        }
        else
        {
            j->next = m->next;
            j->next = m;
        }
    }
    return TRUE;
}
//删除值为x的结点的操作
int dele(node *head, datatype x)
{
    node *p;
    node *pre = NULL;
    if (!head)
    {
        printf("单链表为空");
        exit(0);
    }
    while (p && p->info != x)
    {
        pre = p;
        p = p->next;
    }
    if (p)
    {
        if (!pre)
        {
            head = head->next;
        }
        else
        {
            pre->next = p->next;
            free(p);
        }
    }
    return TRUE;
}

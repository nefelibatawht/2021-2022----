//判断单链表是否有序
#include <stdio.h>
#include <stdlib.h>
typedef struct link_node
{
    int info;
    struct link_node *next;
} node;

node *init()
{
    return NULL;
}

node *creat(node *head)
{
    node *p, *q;
    int x;
    scanf("%d", &x);
    while (x != -1)
    {
        p = (node *)malloc(sizeof(node));
        p->info = x;
        p->next = NULL;
        if (!head)
        {
            head = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = p;
        }
        scanf("%d", &x);
    }
    return head;
}

void display(node *head)
{
    node *p = head;
    if (head == NULL)
    {
        printf("ERROR\n");
        return;
    }
    while (p)
    {
        printf("%d", p->info);
        p = p->next;
    }
    printf("\n");
}

int length(node *head)
{
    node *p = head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int judge(node *head)
{
    int count1 = 1, count2 = 1, count = 1;
    node *p = head;
    if (!head)
    {
        printf("ERROR\n");
        return 1;
    }
    if (head && !head->next)
    {
        return 1;
    }
    while (p->next)
    {
        if (p->info <= p->next->info)
        {
            count1++;
        }
        if (p->info >= p->next->info)
        {
            count2++;
        }
        p = p->next;
    }
    if (count == count1 || count == count2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    node *head;
    int count = 0;
    head = init();
    head = creat(head);
    display(head);
    if (judge(head))
    {
        printf("有序\n");
    }
    else
    {
        printf("无序\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{
    unsigned int data;
    struct link_list *pre;
    struct link_list *next;
} dnode;

dnode *createLink()
{
    dnode *head, *p, *s;
    int x;
    head = (dnode *)malloc(sizeof(dnode));
    p = head;
    printf("输入数据 \n");
    while (1)
    {

        scanf("%d", &x);
        if (x != 65535)
        {
            s = (dnode *)malloc(sizeof(dnode));
            s->data = x;
            s->pre = p;
            p->next = s;
            p = s;
        }
        else
        {
            break;
        }
    }
    p->next = NULL;
    head = head->next;
    head->pre = NULL;
    return head;
}

void printLink(dnode *head)
{
    dnode *p, *s;
    p = head;
    printf("双向链表序列为：\n");
    while (p)
    {
        printf("%d ", p->data);
        s = p;
        p = p->next;
    }
}
int main(void)
{
    dnode *head;
    head = createLink();
    printLink(head);
    return 0;
}
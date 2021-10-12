//设计一个单链表，在值为y的节点前插入一个值为x的结点
#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
    int num;
    struct link_list *next;

} node;

node *CreatList()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}
node *CreatNode(node *head, int n)
{
    node *p;
    while (n--)
    {
        p = (node *)malloc(sizeof(node));
        if (!p)
        {
            printf("分配结点为空\n");
            exit(1);
        }
        scanf("%d", &p->num);
        head->next = p;
        head = p;
    }
    head->next = NULL;
    return 0;
}

void insert(node *head, int y, int x)
{
    if (!head)
    {
        printf("链表为空");
        exit(1);
    }
    node *pre;
    pre = head;

    node *p;
    p = head->next;
    while (p)
    {
        if (p->num != y)
        {
            p = p->next;
            pre = pre->next;
        }
        break;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->num = x;
    newNode->next = p;
    pre->next = newNode;
}
void ShowList(node *head)
{
    node *p = head->next;
    while (p)
    {
        printf("%d ", p->num);
        p = p->next;
    }
}
int main(void)
{
    node *head;
    head = CreatList();
    CreatNode(head, 4);
    insert(head, 2, 30);
    ShowList(head);
    return 0;
}
//输出单链表的结点个数
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *CreatList()
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}
node *CreatNode(node *head)
{
    int n;
    scanf("%d", &n); //创建结点的个数
    while (n--)
    {
        node *newPoint = (node *)malloc(sizeof(node));
        if (!newPoint)
        {
            printf("分配结点为空\n");
            exit(1);
        }
        scanf("%d", &newPoint->data);
        head->next = newPoint;
        head = newPoint;
    }
    head->next = NULL;
    return 0;
}
void ShowList(struct node *head)
{
    struct node *p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int Length(node *head)
{
    int i = 0;
    struct node *p = head->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
int main(void)
{
    node *head;
    head = CreatList();
    CreatNode(head);
    ShowList(head);
    printf("\n%d", Length(head));
    return 0;
}

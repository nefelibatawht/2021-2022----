//利用原来的链表空间将原来的链表转置
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef struct link_list
{
    int data;
    struct link_list *next;
} Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index)
{
    if (head == NULL)
    {
        if (index != 0)
        {
            return head;
        }
        head = node;
        return head;
    }

    if (index == 0)
    {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1)
    {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1)
    {
        node->next = current_node->next;
        current_node->next = node;
    }
    return head;
}

void out_put(LinkedList head)
{
    if (head == NULL)
    {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL && current_node->data != 'p')
    {
        if (current_node != head)
            printf(" ");
        printf("%c", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList reverse(LinkedList head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *current_node = head->next;
    head->next = NULL;
    Node *next_node;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}
int main(void)
{
    int n;
    int m[MAXSIZE];
    scanf("%d", &n);
    LinkedList linkedlist = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &m[i]);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = m[i];
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i);
    }
    linkedlist = reverse(linkedlist);
    out_put(linkedlist);
    return 0;
}

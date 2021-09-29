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

//�жϵ�����Ϊ�յ�������head����Ƿ�Ϊ��
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
// ��ʼ������һ��������
node *init()
{
    return NULL;
}

//�������������ڵ��ֵ�������⣩
void display(node *head)
{
    node *p;
    p = head;
    if (!p)
    {
        printf("������Ϊ��");
        exit(1);
    }
    else
    {
        printf("\n����������ڵ��ֵΪ \n");
        while (p)
        {
            printf("%5d", p->info);
            p = p->next;
        }
    }
}
//��ѯ�������i������ֵ
void showi(node *head, int i)
{
    node *p;
    p = head;
    int j = 1;
    if (!p)
    {
        printf("������Ϊ��");
        exit(1);
    }
    else
    {
        while (j != i && p->next != NULL)
        {
            p = p->next;
            j++;
        }
        printf("��%d��ֵ��%d \n", i, p->info);
    }
}
//���ҵ������i�����
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
//������Ĳ������
int insert(node *head, datatype x, int i)
{
    node *j;
    j = find(head, i);
    if (!j && i != 0)
    {
        printf("�Ҳ�������ڵ�");
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
//ɾ��ֵΪx�Ľ��Ĳ���
int dele(node *head, datatype x)
{
    node *p;
    node *pre = NULL;
    if (!head)
    {
        printf("������Ϊ��");
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

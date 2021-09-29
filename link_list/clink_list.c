//ѭ���������ʵ��
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

//���ѭ���������һ���ڵ�Ĵ洢��ַ
node *rearAddress(node *head)
{
    node *p;
    if (!head)
    {
        printf("������Ϊ��");
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
//���ѭ������ÿ������ֵ
void display(node *head)
{
    node *p;
    if (!head)
    {
        printf("������Ϊ��");
    }
    else
    {
        printf("\n��������ֵ��\n");
        printf("%d", head->info);
        p = head->next;
        printf("%d", p->info);
    }
}

//����ѭ��������ֵΪx�Ľ�㣬�������ĵ�ַ
node *find(node *head, datatype x)
{
    node *p;
    if (!head)
    {
        printf("������Ϊ��");
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
    //Ϊʲô��Ҫ���ж�һ�飬��Ϊһ���ڶ�������Ϊ�٣�Ҳ���˳������ǲ�û���ҵ�
}
//ѭ�������ڵ�iλ�ò�����
node *insert(node *head, datatype x, int i)
{
    node *p, *q, *myrear; //ѭ��������Ҫ�������һ���ڵ�
    int j;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    if (i < 0)
    {
        printf("λ��ֵ����");
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
        printf("û��ָ��λ��");
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
        } //�ұ����л�û���ҵ�ָ��λ��
        if (i != j)
        {
            printf("û��ָ��λ��");
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
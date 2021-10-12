/* ʵ��һ
����ĳ��ѧ����ͨѶ¼��Ҫ��������洢��
  ���幦�ܰ�����
��1������ʵ�ֲ���һ��ͬѧ��ͨѶ¼��¼��
 	��2���ܹ�ɾ��ĳλͬѧ��ͨѶ¼��
  	��3����ͨѶ¼��ӡ�����
Ҫ��
��1������ͨѶ¼���ݵĽṹ�壻
��2�������洢ͨѶ¼������ṹ����ʼ����                                                 
��3��������������
       1������¼�뺯�������������棩
       2���������뺯�������������棩
       3������ɾ�����������������棩
       4����������ʹ�ӡ���������������棩
            I��ͨ��ѭ�������г�Ա��¼���
           II�����ָ��������ĳ��ͬѧ��ͨѶ¼��¼
       5���˳� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//���롢ɾ�������ѧ����Ϣ��ѧ����Ϣ�������������Ա����䣬ѧ�ţ��绰��
typedef struct Node
{
    int data;
    char name[10];
    char sex[10];
    int old;
    int id;
    long int tel;
    struct Node *next;
} Node, *LinkList;

LinkList creatlist();
void disp(LinkList L);  //չʾ
void del(LinkList L);   //ɾ��
void choose();          //����
void menu();            //��ʾ��Ϣ
void input(LinkList L); //���

int main(void)
{
    choose();
    return 0;
}

void choose()
{
    LinkList L = NULL;
    int n;
    int a = 1;
    while (a > 0) //����˵�ѡ��
    {
        menu();
        printf("��ѡ����:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            L = creatlist();
            break;
        case 2:
            disp(L);
            break;

        case 3:
            del(L);
            break;
        case 4:
            input(L);
            break;
        default:
            a = -1;
            break;
        }
    }
}
//-------------
void menu()
{
    printf("\n\n");
    printf("\t\t ѧ����Ϣ����ϵͳ\n      ");
    printf("\t\t1.����ѧ����Ϣ\n");
    printf("\t\t2.���ѧ����Ϣ\n");
    printf("\t\t3.ɾ��ѧ����Ϣ\n");
    printf("\t\t4.����ѧ����Ϣ\n");
    printf("\t\t5.�˳�\n");
}
LinkList creatlist()
{

    int n;
    LinkList L = (Node *)malloc(sizeof(Node));
    LinkList r = NULL;
    L->next = NULL;
    r = L;
    printf("�����뼸��ѧ����Ϣ��");
    scanf("%d", &n);
    L->data = n;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (Node *)malloc(sizeof(Node)); //p��ʾ�µĽڵ�

        printf("��%d��ѧ��������:\n", i + 1);
        scanf("%s", &p->name);
        printf("��%d��ѧ�����Ա�:\n", i + 1);
        scanf("%s", &p->sex);
        printf("��%d��ѧ��������:\n", i + 1);
        scanf("%d", &p->old);
        printf("��%d��ѧ����ѧ��:\n", i + 1);
        scanf("%d", &p->id);
        printf("��%d��ѧ���ĵ绰:\n", i + 1);
        scanf("%ld", &p->tel);
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return L;
}

void disp(LinkList L)
{

    LinkList p = NULL;
    p = L;
    if (p == NULL)
    {
        printf("�������ݣ�");
    }
    else
    {
        printf("����%d��ѧ����Ϣ��\n", L->data);
        for (int i = 0; i < L->data; i++)
        {
            p = p->next;
            printf("����:%s\n", p->name);
            printf("�Ա�%s\n", p->sex);
            printf("���䣺%d\n", p->old);
            printf("ѧ�ţ�%d\n", p->id);
            printf("�绰��%ld\n", p->tel);
            printf("\n\n");
        }
    }
}

void del(LinkList L)
{
    int a;
    int j = 1;
    int i;
    LinkList p = L;
    LinkList q = NULL;
    if (p == NULL)
    {
        printf("�������ݣ�");
        return;
    }
    if (p != NULL)
    {
        printf("ɾ��ѧ����ѧ����:");
        scanf("%d", &a);
        for (i = 1; i < L->data; i++)
        {
            if (a == p->next->id)
            {
                printf("���ҳɹ���");
                q = p->next;
                p->next = q->next;
                del(q);
                printf("ɾ���ɹ���");
                L->data = L->data - 1;
                break;
            }
            else
            {
                printf("�����ڸ�ѧ�� ��������ѧ���Ƿ�����");
            }
            p = p->next;
        }
    }
}

void input(LinkList L)
{
    LinkList p = L;
    int i;
    int j;
    if (p == NULL)
    {
        printf("����δ����ѧ����Ϣ��");
        return;
    }

    else
    {
        printf("���뵽�ڼ����ڵ㣿");
        scanf("%d", &i);

        if (i > 0 && i <= L->data)
        {
            for (j = 0; j < i - 1; j++)
            {
                p = p->next;
            }
            LinkList s = (LinkList)malloc(sizeof(LinkList));
            printf("����:\n");
            scanf("%s", &p->name);
            printf("�Ա�:\n");
            scanf("%s", &p->sex);
            printf("���䣺\n");
            scanf("%d", &p->old);
            printf("ѧ�ţ�\n");
            scanf("%d", &p->id);
            printf("�绰��\n");
            scanf("%ld", &p->tel);
            s->next = p->next;
            p->next = s;
            L->data = L->data + 1;
        }
        else
            printf("�ڵ㲻���ڣ�");
    }
}

/* 实验一
建立某班学生的通讯录，要求用链表存储。
  具体功能包括：
（1）可以实现插入一个同学的通讯录记录；
 	（2）能够删除某位同学的通讯录；
  	（3）对通讯录打印输出。
要求：
（1）定义通讯录内容的结构体；
（2）建立存储通讯录的链表结构并初始化；                                                 
（3）建立主函数：
       1）建立录入函数（返回主界面）
       2）建立插入函数（返回主界面）
       3）建立删除函数（返回主界面）
       4）建立输出和打印函数（返回主界面）
            I）通过循环对所有成员记录输出
           II）输出指定姓名的某个同学的通讯录记录
       5）退出 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//存入、删除、输出学生信息，学生信息包括：姓名，性别，年龄，学号，电话；
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
void disp(LinkList L);  //展示
void del(LinkList L);   //删除
void choose();          //界面
void menu();            //提示信息
void input(LinkList L); //添加

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
    while (a > 0) //进入菜单选择
    {
        menu();
        printf("请选择功能:");
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
    printf("\t\t 学生信息管理系统\n      ");
    printf("\t\t1.创建学生信息\n");
    printf("\t\t2.输出学生信息\n");
    printf("\t\t3.删除学生信息\n");
    printf("\t\t4.插入学生信息\n");
    printf("\t\t5.退出\n");
}
LinkList creatlist()
{

    int n;
    LinkList L = (Node *)malloc(sizeof(Node));
    LinkList r = NULL;
    L->next = NULL;
    r = L;
    printf("请输入几个学生信息？");
    scanf("%d", &n);
    L->data = n;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (Node *)malloc(sizeof(Node)); //p表示新的节点

        printf("第%d个学生的姓名:\n", i + 1);
        scanf("%s", &p->name);
        printf("第%d个学生的性别:\n", i + 1);
        scanf("%s", &p->sex);
        printf("第%d个学生的年龄:\n", i + 1);
        scanf("%d", &p->old);
        printf("第%d个学生的学号:\n", i + 1);
        scanf("%d", &p->id);
        printf("第%d个学生的电话:\n", i + 1);
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
        printf("暂无数据！");
    }
    else
    {
        printf("共有%d个学生信息！\n", L->data);
        for (int i = 0; i < L->data; i++)
        {
            p = p->next;
            printf("姓名:%s\n", p->name);
            printf("性别：%s\n", p->sex);
            printf("年龄：%d\n", p->old);
            printf("学号：%d\n", p->id);
            printf("电话：%ld\n", p->tel);
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
        printf("暂无数据！");
        return;
    }
    if (p != NULL)
    {
        printf("删除学生的学号是:");
        scanf("%d", &a);
        for (i = 1; i < L->data; i++)
        {
            if (a == p->next->id)
            {
                printf("查找成功！");
                q = p->next;
                p->next = q->next;
                del(q);
                printf("删除成功！");
                L->data = L->data - 1;
                break;
            }
            else
            {
                printf("不存在该学生 请检查输入学号是否有误！");
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
        printf("您还未创建学生信息！");
        return;
    }

    else
    {
        printf("插入到第几个节点？");
        scanf("%d", &i);

        if (i > 0 && i <= L->data)
        {
            for (j = 0; j < i - 1; j++)
            {
                p = p->next;
            }
            LinkList s = (LinkList)malloc(sizeof(LinkList));
            printf("姓名:\n");
            scanf("%s", &p->name);
            printf("性别:\n");
            scanf("%s", &p->sex);
            printf("年龄：\n");
            scanf("%d", &p->old);
            printf("学号：\n");
            scanf("%d", &p->id);
            printf("电话：\n");
            scanf("%ld", &p->tel);
            s->next = p->next;
            p->next = s;
            L->data = L->data + 1;
        }
        else
            printf("节点不存在！");
    }
}

#include <stdio.h> 
#include <stdlib.h> 
typedef struct node
{
    char data;
    struct node* next;
} linkstrnode;
typedef linkstrnode* linkstring;

linkstring copy(linkstring head)
{
    linkstring L = NULL, r = NULL, s, p;
    p = head;
    while (p)
    {
        s = (linkstring)malloc(sizeof(linkstrnode));
        s->data = p->data;
        if (L == NULL) L = r = s;
        else
        {
            r->next = s;
            r = s;
        }
        p = p->next;
    }
    if (r != NULL) r->next = NULL;
    return L;
}

void strcreate(linkstring* S)
{
    char ch;
    linkstrnode* p, * r;
    *S = NULL; r = NULL;
    while ((ch = getchar()) != '\n')
    {
        p = (linkstrnode*)malloc(sizeof(linkstrnode));
        p->data = ch;
        if (*S == NULL)
        {
            *S = p; r = p;
        }
        else {
            r->next = p;
            r = p;
        }
    }
    if (r != NULL) r->next = NULL;
}

void print(linkstring head)
{
    linkstrnode* p;
    p = head;
    while (p)
    {
        printf("%c-->", p->data);
        p = p->next;
    }
    printf("\n");
}

// 在字符串S中用T2替换T1 
linkstring replace(linkstring S, linkstring T1, linkstring T2)
{
    linkstring p, q, r, s, pre, temp, pos;
    int flag = 1;
    if (S == NULL || T1 == NULL) return S; //若S为空或T1为空,则原串不变
    pre = NULL;
    pos = S; //pos表示可能的T1串在S中的起始位置
    while (pos && flag) //flag表示S中存在T1
    {
        p = pos;
        q = T1;
        while (p && q) //从pos开始找子串T1
        {
            if (p->data == q->data)
            {
                p = p->next; q = q->next;
            }
            else
            {
                pre = pos;
                pos = pos->next;
                p = pos;
                q = T1;
            }
        }
        if (q != NULL) flag = 0; //*未找到子串T1
        else
        {
            flag = 1; //*找到了子串T1,用T2代替T1
            r = pos;
            while (r != p) //*首先删除子串T1,最后p指向删除串T1的下一个结点
            {
                s = r;
                r = r->next;
                free(s);
            }
            if (T2 != NULL)// /*T2不为空
            {
                temp = r = copy(T2);// /*复制一个T2串
                while (r->next != NULL) ///*找temp串的尾结点
                    r = r->next;
                r->next = p;
                if (pre == NULL)// /*如果T1出现在S的链头
                    S = temp;// /*新串成为链首
                else// /*T1不是链首串
                    pre->next = temp;
                pre = r;
                pos = p;// /*从p开始继续找子串T1
            }
            else// /*原T2子串为空
            {
                if (pre == NULL) //*T1为链首
                    S = p;
                else
                    pre->next = p;
                pos = p;
            }
        }
    }
    return S;
}
int main()
{
    linkstring S, T1, T2;
    printf("\n input S:");
    strcreate(&S); //*建立字符串S
    print(S);
    printf("\n input T1:");
    strcreate(&T1); //*建立字符串T1
    print(T1);
    printf("\n input T2:");
    strcreate(&T2);//*建立字符串T2
    print(T2);
    S = replace(S, T1, T2);
    printf("\n最终结果是:\n");
    print(S);
}
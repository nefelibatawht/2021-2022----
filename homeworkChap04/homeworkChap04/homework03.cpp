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

// ���ַ���S����T2�滻T1 
linkstring replace(linkstring S, linkstring T1, linkstring T2)
{
    linkstring p, q, r, s, pre, temp, pos;
    int flag = 1;
    if (S == NULL || T1 == NULL) return S; //��SΪ�ջ�T1Ϊ��,��ԭ������
    pre = NULL;
    pos = S; //pos��ʾ���ܵ�T1����S�е���ʼλ��
    while (pos && flag) //flag��ʾS�д���T1
    {
        p = pos;
        q = T1;
        while (p && q) //��pos��ʼ���Ӵ�T1
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
        if (q != NULL) flag = 0; //*δ�ҵ��Ӵ�T1
        else
        {
            flag = 1; //*�ҵ����Ӵ�T1,��T2����T1
            r = pos;
            while (r != p) //*����ɾ���Ӵ�T1,���pָ��ɾ����T1����һ�����
            {
                s = r;
                r = r->next;
                free(s);
            }
            if (T2 != NULL)// /*T2��Ϊ��
            {
                temp = r = copy(T2);// /*����һ��T2��
                while (r->next != NULL) ///*��temp����β���
                    r = r->next;
                r->next = p;
                if (pre == NULL)// /*���T1������S����ͷ
                    S = temp;// /*�´���Ϊ����
                else// /*T1�������״�
                    pre->next = temp;
                pre = r;
                pos = p;// /*��p��ʼ�������Ӵ�T1
            }
            else// /*ԭT2�Ӵ�Ϊ��
            {
                if (pre == NULL) //*T1Ϊ����
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
    strcreate(&S); //*�����ַ���S
    print(S);
    printf("\n input T1:");
    strcreate(&T1); //*�����ַ���T1
    print(T1);
    printf("\n input T2:");
    strcreate(&T2);//*�����ַ���T2
    print(T2);
    S = replace(S, T1, T2);
    printf("\n���ս����:\n");
    print(S);
}
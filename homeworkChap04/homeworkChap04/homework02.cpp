#include <stdio.h> 
#include <stdlib.h> 
typedef struct node
{
    char data;
    struct node* next;
} linkstrnode;
typedef linkstrnode* linkstring;

/* β�巨���������� */
void strcreate(linkstring* S)
{
    char ch;
    linkstrnode* p, * r;
    *S = NULL; r = NULL;
    while ((ch = getchar()) != '\n')
    {
        p = (linkstrnode*)malloc(sizeof(linkstrnode));
        p->data = ch; /*�����½��*/
        if (*S == NULL) /*�½�����ձ�
        */
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
/*�������������� */
void print(linkstring head)
{
    linkstrnode* p;
    p = head;
    while (p)
    {
        printf("%c->", p->data);
        p = p->next;
    }
    printf("\n");
}
int strcompare(linkstrnode* S1, linkstrnode* S2)
{
    while (S1 && S2)
    {
        if (S1->data > S2->data)
            return 1;
        else if (S1->data < S2->data)
            return -1;
        S1 = S1->next;
        S2 = S2->next;
    }
    if (S1) return 1;
    else if (S2) return -1;
    return 0;
}
int main(void)
{
    linkstring s1, s2;
    int k;
    printf("\n�����ַ���1:");
    strcreate(&s1); /*�����ַ���
    s1*/
    print(s1);
    printf("\n�����ַ���2:");
    strcreate(&s2); /*�����ַ���
    s2*/
    print(s2);
    k = strcompare(s1, s2);
    if (k == 1) printf("s1>s2");
    else
        if (k == -1)printf("s1<s2");
        else
            printf("s1==s2");
}
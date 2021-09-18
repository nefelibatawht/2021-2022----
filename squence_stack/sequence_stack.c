#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define EMPTY 1
#define NOTEMPTY 0

//�м�ջ��ջ����MAXSIZE-1
typedef int datatype;
typedef struct node
{
    datatype a[MAXSIZE];
    int top;
} sequence_stack;
void init(sequence_stack *st);
int empty(sequence_stack st);
datatype read(sequence_stack st);
void push(sequence_stack *st, datatype x);
void pop(sequence_stack *st);

int main(void)
{
    sequence_stack st;

    init(&st);
    int x = empty(st);
    printf("%d", x);
    printf("\n\n");
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    datatype r = read(st);
    printf("%d", r);
    push(&st, 6);
    pop(&st);
}

//ջ�ĳ�ʼ��
void init(sequence_stack *st)
{
    st->top = -1;
}

//�ж��Ƿ��ǿ�ջ
int empty(sequence_stack st)
{
    return (st.top == -1 ? 1 : 0); //��1��ʾ�գ�0��ʾ�ǿ�
}

//����ջ���洢��ֵ
datatype read(sequence_stack st)
{
    if (empty(st))
    {
        printf("ջ��");
        exit(1);
    }
    return st.a[st.top];
}
//��ջpush����
void push(sequence_stack *st, datatype x)
{
    if (st->top == MAXSIZE)
    {
        printf("ջ��");
    }

    st->top++;
    st->a[st->top] = x;
}
//��ջpop����
void pop(sequence_stack *st)
{
    if (st->top == -1)
    {
        printf("ջ��");
    }
    //if(empty(&st))

    st->top--;
}
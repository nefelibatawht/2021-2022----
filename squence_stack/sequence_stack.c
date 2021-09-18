#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define EMPTY 1
#define NOTEMPTY 0

//切记栈的栈顶是MAXSIZE-1
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

//栈的初始化
void init(sequence_stack *st)
{
    st->top = -1;
}

//判断是否是空栈
int empty(sequence_stack st)
{
    return (st.top == -1 ? 1 : 0); //用1表示空，0表示非空
}

//读出栈顶存储的值
datatype read(sequence_stack st)
{
    if (empty(st))
    {
        printf("栈空");
        exit(1);
    }
    return st.a[st.top];
}
//进栈push操作
void push(sequence_stack *st, datatype x)
{
    if (st->top == MAXSIZE)
    {
        printf("栈满");
    }

    st->top++;
    st->a[st->top] = x;
}
//出栈pop操作
void pop(sequence_stack *st)
{
    if (st->top == -1)
    {
        printf("栈空");
    }
    //if(empty(&st))

    st->top--;
}
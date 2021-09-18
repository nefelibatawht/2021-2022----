//顺序队列
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define FULL 1
#define NOTFULL 0
typedef int datatype;
typedef struct node
{
    datatype a[MAXSIZE];
    int front;
    int rear;

} sequence_queue;

void init(sequence_queue *sq);
int empty(sequence_queue *sq);
void display(sequence_queue sq);
datatype read(sequence_queue sq);
void insert(sequence_queue *sq, datatype x);
int del(sequence_queue *sq);
int main(void)
{
    sequence_queue sq;
    init(&sq);
    int x = empty(&sq);
    printf("\n");
    printf("%d\n", x);
    insert(&sq, 1);
    insert(&sq, 2);
    insert(&sq, 3);
    insert(&sq, 4);
    insert(&sq, 5);
    int y = read(sq);
    printf("%d\n", y);
    display(sq);
    printf("\n");
    int z = del(&sq);
    printf("%d\n", z);
    display(sq);
}
//顺序队列的初始化
void init(sequence_queue *sq)
{
    sq->front = sq->rear = -1;
}
//顺序队列的查询是否为空
int empty(sequence_queue *sq)
{
    return (sq->front == sq->rear ? FULL : NOTFULL);
}
//顺序队列打印队列存储的值
void display(sequence_queue sq)
{
    if (empty(&sq))
    {
        printf("队列为空");
        exit(1);
    }
    for (int i = sq.front; i < sq.rear; i++)
    {
        printf("%d", sq.a[i]);
    }
}

//读取队列队首的值
datatype read(sequence_queue sq)
{
    if (empty(&sq))
    {
        printf("队列是空");
        exit(1);
    }
    return sq.a[sq.front];
}
//顺序队列的入队操作
void insert(sequence_queue *sq, datatype x)
{
    if (sq->rear == MAXSIZE)
    {
        printf("队列满");
        exit(1);
    }
    sq->rear++;
    sq->a[sq->rear] = x;
    while (sq->front == -1)
    {
        sq->front = 0;
    }

    // sq->rear = sq->rear + 1;
}
//顺序队列的出队操作
int del(sequence_queue *sq)
{
    if (empty(sq))
    {
        printf("队列为空");
        exit(1);
    }
    sq->front++;
    return TRUE;
}

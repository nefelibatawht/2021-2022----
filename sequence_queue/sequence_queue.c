//˳�����
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
//˳����еĳ�ʼ��
void init(sequence_queue *sq)
{
    sq->front = sq->rear = -1;
}
//˳����еĲ�ѯ�Ƿ�Ϊ��
int empty(sequence_queue *sq)
{
    return (sq->front == sq->rear ? FULL : NOTFULL);
}
//˳����д�ӡ���д洢��ֵ
void display(sequence_queue sq)
{
    if (empty(&sq))
    {
        printf("����Ϊ��");
        exit(1);
    }
    for (int i = sq.front; i < sq.rear; i++)
    {
        printf("%d", sq.a[i]);
    }
}

//��ȡ���ж��׵�ֵ
datatype read(sequence_queue sq)
{
    if (empty(&sq))
    {
        printf("�����ǿ�");
        exit(1);
    }
    return sq.a[sq.front];
}
//˳����е���Ӳ���
void insert(sequence_queue *sq, datatype x)
{
    if (sq->rear == MAXSIZE)
    {
        printf("������");
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
//˳����еĳ��Ӳ���
int del(sequence_queue *sq)
{
    if (empty(sq))
    {
        printf("����Ϊ��");
        exit(1);
    }
    sq->front++;
    return TRUE;
}

//���һ���㷨��Ҫ��˳�����
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR 0
typedef int datatype;
typedef struct node
{
    datatype a[MAXSIZE];
    int size;
} sequence_list;
void init(sequence_list *slt);
void append(sequence_list *slt, datatype x);
void display(sequence_list slt);
void change(sequence_list slt);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    display(slt);
    change(slt);
}

//��ʼ���ÿ�˳���
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("��ʼ���ɹ�");
}

//���׸��ڵ㿪ʼ����һ�����ݣ�������0Ϊ��β
void append(sequence_list *slt, datatype x)
{
    datatype a;
    slt->a[0] = x;
    slt->size = 1;
    scanf("%d", &a);
    while (a)
    {
        slt->a[slt->size++] = a; //�ȸ�ֵ������
        scanf("%d", &a);
    }
}
//��ӡ˳�������ڵ��ֵ
void display(sequence_list slt)
{
    int i;
    if (slt.size == 0)
    {
        printf("˳����ǿ�");
    }
    else
    {
        for (i = 0; i < slt.size; i++)
        {
            printf("%3d", slt.a[i]);
        }
    }
}
//��������˳�����
void change(sequence_list slt)
{
    int i;
    if (slt.size == 0)
    {
        printf("˳����ǿ�");
    }
    else
    {
        for (i = slt.size - 1; i >= 0; i--)
        {
            printf("%3d", slt.a[i]);
        }
    }
}
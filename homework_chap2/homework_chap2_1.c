//���һ���㷨����˳�����ֵΪx�Ľ��ĸ���

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
int query(sequence_list *slt, datatype x);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    int count = query(&slt, 3);
    printf("%d", count);
    return 0;
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

//��ѯֵΪx�Ľ�����
int query(sequence_list *slt, datatype x)
{
    int i = 0;
    int count;
    for (i; i < slt->size; i++)
    {
        if (slt->a[i] == x)
        {
            count++;
        }
    }
    return count;
}
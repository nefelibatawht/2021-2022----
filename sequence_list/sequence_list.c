//����˳������ع���

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR 0
#define TRUE 1
//����˳��������µ�����
typedef int datatype;
typedef struct sequence_list
{
    datatype a[MAXSIZE];
    int size;

} sequence_list;
void init(sequence_list *slt);
void append(sequence_list *slt, datatype x);
void display(sequence_list slt);
int find(sequence_list *slt, datatype x);
void insert(sequence_list *slt, datatype x, int position);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 20);
    display(slt);
    append(&slt, 30);
    append(&slt, 40);
    display(slt);
    find(&slt, 30);
    insert(&slt, 909, 5);
    display(slt);

    return 0;
}

//�ÿձ�
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("%s", "�ÿձ�ɹ�");
}

//������Ԫ��
void append(sequence_list *slt, datatype x)
{
    if (slt->size == MAXSIZE)
    {
        printf("���Ա��Ѿ���");
        exit(1);
    }
    slt->a[slt->size] = x;
    slt->size = slt->size + 1;
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
//�ж�˳����Ƿ�Ϊ��
int ifEmpty(sequence_list slt)
{
    return (slt.size == 0 ? 0 : 1);
}

//����˳�����ĳ������λ��
int find(sequence_list *slt, datatype x)
{
    int i = 0;
    if (!slt->size < MAXSIZE)
    {
        exit(1);
    }
    if (slt->a[i] != x)
    {
        i++;
    }
    return (i);
}

//˳���Ĳ���
void insert(sequence_list *slt, datatype x, int position)
{
    int i;
    if (slt->size > MAXSIZE)
    {
        printf("���Ѿ���");
        exit(1);
    }
    if (position > slt->size || position < 0)
    {
        printf("λ�÷Ƿ�");
        exit(1);
    }
    for (i = slt->size; i > position; i--) //��ĳ��λ�ò��룬��Ҫ�Ӻ��濪ʼ��ָ��λ�ý��������ƶ�
    {
        slt->a[i] = slt->a[i - 1];
    }
    slt->a[position] = x;
    slt->size++;
}

//˳����ɾ��
void del(sequence_list *slt, int position)
{
    int i;
    if (slt->size == 0)
    {
        printf("˳���Ϊ��");
        exit(1);
    }
    if (position >= slt->size || position < 0)
    {
        printf("λ�÷Ƿ�");
    }
    for (i = position; i < slt->size - 1; i++)
    {
        slt->a[i] = slt->a[i + 1];
    }
    slt->size--;
}

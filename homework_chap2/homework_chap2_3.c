//��֪˳����и����ڵ�ֵ��С�����������һ���㷨��Ҫ�����һ��ֵΪx�Ľ�㣬ʹ˳����н����Ȼ��С��������
/**
 * 2007040136����� 
 * �ڶ��µ�һ��
 */

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
int find(sequence_list slt, datatype x);
void insert(sequence_list slt, datatype x);
int main(void)
{
    sequence_list slt;
    init(&slt);
    append(&slt, 3);
    display(slt);
    insert(slt, 7);
}
//�ÿձ�
void init(sequence_list *slt)
{
    slt->size = 0;
    printf("%s", "�ÿձ�ɹ�");
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
//˳���Ĳ���
int find(sequence_list slt, datatype x)
{
    int i;
    for (i = 0; i < slt.size; i++)
    {
        if (x < slt.a[i])
        {
            return i;
        }
    }
    return i;
}
void insert(sequence_list slt, datatype x)
{
    int p, i;
    p = find(slt, x);
    for (i = slt.size - 1; i >= p; i--)
        slt.a[i + 1] = slt.a[i];
    slt.a[p] = x;
    slt.size++;
    for (i = 0; i < slt.size; i++)
    {
        printf("%3d", slt.a[i]);
    }
}

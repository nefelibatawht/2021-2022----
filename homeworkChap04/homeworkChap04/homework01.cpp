//˳��洢ʵ��replace(S,T1,T2)
#include<stdio.h>
#include<malloc.h>

#define MaxSize 100

typedef struct
{
	char data[MaxSize];
	int length;			//����
} SqString;

void GetNext(SqString t, int next[])		//��ģʽ��t���nextֵ
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;//��һ���ַ�ǰ���ַ�������ֵ-1
	while (j < t.length - 1)
		//��Ϊnext������j���Ϊt.length-1,��ÿһ��next���鸳ֵ������j++֮��
		//�������һ�ξ���whileѭ��ʱjΪt.length-2
	{
		if (k == -1 || t.data[j] == t.data[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
		{
			j++; k++;
			next[j] = k;
			//��Ӧ�ַ�ƥ������£�s��tָ��ͬ������
			//ͨ���ַ���"aaaaab"��next���������һ����һ��������
			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
		}
		else
		{
			k = next[k];
			//��������֪��next[k]��ֵ��������±�Ϊk���ַ�ǰ����ַ�������ǰ��׺�ĳ���
			//Ҳ��ʾ�ô��ַ���ƥ��ʱӦ�û��ݵ����ַ����±�
			//���ֵ��k���ֽ���whileѭ���жϣ���ʱt.data[k]��ָ����ǰ׺��һ���ַ�**
			//ΪʲôҪ���˴˴����бȽϣ��������½��ſ�����ʵԭ���������ܵ�KMPԭ����
			//printf("(2) k=%d\n",k);
		}
	}
}

int KMPIndex(SqString s, SqString t)  //KMP�㷨
{

	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++; j++;  			//i,j����1
		}
		else j = next[j]; 		//i����,j���ˣ�����֪��Ϊʲô�������Ӵ������˰�
	}
	if (j >= t.length)
		return(i - t.length);  	//����ƥ��ģʽ�������ַ��±�
	else
		return(-1);        		//���ز�ƥ���־
}

SqString replace(SqString sq, SqString a, SqString b)
{
	int i = KMPIndex(sq, a);
	int j;
	j = 0;
	if (a.length == b.length)
	{
		while (j < a.length)
		{
			sq.data[i + j] = b.data[j];
			j++;
		}
	}
	else if (a.length > b.length)
	{
		while (j < b.length)
		{
			sq.data[i + j] = b.data[j];
			j++;
		}
		while (i + j < sq.length + a.length - b.length)
		{
			sq.data[i + j] = sq.data[i + j + b.length];
			j++;
		}
	}
	else
	{
		j = sq.length + b.length - a.length;
		while (j > i + b.length - 1)
		{
			sq.data[j] = sq.data[j - b.length + a.length];
			j--;
		}
		j = 0;
		while (j < b.length)
		{
			sq.data[i + j] = b.data[j];
			j++;
		}

	}
	sq.length = sq.length + b.length - a.length;
	return sq;
}

int main()
{
	SqString sq = { "abcfdeffabcd1234567890",21 };
	SqString a = { "abcd",4 };
	SqString b = { "aaaaaa", 6 };
	//printf("%d", KMPIndex(sq, a));
	// aΪҪ���滻�Ĵ� bΪ�����滻�Ĵ�
	sq = replace(sq, a, b);
	printf("%s", sq.data);
	printf("\n%d\n", sq.length);
	SqString c = { "aa", 2 };
	SqString sq1 = { "abcfdeffabcd1234567890",21 };
	sq1 = replace(sq1, a, c);
	printf("%s", sq1.data);
	printf("\n%d\n", sq1.length);
	return 0;
}
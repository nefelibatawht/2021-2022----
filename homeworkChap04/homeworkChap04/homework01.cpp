//顺序存储实现replace(S,T1,T2)
#include<stdio.h>
#include<malloc.h>

#define MaxSize 100

typedef struct
{
	char data[MaxSize];
	int length;			//串长
} SqString;

void GetNext(SqString t, int next[])		//由模式串t求出next值
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;//第一个字符前无字符串，给值-1
	while (j < t.length - 1)
		//因为next数组中j最大为t.length-1,而每一步next数组赋值都是在j++之后
		//所以最后一次经过while循环时j为t.length-2
	{
		if (k == -1 || t.data[j] == t.data[k]) 	//k为-1或比较的字符相等时
		{
			j++; k++;
			next[j] = k;
			//对应字符匹配情况下，s与t指向同步后移
			//通过字符串"aaaaab"求next数组过程想一下这一步的意义
			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,k);
		}
		else
		{
			k = next[k];
			//我们现在知道next[k]的值代表的是下标为k的字符前面的字符串最长相等前后缀的长度
			//也表示该处字符不匹配时应该回溯到的字符的下标
			//这个值给k后又进行while循环判断，此时t.data[k]即指最长相等前缀后一个字符**
			//为什么要回退此处进行比较，我们往下接着看。其实原理和上面介绍的KMP原理差不多
			//printf("(2) k=%d\n",k);
		}
	}
}

int KMPIndex(SqString s, SqString t)  //KMP算法
{

	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++; j++;  			//i,j各增1
		}
		else j = next[j]; 		//i不变,j后退，现在知道为什么这样让子串回退了吧
	}
	if (j >= t.length)
		return(i - t.length);  	//返回匹配模式串的首字符下标
	else
		return(-1);        		//返回不匹配标志
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
	// a为要被替换的串 b为进行替换的串
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
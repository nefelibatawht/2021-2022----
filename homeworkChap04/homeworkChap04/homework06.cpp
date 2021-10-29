#include<stdio.h>
typedef struct
{
    int data[100][100];
    int m, n;
}matrix;
typedef int spmatrix[100][3]; //三元组存储结构 
spmatrix c;
void add(spmatrix a, spmatrix b, spmatrix c) //基于三元组结构的矩阵相加算法
{
    int i, j, k, t, r;
    i = j = k = 1;
    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else
            if (a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1]))
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                j++; k++;
            }
            else
                if (a[i][0] == b[j][0] && (a[i][1] == b[j][1]))
                {
                    c[k][0] = a[i][0];
                    c[k][1] = a[i][1];
                    c[k][2] = a[i][2] + b[j][2];
                    i++; j++;
                    if (c[k][2] != 0) k++; //如果相加0,则生成一个有效项

                }
    }
    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }
    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k - 1;
}
//函数 compressmatrix将普通矩阵存储转换为三元组存储结构
void compressmatrix(matrix* A, spmatrix B)
{
    int i, j, k;
    k = 1;
    for (i = 0; i < A->m; i++)
        for (j = 0; j < A->n; j++)
            if (A->data[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A->data[i][j];
                k++;
            }
    B[0][0] = A->m;
    B[0][1] = A->n;
    B[0][2] = k - 1;
    i = 0;
    printf("the spmatrix is:\n");
    while (i <= B[0][2])
    {
        printf("%d%5d%5d\n", B[i][0], B[i][1], B[i][2]);
        i++;
    }
}
void creat(int r, int w, matrix* s)
{
    int i, j, data;
    printf("input numbers:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < w; j++)
        {
            scanf_s("%d", &data);
            s->data[i][j] = data;
        }
    printf("the array is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < w; j++)
            printf("%5d", s->data[i][j]);
        printf("\n");
    }
    s->m = r;
    s->n = w;
}
int main()
{
    matrix p, q;
    spmatrix a, b, c;
    int r, w, i
        ;
    i = 0;
    printf("input r,w:"); //输入行和列
    scanf_s("%d%d", &r, &w);
    creat(r, w, &p);
    creat(r, w, &q);
    compressmatrix(&p, a);
    compressmatrix(&q, b);
    i = 0;
    add(a, b, c);
    printf("the spmatrix c is:\n");
    while (i <= c[0][2])
    {
        printf("%d%5d%5d\n", c[i][0], c[i][1], c[i][2]);
        i++;
    }
}
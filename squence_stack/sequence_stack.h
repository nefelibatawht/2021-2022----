#define MAXSIZE 100
#define EMPTY 1
#define NOTEMPTY 0

//ÇÐ¼ÇÕ»µÄÕ»¶¥ÊÇMAXSIZE-1
typedef int datatype;
typedef struct node
{
    datatype a[MAXSIZE];
    int top;
} sequence_stack;

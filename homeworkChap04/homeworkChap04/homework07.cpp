#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next[100];
void get_next(char s[])
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    int len = strlen(s);
    while (i < len - 1)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int KMP(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    while (i < len1 && j < len2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= len2)
        return i - len2 + 1;
    else
        return -1;
}
int main(void) {
    char s[100] = "ababbaabaa";
    char p[50] = "aab";
    get_next(p);
    int k = KMP(s, p);
    printf("%d", k);




}

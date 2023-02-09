#include <stdio.h>

int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    int temp1[100000], temp2[100000];
    for (int i = 0; i < 100000; i++)
    {
        temp1[i] = 0;
        temp2[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp1[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        temp2[b[i]]++;
    }
    for (int i = 0; i < 100000; i++)
    {
        if (temp1[i] != temp2[i])
        {
            flag = 1;
        }
    }

    if (flag == 1)
        printf("0\n");
    else
        printf("1\n");
    return 0;
}


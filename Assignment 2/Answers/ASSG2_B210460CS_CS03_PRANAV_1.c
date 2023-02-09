#include <stdio.h>
#include <string.h>

struct student
{
    char name[1000];
    char rollNo[1000];
    int age;
};

struct nameEquivalent
{
    char name[1000];
    int val;
    char branch[1000];
};

int main()
{
    char ch, dept[100];
    int n, q;
    scanf("%d", &n);
    struct student s[n];
    struct nameEquivalent ans[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i].name);
        scanf("%s", s[i].rollNo);
        scanf("%d", &s[i].age);
    }

    int val = 0, k = 0, count = 0;
    int nameEquivalent[10000];
    for (int i = 0; i < 10000; i++)
    {
        nameEquivalent[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        val = 0;
        for (int j = 0; j < strlen(s[i].name); j++)
        {
            val = val + (int)s[i].name[j];
        }
        ans[k].val = (val + s[i].age) % 4;
        strcpy(ans[k].name, s[i].name);
        if ((s[i].rollNo[7] == 'C' && s[i].rollNo[8] == 'S') || (s[i].rollNo[7] == 'c' && s[i].rollNo[8] == 's'))
            strcpy(ans[k].branch, "CS");
        if ((s[i].rollNo[7] == 'E' && s[i].rollNo[8] == 'C') || (s[i].rollNo[7] == 'e' && s[i].rollNo[8] == 'c'))
            strcpy(ans[k].branch, "EC");
        if ((s[i].rollNo[7] == 'E' && s[i].rollNo[8] == 'E') || (s[i].rollNo[7] == 'e' && s[i].rollNo[8] == 'e'))
            strcpy(ans[k].branch, "EE");
        if ((s[i].rollNo[7] == 'C' && s[i].rollNo[8] == 'E') || (s[i].rollNo[7] == 'c' && s[i].rollNo[8] == 'e'))
            strcpy(ans[k].branch, "CE");
        k++;
    }

    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'c':
            scanf("%d", &q);
            count = 0;
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q)
                {
                    count++;
                }
            }
            printf("%d ", count);
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q)
                {
                    printf("%s ", ans[i].name);
                }
            }
            printf("\n");
            break;

        case '1':
            count = 0;
            q = 1;
            scanf("%s", dept);
            if (dept[0] >= 97 && dept[0] <= 122)
                dept[0] -= 32;
            if (dept[1] >= 97 && dept[1] <= 122)
                dept[1] -= 32;
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                {
                    count++;
                }
            }
            if (count == 0)
                printf("-1");
            else
                printf("%d ", count);
            for (int i = 0; i < k; i++)
            {
                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                    printf("%s ", ans[i].name);
            }
            printf("\n");
            break;
        case '2':
            count = 0;
            q = 2;
            scanf("%s", dept);
            if (dept[0] >= 97 && dept[0] <= 122)
                dept[0] -= 32;
            if (dept[1] >= 97 && dept[1] <= 122)
                dept[1] -= 32;
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                {
                    count++;
                }
            }
            if (count == 0)
                printf("-1");
            else
                printf("%d ", count);
            for (int i = 0; i < k; i++)
            {
                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                    printf("%s ", ans[i].name);
            }
            printf("\n");
            break;
        case '3':
            count = 0;
            q = 3;
            scanf("%s", dept);
            if (dept[0] >= 97 && dept[0] <= 122)
                dept[0] -= 32;
            if (dept[1] >= 97 && dept[1] <= 122)
                dept[1] -= 32;
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                {
                    count++;
                }
            }
            if (count == 0)
                printf("-1");
            else
                printf("%d ", count);
            for (int i = 0; i < k; i++)
            {
                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                    printf("%s ", ans[i].name);
            }
            printf("\n");
            break;
        case '4':
            count = 0;
            q = 4;
            scanf("%s", dept);
            if (dept[0] >= 97 && dept[0] <= 122)
                dept[0] -= 32;
            if (dept[1] >= 97 && dept[1] <= 122)
                dept[1] -= 32;
            for (int i = 0; i < k; i++)
            {

                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                {
                    count++;
                }
            }
            if (count == 0)
                printf("-1");
            else
                printf("%d ", count);
            for (int i = 0; i < k; i++)
            {
                if (ans[i].val == q && strcmp(ans[i].branch, dept) == 0)
                    printf("%s ", ans[i].name);
            }
            printf("\n");
            break;
        case 'e':
            return 0;
            break;
        }
    } while (ch != 'e');
    return 0;
}


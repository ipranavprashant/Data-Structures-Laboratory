#include <stdio.h>
#include <stdlib.h>

int count = 0;
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct binaryTree
{
    struct Node *root;
};

struct Node *buildTree(char *str)
{
    int temp, key, i;
    char k[1000];
    str = str + 2;

    if (*str == ')')
    {
        return NULL;
    }

    i = 0;
    while ((*str >= '0' && *str <= '9') || (*str == '-'))
    {
        k[i++] = *str;
        str++;
    }
    k[i] = '\0';
    key = atoi(k);

    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = key;
    str++;
    ptr->lchild = buildTree(str);
    str++;

    temp = 1;
    while (temp != 0)
    {
        if (*str == '(')
            temp++;
        else if (*str == ')')
            temp--;
        str++;
    }
    str++;
    ptr->rchild = buildTree(str);
    return ptr;
}

int summation(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (root->data + summation(root->lchild) + summation(root->rchild));
    }
    return -1;
}

int countAnswer(struct Node *root, int target)
{
    if (root == NULL)
    {
        return 0;
    }
    if (summation(root->lchild) == target)
        count++;
    if (summation(root->rchild) == target)
        count++;

    return count;
}

int main()
{
    char str[10000];
    scanf("%[^\n]s", str);
    struct binaryTree *bt;
    bt = (struct binaryTree *)malloc(sizeof(struct binaryTree));
    bt->root = buildTree(str);

    int answer, target;
    scanf("%d", &target);
    answer = countAnswer(bt->root, target);
    printf("%d\n", answer);

    return 0;
}


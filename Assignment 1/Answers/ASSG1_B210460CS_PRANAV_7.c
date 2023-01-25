#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int k;
    struct Node *left;
    struct Node *right;
};

struct BinaryTree
{
    struct Node *root;
};

struct Node *BUILD_TREE(char *str)
{
    int key, temp, i;
    char k[1000];

    str += 2; // skip ( and space

    if (*str == ')')
    {
        return NULL;
    }

    // extract integer key
    i = 0;
    while ((*str >= '0' && *str <= '9') || *str == '-') // if number or -, extract
    {
        k[i++] = *str;
        str++;
    }
    k[i] = '\0'; // end of string

    key = atoi(k); // convert string to integer

    struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // create new node
    node->k = key;                                                  // store key in the node

    str++;                        // skip space
    node->left = BUILD_TREE(str); // build left sub-tree

    str++; // skip space

    // skip left subtree
    // you can use any other logic here
    temp = 1;
    while (temp != 0)
    {
        if (*str == '(')
            temp++;
        if (*str == ')')
            temp--;
        str++;
    }

    str++;                         // skip space
    node->right = BUILD_TREE(str); // build right sub-tree

    return node;
}

struct Node *find(struct Node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->k == x)
        return root;
    struct Node *t1 = find(root->left, x);
    if (t1)
        return t1;
    struct Node *t2 = find(root->right, x);
    if (t2)
        return t2;
    return NULL;
}

bool printAncestors(struct Node *root, int target)
{

    if (root == NULL)

        return false;

    if (root->k == target)
        return true;
    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target))
    {

        printf("%d ", root->k);
        return true;
    }

    return false;
}

int main()
{

    char *str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]s", str);
    bool isTrue;
    struct BinaryTree *bt = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    bt->root = BUILD_TREE(str);
    struct Node *parent = bt->root;
    int x;
    scanf("%d", &x);
    struct Node *found = find(bt->root, x);
    if (found == NULL)
    {
        printf("-1\n");
    }
    else if (x == parent->k)
        printf("-1\n");
    else
        printAncestors(bt->root, x);

    return 0;
}


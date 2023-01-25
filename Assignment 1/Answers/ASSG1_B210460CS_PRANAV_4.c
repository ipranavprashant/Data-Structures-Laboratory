#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
} *root = NULL;

struct node *Create_node(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *Insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return Create_node(key);
    }
    else if (key < root->key)
        root->left = Insert(root->left, key);
    else
        root->right = Insert(root->right, key);

    return root;
}

struct node *inorder(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node *preorder(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node *postorder(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->key == key)
        return root;

    else if (key < root->key)
        search(root->left, key);

    else
        search(root->right, key);
}

int min(struct node *root)
{
    if (root == NULL)
        return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->key;
}

int max(struct node *root)
{
    if (root == NULL)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->key;
}

struct node *inorderSucc(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        while (root != NULL && root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    return root;
}

struct node *inorderPre(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        while (root != NULL && root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    return root;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->key)
        root->left = delete (root->left, key);
    else if (key > root->key)
        root->right = delete (root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = inorderSucc(root->right);
            root->key = temp->key;
            root->right = delete (root->right, temp->key);
        }
    }
    return root;
}

int getLevel(struct node *root, int data, int level)
{
    if (root == NULL)
        return 0;
    if (root->key == data)
        return level;
    int downLevel = getLevel(root->left, data, level + 1);
    if (downLevel != 0)
        return downLevel;
    downLevel = getLevel(root->right, data, level + 1);
    return downLevel;
}

int getutilLevel(struct node *root, int data)
{
    return getLevel(root, data, 1);
}

int main()
{
    char ch;
    int val;
    int q;
    struct node *found, *temp, *find;
    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf("%d", &q);
            root = Insert(root, q);
            break;

        case 'i':
            inorder(root);
            printf("\n");
            break;

        case 'p':
            preorder(root);
            printf("\n");
            break;

        case 't':
            postorder(root);
            printf("\n");
            break;

        case 's':
            scanf("%d", &q);
            found = search(root, q);
            if (found == NULL)
                printf("-1\n");
            else
                printf("1\n");
            break;

        case 'l':
            scanf("%d", &q);
            if (search(root, q) == NULL)
                printf("-1\n");
            else
            {
                val = getutilLevel(root, q);
                printf("%d\n", val);
            }

            break;

        case 'm':
            q = min(root);
            printf("%d\n", q);
            break;

        case 'x':
            q = max(root);
            printf("%d\n", q);
            break;

        case 'd':
            scanf("%d", &q);
            if (search(root, q) != NULL)
            {
                root = delete (root, q);
            }
            else
                printf("-1\n");

            break;

        case 'r':
            scanf("%d", &val);

            find = search(root, val);
            if (find == NULL)
                printf("-1\n");
            else
            {
                temp = inorderPre(find->left);
                if (temp == NULL)
                    printf("-1\n");
                else
                    printf("%d\n", temp->key);
            }
            break;

        case 'u':
            scanf("%d", &val);

            find = search(root, val);
            if (find == NULL)
                printf("-1\n");
            else
            {
                temp = inorderSucc(find->right);
                if (temp == NULL)
                    printf("-1\n");
                else
                    printf("%d\n", temp->key);
            }
            break;

        case 'e':
            return 0;
        }
    } while (ch != 'e');
    return 0;
}

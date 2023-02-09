#include <stdio.h>
#include <stdlib.h>

int arr[10000];
int flag = 0;
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

int BalanceFactor(struct Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->height = 1;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = height(p);
    pl->height = height(pl);
    if (root == p)
    {
        root = pl;
    }
    return pl;
}
struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);

    if (p == root)
    {
        root = plr;
    }
    return plr;
}
struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = height(p);
    pr->height = height(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}
struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        t->height = 1;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }

    p->height = height(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        arr[flag++] = root->data;
        Inorder(p->rchild);
    }
}

int countNodes(struct Node *root)
{
    int count = 0;
    if (root == NULL)
        return 0;
    else
    {
        count = countNodes(root->lchild) + countNodes(root->rchild) + 1;
        return count;
    }
}

int getMedian(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int val = countNodes(root);
        if (val % 2 == 0)
            return val / 2;
        else
            return (val + 1) / 2;
    }
}

int main()
{
    struct Node *temp;
    char ch;
    int q;
    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &q);
            root = RInsert(root, q);
            break;
        case 'g':
            Inorder(root);
            q = getMedian(root);
            printf("%d\n", arr[q]);
            break;
        case 't':
            return 0;
            break;
        }
    } while (ch != 't');
    return 0;
}

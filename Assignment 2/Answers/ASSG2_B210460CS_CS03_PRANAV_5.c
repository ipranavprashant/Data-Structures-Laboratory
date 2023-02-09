#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

struct Node *InPre(struct Node *p) {
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
 
struct Node *InSucc(struct Node *p) {
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

int BalanceFactor(struct Node *p) {
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
struct Node *LLRotation(struct Node *p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
    p->height = height(p);
    pl->height = height(pl);
    if (root == p){
        root = pl;
    }
    return pl;
}
struct Node *LRRotation(struct Node *p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
 
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
 
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);
 
    if (p == root){
        root = plr;
    }
    return plr;
}
struct Node *RRRotation(struct Node *p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;

    p->height = height(p);
    pr->height = height(pr);

    if (root == p){
        root = pr;
    }
    return pr;
}
struct Node *RLRotation(struct Node *p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;

    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);

    if (root == p){
        root = prl;
    }
    return prl;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
   if (p == NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        t->height = 1;
        return t;
    }
 
    if (key < p->data){
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }

    p->height = height(p);
 
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }
 
    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Inorder(p->lchild);
        Inorder(p->rchild);
    }
}
struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

void PRINT(struct Node *root)
{
    printf("( ");
    if (root == NULL)
    {
        printf(") ");
        return;
    }
    printf("%d ", root->data);
    PRINT(root->lchild);
    PRINT(root->rchild);
    printf(") ");
}

struct Node *Delete(struct Node *p, int key) {
    if (p == NULL){
        return NULL;
    }
 
    if (p->lchild == NULL && p->rchild == NULL){
        if (p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        struct Node* q;
        if (height(p->lchild) > height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = height(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){
        return RRRotation(p);
    }
 
    return p;
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
        case 's':
            scanf("%d", &q);
            temp = Search(q);
            if (temp != NULL)
                printf("TRUE\n");
            else
                printf("FALSE\n");
            break;
        case 'e':
            return 0;
            break;
        case 'b':
            scanf("%d", &q);
            temp = Search(q);
            if(temp==NULL)
            printf("FALSE\n");
            else
            printf("%d\n", BalanceFactor(temp));
            break;
        case 'p':
            PRINT(root);
            printf("\n");
            break;
        case 'd':
            scanf("%d", &q);
            temp = Search(q);
            if (temp == NULL)
                printf("FALSE\n");
            else
            {
                printf("%d\n", temp->data);
                Delete(root,q);
            }
            break;
        }
    } while (ch != 'e');
    return 0;
}

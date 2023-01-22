#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

void insert(int key)
{
    struct node *t=root;
    struct node *r=NULL,*p;

    if(root==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->lchild=NULL;
        p->data=key;
        p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        t=t->lchild;
        else if(key>t->data)
        t=t->rchild;
        else
        return;
    }
        p=(struct node *)malloc(sizeof(struct node));
        p->lchild=NULL;
        p->data=key;
        p->rchild=NULL;

        if(key<r->data)
        r->lchild=p;
        else
        r->rchild=p;    
}

void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }

}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }

}

void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

struct node * search(int key)
{
    struct node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}

// Function to find the node with maximum value
// i.e. rightmost leaf node
int max(struct node* node)
{  
    /* loop down to find the rightmost leaf */
    if(root==NULL)
    return -1;
    else{
    struct node* current = node;
    while (current->rchild != NULL)
        current = current->rchild;
     
    return (current->data);
    }
}

// Function to find the node with minimum value
// i.e. lefttmost leaf node
int min(struct node* node)
{  
    if(root==NULL)
    return -1;
    else
    {
    /* loop down to find the leftmost leaf */
    struct node* current = node;
    while (current->lchild != NULL)
        current = current->lchild;
     
    return (current->data);
    }
}


// Function to find maximum node in a BST
struct node* maximumNode(struct node *root)
{
    while (root->rchild) {
        root = root->rchild;
    }
    return root;
}

// Pred node is passed by reference meaning it is making changes in the original node
int findPredecessor(struct node* root,struct node* pred, int key)
{
    // base case
    if (root == NULL)
    {
        pred = NULL;
        return -1;
    }
    
    // if the root is our key node then the predecessor will be the largest node in its left subtree
    if (root->data == key)
    {
        if (root->lchild != NULL) {
            pred = maximumNode(root->lchild);
        }
    }
 
    // if our key value is less than the root node value then we'll search in left subtree for key node
    else if (key < root->data) {
        findPredecessor(root->lchild, pred, key);
    }
 
    // if our key value is more than the root node value then we'll search in right subtree for key node
    else if (key > root->data) {
        // update predecessor to the current node before recursing in the right subtree
        pred = root;
        findPredecessor(root->rchild, pred, key);
    }
    if(pred==NULL)
    return -1;
    else
    return pred->data;
}


// Function to find minimum node in a BST

struct node* minimumNode(struct node* root)

{

    while (root->lchild) {

        root = root->lchild;

    }

    return root;

}

 

// succ node is passed by reference meaning it is making changes in the original node

int findSuccessor(struct node* root, struct node* succ, int key)

{

    succ = NULL;

    

    while(1){

        

        // if the root is our key node then the successor will be the smallest node in its right subtree

        if (root->data == key)

        {

            if (root->rchild != NULL) {

                succ = minimumNode(root->rchild);

            }

            break;

        }

     

        // if our key value is less than the root node value then we'll search in left subtree for key node

        else if (key < root->data) {

            // update successor to the current node before searching in left subtree

            succ = root;

            root = root->lchild;

        }

     

        // if our key value is more than the root node value then we'll search in right subtree for key node

        else if (key > root->data) {

            root = root->rchild;

        }

        

        // simply return -1 if the key value doesn't exist in tree

        if(root == NULL)
        return -1;

    }
    if(succ==NULL)
    return -1;
    else

    return succ->data;

}

int height(struct node *p)
{
    int x,y;
    if(p==NULL)
    return 0;
    else
    {
        x=height(p->lchild);
        y=height(p->rchild);
        return x>y?x+1:y+1;
    }
}

/*Abdul Bari sir's Version of inorder predecessor and successor*/

struct node *inpre(struct node *p)
{
    while(p && p->rchild!=NULL)    //right most node of the left subtree
    p=p->rchild;

    return p;
}

struct node *insucc(struct node *p)
{
    while(p && p->lchild!=NULL)    //leftmost node of the right sub tree
    p=p->lchild;

    return p;
}

struct node *delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
    return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->lchild=delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=delete(p->rchild,key);
    }
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);
        }
        else        
        {
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data);
        }
    }
    return p;
}

int getLevelUtil(struct node* root, int data, int level)
{
    if (root == NULL)
        return 0;
 
    if (root->data == data)
        return level;
 
    int downlevel
        = getLevelUtil(root->lchild, data, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(root->rchild, data, level + 1);
    return downlevel;
}
 
/* Returns level of given data value */
int getLevel(struct node* root, int data)
{
    return getLevelUtil(root, data, 1);
}

int main()
{
    int x,find,find1,level;
    char ch;
    do
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case 'a':scanf("%d",&x);
            insert(x);
            break;

            case 's':scanf("%d",&x);
            struct node* find2=search(x);
            if(find2==NULL)
            printf("-1\n");
            else
            printf("1\n");
            break;

            case 'x':find=max(root);
            if(find==-1)
            printf("NIL\n");
            else
            printf("%d\n",find);
            break;

            case 'm':find1=min(root);
            if(find1==-1)
            printf("NIL\n");
            else
            printf("%d\n",find1);
            break;

            case 'i':inorder(root);
            printf("\n");
            break;

            case 'p':preorder(root);
            printf("\n");
            break;

            case 't':postorder(root);
            printf("\n");
            break;

            case 'r':scanf("%d",&x);
            int ans;
            ans=findPredecessor(root,NULL,x);
            if(ans==-1)
            printf("NotFound\n");
            else
            printf("%d\n",ans);
            break;

            case 'u':scanf("%d",&x);
            int successor;
            successor=findSuccessor(root,NULL,x);
            if(successor==-1)
            printf("-1\n");
            else
            printf("%d\n",successor);
            break;

            case 'd':scanf("%d",&x);
            struct node *y=search(x);
            if(y==NULL)
            printf("-1\n");
            else
            {
            delete(root,x);
            printf("%d\n",x);
            }
            break;
            
            case 'l':scanf("%d",&x);
            level=getLevel(root, x);
            if(level!=0)
            printf("%d\n",level);
            else
            printf("-1\n");
            break;
            case 'e':return 0;

        }
    }while(ch!='e');
    
    return 0;
}



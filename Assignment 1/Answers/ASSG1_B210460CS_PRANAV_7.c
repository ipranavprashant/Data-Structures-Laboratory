#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct stack
{
    long long int size;
    int top;
    int *s;
}st;

void create(struct stack *st)
{

    st->size=10000;
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

int isempty(struct stack st)
{
    if(st.top==-1)
    return 1;
    else
    return 0;
}

int stacktop(struct stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

void stackpush(struct stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int stackpop(struct stack *st)
{
    int x;
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

struct node
{
    struct node *lchild;
    struct node *rchild;
    char key;
}root;

struct node *createNode(int val)
{
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->lchild=NULL;
    newNode->rchild=NULL;
    newNode->key=val;
    
    return newNode;
}

void preOrder(struct node *root)
{
    if(root==NULL)
    return;
    else
    {
        printf("%d ",root->key);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int findIndex(char str[], int si, int ei)
{
    if (si > ei)
        return -1;
 
    for (int i = si; i <= ei; i++) {
 
        if (str[i] == '(')
            stackpush(&st,str[i]);
            
        else if (str[i] == ')') {
            if (stacktop(st) == '(') {
                stackpop(&st);
 
                if (isempty(st))
                    return i;
            }
        }
    }
    return -1;
}

struct node* treeFromString(char str[], int si, int ei)
{
    
    if (si > ei)
        return NULL;
 
     
      int num = 0;
      while(si <= ei && str[si] >= '0' && str[si] <= '9')
    {
      num *= 10;
      num += (str[si] - '0');
      si++;
    }
   
    struct node* root = createNode(num);
    int index = -1;
 

    if (si <= ei && str[si] == '(')
        index = findIndex(str, si, ei);
 
    if (index != -1) {
 
       
        root->lchild = treeFromString(str, si + 1, index - 1);
 
        root->rchild
            = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}

int stringLength(char str[])
{
    int count=0;
    for(int i=0;str[i]!='\0';i++)
    {
        count++;
    }
    return count;
}

bool printAncestors(struct node *root, int target)
{

  if (root == NULL)
     return false;
 
  if (root->key == target)
     return true;
  if ( printAncestors(root->lchild, target) ||
       printAncestors(root->rchild, target) )
  {
      if(root->key!=0)
    printf("%d ",root->key);
    return true;
  }
 
  return false;
}

int main()
{
    create(&st);
    char str[10000],str1[10000];
    int k=0;
    scanf("%[^\n]s",str1);
    for(int i=0;str1[i]!='\0';i++)
    {
        if(str1[i]!=' ')
        {
        str[k]=str1[i];
        k++;
        }
    }
    struct node* root = treeFromString(str, 0, k-1);
    // preOrder(root);
    // printf("\n");
    
  printAncestors(root, 2);
    return 0;
}

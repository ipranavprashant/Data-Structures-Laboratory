#include<stdio.h>
#include<stdlib.h>


struct Node{
    int k;
    struct Node* left;
    struct Node* right;
};

struct BinaryTree{
    struct Node* root;
};


struct Node* BUILD_TREE(char* str)
{ 
    int key, temp, i;
    char k[1000];
    
    str += 2; // skip ( and space
    
    if(*str == ')')
    {
        return NULL;
    }
    
    // extract integer key
    i = 0;
    while((*str >= '0' && *str <= '9') || *str == '-') // if number or -, extract
    {
        k[i++] = *str;
        str++;
    }
    k[i] = '\0'; // end of string

    key = atoi(k); // convert string to integer

    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); // create new node
    node->k = key; //store key in the node
    
    str++; // skip space
    node->left = BUILD_TREE(str); // build left sub-tree

    str++; // skip space

    // skip left subtree 
    // you can use any other logic here
    temp = 1;
    while(temp != 0)
    {
        if(*str == '(')
            temp++;
        if(*str == ')')
            temp--;
        str++;
    }

    str++; // skip space
    node->right = BUILD_TREE(str); // build right sub-tree

    return node;
  
}

void PRINT(struct Node* root,int x,int y){
    if(root == NULL)
        return;

    PRINT(root->left,x,y);
    if(root->k>=x && root->k<=y)
    printf("%d ", root->k);
    PRINT(root->right,x,y);
  
}


int main(){
    
    char* str  = (char*)malloc(1000 * sizeof(char));
    scanf("%[^\n]s", str); 
    
    struct BinaryTree* bt = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    bt->root = BUILD_TREE(str); 
    int x,y;
    scanf("%d%d",&x,&y);
    PRINT(bt->root,x,y);
    
    return 0;
}
/*Read the Comments properly as there are multiple ways I have solved this in multiple ways
whichever function you call you gonna get your answer*/

/*Also I've commented out the function calls for each methods, you can check the functionality or debug
by uncommenting the same*/

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

/*Method-I */

void nth_dist(struct Node *root, int depth, int dist)
{
    if (root != NULL)
    {
        depth = depth + 1;
        if (depth == dist)
            printf("%d ", root->k);
        nth_dist(root->left, depth, dist);
        nth_dist(root->right, depth, dist);
    }
    else
        return;
}

/*Method-II */

void nth_dist_variation(struct Node *root, int depth, int dist)
{
    if (root != NULL)
    {
        depth = depth + 1;
        if (depth == dist)
            printf("%d ", root->k);
        nth_dist(root->left, depth, dist);
        nth_dist(root->right, depth, dist);
    }
    else
        return;
}

/*Method-III */

struct Node *printSubtreeNodes(struct Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return NULL;
    }
    if (k == 0)
    {
        return root;
    }
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

/* This function is used to print all the nodes at the k-th distance, irrespective of if it is the
descendant or ancestor*/
/*int printNodesatk(struct Node *root,struct Node *target,int k)
{
    if(root==NULL){
    return -1;
    }

    if(root==target)
    {
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl=printNodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            printf("%d ",root->k);
        }
        else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr=printNodesatk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            printf("%d ",root->k);
        }
        else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}*/

int main()
{

    char *str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]s", str);

    struct BinaryTree *bt = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    bt->root = BUILD_TREE(str);
    int x, dist;
    int depth = -1;
    scanf("%d%d", &x, &dist);
    struct Node *found = find(bt->root, x);
    if (found == NULL)
    {
        printf("-1\n");
    }
    else
    {
        // printNodesatk(bt->root,found,dist);                           //To Print all the nodes at k-th distance, both ancestors and descendants
        //  nth_dist(found,depth,dist);                                  //Method-I
        //  nth_dist_variation(found,depth,dist);                        //Method-II
        printSubtreeNodes(found, dist); // Method-III
    }

    return 0;
}


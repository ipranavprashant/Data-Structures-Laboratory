#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
struct studentBST
{
    char firstName[1000];
    char lastName[1000];
    char gender;
    char DOB[1000]; // Have to be in the format of DD-MM-YYYY
    char dept[1000];
    float cgpa;
    struct studentBST *lchild;
    struct studentBST *rchild;
} *rootA = NULL, *rootB = NULL, *rootC = NULL, *rootD = NULL, *rootE = NULL, *rootF = NULL, *rootG = NULL, *rootH = NULL, *rootI = NULL, *rootJ = NULL, *rootK = NULL, *rootL = NULL, *rootM = NULL, *rootN = NULL, *rootO = NULL, *rootP = NULL, *rootQ = NULL, *rootR = NULL, *rootS = NULL, *rootT = NULL, *rootU = NULL, *rootV = NULL, *rootW = NULL, *rootX = NULL, *rootY = NULL, *rootZ = NULL;

struct studentBST *createNode(char *firstName, char *lastName, char gender, char *DOB, char *dept, float cgpa)
{
    struct studentBST *temp = (struct studentBST *)malloc(sizeof(struct studentBST));
    strcpy(temp->firstName, firstName);
    strcpy(temp->lastName, lastName);
    temp->gender = gender;
    strcpy(temp->DOB, DOB);
    strcpy(temp->dept, dept);
    temp->cgpa = cgpa;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

struct studentBST *insert(struct studentBST *root, char *firstName, char *lastName, char gender, char *DOB, char *dept, float cgpa)
{
    if (root == NULL)
    {
        // count++;
        return createNode(firstName, lastName, gender, DOB, dept, cgpa);
    }
    else
    {
        if (strcmp(firstName, root->firstName) < 0)
        {
            count++;
            root->lchild = insert(root->lchild, firstName, lastName, gender, DOB, dept, cgpa);
        }
        else if (strcmp(firstName, root->firstName) == 0)
        {
            if (strcmp(lastName, root->lastName) < 0)
            {
                count++;
                root->lchild = insert(root->lchild, firstName, lastName, gender, DOB, dept, cgpa);
            }
            else
            {
                count++;
                root->rchild = insert(root->rchild, firstName, lastName, gender, DOB, dept, cgpa);
            }
        }
        else
        {
            count++;
            root->rchild = insert(root->rchild, firstName, lastName, gender, DOB, dept, cgpa);
        }
        return root;
    }
}

void PRINT(struct studentBST *root)
{
    if (root == NULL)
        return;
    else
    {
        PRINT(root->lchild);
        printf("%s ", root->firstName);
        printf("%s ", root->lastName);
        printf("%c ", root->gender);
        printf("%s ", root->DOB);
        printf("%s ", root->dept);
        printf("%0.1f \n", root->cgpa);
        PRINT(root->rchild);
    }
}

/*Hashing Concept*/
/*Linked List Helper Functions*/
struct Node
{
    int data;
    struct studentBST *root;
    struct Node *next;
};
void SortedInsert(struct Node **H, int x, struct studentBST *root)
{
    struct Node *t, *q = NULL, *p = *H;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->root = root;
    t->next = NULL;
    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}


struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
/*Linked List Helper Functions*/

int hash(int key)
{
    return key;
}

void Insert(struct Node *H[], int key, struct studentBST *root)
{
    int index = hash(key);
    SortedInsert(&H[index], key, root);
}


struct studentBST *bstSearchPrint(struct studentBST *root, char *firstName, char *lastName)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (strcmp(root->firstName, firstName) == 0 && strcmp(root->lastName, lastName) == 0)
        {
            // count++;
            return root;
        }
        if (strcmp(firstName, root->firstName) < 0)
        {
            // count++;
            printf("L");
            bstSearchPrint(root->lchild, firstName, lastName);
        }
        else if (strcmp(firstName, root->firstName) == 0 && strcmp(lastName, root->lastName) != 0)
        {
            if (strcmp(lastName, root->lastName) < 0)
            {
                // count++;
                printf("L");
                bstSearchPrint(root->lchild, firstName, lastName);
            }
            else
            {
                // count++;
                printf("R");
                bstSearchPrint(root->rchild, firstName, lastName);
            }
        }
        else if (strcmp(firstName, root->firstName) > 0)
        {
            // count++;
            printf("R");
            bstSearchPrint(root->rchild, firstName, lastName);
        }
    }
}

struct studentBST *bstSearch(struct studentBST *root, char *firstName, char *lastName)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (strcmp(root->firstName, firstName) == 0 && strcmp(root->lastName, lastName) == 0)
        {
            // count++;
            return root;
        }
        if (strcmp(firstName, root->firstName) < 0)
        {
            count++;
            bstSearch(root->lchild, firstName, lastName);
        }
        else if (strcmp(firstName, root->firstName) == 0 && strcmp(lastName, root->lastName) != 0)
        {
            if (strcmp(lastName, root->lastName) < 0)
            {
                count++;
                bstSearch(root->lchild, firstName, lastName);
            }
            else
            {
                count++;
                bstSearch(root->rchild, firstName, lastName);
            }
        }
        else if (strcmp(firstName, root->firstName) > 0)
        {
            count++;
            bstSearch(root->rchild, firstName, lastName);
        }
    }
}

struct studentBST *actualRoot(char key)
{
    if (key == 'A' || key == 'a')
        return rootA;
    else if (key == 'B' || key == 'b')
        return rootB;
    else if (key == 'C' || key == 'c')
        return rootC;
    else if (key == 'D' || key == 'd')
        return rootD;
    else if (key == 'E' || key == 'e')
        return rootE;
    else if (key == 'F' || key == 'f')
        return rootF;
    else if (key == 'G' || key == 'g')
        return rootG;
    else if (key == 'H' || key == 'h')
        return rootH;
    else if (key == 'I' || key == 'i')
        return rootI;
    else if (key == 'J' || key == 'j')
        return rootJ;
    else if (key == 'K' || key == 'k')
        return rootK;
    else if (key == 'L' || key == 'l')
        return rootL;
    else if (key == 'M' || key == 'm')
        return rootM;
    else if (key == 'N' || key == 'n')
        return rootN;
    else if (key == 'O' || key == 'o')
        return rootO;
    else if (key == 'P' || key == 'p')
        return rootP;
    else if (key == 'Q' || key == 'q')
        return rootQ;
    else if (key == 'R' || key == 'r')
        return rootR;
    else if (key == 'S' || key == 's')
        return rootS;
    else if (key == 'T' || key == 't')
        return rootT;
    else if (key == 'U' || key == 'u')
        return rootU;
    else if (key == 'V' || key == 'v')
        return rootV;
    else if (key == 'W' || key == 'w')
        return rootW;
    else if (key == 'X' || key == 'x')
        return rootX;
    else if (key == 'Y' || key == 'y')
        return rootY;
    else if (key == 'Z' || key == 'z')
        return rootZ;
}

struct studentBST *inorderSucc(struct studentBST *root, struct studentBST *ptr)
{
    struct studentBST *successor = NULL;
    while (root != NULL)
    {
        if (strcmp(ptr->firstName, root->firstName) > 0)
        {
            // count++;
            root = root->rchild;
        }
        else if (strcmp(ptr->firstName, root->firstName) == 0 && strcmp(ptr->lastName, root->lastName) != 0)
        {
            if (strcmp(ptr->lastName, root->lastName) > 0)
            {
                // count++;
                root = root->rchild;
            }
            else
            {
                // count++;
                successor = root;
                root = root->lchild;
            }
        }
        else if (strcmp(ptr->firstName, root->firstName) > 0)
        {
            // count++;
            successor = root;
            root = root->lchild;
        }
    }
    return successor;
}

struct studentBST *delete(struct studentBST *root, char *firstName, char *lastName)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (strcmp(firstName, root->firstName) < 0)
        {
            // count++;
            root->lchild = delete (root->lchild, firstName, lastName);
        }
        else if (strcmp(firstName, root->firstName) == 0 && strcmp(lastName, root->lastName) != 0)
        {
            if (strcmp(lastName, root->lastName) < 0)
            {
                // count++;
                root->lchild = delete (root->lchild, firstName, lastName);
            }
            else
            {
                // count++;
                root->rchild = delete (root->rchild, firstName, lastName);
            }
        }
        else if (strcmp(firstName, root->firstName) > 0)
        {
            // count++;
            root->rchild = delete (root->rchild, firstName, lastName);
        }
        else
        {
            if (root->lchild == NULL)
            {
                struct studentBST *temp = root->rchild;
                free(root);
                return temp;
            }
            else if (root->rchild == NULL)
            {
                struct studentBST *temp = root->lchild;
                free(root);
                return temp;
            }
            else
            {
                struct studentBST *temp = bstSearch(root->rchild, root->rchild->firstName, root->rchild->lastName);
                inorderSucc(root, temp);
                strcpy(root->firstName, temp->firstName);
                strcpy(root->lastName, temp->lastName);
                root->gender = temp->gender;
                strcpy(root->DOB, temp->DOB);
                strcpy(root->dept, temp->dept);
                root->cgpa = temp->cgpa;
                root->rchild = delete (root->rchild, temp->firstName, temp->lastName);
            }
        }
        return root;
    }
}
int main()
{
    struct Node *temp;
    struct studentBST *temp1, *actualRootVal;

    struct Node *HT[26];
    for (int i = 0; i < 25; i++)
    {
        HT[i] = NULL;
    }
    char firstName[1000], lastName[1000], gender, DOB[1000], dept[1000], ch;
    float cgpa;
    int q;
    char query;
    do
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
            count = 0;
            scanf("%s", firstName);
            scanf("%s", lastName);
            scanf("\n%c", &gender);
            scanf("%s", DOB);
            scanf("%s", dept);
            scanf("%f", &cgpa);
            if (firstName[0] == 'A' || firstName[0] == 'a')
            {
                rootA = insert(rootA, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootA);
            }
            else if (firstName[0] == 'B' || firstName[0] == 'b')
            {
                rootB = insert(rootB, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootB);
            }
            else if (firstName[0] == 'C' || firstName[0] == 'c')
            {
                rootC = insert(rootC, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootC);
            }
            else if (firstName[0] == 'D' || firstName[0] == 'd')
            {
                rootD = insert(rootD, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootD);
            }
            else if (firstName[0] == 'E' || firstName[0] == 'e')
            {
                rootE = insert(rootE, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootE);
            }
            else if (firstName[0] == 'F' || firstName[0] == 'f')
            {
                rootF = insert(rootF, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootF);
            }
            else if (firstName[0] == 'G' || firstName[0] == 'g')
            {
                rootG = insert(rootG, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootG);
            }
            else if (firstName[0] == 'H' || firstName[0] == 'h')
            {
                rootH = insert(rootH, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootH);
            }
            else if (firstName[0] == 'I' || firstName[0] == 'i')
            {
                rootI = insert(rootI, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootI);
            }
            else if (firstName[0] == 'J' || firstName[0] == 'j')
            {
                rootJ = insert(rootJ, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootJ);
            }
            else if (firstName[0] == 'K' || firstName[0] == 'k')
            {
                rootK = insert(rootK, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootK);
            }
            else if (firstName[0] == 'L' || firstName[0] == 'l')
            {
                rootL = insert(rootL, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootL);
            }
            else if (firstName[0] == 'M' || firstName[0] == 'm')
            {
                rootM = insert(rootM, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootM);
            }
            else if (firstName[0] == 'N' || firstName[0] == 'n')
            {
                rootN = insert(rootN, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootN);
            }
            else if (firstName[0] == 'O' || firstName[0] == 'o')
            {
                rootO = insert(rootO, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootO);
            }
            else if (firstName[0] == 'P' || firstName[0] == 'p')
            {
                rootP = insert(rootP, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootP);
            }
            else if (firstName[0] == 'Q' || firstName[0] == 'q')
            {
                rootQ = insert(rootQ, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootQ);
            }
            else if (firstName[0] == 'R' || firstName[0] == 'r')
            {
                rootR = insert(rootR, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootR);
            }
            else if (firstName[0] == 'S' || firstName[0] == 's')
            {
                rootS = insert(rootS, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootS);
            }
            else if (firstName[0] == 'T' || firstName[0] == 't')
            {
                rootT = insert(rootT, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootT);
            }
            else if (firstName[0] == 'U' || firstName[0] == 'u')
            {
                rootU = insert(rootU, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootU);
            }
            else if (firstName[0] == 'V' || firstName[0] == 'v')
            {
                rootV = insert(rootV, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootV);
            }
            else if (firstName[0] == 'W' || firstName[0] == 'w')
            {
                rootW = insert(rootW, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootW);
            }
            else if (firstName[0] == 'X' || firstName[0] == 'x')
            {
                rootX = insert(rootX, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootX);
            }
            else if (firstName[0] == 'Y' || firstName[0] == 'y')
            {
                rootY = insert(rootY, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootY);
            }
            else if (firstName[0] == 'Z' || firstName[0] == 'z')
            {
                rootZ = insert(rootZ, firstName, lastName, gender, DOB, dept, cgpa);
                Insert(HT, (int)firstName[0] - 65, rootZ);
            }
            printf("%d\n", count);
            break;

        case 'l':
            count = 0;
            scanf("%s", firstName);
            scanf("%s", lastName);
            // scanf("%c", &query);
            q = (int)firstName[0] - 65;
            temp = Search(HT[hash(q)], q);
            if (temp == NULL)
                printf("haha-1\n");
            else
            {
                actualRootVal = actualRoot(firstName[0]);
                temp1 = bstSearch(actualRootVal, firstName, lastName);
                if (temp1 == NULL)
                    printf("-1\n");
                else
                {
                    printf("%d-", temp->data);
                    bstSearchPrint(actualRootVal, firstName, lastName);
                    printf("\n");
                }
            }
            break;
        case 'u':
            count = 0;
            scanf("%s", firstName);
            scanf("%s", lastName);
            scanf("%f", &cgpa);
            actualRootVal = actualRoot(firstName[0]);
            temp1 = bstSearch(actualRootVal, firstName, lastName);
            if (temp1 == NULL)
            {
                printf("-1\n");
            }
            else
            {
                //  printf("%d ",count);
                temp1->cgpa = cgpa;
                //count++;
                printf("%d\n", count);
            }
            break;

        case 'd':
            count = 0;
            scanf("%s", firstName);
            scanf("%s", lastName);
            actualRootVal = actualRoot(firstName[0]);
            temp1 = bstSearch(actualRootVal, firstName, lastName);
            if (temp1 == NULL)
                printf("-1\n");
            else
            {
                actualRootVal = delete (actualRootVal, firstName, lastName);
                printf("%d\n", count);
            }
            break;
        case 'p':
            PRINT(rootR);
            printf("\n");
            break;
        case 'e':
            return 0;
            break;
        }
    } while (ch != 'e');

    return 0;
}

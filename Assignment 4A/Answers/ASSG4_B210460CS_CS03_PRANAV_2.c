/*
Process:
-Make an adjacency matrix
-Call DFS
*/


#include <stdio.h>
#include <stdlib.h>

int length;
struct Node
{
    int value;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is full\n");
    else
    {
        t->value = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* t;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        x = front->value;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int is_empty()
{
    return front == NULL;
}

void BFS(int graph[][length], int start, int len)
{
    int i = start, j;
    int visited[10000] = {0};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!is_empty())
    {
        i = dequeue();
        for (j = 1; j < len; j++)
        {
            if (graph[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int graph[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int f = 0; f < n; f++)
        {
            graph[l][f] = 0;
        }
    }
    char edges[20000], t[1000];
    for (i = 0; i < n; i++) {
        scanf(" %[^\n]s", edges);
        int j;
        int p = 0;
        int c = 0;
        int a[10000];
        for (j = 0; edges[j] != '\0'; j++) if (edges[j] == ' ') c++;
        c++;
        for (j = 0; j < c; j++) {
            int k = 0;
            while (edges[p] != ' ' && edges[p] != '\0') t[k++] = edges[p++];
            t[k] = '\0';
            p++;
            int e = atoi(t);
            a[j] = e;
        }
        for (j = 1; j < c; j++) graph[i][a[j]] = 1;
    }

    // for(int l=0;l<n;l++)
    // {
    //     for(int f=0;f<n;f++)
    //     {
    //         printf("%d ",graph[l][f]);
    //     }
    //     printf("\n");
    // }
    length = n;
    BFS(graph, 0, n);
    return 0;
}

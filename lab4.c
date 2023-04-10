#include <stdio.h>
#include <stdlib.h>

int length;
struct Node
{
    int value;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
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
    struct Node *t;
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

void DFS(int graph[][length],int start,int len)
{
    static int visited[10000]={0};
    int j;
    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start]=1;
        for(j=1;j<len;j++)
        {
            if(graph[start][j]==1 && visited[j]==0)
                DFS(graph,j,len);
        }
    }
}


int main()
{
    int size;
    scanf("%d", &size);
    int graph[size + 1][size + 1];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            graph[i][j] = 0;
        }
    }
    int x, y;
    char c;
    for (int i = 0; i < size; i++)
    {
        scanf("%d%c", &y, &c);
        while (c != '\n')
        {
            scanf("%d%c", &x, &c);
            graph[y][x] = 1;
            graph[x][y] = 1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    // length = size;
    // BFS(graph, 0, size);
    return 0;
}

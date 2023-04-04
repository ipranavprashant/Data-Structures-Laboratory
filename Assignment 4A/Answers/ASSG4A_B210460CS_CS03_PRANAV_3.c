#include <stdio.h>
#include <stdlib.h>

int length;

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
    DFS(graph, 0, n);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<limits.h>

int makeSet(int *parent, const int x) {
    if (parent[x] != -1) {
        return -1;
    }
    parent[x] = x;
    return x;
}
int makeSetRanked(int *rank, int *parent, const int x) {
    if (parent[x] != -1) {
        return -1;
    }
    parent[x] = x;
    rank[x] = 0;
    return x;
}
int findWithPathCompression(int *parent, const int x, int *perf) {
    (*perf)++;
    if (parent[x] != x) {
        parent[x] = findWithPathCompression(parent, parent[x], perf);
    }
    return parent[x];
}
int find(int *parent, const int x, int *perf) {
    (*perf)++;
    if (parent[x] != x) {
        return parent[find(parent, parent[x], perf)];
    }
    return x;
}
int unionRanked(int *rank, int *parent, const int x, const int y, int pathCompression) {
    int dummy = 0;
    int xParent, yParent;
    if (pathCompression) {
        xParent = findWithPathCompression(parent, x, &dummy);
        yParent = findWithPathCompression(parent, y, &dummy);
    } else {
        xParent = find(parent, x, &dummy);
        yParent = find(parent, y, &dummy);
    }
    if (xParent == yParent && xParent != -1) {
        printf("%d ", xParent);
        return dummy;
    }
    if (rank[xParent] > rank[yParent]) {
        parent[yParent] = xParent;
        printf("%d ", xParent);
        return dummy;
    } else if (rank[xParent] == rank[yParent]) {
        parent[yParent] = xParent;
        rank[xParent]++;
        printf("%d ", xParent);
        return dummy;
    } else {
        parent[xParent] = yParent;
        printf("%d ", yParent);
        return dummy;
    }
}
int unionUnranked(int *parent, const int x, const int y, int pathCompression) {
    int dummy = 0;
    int xParent, yParent;
    if (pathCompression) {
        xParent = findWithPathCompression(parent, x, &dummy);
        yParent = findWithPathCompression(parent, y, &dummy);
    } else {
        xParent = find(parent, x, &dummy);
        yParent = find(parent, y, &dummy);
    }
    if (xParent == -1 || yParent == -1) {
        printf("-1 ");
        return dummy;
    }
    if (xParent == yParent && xParent != -1) {
        printf("%d ", xParent);
        return dummy;
    } else {
        parent[yParent] = xParent;
        printf("%d ", xParent);
        return dummy;
    }
}
int main(){
    int pa[10002] = {-1};//no heuristics
    int pb[10002] = {-1};//only ranked union
    int pc[10002] = {-1};//only path compression
    int pd[10002] = {-1};//both ranked union and path compression
    memset(pa, -1, 10002* sizeof(int));/// only memset like this for 0 and -1
    memset(pb, -1, 10002* sizeof(int));
    memset(pc, -1, 10002* sizeof(int));
    memset(pd, -1, 10002* sizeof(int));
    int rb[10002] = {-1};
    int rd[10002] = {-1};
    memset(rb, -1, 10002* sizeof(int));
    memset(rd, -1, 10002* sizeof(int));
    
    char ch;
    int perf=0;
    int perfa=0;
    int perfb=0;
    int perfc=0;
    int perfd=0;
    while(EOF != (ch = fgetc(stdin))){
        if(ch == 'm'){
            int x;scanf("%d", &x);
            makeSet(pa, x);        
            makeSetRanked(rb, pb, x);        
            makeSet(pc, x);        
            int rc =makeSetRanked(rd, pd, x);        
            printf("%d\n" ,rc);
        }
        if(ch == 'f'){
            int x;scanf("%d", &x);
            int resa=find(pa, x,&perf);
            printf("%d ", resa);
            perfa+=perf;
            perf =0;

            int resb=find(pb, x,&perf);
            perfb+=perf;
            printf("%d ", resb);
            perf =0;

            int resc=findWithPathCompression(pc, x,&perf);
            perfc+=perf;
            printf("%d ", resc);
            perf =0;

            int resd=findWithPathCompression(pd, x,&perf);
            perfd+=perf;
            printf("%d ", resd);
            perf =0;
            printf("\n");
        }
        if(ch == 'u'){
            int x, y;scanf("%d %d", &x ,&y);
            perfa+=unionUnranked(pa, x, y,0);
            perfb+=unionRanked(rb,pb, x, y,0);
            perfc+=unionUnranked(pc, x, y,1);
            perfd+=unionRanked(rd,pd, x, y,1);
            printf("\n");
        }
        if(ch == 's'){
            printf("%d %d %d %d\n", perfa , perfb , perfc ,perfd);
            return 0;
        }
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int min_cost_to_connect_ropes(int ropes[], int n) {
  int total_cost = 0;
  qsort(ropes, n, sizeof(int), cmpfunc);
  while (n > 1) {
    int cost = ropes[0] + ropes[1];
    total_cost += cost;
    ropes[0] = cost;
    for (int i = 1; i < n - 1; i++) {
      ropes[i] = ropes[i + 1];
    }
    n--;
  }
  return total_cost;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  int min_cost = min_cost_to_connect_ropes(a, n);
  printf("%d", min_cost);
  return 0;
}

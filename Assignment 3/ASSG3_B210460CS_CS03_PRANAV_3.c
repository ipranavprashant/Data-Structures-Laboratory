#include <stdio.h>

int maxheap(int a[], int beg, int end);
int heapsort(int a[], int size);
int maxheapify(int a[], int f, int size);

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d", &m);
    int arr[m];
    for (int i = 1; i <= m; i++) {
      scanf("%d", &arr[i]);
    }
    maxheap(arr, 0, m);
    heapsort(arr, m);
    int k;
    scanf("%d", &k);
    for (int i = m; i > m - k; i--) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  return 0;
}

int heapsort(int a[], int size) {
  int temp;
  for (int i = size; i >= 2; i--) {
    temp = a[1];
    a[1] = a[i];
    a[i] = temp;
    maxheapify(a, 1, i - 1);
  }
}

int maxheap(int a[], int beg, int end) {
  for (int i = end / 2; i > beg; i--) {
    maxheapify(a, i, end);
  }
}

int maxheapify(int a[], int f, int size) {
  int max = f, l = f * 2, r = f * 2 + 1, temp;
  if (l <= size && a[l] > a[max]) {
    max = l;
  }
  if (r <= size && a[r] > a[max]) {
    max = r;
  }

  if (f != max) {
    temp = a[f];
    a[f] = a[max];
    a[max] = temp;
    maxheapify(a, max, size);
  }
}

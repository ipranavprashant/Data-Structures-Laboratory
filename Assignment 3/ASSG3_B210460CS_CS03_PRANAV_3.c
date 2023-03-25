#include <stdio.h>

void insertionSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int j = i - 1;
    int key = arr[i];
    while (j > -1 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    int k;
    scanf("%d", &k);
    for (int i = n - 1; i >= n - k; i--) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  return 0;
}


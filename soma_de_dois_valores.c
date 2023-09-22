#include <stdio.h>
#include <stdlib.h>

static void heapify(int *v, size_t i, size_t size) {
  int left, right, largest;
  while (i < size) {
    left = (i * 2) + 1;
    right = (i * 2) + 2;
    largest = i;

    if (left < size && v[left] > v[largest]) {
      largest = left;
    }

    if (right < size && v[right] > v[largest]) {
      largest = right;
    }

    if (largest == i) {
      break;
    }

    int aux = v[i];
    v[i] = v[largest];
    v[largest] = aux;
    i = largest;
  }
}

void make_heap(int *v, size_t size) {
  int i;
  for (i = size / 2; i >= 0; i--) {
    heapify(v, i, size);
  }
}

void heap_sort(int *v, size_t size) {
  int i;
  make_heap(v, size);
  for (i = size - 1; i > 0; i--) {
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    heapify(v, 0, i);
  }
}

int busca_binaria(int *v, size_t size, int key, size_t i) {
  int low = 0;
  int high = size - 1;
  int index = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (key == v[mid] && mid != i) {
      index = mid;
      high = mid - 1;
    } else if (key < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return (index) ? index : -1;
}

void print_vetor(int *v, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d\n", v[i]);
  }
}

void soma_dois_valores(int *v, size_t size, int k) {
  heap_sort(v, size);

  for (size_t i = 0; i < size; i++) {
    int value = k - v[i];
    int status = busca_binaria(v, size, value, i);

    if (status != -1 && status != i) {
      printf("%zu %d\n", i + 1, status + 1);
      return;
    }
  }
  printf("-1\n");
}

int main() {

  int n, k;
  scanf("%d %d", &n, &k);

  int *v = malloc(sizeof(int) * n);

  for (size_t i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  soma_dois_valores(v, n, k);

  return 0;
}

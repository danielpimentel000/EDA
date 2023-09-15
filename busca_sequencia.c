#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* busca_sequencia O(n) */
int busca_sequencia(int *v, size_t size, int key) {
  for (int i = 0; i < size; i++) {
    if (v[i] == key) {
      return i;
    }
  }
  return -1;
}

int busca_sequencial_otimizada(int *v, size_t size, int key) {
  for (int i = 0; i < size; i++) {
    if (key < v[i]) {
      break;
    } else if (v[i] == key) {
      return i;
    }
  }
  return -1;
}

int busca_binaria(int *v, size_t size, int key) {
  size_t low = 0;
  size_t hight = size - 1;
  size_t mid;
  while (low <= hight) {
    mid = (low + hight) / 2;
    if (v[mid] == key) {
      return mid;
    } else if (v[mid] > key) {
      hight = mid - 1;
    } else if (v[mid] < key) {
      low = mid + 1;
    }
  }
  return -1;
}

int main() {
  srand(time(NULL));
  size_t max = 100000;
  int *v = malloc(sizeof(int) * max);

  for (size_t i = 0; i < max; i++) {
    v[i] = i;
  }

  for (size_t i = 0; i < 100; i++) {
    printf("%d\n", busca_binaria(v, max, rand() % max));
  }

  free(v);
  return 0;
}

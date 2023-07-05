#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

typedef struct binary_tree_node_t {
  int data;
  struct binary_tree_node_t *left;
  struct binary_tree_node_t *right;
} binary_tree_node_t;

typedef struct binary_tree_t {
  binary_tree_node_t *root;
  size_t size;
} binary_tree_t;

void *mallocx(long size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("Error ao alocar memoria !!");
    exit(1);
  }
  return ptr;
}

void bst_initialize(binary_tree_t **t);
void bst_delete(binary_tree_t **t);

void binary_tree_insert_pre_order(binary_tree_node_t *root, char *topology) {
  if (root == NULL) {
    if (topology++ == '(') {
    }
  }
}

size_t bst_size(binary_tree_t *t) { return (t->size); }

int main() {

  int n;
  binary_tree_t *t;

  scanf("%d", &n);

  char *topology = mallocx(sizeof(char) * (3 * n + 1));
  int *vector = mallocx(sizeof(int) * n);

  scanf("%s", topology);

  for (size_t i = 0; i < n; i++) {
    scanf("%d", &vector[i]);
  }

  bst_initialize(&t);

  bst_delete(&t); // delete tree
  free(topology); // delete topology string
  free(vector);   // delete vector of integers

  return 0;
}

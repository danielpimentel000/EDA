#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *left;
  struct node_t *right;
} node_t;

typedef struct tree_t {
  node_t *root;
}

void init(){};

node_t *constroi(char topologia[], int *idx) {
  if (topologia[*idx] == '.') {
    (*idx)++;
    return NULL;
  }
  node_t *node = malloc(sizeof(node_t));
  scanf("%d", &node->data);
  node->left = constroi(topologia, idx);
  node->right = constroi(topologia, idx);
  (*idx)++;
  return node;
}

void print_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_tree(root->left);
  print_tree(root->right);
  printf("\n");
}

int main() {
  int n, idx = 0;
  scanf("%d", &n);

  char *topologia = malloc(sizeof(char) * (3 * n + 1));
  scanf("%s", topologia);

  node_t *root = constroi(topologia, &idx);

  print_tree(root);

  free(topologia);

  return 0;
}

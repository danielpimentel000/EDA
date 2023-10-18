#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_t {
  size_t front;
  size_t back;
  size_t size;
  size_t capacity;
  int *queue;
} queue_t;

void queue_initialize(queue_t **q) {
  (*q) = malloc(sizeof(queue_t));
  (*q)->front = 0;
  (*q)->back = 3;
  (*q)->size = 0;
  (*q)->capacity = 4;
  (*q)->queue = malloc(sizeof(int) * 4);
}

size_t queue_size(queue_t *q) { return q->size; }

bool queue_empty(queue_t *q) { return queue_size(q) == 0; }

void queue_push(queue_t *q, int data) {
  if (q->size == q->capacity) {
    size_t old_capacity = q->capacity;
    q->capacity *= 2;
    q->queue = realloc(q->queue, sizeof(int) * q->capacity);

    if (q->front > q->back) {
      for (size_t i = q->front; i < old_capacity; i++) {
        q->queue[i + old_capacity] = q->queue[i];
      }
    }
    q->front = q->front + old_capacity;
  }

  q->back++;
  if (q->back == q->capacity) {
    q->back = 0;
  }
  q->queue[q->back] = data;
  q->size++;
}

void queue_pop(queue_t *q) {
  if (q->size == q->capacity / 4 && q->capacity > 4) {
    size_t new_capacity = q->capacity / 2;
    if (q->front <= q->back) {
      for (size_t i = q->front, j = 0; i <= q->back; i++, j++) {
        q->queue[j] = q->queue[i];
      }
    } else {
      size_t front_len = q->capacity - q->front;
      memmove(&q->queue[q->back + front_len], &q->queue[q->back],
              sizeof(int) * front_len);

      memmove(&q->queue[0], &q->queue[q->capacity - front_len],
              sizeof(int) * front_len);
    }

    q->front = 0;
    q->back = q->size - 1;
    q->capacity = new_capacity;
    q->queue = realloc(q->queue, q->capacity * sizeof(int));
  }
  q->front++;
  q->size--;
  if (q->front == q->capacity) {
    q->front = 0;
  }
}

int queue_front(queue_t *q) { return q->queue[q->front]; }

void queue_delete(queue_t **q) {
  free((*q)->queue);
  free(*q);
  *q = NULL;
}

int main() {
  queue_t *q;
  queue_initialize(&q);
  for (size_t i = 0; i < 128; i++) {
    queue_push(q, i);
  }

  while (!queue_empty(q)) {
    printf("%d\n", queue_front(q));
    queue_pop(q);
  }

  queue_delete(&q);

  return 0;
}

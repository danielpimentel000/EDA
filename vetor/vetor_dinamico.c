#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct dynamic_array {
	int *v;
	size_t capacity;
	size_t size;

}dynamic_array_t;


void dynamic_array_initialize(dynamic_array_t **array) {

	(*array) = malloc(sizeof(dynamic_array_t));
	
	if((*array) == NULL) {
		printf("Falha ao alocar memoria !!\n");
		exit(1);
	}

	(*array)->capacity = 4;
	(*array)->size = 0;

	(*array)->v = malloc(sizeof(int) * (*array)->capacity);
	
	if((*array)->v == NULL) {
		printf("Falha ao alocar memoria !!\n");
		exit(1);
	} 

}

void dynamic_array_push_back(dynamic_array_t *array, int data) {

	if(array->size == array->capacity) {
		array->capacity *= 2;
		array->v = realloc(array->v, sizeof(int) * array->capacity);
		if(array->v == NULL) {
			printf("Falha ao alocar memoria !!\n");
			exit(1);
		}
	}

	array->v[array->size++] = data;
}

void dynamic_array_pop_back(dynamic_array_t *array) {
	if(array->size < array->capacity / 4 && array->capacity > 4) {
		array->capacity /= 2;
		array->v = realloc(array->v, sizeof(int) * array->capacity);
		if(array->v == NULL) {
			printf("Falha ao alocar memoria !!\n");
			exit(1);
		}
	}
	array->size--;
}


size_t dynamic_array_size(dynamic_array_t *array) {
	return array->size;
}


void dynamic_array_delete(dynamic_array_t **array) {
	free((*array)->v);
	free(*array);
	*array = NULL;
}

int dynamic_array_front(dynamic_array_t *array) {
	if(array->size == 0) {
		printf("Error array vazio !");
		exit(1);

	}
	return array->v[0];
}

int dynamic_array_back(dynamic_array_t *array) {
	if(array->size == 0) {
		printf("Error array vazio !");
		exit(1);

	}
	return array->v[array->size-1];
}


int main() {
	const int N = 1000;

	dynamic_array_t *arr;
	dynamic_array_initialize(&arr);

	srand(time(NULL));

	for(size_t i = 0; i < N; i++) {
		int value = rand();
		dynamic_array_push_back(arr, value);
	}

	while(dynamic_array_size(arr) > 0 ) {
		printf("v[%zu] => FRONT: %d\tBACK: %d\n", dynamic_array_size(arr) -1, dynamic_array_front(arr), dynamic_array_back(arr));
		dynamic_array_pop_back(arr);
	}

	dynamic_array_delete(&arr);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>


void swap(int *v, int i, int j) {

	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;

}


void bubble_sort(int *v, size_t size) {
	int swapped = 1;

	for(int i = 0; i < size - 1 && swapped; i++) {
		swapped = 0;
		for(int j = 0; j < size - i - 1; j++) {
			if(v[j] > v[j+1]) {
				swap(v, j, j + 1);
				swapped = 1;
			}
		}
	}

}


void print_vetor(int *v, size_t size) {
	for(size_t i = 0; i < size; i++) {
		printf("V[%zu] => %d\n", i, v[i]);
	}
} 


int main() {

	int vetor[] = { 3, -1, 8 , 2, 0, 100, -1, 90};

	print_vetor(vetor, 8);

	bubble_sort(vetor, 8);

	print_vetor(vetor, 8);



	return 0;
}
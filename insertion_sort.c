
#include <stdio.h>
#include <stdlib.h>


 
void swap(int *v, int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;

}


void insertion_sort(int *v, size_t size) {
	int i;
	int j;
	int chosen;

	for( i = 1; i < size; i++) {
		chosen = v[i];
		for(j = i - 1; (j >= 0) && (chosen < v[j]); j--) {
			v[j + 1]  = v[j];
		}
		v[j+1] = chosen;
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

	insertion_sort(vetor, 8);

	print_vetor(vetor, 8);



	return 0;
}
#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int *v, size_t size) {
    int i;
    int j;
    int chosen;

    for(i = 1; i < size; i++) {
        chosen = v[i];
        for(j = i - 1; (j >= 0) && (chosen < v[j]); j--) {
            v[j+1] = v[j];
        } 
        v[j+1] = chosen;
    }

}


void static merge(int *v, int *v1, int *v2, size_t size) {
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    
    int i = 0; // index of v
    int j = 0; // index of v1
    int k = 0; // index of v2
    
    for(i = 0; (j < size_v1) && (k < size_v2); i++) {
        
        if(v1[j] <= v2[k]) {
            v[i] = v1[j++];
        } else {
            v[i] = v2[k++];
        }

    }

    while(j < size_v1) {
        v[i++] = v1[j++];
    }

    while(k < size_v2) {
        v[i++] = v2[k++];
    }

}

void merge_sort(int *v, size_t size) {
    
    if(size > 16) {
        size_t mid = size / 2;

        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * size - mid);

        for(int i = 0; i < mid; i++) {
            v1[i] = v[i];
        }

        for(int i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }

        merge_sort(v1, mid);
        merge_sort(v2, size - mid);
        merge(v, v1, v2, size);
        

        free(v1);
        free(v2);
    } else {
        insertion_sort(v, size);
    }

}


void print_vetor(int *v, size_t size) {
    for(size_t i = 0; i < size; i++) {
        printf("%d\n", v[i]);
    }
}

int main() {
    
    const int tam = 100000;
    
    int *v = malloc(sizeof(int) * tam);

    for(size_t i = 0; i < tam; i++) {
        v[i] = rand() % tam;
    }
    
    //print_vetor(v, tam);

    merge_sort(v, tam);

    printf("********\n");
    //print_vetor(v, tam);


    free(v);

    return 0;
}

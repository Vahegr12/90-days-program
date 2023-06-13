#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int _size;
    int _capacity;
    int* _ptr;
} My_vector;

void My_vector_init(My_vector* vec){
    vec->_ptr = (int*)malloc(0);
}

void My_vector_init_size(My_vector* vec, int size){
    vec->_ptr = (int*)malloc(size * sizeof(int));
    vec->_capacity = size;
    vec->_size = size;
    int i = 0; 
    while(i < vec->_size){
        vec->_ptr[i] = 0;
        ++i;
    }
}

void My_vector_destroy(My_vector* vec){
    free(vec->_ptr);
}

int My_vector_get(My_vector* vec, int i){ // []
    return *(vec->_ptr+i);
}

void My_vector_print(My_vector* vec){
    int i = 0;
    while(i < vec->_size){
        printf("%d ", vec->_ptr[i]);
        ++i;
    }
    printf("\n");
}

int My_vector_push_back(My_vector* vec, int element){
    if (vec->_size >= vec->_capacity){
        vec->_capacity *= 2;
        
        int* tmp_ptr = (int*)malloc(vec->_capacity * sizeof(int));
        if(tmp_ptr == NULL){
            return -1;
        }
        for(int i = 0; i < vec->_size; ++i){
            tmp_ptr[i] = vec->_ptr[i];
        }
        free(vec->_ptr);
        vec->_ptr = tmp_ptr;
        vec->_ptr[vec->_size] = element;
    }
    else{
        vec->_ptr[vec->_size] = element;
    }
    vec->_size++;
    return 0;
}

void My_vector_reserve(My_vector* vec, int size){
    vec->_ptr = (int*)realloc(vec->_ptr,size);
    vec->_capacity = size;
}

int My_vector_at(My_vector* vec, int pos){
    if(pos < 0 || pos > vec->_size){
        return -1;
    }
    return vec->_ptr[pos];
}

int My_vector_insert(My_vector* vec, int pos, int element){
    if(pos < 0 || pos > vec->_size){
        return -1;
    }
    vec->_ptr[pos] = element;
    return 0;
}
size_t My_vector_size(My_vector* vec){
    return vec->_size;
}

size_t My_vector_capacity(My_vector* vec){
    return vec->_capacity;
}

int main(){
    My_vector arr;
    My_vector* arr_ptr = &arr;
    My_vector_init_size(arr_ptr, 1);
    My_vector_push_back(arr_ptr, 10);
    My_vector_push_back(arr_ptr, 10);
    My_vector_insert(arr_ptr,0,10);
    int tmp_num = My_vector_at(arr_ptr,1);
    My_vector_print(arr_ptr);
    size_t tmp_size = My_vector_size(arr_ptr);
    size_t tmp_capacity = My_vector_capacity(arr_ptr);
    My_vector_destroy(arr_ptr);
    return 0;
}

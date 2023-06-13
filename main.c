// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Dynamic_array{
//     int* _ptr;
//     size_t _size;
//     size_t _capacity;
// } Dmc_arr;

// void init_dmc_arr(Dmc_arr* arr_obj, size_t size){
//     if(size == 0){
//         return;
//     }
//     arr_obj->_size = size ;
//     arr_obj->_capacity = size * sizeof(int);

//     arr_obj->_ptr = (int*)calloc(size,sizeof(int));
// }

// void free_dmc_arr(Dmc_arr* arr_obj) {
//     free(arr_obj->_ptr);
//    arr_obj->_ptr = NULL;
//    arr_obj->_size = 0;
//    arr_obj->_capacity = 0;
// }

// void print_Dmc_arr(Dmc_arr* arr_obj){
//     printf("the array is: ");
//     for(int i = 0; i < arr_obj->_size; ++i){
//         printf("%d ", arr_obj->_ptr[i]);
//     }
//     printf("\n");
// }

// void push_back(Dmc_arr* arr_obj, int element){
    
//     if(arr_obj->_size >= arr_obj->_capacity){
//         arr_obj->_capacity *= 2;
//         arr_obj->_ptr = realloc(arr_obj->_ptr, arr_obj->_capacity );
        
//     }

//     arr_obj->_ptr[arr_obj->_size] = element;
//     ++arr_obj->_size;

// }


// int main(){
//     Dmc_arr array_1;
//     Dmc_arr* arr_obj = &array_1;
//     init_dmc_arr(arr_obj, 10100);
//     push_back(arr_obj, 2);
//     push_back(arr_obj, 2);
//     push_back(arr_obj, 2);

//     // print_Dmc_arr(arr_obj);



//     free_dmc_arr(arr_obj);
//     return 0;
// }

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

int main(){
    My_vector arr;
    My_vector* arr_ptr = &arr;
    My_vector_init_size(arr_ptr, 1);
    My_vector_push_back(arr_ptr, 10);
    My_vector_push_back(arr_ptr, 10);
    My_vector_insert(arr_ptr,0,10);
    My_vector_at(arr_ptr,1);
    My_vector_print(arr_ptr);
    My_vector_destroy(arr_ptr);
    return 0;
}

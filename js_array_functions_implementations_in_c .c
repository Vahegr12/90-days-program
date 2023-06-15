#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//function implementations

void print_int(int num){
    printf("%d ", num);
}
void print(int* arr, int size){
    for(int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
}

void push(int** arr, int* size, int* capacity ,int element){
    if(*size >= *capacity){
        
        int* tmp_ptr = (int*)calloc(sizeof(int),*(capacity) * 2);
        *capacity *= 2;

        if(tmp_ptr == NULL){
            return;
        }
        
        for(int i = 0; i < *size; ++i){
            tmp_ptr[i] = (*arr)[i];
        }
        free(*arr);
        *arr = tmp_ptr;
        (*arr)[*size] = element;
    }
    else{
        (*arr)[*size] = element;
    }
    ++*(size);
}

void for_each(int* arr, int size, void (*callback)(int)) {
  for (int i = 0; i < size; ++i) {
    callback(arr[i]);
  }
}

int* concat(int* arr_1, int size_1, int* arr_2, int size_2){
    int* new_arr = (int*)calloc(size_1 + size_2, sizeof(int));
    if(new_arr == NULL){
        return NULL;
    }
    for(int i = 0; i < size_1; ++i){
        new_arr[i] = arr_1[i];
    }
    for(int i = 0; i < size_2; ++i){
        new_arr[size_1+i] = arr_2[i];
    }
    return new_arr;
}

int every(int* arr, int size, int(*f_ptr)(int)){
    for(int i = 0; i < size; ++i){
        if(!f_ptr(arr[i])){
            return 0;
        }
    }
    return 1;
};

int* filter(int* arr, int size, int(*f_ptr)(int)){
    int* arr_filtered = (int*)calloc(sizeof(int),0);
    if(arr_filtered == NULL){
        return NULL;
    }
    int new_arr_size = 0;
    int new_arr_capacity = 0;
    for(int i = 0; i < size; ++i){
        if(f_ptr(arr[i])){
            push(&arr_filtered, &new_arr_size, &new_arr_capacity, arr[i]);
        }
    }
    return arr_filtered;
}

int index_of(int* arr, int size, int element){
    for(int i = 0; i < size; ++i){
        if(arr[i] == element){
            return i;
        }
    }
    return -1; 
}

int* map(int* arr, int size, int(*f_ptr)(int)){
    int* new_arr = (int*)calloc(size,sizeof(int));
    if(new_arr == NULL){
        return NULL;
    }
    for(int i = 0; i < size; ++i){
        new_arr[i] = f_ptr(arr[i]);
    }
    return new_arr;
}

int reduce(int* arr, int size,int accumulator, int(*f_ptr)(int,int)){
    for(int i = 0; i < size; ++i){
        accumulator = f_ptr(arr[i],accumulator);
    }
    return accumulator;
}

void reverce(int* arr, int size){
    int tmp = 0;
    for(int i = 0; i < size/2; ++i){
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}

int some(int* arr, int size, int(*f_ptr)(int)){
    for(int i = 0; i < size; ++i){
        if(f_ptr(arr[i]) > 0){
            return 1;
        }
    }
    return -1;
}

void sort(int* arr, int size){
    char* str_arr[size];
    for(int i = 0; i < size; ++i){
        sprintf(str_arr[i], "%d", arr[i]);
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size-1-i; j++){
            if(strcmp(str_arr[j], str_arr[j+1]) > 0){
                //swap array[j] and array[j+1]
                char temp[32];
                strcpy(temp, str_arr[j]);
                strcpy(str_arr[j], str_arr[j+1]);
                strcpy(str_arr[j+1], temp);
            }
        }
    }

    for(int i = 0; i < size; ++i){
        arr[i] = atoi(str_arr[i]);
    }

}

void splice(int** arr, int size, int pos, int count){
    int new_size = size - count;
    int* new_ptr = (int*)calloc(new_size,sizeof(int));
    if(new_ptr == NULL){
        return;
    }
    for(int i = 0; i < pos; ++i){
        new_ptr[i] = *(arr)[i];
    }
    for(int i = pos + count, j = pos; i < size; ++i,++j){
        new_ptr[j] = *(arr)[i];
    }
    free(*arr);
    *(arr) = new_ptr;

}

void fill(int* arr, int size, int el, int pos_1, int pos_2){
    for(int i = pos_1; i < pos_2; ++i){
        arr[i] = el;
    }
}

int find(int* arr, int size, int(*f_ptr)(int)){
    for(int i = 0; i < size; ++i){
        if(f_ptr(arr[i]) > 0){
            return arr[i];
        }
    }
    return -1;
}

int find_index(int* arr, int size, int(*f_ptr)(int)){
    for(int i = 0; i < size; ++i){
        if(f_ptr(arr[i]) > 0){
            return i;
        }
    }
    return -1;
}

int find_last_index(int* arr, int size, int(*f_ptr)(int)){
    for(int i = size-1; i >= 0; --i){
        if(f_ptr(arr[i]) > 0){
            return i;
        }
    }
    return -1;
}

int includes(int* arr, int size, int el){
    for(int i = 0; i < size; ++i){
        if(arr[i] == el){
            return 1;
        }
    }
    return 0;
}

char* join(const char** array, int size, const char* separator) {
    if (size == 0) {
        return NULL; 
    }

    
    int total_length = 0;
    for (int i = 0; i < size; i++) {
        total_length += strlen(array[i]);
    }
    total_length += (size - 1) * strlen(separator) + 1; 

    char* result = (char*)calloc(sizeof(char),total_length);
    if (!result) {
        return NULL;
    }

    strcpy(result, array[0]);
    for (int i = 1; i < size; i++) {
        strcat(result, separator);
        strcat(result, array[i]);
    }

    return result;
}

int* with(int* arr, int size, int pos, int el){
    int* new_arr = (int*)calloc(size,sizeof(int));
    if(new_arr == NULL){
       return NULL;
    }
    for(int i = 0; i < pos; ++i){
        new_arr[i] = arr[i];
    }

    new_arr[pos] = el;
    
    for(int i = pos + 1; i < size; ++i){
        new_arr[i] = arr[i];
    }
    return new_arr;
}

int* slice(int* arr, int size, int pos_1, int pos_2){
    if(pos_1 < 0-size || pos_1 >= size || pos_2 < 0-size || pos_2 >= size){
        return NULL;
    }

    if(pos_1 < 0){
        pos_1 += size;
    }
    if(pos_2 < 0){
        pos_2 += size;
    }

    int* new_arr = (int*)calloc(pos_2 - pos_1,sizeof(int));
    if(new_arr == NULL){
        return NULL;
    }
    int index = 0;

    for(int i = 0; i < pos_2 - pos_1; ++i){

        new_arr[i] = arr[index];
        ++index;
    }
    return new_arr;
}


// additioal functions used as arguments

int sum(int a, int b){
    return a + b;
}
int greater_then_10(int num){
    return (num > 10);
}
int increment(int a){
        return ++a;
    }
int is_odd(int num){
    return num % 2;
}

int main(int argc, char* argv[]){
    int arr_1_capacity = 2;
    int arr_1_size = 0;
    
    void (*print_element)(int) = &print_int;
    
    int* arr_1 = (int*)calloc(arr_1_capacity,sizeof(int));
    if(arr_1 == NULL){
        exit(-1);
    }
// push() 
    push(&arr_1, &arr_1_size, &arr_1_capacity, 9);
    push(&arr_1, &arr_1_size, &arr_1_capacity, 12);
    push(&arr_1, &arr_1_size, &arr_1_capacity, 21);
    push(&arr_1, &arr_1_size, &arr_1_capacity, 34);
// print()
    //print(arr_1,arr_1_size);

// for_each()
    //for_each(arr_1,arr_1_size,print_element); 
    
//concat()
    int arr_2_capacity = 1;
    int arr_2_size = 0;
    int* arr_2 = (int*)calloc(arr_2_capacity, sizeof(int));
    if(arr_2 == NULL){
        exit(-2);
    }
    push(&arr_2, &arr_2_size, &arr_2_capacity, 33);
    push(&arr_2, &arr_2_size, &arr_2_capacity, 44);
    push(&arr_2, &arr_2_size, &arr_2_capacity, 55);
    int * arr_concat = concat(arr_1, arr_1_size, arr_2, arr_2_size);
   // print(arr_concat,arr_1_size + arr_2_size);

// every()
   

    int (*f_ptr)(int);
    f_ptr = greater_then_10;
    
    //printf("%d ",every(arr_1, arr_1_size, f_ptr));

// filter()
    int *arr_filtered = filter(arr_1,arr_1_size,f_ptr);
    //print(arr_filtered, 2);

// index_of()
    // printf("%d ", index_of(arr_1, arr_1_size, 21));
    // printf("%d ", index_of(arr_1, arr_1_size, 9));
    // printf("%d ", index_of(arr_1, arr_1_size, 111111));

//map() // modify every element
    
    f_ptr = increment;
    int* map_array = map(arr_1, arr_1_size, f_ptr);
    // print(map_array, arr_1_size);

//sort()
    //sort(arr_1, arr_1_size);
    //print(arr_1, arr_1_size);

//reduce() 
   
    int(*reduce_func_arg_ptr)(int,int);
    reduce_func_arg_ptr = sum;
    int reduced_val_arr = reduce(arr_1, arr_1_size, 1, reduce_func_arg_ptr);
    //printf("%d ", reduced_val_arr);

//reverce()
    reverce(arr_1,arr_1_size);
    // print(arr_1, arr_1_size);

//some()
    f_ptr = is_odd;
    int contains_odd = some(arr_1, arr_1_size, f_ptr);
    //printf("%d ", contains_odd);

// slice()
    int* sliced_arr = slice(arr_1,arr_1_size,0,3);
    print(sliced_arr,3);





// free allocated memory
    free(arr_1);
    free(arr_2);
    free(arr_concat);
    free(arr_filtered);
    free(map_array);
    free(sliced_arr);
    return 0;
}

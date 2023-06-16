#include <stdlib.h>
#include <stdio.h>

int length(char* str){
    int str_legth = 0;
    int i = 0;
    while(str[i]){
        ++str_legth;
        ++i;
    }
    return str_legth;
}

char* at(char* str,int index){
    
    int str_length = length(str);

    if(index >= str_length || index < 0-str_length){
        return NULL;
    }
    char* new_str = (char*)calloc(2,sizeof(char));
    
    if(index >= 0){
        new_str[0] = str[index];
    }
    else{
        new_str[0] = str[str_length + index];
    }
   
    new_str[1] = '\0';
    return new_str; 
}

char* char_at(char* str, int index){
    
    int str_length = length(str);
    
    if(index >= str_length || index < 0){
    
        char* new_str = (char*)calloc(2,sizeof(char));
        return new_str; 
    }
    
    char* new_str = (char*)calloc(2,sizeof(char));
    new_str[0] = str[index];
    new_str[1] = '\0';
    return new_str;
}

int char_code_at(char* str, int index){
    
    int str_length = length(str);
    
    if(index < 0 || index > str_length){
    
        return -1;
    }
    
    return (int)(str[index]);
}

char* concat(char* str_1, char* str_2, char* middle_string){
    
    int str_1_length = length(str_1);
    int str_2_length = length(str_2);
    int middle_length = length(middle_string);
    int str_out_length = str_1_length + middle_length + str_2_length;
    
    char* str_out = (char*)calloc(str_out_length + 1,sizeof(char));
    int i = 0;
    
    for(i = 0; i < str_1_length; ++i){
        str_out[i] = str_1[i];
    }

    for(i = 0; i < middle_length; ++i){
        str_out[str_1_length + i] = middle_string[i];
    }
    
    for(i = 0; i < str_2_length; ++i){
        str_out[i + str_1_length + middle_length] = str_2[i]; 
    }
    str_out[str_out_length] = '\0';
    return str_out;
}

int ends_with(char* str, char* cmp_to){
    
    int cmp_length = length(cmp_to);
    int str_legth = length(str);

    if(cmp_length > str_legth){
        return 0;
    }

    for(int i = 0; i < cmp_length; ++i){
        if(str[str_legth - cmp_length + i] != cmp_to[i]){
            return 0;
        }
    }


    return 1;
}

int includes(char* str, char* search_to){
    
    int search_length = length(search_to);
    int str_legth = length(str);

    if(search_length > str_legth){
        return 0;
    }

    int indicator = 1;

    for(int i = 0; i < str_legth; ++i){
       
        if(str[i] == search_to[0]){

            for(int j = 0; j < search_length; ++j){
                
                if(str[i+j] != search_to[j]){
                    indicator = 0;
                    break;
                }
            }

            if(indicator){
                return 1;
            }
        }
    }    

    return 0;
}

int index_of(char* str, char element){
    int str_length = length(str);
    for(int i = 0; i < str_length; ++i){
        if(str[i] == element){
            return i;
        }
    }
    return -1; 
}

char* pad_end(char** str, int size_to, char el){
    int str_length = length(*str);
    char* str_edited = (char*)calloc(size_to + 1,sizeof(char));

    if(str_length > size_to){
        for(int i = 0; i < size_to; ++i){
            str_edited[i] = (*str)[i];
        }
        free(*str);
        *str = str_edited;
    }
    else{
        for(int i = 0; i < str_length-1; ++i){
            str_edited[i] = (*str)[i];
        }
        for(int i = str_length; i < size_to; ++i){
            str_edited[i] = el;
        }
        free(*str);
        *str = str_edited;
    }
    
    
    return *str; 
}

char* pad_start(char** str, int size_to, char el){
    int str_length = length(*str);
    char* str_edited = (char*)calloc(size_to + 1,sizeof(char));

    if(str_length > size_to){
        for(int i = 0; i < size_to; ++i){
            str_edited[i] = (*str)[i];
        }
        free(*str);
        *str = str_edited;
    }
    else{
        for(int i = 0; i < str_length-1; ++i){
            str_edited[i] = (*str)[i];
        }
        for(int i = str_length; i < size_to; ++i){
            str_edited[i] = el;
        }
        free(*str);
        *str = str_edited;
    }
    
    
    return *str; 
}

char* repeat(char* str, int times){
    int str_length = length(str);
    char* out_str = (char*)calloc(str_length * times + 1,sizeof(char));
    
    int result_index = 0;
    for (int i = 0; i < times; ++i) {
        int str_index = 0;
        while (str[str_index] != '\0') {
            out_str[result_index] = str[str_index];
            result_index++;
            str_index++;
        }
    }

    out_str[str_length*times] = '\0';
    return out_str;
}

char* replace(char* str, char* from, char* to){
    int str_len = length(str);
    int from_len = length(from);
    int to_len = length(to);
    int str_out_len = str_len + (to_len - from_len);
    char* str_out = (char*)calloc(str_out_len + 1,sizeof(char));

    int from_index = -1;

    for(int i = 0; i < str_len; ++i){
        if(str[i] == from[0]){
            from_index = i;
            for(int j = 0; j < from_len; ++j){
                if(str[i+j] != from[j]){
                    from_index = -1;
                    break;
                }
            }
            if(from_index == i){
                break;
            }
        }
    }

    if(from_index == -1){
        return NULL;
    }

    for(int i = 0; i < from_index; ++i){
        str_out[i] = str[i];
    }

    for(int i = from_index; i < from_index + to_len; ++i){
        str_out[i] = to[i];
    }

    for(int i = from_index + to_len; i < str_out_len; ++i){
        str_out[i] = str[i + (to_len - from_len)];
    }


    str_out[str_out_len] = '\0';
    return str_out;
}

char* replace_all(char* str, char* from, char* to) {
    int str_out_len = 1;
    int from_len = 0;
    int to_len = 0;
    int replaced = 0;

    while (str[str_out_len - 1] != '\0') {
        str_out_len++;
    }
    while (from[from_len] != '\0') {
        from_len++;
    }
    while (to[to_len] != '\0') {
        to_len++;
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int j;
        for (j = 0; from[j] != '\0'; j++) {
            if (str[i + j] != from[j]) {
                break;
            }
        }
        if (from[j] == '\0') {
            count++;
        }
    }

    int str_out_total_len = str_out_len + count * (to_len - from_len);
    char* str_out = (char*)calloc(str_out_total_len + 1,sizeof(char));
    int str_out_index = 0;

    int i = 0;
    while (str[i] != '\0') {
        int j;
        for (j = 0; from[j] != '\0'; j++) {
            if (str[i + j] != from[j]) {
                break;
            }
        }
        if (from[j] == '\0') {
            int k = 0;
            while (to[k] != '\0') {
                str_out[str_out_index++] = to[k++];
            }
            i += from_len;
            replaced = 1;
        } else {
            str_out[str_out_index++] = str[i++];
        }
    }
    str_out[str_out_index] = '\0';

    if (!replaced) {
        return NULL;
    }

    return str_out;
}

char* slice(char* str, int pos_1, int pos_2){
    int str_length = length(str);
    if(pos_1 < 0-str_length || pos_1 >= str_length || pos_2 < 0-str_length || pos_2 >= str_length){
        return NULL;
    }

    if(pos_1 < 0){
        pos_1 += str_length;
    }
    if(pos_2 < 0){
        pos_2 += str_length;
    }

    char* new_str = (char*)calloc(pos_2 - pos_1 + 1,sizeof(char));
    if(new_str == NULL){
        return NULL;
    }
    int index = 0;

    for(int i = 0; i < pos_2 - pos_1; ++i){

        new_str[i] = str[index];
        ++index;
    }
    new_str[pos_2 - pos_1] = '\0';
    return new_str;
}

void splice(char** str, int pos, int count){
    int str_length = length(*str);
    int new_length = str_length - count;
    char* new_ptr = (char*)calloc(new_length + 1,sizeof(char));
    if(new_ptr == NULL){
        return;
    }
    for(int i = 0; i < pos; ++i){
        new_ptr[i] = *(str)[i];
    }
    for(int i = pos + count, j = pos; i < str_length; ++i,++j){
        new_ptr[j] = *(str)[i];
    }
    free(*str);
    *(str) = new_ptr;

}

int starts_with(char* str, char* cmp_to){
    
    int cmp_length = length(cmp_to);
    int str_legth = length(str);

    if(cmp_length > str_legth){
        return 0;
    }

    for(int i = 0; i < cmp_length; ++i){
        if(str[i] != cmp_to[i]){
            return 0;
        }
    }


    return 1;
}

char* substring(char* str, int start_index, int end_index){
    int str_len = length(str);
    if(start_index < 0 || start_index >= str_len || end_index < 0 || end_index >= str_len || start_index > end_index){
        return NULL;
    }

    int out_str_length = end_index - start_index;
    char* out_str = (char*)calloc(out_str_length + 1, sizeof(char));
    
    for(int i = 0; i < out_str_length; ++i){
        out_str[i] = str[start_index + i];
    }

    out_str[out_str_length] = '\0';
    return out_str;

}

char* to_lower_case(char* str){
    int str_len = length(str);
    for(int i = 0; i < str_len; ++i){
        if(str[i] >= 'A' && str[i] <= 'z'){
            str[i] += 32;
        }
    }
    return str;
}

char* to_upper_case(char* str){
    int str_len = length(str);
    for(int i = 0; i < str_len; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    return str;
}

char* trim_end(char* str){
    int str_len = length(str);
    int w_s_count = 0;
    int i = str_len - 1;
    
    while(str[i] == ' '){
        ++w_s_count; 
        --i;
    }

    int out_str_length = str_len - w_s_count;
    char* out_str = (char*)calloc(out_str_length + 1,sizeof(char));

    for(int i = 0; i < out_str_length; ++i){
        out_str[i] = str[i];
    }
    
    out_str[out_str_length] = '\0';
    return out_str;
}

char* trim_start(char* str){
    int str_len = length(str);
    int w_s_count = 0;
    int i = 0;
    
    while(str[i] == ' '){
        ++w_s_count; 
        ++i;
    }

    int out_str_length = str_len - w_s_count;
    char* out_str = (char*)calloc(out_str_length + 1,sizeof(char));

    for(int i = 0; i < out_str_length; ++i){
        out_str[i] = str[i + w_s_count];
    }
    
    out_str[out_str_length] = '\0';
    return out_str;
}

char* trim(char* str){
    return trim_end(trim_start(str));
}



int main(){
    int str_1_length = 7;
    int str_1_capacity = 8;
    char* str_1 = "Hrazdan";
    //printf("%s \n", str_1);

    int str_2_length = 7;
    int str_2_capacity = 8;
    char* str_2 = "Yerevan";
    //printf("%s \n", str_1);


//at()
    char* str_at = at(str_1, -1);
    // printf("%s \n", str_at);

//char_at()
    char* str_char_at_str =  char_at(str_1, 2);
    // printf("%s \n", str_char_at_str);

//char_code_at()
    // printf("%d \n", char_code_at(str_1, 2));

//concat()
    char* concat_arg = (char*)calloc(2,sizeof(char));
    concat_arg[0] = '-';
    char* str_concat = concat(str_1,  str_2, concat_arg);
    //printf("%s \n", str_concat);

//ends_with()
    // printf("%d \n",ends_with("Hrazdan","zdan"));
    // printf("%d \n",ends_with("Hrazdan","asd"));
    // printf("%d \n",ends_with("Hrazdan","asdasdafsdf"));

//includes()
    // printf("%d \n", includes("Hrazdan","Hrazdan"));
    // printf("%d \n", includes("Hrazdan","Hraz"));
    // printf("%d \n", includes("Hrazdan","Hrazk"));
    // printf("%d \n", includes("Hrazdan","Hrazdanaaa"));

//index_of()
    // printf("%d \n", index_of(str_1,'r'));
    // printf("%d \n", index_of(str_1,'z'));
    // printf("%d \n", index_of(str_1,'v'));

//pad_end
    //printf("%s \n", pad_end(&str_1,30,'r'));
    //printf("%s \n", pad_end(&str_1,2,'r'));

//pad_start
    //printf("%s \n", pad_start(&str_1,30,'r'));
    //printf("%s \n", pad_start(&str_1,30,'r'));
    
//repeat()
    //printf("%s \n", repeat(str_1,3));

//replace()
    //printf("%s \n", replace(str_1,"hr","ye"));

//replace_all()
    //printf("%s \n", replace_all(str_1,"a","z"));

//trim_end()
    //printf("%s%c \n",trim_end(str_1),'|');

//trim_start()
    //printf("%c%s \n",'|',trim_start(str_1));

//trim()
    // printf("%c%s%c",'|',trim(str_1),'|');
    


//free memory    
    free(str_at);
    free(str_char_at_str);
    free(concat_arg);
    free(str_concat);
    return 0;
}

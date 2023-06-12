#include <iostream>

template<class T>
class My_vector{
public:
//constructors
    My_vector(){
        this->_ptr = (T*)malloc(0);
    }
    My_vector(size_t size){
        this->_ptr = new T[size];
        this->_capacity = size;

        int i = 0; 
        while(i < this->_size){
            this->_ptr[i] = T();
            ++i;
        }
    }

//destructor
    ~My_vector(){
        delete[] this->_ptr;
    }

//operators
    T operator[](size_t i){
        return *(this->_ptr+i);
    }

// functions  
    void print(){
        int i = 0;
        while(i < this->_size){
            std::cout << this->_ptr[i] << " ";
            ++i;
        }
        std::cout << std::endl;
    }

    bool push_back(T element){
        
        if (this-> _size >= this-> _capacity){
            this-> _capacity *= 2;
            //////////////////////////////////this->_ptr = realloc(this->_capacity); 
            T* tmp_ptr = new T[this->_capacity];
            if(tmp_ptr == nullptr){return -1;}

            for(int i = 0; i < this->_size; ++i){
                tmp_ptr[i] = this->_ptr[i];
            }
            delete[] this->_ptr;
            this->_ptr = tmp_ptr;
            this->_ptr[this->_size] = element;
        }
        else{
            this->_ptr[this->_size] = element;
        }

        this->_size++;
        return 0;
    }
    
    // bool reserve(){}
    
    // bool insert(size_t pos, T element);
    
    T at(size_t pos){
        if (pos < 0 || pos >= this->_size) {
        throw std::out_of_range("inaccessible position");
    }
        return this->_ptr[pos];
    }

    size_t size(){
        return this->_size;
    }
    
    bool empty(){
        return !(bool)this->_size;
    }

    size_t capacity(){
        return this->_capacity;
    }

private:
    int _size = 0;
    int _capacity = 0;
    T* _ptr = nullptr;
};


int main (){
    My_vector<int> arr(1);
    arr.push_back(15);
    arr.push_back(14);
    arr.push_back(13);
    arr.push_back(12);
    arr.push_back(11);
    arr.print();
    std::cout << "size is: " << arr.size() << std::endl;
    std::cout << "Capacity is: " << arr.capacity() << std::endl;
    std::cout << "is empty: " << arr.empty() << std::endl;
    std::cout << "at 3 is: " << arr.at(3) << std::endl;
    std::cout << "[4] is: " << arr[4] << std::endl;

    My_vector<std::string> str(1);
    str.push_back("armenia");
    str.push_back("armenia");
    str.push_back("armenia");
    str.print();

    return 0;
}

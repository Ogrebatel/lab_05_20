// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstdlib>
#include <iostream>

//using namespace std;
using std::cout;
using std::endl;

template <typename T>
class stack {
public:
    stack() : count(0), my_stack(nullptr){}
    ~stack(){
        free(my_stack);
        count = 0;
    }
    void push(T &&value) {
        ++count;
        my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
        my_stack[count - 1] = value;
        //delete value;
    }
    void push(const T &value) {
        ++count;
        my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
        my_stack[count - 1] = value;
    }
    T pop() {
            if (count == 0) {
                cout << "stack underflow" << endl;
                exit(-2);
            }
            T tmp = my_stack[count - 1];
            my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
            --count;
            return tmp;
    }
    const T &head() const {
        if (count == 0) {
            cout << "stack underflow" << endl;
            exit(-2);
        }
        return my_stack[count - 1];
    }
    unsigned count;
    T* my_stack;
};

#endif // INCLUDE_HEADER_HPP_

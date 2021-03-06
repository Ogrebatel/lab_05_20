// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER2_HPP_
#define INCLUDE_HEADER2_HPP_

#include <cstdlib>
#include <iostream>

#define STACK_UNDERFLOW -2

using std::cout;
using std::endl;

template <typename T>

class stack_st {
    public:
              template <typename ... Args>
              void push_emplace(Args&&... value){
              ++count;
              my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
              T tmp(value...);
              my_stack[count - 1] = tmp;
          }
        ~stack_st(){
        free(my_stack);
        count = 0;
    }

          void push(T&& value){
              ++count;
              my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
              my_stack[count - 1] = value;
              //delete value;
          }

          const T& head() const{
              if (count == 0) {
                  cout << "stack underflow" << endl;
                  exit(STACK_UNDERFLOW);
              }
              return my_stack[count - 1];
          }

          T pop() {
              if (count == 0) {
                  cout << "stack underflow" << endl;
                  exit(STACK_UNDERFLOW);
              }
              T tmp = my_stack[count - 1];
              my_stack = static_cast<T*>(realloc(my_stack, count * sizeof(T)));
              --count;
              return tmp;
          }
    unsigned count = 0;
    T* my_stack = nullptr;
};

#endif // INCLUDE_HEADER2_HPP_

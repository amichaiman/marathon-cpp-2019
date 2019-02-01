//
// Created by amichai on 01/02/19.
//

#ifndef MARATHON_CPP_2019_STACK_H
#define MARATHON_CPP_2019_STACK_H
#include <exception>
#include <vector>

using namespace std;

template <typename T>
class Stack {
public:
    explicit Stack();
    bool push(T& elem);
    T& top() const throw(EmptyStackException);
    void pop() throw(EmptyStackException);
    int size() const;
    bool empty() const;

    struct EmptyStackException : public exception {
        const char* what() const throw {
            return "Stack is empty";
        }
    };

private:
    vector v;
};
#endif //MARATHON_CPP_2019_STACK_H

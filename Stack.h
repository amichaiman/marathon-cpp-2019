//
// Created by amichai on 06/02/19.
//

#ifndef MARATHON_CPP_2019_STACKMARATHON_H
#define MARATHON_CPP_2019_STACKMARATHON_H
#include <vector>

using namespace std;

template <typename T>
class Stack {
public:
    void push(const T &t);
    T& top() const throw(EmptyStackException);
    void pop() throw(EmptyStackException);
    int size() const;
    bool empty() const;

    struct EmptyStackException : exception {
        virtual const char* what() const throw() {
            return "stack is empty";
        }
    };
private:
    vector<T> v;
};


#endif //MARATHON_CPP_2019_STACKMARATHON_H

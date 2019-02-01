//
// Created by amichai on 01/02/19.
//

#ifndef MARATHON_CPP_2019_QUEUE_H
#define MARATHON_CPP_2019_QUEUE_H

#include "Stack.h"

template <typename T>
class Queue {
public:
    explicit Queue();
    bool enqueue(T elem);
    T& front() const throw(EmptyQueueException);
    T& back() const throw(EmptyQueueException);
    bool dequeue(T elem) throw(EmptyQueueException);

    struct EmptyQueueException : public exception {
        const char* what() const throw() {
            return "queue is emtpy";
        }
    };
private:
    Stack<T> a,b;
};
#endif //MARATHON_CPP_2019_QUEUE_H

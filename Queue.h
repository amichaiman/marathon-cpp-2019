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
    bool enqueue(T& elem);
    T& front() throw(EmptyQueueException);
    T & back()  throw(EmptyQueueException);
    void dequeue(T elem) throw(EmptyQueueException);

    struct EmptyQueueException : public exception {
        const char* what() const throw() {
            return "queue is emtpy";
        }
    };
private:
    Stack<T> a,b;

    void transferAtoB();

    void transferBtoA();
};

template<typename T>
Queue<T>::Queue() { }

template<typename T>
bool Queue<T>::enqueue(T& elem) {
    return a.push(elem);
}

template<typename T>
T &Queue<T>::front() {
    if (a.size() + b.size() == 0) {
        throw EmptyQueueException();
    }
    if (!b.size()) {
        transferAtoB();
    }
    return b.top();
}

template<typename T>
void Queue<T>::transferAtoB() {
    int size = a.size();

    for (int i=0; i<size; i++) {
        b.push(a.top());
        a.pop();
    }
}

template<typename T>
void Queue<T>::transferBtoA() {
    int size = b.size();

    for (int i=0; i<size; i++) {
        a.push(b.top());
        b.pop();
    }
}

template<typename T>
T & Queue<T>::back() {
    if (a.size() + b.size() == 0) {
        throw EmptyQueueException();
    }
    if (!a.size()) {
        transferBtoA();
    }
    return a.top();
}

template<typename T>
void Queue<T>::dequeue(T elem) {
    if (a.size() + b.size() == 0) {
        throw EmptyQueueException();
    }
    if (!a.size()) {
        transferBtoA();
    }
    a.pop();
}

#endif //MARATHON_CPP_2019_QUEUE_H


#ifndef LABA5STACK_STACK_H
#define LABA5STACK_STACK_H

#include <iostream>

template <class T>
class Node {
public:
    Node *pNext;
    T value;

    Node (T value=T(), Node* pNext = nullptr) {
        this->value = value;
        this->pNext = pNext;
    }
};


template <class T>
class Stack {
public:
    Stack ();
    ~Stack();

    int getSize() { return this->size; }
    bool isEmpty() { return size == 0; }

    void push(T value);
    void print();
    void clear();

    T& operator() (const int index);
    T pop();

private:
    Node<T> *head;
    int size;
};

template<class T>
Stack<T>::Stack() {
    size = 0;
    head = nullptr;
}

template<class T>
Stack<T>::~Stack() {}

template <class T>
void Stack<T>::print() {
    Node<T> *current = this->head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->pNext;
    }
}

template <class T>
T & Stack<T>::operator() (const int index) {
    Node<T> *current = this->head;

    int i = 0;
    while (current->pNext != nullptr) {
        if (i == index) break;
        ++i;
        current = current->pNext;
    }
    return current->value;
}

template <class T>
T Stack<T>::pop() {
    Node<T> *temp = this->head;
    T tempValue = temp->value;

    this->head = this->head->pNext;
    delete temp;
    size--;

    return tempValue;
}

template<class T>
void Stack<T>::push(T value) {
    this->head = new Node<T>(value, this->head);
    size++;
}

template<class T>
void Stack<T>::clear() {
    while (size) {
        pop();
    }
}


#endif //LABA5STACK_STACK_H

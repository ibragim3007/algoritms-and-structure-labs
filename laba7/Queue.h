#ifndef LABA6_QUEUE_H
#define LABA6_QUEUE_H

#include <iostream>

template<class T>
class Node {
public:
    T value;
    Node *pNext;
    Node (T value = T(), Node* pNext = nullptr) {
        this->value = value;
        this->pNext = pNext;
    }
};

template<class T>
class Queue {
private:
    int size;
    Node<T> *head;
public:
    Queue() {
        size = 0;
        head = nullptr;
    };
    ~Queue() {};

    void push (T value) {
        if (this->head == nullptr) {
            this->head = new Node<T>(value);
        } else {
            Node<T> *current = this->head;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node<T>(value);
        }
        this->size++;
    }

    T pop () {
        Node<T> *temp = this->head;
        T tempValue = temp->value;
        this->head = this->head->pNext;

        delete temp;
        size--;
        return tempValue;
    }

    void clear () {
        while (size) pop();
    }

    void print() {
        Node<T> *current = this->head;
        while(current != nullptr) {
            std::cout << current->value << " ";
            current = current->pNext;
        }
    }

    bool isEmpty() { return size == 0; }
};


#endif //LABA6_QUEUE_H

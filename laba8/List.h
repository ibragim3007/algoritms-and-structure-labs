//
// Created by ибра on 4/9/22.
//

#ifndef LABA8_LIST_H
#define LABA8_LIST_H


#include <iostream>

template<class T>
class Node {
public:
    T value;
    Node *pNext;

    explicit Node (T value = T(), Node *pNext = nullptr) {
        this->value = value;
        this->pNext = pNext;
    }
};

template<class T>
class List {
private:
    Node<T> *head;
    int size;
public:
    List() {
        this->head = nullptr;
        size = 0;
    }

    void pushBack (T value) {
        if (this->head == nullptr) {
            this->head = new Node<T>(value);
        } else {
            Node<T> *current = this->head;
            while(current->pNext != nullptr)
                current = current->pNext;
            current->pNext = new Node<T>(value);
        }
        size++;
    }

    bool isEmpty () { return size == 0; }

    T removeAt(int index) {
        if (index == 0) popFront();

        auto *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
            previous = previous->pNext;

        Node<T> *toDelete = previous->pNext;
        T tempValue = toDelete->value;
        previous->pNext = toDelete->pNext;
        delete toDelete;

        return tempValue;
    }

    T popBack () {
        return this->removeAt(size - 1);
    }

    T popFront() {
        Node<T> *temp = this->head;
        T tempValue = temp->value;
        this->head = this->head->pNext;
        delete temp;

        size--;
        return tempValue;
    }

    void print() {
        Node<T> *current = this->head;
        while (current != nullptr) {
            std::cout << current->value << ' ';
            current = current->pNext;
        }
    }

    T & operator[] (const int index) {
        Node<T> *current = this->head;

        int i = 0;
        while(current->pNext != nullptr) {
            if (i == index) break;
            i++;
            current = current->pNext;
        }

        return current->value;
    }

    void pushHead(T value) {
        this->head = new Node<T>(value, this->head);
        size++;
    }

    void clear () {
        while (size != 0) {
            popFront();
        };
    }

    void insert(T value, int index) {

        if (index == 0) pushHead(value);
        else {

            Node<T> *previous = this->head;
            for (int i = 0; i < index - 1; ++i)
                previous = previous->pNext;

            auto *newNode = new Node<T>(value, previous->pNext);
            previous->pNext = newNode;
        }
        size++;
    }

};



#endif //LABA8_LIST_H

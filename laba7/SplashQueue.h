
#ifndef LABA6_SPLASHQUEUE_H
#define LABA6_SPLASHQUEUE_H


#include <iostream>

template <class T>
class SplashQueue {
private:
    int maxSize{};

    T *data;
    int last{};
    int first{};

public:
    explicit SplashQueue(int size) {
        this->maxSize = size;
        this->data = new T[size];
        last = 0;
        first = 0;
    }

    void push(T value) {
        if (this->last - this->first == this->maxSize) {
            std::cout << "Queue overflow" << std::endl;
            return;
        }
        else data[(last++) % maxSize] = value;
    }

    T pop() { return this->data[(first++) % maxSize]; }

    int getSize () { return (last - first) % (maxSize + 1); }

    void clear() { while(last - first) pop(); last = 0; first = 0; }

    void print() {
        for (int i = first; i < last; ++i)
            std::cout << this->data[i] << ' ';
    }

    bool isEmpty() { return last - first == 0; }
};


#endif //LABA6_SPLASHQUEUE_H

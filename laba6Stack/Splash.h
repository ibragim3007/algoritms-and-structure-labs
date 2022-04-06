#ifndef LABA5STACK_SPLASH_H
#define LABA5STACK_SPLASH_H

#include <iostream>

template <class T>
class Splash {
private:
    int maxSize{};
    T *data;
    int last{};

public:
    explicit Splash(int size) {
        this->maxSize = size;
        this->data = new T[size];
    }

    void push(T value) {
        if (this->last == maxSize) {
            std::cout << "Overflow\n";
            return;
        }
        this->data[this->last++] = value;
    }

    void print () {
        for (int i = this->last - 1; i >= 0; --i) {
            std::cout << this->data[i] << ' ';
        }
    }

    T pop() {
        return this->data[--this->last];
    }

    bool isEmpty() const { return this->last == 0; }

    void clear() {
        while (!isEmpty()) pop();
    }

};

#endif //LABA5STACK_SPLASH_H
